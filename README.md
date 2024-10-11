# Welcome
Hey there! StormLib is a template built for PROS 4 that includes LED control and an auton selector. For installation details, see the [Releases](https://github.com/ItzSt0rmz/StormLib/releases) page.

# LEDs
To physically make and LED strand, you need a 
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
* `set_color()` - sets the strand(s) a color
* `flow()` - sets the strand(s) to cycle a gradient between two colors
* `rainbow()` - sets the strand(s) to cycle a rainbow
* `flash()` - sets the strand(s) to flash a color or flash between two colors
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

# Contributing
If you want to see a feature, feel free to open a pull request!

<img src="https://img.shields.io/github/downloads/ItzSt0rmz/StormLib/total?style=for-the-badge">
