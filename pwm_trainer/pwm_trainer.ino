
int rLEDPin = 6;
int gLEDPin = 5;
int bLEDPin = 3;

#include <MicroView.h>

void setup() {
  uView.begin();
  uView.clear(PAGE);
  Serial.begin(115200);
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
}

const int pwm_height = 10;
const int pwm_width = 28;

const int left_column = 1;
const int right_column = 34;
const int top_row = 1;
const int bottom_row = 26;

const int text_spacing = 3;
const int top_text = top_row + pwm_height + text_spacing;
const int bottom_text = bottom_row + pwm_height + text_spacing;

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  int rInput = analogRead(A2);
  int gInput = analogRead(A1);
  int bInput = analogRead(A0);
  int rPercent = map(rInput, 0, 1024, 0, 100);
  int gPercent = map(gInput, 0, 1024, 0, 100);
  int bPercent = map(bInput, 0, 1024, 0, 100);
  uView.clear(PAGE);
  analogWrite(rLEDPin, 255 - (rInput / 4));
  squareWave(left_column, top_row, pwm_width, pwm_height, rPercent);
  uView.setCursor(left_column, top_text);
  uView.print(rPercent);
  analogWrite(gLEDPin, 255 - (gInput / 4));
  squareWave(right_column, top_row, pwm_width, pwm_height, gPercent);
  uView.setCursor(right_column, top_text);
  uView.print(gPercent);
  analogWrite(bLEDPin, 255 - (bInput / 4));
  squareWave(left_column, bottom_row, pwm_width, pwm_height, bPercent);
  uView.setCursor(left_column, bottom_text);
  uView.print(bPercent);

  // grid lines
  uView.line(0, 24, 64, 24);
  uView.line(32, 0, 32, 48);

  // print out the value you read:
  Serial.print(rInput);
  Serial.print(", ");
  Serial.print(gInput);
  Serial.print(", ");
  Serial.println(bInput);
  delay(1);  // delay in between reads for stability
  uView.display();
}

void squareWave(int x, int y, int width, int height, int duty_percent) {
  int falling_edge = map(duty_percent, 0, 100, 0, width);
  // front line
  uView.line(x, y, x, y + height);
  // Top edge
  uView.line(x, y, x + falling_edge, y);
  uView.line(x + falling_edge, y, x + falling_edge, y + height);
  uView.line(x + falling_edge, y + height, x + width, y + height);
  // end line
  uView.line(x + width, y, x + width, y + height);
}
