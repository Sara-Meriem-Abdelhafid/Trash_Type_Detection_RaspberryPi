// Motor A connection 
//#define ENA 8
int in1 = 8;
int in2 = 9;
//int in1 = 8;
//int in2 = 9;

//int run = 0;
//int MAX = 10;

void setup() {
  // put your setup code here, to run once:
  //pinMode(ENA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600); // Set the baud rate to match the Raspberry Pi
  
  // Turn the Motor OFF 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  //Serial.write("Inter MAX SPEED Val:\n ");
  //MAX =  Serial.parseInt(); // Read the integer from Serial input
  //speedControl(MAX);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  /*if(run == 1){
    stop();
  }*/
  //else {
    //digitalWrite(ENA, MAX);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);


    //Serial.write("Inter MAX SPEED Val:\n ");
    //MAX =  Serial.parseInt(); // Read the integer from Serial input

    //directionControl();
    //delay(1000);
    //speedControl(MAX);
    delay(1000);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    //digitalWrite(in1, LOW);
    //digitalWrite(in2, LOW);

    //Serial.write("Enter 0 if you Want to 0 \n ");
    //run =  Serial.parseInt(); // Read the integer from Serial input
    //Serial.write("run \n");

  //}
}
/*
void directionControl(){
  //set Motor to max speed
  digitalWrite(ENA, MAX);

  //turn the motor ON LEFT
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000);


  //turn the motor ON RIGHT
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(2000);

  // Turn the Motor OFF Again 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

}
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void speedControl(int speed){
  //turn motor A ON
  digitalWrite(ENA, speed);
  
  //digitalWrite(in1, LOW);
  //digitalWrite(in2, HIGH);
  

  /*
  //Accelerate from 0 to MAX speed
  for(int i = 0; i <= MAX ;i++){
      digitalWrite(enA, i);
      delay(100);
  }

  //Decelerate from MAX to 0 speed
  for(int i = MAX; i >= 0 ;i--){
      digitalWrite(enA, i);
      delay(100);
  }

  // Turn the Motor OFF Again 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);* /
  }*/
