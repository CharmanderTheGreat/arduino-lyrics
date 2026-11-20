#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {     20, "Terranova," },
  {   2080, "i'll" },
  {   2800, "find" },
  {   3300, "you" },
  {   4080, "I" },
  {   4520, "don't" },
  {   4980, "mind" },
  {   5620, "if" },
  {   5740, "you're" },
  {   6260, "far" },
  {   7000, "away" },
  {   8480, "Terranova," },
  {  10240, "so" },
  {  10430, "far" },
  {  10950, "away" },
  {  12080, "Terranova," },
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
  {  24570, "Dammmmm" },
  {  24830, "dammmmm" },
  {  25350, "dii" },
  {  25570, "dii" },
  {  25830, "dii" },
  {  26050, "dii" },
  {  26310, "Dammmmm" },
  {  26810, "dammmmm" },
  {  27330, "dii" },
  {  27550, "dii" },  
  {  27790, "dii" },
  {  28030, "dii" },
  {  28290, "Dammmmm" },
  {  28810, "dammmmm" },
  {  29310, "dii" },
  {  29550, "dii" },
  {  29790, "dii" },
  {  30030, "dii" },
  {  30130, "Dammmmm" },
  {  30810, "dammmmm" },
  {  31270, "dii" },
  {  31530, "dii" },
  {  31770, "dii" },
  {  32030, "dii" },
  {  32270, "Dammmmm" },
  {  32770, "dammmmm" },  
  {  33270, "dii" },
  {  33520, "dii" },
  {  33760, "dii" },
  {  33990, "dii" },
  {  34260, "Dammmmm" },
  {  34760, "dammmmm" },
  {  35280, "dii" },
  {  35500, "dii" },
  {  35740, "dii" },
  {  35980, "dii" },
  {  36240, "Dammmmm" },
  {  36740, "dammmmm" },
  {  36260, "dii" },
  {  37480, "dii" },
  {  37740, "dii" },
  {  37960, "dii" },
  {  38220, "Dammmmm" },
  {  38720, "dammmmm" },
  {  39220, "dii" },
  {  39480, "dii" },
  {  39720, "dii" },
  {  39960, "dii" }
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