// code for sending the message with the LED

//char message[] = {'h','a','l','l','o',' '};
int weights[] = {1,2,4,8,16,32,64,128};

int rate = 100;
int mes;
float off;
int delay1;

void setup() {
  pinMode(10, OUTPUT); //pin connected to the led
  Serial.begin(9600); //sets serial port for communication
  delay(10000);
}

void loop() {
  String mes;
  int len;
  off = rate*1/100;
  
  while(Serial.available()) {
    mes = Serial.readString();
    Serial.println(mes);
    len = mes.length();
    char message[len+1];
    mes.toCharArray(message, len+1);
    
    for(int i=0; i<len; i++) {
  
      Serial.println(message[i]);
  
      int binary[] = {0,0,0,0,0,0,0,0};
      int rest = message[i];
      for(int bin = 7; bin > -1; bin--) {
        binary[bin] = rest/weights[bin];
        rest -= weights[bin]*binary[bin];
      }
      for(int h = 0; h < 7; h++){
        if (binary[h] == 0){
          delay1 = rate + off;
        } else if (binary[h] == 1){
          delay1 = rate*2 + off*2;
        } 
       digitalWrite(10, HIGH);
       delay(delay1);
       digitalWrite(10, LOW);
       delay(rate);
     }
    }
  }
}
