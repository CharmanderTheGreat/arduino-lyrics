# Terranova by Janina Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Terranova**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Terranova
- **Artist:** Janina
 
## Lyrics File (.lrc)

The `terranova-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.02]Terranova
[00:02.08]i'll
[00:02.80]find
[00:03.30]you
[00:04.08]I
[00:04.52]don't
[00:04.98]mind
[00:05.62]if
[00:05.74]you're
[00:06.26]far
[00:07.00]away
[00:08.48]Terranova
[00:10.24]so
[00:10.43]far
[00:10.95]away
[00:12.08]Terranova
[00:13.91]so
[00:14.43]far
[00:15.01]away
[00:15.85]Terranova
[00:17.87]so
[00:18.37]far
[00:18.99]away
[00:19.85]Terranova
[00:21.83]so
[00:22.35]far
[00:23.13]far
[00:23.95]away
[00:24.57]Dammmmm
[00:24.83]dammmmm
[00:25.35]dii
[00:25.57]dii
[00:25.83]dii
[00:26.05]dii
[00:26.31]Dammmmm
[00:26.81]dammmmm
[00:27.33]dii
[00:27.55]dii  
[00:27.79]dii
[00:28.03]dii
[00:28.29]Dammmmm
[00:28.81]dammmmm
[00:29.31]dii
[00:29.55]dii
[00:29.79]dii
[00:30.03]dii
[00:30.13]Dammmmm
[00:30.81]dammmmm
[00:31.27]dii
[00:31.53]dii
[00:31.77]dii
[00:32.03]dii
[00:32.27]Dammmmm
[00:32.77]dammmmm  
[00:33.27]dii
[00:33.52]dii
[00:33.76]dii
[00:33.99]dii
[00:34.26]Dammmmm
[00:34.76]dammmmm
[00:35.28]dii
[00:35.50]dii
[00:35.74]dii
[00:35.98]dii
[00:36.24]Dammmmm
[00:36.74]dammmmm
[00:36.26]dii
[00:37.48]dii
[00:37.74]dii
[00:37.96]dii
[00:38.22]Dammmmm
[00:38.72]dammmmm
[00:39.22]dii
[00:39.48]dii
[00:39.72]dii
[00:39.96]dii
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `terranova-lyrics.ino` from this repo in Arduino IDE.
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
| `terranova-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `terranova-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.