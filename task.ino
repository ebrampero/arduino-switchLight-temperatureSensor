int pinButton = 8;              //the pin where we connect the button
int LED = 2;                   //the pin we connect the LED
float temperatura = 0;        //variable  temperatura sensor analog

void setup() {
  Serial.begin(9600);       //start serial connection
  pinMode(pinButton, INPUT); //set the button pin as INPUT
  pinMode(LED, OUTPUT); //set the LED pin as OUTPUT

}

void loop() {
 int b;
  b = switch_light();
  Serial.print(b);
  /* we using LM35dz temperature sensor*/
    //Calculate the temperature using as reference 5v
temperatura = (5.0 * analogRead(0)*100.0)/1023.0;
Serial.print("\t\tC\t");
Serial.println (temperatura); //write the temperature in the serial monitor

delay (3000); //wait 3 seconds for the next read
 
}
int switch_light(){
  int stateButton = digitalRead(pinButton); //read the state of the button
  if(stateButton == 1) { //if is pressed
     digitalWrite(LED, HIGH); //write 1 or HIGH to led pin
     Serial.println("Pressed\t\tLed ON");
  } else { //if not pressed
     digitalWrite(LED, LOW);  //write 0 or low to led pin
     Serial.print("\tLED OFF\t");
  }
  return 0;
  }
