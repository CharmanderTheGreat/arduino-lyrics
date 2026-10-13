#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  { 4480, "Ako'y" },
  { 5100, "alpin" },
  {   6100, "mo" },
  {   6460, "kahit" },
  {   7700, "hindi" },
  {   8080, "batid" },
  {   11620, "Aaminin" },
  {   12360, "ko" },
  {   12940, "minsan" },
  {   13800, "ako'y" },
  {  14580, "manhid" },
  {  16980, "Sana" },
  {  17920, "ay" },
  {  19800, "iyong" },
  {  20180, "naririnig" },
  {  24040, "Sa'yong" },
  {  24640, "yakap" },
  {  25880, "ako'y" },
  {  26640, "nasasabik" },
  {  29960, "'Pagkat" },
  {  30840, "ikaw" },
  {  31300, "lang" },
  {  31880, "ang" },
  {  32220, "nais" },
  {  33000, "makatabi" },
  {  36640, "Malamig" },
  {  37880, "man" },
  {  38360, "o" },
  {  38680, "mainit" },
  {  39920, "ang" },
  {  40280, "gabi" },
  {  42680, "Nais" },
  {  43460, "ko" },
  {  44270, "sana"},
  {  45910, "iparating"},  
  {  49410, "na"},
  {  50020, "ikaw"},
  {  50560, "lamang"},
  {  52600, "Ang"},
  {  52880, "siyang"},
  {  53370, "aking"},
  {  58870, "iibigin"},
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