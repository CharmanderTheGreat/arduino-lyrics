# Pasensya Ka Na by Silent Sanctuary Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Pasensya Ka Na**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Pasensya Ka Na
- **Artist:** Silent Sanctuary
 
## Lyrics File (.lrc)

The `pasenyakana-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.22]Pasensya
[00:01.32]ka
[00:01.70]na
[00:03.14]at
[00:03.44]'di
[00:03.80]ko
[00:04.16]na
[00:04.54]rin
[00:05.26]madama
[00:07.04]Kay
[00:07.34]tagal
[00:08.08]kitang
[00:08.78]hinihintay
[00:11.64]Pasensya
[00:12.74]ka
[00:13.12]na
[00:14.56]at
[00:14.84]kaya
[00:15.58]ko
[00:15.96]ng
[00:16.66]mag
[00:17.02]-isa
[00:18.42]Kalayaan
[00:19.82]sa
[00:20.20]kamay
[00:20.92]ng
[00:21.30]lumbay
[00:23.08]Pasensya
[00:24.16]ka
[00:24.54]na
[00:28.80]Pasensya
[00:29.88]ka
[00:30.20]na
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `pasenyakana-lyrics.ino` from this repo in Arduino IDE.
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
| `pasenyakana-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `pasenyakana-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.