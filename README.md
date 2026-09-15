# Damned by Miguel Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Damned**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Damned
- **Artist:** Miguel
 
## Lyrics File (.lrc)

The `.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.30]Two
[00:00.72]hearts
[00:01.04]committed
[00:02.10]to
[00:02.50]hopeless
[00:03.22]fate
[00:04.34]I’d
[00:04.74]serve
[00:05.16]my
[00:05.44]life
[00:05.86]sentence
[00:06.58]a
[00:06.94]thousand
[00:07.68]times,
[00:08.12]woman
[00:08.92]When
[00:09.08]the
[00:09.22]gavel
[00:09.80]hit
[00:09.90]the
[00:09.100]stand
[00:11.18]I'm
[00:11.48]damned
[00:11.86]to
[00:11.100]loving
[00:12.28]you
[00:13.36]Two
[00:13.64]palm
[00:13.94]trees
[00:14.26]in
[00:14.36]the
[00:14.50]sand
[00:15.58]I'm
[00:15.90]damned
[00:16.59]to
[00:16.70]loving
[00:17.04]you
[00:17.52]now
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-karaoke-lcd](https://github.com/CharmanderTheGreat/arduino-karaoke-lcd) hub repo. Once your board and LCD are wired and ready:

1. Open `[sketch-filename].ino` from this repo in Arduino IDE.
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
| `damned-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `damned-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-karaoke-lcd](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
