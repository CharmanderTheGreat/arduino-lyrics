# Kalapastangan by fitterkarma Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Kalapastangan**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Kalapastangan
- **Artist:** fitterkarma
 
## Lyrics File (.lrc)

The `kalapastangan-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.00]Mamamatay
[00:01.82]akong
[00:02.28]nakangiti
[00:04.42]Kapag
[00:05.04]ikaw
[00:05.60]ang 
[00:06.18]nasa
[00:07.48]aking
[00:08.16]tabi
[00:08.92]Mabubuhay
[00:10.44]akong
[00:11.12]nagsisisi
[00:13.38]Kapag
[00:13.74]'sang
[00:14.19]araw
[00:14.87]hindi
[00:15.53]kita
[00:16.35]mapapangiti
[00:17.79]Kalapastangan
[00:19.33]ang 
[00:19.59]'di
[00:19.99]ka
[00:20.47]ibigin
[00:22.53]kalokohan
[00:23.57]ang
[00:23.89]'di
[00:24.07]ka
[00:24.89]isipin
[00:26.65]Kung
[00:27.10]ang
[00:27.33]mundo
[00:28.07]ay 
[00:28.21]biglang
[00:29.11]gugunawin
[00:31.29]Ikaw
[00:31.73]ang
[00:32.11]una
[00:32.61]kong 
[00:32.91]hahanapin
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `kalapastangan-lyrics.ino` from this repo in Arduino IDE.
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
| `kalapastangan-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `kalapastangan-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.