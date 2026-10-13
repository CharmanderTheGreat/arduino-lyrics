# Alipin by Shamrock (Khel Pangilinan Cover) Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Alipin**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Alipin
- **Artist:** Shamrock
 
## Lyrics File (.lrc)

The `alipin-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:04.48]Ako'y 
[00:05.10]alipin 
[00:06.10]mo 
[00:06.46]kahit 
[00:07.70]hindi 
[00:08.08]batid
[00:11.62]Aaminin 
[00:12.36]ko 
[00:12.94]minsan 
[00:13.80]ako'y 
[00:14.58]manhid
[00:16.98]Sana
[00:17.92]ay 
[00:19.80]iyong
[00:20.18]naririnig 
[00:24.04]Sa'yong 
[00:24.64]yakap
[00:25.88]ako'y
[00:26.64]nasasabik
[00:29.96]'Pagkat  
[00:30.84]ikaw
[00:31.30]lang
[00:31.88]ang 
[00:32.22]nais
[00:33.00]makatabi 
[00:36.64]Malamig 
[00:37.88]man 
[00:38.36]o
[00:38.68]mainit 
[00:39.92]ang 
[00:40.28]gabi 
[00:42.68]Nais 
[00:43.46]ko 
[00:44.27]sana 
[00:45.91]iparating 
[00:49.41]na 
[00:50.02]ikaw 
[00:50.56]lamang 
[00:52.60]Ang 
[00:52.88]siyang
[00:53.37]aking
[00:58.87]iibigin
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `alipin-lyrics.ino` from this repo in Arduino IDE.
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
| `alipin-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `alipin-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.