#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define trigPin 9
#define echoPin 8
#define BUZ 13
#define RED_LED 7
#define VIB 6

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

long duration, distance;

void setup() {
  pinMode(BUZ, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(VIB, OUTPUT);
  Serial.begin(9600);
  
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  digitalWrite(VIB, HIGH);
  delay(3000);
  digitalWrite(VIB, LOW);

}

// void vibrate(int num_sec) {
//     Serial.println(1);
//      digitalWrite(VIB, HIGH);
//      delay(num_sec*1000);
//      Serial.println(0);
//      digitalWrite(VIB, LOW);
// }

// void blink_led(int num_blinks){
//   for (int i = 0; i < num_blinks; ++i){
//   digitalWrite(RED_LED, HIGH);
//   delay(200);
//   digitalWrite(RED_LED, LOW);
//   delay(200);
//   }
// }

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  display.clearDisplay();
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Distance: ");
  display.print(distance);
  display.println(" cm");
  display.display();
  
  if (distance < 5) {
    digitalWrite(VIB, HIGH);
    for (int i = 0; i < 4; i++) {
      digitalWrite(BUZ, HIGH);
      digitalWrite(RED_LED, HIGH);
      delay(10);
      digitalWrite(BUZ, LOW);
      digitalWrite(RED_LED, LOW);
      delay(10);
    }
    delay(2000);
    digitalWrite(VIB, LOW);
  } else if (distance < 15) {
    digitalWrite(VIB, HIGH);
    for (int i = 0; i < 3; i++) {
      digitalWrite(BUZ, HIGH);
      digitalWrite(RED_LED, HIGH);
      delay(50);
      digitalWrite(BUZ, LOW);
      digitalWrite(RED_LED, LOW);
      delay(50);
    }
    delay(2000);
    digitalWrite(VIB, LOW);
  } else if (distance < 25) {
    digitalWrite(VIB, HIGH);
    for (int i = 0; i < 2; i++) {
      digitalWrite(BUZ, HIGH);
      digitalWrite(RED_LED, HIGH);
      delay(100);
      digitalWrite(BUZ, LOW);
      digitalWrite(RED_LED, LOW);
      delay(100);
    }
    delay(2000);
    digitalWrite(VIB, LOW);
  } else if (distance < 38) {
    digitalWrite(VIB, HIGH);
    for (int i = 0; i < 1; i++) {
      digitalWrite(BUZ, HIGH);
      digitalWrite(RED_LED, HIGH);
      delay(300);
      digitalWrite(BUZ, LOW);
      digitalWrite(RED_LED, LOW);
      delay(300);
    }
    delay(2000);
    digitalWrite(VIB, LOW);
  } else if (distance < 40) {
    digitalWrite(VIB, HIGH);
    for (int i = 0; i < 1; i++) {
      digitalWrite(BUZ, HIGH);
      digitalWrite(RED_LED, HIGH);
      delay(400);
      digitalWrite(BUZ, LOW);
      digitalWrite(RED_LED, LOW);
      delay(400);
    }
    delay(2000);
    digitalWrite(VIB, LOW);
  }
  delay(200); 
}