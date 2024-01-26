#include <M5CoreS3.h>
#include <Avatar.h>
#include <cstdlib>  // Include for random number generation

using namespace m5avatar;

Avatar avatar;

// Define sets of lyrics here
const char* lyrics1[] = {
  // Lyrics 1
};
const char* lyrics2[] = {
  // Lyrics 2
};
const char* lyrics3[] = {
  // Lyrics 3
};
const char* lyrics4[] = {
  // Lyrics 4
};
const char* lyrics5[] = {
  // Lyrics 5
};
// Define additional sets of lyrics here

const int lyrics1Size = sizeof(lyrics1) / sizeof(char*);
const int lyrics2Size = sizeof(lyrics2) / sizeof(char*);
const int lyrics3Size = sizeof(lyrics3) / sizeof(char*);
const int lyrics4Size = sizeof(lyrics4) / sizeof(char*);
const int lyrics5Size = sizeof(lyrics5) / sizeof(char*);

int lyricsIdx = 0;
bool isPlaying = false;
unsigned long lastLyricTime = 0;
const unsigned long lyricInterval = 500;
const unsigned long endDelay = 3000;

// Variables for lyrics set selection
int currentLyricsSet = 0;  // Initialize with any default set

void setup() {
    M5.begin();
    avatar.init();
    randomSeed(analogRead(0));  // Seed for random number generator
}

static m5::touch_state_t prev_state;

void loop() {
    M5.update();

    auto t = M5.Touch.getDetail();
    if (t.state == m5::touch_state_t::touch_begin) {
        // On touch, select a random lyrics set
        currentLyricsSet = random(5); // Randomly select between 0 to 4 (inclusive)
        lyricsIdx = 0;  // Reset the lyrics index
        isPlaying = true;
        lastLyricTime = millis();  // Reset the timer
    }

    if (isPlaying && millis() - lastLyricTime >= lyricInterval) {
        const char** currentLyrics = getCurrentLyrics();
        int currentLyricsSize = getCurrentLyricsSize();

        if (lyricsIdx < currentLyricsSize) {
            // Display the current lyric
            const char* l = currentLyrics[lyricsIdx++];
            avatar.setSpeechText(l);
            avatar.setMouthOpenRatio(0.7);
            delay(200);  // Short delay for mouth animation
            avatar.setMouthOpenRatio(0);
            lastLyricTime = millis();  // Update the timer
        } else {
            // After displaying all lyrics, wait for endDelay before clearing the text
            if (millis() - lastLyricTime >= endDelay) {
                avatar.setSpeechText("");  // Clear the text
                isPlaying = false;  // Stop the sequence
            }
        }
    }
}

// Function to select the current set of lyrics based on the random choice
const char** getCurrentLyrics() {
    switch (currentLyricsSet) {
        case 0: return lyrics1;
        case 1: return lyrics2;
        case 2: return lyrics3;
        case 3: return lyrics4;
        case 4: return lyrics5;
        default: return lyrics1; // Default case
    }
}

// Function to get the size of the current set of lyrics
int getCurrentLyricsSize() {
    switch (currentLyricsSet) {
        case 0: return lyrics1Size;
        case 1: return lyrics2Size;
        case 2: return lyrics3Size;
        case 3: return lyrics4Size;
        case 4: return lyrics5Size;
        default: return lyrics1Size; // Default case
    }
}
