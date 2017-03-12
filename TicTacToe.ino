int datapin = 2; 
int clockpin = 3;
int latchpin = 4;
byte data1 = 0;
byte data2=0;
byte data3=0;
const int button1Pin=5;
const int button2Pin=6;
const int button3Pin=7;
const int button4Pin=8;
const int button5Pin=9;
const int button6Pin=10;
const int button7Pin=11;
const int button8Pin=12;
const int button9Pin=13;
boolean computerPlay=true;

void setup() 
{
  pinMode(datapin, OUTPUT);  
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  pinMode(button6Pin, INPUT);
  pinMode(button7Pin, INPUT);
  pinMode(button8Pin, INPUT);
  pinMode(button9Pin, INPUT);
  reset();
  randomSeed(analogRead(0));
}

void loop() 
{
  randomCorner();//  start the game with the computer chosing a random corner
  button1();  //checks if button 1 is pushed, and turns the corresponding led to red if it's pushed.  
  button2();
  button3();
  button4();
  button5();
  button6();
  button7();
  button8();
  button9();
  oppositeCorner(); //puts blue LED light in the opposite corner, unless the player chose it (red).  
  //if the player chose it, then it will select randomly from the remaining unchosen corners.
  fillIn();
}

void shiftWrite3(int desiredPin, boolean desiredState) 
{
  bitWrite(data3,desiredPin,desiredState);
  shiftOut(datapin, clockpin, MSBFIRST, data3);
  shiftOut(datapin, clockpin, MSBFIRST, data2);
  shiftOut(datapin, clockpin, MSBFIRST, data1);
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}

void shiftWrite2(int desiredPin, boolean desiredState) 
{
  bitWrite(data2,desiredPin,desiredState);
  shiftOut(datapin, clockpin, MSBFIRST, data3);
  shiftOut(datapin, clockpin, MSBFIRST, data2);
  shiftOut(datapin, clockpin, MSBFIRST, data1);
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}

void shiftWrite1(int desiredPin, boolean desiredState) 
{   
  bitWrite(data1,desiredPin,desiredState);
  shiftOut(datapin, clockpin, MSBFIRST, data3);
  shiftOut(datapin, clockpin, MSBFIRST, data2);
  shiftOut(datapin, clockpin, MSBFIRST, data1);
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}

void reset()
{
  shiftWrite3(0, LOW);
  shiftWrite2(0, LOW);
  shiftWrite1(0, LOW);
}

void button1Red()
{
  if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, LOW);
    shiftWrite1(1, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(1, HIGH);    
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 1)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 1)==1)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 2)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 2)==1)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
}

void button2Red()
{
 if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, LOW);
    shiftWrite1(3, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(3, HIGH);    
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }

  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 3)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 3)==1)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 4)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 4)==1)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
}

void button3Red()
{
  if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, LOW);
    shiftWrite1(5, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(5, HIGH);    
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }

  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 5)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 5)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 5)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 6)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
}

void button4Red()
{
  if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, LOW);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, LOW);    
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }

  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
    computerPlay=true;
  }
}

void button5Red()
{
  if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, LOW);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, LOW);    
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }

  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
    computerPlay=true;
  }
}

void button6Red()
{
  if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, LOW);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, LOW);    
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }

  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
    computerPlay=true;
  }
}

void button7Red()
{
  if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(1, LOW);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, LOW);    
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }

  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(2, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 2)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 2)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(2, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
    computerPlay=true;
  }
}

void button8Red()
{
  if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(3, LOW);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(3, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, LOW);    
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }

  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(4, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 4)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 4)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(4, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
    computerPlay=true;
  }
}

void button9Red()
{
  if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    //shiftWrite2(5, LOW);
    //shiftWrite1(5, LOW);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    //shiftWrite2(5, LOW);
    //shiftWrite1(5, HIGH);
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    //shiftWrite2(5, HIGH);
    //shiftWrite1(5, LOW);    
    delay(100);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    //shiftWrite2(5, HIGH);
    //shiftWrite1(5, HIGH);
    computerPlay=true;
  }

  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    //shiftWrite2(6, LOW);
    //shiftWrite1(6, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, LOW);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 6)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 6)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, LOW);
    computerPlay=true;
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(6, HIGH);
    computerPlay=true;
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
    computerPlay=true;
  }
}

void randomCorner()
{
  if(computerPlay==true)
  {
    if((bitRead(data1, 2)==0)&&(bitRead(data1, 6)==0)&&(bitRead(data3, 2)==0)&&(bitRead(data3, 6)==0))
    {
      int corner=random(4);
      delay(100);
      if(corner==0)
      { 
        shiftWrite3(2, LOW);
        shiftWrite2(2, LOW);
        shiftWrite1(2, HIGH);
        delay(100);
        computerPlay=false;
      }
      else if(corner==1)
      {
        shiftWrite3(6, LOW);
        shiftWrite2(6, LOW);
        shiftWrite1(6, HIGH);
        delay(100);
        computerPlay=false;
      }
      else if(corner==2)
      {
        shiftWrite3(2, HIGH);
        shiftWrite2(2, LOW);
        shiftWrite1(2, LOW);
        delay(100);
        computerPlay=false;
      }
      else if(corner==3)
      {
        shiftWrite3(6, HIGH);
        shiftWrite2(6, LOW);
        shiftWrite1(6, LOW);
        delay(100);
        computerPlay=false;
      }
    }
    
    else if((bitRead(data1, 2)==1)&&(bitRead(data3, 5)==1)&&(bitRead(data1, 6)==0)&&(bitRead(data3, 2)==0))
    {
      int corner=random(0,2);
      if(corner==0)
      {
        shiftWrite3(2, HIGH);
        shiftWrite2(2, LOW);
        shiftWrite1(2, HIGH);
        computerPlay=false;
      }
      else if(corner==1)
      {
        shiftWrite3(5, HIGH);
        shiftWrite2(6, LOW);
        shiftWrite1(6, HIGH);
        computerPlay=false;
      }
    }
    
    else if((bitRead(data1, 1)==1)&&(bitRead(data3, 6)==1)&&(bitRead(data1, 6)==0)&&(bitRead(data3, 2)==0))
    {
      int corner=random(2);
      if(corner==0)
      {
        shiftWrite3(2, HIGH);
        shiftWrite2(2, LOW);
        shiftWrite1(1, HIGH);
        computerPlay=false;
      }
      if(corner==1)
      {
        shiftWrite3(6, HIGH);
        shiftWrite2(6, LOW);
        shiftWrite1(6, HIGH);
        computerPlay=false;
      }
    }
    else if((bitRead(data1, 5)==1)&&(bitRead(data3, 2)==1)&&(bitRead(data1, 2)==0)&&(bitRead(data3, 6)==0))
    {
      int corner=0;
      if(corner==0)
      {
        shiftWrite3(6, LOW);
        shiftWrite2(2, LOW);
        shiftWrite1(2, HIGH);
        computerPlay=false;
      }
      else if(corner==1)
      {
        shiftWrite3(6, HIGH);
        shiftWrite2(6, LOW);
        shiftWrite1(2, LOW);
        computerPlay=false;
      }
    }
    else if((bitRead(data1, 6)==1)&&(bitRead(data3, 1)==1)&&(bitRead(data1, 2)==0)&&(bitRead(data3, 6)==0))
    {
      int corner=0;;
      if(corner==0)
      {
        shiftWrite3(6, LOW);
        shiftWrite2(2, LOW);
        shiftWrite1(2, HIGH);
        computerPlay=false;
      }
      else if(corner==1)
      {
        shiftWrite3(6, HIGH);
        shiftWrite2(6, LOW);
        shiftWrite1(2, LOW);
        computerPlay=false;
      }
    }
  }
}

void oppositeCorner()
{
  if(computerPlay==true)
  {
    if((bitRead(data1, 2)==1)&&(bitRead(data3, 6)==0)&&(bitRead(data3, 5)==0)) 
    {
      shiftWrite3(6, HIGH);
      shiftWrite2(5, LOW);
      shiftWrite1(5, LOW);
      computerPlay=false;
    }
    /**else if((bitRead(data1, 2)==1)&&(bitRead(data1, 5)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 6)==0))
    {
      shiftWrite3(6, HIGH);
      shiftWrite2(5, LOW);
      shiftWrite1(5, HIGH);
      computerPlay=false;
    }
    else if((bitRead(data1, 2)==1)&&(bitRead(data1, 5)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 6)==0))
    {
      shiftWrite3(6, HIGH);
      shiftWrite2(5, HIGH);
      shiftWrite1(5, LOW);
      computerPlay=false;
    }**/
    else if((bitRead(data1, 2)==1)&&(bitRead(data3, 5)==1)&&(bitRead(data3, 6)==0))
    {
      randomCorner();
      computerPlay=false;
    }
    else if((bitRead(data3, 6)==1)&&(bitRead(data1, 2)==0)&&(bitRead(data1, 1)==0))
    {
      shiftWrite3(1, LOW);
      shiftWrite2(1, LOW);
      shiftWrite1(2, HIGH);
      computerPlay=false;
    }
    /**else if((bitRead(data3, 6)==1)&&(bitRead(data1, 2)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==0))
    {
      shiftWrite3(1, LOW);
      shiftWrite2(1, HIGH);
      shiftWrite1(2, HIGH);
      computerPlay=false;
    }
    else if((bitRead(data3, 6)==1)&&(bitRead(data1, 2)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
    {
      shiftWrite3(1, HIGH);
      shiftWrite2(1, LOW);
      shiftWrite1(2, HIGH);
      computerPlay=false;
    }**/
    else if((bitRead(data3, 6)==1)&&(bitRead(data1, 1)==1)&&(bitRead(data1, 2)==0))
    {
      randomCorner();
      computerPlay=false;
    }
    else if((bitRead(data1, 6)==1)&&(bitRead(data3, 2)==0)&&(bitRead(data3, 1)==0))
    {
      shiftWrite3(2, HIGH);
      //shiftWrite2(1, LOW);
      //shiftWrite1(1, LOW);
      computerPlay=false;
    }
    /**else if((bitRead(data1, 6)==1)&&(bitRead(data1, 1)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 2)==0))
    {
      shiftWrite3(2, HIGH);
      shiftWrite2(1, LOW);
      shiftWrite1(1, HIGH);
      computerPlay=false;
    }
    else if((bitRead(data1, 6)==1)&&(bitRead(data1, 1)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 2)==0))
    {
      shiftWrite3(2, HIGH);
      shiftWrite2(1, HIGH);
      shiftWrite1(1, LOW);
      computerPlay=false;
    }
    else if((bitRead(data1, 6)==1)&&(bitRead(data3, 1)==1)&&(bitRead(data3, 2)==0))
    {
      //randomCorner();
      int newCorner = random(2);
      if(newCorner == 0)
      {
        shiftWrite1(2, HIGH);
        computerPlay = false;
      }
      else if(newCorner == 1);
      {
        shiftWrite3(6, HIGH);
        computerPlay = false;
      }
      computerPlay=false;
    }**/
    else if((bitRead(data3, 2)==1)&&(bitRead(data1, 6)==0)&&(bitRead(data1, 5)==0))
    {
      //shiftWrite3(5, LOW);
      //shiftWrite2(5, LOW);
      shiftWrite1(6, HIGH);
      computerPlay=false;
    }
    /**else if((bitRead(data3, 2)==1)&&(bitRead(data1, 6)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==0))
    {
      shiftWrite3(5, LOW);
      shiftWrite2(5, HIGH);
      shiftWrite1(6, HIGH);
      computerPlay=false;
    }
    else if((bitRead(data3, 2)==1)&&(bitRead(data1, 6)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==1))
    {
      shiftWrite3(5, HIGH);
      shiftWrite2(5, LOW);
      shiftWrite1(6, HIGH);
      computerPlay=false;
    }
    else if((bitRead(data3, 2)==1)&&(bitRead(data1, 5)==1)&&(bitRead(data1, 6)==0))
    {
      //randomCorner();
      int newCorner = random(2);
      if(newCorner == 0)
      {
        shiftWrite1(2, HIGH);
        computerPlay = false;
      }
      else if(newCorner == 1);
      {
        shiftWrite3(6, HIGH);
        computerPlay = false;
      }
    }**/
  }
}

void button1()
{
  int button1State;
  button1State=digitalRead(button1Pin);
  if(button1State==LOW)
  {
    button1Red();
    computerPlay=true;
  }
}

void button2()
{
  int button2State;
  button2State=digitalRead(button2Pin);
  if(button2State==LOW)
  {
    button2Red();
    computerPlay=true;
  }
}

void button3()
{
  int button3State;
  button3State=digitalRead(button3Pin);
  if(button3State==LOW)
  {
    button3Red();
    computerPlay=true;
  }
}

void button4()
{
  int button4State;
  button4State=digitalRead(button4Pin);
  if(button4State==LOW)
  {
    button4Red();
    computerPlay=true;
  }
}

void button5()
{
  int button5State;
  button5State=digitalRead(button5Pin);
  if(button5State==LOW)
  {
    button5Red();
    computerPlay=true;
  }
}

void button6()
{
  int button6State;
  button6State=digitalRead(button6Pin);
  if(button6State==LOW)
  {
    button6Red();
    computerPlay=true;
  }
}

void button7()
{
  int button7State;
  button7State=digitalRead(button7Pin);
  if(button7State==LOW)
  {
    button7Red();
    computerPlay=true;
  }
}

void button8()
{
  int button8State;
  button8State=digitalRead(button8Pin);
  if(button8State==LOW)
  {
    button8Red();
    computerPlay=true;
  }
}

void button9()
{
  int button9State;
  button9State=digitalRead(button9Pin);
  if(button9State==LOW)
  {
    button9Red();
    computerPlay=true;
  }
}


void fillIn()
{
  if (computerPlay==true)
  {
  // blue winning begin
  if ((bitRead(data1, 2)==1) && (bitRead(data2, 2) == 1) && (bitRead(data3, 2) == 0) && (bitRead(data3, 1) == 0)) 
{
  shiftWrite3(2, HIGH);
  computerPlay = false;
}  
else if ((bitRead(data2, 2) == 1) && (bitRead(data3, 2) == 1) && (bitRead(data1, 2) == 0) && (bitRead(data1, 1) == 0))
{
  shiftWrite1(2, HIGH);
  computerPlay = false;
}
else if ((bitRead(data1, 2) == 1) && (bitRead(data3, 2) == 1) && (bitRead(data2, 2) == 0) && (bitRead(data2, 1) == 0))
{
  shiftWrite2(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 4) == 1) && (bitRead(data2, 4) == 1) && (bitRead(data3, 4) == 0) && (bitRead(data3, 3) == 0))
{
  shiftWrite3(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 4) == 1) && (bitRead(data3, 4) == 1) && (bitRead(data1, 4) == 0) && (bitRead(data1, 3) == 0))
{
  shiftWrite1(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 4) == 1) && (bitRead(data3, 4) == 1) && (bitRead(data2, 4) == 0) && (bitRead(data2, 3) == 0))
{
  shiftWrite2(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 6) == 1) && (bitRead(data2, 6) == 1) && (bitRead(data3, 6) == 0) && (bitRead(data3, 5) == 0))
{
  shiftWrite3(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 6) == 1) && (bitRead(data3, 6) == 1) && (bitRead(data1, 6) == 0) && (bitRead(data1, 5) == 0))
{
  shiftWrite1(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 6) == 1) && (bitRead(data3, 6) == 1) && (bitRead(data2, 6) == 0) && (bitRead(data2, 5) == 0))
{
  shiftWrite2(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 2) == 1) && (bitRead(data1, 4) == 1) && (bitRead(data1, 6) == 0) && (bitRead(data1, 5) == 0))
{
  shiftWrite1(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 4) == 1) && (bitRead(data1, 6) == 1) && (bitRead(data1, 2) == 0) && (bitRead(data1, 1) == 0))
{
  shiftWrite1(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 2) == 1) && (bitRead(data1, 6) == 1) && (bitRead(data1, 4) == 0) && (bitRead(data1, 3) == 0))
{
  shiftWrite1(4, HIGH);
  computerPlay = false; 
}

else if ((bitRead(data2, 2) == 1) && (bitRead(data2, 4) == 1) && (bitRead(data2, 6) == 0) && (bitRead(data2, 5) == 0))
{
 shiftWrite2(6, HIGH);
 computerPlay = false;
}

else if ((bitRead(data2, 4) == 1) && (bitRead(data2, 6) == 1) && (bitRead(data2, 2) == 0) && (bitRead(data2, 1) == 0))
{
 shiftWrite2(2, HIGH);
 computerPlay = false;
}

else if ((bitRead(data2, 2) == 1) && (bitRead(data2, 6) == 1) && (bitRead(data2, 4) == 0) && (bitRead(data2, 3) == 0))
{
 shiftWrite2(4, HIGH);
 computerPlay = false;
}

else if ((bitRead(data3, 2) == 1) && (bitRead(data3, 4) == 1) && (bitRead(data3, 6) == 0) && (bitRead(data3, 5) == 0))
{
  shiftWrite3(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data3, 4) == 1) && (bitRead(data3, 6) == 1) && (bitRead(data3, 2) == 0) && (bitRead(data3, 1) == 0))
{
  shiftWrite3(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data3, 2) == 1) && (bitRead(data3, 6) == 1) && (bitRead(data3, 4) == 0) && (bitRead(data3, 3) == 0))
{
  shiftWrite3(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 2) == 1) && (bitRead(data2, 4) == 1) && (bitRead(data3, 6) == 0) && (bitRead(data3, 5) == 0))
{
  shiftWrite3(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 4) == 1) && (bitRead(data3, 6) == 1) && (bitRead(data1, 2) == 0) && (bitRead(data1, 1) == 0 ))
{
  shiftWrite1(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 2) == 1) && (bitRead(data3, 6) == 1) && (bitRead(data2, 4) == 0) && (bitRead(data2, 3) == 0))
{
  shiftWrite2(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 6) == 1) && (bitRead(data2, 4) == 1) && (bitRead(data3, 2) == 0) && (bitRead(data3, 1) == 0))
{
  shiftWrite3(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 4) == 1) && (bitRead(data3, 2) == 1) && (bitRead(data1, 6) == 0) && (bitRead(data1, 5) == 0))
{
  shiftWrite1(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 6) == 1) && (bitRead(data3, 2) == 1) && (bitRead(data2, 4) == 0) && (bitRead(data2, 3) == 0))
{
  shiftWrite2(4, HIGH);
  computerPlay = false;
}

// end blue winning

//bloocking red from winning begin

else if ((bitRead(data1, 1) == 1) && (bitRead(data2, 1) == 1) && (bitRead(data3, 2) == 0) && (bitRead(data3, 1)== 0))
{
  shiftWrite3(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 1) == 1) && (bitRead(data3, 1) == 1) && (bitRead(data1, 2) == 0) && (bitRead(data1, 1) == 0))
{
  shiftWrite1(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 1) == 1) && (bitRead(data3, 1) == 1) && (bitRead(data2, 2) == 0) && (bitRead(data2, 1) == 0))
{
  shiftWrite2(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 3) == 1) && (bitRead(data2, 3) == 1) && (bitRead(data3, 4) == 0) && (bitRead(data3, 3) == 0))
{
  shiftWrite3(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 3) == 1) && (bitRead(data3, 3) == 1) && (bitRead(data1, 4) == 0) && (bitRead(data1, 3) == 0))
{
  shiftWrite1(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 3) == 1) && (bitRead(data3, 3) == 1) && (bitRead(data2, 4) == 0) && (bitRead(data2, 3) == 0))
{
  shiftWrite2(4, HIGH);
   computerPlay = false;
}

else if ((bitRead(data1, 5) == 1) && (bitRead(data2, 5) == 1) && (bitRead(data3, 6) == 0) && (bitRead(data3, 5) == 0))
{
  shiftWrite3(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 5) == 1) && (bitRead(data3, 5) == 1) && (bitRead(data1, 6) == 0) && (bitRead(data1, 5) == 0))
{
  shiftWrite1(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 5) == 1) && (bitRead(data3, 5) == 1) && (bitRead(data2, 6) == 0) && (bitRead(data2, 5) == 0))
{
  shiftWrite2(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 1) == 1) && (bitRead(data1, 3) == 1) && (bitRead(data1, 6) == 0) && (bitRead(data1, 5) == 0))
{
  shiftWrite1(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 3) == 1) && (bitRead(data1, 5) == 1) && (bitRead(data1, 2) == 0) && (bitRead(data1, 1) == 0))
{
 shiftWrite1(2, HIGH);
 computerPlay = false; 
}

else if ((bitRead(data1, 1) == 1) && (bitRead(data1, 5) == 1) && (bitRead(data1, 4) == 0) && (bitRead(data1, 4) == 0))
{
  shiftWrite1(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 1) == 1) && (bitRead(data2, 3) == 1) && (bitRead(data2, 6) == 0) && (bitRead(data2, 5) == 0))
{
 shiftWrite2(6, HIGH);
 computerPlay = false;
}

else if ((bitRead(data2, 3) == 1) && (bitRead(data2, 5) == 1) && (bitRead(data2, 2) == 0) && (bitRead(data2, 1) == 0))
{
  shiftWrite2(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 1) == 1) && (bitRead(data2, 5) == 1) && (bitRead(data2, 4) == 0) && (bitRead(data2, 3) == 0))
{
  shiftWrite2(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data3, 1) == 1) && (bitRead(data3, 3) == 1) && (bitRead(data3, 6) == 0) && (bitRead(data3, 5) == 0))
{
  shiftWrite3(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data3, 3) == 1) && (bitRead(data3, 5) == 1) && (bitRead(data3, 2) == 0) && (bitRead(data3, 1) == 0))
{
  shiftWrite3(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data3, 1) == 1) && (bitRead(data3, 5) == 1) && (bitRead(data3, 4) == 0) && (bitRead(data3, 3) == 0))
{
  shiftWrite3(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 1) == 1) && (bitRead(data2, 3) == 1) && (bitRead(data3, 6) == 0) && (bitRead(data3, 5) == 0))
{
  shiftWrite3(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 3) == 1) && (bitRead(data3, 5) == 1) && (bitRead(data1, 2) == 0) && (bitRead(data1, 1) == 0))
{
  shiftWrite1(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 1) == 1) && (bitRead(data3, 5) == 1) && (bitRead(data2, 4) == 0) && (bitRead(data2, 3) == 0))
{
  shiftWrite2(4, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 5) == 1) && (bitRead(data2, 3) == 1) && (bitRead(data3, 2) == 0) && (bitRead(data3, 1) == 0))
{
  shiftWrite3(2, HIGH);
  computerPlay = false;
}

else if ((bitRead(data2, 3) == 1) && (bitRead(data3, 1) == 1) && (bitRead(data1, 6) == 0) && (bitRead(data1, 5) == 0))
{
  shiftWrite1(6, HIGH);
  computerPlay = false;
}

else if ((bitRead(data1, 5) == 1) && (bitRead(data3, 1) == 1) && (bitRead(data2, 4) == 0) && (bitRead(data2, 3) == 0))
{
  shiftWrite2(4, HIGH);
  computerPlay = false;
}
//end blocking red from winning
}
}
