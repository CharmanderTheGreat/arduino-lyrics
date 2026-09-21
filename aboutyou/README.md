# About You by The 1975 using Arduino Uno R3 with I2C Screen Display

A timestamp-synced lyric display for the song "**About You**", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

> Part of the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) collection — see that repo for general hardware info, wiring, and setup instructions shared across all song repos.

## Song Info

- **Title:** About You
- **Artist:** The 1975
 
## Lyrics File (.lrc)

The `aboutyou-lyrics.lrc` file below contains the full lyrics with line-level timestamps, in the standard LRC format. It's included so the timing data can be reused or ported to other languages/platforms if you don't want to use the Arduino sketch as-is.

```
[00:00.22] I
[00:04.58] know
[00:05.04] a
[00:05.20] place
[00:09.94] It's
[00:10.20] somewhere
[00:11.26] I
[00:11.48] go
[00:12.08] when
[00:12.48] I
[00:12.74] need
[00:13.38] to
[00:13.68] remember
[00:14.96] your
[00:15.88] face
[00:19.62] We
[00:19.96] get
[00:20.28] married
[00:24.60] in
[00:24.98] our
[00:25.86] heads
[00:30.22] Something
[00:31.28] to
[00:31.50] do
[00:32.10] while
[00:32.44] we
[00:32.70] try
[00:33.38] to
[00:33.68] recall
[00:34.58] how
[00:34.92] we
[00:35.86] met
[00:39.60] Do
[00:39.84] you
[00:40.20] think
[00:41.16] I
[00:42.16] have
[00:42.40] forgotten?
[00:44.62] Do
[00:44.88] you
[00:45.18] think
[00:46.16] I
[00:46.64] have
[00:47.42] forgotten?
[00:49.58] Do
[00:49.86] you
[00:50.20] think
[00:51.18] I
[00:51.62] have
[00:52.42] forgotten
[00:54.64] About
[00:56.12] you?
```

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Setup

For hardware, wiring, and general setup instructions, see the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo. Once your board and LCD are wired and ready:

1. Open `aboutyou-lyrics.ino` from this repo in Arduino IDE.
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
| `aboutyou-lyrics.ino` | Arduino sketch with the word-timestamp array and LCD display logic |
| `aboutyou-lyrics.lrc` | Lyrics with timestamps in standard LRC format |

## Credits

See the [arduino-lyrics](https://github.com/CharmanderTheGreat/arduino-lyrics) hub repo for library and tool credits.
