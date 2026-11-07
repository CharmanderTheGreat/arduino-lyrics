#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {   340, "I" },
  {   380, "would" },
  {   760, "rather" },
  {  1620, "burn" },
  {  2180, "forever" },
  {  3740, "But" },
  {  4040, "you" },
  {  4380, "should" },
  {  4760, "know" },
  {  5600, "that" },
  {  6340, "I" },
  {  6480, "died" },
  {  6880, "slow" },
  {  8310, "running" },
  {  8890, "through" },
  {  9350, "the" },
  {  9770, "halls" },
  { 10550, "of" },
  { 10750, "your" },
  { 11050, "haunted" },
  { 11510, "home" },
  { 12390, "And" },
  { 12470, "the" },
  { 12570, "toughest" },
  { 13370, "part" },
  { 14310, "is" },
  { 14470, "that" },
  { 14770, "we" },
  { 15030, "both" },
  { 15510, "know" },
  { 16350, "What" },
  { 16930, "happened" },
  { 17410, "to" },
  { 17670, "you" },
  { 18470, "Why" },
  { 18890, "you're" },
  { 19190, "out" },
  { 19430, "on" },
  { 19570, "your" },
  { 20050, "own" },
  { 21410, "Merry" },
  { 21910, "christmas" },
  { 23280, "please" },
  { 23720, "don't" },
  { 24100, "call" },
  { 25760, "Merry" },
  { 26280, "christmas" },
  { 27200, "I'm" },
  { 27400, "not" },
  { 27640, "yours" },
  { 28300, "at" },
  { 29000, "all" },
  { 29880, "Merry" },
  { 30480, "christmas" },
  { 31840, "please" },
  { 32460, "don't" },
  { 32900, "call" },
  { 33560, "me" }
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