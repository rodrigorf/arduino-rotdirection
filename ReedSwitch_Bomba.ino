const int switchPin = 2; // // Reed switch to digital pin 2
const int switchPin12 = 12;
const int switchPin8 = 8;
int ledPin4= 4; // // LED is on digital pin 13
int ledPin13= 13; // // LED is on digital pin 13
int buzPin9= 9; // // LED is on digital pin 13
int state = HIGH; // the current state of the output pin
int readSensor1, readSensor2, readSensor3; 
String leitura, anterior;
int direcao;

void setup() 
{
  pinMode(switchPin, INPUT); 
  pinMode(switchPin12, INPUT); 
  pinMode(switchPin8, INPUT); 
  pinMode (ledPin4, OUTPUT); 
  pinMode (ledPin13, OUTPUT);
  pinMode (buzPin9, OUTPUT);
  digitalWrite(switchPin, HIGH); 
  digitalWrite(switchPin12, HIGH); 
  digitalWrite(switchPin8, HIGH); 
  Serial.begin(9600);
  leitura = "";
  anterior = "4";
}

void loop() 
{
    readSensor1 = digitalRead(switchPin);
    readSensor2 = digitalRead(switchPin12);
    readSensor3 = digitalRead(switchPin8);
    
    if(readSensor1 == LOW && leitura.indexOf("1") == -1){
      leitura += "1";
    }
    if(readSensor2 == LOW && leitura.indexOf("2") == -1){
      leitura += "2";
    }
    if(readSensor3 == LOW && leitura.indexOf("3") == -1){
      leitura += "3";
    }
    
   if(leitura.length() == 3)
   {      
      if (leitura == "123" || leitura == "231" || leitura == "312") 
      {
        Serial.println(leitura + " - HORA");
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin13, HIGH);
        analogWrite(9, 0);
      }
      else 
      {
        Serial.println(leitura + " - ANTI");
        digitalWrite(ledPin4, HIGH);
        digitalWrite(ledPin13, LOW);
        analogWrite(9,200);
      }      

      leitura="";
      Serial.flush();
    }    
}
