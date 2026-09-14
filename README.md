# [Damned by Miguel] Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**[Damned]**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-karaoke-lcd](https://github.com/CharmanderTheGreat/arduino-karaoke-lcd) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** [Damned]
- **Artist:** [Miguel]
 
## Lyrics File (.lrc)

The `.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[paste .lrc content here, or link to the .lrc file in this repo]
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-karaoke-lcd](https://github.com/CharmanderTheGreat/arduino-karaoke-lcd) hub repo. Once your board and LCD are wired and ready:

1. Open `[sketch-filename].ino` from this repo in Arduino IDE.
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
| `[sketch-filename].ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `[song-title].lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-karaoke-lcd](https://github.com/CharmanderTheGreat/arduino-karaoke-lcd) hub repo for library and tool credits.
