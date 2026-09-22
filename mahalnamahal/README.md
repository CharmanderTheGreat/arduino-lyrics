# Mahal na Mahal by Sam Concepcion using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Mahal na Mahal**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Mahal na Mahal
- **Artist:** Sam Concepcion
 
## Lyrics File (.lrc)

The `mahalnamahal.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:01.08]Hindi
[00:01.70]ko
[00:02.00]maiwasan
[00:03.28]na
[00:03.78]isipin
[00:05.44]ka
[00:06.08]Tanong
[00:06.70]sa
[00:07.02]hangin
[00:07.62]kung
[00:08.00]ako
[00:08.60]ba'y
[00:08.86]naiisip
[00:10.50]mo
[00:11.34]Litong-lito,
[00:13.82]litong-lito
[00:16.36]Sa'yo,
[00:17.60]sa′yo,
[00:18.84]sa′yo,
[00:20.08]sa'yo
[00:21.30]Sino
[00:22.00]ba
[00:22.32]naman
[00:22.98]ako
[00:23.54]para
[00:24.20]isipin
[00:25.46]mo
[00:26.08]Hindi
[00:26.68]mo
[00:27.00]ba
[00:27.32]hinihintay
[00:28.60]ang
[00:28.86]mga
[00:29.48]tawag
[00:30.42]ko
[00:31.34]Sa′yo,
[00:32.62]sa'yo,
[00:33.84]sa′yo,
[00:35.12]sa'yo′y
[00:36.36]Litong-lito,
[00:38.86]litong-lito
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `mahalnamahal-lyrics.ino` from this repo in Arduino IDE.
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
| `mahalnamahal-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `mahalnamahal-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
