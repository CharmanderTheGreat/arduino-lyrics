# Merry Christmas, Please Don't Call by Bleachers using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Merry Christmas, Please Don't Call**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Merry Christmas, Please Don't Call
- **Artist:** Bleachers
 
## Lyrics File (.lrc)

The `merrychristmaspleasedontcall-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.70]Just
[00:01.14]one
[00:01.54]ticket
[00:02.08]out
[00:02.46]of
[00:02.58]your
[00:03.22]heavy 
[00:03.76]gaze
[00:04.24]I 
[00:04.28]want 
[00:05.46]one 
[00:05.82]ticket 
[00:06.12]off 
[00:06.54]of 
[00:06.86]your 
[00:07.32]carousel 
[00:07.88]I 
[00:08.04]want 
[00:09.76]one 
[00:10.08]ticket 
[00:10.54]out 
[00:11.06]of 
[00:11.20]your 
[00:12.04]heavy 
[00:12.20]gaze 
[00:12.68]I 
[00:12.84]want 
[00:14.04]one 
[00:14.40]ticket 
[00:15.04]off 
[00:15.36]of 
[00:15.46]your 
[00:15.88]carousel 
[00:18.30]Only, 
[00:18.80]you 
[00:19.08]should 
[00:19.50]know 
[00:20.32]that 
[00:21.06]I 
[00:21.20]died
[00:21.64]slow 
[00:23.00]Running 
[00:23.52]through 
[00:24.46]the 
[00:24.71]halls 
[00:25.09]of 
[00:25.25]your 
[00:25.55]haunted 
[00:26.32]home 
[00:26.54]And 
[00:26.98]the 
[00:27.29]toughest 
[00:28.09]part 
[00:29.01]is 
[00:29.19]that 
[00:29.47]we 
[00:29.73]both 
[00:30.23]know 
[00:31.07]What 
[00:31.63]happened 
[00:32.17]to 
[00:32.49]you 
[00:32.97]Why 
[00:33.37]you're 
[00:33.91]out 
[00:34.15]on 
[00:34.29]your 
[00:34.87]own 
[00:36.13]Merry
[00:36.63]christmas, 
[00:37.99]please 
[00:38.43]don't 
[00:38.83]call
[00:40.47]Merry 
[00:40.99]christmas, 
[00:41.91]I'm 
[00:42.11]not 
[00:42.35]yours 
[00:42.81]at 
[00:43.05]all 
[00:44.59]Merry
[00:45.19]christmas,
[00:46.55]please
[00:47.15]don't 
[00:47.61]call
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `merrychristmaspleasedontcall-lyrics.ino` from this repo in Arduino IDE.
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
| `merrychristmaspleasedontcall-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `merrychristmaspleasedontcall-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.