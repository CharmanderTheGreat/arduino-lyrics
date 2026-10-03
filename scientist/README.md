# Scientist by Coldplay Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Scientist**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Scientist
- **Artist:** Coldplay
 
## Lyrics File (.lrc)

The `scientist-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:01.06]And
[00:01.40]tell
[00:01.86]me
[00:02.28]you
[00:02.66]love
[00:03.52]me
[00:04.64]come
[00:05.12]back
[00:05.56]and
[00:05.94]haunt
[00:06.78]me
[00:08.06]Oh,
[00:08.48]and
[00:08.86]I
[00:09.18]rush
[00:10.04]to
[00:10.82]the
[00:11.14]start
[00:14.50]Runnin'
[00:15.38]in
[00:15.72]circles
[00:17.76]chasin'
[00:18.72]our
[00:19.00]tails
[00:21.08]Comin'
[00:22.32]back
[00:23.18]as
[00:23.96]we
[00:24.40]are
[00:27.28]Nobody
[00:28.84]said
[00:29.78]it
[00:30.08]was
[00:30.54]easy
[00:33.84]Oh,
[00:34.28]it's
[00:34.54]such
[00:35.04]a
[00:35.36]shame
[00:36.24]for
[00:36.66]us
[00:37.04]to
[00:37.42]part
[00:40.39]Nobody
[00:41.95]said
[00:42.89]it
[00:43.19]was
[00:43.69]easy
[00:46.87]No
[00:47.71]one
[00:48.17]ever
[00:48.85]said
[00:49.41]it
[00:49.77]would
[00:50.17]be
[00:50.55]so
[00:51.37]hard
[00:55.95]I'm
[00:56.35]goin'
[00:57.15]back
[00:57.59]to
[00:57.99]the
[00:58.35]start
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `scientist-lyrics.ino` from this repo in Arduino IDE.
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
| `scientist-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `scientist-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.