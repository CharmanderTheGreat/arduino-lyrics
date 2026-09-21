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
  {   2140, "Walang",      0, 0, true  },
  {   2600, "sagot",       7, 0, false },
  {   4020, "sa",          0, 1, false },
  {   4280, "tanong",      3, 1, false },
  {   6680, "Kung",        0, 0, true  },
  {   6940, "bakit",       5, 0, false },
  {   7660, "ka",         11, 0, false },
  {   8660, "mahalaga",    0, 1, false },
  {  11960, "Walang",      0, 0, true  },
  {  12700, "papantay",    7, 0, false },
  {  14120, "sa'yo",       0, 1, false },
  {  15820, "Maging",      0, 0, true  },
  {  16500, "sino",        7, 0, false },
  {  17280, "man",        12, 0, false },
  {  17740, "sila",        0, 1, false },
  {  27320, "Walang",      0, 0, true  },
  {  27980, "papantay",    7, 0, false },
  {  29360, "sa'yo",       0, 1, false },
  {  31260, "Maging",      0, 0, true  },
  {  32080, "sino",        7, 0, false },
  {  32740, "man",        12, 0, false },
  {  33220, "sila",        0, 1, false }
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