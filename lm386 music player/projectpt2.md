It is now April 14, 2026. For the past two days I have been working on rebuilding the audio circuit to make some improvements on it.

A few things:

1. I want it to sound cleaner.
2. I want it to run more efficiently.
3. Adjustable volume.
4. I want it to be WAY louder.

With that, I got to work.

From the first design, which I did not make a schematic for to illustrate, used two low-pass filters in series that used a 1kΩ resistor and a 100pF capacitor.

Together, they make a pretty bland low-pass. With that setup I get a cutoff of about 1.59MHz, which is pretty useless since PWM doesn't get anywhere near that.

So, with the components I had, I decided to replace the resistor with a 10kΩ and the capacitors with a 100nF. This would now make my new cutoff frequency about 159Hz. But even this is kind of an issue since that means higher frequencies are being neglected. In our case, it ended up not being too bad for the audio, but trying this with 1kΩ...

Wait... I was going to rewrite this section but this was literally the point I realized that I didn't even use 10kΩ resistors... AWKWAARD..

I used 1kΩ resistors, which may be why it didn't sound like it was being played under 5 comforters and wool blankets. And since they were in series, that means we had a 2nd order filter and our actual cutoff frequency was closer to 1.024kHz.

Interestingly, I have 560Ω and 220Ω and if I were to use them I would get cutoff's of 1.829kHz and 4.655kHz, respectively, which may sound much better.

Though, for now, let's stick with the 1kΩ resistor setup we have going.


From the previous design, I also argue I made it more efficient by taking off the resistors in parallel on the output and to instead use capacitors connected directly to the 4Ω speaker.

For the capacitors I used 2 100uF in parallel that connected directly with the speaker and a 100nF capacitor connected at the output of the LM386 to ground. This was done because I had previously made a grave mistake (treating pin 2 as ground and completely ignoring pin 4), which caused my circuit to oscillate a LOT and it produced various frequencies as a result. Before realizing said mistake, the 100nF capacitor helped alievate some of the issues as it have the higher frequencies a way out of the circut and this would put less strain on the LM386. A short search later and what this is is a Zobel Network without the resistor since I didn't have one. I haven't tested efficiency without this capacitor, but from what I can read it should make our output more stable.

Otherwise, all 100pF capacitors were replaced by the 100nF. The last addition that was made was a potentiometer at the input to adjust the volume. I did this because when I heard the oscillations I assumed the PWM was too high and it was maxing out the IC.

Funnily enough, the time I realized that the PWM wasn't the issue was exactly when I removed it entirely and still heard the oscillations. Man, analog circuits are fun.

Lastly, I kind of also thought the problem was to do with the shared grounding which was also causing errors on the Arduino... I guess uploading code to it while it is connected to a breadboard with about 9V is "a problem". So, I decided to scrap USB power entirely and to just use my DC Power Supply to connect to the input of the LM386 and to the VIN plug on the Arduino. This massively improved setup and wiring.



By the end, we are left with a circuit like this:

<img src="/images/20260414_114011.jpg">
<img src="/images/20260414_115952.jpg">
<img src="/images/20260414_120000.jpg">
<img src="/images/20260414_120022.jpg">
<img src="/images/20260414_120038.jpg">
<img src="/images/20260414_120045.jpg">
<img src="/images/20260414_120153.jpg">



And here is the circuit diagram I put together in QUCS-S.

<img src="/images/lm386ampcircuit2.png">



And with that, we can hook it up and we can hear how the audio has changed. It is louder, less static, and I am overall much happier with it. The new audio is in the folder under "Esther's Waltz Circuit 2.m4a".

Take care.
