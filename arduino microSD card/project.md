# MicroSD Card Project

Ever since I got my Arduino and knew how to use the buzzer, I wanted to make music. Not quite pre-coded tones or a small piano to play said tones, but something that could play music for me.

Now, there are dedicated mp3 players for the Arduino, but at the time of buying parts for future projects (that included a Pi 5 server) I decided to get a MicroSD Card Adapter. I'm not fully sure why I did besides the assumption that all I need was an adapter to talk with the Arduino to send data over. Nonetheless, this project is going to be split into three parts:
1. Get the MicroSD card to talk with the Arduino and read files.
2. Get the Arduino to write a file to the MicroSD card (I was thinking calculating Pi to 1000 digits and writing that to a file)
3. Get a library to be able to read WAV files and play music via a buzzer (or a speaker with the help of the LM386) instead of embedding music in the limited flash.

With that being said, it was time to start part 1.

## Arduino, meet MicroSD

To start the project, I will be using: an Arduino Uno R3, a MicroSD Card Adapter that can connect to the Arduino, and a MicroSD card.
Below are pictures of what I am using.
![](/images/20251028_181016.jpg) ![](/images/20251028_181113.jpg)
Above on the adapter is a VHC T125A (Quad Bus Buffer) and a AMS1117 Voltage Regulator.

Firstly, I should state the MicroSD card was initially from a kit I had gotten for the Pi 5. It was here I realized that the adapters I had bought were, in fact, not not for normal sized SD cards, but rather MicroSD cards; because of this, I decided to wipe the Rasbian image off of the SD card to reformat it with F32. I decided to use GParted to do this and "lsblk -f" was giving me the greenlight. From here, it was time to put the wiring and code together. 

It is relatively simple to use the documentation on Arduino's [website to get code and wiring](https://docs.arduino.cc/learn/programming/sd-guide/) in order.

I tweaked the [code](ArduinoSDCardCode1.ino) (of which is not my own) ever so slightly to save an integer "cs" to represent the pin for cs and place that within SD.begin(cs)

![](/images/20251028_181339.jpg)

However, no matter how the board was wired, I could not get the card to initialize. It was here I decided to use AI to try to solve this issue and I was informed that, you guessed it, an Arduino is probably going to have a hard time with a microSDXC 128GB card. Because of this, the adapter likely cannot speak to the card or the arduino can't.

From here (October 28, 2025), I will have to postpone this project until I am able to get a smaller microSD card that can support it or I can find a library that could solve this, but I am opting for a functional SD card (for recovering the Pi 5 and to just have another microSD card on hand).
