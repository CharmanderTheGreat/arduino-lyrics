#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordStep lyrics[] = {
  {  1500, "I'm" },
  {  1680, "gonna" },
  {  2060, "work" },
  {  2400, "on" },
  {  2740, "my" },
  {  3040, "temper" },
  {  3620, "While" },
  {  3920, "you" },
  {  4100, "learn" },
  {  4420, "to" },
  {  4540, "speak" },
  {  4940, "your" },
  {  5240, "mind" },
  {  5580, "some" },
  {  5780, "more" },
  {  6980, "I'll" },
  {  7200, "be" },
  {  7460, "more" },
  {  7860, "of" },
  {  8240, "a" },
  {  8480, "shelter", },
  {  9860, "and" },
  { 10180, "less" },
  { 10580, "of" },
  { 10960, "a" },
  { 11160, "storm" },
  { 12240, "While" },
  { 12460, "we" },
  { 12800, "both" },
  { 13140, "are" },
  { 13460, "working" },
  { 14140, "on" },
  { 14500, "ourselves" },
  { 15680, "in" },
  { 15880, "our" },
  { 16260, "own" },
  { 16700, "ways"},
  { 17340, "I" },
  { 17500, "just" },
  { 17700, "wanna" },
  { 18120, "be" },
  { 18740, "with" },
  { 18940, "you" },
  { 19600, "every" },
  { 20240, "single" },
  { 20980, "day" },
  { 22820, "Oh," },
  { 23000, "I" },
  { 23160, "wanna" },
  { 23540, "be" },
  { 24160, "with" },
  { 24400, "you" },
  { 25060, "every" },
  { 25700, "single" },
  { 26260, "day" },
  { 30280, "For" },
  { 30480, "the" },
  { 30680, "rest" },
  { 31040, "of" },
  { 31200, "our" },
  { 31680, "lives" }
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