# Getting Started
To use this library, download the zip file here and move it into your PROS project. Then, go to your terminal and run the following commands:

`pros c fetch [write the whole file name here]`

`pros c apply [write the whole file name here without the .zip part]`

# Setting Up Your Main.cpp
After bringing the library into your code, you need to add two things to your main.cpp for the auton selector and leds to work:

In the initialize method, add:
selector_initialize();

In the automous method, add:

```cpp
if (!isSkills) {

		if (isRed) {
  
			if (isLeft) {
   
				if (currentAuton == 1) {}; // Red Left AWP
    
				if (currentAuton == 2) {}; // Red Left Safe
    
				if (currentAuton == 3) {}; // Red Left Rush
    
				if (currentAuton == 4) {}; // Red Left Misc
    
			}
   
			else {
   
				if (currentAuton == 1) {}; // Red Right AWP
    
				if (currentAuton == 2) {}; // Red Right Safe
    
				if (currentAuton == 3) {}; // Red Right Rush
    
				if (currentAuton == 4) {}; // Red Right Misc
    
			}
   
		}
  
		else {
  
			if (isLeft) {

				if (currentAuton == 1) {}; // Blue Left AWP
    
				if (currentAuton == 2) {}; // Blue Left Safe
    
				if (currentAuton == 3) {}; // Blue Left Rush
    
				if (currentAuton == 4) {}; // Blue Left Misc
    
			}
   
			else {
   
				if (currentAuton == 1) {}; // Blue Right AWP
    
				if (currentAuton == 2) {}; // Blue Right Safe
    
				if (currentAuton == 3) {}; // Blue Right Rush
    
				if (currentAuton == 4) {}; // Blue Right Misc
    
			}
   
		}
  
	}
 
	else {
 
		if (currentAuton == -1) {}; // Skills 1
  
		if (currentAuton == -2) {}; // Skills 2
  
		if (currentAuton == -3) {}; // Skills 3
  
		if (currentAuton == -4) {}; // Skills 4
  
	}
 
}
```
