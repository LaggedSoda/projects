# The LM386 Music Player
(Nov 10 - Nov 16)

Oh, what joyous day it is today. It has only taken me a week (or less) to finally write about this project. I would like to say that there were many times where what I was doing would probably make someone's chest hurt after what I did to my poor LM386. You'll have to read more to find out about that.

But, I would like to start where I got this LM386. I got it from an audio kit after I had got my first soldering station. It was meant to be a fun little project where I soldered different components and chips together. However, what wasn't fun was me having to make sure all of the components were in place, since I didn't have any way to hold said components in place, for some reason it wanted to save board space by putting a bunch of resistors and I think a capacitor under an STC89C52RC (which I'd like to start a project about as soon as I learn mandarin to read the datasheets), and the solder pads would rip off after I kept on accidentally joining two pins on the RDA5807M (rest it rest its soul-der). Either way, it was an ambitious soldering project given it was my first time ever soldering. Bad news is that it didn't work, but pressing around on this weird IC (LM386) made loud lightning noises, good news was that I got some new toys to play with.

It was only until recently that I finally sat down and gave the time to build the amplifier with the speaker I also got from the kit t o make something that could play music.

## We Are The Music Makers

First up was going to be the code I was using. Because I am very original, I just copied the code from the projecthub on arduino's website [here](https://projecthub.arduino.cc/Sparkbuzzer/happy-birthday-tone-using-arduino-uno-66a676) and I changed the speaker pin to match my design. Speaking of design, below are the pictures and then a full video of the journey I went on with the chip.



It may be difficult to see, but I'll just tell you about the pins on the LM386. If you'd like the reference, the datasheet can be found [here](https://www.ti.com/lit/ds/symlink/lm386.pdf?ts=1734118207298).

Going down, left to right, we have:



Pin 1: Connects to Pin 8 with a (130nF) capacitor to control Gain

Pin 2: We set the (-) inverting pin to GND because we don't need it

Pin 3: We send our input signal here, in our case PWM. We have a low-pass filter (0.3nF and 1kΩ) so it can smooth the square wave to something nicer for the LM386

Pin 4: GND. There are two capacitors in parallel (a 130nF and a 100μF) connected to pin 6 to make the voltage more stable for the chip.

Pin 5: This is V_Out, and this is where we will connect out speaker to.

Pin 6: Vs is our power. I have two capacitors in parallel (a 100nF and a 100μF) to pin 4 to make the chip more stable (no sudden voltage changes)

Pin 7: This is the bypass pin, so I just bypassed it. Putting this pin and a small (0.3nF) capacitor to GND helps with noise.

Pin 8: Connects to Pin 1 with a (130 nF) capacitor to control Gain (same capacitor from pin 1)




Needless to say, me messing with the contacts on the LM386 played a role before and after the project.

Also, I was really bored and I made some code (again, very smart, so I had it optimized with ChatGPT so it wouldn't eat away at my delicate EERPROM memory). It is a "music engine" and the code is [here]().

## Trial and Error

The videos capture it perfectly. Just watch.



## PWM Awesomeness

If you are here because you want me to do something CRAZY like connecting a .wav file from an external microSD card module and then using TMRpcm.h to then generate a PWM signal from said .wav file???? Then you are in luck.

The song I chose to be the first song I'd ever play on a circuit I made myself (we won't count happy birthday and all of the other projects I have made in the past) was one that was very special to me, and that was also in the YouTube Audio Library where I found it: "Esther's Waltz No.9" by Esther Abrami.

I hooked up the pins for the microSD module the same as is shown in the microSD card project or, if you don't feel like going over there:
GND -> GND

VCC -> 5V VCC

MISO -> Arduino Pin 12

MOSI -> Arduino Pin 11

SCK -> Arduino Pin 13

CS -> Arduino Pin 10



And here it is, the sound I recorded with my phone so you can hear the crackle and noise in the amp. Ahh, so rustic. It makes imperfection feel intentional, but I didn't intend on the noise, but I liked it.
