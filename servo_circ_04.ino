// Servo motor control
// James Perrin GE102

#include <Servo.h>
bool lastButton = LOW;              // True or False
bool currentButton = LOW;             // True or False
bool lastButton2 = LOW;              // True or False
bool currentButton2 = LOW;             // True or False
Servo myservo;                     // create servo object to control a servo
                                     // a maximum of eight servo objects can be created
#define buttonPin 2            // control button one
#define buttonPin2 4           // control button two
int pos = 0;                         // variable to store the servo position

void setup()
{
  myservo.attach(9);                           // attaches the servo on pin 9 to the servo object
   pinMode(buttonPin, INPUT);                 // Uhh setting pinmode to input for the button
   pinMode(buttonPin2, INPUT);                 // Uhh setting pinmode to input for the button
  Serial.begin (9600);                      // So I can see what the POSition is in the serial monitor
}

 boolean debounce(boolean last)                   // My debouncing attempt for the first button
  {
    boolean current = digitalRead(buttonPin);
    if (last != current)
    {
      delay(2);
      current = digitalRead(buttonPin);
    }
    return current;
  }

boolean debounce2(boolean last)                   // My debouncing attempt for the second button
  {
    boolean current = digitalRead(buttonPin2);
    if (last != current)
    {
      delay(2);
      current = digitalRead(buttonPin2);
    }
    return current;
  }
  
void loop()
{
    currentButton = debounce(lastButton);                      // runs debounce routine
 
    
  if (lastButton == LOW && currentButton == HIGH) {            // Part of the debounce and beginning of "if" tree

        if(pos <= 180; pos += 10)                         // goes from 0 degrees to 180 degrees
   
       {                                                 // in steps of 1 degree
            myservo.write(pos);                           // tell servo to go to position in variable 'pos'
            Serial.println (pos);
            Serial.println (buttonPin);
            delay(15);                                 // waits 15ms for the servo to reach the position
}
  }

 currentButton2 = debounce2(lastButton2);                      // runs debounce routine

 if (lastButton2 == LOW && currentButton2 == HIGH) {            // ** so that the button doesnt double register... I think...

        if(pos >= 0; pos -= 10)                                         // goes from 180 degrees to 0 degrees
  
       {                                                         // in steps of 1 degree
            myservo.write(pos);                         // tell servo to go to position in variable 'pos'
            Serial.println (pos);
            Serial.println (buttonPin2);
            delay(15);                                     // waits 15ms for the servo to reach the position
}
  }
  
  if(pos > 180)                                      // helps reset position if I go to far to the right
  {
  pos = 0;                                     // goes from 0 degrees to 180 degrees
  
  {                                                      // in steps of 1 degree
    myservo.write(pos);                             // tell servo to go to position in variable 'pos'
    Serial.println (pos);
    Serial.println (buttonPin);
    delay(15);                                   // waits 15ms for the servo to reach the position

    
  }
  
                        // waits 15ms for the servo to reach the position
  }

if(pos < 0)
  {
  pos = 180;                                   // resets motor to the other side of its min
  
  {                                  // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println (pos);
    Serial.println (buttonPin);
    delay(15);                       // waits 15ms for the servo to reach the position

    
  }
  
                       
  }

   
   lastButton = currentButton;                  //  ties back to **
    lastButton2 = currentButton2;                  //  ties back to **
}
