#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {   480, "Oh," },
  {  1000, "I" },
  {  1360, "don't" },
  {  1860, "care" },
  {  2420, "if" },
  {  2720, "you're" },
  {  3700, "insincere" },
  {  6920, "Just" },
  {  7200, "tell" },
  {  7660, "me" },
  {  8060, "what" },
  {  8400, "I" },
  {  8980, "wanna" },
  {  9680, "hear" },
  { 12300, "You" },
  { 12460, "know" },
  { 12920, "where" },
  { 13440, "to" },
  { 13660, "find" },
  { 14060, "me" },
  { 14960, "The" },
  { 15120, "place" },
  { 15660, "where" },
  { 16080, "we" },
  { 16280, "lived" },
  { 16960, "all" },
  { 17360, "these" },
  { 18180, "years," },
  { 19420, "oh" },
  { 22730, "and" },
  { 23110, "tell" },
  { 23630, "me" },
  { 23970, "you" },
  { 24230, "love" },
  { 24630, "me" },
  { 25750, "That's" },
  { 26290, "all" },
  { 26630, "that" },
  { 26890, "I" },
  { 27530, "need" },
  { 27970, "to" },
  { 28970, "hear" }
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