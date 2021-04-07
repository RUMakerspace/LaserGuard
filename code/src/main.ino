long delayTime;

#include <Bounce2.h>
Bounce2::Button button = Bounce2::Button();

bool enabledLaser;
void setup() {
	enabledLaser = false;
	pinMode(LED_BUILTIN, OUTPUT);

	
	// these pins detect when the relay is closed on the control box
    pinMode(11, OUTPUT);
    digitalWrite(11, LOW);
	
	button.attach(12, INPUT_PULLUP);
	button.interval(100);
	button.setPressedState(LOW); 
	
	disableLaser();
}

void disableLaser() {
	pinMode(9, OUTPUT);  
    pinMode(10, OUTPUT); 
}

void enableLaser() {
    pinMode(9, INPUT);  // turn the LED on (HIGH is the voltage level)
    pinMode(10, INPUT);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
}
// the loop function runs over and over again forever
void loop() {	
  button.update();
  //***************************   
  //check if this switch has changed state
  
  if (button.fell()) {
      enabledLaser = !enabledLaser;
	  Serial.println(enabledLaser);
	  
	  if (!enabledLaser) {
		  disableLaser();
	  } else {
		  enableLaser();
	  }
  }
  

  
  
}

