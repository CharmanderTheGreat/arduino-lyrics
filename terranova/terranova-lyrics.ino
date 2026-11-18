#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {     20, "terranova," },
  {     58, "i'll" },
  {   1040, "find" },
  {   1300, "you" },
  {   2080, "I" },
  {   2520, "don't" },
  {   4980, "mind" },
  {   5620, "if" },
  {   5740, "you're" },
  {   6960, "far" },
  {   8200, "away're" },
  {   8480, "Terranova," },
  {  10240, "so" },
  {  10430, "far" },
  {  10950, "away" },
  {  11080, "Terranova," },
  {  13910, "so" },
  {  14430, "far" },
  {  15010, "away" },
  {  15850, "Terranova," },
  {  17870, "so" },
  {  18370, "far" },
  {  18990, "away" },
  {  19850, "Terranova," },
  {  21830, "so" },
  {  22350, "far" },
  {  23130, "far" },
  {  23950, "away" },
  {  24570, "Dam" },
  {  24830, "dam" },
  {  25350, "di" },
  {  25570, "di" },
  {  25830, "di" },
  {  26050, "di" },
  {  26310, "Dam" },
  {  26810, "dam" },
  {  27330, "di" },
  {  27550, "di" },  
  {  27790, "di" },
  {  28030, "di" },
  {  28290, "Dam" },
  {  28810, "dam" },
  {  29310, "di" },
  {  29550, "di" },
  {  29790, "di" },
  {  30030, "di" },
  {  30130, "Dam" },
  {  30810, "dam" },
  {  31270, "di" },
  {  31530, "di" },
  {  31770, "di" },
  {  32030, "di" },
  {  32270, "Dam" },
  {  32770, "dam" },  
  {  33270, "di" },
  {  33520, "di" },
  {  33760, "di" },
  {  33990, "di" },
  {  34260, "Dam" },
  {  34760, "dam" },
  {  35280, "di" },
  {  35500, "di" },
  {  35740, "di" },
  {  35980, "di" },
  {  36240, "Dam" },
  {  36740, "dam" },
  {  36260, "di" },
  {  37480, "di" },
  {  37740, "di" },
  {  37960, "di" },
  {  38220, "Dam" },
  {  38720, "dam" },
  {  39220, "di" },
  {  39480, "di" },
  {  39720, "di" },
  {  39960, "di" }
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