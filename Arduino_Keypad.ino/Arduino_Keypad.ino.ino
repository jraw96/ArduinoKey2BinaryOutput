// Program: Using a keypad with an Arduino Uno and 4-to-16 Decoder to control 16 LED lights individually


#include <Keypad.h>

//Initialize output pins:
int LEDpins[] = {10,11,12,13}; // The first four output pins. Numbers 2-5 are for BCD selection, 6 is for turning all outputs HIGH
int keypadPins[] = {2,3,4,5,6,7,8,9};
int pinCount = 4;


//Initialize 4x4 keypad

const byte rows = 4;
const byte columns = 4; 
char keys[rows][columns] = {
  {'G','8','C','4'}, 
  {'F','7','B','3'},
  {'E','6','A','2'},
  {'D','5','9','1'}
};

/*
{'G','8','C','4'}, 
  {'F','7','B','3'},
  {'E','6','A','2'},
  {'D','5','9','1'}
  */
  

byte rowPins[rows] = {2,3,4,5}; // Connect to digital pins #2,3,4,5
byte columnPins[columns] = {6,7,8,9}; // Connect to the digital pins #6,7,8,9

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, columnPins, rows, columns); // Create the keypad obejct


void setup() {
Serial.begin(9600); // The computers now talk at the same bit rate

//Initialize the digital output pins on the Arduino so that they will be sending OUT data
for (int outputPin = 0; outputPin < pinCount; outputPin++){ // Connect to digital pins #10,11,12,13
  pinMode(LEDpins[outputPin], OUTPUT);
  if(outputPin == 4){
    pinMode(LEDpins[outputPin], INPUT);
  }
}

//Initialize input pins:
for (int inputPin = 0; inputPin < 7; inputPin++){
  pinMode(keypadPins[inputPin], INPUT);
}

  
} // End of setup

void loop() {
  
  //Configure the keypad so when a button is pushed, the binary equivalent is sent the decoder
  char pushedKey = myKeypad.getKey(); // Assign a pushed key symbol to a varaible called 'pushedKey'
  
    if(pushedKey == '1'){
      digitalWrite(LEDpins[0], LOW); // BCD: 0000
      digitalWrite(LEDpins[1], LOW);
      digitalWrite(LEDpins[2], LOW);
      digitalWrite(LEDpins[3], LOW);
    }

   if (pushedKey == '2'){
      digitalWrite(LEDpins[0], HIGH); // BCD: 0001
      digitalWrite(LEDpins[1], LOW);
      digitalWrite(LEDpins[2], LOW);
      digitalWrite(LEDpins[3], LOW);
    }

  if (pushedKey == '3'){
      digitalWrite(LEDpins[0], LOW); // BCD: 0010
      digitalWrite(LEDpins[1], HIGH);
      digitalWrite(LEDpins[2], LOW);
      digitalWrite(LEDpins[3], LOW);
    }
    
     if (pushedKey == '4'){
      digitalWrite(LEDpins[0], HIGH); // BCD: 0011
      digitalWrite(LEDpins[1], HIGH);
      digitalWrite(LEDpins[2], LOW);
      digitalWrite(LEDpins[3], LOW);
    }

      if (pushedKey == '9'){
      digitalWrite(LEDpins[0], LOW); // BCD: 0100
      digitalWrite(LEDpins[1], LOW);
      digitalWrite(LEDpins[2], HIGH);
      digitalWrite(LEDpins[3], LOW);
     }

      if (pushedKey == 'A'){
      digitalWrite(LEDpins[0], HIGH); // BCD: 0101
      digitalWrite(LEDpins[1], LOW);
      digitalWrite(LEDpins[2], HIGH);
      digitalWrite(LEDpins[3], LOW);
     }

     if (pushedKey == 'B'){
      digitalWrite(LEDpins[0], LOW); // BCD: 0110
      digitalWrite(LEDpins[1], HIGH);
      digitalWrite(LEDpins[2], HIGH);
      digitalWrite(LEDpins[3], LOW);
     }

     if (pushedKey == 'C'){
      digitalWrite(LEDpins[0], HIGH); // BCD: 0111
      digitalWrite(LEDpins[1], HIGH);
      digitalWrite(LEDpins[2], HIGH);
      digitalWrite(LEDpins[3], LOW);
     }

     if (pushedKey == '5'){
      digitalWrite(LEDpins[0], LOW); // BCD: 1000
      digitalWrite(LEDpins[1], LOW);
      digitalWrite(LEDpins[2], LOW);
      digitalWrite(LEDpins[3], HIGH);
     }

     if (pushedKey == '6'){
      digitalWrite(LEDpins[0], HIGH); // BCD: 1001
      digitalWrite(LEDpins[1], LOW);
      digitalWrite(LEDpins[2], LOW);
      digitalWrite(LEDpins[3], HIGH);
     }

     if (pushedKey == '7'){
      digitalWrite(LEDpins[0], LOW); // BCD: 1010
      digitalWrite(LEDpins[1], HIGH);
      digitalWrite(LEDpins[2], LOW);
      digitalWrite(LEDpins[3], HIGH);
     }

     if (pushedKey == '8'){
      digitalWrite(LEDpins[0], HIGH); // BCD: 1011
      digitalWrite(LEDpins[1], HIGH);
      digitalWrite(LEDpins[2], LOW);
      digitalWrite(LEDpins[3], HIGH);
     }

    if (pushedKey == 'D'){
      digitalWrite(LEDpins[0], LOW); // BCD: 1100
      digitalWrite(LEDpins[1], LOW);
      digitalWrite(LEDpins[2], HIGH);
      digitalWrite(LEDpins[3], HIGH);
     } 

     if (pushedKey == 'E'){
      digitalWrite(LEDpins[0], HIGH); // BCD: 1101
      digitalWrite(LEDpins[1], LOW);
      digitalWrite(LEDpins[2], HIGH);
      digitalWrite(LEDpins[3], HIGH);
     }

     if (pushedKey == 'F'){
      digitalWrite(LEDpins[0], LOW); // BCD: 1110
      digitalWrite(LEDpins[1], HIGH);
      digitalWrite(LEDpins[2], HIGH);
      digitalWrite(LEDpins[3], HIGH);
     }

     if (pushedKey == 'G'){
      digitalWrite(LEDpins[0], HIGH); // BCD: 1111
      digitalWrite(LEDpins[1], HIGH);
      digitalWrite(LEDpins[2], HIGH);
      digitalWrite(LEDpins[3], HIGH);
     }

     if(myKeypad.getState() == RELEASED){ // If no button is currently being pressed, press the BCD for 16. This acts as a default toggle off switch after a button is pushed. 
      digitalWrite(LEDpins[0], HIGH);
      digitalWrite(LEDpins[1], HIGH);
      digitalWrite(LEDpins[2], HIGH);
      digitalWrite(LEDpins[3], HIGH);
     }

}
