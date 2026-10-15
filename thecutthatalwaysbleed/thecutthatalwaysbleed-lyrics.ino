#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  { 200, "The" },
  { 420, "cut" },
  { 880, "that" },
  { 1280, "always" },
  { 2600, "bleeds" },
  { 12230, "But" },
  { 13010, "even" },
  { 13390, "though" },
  { 13990, "you're" },
  { 14210, "killing" },
  { 14690, "me," },
  { 16150, "yeah" },
  { 19370, "I" },
  { 19510, "need" },
  { 20130, "you" },
  { 20390, "like" },
  { 21010, "the" },
  { 21590, "air" },
  { 21930, "I" },
  { 21990, "breath" },
  { 23230, "I" },
  { 23450, "need," },
  { 23770, "I" },
  { 23910, "need" },
  { 24490, "you" },
  { 24750, "more" },
  { 25190, "than" },
  { 25430, "me" },
  { 26410, "I" },
  { 26850, "need" },
  { 27140, "you" },
  { 27390, "more" },
  { 28050, "than" },
  { 28590, "anything" },
  { 30200, "Please," },
  { 33720, "please" }
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