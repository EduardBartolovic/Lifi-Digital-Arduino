// code for receiving using the LDR

unsigned long StartTime = millis();

unsigned long Value; unsigned long EndTime;

int Message;

boolean StartedCounting = false; //this is used to determine if the counting has started

void setup() { Serial.begin(9600); }

void loop() {

int sensorValue = analogRead(A0); //read the sensor value

delay(1); // to stabilize

// Serial.println(sensorValue); // this can be used to determine the threshold in your lighting conditions

if (StartedCounting==false && sensorValue>850){ //if the counting has not yet started and the light is on

StartTime = millis(); // This saves the current time in milli seconds

StartedCounting= true; }

if (StartedCounting== true && sensorValue<850){ // if the counting has started and the light is off

Value = millis() - StartTime; // subtract the starting time from the current time to get message time Message= Value/1000;

StartedCounting= false;

Serial.print ("Message: ");

if (Message == 1){ // change these to your own messages. the sender should also have this list so they know what they send.

Serial.println("hi"); }

else if (Message == 2){

Serial.println("wazzup?"); }

else if (Message == 3){

Serial.println("HELP"); }

else if (Message == 4){

Serial.println("top secret"); }

else if (Message == 5){

Serial.println("Penguins"); } '

else if (Message == 6){

Serial.println("LI-FI is the future"); }

else if (Message == 7){

Serial.println("#notreallythough"); } } }
