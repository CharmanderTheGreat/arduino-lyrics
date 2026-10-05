# Thinking Of You by Katy Perry Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Thinking Of You**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Thinking Of You
- **Artist:** Katy Perry
 
## Lyrics File (.lrc)

The `thinkingofyou-lyrics.lrc` file below contains the full lyrics with word-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.04]You're
[00:01.04]the
[00:01.40]best
[00:02.62]And
[00:02.86]yes,
[00:03.60]I
[00:03.94]do
[00:04.20]regret
[00:06.06]How
[00:06.60]I
[00:07.34]could
[00:07.76]let
[00:08.94]myself
[00:10.94]let
[00:12.10]you
[00:12.42]go?
[00:14.24]Now,
[00:15.90]now
[00:16.30]the
[00:16.72]lesson's
[00:17.50]learned
[00:18.88]I
[00:19.14]touched
[00:19.80]it,
[00:20.00]I
[00:20.32]was
[00:20.56]burned
[00:22.22]Oh,
[00:22.56]I
[00:23.58]think
[00:23.92]you
[00:25.24]should
[00:25.66]know
[00:26.52]'Cause
[00:26.92]when
[00:27.92]I'm
[00:28.16]with
[00:29.04]him,
[00:29.82]I
[00:30.14]am
[00:31.02]Thinking
[00:31.64]of
[00:32.02]you
[00:34.26]Thinking
[00:35.00]of
[00:35.30]you
[00:36.30]Oh,
[00:37.56]what
[00:37.96]you
[00:38.34]would
[00:38.76]do
[00:39.42]if
[00:40.40]You
[00:41.20]were
[00:41.84]the
[00:42.12]one
[00:42.84]who
[00:43.20]was
[00:43.97]spending
[00:44.89]the
[00:45.11]night
[00:47.35]Oh,
[00:47.59]I
[00:47.95]wish
[00:48.55]that
[00:49.41]I
[00:49.93]Was
[00:50.33]looking
[00:51.03]into
[00:51.79]your
[00:52.15]eyes
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `thinkingofyou-lyrics.ino` from this repo in Arduino IDE.
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
| `thinkingofyou-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `thinkingofyou-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.