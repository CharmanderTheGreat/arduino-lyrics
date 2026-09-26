# Libu-Libong Buwan by Kyle Raphael Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Libu-Libong Buwan**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Libu-Libong Buwan
- **Artist:** Kyle Raphael
 
## Lyrics File (.lrc)

The `libulibongbuwan-lyrics.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.28]Mahal,
[00:01.10]ikaw
[00:02.10]ang
[00:02.64]uuwian
[00:07.06]At
[00:07.54]kung
[00:08.10]umabot
[00:09.34]man
[00:10.06]sa
[00:10.60]dulo
[00:12.06]at
[00:12.84]tatanda
[00:14.06]na
[00:14.56]tayo
[00:16.32]Ikaw
[00:17.08]pa
[00:17.34]rin
[00:18.08]ang
[00:18.58]uuwian
[00:23.04]At
[00:23.56]kahit
[00:24.56]na
[00:25.08]maghirap
[00:26.58]tayo,
[00:28.10]'di
[00:29.08]na
[00:29.56]magbabago
[00:34.22]Ikaw
[00:35.12]pa
[00:35.40]rin
[00:36.10]ang
[00:36.60]uuwian
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `libulibongbuwan-lyrics.ino` from this repo in Arduino IDE.
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
| `libulibongbuwan-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `libulibongbuwan-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
