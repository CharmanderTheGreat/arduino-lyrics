#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordStep {
  unsigned long timeMs;
  const char* word;
  bool clearScreen;
};

const WordStep lyrics[] = {

  // --- LINE 1 ---
  {   220, "I",         true  },
  {  4580, "know",      false },
  {  5040, "a",         false },
  {  5200, "place",     false },

  // --- LINE 2 ---
  {  9940, "It's",      true  },
  { 10200, "somewhere", false },
  { 11260, "I",         false },
  { 11480, "go",        false },
  { 12080, "when",      false },
  { 12480, "I",         false },
  { 12740, "need",      false },
  { 13380, "to",        false },
  { 13680, "remember",   false },

  // --- LINE 3 ---
  { 14960, "your",      true  },
  { 15880, "face",      false },

  // --- LINE 4 ---
  { 19620, "We",        true  },
  { 19960, "get",       false },
  { 20280, "married",   false },
  { 24600, "in",        false },
  { 24980, "our",       false },
  { 25860, "heads",     false },

  // --- LINE 5 ---
  { 30220, "Something", true  },
  { 31280, "to",        false },
  { 31500, "do",        false },
  { 32100, "while",     false },
  { 32440, "we",        false },
  { 32700, "try",       false },
  { 33380, "to",        false },

  // --- LINE 6 ---
  { 33680, "recall",    true  },
  { 34580, "how",       false },
  { 34920, "we",        false },
  { 35860, "met",       false },

  // --- LINE 7 ---
  { 39600, "Do",        true  },
  { 39840, "you",       false },
  { 40200, "think",     false },
  { 41160, "I",         false },
  { 42160, "have",      false },
  { 42400, "forgotten?",false },

  // --- LINE 8 ---
  { 44620, "Do",        true  },
  { 44880, "you",       false },
  { 45180, "think",     false },
  { 46160, "I",         false },
  { 46640, "have",      false },
  { 47420, "forgotten?",false },

  // --- LINE 9 ---
  { 49580, "Do",        true  },
  { 49860, "you",       false },
  { 50200, "think",     false },
  { 51180, "I",         false },
  { 51620, "have",      false },
  { 52420, "forgotten",  false },

  // --- FINAL ---
  { 54640, "About",     true  },
  { 56120, "you?",      false }
};

const int totalWords = sizeof(lyrics) / sizeof(lyrics[0]);

int currentWordIndex = 0;
unsigned long startPlaybackTime = 0;

uint8_t currentCol = 0;
uint8_t currentRow = 0;


// ==============================
// PRINT WORD AUTOMATICALLY
// ==============================
void printWord(const char* word) {

  uint8_t wordLength = strlen(word);

  // Space needed before the next word
  uint8_t neededSpace = (currentCol == 0) ? 0 : 1;

  // If word does not fit on current line
  if (currentCol + neededSpace + wordLength > 16) {

    // Go to next row
    currentRow++;

    currentCol = 0;

    // If already at bottom, clear and start again
    if (currentRow > 1) {
      lcd.clear();

      currentRow = 0;
      currentCol = 0;
    }
  }

  // Add a space if this isn't the beginning of a line
  if (currentCol > 0) {
    lcd.setCursor(currentCol, currentRow);
    lcd.print(" ");
    currentCol++;
  }

  // Print word
  lcd.setCursor(currentCol, currentRow);
  lcd.print(word);

  // Move cursor position
  currentCol += wordLength;
}


// ==============================
// RESET SCREEN
// ==============================
void resetScreen() {

  lcd.clear();

  currentCol = 0;
  currentRow = 0;
}


// ==============================
// SETUP
// ==============================
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


// ==============================
// LOOP
// ==============================
void loop() {

  unsigned long elapsed =
    millis() - startPlaybackTime;

  if (currentWordIndex < totalWords) {

    if (elapsed >= lyrics[currentWordIndex].timeMs) {

      // New phrase
      if (lyrics[currentWordIndex].clearScreen) {
        resetScreen();
      }

      // Print word
      printWord(lyrics[currentWordIndex].word);

      currentWordIndex++;
    }
  }
}
