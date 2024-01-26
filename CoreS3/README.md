# M5CoreS3 Avatar Lyric Display

This project is for the M5CoreS3 device, utilizing its touch capabilities and display to show different sets of lyrics in an animated manner. Touching the screen, a random set of lyrics is displayed, character by character, with a mouth animation to mimic singing or speaking.

## Features

- Utilizes M5CoreS3's touch screen and display.
- Random selection of different lyric sets.
- Animated avatar that simulates singing/speaking the lyrics.

## Hardware Requirements

- M5CoreS3 device.

## Software Requirements

- Arduino IDE.
- M5CoreS3 library.
- Avatar library.

## Installation

1. **Arduino IDE Setup**: If you haven't already, download and install the Arduino IDE from [the Arduino website](https://www.arduino.cc/en/Main/Software).

2. **Library Installation**:
   - Open the Arduino IDE.
   - Go to `Sketch` > `Include Library` > `Manage Libraries...`.
   - Search for `M5CoreS3` and `Avatar`, then install these libraries.

3. **Loading the Sketch**:
   - Clone this repository or download the source code.
   - Open the `.ino` file with Arduino IDE.
   - Select the correct board (M5CoreS3) and port from the `Tools` menu.

4. **Upload the Code**:
   - Connect your M5CoreS3 to your computer.
   - Click on the upload button in the Arduino IDE.

## Usage

- Simply power on the M5CoreS3.
- Touch the screen to start the lyric display.
- The device will randomly select one of the available sets of lyrics and display them one by one.
- Touch the screen again to display another random set of lyrics.

## Customization

- You can add or modify the lyrics sets in the provided arrays within the code.
- Adjust the `lyricInterval` and `endDelay` constants in the code to change the speed of lyric display and the delay after finishing a set.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
