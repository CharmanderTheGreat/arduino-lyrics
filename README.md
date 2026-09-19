# Waltz Of Four Left Feet by Shirebound and Busking using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Waltz Of Four Left Feet**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Waltz Of Four Left Feet
- **Artist:** Shirebound and Busking
 
## Lyrics File (.lrc)

The `waltoffourfeet-lyrics.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:02.80]Sapat
[00:03.82]na
[00:04.10]sakin
[00:04.82]ang
[00:05.48]ganito
[00:07.46]ooh
[00:11.16]Ang
[00:11.44]pagmasdan
[00:12.44]ka
[00:13.48]sa
[00:13.82]malayo
[00:18.82]Kapag
[00:19.50]kinausap
[00:22.80]walang
[00:23.48]masagot
[00:26.80]Hininga'y lagot
[00:31.80]Hindi
[00:34.14]ko
[00:35.78]naman
[00:36.46]yata
[00:37.50]ikamamatay
[00:39.50]kung
[00:39.82]hindi
[00:42.14]ko
[00:43.50]mahawakan
[00:45.52]ang
[00:45.88]iyong
[00:46.78]kamay 
[00:47.82]Handa
[00:48.46]akong
[00:49.48]mabuhay
[00:50.46]sa
[00:51.12]aking
[00:51.46]kalokohan 
[00:55.48]Kung
[00:55.84]wala
[00:56.46]ka
[00:57.46]sa
[00:57.78]aking
[00:58.16]buhay,
[00:58.84]walang
[00:59.46]kalungkutan
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `waltoffourfeet-lyrics.ino` from this repo in Arduino IDE.
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
| `waltoffourfeet-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `waltoffourfeet-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
