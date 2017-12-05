//GPS
//button
//gps
//transmiter


#include <LiquidCrystal.h>
#include <string.h>
#include <ctype.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int rxPin = 0; // RX pin
int txPin = 1; // TX pin
int byteGPS=-1;
char cmd[7] = "$GPRMC";
int counter1 = 0; // counts how many bytes were received (max 300)
int counter2 = 0; // counts how many commas were seen
int offsets[13];
char buf[300] = "";

/**
 * Setup display and gps
 */
void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  Serial.begin(4800);
  lcd.begin(16, 2);
  lcd.print("waiting for gps");
  offsets[0] = 0;
  reset();
}

void reset() {
  counter1 = 0;
  counter2 = 0;
}

int get_size(int offset) {
  return offsets[offset+1] - offsets[offset] - 1;
}

int handle_byte(int byteGPS) {
  buf[counter1] = byteGPS;
  Serial.print((char)byteGPS);
  counter1++;
  if (counter1 == 300) {
    return 0;
  }
  if (byteGPS == ',') {
    counter2++;
    offsets[counter2] = counter1;
    if (counter2 == 13) {
      return 0;
    }
  }
  if (byteGPS == '*') {
    offsets[12] = counter1;
  }

  // Check if we got a <LF>, which indicates the end of line
  if (byteGPS == 10) {
    // Check that we got 12 pieces, and that the first piece is 6 characters
    if (counter2 != 12 || (get_size(0) != 6)) {
      return 0;
    }

    // Check that we received $GPRMC
    for (int j=0; j<6; j++) {
      if (buf[j] != cmd[j]) {
        return 0;
      }
    }

    // Check that time is well formed
    if (get_size(1) != 10) {
      return 0;
    }

    // Check that date is well formed
    if (get_size(9) != 6) 
      return 0;
  }
}
  


// constants won't change. They're used here to set pin numbers:
//const int buttonPin = 2;     // the number of the pushbutton pin
//!!!!!!!!!!!!!GPS const int!!!!!!!!!!!!!!!!


//int buttonState = 0;         // variable for reading the pushbutton status

//void setup() {
  // initialize the LED pin as an output:
 // pinMode(!!!!!!!GPS!!!!!!!!, OUTPUT);
  // initialize the pushbutton pin as an input:
//  pinMode(buttonPin, INPUT);
//}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn GPS on:
   digitalWrite(!!!!!!!GPS!!!!!!, HIGH);

  }
}
{
void(* resetFunc) (void) = 0;//declare reset function at address 0
}