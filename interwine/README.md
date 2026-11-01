# Interwine by Over October ft. The Ridleys Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Interwine**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Interwine
- **Artist:** Over October ft. The Ridleys
 
## Lyrics File (.lrc)

The `interwine-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.36]Take 
[00:01.74]this
[00:03.08]heart
[00:04.34]to
[00:05.04]be
[00:05.36]yours,
[00:07.28]only
[00:08.28]yours 
[00:09.66]And
[00:10.26]every 
[00:10.86]part
[00:12.80]of 
[00:13.45]you 
[00:14.87]will
[00:15.45]be 
[00:16.05]mine,
[00:17.75]only 
[00:18.67]mine
[00:20.31]Even 
[00:20.87]the 
[00:21.11]ghosts
[00:22.73]and 
[00:23.27]all 
[00:23.51]the
[00:23.71]fears
[00:25.53]Even 
[00:26.13]the
[00:26.49]most
[00:27.39]uncertain
[00:28.99]years,
[00:30.01]I'll
[00:30.39]hold
[00:31.13]you 
[00:31.69]close
[00:33.85]It
[00:34.27]starts
[00:35.67]tonight,
[00:39.35]the
[00:39.55]night
[00:40.05]when
[00:40.49]our
[00:40.65]lives 
[00:41.49]interwine
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `interwine-lyrics.ino` from this repo in Arduino IDE.
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
| `interwine-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `interwine-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.