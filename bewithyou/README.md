# Be With You by Ridleys Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Be With You**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Be With You
- **Artist:** The Ridleys
 
## Lyrics File (.lrc)

The `bewithyou-lyrics.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:01.50]I'm
[00:01.68]gonna
[00:02.06]work
[00:02.40]on
[00:02.74]my
[00:03.04]temper
[00:03.62]While
[00:03.92]you
[00:04.10]learn
[00:04.42]to
[00:04.54]speak
[00:04.94]your
[00:05.24]mind
[00:05.58]some
[00:05.78]more
[00:06.98]I'll
[00:07.20]be
[00:07.46]more
[00:07.86]of
[00:08.24]a
[00:08.48]shelter
[00:09.86]and
[00:10.18]less
[00:10.58]of
[00:10.96]a
[00:11.16]storm
[00:12.24]While
[00:12.46]we
[00:12.80]both
[00:13.14]are
[00:13.46]working
[00:14.14]on
[00:14.50]ourselves
[00:15.68]in
[00:15.88]our
[00:16.26]own
[00:16.70]ways
[00:17.34]I
[00:17.50]just
[00:17.70]wanna
[00:18.12]be
[00:18.74]with
[00:18.94]you
[00:19.60]every
[00:20.24]single
[00:20.98]day
[00:22.82]Oh,
[00:23.00]I
[00:23.16]wanna
[00:23.54]be
[00:24.16]with
[00:24.40]you
[00:25.06]every
[00:25.70]single
[00:26.26]day
[00:30.28]For
[00:30.48]the
[00:30.68]rest
[00:31.04]of
[00:31.20]our
[00:31.68]lives
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `bewithyou-lyrics.ino` from this repo in Arduino IDE.
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
| `bewithyou-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `bewithyou-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
