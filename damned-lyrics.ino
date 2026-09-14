#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordStep {
  unsigned long timeMs;
  const char* word;
  uint8_t col;
  uint8_t row;
  bool clearScreen;
};

const WordStep lyrics[] = {
  {   300, "Two",          0, 0, true  },
  {   720, "hearts",       4, 0, false },
  {  1040, "committed",    0, 1, false },
  {  2100, "to",          10, 1, false },
  {  2500, "hopeless",     0, 0, true  },
  {  3220, "fate",         9, 0, false },
  {  4340, "I'd",          0, 1, false },
  {  4740, "serve",        4, 1, false },
  {  5160, "my",          10, 1, false },
  {  5440, "life",         0, 0, true  },
  {  5860, "sentence",     5, 0, false },
  {  6580, "a",           14, 0, false },
  {  6940, "thousand",     0, 1, false },
  {  7680, "times,",       9, 1, false },
  {  8120, "woman",        0, 0, true  },
  {  8920, "When",         0, 1, false },
  {  9080, "the",          5, 1, false },
  {  9220, "gavel",        9, 1, false },
  {  9800, "hit",          0, 0, true  },
  {  9900, "the",          4, 0, false },
  { 10000, "stand",        8, 0, false },
  { 11180, "I'm",          0, 1, false },
  { 11480, "damned",       4, 1, false },
  { 11860, "to",          11, 1, false },
  { 12000, "loving",       0, 0, true  },
  { 12280, "you",          7, 0, false },
  { 13360, "Two",          0, 1, false },
  { 13640, "palm",         4, 1, false },
  { 13940, "trees",        9, 1, false },
  { 14260, "in",           0, 0, true  },
  { 14360, "the",          3, 0, false },
  { 14500, "sand",         7, 0, false },
  { 15580, "I'm",          0, 1, false },
  { 15900, "damned",       4, 1, false },
  { 16590, "to",          11, 1, false },
  { 16700, "loving",       0, 0, true  },
  { 17040, "you",          7, 0, false },
  { 17520, "now",         11, 0, false }
};

const int totalWords = sizeof(lyrics) / sizeof(lyrics[0]);
int currentWordIndex = 0;
unsigned long startPlaybackTime = 0;

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
      if (lyrics[currentWordIndex].clearScreen) {
        lcd.clear();
      }
      lcd.setCursor(lyrics[currentWordIndex].col, lyrics[currentWordIndex].row);
      lcd.print(lyrics[currentWordIndex].word);
      currentWordIndex++;
    }
  }
}