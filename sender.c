// code for sending the message with the LED


int Message1 = 6; // set the number of the first message you want to convey

int Message2 = 2; // set the number of the second message you want to convey boolean Message1done = false; // this will be used to determine if the first message has been sent

int i=0;

int j=0;

void setup()

{ pinMode(10, OUTPUT); //pin connected to the led Serial.begin(9600); //sets serial port for communication }

void loop(){

if ( i < Message1) { // Sending the first message. this will loop until i has reached the value of message1

digitalWrite(10,HIGH); // turn on the LED

i++; //increase i with 1

delay (1010); // wait for a second (1010 mili seconds, a little more than a second to correct inaccuracies) }

else if (Message1done == false){ // once the led has been lit long enough it will be turned off a

digitalWrite(10,LOW);

delay(1000); // wait a second before sending the next message

Message1done= true; // note that message one has been sent }

if (( j < Message2) && (Message1done == true)) { // sending the second message only if message one is done

digitalWrite(10,HIGH); //this code is in priciple the same as for message 1

j++;

delay (1010); }

else if (Message1done == true) { digitalWrite(10,LOW);

exit(0); // stop the execution of the code when both messages are sent } }
