# Intro
StormLib is a template built for PROS 4 that includes LED control and an auton selector. For installation details, see the [Releases](https://github.com/ItzSt0rmz/StormLib/releases) page. 

Have any questions or feature requests, join the discord: [https://discord.gg/vTmMG3dAX6](https://discord.gg/vTmMG3dAX6)

<p align="center">
<img src="https://img.shields.io/github/downloads/ItzSt0rmz/StormLib/total?style=for-the-badge">
<img src="https://img.shields.io/github/actions/workflow/status/StormLib/StormLib/pros-build.yml?style=for-the-badge">
</p>

# LEDs

## Hardware
> **Note**: You will need to be able to solder to make LED strips work with the brain.

To physically make and LED strand, you need a ws2812b LED strip. Ideally, it should be the 3.2 ft / 144 LEDs version. I have found succes with [these](https://www.amazon.com/LOAMLIN-WS2812B-Individually-Addressable-Waterproof/dp/B0BDS7NHQM/ref=sr_1_1_sspa?crid=3QMI9YVXRJ2PC&dib=eyJ2IjoiMSJ9.mlyNyKu8sW0HjM47ymHDzEoFGXABafTwodGXpzt9VwI-Lv8LFS2u9yhH3BhA2Iwf570mAY4Ekyexp1H5W5RJWK3aMbZSfJYFwXSIwvYHNLbljmZfGRvuHppLttSrjQ3SZqhybXdSesw3p_CfC1Ew92qXghKaDi4X59g48a-ebQAcGYDuKsucng5k_89eOIewr568RB15qNSmQ6VtADMjS9qBByOqL5m592_0AjCXj5ISq4WEAAtE1Nk9f57PaQEhKthh33rfUSNlL87D0NNGItlc_Pi_Z69DmE6U8X5mavQ.-1wO_W9skZxd1iY8jUoIQ9bATbgxqLLgguVxvFfZndg&dib_tag=se&keywords=ws2812b&qid=1728614690&sprefix=ws%2Caps%2C146&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1).

Once you have a roll of LEDs, you will clip the size you want (must be less than 64 pixels), then solder it to a vex 3-wire cable according to the following diagram:

![LEDwiringdiagram](https://github.com/user-attachments/assets/472b7a1e-f3a8-4127-a1ea-fa88f478a0f2)
Credit: Sylvie

> [!NOTE]  
> If you don't want to solder the LEDs yourself, you can order them from the_storm_cloud on Discord.

## Software
LEDs are constructed as: 
<br>
`stormlib::aRGB name(adiPort, length);`
<br>
<br>
Then fed into the manager, constructed as:
<br>
`stormlib::aRGB_manager LEDmanager(
	&strand1,
	&strand2,
	&strand3,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr
);`
<br>
<br>
Finally, to initalize your LEDs, run `LEDmanager.initialize();` in initialize()
<br>
<br>
Now, individual strands or the manager as a whole can take the following commands:
<br>
* `set_color(uint32_t color)` - sets the strand(s) a color
* `flow(uint32_t color1, uint32_t color2, int speed)` - sets the strand(s) to cycle a gradient between two colors
* `rainbow(int speed)` - sets the strand(s) to cycle a rainbow
* `flash(uint32_t color1, int speed, uint32_t color2)` - sets the strand(s) to flash a color or flash between two colors
* `pulse(uint32_t color, int length, int speed, uint32_t color2)` - sends a pulse down the strand(s)
* `off()` - turns off the strand(s)

# Auton Selector
The auton selector is constructed as:
<br>
`stormlib::selector autonSelector(stormlib::selector::E_BLUE_RIGHT_4, "slot1Name", "slot2Name", "slot3Name", "slot4Name");`
<br>
<br>
Then, to initalize it, run `autonSelector.initialize();` in initialize()
<br>
<br>
In autonomous(), autons are assigned to slots as following:
<br>
`if (autonSelector.getAuton() == ENUMERATED SLOT VALUE) {function here}`
<br>
<br>
A default auton can be set using the form:
<br>
`if (autonSelector.getAuton() == 0) {function here};`

# Clock
A clock is initialized as:
<br>
`stormlib::clock driverClock;`
<br>
<br>
Then, to start it, run `driverClock.start(time_in_seconds * 100);` It is default 1:45 (i.e. opcontrol period) if you leave the parameter blank.
<br>
<br>
Once the clock is started, you can now access how much time is left via:
<br>
<br>
`driverClock.timeLeft()`
<br>
<br>
Or delay until a certain time, which is useful for tasks dependent on the game clock:
<br>
<br>
`driverClock.waitUntil(time_in_seconds * 1000);`

# Contributing
If you want to see a feature, feel free to open a pull request!
