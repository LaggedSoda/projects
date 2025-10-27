### Minimal Arduino Alarm Clock

The minimal arduino alarm clock is a project I worked on sometime in April 2025. The goal of the project was:

1. Make a functional Arduino alarm clock that can keep somewhat accurate time without any other IC.
2. Ensure the alarm clock can set the time and alarm clock.


## The Beginning

With a small breadboard, an Arduino UNO R3, a 16x2 LCD {the TC1602A}, jumper wires, a piezo buzzer {the PKM22EPP-40} and a computer to program on, I was already limited in terms of how complex I could make it. For instance, I couldn't have any external clock to ensure greater accuracy nor could I implement any external storage (for storing alarm sounds), WIFI or Bluetooth devices (for remote access, setting alarm times, and sending files), sensors (for an option for temperature), and an FM radio reciever and amp (for FM radio as an alarm option).

With this in mind, I began working on the simplest alarm.

# Clockv1
[Code](clockv1.ino)

Code was the only way I was going to get any sort of functionality out of my devices. The first bit of code I made (and some code that was more advanced but promised more accurate time keeping) only had the option to set the time and to adjust the time of the alarm.

In this setup, 6 pins from the arduino controlled the LCD while only two other buttons controlled the time.

Testing the code, I was welcomed with a working clock that kept the time fairly accurately, though there was a visible flash from the LCD due to how it updated the time. This "flashing" would go unresolved.

All future versions of the alarm clock are meant to be compatible with future versions of the code.

# Clockv2
[Code](clockv2.ino)

Version 2 of the code organized the code and added two more buttons that would control the alarm and that would also add support for a piezo buzzer. I was incredibly glad to see that the small piezo buzzer that I had (the PKM22EPP-40) could be seated directly on the Arduino to connect the GND pin and the PWM Pin 10, giving the Arduino an "aestetic" and reserving more space on the small breadboard.

In the code, it sets the tone for the piezo buzzer to be 200, with a duration of 0.5s that lasts indefinitely until the "alarm_state" is set to false via the button tied to Pin 13 toggles it off.

The elephant in the room with this code was that there was no way to adjust the time of the alarm besides going and editing the code directly. This could be done on lines 23-26 via alm_hr, alm_min, alm_sec, and alm_flag where alm_flag represented AM/PM.


# Clockv2.1
[Code](clockv2.1.ino)

Version 2.1 adds better formatting for the LCD, buttons to adjust the time of the alarm, and an indicator that showed whether the alarm was set or not. In order to be able to set the time *and* the time for the alarm, I decided to use the button meant for toggling the alarm to also work with the time-setting buttons.

Basically, you could toggle the alarm by pressing it. However, holding the button would cause the "alarm_set" state to alternate every second. With the help of some if-statements, I managed to detect whether or not the h_shift and m_shift (buttons that shifted the hours and minutes by one) were being held. So, if the alarm's button was held, we could use the same logic from the time setting functionality to work for setting the alarm's time.

I also added functionality to show the time the alarm was being set to in the second row (technically row 1) of the LCD while the alarm button was being held. Now, the alarm clock was more or less complete.


# Clockv3
[Code](clockv3.ino)

This version of the code claims to implement less flickering (which, visually, it is hard to notice), made the code more efficient (aka less writes to the LCD), and "fixed" a minor flag issue (which was not fixed, but commented out).

Overall, the code is also somewhat more organized.


## Final Notes

While I never expected to feel so proud of this project, I did (not because I would spend an hour figuring out why the flag option was not displaying) because I made something with as little as possible.

In the future, I would like to firstly make a Clockv3.1 to organize the code further to make sure any configuration for the alarm is located at the top (i.e. adjusting tone and a toggle for 24-hour time if I decide to implement it).

It would be nice to see this project in the future with more components, such as rechargable batteries, memory to restore the last saved time and the settings for the alarm, the option for more advanced sounds and music (or even sensor monitoring) via an SD card. Other fun (but won't likely happen) improvents could be switching to a custom LCD, OLED Display (but I'm anal about low-power), a bluetooth option to adjust any settings on the alarm clock, and an AM/FM reciever to play music.

And as much as I say that this is a practical use of my Arduino, I am continually reminded of how cell phones today can do everything and more, but it was still incredibly fun to build and code the alarm clock (especially knowing the R3 has 32kb of Flash, 2kb of SRAM, and 1kb of EEPROM).
