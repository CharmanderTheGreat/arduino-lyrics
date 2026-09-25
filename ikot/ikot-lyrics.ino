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
  {  900, "Pauulit-",       0, 0, true  },
  {  1820, "ulit",          8, 0, false },
  {  2320, "na",           13, 0, false },
  {  2600, "lang",          0, 1, false },
  {  4200, "sinasabi",      5, 1, false },
  {  6520, "Pero",          0, 0, true  },
  {  7120, "'di",           5, 0, false },
  {  7700, "ko",            0, 1, false },
  {  7960, "naman",         3, 1, false },
  {  8760, "pinaninindigan",0, 0, true  },
  {  11160, "Oh,",           0, 1, false },
  {  13520, "palaging",      4, 1, false },
  {  15780, "nagdadalawang", 0, 0, true  },
  {  17960, "isip",          0, 1, false },
  {  18860, "Paulit-",        0, 0, true  },
  {  19780, "ulit",          7, 0, false },
  {  20280, "ko",           12, 0, false },
  {  20560, "lang",          0, 1, false },
  {  22220, "sinasabi",      5, 1, false },
  {  24440, "Sa",            0, 0, true  },
  {  24720, "sarili",        3, 0, false },
  {  26180, "ko",           10, 0, false },
  {  26720, "ang",           0, 1, false },
  {  26980, "mga",           4, 1, false },
  {  27900, "hindi",         8, 1, false },
  {  28000, "Mabitawang",    0, 0, true  },
  {  31160, "salita",        0, 1, false },
  {  32880, "para",          7, 1, false },
  {  33660, "sayo",        12, 1, false },
  {  38260, "Ikaw",          0, 0, true  },
  {  39040, "lang",          5, 0, false },
  {  39340, "at",            0, 1, false },
  {  39640, "ikaw",          3, 1, false },
  {  40780, "Ang",           0, 0, true  },
  {  41280, "sinisigaw",     4, 0, false },
  {  42800, "ng",            0, 1, false },
  {  42980, "puso",          3, 1, false },
  {  43800, "kong",          0, 0, true  },
  {  44100, "'di",           5, 0, false },
  {  44320, "mapakali",      0, 1, false },
  {  47220, "Ikaw",          0, 0, true  },
  {  48060, "lang",          5, 0, false },
  {  48360, "at",            0, 1, false },
  {  48640, "ikaw",          3, 1, false },
  {  49740, "Ang",           0, 0, true  },
  {  50300, "sinisigaw",     4, 0, false },
  {  51660, "Pag-ibig",      0, 1, false },
  {  52760, "ko'y",          0, 0, true  },
  {  53040, "sana",          5, 0, false },
  {  53620, "mapansin",      0, 1, false };
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