#include <pitches.h>
#include <Tone32.h>

/*
   Ultrasonic Simple
   Prints the distance read by an ultrasonic sensor in
   centimeters. They are supported to four pins ultrasound
   sensors (liek HC-SC04) and three pins (like PING)))
   and Seeed Studio sensors).

   The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
     three pins), attached to digital pins as follows:
   ---------------------    --------------------
   | HC-SC04 | Arduino |    | 3 pins | Arduino |
   ---------------------    --------------------
   |   Vcc   |   5V    |    |   Vcc  |   5V    |
   |   Trig  |   12    | OR |   SIG  |   13    |
   |   Echo  |   13    |    |   Gnd  |   GND   |
   |   Gnd   |   GND   |    --------------------
   ---------------------
   Note: You do not obligatorily need to use the pins defined above

   By default, the distance returned by the read()
   method is in centimeters. To get the distance in inches,
   pass INC as a parameter.
   Example: ultrasonic.read(INC)

   created 3 Apr 2014
   by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
   modified 23 Jan 2017
   by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
   modified 03 Mar 2017
   by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
   modified 11 Jun 2018
   by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)

   This example code is released into the MIT License.
*/

#include <Ultrasonic.h>

#define BUZZER_PIN 26
#define BUZZER_CHANNEL 0

/*
   Pass as a parameter the trigger and echo pin, respectively,
   or only the signal pin (for sensors 3 pins), like:
   Ultrasonic ultrasonic(13);
*/
Ultrasonic ultrasonic(5, 4);//Trig,Echo
int distance, olddistance, flag = 0;
unsigned int D = 300;
void setup() {
  Serial.begin(115200);
  //  pinMode(26, OUTPUT);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  //  digitalWrite(26, HIGH);
  //  digitalWrite(26, LOW);
  //  if (olddistance > distance)
  //  {
  //    //  tone(BUZZER_PIN, NOTE_C4, 500, BUZZER_CHANNEL);
  //    //   noTone(BUZZER_PIN, BUZZER_CHANNEL);
  //    // Serial.println("X2");
  //    flag = 1;
  //    delay(100);
  //  }
  //  else if (olddistance < distance)
  //  {
  //    //    tone(BUZZER_PIN, NOTE_C4, 500, BUZZER_CHANNEL);
  //    //   noTone(BUZZER_PIN, BUZZER_CHANNEL);
  //    // Serial.println("X3");
  //    flag = 2;
  //    delay(100);
  //  }
  for (D; distance <= 20; D--)
  {
    D=D+1;
    tone(BUZZER_PIN, NOTE_C4, 500, BUZZER_CHANNEL);
    delay(D);
    noTone(BUZZER_PIN, BUZZER_CHANNEL);
    delay(D);
  }
  for (; distance > 20; D++)
  {
    tone(BUZZER_PIN, NOTE_C4, 500, BUZZER_CHANNEL);
    delay(D);
    noTone(BUZZER_PIN, BUZZER_CHANNEL);
    delay(D);
  }

  olddistance = distance;

  Serial.println(D);
  Serial.println(flag);

  //  tone(BUZZER_PIN, NOTE_C4, 500, BUZZER_CHANNEL);
  //  noTone(BUZZER_PIN, BUZZER_CHANNEL);
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  // delay(1000);
}
