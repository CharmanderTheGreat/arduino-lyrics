#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {     70, "Just" },
  {   1140, "one" },
  {   1540, "ticket" },
  {   2080, "out" },
  {   2460, "of" },
  {   2580, "your" },
  {   3220, "heavy" },
  {   3760, "gaze" },
  {   4240, "I" },
  {   4280, "want" },
  {   5460, "one" },
  {   5820, "ticket" },
  {   6120, "off" },
  {   6540, "of" },
  {   6860, "your" },
  {   7320, "carousel" },
  {   7880, "I" },
  {   8040, "want" },
  {   9760, "one" },
  {  10080, "ticket" },
  {  10540, "out" },
  {  11060, "of" },
  {  11200, "your" },
  {  12040, "heavy" },
  {  12200, "gaze" },
  {  12680, "I" },
  {  12840, "want" },
  {  14040, "one" },
  {  14400, "ticket" },
  {  15040, "off" },
  {  15360, "of" },
  {  15460, "your" },
  {  15880, "carousel" },
  {  18300, "Only," },
  {  18800, "you" },  
  {  19080, "should" },
  {  19500, "know" },
  {  20320, "that" },
  {  21060, "I" },
  {  21200, "died" },
  {  21640, "slow" },
  {  23000, "Running" },
  {  23520, "through" },
  {  24460, "the" },
  {  24710, "halls" },
  {  25090, "of" },
  {  25250, "your" },
  {  25550, "haunted" },
  {  26320, "home" },
  {  26540, "And" },
  {  26980, "the" },  
  {  27290, "toughest" },
  {  28090, "part" },
  {  29010, "is" },
  {  29190, "that" },
  {  29470, "we" },
  {  29730, "both" },
  {  30230, "know" },
  {  31070, "What" },
  {  31630, "happened" },
  {  32170, "to" },
  {  32490, "you" },
  {  32970, "Why" },
  {  33370, "you're" },
  {  33910, "out" },
  {  34150, "on" },
  {  34290, "your" },
  {  34870, "own" },
  {  36130, "Merry" },
  {  36630, "christmas," },
  {  37990, "please" },
  {  38430, "don't" },
  {  38830, "call" },
  {  40470, "Merry" },
  {  40990, "christmas," },
  {  41910, "I'm" },
  {  42110, "not" },
  {  42350, "yours" },
  {  42810, "at" },
  {  43050, "all" },
  {  44590, "Merry" },
  {  45190, "christmas," },
  {  46550, "please" },
  {  47150, "dont" },
  {  47610, "call" }
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