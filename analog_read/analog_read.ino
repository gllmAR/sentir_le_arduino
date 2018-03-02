#define minimum_value 450
#define maximum_value 550
#define input_pin A0
#define output_pin 9

/*

*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int raw_value = analogRead(A0);
  int scale_value = map(raw_value, minimum_value, maximum_value, 0, 255);
  scale_value = constrain(scale_value, 0, 255);
  analogWrite(output_pin, scale_value);
  analogWrite(13, scale_value);

  // print out the value you read:
  Serial.print(raw_value);
  Serial.print(" ");
  Serial.println(scale_value);
  delay(1);        // delay in between reads for stability
}
