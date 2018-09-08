#include <UltrasonicProximitySensor.h>

UltrasonicProximitySensor proximity_sensor(2, 3);
int led = 13;
int led2 = 12;

void setup(void)
{
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  unsigned long distance_in_cm = proximity_sensor.getDistanceInCm();
  
  if (distance_in_cm < 70) {
    if (digitalRead(led) == LOW) {
      digitalWrite(led, HIGH);
      digitalWrite(led2, HIGH);
      Serial.print("Led: ON\n");
      Serial.print("Distance: ");
      Serial.print(distance_in_cm);
      Serial.print("cm\n");
      
    }
    else {
      digitalWrite(led, LOW);
      digitalWrite(led2, LOW);
      Serial.print("Led: OFF\n");
      Serial.print("Distance: ");
      Serial.print(distance_in_cm);
      Serial.print("cm\n");
    }
  
  }
  else {
     Serial.print("Distance: ");
     Serial.print(distance_in_cm);
     Serial.print("cm\n");
  }
  delay(500);
}
