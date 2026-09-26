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
  {    280, "Mahal,",     0, 0, true  },
  {   1100, "ikaw",      7, 0, false },
  {   2100, "ang",       0, 1, false },
  {   2640, "uuwian",    4, 1, false },
  {   7060, "At",        0, 0, true  },
  {   7540, "kung",      3, 0, false },
  {   8100, "umabot",    8, 0, false },
  {   9340, "man",       0, 1, false },
  {  10060, "sa",        4, 1, false },
  {  10600, "dulo",      7, 1, false },
  {  12060, "at",        0, 0, true  },
  {  12840, "tatanda",   3, 0, false },
  {  14060, "na",       11, 0, false },
  {  14560, "tayo",      0, 1, false },
  {  16320, "Ikaw",      0, 0, true  },
  {  17080, "pa",        5, 0, false },
  {  17340, "rin",       8, 0, false },
  {  18080, "ang",       0, 1, false },
  {  18580, "uuwian",    4, 1, false },
  {  23040, "At",        0, 0, true  },
  {  23560, "kahit",     3, 0, false },
  {  24560, "na",        9, 0, false },
  {  25080, "maghirap",  0, 1, false },
  {  26580, "tayo,",     9, 1, false },
  {  28100, "'di",       0, 0, true  },
  {  29080, "na",        4, 0, false },
  {  29560, "magbabago", 0, 1, false },
  {  34220, "Ikaw",      0, 0, true  },
  {  35120, "pa",        5, 0, false },
  {  35400, "rin",       8, 0, false },
  {  36100, "ang",       0, 1, false },
  {  36600, "uuwian",    4, 1, false }
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