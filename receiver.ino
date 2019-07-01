unsigned long StartTime = millis();

unsigned long Value; 

unsigned long EndTime;

int Message;

int counter = 0;

byte group[7] = {0,0,0,0,0,0,0};

int weights[7] = {1,2,4,8,16,32,64};

boolean StartedCounting = false; //this is used to determine if the counting has started

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0); //read the sensor value

  delay(1); // to stabilize

  //Serial.println(sensorValue); // this can be used to determine the threshold in your lighting conditions

  if (StartedCounting == false && sensorValue > 900) { //if the counting has not yet started and the light is on

    StartTime = millis(); // This saves the current time in milli seconds

    StartedCounting = true;
  }

  if (StartedCounting == true && sensorValue < 900) { // if the counting has started and the light is off

    Value = millis() - StartTime; // subtract the starting time from the current time to get message time 
    
    Message = Value/8; // Message 

    StartedCounting = false;

    if (Message == 1) { 
      group[counter] = 0;
      //Serial.println("0");
      counter += 1;
    } else if (Message == 2) {
      group[counter] = 1;
      counter += 1;
      //Serial.println("1");
    } else {
      group[0] = 0;
      group[1] = 0;
      group[2] = 0;
      group[3] = 0;
      group[4] = 0;
      group[5] = 0;
      group[6] = 0;
      group[7] = 0;
      counter = 0;
    }
  }
  
  if(counter>6){
    int chara = 0;
    for(int i=0;i<8;i++){
      chara += group[i]*weights[i];
    }
    char final = chara;
    Serial.print(final);
    counter = 0;
  }
}
