# Multo by Cup of Joe Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Multo**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Multo
- **Artist:** Cup of Joe
 
## Lyrics File (.lrc)

The `multo-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.08]Hindi
[00:00.52]na
[00:02.08]makalaya
[00:04.70]dinadalaw
[00:06.16]mo
[00:06.42]'ko
[00:06.70]bawat
[00:07.28]gabi
[00:09.30]Wala
[00:09.92]mang
[00:10.74]nakikita
[00:13.94]haplos
[00:14.54]mo'y
[00:15.12]ramdam
[00:15.82]pa
[00:15.92]rin
[00:16.20]sa
[00:16.54]dilim
[00:18.54]Hindi
[00:19.14]na
[00:19.98]na-nanaginip,
[00:23.14]hindi
[00:23.74]na
[00:24.60]ma-makagising
[00:27.76]Pasindi
[00:29.20]na
[00:30.08]ng
[00:30.74]ilaw
[00:32.38]Minumulto
[00:33.58]na
[00:33.84]'ko
[00:34.16]ng
[00:34.42]damdamin
[00:35.30]ko
[00:36.44]ng
[00:36.74]damdamin
[00:37.60]ko
[00:37.92]Hindi
[00:38.76]mo
[00:39.04]ba
[00:39.70]ako
[00:40.22]lilisanin?
[00:42.76]Hindi
[00:43.36]pa
[00:43.66]ba
[00:44.22]sapat
[00:45.10]pagpapahirap
[00:46.52]sa 'kin?
[00:47.10]Hindi
[00:48.00]na
[00:48.28]ba
[00:48.84]ma-mamamayapa?
[00:51.22]Hindi
[00:52.60]na
[00:52.90]ba
[00:53.46]ma-mamamayapa?
[00:55.48]Hindi
[00:56.06]na
[00:56.88]makalaya...
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `multo-lyrics.ino` from this repo in Arduino IDE.
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
| `multo-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `multo-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.