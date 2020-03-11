#include <SimpleShell.h>

#define BAUDRATE 1200

void helloworld(String *args) {
  // Print "Hello World!"
  Serial.println("Hello World!");
  // Print the arguments we've got
  Serial.println(*args);
}

void setup() {
  // Setup the builtin LED for blinking
  pinMode(LED_BUILTIN, OUTPUT);

  // Register our 'helloworld' command
  Shell.registerCommand(new ShellCommand(helloworld, F("helloworld")));
  // Setup the serial communication
  Shell.begin(BAUDRATE);
}

void serialEvent() {
  // Handle the serial input
  Shell.handleEvent();
}

void loop() {
  // Blink the builtin LED
	digitalWrite(LED_BUILTIN, HIGH);
	delay(250);
	digitalWrite(LED_BUILTIN, LOW);
	delay(250);
}
