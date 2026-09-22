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
  {   1080, "Hindi",       0, 0, true  },
  {   1700, "ko",          6, 0, false },
  {   2000, "maiwasan",    0, 1, false },
  {   3280, "na",          9, 1, false },
  {   3780, "isipin",      0, 0, true  },
  {   5440, "ka",          7, 0, false },
  {   6080, "Tanong",      0, 0, true  },
  {   6700, "sa",          7, 0, false },
  {   7020, "hangin",     10, 0, false },
  {   7620, "kung",        0, 1, false },
  {   8000, "ako",         5, 1, false },
  {   8600, "ba'y",        9, 1, false },
  {   8860, "naiisip",     0, 0, true  },
  {  10500, "mo",          8, 0, false },
  {  11340, "Litong-lito,", 0, 0, true  },
  {  13820, "litong-lito", 0, 1, false },
  {  16360, "Sa'yo,",      0, 0, true  },
  {  17600, "sa'yo,",      7, 0, false },
  {  18840, "sa'yo,",      0, 1, false },
  {  20080, "sa'yo",       7, 1, false },
  {  21300, "Sino",        0, 0, true  },
  {  22000, "ba",          5, 0, false },
  {  22320, "naman",       8, 0, false },
  {  22980, "ako",         0, 1, false },
  {  23540, "para",        4, 1, false },
  {  24200, "isipin",      9, 1, false },
  {  25460, "mo",          0, 0, true  },
  {  26080, "Hindi",       0, 0, true  },
  {  26680, "mo",          6, 0, false },
  {  27000, "ba",          9, 0, false },
  {  27320, "hinihintay",  0, 1, false },
  {  28600, "ang",         0, 0, true  },
  {  28860, "mga",         4, 0, false },
  {  29480, "tawag",       8, 0, false },
  {  30420, "ko",          0, 1, false },
  {  31340, "Sa'yo,",      0, 0, true  },
  {  32620, "sa'yo,",      7, 0, false },
  {  33840, "sa'yo,",      0, 1, false },
  {  35120, "sa'yo'y",     7, 1, false },
  {  36360, "Litong-lito,", 0, 0, true  },
  {  38860, "litong-lito", 0, 1, false }
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