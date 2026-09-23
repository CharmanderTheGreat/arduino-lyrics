# Mahal Magmahal by Esremborak Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Mahal Magmahal**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Mahal Magmahal
- **Artist:** Esremborak
 
## Lyrics File (.lrc)

The `mahalmagmahal-lyrics.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.04]Ngunit
[00:01.18]saka
[00:01.88]na
[00:02.16]lang
[00:02.88]pakakawalan
[00:04.98]Kung
[00:05.22]may
[00:05.66]sigurado
[00:06.56]na
[00:06.78]sa
[00:07.00]kawalan
[00:08.70]Mahal
[00:09.34]ngayon
[00:10.40]ang
[00:10.82]magmahal
[00:12.44]Mahal
[00:13.08]kita,
[00:14.08]pero
[00:14.96]mahal
[00:18.02]Mahal
[00:18.74]na
[00:19.02]ang
[00:19.70]bigas
[00:20.60]Pati
[00:21.56]lata
[00:22.52]ng
[00:22.96]sardinas
[00:24.46]Kung
[00:24.94]mamahalin
[00:27.52]kita
[00:27.98]ngayon
[00:29.48]Sabay
[00:30.20]tayong
[00:31.14]magugutom
[00:33.08]'Di
[00:33.26]sapat
[00:34.04]ang
[00:34.46]sahod
[00:35.48]ko
[00:35.96]Kahit
[00:37.20]tapat
[00:37.86]ako
[00:38.80]sa 'yo
[00:39.72]Anong
[00:40.60]silbi
[00:41.62]nitong
[00:42.78]pagmamahal
[00:44.48]Kung
[00:44.74]lahat
[00:45.38]din
[00:45.70]ay
[00:46.56]nagmamahal?
[00:48.38]Ayoko
[00:49.32]lang
[00:50.02]namang
[00:50.94]makita
[00:52.04]ka
[00:55.66]Kinikilig
[00:57.33]habang
[00:58.17]sa
[00:58.45]hirap
[01:00.01]ay
[01:01.83]nagdurusa
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `mahalmagmahal-lyrics.ino` from this repo in Arduino IDE.
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
| `mahalmagmahal-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `mahalmagmahal-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
