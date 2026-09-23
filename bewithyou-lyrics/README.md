# Be With You by Ridleys Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Be With You**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Be With You
- **Artist:** The Ridleys
 
## Lyrics File (.lrc)

The `bewithyou-lyrics.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:01.52]And
[00:01.80]it's
[00:02.04]all
[00:02.30]because
[00:03.32]I
[00:03.52]see
[00:03.84]the
[00:04.10]galaxies
[00:04.88]when
[00:05.14]I
[00:05.40]look
[00:05.66]in
[00:05.88]your
[00:06.20]eyes
[00:06.68]and
[00:06.92]I
[00:07.62]can't
[00:08.12]speak
[00:08.70]no
[00:09.02]I
[00:09.70]can't
[00:10.20]speak
[00:10.84]at
[00:11.10]all
[00:11.54]I
[00:11.72]swear
[00:12.08]to
[00:12.30]Zeus
[00:12.60]you're
[00:12.88]Aphrodite
[00:13.90]in
[00:14.08]disguise
[00:15.10]don't
[00:15.36]think
[00:15.62]that
[00:15.92]you
[00:16.10]can
[00:16.40]hide
[00:16.72]it
[00:16.88]from
[00:17.20]me
[00:18.72]Oh
[00:18.96]no
[00:19.24]I
[00:19.46]never
[00:19.96]thought
[00:20.32]I'd
[00:20.50]get
[00:20.74]this
[00:20.98]close
[00:21.30]to
[00:21.50]someone
[00:22.02]so
[00:22.30]divine
[00:23.14]Oh
[00:23.38]I
[00:24.06]can't
[00:24.60]breathe
[00:25.14]no
[00:25.44]I
[00:26.14]can't
[00:26.68]breathe
[00:27.26]at
[00:27.52]all
[00:28.14]Aphrodite
[00:29.45]could
[00:29.71]you
[00:29.73]could
[00:30.05]you
[00:30.33]please
[00:30.67]be
[00:30.92]mine
[00:31.70]oh,
[00:34.01]could
[00:33.39]you
[00:34.77]please
[00:35.05]be
[00:35.48]mine
[00:35.82]oh,
[00:36.22] mine :D
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `bewithyou-lyrics.ino` from this repo in Arduino IDE.
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
| `bewithyou-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `bewithyou-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
