# Lyrics using Arduino

A collection of timestamp-synced karaoke-style lyric displays, built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Each song has its own dedicated repo with its own code and lyric timing. This repo serves as the general hub: hardware info, wiring, setup, and the full list of song repos.

## How It Works

Each word in a song's lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD, filling the first row, then the second, creating a karaoke-style scrolling lyric effect.

## Song Repos

| Song | Repo Link |
|------|-----------|
| *(About You by The 1975)* | *[(https://github.com/CharmanderTheGreat/aboutyou-lyrics.git)](https://github.com/CharmanderTheGreat/aboutyou-lyrics.git)S* |
| *(Damned by Miguel)* | *[https://github.com/CharmanderTheGreat/damned-lyrics.git](https://github.com/CharmanderTheGreat/damned-lyrics.git)* |
| *(Sila by SUD)* | *[https://github.com/CharmanderTheGreat/sila-lyrics](https://github.com/CharmanderTheGreat/sila-lyrics)* |
| *(Totoong Tayo by Jin DC)* | *[https://github.com/CharmanderTheGreat/totoongtayo-lyrics.git](https://github.com/CharmanderTheGreat/totoongtayo-lyrics.git)* |
| *(Waltz Of Four Left Feet by Shirebound and Busking)* | *[https://github.com/CharmanderTheGreat/waltzoffourfeet-lyrics.git](https://github.com/CharmanderTheGreat/waltzoffourfeet-lyrics.git)* |

## Hardware Used

<img width="400" height="400" alt="Arduino Uno R3" src="https://github.com/user-attachments/assets/7e494cd4-429d-4461-91e6-ccbd466cf55f" />

- **Arduino Uno R3** — you may choose either the official board or the economy/clone variant (the clone requires the **CH340 driver** to be installed on your PC before it gets detected)

<img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/eceb8b83-965c-4ff5-8600-a5cba77cee0b" />

- **16x2 LCD screen with I2C backpack** — make sure to get a screen that comes with (or includes) an I2C module, since plain LCDs are often sold without it. It's recommended to buy one that's already pre-soldered to skip the soldering step.

<img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/094048b2-fa7a-40db-835c-37d760e47b1c" />

- **4x female-to-male jumper wires** — (female end connects to the LCD's I2C pins, male end connects to the Arduino's pin headers)

## Wiring

I2C only needs 4 connections:

| LCD (I2C) Pin | Arduino Uno Pin |
|----------------|------------------|
| GND            | GND              |
| VCC            | 5V               |
| SDA            | A4               |
| SCL            | A5               |

> Default I2C address used in code: `0x27`. If your screen doesn't light up or show text, run an I2C scanner sketch first to confirm the actual address (some modules use `0x3F` instead).

## Setup

1. Install the CH340 driver. This is only needed if you bought the economy/clone Uno R3, since it's cheaper but requires this extra step.
2. Solder the I2C backpack onto the LCD screen, if not pre-assembled. (Tip: buying a pre-soldered LCD module saves you this step.)
3. Wire the LCD to the Arduino following the table above.
4. Open the `.ino` sketch from the specific song repo you want in Arduino IDE.
5. Install the `LiquidCrystal_I2C` library via `Sketch > Include Library > Manage Libraries` → search "LiquidCrystal I2C" → install.
6. Select **Board: Arduino Uno** and the correct **COM Port**.
7. Upload the sketch.

## Uploading via Mobile (No PC Needed)

You can also upload sketches straight from an Android phone using **OTG** — no computer required.

**Requirements:**
- Android phone with **USB-host (OTG) support**
- **USB-C to USB-A cable** (or OTG adapter, depending on your Arduino's cable)
- [**ArduinoDroid**](https://play.google.com/store/apps/details?id=name.antonsmirnov.android.arduinodroid2) app (Play Store)

> Note: ArduinoDroid's core features (compile + upload) are free and unlimited — there's no hard cap on how many times you can upload. The catch is it's ad-supported: expect a ~30-second video ad on most compile/upload actions unless you get the premium unlock (also removes ads + adds extras like autocomplete).

### How to Operate

1. Install ArduinoDroid from the Play Store.
2. Connect your phone to the Arduino via the USB-C to USB cable.
3. Open the app — it should prompt for USB permission; allow it.
4. Load the `.ino` sketch from the song repo (import/open from storage).
5. Add the required library (see below) before compiling.
6. Set the board to **Arduino Uno** in ArduinoDroid's board settings.
7. Tap **Compile**, then **Upload**.

### Adding the LiquidCrystal_I2C Library (Mobile)

ArduinoDroid doesn't have the full Library Manager search like the desktop IDE, so the library has to be added manually as a `.zip`:

1. Download the library as a ZIP from its GitHub repo: **[github.com/johnrickman/LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C)** → **Code** → **Download ZIP**.
2. In ArduinoDroid, tap the **3-dot menu** (upper right).
3. Go to **Libraries**.
4. Select **Add downloaded .zip library**, then pick the ZIP you downloaded.

## Usage

This is a **visual-only** display. There's no actual audio playback, just the lyrics scrolling in sync with timestamps. To start or replay the sequence from the beginning, reset the board using any of the following:

- **Reset button** — the red button on the Arduino board itself
- **Re-upload the sketch** — re-uploading via Arduino IDE also restarts the board
- **Plug and play** — unplug and replug the USB/power

There's no separate "play" command in software. Resetting the board is what triggers the sequence to play again.

## Limitations / Out of Scope

This project is intentionally simple. The following are **not** included:

- **No on/off switch** — the board only runs/resets via power plug or the reset button
- **No sound/audio output** — visual-only; does not play or sync with actual audio
- **No external "play" button** — playback restarts only by resetting the board

## Software & Credits

| What | Link | Author / Source |
|------|------|------------------|
| Arduino IDE | [arduino.cc/en/software](https://www.arduino.cc/en/software) | Arduino |
| CH340 Driver | [wch-ic.com/downloads/CH341SER_EXE.html](https://www.wch-ic.com/downloads/CH341SER_EXE.html) | Nanjing Qinheng Microelectronics (WCH) — official manufacturer of the CH340/CH341 chip |
| LiquidCrystal_I2C Library | [github.com/johnrickman/LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C) | Author: Frank de Brabander · Maintainer: Marco Schwartz |
| ArduinoDroid | [https://play.google.com/store/apps/details?id=name.antonsmirnov.android.arduinodroid2](https://play.google.com/store/apps/details?id=name.antonsmirnov.android.arduinodroid2) | Publisher: PE Smirnov Anton Sergeevich |



> Install LiquidCrystal_I2C directly through Arduino IDE's Library Manager instead of downloading it manually. Search "LiquidCrystal I2C" and install the one by Frank de Brabander.

## What You'll Learn / Skills Gained

Replicating or studying these projects touches on a few practical skills:

- **I2C communication** — wiring and addressing an I2C device (LCD) with only 4 connections
- **Basic soldering** — attaching an I2C backpack module onto an LCD screen
- **Driver troubleshooting** — installing and recognizing USB-to-serial drivers (CH340) for clone microcontroller boards
- **Timestamp-based logic** — syncing output (lyrics) to elapsed time using `millis()`, instead of relying on delays
- **Library usage** — installing and using a third-party Arduino library (`LiquidCrystal_I2C`) via the Library Manager
- **Hardware-software integration** — connecting a physical display to custom logic that controls what's shown and when
