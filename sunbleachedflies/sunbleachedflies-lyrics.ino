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
  {    420, "But",       0, 0, true  },
  {    660, "I",         4, 0, false },
  {   1140, "always",    6, 0, false },
  {   1960, "knew",      0, 1, false },
  {   2980, "that",      5, 1, false },
  {   3420, "in",       10, 1, false },
  {   3840, "the",      13, 1, false },
  {   4140, "end",       0, 0, true  },
  {   5140, "no",        4, 0, false },
  {   5580, "one",       7, 0, false },
  {   6020, "was",      11, 0, false },
  {   6360, "coming",    0, 1, false },
  {   8120, "to",        7, 1, false },
  {   8480, "save",     10, 1, false },
  {   9060, "me",        0, 0, true  },
  {   9580, "so",        3, 0, false },
  {   9860, "I",         6, 0, false },
  {  10160, "just",      0, 1, false },
  {  10660, "prayed",    5, 1, false },
  {  13900, "and",       0, 0, true  },
  {  14260, "I",         4, 0, false },
  {  14540, "keep",      6, 0, false },
  {  14940, "praying",   0, 1, false },
  {  16920, "and",       0, 0, true  },
  {  17180, "praying",   4, 0, false },
  {  19080, "and",       0, 1, false },
  {  19400, "praying",   4, 1, false },
  {  19700, "If",        0, 0, true  },
  {  20020, "it's",        3, 0, false },
  {  20720, "meant",     8, 0, false },
  {  21260, "to",        0, 1, false },
  {  21560, "be",        3, 1, false },
  {  22280, "then",      0, 0, true  },
  {  22740, "it",        5, 0, false },
  {  23160, "will",      0, 1, false },
  {  23780, "be",        5, 1, false },
  {  27260, "So",        0, 0, true  },
  {  27600, "I",         3, 0, false },
  {  27900, "met",       5, 0, false },
  {  28820, "him",       9, 0, false },
  {  29340, "there",     0, 1, false },
  {  29760, "and",       6, 1, false },
  {  30280, "told",     10, 1, false },
  {  30840, "him",       0, 0, true  },
  {  31680, "I",         4, 0, false },
  {  32200, "believe",   6, 0, false },
  {  36570, "Singing",   0, 1, false },
  {  37170, "if",        8, 1, false },
  {  37450, "it's",       11, 1, false },
  {  38190, "meant",     0, 0, true  },
  {  38690, "to",        6, 0, false },
  {  39090, "be",        9, 0, false },
  {  40130, "then",      0, 1, false },
  {  40490, "it'll",     5, 1, false },
  {  41230, "be",       11, 1, false },
  {  45250, "I",         0, 0, true  },
  {  45590, "forgive",   2, 0, false },
  {  46170, "it",       10, 0, false },
  {  46910, "all",       0, 1, false },
  {  47550, "as",        4, 1, false },
  {  47830, "it",        7, 1, false },
  {  48250, "comes",     0, 0, true  },
  {  49070, "back",      6, 0, false },
  {  49630, "to",       11, 0, false },
  {  49930, "me",       14, 0, false }
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