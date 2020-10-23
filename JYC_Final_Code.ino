int r=0;
int motorPin_1 = 8;   //pin numbers for right motor
int motorPin_2 = 9;
int motorPin_3 = 10;   //pin numbers for left motor
int motorPin_4 = 11;
unsigned long encoderM1 = 0;
unsigned long encoderM2 = 0;
  void transferm(void);
int maze5[25];
int mazeex[5][5];
int mazedef[5][5];
int l9=0;
int snd=0;
int r9=0;
int u9=0;
int m=0;
int s9=0;
int e9=0;
int w9=0;
int n9=0;
int west=0;
int north=0;
int south=0;
int east=0;
int forwardcall = 0;
int uturncall = 0;
int leftcall = 0;
int rightcall = 0;
int startrow=0;
int startcol=0;
int startnum=0;
void printllxll(void);
const int trigPinS1 = 44;
const int echoPinS1 = 45;
const int trigPinS2 = 46;
const int echoPinS2 = 47;
const int trigPinS3 = 48;
const int echoPinS3 = 49;
const int trigPinS4 = 42;
const int echoPinS4 = 43;
const int trigPinS5 = 52;
const int echoPinS5 = 53;
const int trigPinS6 = 40;
const int echoPinS6 = 41;
// defines variables
long durationS1;
int distanceS1;
long durationS2;
int distanceS2;
long durationS3;
int distanceS3;
long durationS4;
int distanceS4;
long durationS5;
int distanceS5;
long durationS6;
int distanceS6;
int WOL;
int WOR;
int WOF;
int WOB;
int maze9[9][9];
int f9 = 0;
int rev9 = 0;
int right9 = 0;
int left9 = 0;
int row9=4;
int col9=4;
int val9 = 1;
int a=0;
int f=0;
int v9=1;
int z=0;
int maze11[11][11];
void count(void); // code for counting the increasing values of encoder ticks void setup()
void countM2(void);
void extract5(void);
void mazep(void);
void print11x11(void);
void twoarray(void);
void setm(void);
void buildfinalmaze(void);
void build24(void);
void direct(void);
void setmaze9(void);
void printmze24(void);
void buildmaze9(void);
void checkwall(void);
void proceed(void);
void startingpoint(void);
void low(void);
void move_left(void);
void move_forward(void);
void move_right(void);
void move_uturn(void);
void printmaze9(void);
 int maze24[25][4];
void setup()
{
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), count, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), countM2, RISING);
  pinMode(motorPin_1, OUTPUT);
  pinMode(motorPin_2, OUTPUT);
  pinMode(motorPin_3, OUTPUT);
  pinMode(motorPin_4, OUTPUT);
  pinMode(trigPinS1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinS1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPinS2, OUTPUT);
  pinMode(echoPinS2, INPUT);
  pinMode(trigPinS3, OUTPUT);
  pinMode(echoPinS3, INPUT);
  pinMode(trigPinS4, OUTPUT);
  pinMode(echoPinS4, INPUT);
  pinMode(trigPinS5, OUTPUT);
  pinMode(echoPinS5, INPUT);
  pinMode(trigPinS6, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinS6, INPUT);
  delay(1000);
  while (r<45)
  {
  setmaze9();
  maze9[row9][col9] = val9;
  //printmaze9();
  //Serial.print('\n');
  //Serial.print("movement start");
  //Serial.print('\n');
  
    sonar();
    checkwall();
    build24();
    printmaze24();
    proceed();
    Serial.print('\n');
    printmaze9();
    Serial.print('\n');
    Serial.print("=======");
   Serial.print(row9);
    Serial.print(col9);
    Serial.print("======");
    Serial.print('\n');
    Serial.print("leftcall:");
    Serial.print(leftcall);
    Serial.print('\n');
    Serial.print("forwardcall:");
    Serial.print(forwardcall);
    Serial.print('\n');
    Serial.print("rightcall:");
    Serial.print(rightcall);
    Serial.print('\n');
    Serial.print("uturncall:");
    Serial.print(uturncall);
      Serial.print('\n');
    Serial.print("value of m");
     Serial.print(m);
      direct();
      buildmaze9();
      setm();
     r=r+1;
    Serial.print('\n');
  }
   extract5();
   twoarray();
   mazep();
   printmaze24();
   buildfinalmaze();
   print11x11();     
   startingpoint();
   Serial.print("startnum:");
   Serial.print(startnum);
   Serial.print('\n');

}


void transferm()
{
  Serial.write(snd);
  delay(1000);
  Serial.write(startnum);
  delay(1000);
  for (int i = 0; i < 11; i++)
  {
    for (int j = 0; j < 11; j++)
     { Serial.write(maze11[i][j]);
      Serial.write("  ");}
    Serial.write("    ");
  }
  
}

void loop()
{
 
    
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

void proceed()                        //movement pirority
{
 if (m==0)
  {if (WOL == 0 && maze9[row9][col9 - 1] == 0)
    move_left();
  else {
    if (WOF == 0 && maze9[row9 - 1][col9] == 0)
      move_forward();
    else {
      if (WOR == 0 && maze9[row9][col9 + 1] == 0)
        move_right();
      else {
        if (WOL == 0 && maze9[row9][col9 - 1] != 0)
          move_left();
        else {
          if (WOF == 0 && maze9[row9 - 1][col9] != 0)
            move_forward();
          else {
            if (WOR == 0 && maze9[row9][col9 + 1] != 0)
              move_right();
            else move_uturn();
          }
        }
      }
    }
  }
}
if (m==1)
  {if (WOL == 0 && maze9[row9+1][col9] == 0)
    move_left();
  else {
    if (WOF == 0 && maze9[row9][col9-1] == 0)
      move_forward();
    else {
      if (WOR == 0 && maze9[row9-1][col9] == 0)
        move_right();
      else {
        if (WOL == 0 && maze9[row9+1][col9] != 0)
          move_left();
        else {
          if (WOF == 0 && maze9[row9][col9-1] != 0)
            move_forward();
          else {
            if (WOR == 0 && maze9[row9-1][col9] != 0)
              move_right();
            else move_uturn();
          }
        }
      }
    }
  }
}
if (m==2)
  {if (WOL == 0 && maze9[row9][col9 +1] == 0)
    move_left();
  else {
    if (WOF == 0 && maze9[row9+1][col9] == 0)
      move_forward();
    else {
      if (WOR == 0 && maze9[row9][col9 - 1] == 0)
        move_right();
      else {
        if (WOL == 0 && maze9[row9][col9 + 1] != 0)
          move_left();
        else {
          if (WOF == 0 && maze9[row9 + 1][col9] != 0)
            move_forward();
          else {
            if (WOR == 0 && maze9[row9][col9 - 1] != 0)
              move_right();
            else move_uturn();
          }
        }
      }
    }
  }
}
if (m==3)
  {if (WOL == 0 && maze9[row9-1][col9 ] == 0)
    move_left();
  else {
    if (WOF == 0 && maze9[row9 ][col9+1] == 0)
      move_forward();
    else {
      if (WOR == 0 && maze9[row9+1][col9] == 0)
        move_right();
      else {
        if (WOL == 0 && maze9[row9-1][col9 ] != 0)
          move_left();
        else {
          if (WOF == 0 && maze9[row9 ][col9+1] != 0)
            move_forward();
          else {
            if (WOR == 0 && maze9[row9+1][col9] != 0)
              move_right();
            else move_uturn();
          }
        }
      }
    }
  }
}
}
void direct()
{ 
  if(m==0)
{if(forwardcall>f9) 
  {north=(north+1);
  f9=(f9+1);
  }
  if(rightcall>right9)
  { east=(east+1);
   right9=(right9+1);
    }
    if(leftcall>left9)
  { west=(west+1);
   left9=(left9+1);
    }
     if(uturncall>rev9)
  { south=(south+1);
   rev9=(rev9+1);
    }
  }
  if(m==1)
{if(forwardcall>f9) 
  {west=(west+1);
  f9=(f9+1);
  }
  if(rightcall>right9)
  { north=(north+1);
   right9=(right9+1);
    }
    if(leftcall>left9)
  { south=(south+1);
   left9=(left9+1);
    }
     if(uturncall>rev9)
  { east=(east+1);
   rev9=(rev9+1);
    }
  }
  if(m==2)
{if(forwardcall>f9) 
  {south=(south+1);
  f9=(f9+1);
  }
  if(rightcall>right9)
  { west=(west+1);
   right9=(right9+1);
    }
    if(leftcall>left9)
  { east=(east+1);
   left9=(left9+1);
    }
     if(uturncall>rev9)
  { north=(north+1);
   rev9=(rev9+1);
    }
  }
  if(m==3)
{if(forwardcall>f9) 
  {east=(east+1);
  f9=(f9+1);
  }
  if(rightcall>right9)
  { south=(south+1);
   right9=(right9+1);
    }
    if(leftcall>left9)
  { north=(north+1);
   left9=(left9+1);
    }
     if(uturncall>rev9)
  { west=(west+1);
   rev9=(rev9+1);
    }
  }
}

void buildmaze9()                   //to be called after every movement making 9x9
{

   if (north > n9 && maze9[row9-1][col9]==0)                                          //forwardcall incrimented in forward() loop.
    {
      //Serial.print("looping \n");
      n9=(n9+1);
      val9=(val9+1);
      row9=(row9-1);
      maze9[row9][col9] = val9;
      //Serial.print("loop running \n") ;
      //Serial.print('\n');
      //Serial.print("++++++++");

      //Serial.print(row9);
      //Serial.print(col9);
      //Serial.print("++++++++");
      //Serial.print('\n');
    }
     
   if (north > n9 && maze9[row9-1][col9]!=0)
   {
    n9=(n9+1);
    row9=(row9-1);
    }
   if (south > s9 && maze9[row9+1][col9]==0)
    {
      s9=(s9+1);
      val9=(val9+1);
      row9=(row9+1);
      maze9[row9][col9] = val9;
    }
    
  if (south > s9 && maze9[row9+1][col9]!=0)
   {
    s9=(s9+1);
    row9=(row9+1);
    
    }
   if (east > e9 && maze9[row9][col9+1]==0)
    {
      e9=(e9+1);
      val9=(val9+1);
      col9=(col9+1);
      maze9[row9][col9] = val9;
    }

    if (east > e9 && maze9[row9][col9+1]!=0)
   {
    e9=(e9+1);
    col9=(col9+1);
    
    }
   if (west > w9 && maze9[row9][col9-1]==0)
    {
      w9=(w9+1);
      val9=(val9+1);
      col9=(col9-1);
      maze9[row9][col9] = val9;
      //Serial.print("loop running \n") ;
      //Serial.print('\n');
      //Serial.print("---------");
      //Serial.print(row9);
      //Serial.print(col9);
      //Serial.print("--------");
      //Serial.print('\n');
    }
    if (west > w9 && maze9[row9][col9-1]!=0)
   {
    w9=(w9+1);
    col9=(col9-1);
    
    }
  
}
void setm()
{
  if(leftcall>l9)
   {m=(m+1);
   l9=(l9+1);
  if(m>3)
  {m=0;
    }}
   if(rightcall>r9)
  { m=(m-1);
  r9=(r9+1);
  if (m<0)
  {
    m=3;
    }}
    if(uturncall>u9)
  {  m=(m+2);
     u9=(u9+1);
     if(m==5)
     {m=1;}
   if(m==4)
 { m=0;
  }}
  }

void sonar()
{
  delay(500);
  // Clears the trigPin
  digitalWrite(trigPinS1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinS1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinS1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationS1 = pulseIn(echoPinS1, HIGH);
  // Calculating the distance
  distanceS1 = durationS1 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("DistanceS1: ");
  //Serial.println(distanceS1);
  digitalWrite(trigPinS2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinS2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinS2, LOW);
  durationS2 = pulseIn(echoPinS2, HIGH);
  distanceS2 = durationS2 * 0.034 / 2;
  //Serial.print("DistanceS2: ");
  //Serial.println(distanceS2);
  digitalWrite(trigPinS3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinS3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinS3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationS3 = pulseIn(echoPinS3, HIGH);
  // Calculating the distance
  distanceS3 = durationS3 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("DistanceS3: ");
  //Serial.println(distanceS3);
  digitalWrite(trigPinS4, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinS4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinS4, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationS4 = pulseIn(echoPinS4, HIGH);
  // Calculating the distance
  distanceS4 = durationS4 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("DistanceS4: ");
  //Serial.println(distanceS4);
  digitalWrite(trigPinS5, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinS5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinS5, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationS5 = pulseIn(echoPinS5, HIGH);
  // Calculating the distance
  distanceS5 = durationS5 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("DistanceS5: ");
  //Serial.println(distanceS5);
  // Sonar S6
  digitalWrite(trigPinS6, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinS6, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinS6, LOW);
  durationS6 = pulseIn(echoPinS6, HIGH);
  distanceS6 = durationS6 * 0.034 / 2;
  //Serial.print("DistanceS6: ");
  //Serial.println(distanceS6);
}

void setmaze9()             //to be called once in the starting, making 9x9=0
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
      maze9[i][j] = 0;
  }
}


void printmaze9()             //to be called once in the starting, making 9x9=0
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
     { Serial.print(maze9[i][j]);
      Serial.print('\t');}
    Serial.print('\n');
  }
}
void printmaze24()             //to be called once in the starting, making 9x9=0
{
  for (int i = 0; i < 25; i++)
  {
    for (int j = 0; j < 4; j++)
     { Serial.print(maze24[i][j]);
      Serial.print('\t');}
    Serial.print('\n');
  }
}

void checkwall()                        //to be called before every movement, check walls
{
  if ((distanceS3 >= 1 && distanceS3 <= 20) || (distanceS5 >= 1 && distanceS5 <= 20))
    WOL = 1;
  else WOL = 0;
  if ((distanceS2 >= 1 && distanceS2 <= 20) || (distanceS4 >= 1 && distanceS4 <= 20))
    WOR = 1;
  else WOR = 0;

  if (distanceS1 >= 1 && distanceS1 <= 20)
    WOF = 1;
  else WOF = 0;

  if (distanceS6 >= 1 && distanceS6 <= 20)
    WOB = 1;
  else WOB = 0;

}
void build24()
{
  if (m==0 && val9==v9)
  {
    maze24[val9-1][0]=WOF;
    maze24[val9-1][1]=WOR;
    maze24[val9-1][2]=WOL;
    maze24[val9-1][3]=WOB;
    v9=v9+1;
  }

  if (m==1 && val9==v9)
  {
    maze24[val9-1][0]=WOR;
    maze24[val9-1][1]=WOB;
    maze24[val9-1][2]=WOF;
    maze24[val9-1][3]=WOL;
    v9=v9+1;
  }
  if (m==2  && val9==v9)
  {
    maze24[val9-1][0]=WOB;
    maze24[val9-1][1]=WOL;
    maze24[val9-1][2]=WOR;
    maze24[val9-1][3]=WOF;
    v9=v9+1;
  }
  if (m==3  && val9==v9 )
  {
    maze24[val9-1][0]=WOL;
    maze24[val9-1][1]=WOF;
    maze24[val9-1][2]=WOB;
    maze24[val9-1][3]=WOR;
    v9=v9+1;
  }
  if (WOL==0 && WOR==0 && WOF==0)
  {
    for(int n=0;n<4;n++)
    {
      if (maze24[val9-1][n]==0)
      {
        maze24[val9-1][n]=1;
      }
      if (maze24[val9-1][n]==1)
      {
        maze24[val9-1][n]=0;
      }
    }
    
  }
  }
void startingpoint()
{
  for (int i=0; i<5; i++)
{
  for(int j=0; j<5; j++)
  {
    if(mazeex[i][j]==1);
    {startrow=i;
    startcol=j;}
    }
  }
  int v=0;
  for(int i=0; i<5; i++)
  { for(int j=0; j<5; j++)
     {
      mazedef[i][j]=v;
      v++;
      }
    }
    mazedef[startrow][startcol]=startnum; 
  }

void extract5(void)
{
  for(int i=0; i<9; i++)
  {
    for(int j=0; j<9; j++)
    { if (maze9[i][j]!=0)
    { maze5[z]=maze9[i][j];
      z=z+1;
      }
      }
    }
 }
 void twoarray()
{
  for(int g=0; g<25; g++)
    {Serial.print(maze5[g]);
    }

   
  for(int k=0; k<5; k++)
  {
    for(int d=0; d<5; d++)
    {
      if(maze5[f]!=0)
      {mazeex[k][d]=maze5[f];
      f=f+1;}
      }
    }
  }
  void mazep()
{   Serial.print('\n');
  Serial.print("5x5 Extracted");
  Serial.print('\n');
  for(int q=0; q<5; q++)
  {
    for(int w=0; w<5; w++)
    {
      Serial.print(mazeex[q][w]);
       Serial.print('\t');}
    Serial.print('\n');
      }
    }
void buildfinalmaze()
{
  for(int i=0; i<11; i++)
  {for(int j=0; j<11; j++)
    {
      maze11[i][j]=99;
      }
    }
    for (int i=0, y=1; i<5; i++, y+=2)
    {
      for(int j=0, x=1, block; j<5; j++, x+=2)
      {
        block=mazeex[i][j]-1;
        maze11[y][x]=90;
        maze11[y-1][x]=maze24[block][3];
        maze11[y+1][x]=maze24[block][1];
        maze11[y][x-1]=maze24[block][0];
        maze11[y][x+1]=maze24[block][2];
        }
      }
  }
  void print11x11()
  {
    Serial.print('\n');
    Serial.print('\n');
    for(int i=0; i<11; i++)
    {for(int j=0; j<11; j++)
    {
      Serial.print(maze11[i][j]);
      Serial.print('\t');
      }
      Serial.print('\n');
    }
   }

void low()
{
  analogWrite(motorPin_1, 0);
  analogWrite(motorPin_2, 0);
  analogWrite(motorPin_3, 0);
  analogWrite(motorPin_4, 0);
  delay(1000);
  encoderM1 = 0;
  encoderM2 = 0;
}
void move_forward()       //for forward movement
{
  forwardcall=(forwardcall+1);
  encoderM1 = 0;
  encoderM2 = 0;
  int e = 0;
  unsigned long x = 0;
  unsigned long y = 0;
  x = encoderM1;
  y = encoderM2;
  int slavepower = 120;
  int masterpower = 126;
  while ((x + 2100) > encoderM1 && (y + 2100) > encoderM2)
  {
    analogWrite(motorPin_1, slavepower);
    analogWrite(motorPin_2, 0);
    analogWrite(motorPin_3, masterpower);
    analogWrite(motorPin_4, 0);
    e = 0;
    e = encoderM1 - encoderM2;
    //Serial.print("Error;");
    //Serial.print(e);
    //Serial.print('\n');
    slavepower = slavepower + (0.2 * e);
    slavepower = constrain(slavepower, 0, 255);
    masterpower = masterpower - (0.2 * e);
    masterpower = constrain(masterpower, 0, 255);
    //Serial.print("Slavepower;");
    //Serial.print(slavepower);
    //Serial.print('\n');
    //Serial.print("masterpower;");
    //Serial.print(masterpower);
    //Serial.print('\n');
    masterpower = 126;
    slavepower = 120;

  }
  
  low();

}
void move_left()    //code for left rotation 90
{
 
  encoderM1 = 0;
  encoderM2 = 0;
  int e = 0;
  unsigned long x = 0;
  unsigned long y = 0;
  x = encoderM1;
  y = encoderM2;
  int slavepower = 121;
  int masterpower = 121;
  while ((x + 830) > encoderM1)
  { analogWrite(motorPin_1, slavepower);
    analogWrite(motorPin_2, 0);
    analogWrite(motorPin_3, 0);
    analogWrite(motorPin_4, masterpower);
  }
  analogWrite(motorPin_1, 0);
  analogWrite(motorPin_2, 0);
  analogWrite(motorPin_3, 0);
  analogWrite(motorPin_4, 0);
  delay(1000);
  encoderM1 = 0;
  encoderM2 = 0;
  x = encoderM1;
  y = encoderM2;
  e = x - y;
  slavepower = 120;
  masterpower = 126;
  while ((x + 2100) > encoderM1 && (y + 2100) > encoderM2)
  { analogWrite(motorPin_1, slavepower);
    analogWrite(motorPin_2, 0);
    analogWrite(motorPin_3, masterpower);
    analogWrite(motorPin_4, 0);
    e = 0;
    e = encoderM1 - encoderM2;
    slavepower = slavepower + (0.2 * e);
    slavepower = constrain(slavepower, 0, 255);
    masterpower = masterpower - (0.2 * e);
    masterpower = constrain(masterpower, 0, 255);
    masterpower = 126;
    slavepower = 120;
  }
  leftcall=(leftcall+1);
  low();
}
void move_right()    //code for left rotation 90
{
  
  encoderM1 = 0;
  encoderM2 = 0;
  int e = 0;
  unsigned long x = 0;
  unsigned long y = 0;
  x = encoderM1;
  y = encoderM2;
  int slavepower = 121;
  int masterpower = 121;
  while ((x + 830) > encoderM1)
  { analogWrite(motorPin_1, 0);
    analogWrite(motorPin_2, slavepower);
    analogWrite(motorPin_3, masterpower);
    analogWrite(motorPin_4, 0);
  }
  analogWrite(motorPin_1, 0);
  analogWrite(motorPin_2, 0);
  analogWrite(motorPin_3, 0);
  analogWrite(motorPin_4, 0);
  delay(1000);
  encoderM1 = 0;
  encoderM2 = 0;
  x = encoderM1;
  y = encoderM2;
  e = x - y;
  slavepower = 120;
  masterpower = 126;
  while ((x + 2100) > encoderM1 && (y + 2100) > encoderM2)
  { analogWrite(motorPin_1, slavepower);
    analogWrite(motorPin_2, 0);
    analogWrite(motorPin_3, masterpower);
    analogWrite(motorPin_4, 0);
    e = 0;
    e = encoderM1 - encoderM2;
    slavepower = slavepower + (0.2 * e);
    slavepower = constrain(slavepower, 0, 255);
    masterpower = masterpower - (0.2 * e);
    masterpower = constrain(masterpower, 0, 255);
    masterpower = 126;
    slavepower = 120;
  }
  rightcall=(rightcall+1);
  low();
}

void printllxll()
 {
int MAZE[11][11]={
                  {99,1,99,1,99,1,99,1,99,1,99},
                  {1,90,0,90,0,90,0,90,0,90,1},
                  {99,0,99,0,99,1,99,0,99,1,99},
                  {1,90,0,90,1,90,0,90,1,90,1},
                  {99,1,99,0,99,1,99,0,99,0,99},
                  {0,90,1,90,0,90,0,90,0,90,1},
                  {99,0,99,1,99,0,99,1,99,1,99},
                  {0,90,1,90,0,90,1,90,0,90,0},
                  {99,1,99,0,99,0,99,1,99,1,99},
                  {1,90,0,90,0,90,0,90,0,90,1},
                  {99,1,99,1,99,1,99,1,99,1,99} 
                  };
                  

  
  for(int a=0; a<11;a++)
  {
    for (int b=0;b<11;b++)
    {
      Serial.print(MAZE[a][b]);
      Serial.print("   ");
    }
  Serial.println("");
  
  }
 }


void move_uturn()
{
 
  encoderM1 = 0;
  encoderM2 = 0;
  int e = 0;
  unsigned long x = 0;
  unsigned long y = 0;
  x = encoderM1;
  y = encoderM2;
  int slavepower = 121;
  int masterpower = 121;
  while ((x + 830) > encoderM1)
  { analogWrite(motorPin_1, slavepower);
    analogWrite(motorPin_2, 0);
    analogWrite(motorPin_3, 0);
    analogWrite(motorPin_4, masterpower);
  }
  analogWrite(motorPin_1, 0);
  analogWrite(motorPin_2, 0);
  analogWrite(motorPin_3, 0);
  analogWrite(motorPin_4, 0);
  delay(1000);
  encoderM1 = 0;
  encoderM2 = 0;
  x = encoderM1;
  y = encoderM2;
  e = x - y;
  slavepower = 121;
  masterpower = 121;
  while ((x + 830) > encoderM1)
  { analogWrite(motorPin_1, slavepower);
    analogWrite(motorPin_2, 0);
    analogWrite(motorPin_3, 0);
    analogWrite(motorPin_4, masterpower);
  }
  analogWrite(motorPin_1, 0);
  analogWrite(motorPin_2, 0);
  analogWrite(motorPin_3, 0);
  analogWrite(motorPin_4, 0);
  delay(1000);
  encoderM1 = 0;
  encoderM2 = 0;
  x = encoderM1;
  y = encoderM2;
  e = x - y;
  slavepower = 120;
  masterpower = 126;
  while ((x + 2100) > encoderM1 && (y + 2100) > encoderM2)
  { analogWrite(motorPin_1, slavepower);
    analogWrite(motorPin_2, 0);
    analogWrite(motorPin_3, masterpower);
    analogWrite(motorPin_4, 0);
    e = 0;
    e = encoderM1 - encoderM2;
    slavepower = slavepower + (0.2 * e);
    slavepower = constrain(slavepower, 0, 255);
    masterpower = masterpower - (0.2 * e);
    masterpower = constrain(masterpower, 0, 255);
    masterpower = 126;
    slavepower = 120;
  }
  uturncall=(uturncall+1);
  low();
}


