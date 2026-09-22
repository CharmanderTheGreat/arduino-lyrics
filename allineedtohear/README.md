# All I Need To Hear by The 1975 Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**All I Need To Hear**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** All I Need To Hear
- **Artist:** The 1975
 
## Lyrics File (.lrc)

The `allineedtohear-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.48]Oh,
[00:01.00]I
[00:01.36]don't
[00:01.86]care
[00:02.42]if
[00:02.72]you're
[00:03.70]insincere,
[00:06.92]Just
[00:07.20]tell
[00:07.66]me
[00:08.06]what
[00:08.40]I
[00:08.98]wanna
[00:09.68]hear
[00:12.30]You
[00:12.46]know
[00:12.92]where
[00:13.44]to
[00:13.66]find
[00:14.06]me
[00:14.96]The
[00:15.12]place
[00:15.66]where
[00:16.08]we
[00:16.28]lived
[00:16.96]all
[00:17.36]these
[00:18.18]years,
[00:19.42]oh
[00:22.73]and
[00:23.11]tell
[00:23.63]me
[00:23.97]you
[00:24.23]love
[00:24.63]me
[00:25.75]That's
[00:26.29]all
[00:26.63]that
[00:26.89]I
[00:27.53]need
[00:27.97]to
[00:28.97]hear
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `allineedtohear-lyrics.ino` from this repo in Arduino IDE.
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
| `allineedtohear-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `allineedtohear-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.