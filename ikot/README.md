# Ikot by Over October Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Ikot**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Ikot
- **Artist:** Over October
 
## Lyrics File (.lrc)

The `ikot-lyrics.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:04.90]Pauulit
[00:05.82]ulit
[00:06.32]na
[00:06.60]lang
[00:08.20]sinasabi
[00:10.52]Pero
[00:11.12]'di
[00:11.70]ko
[00:11.96]naman
[00:12.76]pinaninindigan
[00:15.16]Oh,
[00:17.52]palaging
[00:19.78]nagdadalawang
[00:21.96]isip
[00:22.86]Paulit
[00:23.78]ulit
[00:24.28]ko
[00:24.56]lang
[00:26.22]sinasabi
[00:28.44]Sa
[00:28.72]sarili
[00:30.18]ko
[00:30.72]ang
[00:30.98]mga
[00:31.90]hindi
[00:32.100]Mabitawang
[00:35.16]salita
[00:36.88]para
[00:37.66]sa'yo
[00:42.26]Ikaw
[00:43.04]lang
[00:43.34]at
[00:43.64]ikaw
[00:44.78]Ang
[00:45.28]sinisigaw
[00:46.80]Ng
[00:46.98]puso
[00:47.80]kong
[00:48.10]'di
[00:48.32]mapakali
[00:51.22]Ikaw
[00:52.06]lang
[00:52.36]at
[00:52.64]ikaw
[00:53.74]Ang
[00:54.30]sinisigaw
[00:55.66]Pag-ibig
[00:56.76]ko'y
[00:57.04]sana
[00:57.62]mapansin
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `ikot-lyrics.ino` from this repo in Arduino IDE.
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
| `ikot-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `ikot-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
