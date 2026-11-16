#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {  5100, "Kung" },
  {  5820, "sakaling" },
  {  7460, "mapundi" },
  {  8620, "Ang" },
  {  9040, "pag-ibig" },
  {  9720, "mo" },
  { 10020, "sa" },
  { 10340, "akin" },
  { 13320, "Ay" },
  { 13770, "hayaan" },
  { 15210, "mo" },
  { 15510, "'kong" },
  { 15910, "magbigay" },
  { 16870, "Ng" },
  { 17350, "liwanag" },
  { 18590, "para" },
  { 19110, "satin" },
  { 22650, "Akala" },
  { 23310, "ko" },
  { 23850, "tayo" },
  { 24610, "hanggang" },
  { 25310, "dulo" },
  { 27090, "Ba't" },
  { 27370, "ngayon" },
  { 27890, "nag" },
  { 28170, "iisa" },
  { 29010, "ako?" },
  { 30750, "Ohh" },
  { 31150, "'di" },
  { 31490, "ba" },
  { 32390, "wala" },
  { 32790, "akong" },
  { 33250, "natutunan" },
  { 35450, "Ang" },
  { 35830, "hirap" },
  { 36490, "mo" },
  { 36670, "pa" },
  { 36910, "ring" },
  { 37290, "kalimutan" }
};

const int totalWords = sizeof(lyrics) / sizeof(lyrics[0]);
int currentWordIndex = 0;
unsigned long startPlaybackTime = 0;

uint8_t currentCol = 0;
uint8_t currentRow = 0;

void printFittedWord(const char* word) {
  int len = strlen(word);
  bool isCapital = (word[0] >= 'A' && word[0] <= 'Z');

  if (isCapital && (currentCol > 0 || currentRow > 0)) {
    lcd.clear();
    currentRow = 0;
    currentCol = 0;
  } 
  else if (currentCol > 0 && (currentCol + 1 + len > 16)) {
    if (currentRow == 0) {
      currentRow = 1;
      currentCol = 0;
    } else {
      lcd.clear();
      currentRow = 0;
      currentCol = 0;
    }
  }

  if (currentCol > 0) {
    lcd.setCursor(currentCol, currentRow);
    lcd.print(" ");
    currentCol++;
  }

  lcd.setCursor(currentCol, currentRow);
  lcd.print(word);
  currentCol += len;
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("@rence.szkyrob");
  delay(1300);
  lcd.clear();
  startPlaybackTime = millis();
}

void loop() {
  unsigned long elapsed = millis() - startPlaybackTime;
  if (currentWordIndex < totalWords) {
    if (elapsed >= lyrics[currentWordIndex].timeMs) {
      printFittedWord(lyrics[currentWordIndex].word);
      currentWordIndex++;
    }
  }
}