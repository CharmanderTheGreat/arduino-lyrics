#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {     40, "You're" },
  {   1040, "the" },
  {   1400, "best" },
  {   2620, "And" },
  {   2860, "yes," },
  {   3600, "I" },
  {   3940, "do" },
  {   4200, "regret" },
  {   6060, "How" },
  {   6600, "I" },
  {   7340, "could" },
  {   7760, "let" },
  {   8940, "myself" },
  {  10940, "let" },
  {  12100, "you" },
  {  12420, "go?" },
  {  14240, "Now," },
  {  15900, "now" },
  {  16300, "the" },
  {  16720, "lesson's" },
  {  17500, "learned" },
  {  18880, "I" },
  {  19140, "touched" },
  {  19800, "it," },
  {  20000, "I" },
  {  20320, "was" },
  {  20560, "burned" },
  {  22220, "Oh," },
  {  22560, "I" },
  {  23580, "think" },
  {  23920, "you" },
  {  25240, "should" },
  {  25660, "know" },
  {  26520, "'Cause" },
  {  26920, "when" },
  {  27920, "I'm" },
  {  28160, "with" },
  {  29040, "him," },
  {  29820, "I" },
  {  30140, "am" },
  {  31020, "Thinking" },
  {  31640, "of" },
  {  32020, "you" },
  {  34260, "Thinking" },
  {  35000, "of" },
  {  35300, "you" },
  {  36300, "Oh," },
  {  37560, "what" },
  {  37960, "you" },
  {  38340, "would" },
  {  38760, "do" },
  {  39420, "if" },
  {  40400, "You" },
  {  41200, "were" },
  {  41840, "the" },
  {  42120, "one" },
  {  42840, "who" },
  {  43200, "was" },
  {  43970, "spending" },
  {  44890, "the" },
  {  45110, "night" },
  {  47350, "Oh," },
  {  47590, "I" },
  {  47950, "wish" },
  {  48550, "that" },
  {  49410, "I" },
  {  49930, "Was" },
  {  50330, "looking" },
  {  51030, "into" },
  {  51790, "your" },
  {  52150, "eyes" }
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