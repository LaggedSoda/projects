**Receiving Radio**

It is currently December 30th, 2025 (as of the writing of this section), and all I wanted for Christmas was a few things, such as a real USB ADC interface for nicer audio equipment that I could use with my PC.

Truthfully, ever since I touched my LM386 I have been in a bit of a rabbit hole. For starters, I have been spending a lot of my break learning about the basics of radio and RF, and *OHH HOWDY* is there a lot. Just when I thought using a microcontroller to make an LED blink was fun, wait to you hear about what I did with the RTL-SDR V4! Actually, don't wait. I listened to a WEATHER STATION! It told me in the robotic voice the temperature and I could have used my phone or watched the news but instead I used a well priced dongle and put an antenna and installed drivers and software on linux and configured GRC (GNU Radio Companion) and I added a filter and demodulators and I managed to add an audio sink to listen to the NOAA!

*insert imaginary gasp*

Anyhow, yes, I have obtained an SDR which is a "Software-defined Radio", basically instead of spending all of my christmas money on demodulators, adjustable capacitors, inductors, amplifiers, transistors, and all of the other special components to then only have bad signals because everything is running through a breadboard; I have simply decided to take the easy route and pretty much have my CPU do the DSP (Digital Signal Processing): all of the amplification, demodulation, and filtering. The RTL-SDR is a reciever that takes in signals via the antenna and converts them digitally and does some pre-processing, tuning, and sampling. Has a neat FPGA inside and all for it.

And with the GNU Radio Companion, which is a GUI frontend for GNU Radio, I can assemble together blocks to adjust the radio in all sorts of fun ways. It even came with QT support and I managed to get a little screen where I had a "Tuner" to adjust the frequency in steps of 100k samples and there was a "sink" which displayed the waveforms in real time and when the robotic guy spoke, the waves moved.

Of course, the technical reasons the waves move is because we demodulate the signals in the air, which is like getting a package (the carrier wave) and demodulating it (opening the package), and using the signals contents to do what we want (and in this case that is converting the bits and bytes from our demodulated signal and turning it into audio via the "audio sink".


In general, I am happy with the small dongle and the entire kit was ~$50, which, if you are anyone like me, is WAY cheaper than a videogame nowadays. Endless entertainment, endless creativity, and I can now see what is happening.

Of course, I believe there are probably some channels I can't listen to for one reason for another, but there are some I can listen to.

I already plan on using similar techniques to make an actual FM radio from 88MHz to 108MHz and, if what I asked ChatGPT is correct, I can also listen to NHK World Radio Japan so long as my antennas are long enough.

Below is a small video of my small setup.

[![Watch the video](https://img.youtube.com/vi/gDL-5G-u-qQ/maxresdefault.jpg)](https://www.youtube.com/watch?v=gDL-5G-u-qQ)

In the video above I was using a Framework 13 Laptop with a 7640U with 32GB DDR5 running Arch Linux x86_64 with kernel version 6.18.2-arch2-1 and with a DE of Cinnamon 6.6.3 while using X11.


-------Future Stuff-------
