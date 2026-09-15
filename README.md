# Totoong Tayo by Jin DC Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Totoong Tayo**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Totoong Tayo
- **Artist:** Jin DC
 
## Lyrics File (.lrc)

The `totoongtayo-lyrics.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.58]Kitang-kita
[00:01.98]na
[00:02.66]sa
[00:02.92]kilos
[00:03.87]mong
[00:04.76]kakaiba,
[00:07.08]ooh,
[00:08.55]ako
[00:08.95]pa
[00:09.24]ba?
[00.09.64]oh
[00:14.10]Ikaw
[00:14.86]at
[00:15.33]ako
[00:18.52]Ang
[00:19.24]magkasama
[00:22.23]sa
[00:22.47]mga
[00:23.03]alaala
[00:25.41]Puwede
[00:27.41]bang
[00:30.11]kalimutan
[00:31.77]muna
[00:32.67]natin
[00:33.64]ang
[00:33.98]mundo
[00:37.17]At
[00:37.37]hawakan
[00:38.52]mo
[00:39.55]ang
[00:39.77]kamay
[00:40.90]ko?
[00:41.35]Magmahalan
[00:45.54]na
[00:45.72]walang
[00:46.53]iniisip
[00:48.57]na
[00:48.79]kung
[00:49.25]ano
[00:51.96]Ipakita
[00:53.41]lang
[00:53.95]ang
[00:54.31]totoong
[00:55.97]tayo
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `totoongtayo-lyrics.ino` from this repo in Arduino IDE.
2. Install the `LiquidCrystal_I2C` library via `Sketch > Include Library > Manage Libraries` → search "LiquidCrystal I2C" → install.
3. Select **Board: Arduino Uno** and the correct **COM Port**.
4. Upload the sketch.

## Usage

This is a **visual-only** display. There's no actual audio playback, just the lyrics scrolling in sync with timestamps. To start or replay the sequence from the beginning, reset the board using any of the following:

- **Reset button** — the red button on the Arduino board itself
- **Re-upload the sketch** — re-uploading via Arduino IDE also restarts the board
- **Plug and play** — unplug and replug the USB/power

There's no separate "play" command in software. Resetting the board is what triggers the sequence to play again.

## Files in This Repo

| File | Description |
|------|--------------|
| `totoongtayo-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `totoongtayo-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
