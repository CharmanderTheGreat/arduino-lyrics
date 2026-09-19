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
  {   2800, "Sapat",          0, 0, true  },
  {   3820, "na",             6, 0, false },
  {   4100, "sakin",          9, 0, false },
  {   4820, "ang",            0, 1, false },
  {   5480, "ganito",         4, 1, false },
  {   7460, "ooh",           11, 1, false },
  {  11160, "Ang",            0, 0, true  },
  {  11440, "pagmasdan",      4, 0, false },
  {  12440, "ka",            14, 0, false },
  {  13480, "sa",             0, 1, false },
  {  13820, "malayo",         3, 1, false },
  {  18820, "Kapag",          0, 0, true  },
  {  19500, "kinausap",       6, 0, false },
  {  22800, "walang",         0, 1, false },
  {  23480, "masagot",        7, 1, false },
  {  26800, "Hininga'y lagot", 0, 0, true  },
  {  31800, "Hindi",          0, 0, true  },
  {  34140, "ko",             6, 0, false },
  {  35780, "naman",          9, 0, false },
  {  36460, "yata",           0, 1, false },
  {  37500, "ikamamatay",     5, 1, false },
  {  39500, "kung",           0, 0, true  },
  {  39820, "hindi",          5, 0, false },
  {  42140, "ko",            11, 0, false },
  {  43500, "mahawakan",      0, 1, false },
  {  45520, "ang",           10, 1, false },
  {  45880, "iyong",          0, 0, true  },
  {  46780, "kamay",        6, 0, false },
  {  47820, "Handa",          0, 0, true  },
  {  48460, "akong",          6, 0, false },
  {  49480, "mabuhay",        0, 1, false },
  {  50460, "sa",             8, 1, false },
  {  51120, "aking",         11, 1, false },
  {  51460, "kalokohan",    0, 0, true  },
  {  55480, "Kung",           0, 0, true  },
  {  55840, "wala",           5, 0, false },
  {  56460, "ka",            10, 0, false },
  {  57460, "sa",            13, 0, false },
  {  57780, "aking",          0, 1, false },
  {  58160, "buhay,",         6, 1, false },
  {  58840, "walang",         0, 0, true  },
  {  59460, "kalungkutan",    0, 1, false }
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