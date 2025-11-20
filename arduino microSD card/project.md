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

Luckily, weeks later, I managed to find a microSD card that was SDHC. It was a small 32GB model. With this card, everything worked as intended.

## OOPS, I already did that!

Unfortunately, since it took me weeks to get, I had already moved onto a different project, and that was building an LM386 amp. If you want to see my attemps at playing a .wav file with the arduino R3 and a speaker (with amplification via an LM386), check it out here.

## Calculating 1000 Digits of PI

Otherwise, it was time to finally calculate and store 1000 digits of PI.

In order to do this, I figured the only way I could calculate PI accurately would be to use a Fourier Series (which I thankfully just learned in class recently) and sum an incredibly long decimal. This could be done with the square wave fourier series that can be simplified to (at t = pi/2): 1 = 4/pi * (1 + 1/3 + 1/5 + 1/7 + ...), and we can simplify this into pi/4 = 1 - 1/3 + 1/5 - 1/7 + ... and we just multiply the right side by four.

There is a BIG problem many mathematicians may already see here. This fourier series approximation of pi converges VERY slowly. If we believe what ChatGPT told me, 10 digits of pi would need 10^5 terms, and 1000 digits would need easily over 10^60 terms, which is simply not feasible on an arduino.

However, because math, there are multiple ways to calculate PI. Let me introduce you to the Base-10 Spigot Algorithm.

Basically, we can say pi = 3 + the sum of(  (((-1)^n+1 * (n!)^2)  /  (2n)!) * 10^-n    ). I appologize I do not know how to show the mathematical symbols in Github markdown yet. But the formula I just gave, while it looks like it will be fairly difficult, it will be able to generate a single decimal of PI over each iteration.

We are going to have an array what will be about exactly 10*1000 / 3 in size. And I know what you are thinking: "At this point, why not just give up and spend the next hours of calculating on something useful like reading that book you've been wanting to read or maybe learn a new recipe?"

And to answer that, I say "Quitting is for quitters."
