# Sun Bleached Flies by Ethel Cain Lyrics using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**Sun Bleached Flies**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** Sun Bleached Flies
- **Artist:** Ethel Cain
 
## Lyrics File (.lrc)

The `sunbleachedflies-lyrics.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.42]But
[00:00.66]I
[00:01.14]always
[00:01.96]knew
[00:02.98]that
[00:03.42]in
[00:03.84]the
[00:04.14]end
[00:05.14]no
[00:05.58]one
[00:06.02]was
[00:06.36]coming
[00:08.12]to
[00:08.48]save
[00:09.06]me
[00:09.58]So
[00:09.86]I
[00:10.16]just
[00:10.66]prayed
[00:13.90]and
[00:14.26]I
[00:14.54]keep
[00:14.94]praying
[00:16.92]and
[00:17.18]praying
[00:19.08]and
[00:19.40]praying
[00:19.70]If
[00:20.02]it's
[00:20.72]meant
[00:21.26]to
[00:21.56]be
[00:22.28]then
[00:22.74]it
[00:23.16]will
[00:23.78]be
[00:27.26]So
[00:27.60]I
[00:27.90]met
[00:28.82]him
[00:29.34]there
[00:29.76]and
[00:30.28]told
[00:30.84]him
[00:31.68]I
[00:32.20]believe
[00:36.57]Singing
[00:37.17]if
[00:37.45]it's
[00:38.19]meant
[00:38.69]to
[00:39.09]be
[00:40.13]then
[00:40.49]it'll
[00:41.23]be
[00:45.25]I
[00:45.59]forgive
[00:46.17]it
[00:46.91]all
[00:47.55]as
[00:47.83]it
[00:48.25]comes
[00:49.07]back
[00:49.63]to
[00:49.93]me 
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `sunbleachedflies-lyrics.ino` from this repo in Arduino IDE.
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
| `sunbleachedflies-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `sunbleachedflies-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
