#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Palitan ang 0x27 kung 0x3F ang address ng iyong LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordStep {
  unsigned long timeMs;
  const char* word;
  uint8_t col;
  uint8_t row;
  bool clearScreen;
};

const WordStep lyrics[] = {
  // --- PAIR 1 ---
  {  1520, "And",      0, 0, true },
  {  1800, "it's",     4, 0, false },
  {  2040, "all",      9, 0, false },
  {  2300, "because",  0, 1, false },

  // --- PAIR 2 ---
  {  3320, "I",        0, 0, true },
  {  3520, "see",      2, 0, false },
  {  3840, "the",      0, 1, false },
  {  4100, "galaxies", 4, 1, false },

  // --- PAIR 3 ---
  {  4880, "when",     0, 0, true },
  {  5140, "I",        5, 0, false },
  {  5400, "look",     7, 0, false },
  {  5660, "in",       0, 1, false },
  {  5880, "your",     3, 1, false },
  {  6200, "eyes",     8, 1, false },

  // --- PAIR 4 ---
  {  6680, "and",      0, 0, true },
  {  6920, "I",        4, 0, false },
  {  7620, "can't",    6, 0, false },
  {  8120, "speak",    0, 1, false },

  // --- PAIR 5 ---
  {  8700, "no",       0, 0, true },
  {  9020, "I",        3, 0, false },
  {  9700, "can't",    5, 0, false },
  { 10200, "speak",    0, 1, false },
  { 10840, "at",       6, 1, false },
  { 11100, "all",      9, 1, false },

  // --- PAIR 6 ---
  { 11540, "I",        0, 0, true },
  { 11720, "swear",    2, 0, false },
  { 12080, "to",       8, 0, false },
  { 12300, "Zeus",    11, 0, false },
  { 12600, "you're",   0, 1, false },
  { 12880, "Aphrodite",7, 1, false },

  // --- PAIR 7 ---
  { 13900, "in",       0, 0, true },
  { 14080, "disguise", 3, 0, false },
  { 15100, "don't",    0, 1, false },
  { 15360, "think",    6, 1, false },

  // --- PAIR 8 ---
  { 15620, "that",     0, 0, true },
  { 15920, "you",      5, 0, false },
  { 16100, "can",      9, 0, false },
  { 16400, "hide",     0, 1, false },
  { 16720, "it",       5, 1, false },
  { 16880, "from",     8, 1, false },
  { 17200, "me",      13, 1, false },

  // --- PAIR 9 (Kasya na ang buong "thought I'd get") ---
  { 18720, "Oh",       0, 0, true },
  { 18960, "no",       3, 0, false },
  { 19240, "I",        6, 0, false },
  { 19460, "never",    8, 0, false },
  { 19960, "thought",  0, 1, false },
  { 20320, "I'd",      8, 1, false },
  { 20500, "get",     12, 1, false },

  // --- PAIR 10 (Inilipat dito ang "this") ---
  { 20740, "this",     0, 0, true },
  { 20980, "close",    5, 0, false },
  { 21300, "to",      11, 0, false },
  { 21500, "someone",  0, 1, false },

  // --- PAIR 11 ---
  { 22020, "so",       0, 0, true },
  { 22300, "divine",   3, 0, false },

  // --- PAIR 12 ---
  { 23140, "Oh",       0, 0, true },
  { 23380, "I",        3, 0, false },
  { 24060, "can't",    5, 0, false },
  { 24600, "breathe",  0, 1, false },
  { 25140, "no",       8, 1, false },
  { 25440, "I",       11, 1, false },

  // --- PAIR 13 ---
  { 26140, "can't",    0, 0, true },
  { 26680, "breathe",  6, 0, false },
  { 27260, "at",       0, 1, false },
  { 27520, "all",      3, 1, false },

  // --- PAIR 14 ---
  { 28144, "Aphrodite",0, 0, true },
  { 29456, "could",    0, 1, false },
  { 29714, "you",      6, 1, false },

  // --- PAIR 15 ---
  { 29738, "could",    0, 0, true },
  { 30050, "you",      6, 0, false },
  { 30336, "please",   0, 1, false },
  { 30674, "be",       7, 1, false },
  { 30924, "mine",    10, 1, false },

  // --- PAIR 16 ---
  { 31705, "oh,",      0, 0, true },
  { 34017, "could",    4, 0, false },
  { 33391, "you",     10, 0, false },
  { 34774, "please",   0, 1, false },
  { 35053, "be",       7, 1, false },
  { 35488, "mine",    10, 1, false },

  // --- PAIR 17 ---
  { 35822, "oh, ",       0, 0, true },
  { 36229, " mine :D",     3, 0, false }
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