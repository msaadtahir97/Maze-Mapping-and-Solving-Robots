int motorPin_1 = 8;   //pin numbers for right motor
int motorPin_2 = 9;
int motorPin_3 = 10;   //pin numbers for left motor
int motorPin_4 = 11;
unsigned long encoderM1=0;
unsigned long encoderM2=0;
void count(void); // code for counting the increasing values of encoder ticks void setup()
void countM2(void);
void low(void);
void move_left(void);
void move_forward(void);
void move_right(void);
void move_uturn(void);

void setup()
{
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),count,FALLING);
  attachInterrupt(digitalPinToInterrupt(3),countM2,RISING);
  pinMode(motorPin_1,OUTPUT);
  pinMode(motorPin_2,OUTPUT);
  pinMode(motorPin_3,OUTPUT);
  pinMode(motorPin_4,OUTPUT);
 }

void loop()
{
  move_left();
  delay(1000);
}

// DEFINATION OF FUNCTIONS USED ABOVE
void count()

{

encoderM1++;


}
void countM2()
{ 
  encoderM2++;
 
 }

 
void low()
{
  analogWrite(motorPin_1,0);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,0);
  analogWrite(motorPin_4,0);
  delay(1000);
  encoderM1=0;
  encoderM2=0;
  }
void move_forward()       //for forward movement
{
  encoderM1=0;
  encoderM2=0;
  int e=0;
  unsigned long x=0;
  unsigned long y=0;
  x=encoderM1;
  y=encoderM2;
  int slavepower=120;
  int masterpower=123;
  while ((x+2050)>encoderM1 && (y+2050)>encoderM2)
{ 
  analogWrite(motorPin_1,slavepower);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,masterpower);
  analogWrite(motorPin_4,0);
  e=0;
  e=encoderM1-encoderM2;
  Serial.print("Error;");
  Serial.print(e);
  Serial.print('\n');
  slavepower=slavepower+(0.2*e);
  slavepower=constrain(slavepower,0,255);
  masterpower=masterpower-(0.2*e);
  masterpower=constrain(masterpower,0,255);
  Serial.print("Slavepower;");
  Serial.print(slavepower);
  Serial.print('\n');
  Serial.print("masterpower;");
  Serial.print(masterpower);
  Serial.print('\n');
  masterpower=123;
  slavepower=120; 

}
  
low();

}
void move_left()    //code for left rotation 90
{
  encoderM1=0;
  encoderM2=0;
  int e=0;
  unsigned long x=0;
  unsigned long y=0;
  x=encoderM1;
  y=encoderM2;
  int slavepower=120;
  int masterpower=120;
  while ((x+820)>encoderM1)
{ analogWrite(motorPin_1,slavepower);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,0);
  analogWrite(motorPin_4,masterpower);
 }
  analogWrite(motorPin_1,0);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,0);
  analogWrite(motorPin_4,0);
  delay(1000);
  encoderM1=0;
  encoderM2=0;
  x=encoderM1;
  y=encoderM2;
  e=x-y;
  slavepower=120;
  masterpower=123;
   while ((x+2050)>encoderM1 && (y+2050)>encoderM2)
{ analogWrite(motorPin_1,slavepower);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,masterpower);
  analogWrite(motorPin_4,0);
  e=0;
  e=encoderM1-encoderM2;
  slavepower=slavepower+(0.2*e);
  slavepower=constrain(slavepower,0,255);
  masterpower=masterpower-(0.2*e);
  masterpower=constrain(masterpower,0,255);
  masterpower=123;
  slavepower=120; 
}
 low();
}
void move_right()    //code for left rotation 90
{
  encoderM1=0;
  encoderM2=0;
  int e=0;
  unsigned long x=0;
  unsigned long y=0;
  x=encoderM1;
  y=encoderM2;
  int slavepower=120;
  int masterpower=123;
  while ((x+835)>encoderM1)
{ analogWrite(motorPin_1,0);
  analogWrite(motorPin_2,slavepower);
  analogWrite(motorPin_3,masterpower);
  analogWrite(motorPin_4,0);
 }
  analogWrite(motorPin_1,0);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,0);
  analogWrite(motorPin_4,0);
  delay(1000);
  encoderM1=0;
  encoderM2=0;
  x=encoderM1;
  y=encoderM2;
  e=x-y;
  slavepower=120;
  masterpower=123;
   while ((x+2050)>encoderM1 && (y+2050)>encoderM2)
{ analogWrite(motorPin_1,slavepower);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,masterpower);
  analogWrite(motorPin_4,0);
  e=0;
  e=encoderM1-encoderM2;
  slavepower=slavepower+(0.2*e);
  slavepower=constrain(slavepower,0,255);
  masterpower=masterpower-(0.2*e);
  masterpower=constrain(masterpower,0,255);
  masterpower=123;
  slavepower=120; 
}
 low();
}
void move_uturn()
{
  encoderM1=0;
  encoderM2=0;
  int e=0;
  unsigned long x=0;
  unsigned long y=0;
  x=encoderM1;
  y=encoderM2;
  int slavepower=120;
  int masterpower=120;
  while ((x+835)>encoderM1)
{ analogWrite(motorPin_1,slavepower);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,0);
  analogWrite(motorPin_4,masterpower);
 }
  analogWrite(motorPin_1,0);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,0);
  analogWrite(motorPin_4,0);
  delay(1000);
  encoderM1=0;
  encoderM2=0;
  x=encoderM1;
  y=encoderM2;
  e=x-y;
  slavepower=120;
  masterpower=120;
  while ((x+835)>encoderM1)
{ analogWrite(motorPin_1,slavepower);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,0);
  analogWrite(motorPin_4,masterpower);
 }
  analogWrite(motorPin_1,0);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,0);
  analogWrite(motorPin_4,0);
  delay(1000);
  encoderM1=0;
  encoderM2=0;
  x=encoderM1;
  y=encoderM2;
  e=x-y;
  slavepower=120;
  masterpower=123;
  while ((x+2050)>encoderM1 && (y+2050)>encoderM2)
{ analogWrite(motorPin_1,slavepower);
  analogWrite(motorPin_2,0);
  analogWrite(motorPin_3,masterpower);
  analogWrite(motorPin_4,0);
  e=0;
  e=encoderM1-encoderM2;
  slavepower=slavepower+(0.2*e);
  slavepower=constrain(slavepower,0,255);
  masterpower=masterpower-(0.2*e);
  masterpower=constrain(masterpower,0,255);
  masterpower=123;
  slavepower=120; 
}
 low();
  }

