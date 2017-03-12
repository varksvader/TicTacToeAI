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
const int buzzerPin=A0;

boolean counter = true; //true --> blue turn
                 //false --> red turn

void setup() 
{
  // put your setup code here, to run once:
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
  pinMode(buzzerPin, OUTPUT);
  reset();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  button1();  
  button2();
  button3();
  button4();
  button5();
  button6();
  button7();
  button8();
  button9();
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
  if((bitRead(data1, 1) == 0) && (bitRead(data1, 2) == 0))
  {
    shiftWrite1(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  /**
  if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, LOW);
    shiftWrite1(1, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(1, HIGH);    
    delay(100);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
  }
  
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data2, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data2, 1)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data2, 1)==1)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data2, 2)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data2, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data2, 2)==1)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  **/
}

void button1Blue()
{
  if ((bitRead(data1, 1) == 0) && (bitRead(data1, 2) == 0))
  {
    shiftWrite1(2, HIGH);
    shiftWrite1(1, LOW);
  }
  /**
  if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==0)&&(bitRead(data1, 1)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(2, LOW);
    shiftWrite1(2, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 2)==0)&&(bitRead(data1, 1)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==1)&&(bitRead(data1, 1)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(2, HIGH);    
    delay(100);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 2)==1)&&(bitRead(data1, 1)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
  }
  
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==1)&&(bitRead(data1, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==0)&&(bitRead(data1, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==1)&&(bitRead(data1, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data2, 2)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data2, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data2, 2)==1)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data2, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data2, 1)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data2, 1)==1)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  **/
}

void button2Red()
{
  if((bitRead(data1, 3) == 0) && (bitRead(data1, 4) == 0))
  {
    shiftWrite1(3, HIGH);
    shiftWrite1(4, LOW);
  }
  /**
 if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, LOW);
    shiftWrite1(3, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(3, HIGH);    
    delay(100);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
  }

  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data2, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data2, 3)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data2, 3)==1)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data2, 4)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data2, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data2, 4)==1)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  **/
}

void button2Blue()
{
  if((bitRead(data1, 3) == 0) && (bitRead(data1, 4) == 0))
  {
    shiftWrite1(4, HIGH);
    shiftWrite1(3, LOW);
  }
  /**
 if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(4, LOW);
    shiftWrite1(4, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(4, HIGH);    
    delay(100);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
  }

  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data2, 4)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data2, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data2, 4)==1)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data2, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data2, 3)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data2, 3)==1)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  **/
}

void button3Red()
{
  if((bitRead(data1, 5) == 0) && (bitRead(data1, 6) == 0))
  {
    shiftWrite1(5, HIGH);
    shiftWrite1(6, LOW);
  }
  /**
  if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, LOW);
    shiftWrite1(5, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(5, HIGH);    
    delay(100);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
  }

  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data2, 5)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data2, 5)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data2, 5)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data2, 6)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  **/
}

void button3Blue()
{
  if((bitRead(data1, 5) == 0) && (bitRead(data1, 6) == 0))
  {
    shiftWrite1(6, HIGH);
    shiftWrite1(5, LOW);
  }
  /**
  if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(6, LOW);
    shiftWrite1(6, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(6, HIGH);    
    delay(100);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
  }

  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data2, 6)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data2, 6)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data2, 5)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data2, 5)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  **/
}

void button4Red()
{
  if((bitRead(data2, 1) == 0) && (bitRead(data2, 2) == 0))
  {
    shiftWrite2(1, HIGH);
    shiftWrite2(2, LOW);
  }
  /**
  if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, LOW);
    delay(100);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, LOW);    
    delay(100);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
  }

  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, LOW);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, LOW);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, LOW);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  **/
}

void button4Blue()
{
  if((bitRead(data2, 1) == 0) && (bitRead(data2, 2) == 0))
  {
    shiftWrite2(2, HIGH);
    shiftWrite2(1, LOW);
  }
  /**
  if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, LOW);
    delay(100);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, LOW);    
    delay(100);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
  }

  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, LOW);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, LOW);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data3, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, LOW);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, LOW);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data3, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  **/
}

void button5Red()
{
  if((bitRead(data2, 3) == 0) && (bitRead(data2, 4) == 0))
  {
    shiftWrite2(3, HIGH);
    shiftWrite2(4, LOW);
  }
  /**
  if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, LOW);
    delay(100);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, LOW);    
    delay(100);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
  }

  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, LOW);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, LOW);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, LOW);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  **/
}

void button5Blue()
{
  if((bitRead(data2, 3) == 0) && (bitRead(data2, 4) == 0))
  {
    shiftWrite2(4, HIGH);
    shiftWrite2(3, LOW);
  }
  /**
  if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, LOW);
    delay(100);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, LOW);    
    delay(100);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
  }

  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, LOW);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, LOW);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data3, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, LOW);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, LOW);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data3, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  **/
}

void button6Red()
{
  if((bitRead(data2, 5) == 0) && (bitRead(data2, 6) == 0))
  {
    shiftWrite2(5, HIGH);
    shiftWrite2(6, LOW);
  }
  /**
  if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, LOW);
    delay(100);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, LOW);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
  }

  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, LOW);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, LOW);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, LOW);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  **/
}

void button6Blue()
{
  if((bitRead(data2, 5) == 0) && (bitRead(data2, 6) == 0))
  {
    shiftWrite2(6, HIGH);
    shiftWrite2(5, LOW);
  }
  /**
  if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, LOW);
    delay(100);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, LOW);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
  }

  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, LOW);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, LOW);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, LOW);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, LOW);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  **/
}

void button7Red()
{
  if((bitRead(data3, 1) == 0) && (bitRead(data3, 2) == 0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite3(2, LOW);
  }
  /**
  if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(1, LOW);
    delay(100);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, LOW);    
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
  }

  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, LOW);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 2)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, LOW);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 2)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, LOW);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==0))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==1))
  {
    shiftWrite3(1, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  **/
}

void button7Blue()
{
  if((bitRead(data3, 1) == 0) && (bitRead(data3, 2) == 0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite3(1, LOW);
  }
  /**
  if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(2, LOW);
    delay(100);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 2)==0)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, LOW);    
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 2)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(2, HIGH);
  }

  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==0)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, LOW);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 1)==1)&&(bitRead(data3, 2)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, LOW);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 2)==0)&&(bitRead(data2, 1)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, LOW);
  }
  else if((bitRead(data1, 2)==1)&&(bitRead(data2, 1)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(1, HIGH);
    shiftWrite1(2, HIGH);
  }
  else if((bitRead(data1, 1)==0)&&(bitRead(data2, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, LOW);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 2)==0))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, LOW);
    shiftWrite1(1, HIGH);
  }
  else if((bitRead(data1, 1)==1)&&(bitRead(data2, 2)==1))
  {
    shiftWrite3(2, HIGH);
    shiftWrite2(2, HIGH);
    shiftWrite1(1, HIGH);
  }
  **/
}

void button8Red()
{
  if((bitRead(data3, 3) == 0) && (bitRead(data3, 4) == 0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite3(4, LOW);
  }
  /**
  if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(3, LOW);
    delay(100);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(3, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, LOW);    
    delay(100);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
  }

  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, LOW);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, LOW);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 4)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 4)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, LOW);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==0))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==1))
  {
    shiftWrite3(3, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  **/
}

void button8Blue()
{
  if((bitRead(data3, 3) == 0) && (bitRead(data3, 4) == 0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite3(3, LOW);
  }
  /**
  if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(4, LOW);
    delay(100);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 4)==0)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(4, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, LOW);    
    delay(100);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 4)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(4, HIGH);
  }

  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==0)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, LOW);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 3)==1)&&(bitRead(data3, 4)==0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 4)==0)&&(bitRead(data2, 3)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, LOW);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, LOW);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 4)==1)&&(bitRead(data2, 3)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(3, HIGH);
    shiftWrite1(4, HIGH);
  }
  else if((bitRead(data1, 3)==0)&&(bitRead(data2, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, LOW);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 4)==0))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, LOW);
    shiftWrite1(3, HIGH);
  }
  else if((bitRead(data1, 3)==1)&&(bitRead(data2, 4)==1))
  {
    shiftWrite3(4, HIGH);
    shiftWrite2(4, HIGH);
    shiftWrite1(3, HIGH);
  }
  **/
}

void button9Red()
{
  if((bitRead(data3, 5) == 0) && (bitRead(data3, 6) == 0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite3(6, LOW);
  }
  /**
  if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(5, LOW);
    delay(100);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(5, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, LOW);    
    delay(100);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
  }

  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, LOW);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, LOW);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 6)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 6)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, LOW);
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==0))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data2, 6)==1)&&(bitRead(data3, 5)==1))
  {
    shiftWrite3(5, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  **/
}

void button9Blue()
{
  if((bitRead(data3, 5) == 0) && (bitRead(data3, 6) == 0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite3(5, LOW);
  }
  /**
  if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(6, LOW);
    delay(100);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 6)==0)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(6, HIGH);
    delay(100);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, LOW);    
    delay(100);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 6)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(6, HIGH);
  }

  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==0)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, LOW);
  }
  else if((bitRead(data1, 5)==1)&&(bitRead(data2, 5)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data1, 6)==0)&&(bitRead(data2, 5)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, LOW);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 5)==0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, LOW);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 6)==1)&&(bitRead(data2, 5)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(5, HIGH);
    shiftWrite1(6, HIGH);
  }
  else if((bitRead(data1, 5)==0)&&(bitRead(data2, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, LOW);
  }
  else if((bitRead(data2, 5)==1)&&(bitRead(data3, 6)==0))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, LOW);
    shiftWrite1(5, HIGH);
  }
  else if((bitRead(data2, 5)==1)&&(bitRead(data3, 6)==1))
  {
    shiftWrite3(6, HIGH);
    shiftWrite2(6, HIGH);
    shiftWrite1(5, HIGH);
  }
  **/
}

void button1()
{
  int button1State;
  button1State=digitalRead(button1Pin);
  if(counter==true)
  {
    if(button1State==LOW)
    {
      button1Blue();
      counter = false;
    }
  }
  else if(counter==false)
  {
    if(button1State==LOW)
    {
      button1Red();
      counter = true;
    }
  }
}

void button2()
{
  int button2State;
  button2State=digitalRead(button2Pin);
  if(counter==true)
  {
    if(button2State==LOW)
    {
      button2Blue();
      counter = false;
    }
  }
  else if(counter = false)
  {
    if(button2State==LOW)
    {
      button2Red();
      counter = true;
    }
  }
}

void button3()
{
  int button3State;
  button3State=digitalRead(button3Pin);
  if(counter==true)
  {
    if(button3State==LOW)
    {
      button3Blue();
      counter = false;
    }
  }
  else if(counter==false)
  {
    if(button3State==LOW)
    {
      button3Red();
      counter = true;
    }
  }
}

void button4()
{
  int button4State;
  button4State=digitalRead(button4Pin);
  if(counter == true)
  {
    if(button4State==LOW)
    {
      button4Blue();
      counter = false;
    }
  }
  else if(counter == false)
  {
    if(button4State==LOW)
    {
      button4Red();
      counter = true;
    }
  }
}

void button5()
{
  int button5State;
  button5State=digitalRead(button5Pin);
  if(counter==true)
  {
    if(button5State==LOW)
    {
      button5Blue();
      counter = false;
    }
  }
  else if(counter==false)
  {
    if(button5State==LOW)
    {
      button5Red();
      counter = true;
    }
  }
}

void button6()
{
  int button6State;
  button6State=digitalRead(button6Pin);
  if(counter==true)
  {
    if(button6State==LOW)
    {
      button6Blue();
      counter=false;
    }
  }
  else if(counter==false)
  {
    if(button6State==LOW)
    {
      button6Red();
      counter=true;
    }
  }
}

void button7()
{
  int button7State;
  button7State=digitalRead(button7Pin);
  if(counter==true)
  {
    if(button7State==LOW)
    {
      button7Blue();
      counter=false;
    }
  }
  else if(counter==false)
  {
    if(button7State==LOW)
    {
      button7Red();
      counter=true;
    }
  }
}

void button8()
{
  int button8State;
  button8State=digitalRead(button8Pin);
  if(counter==true)
  {
    if(button8State==LOW)
    {
      button8Blue();
      counter=false;
    }
  }
  else if(counter==false)
  {
    if(button8State==LOW)
    {
      button8Red();
      counter=true;
    }
  }
}

void button9()
{
  int button9State;
  button9State=digitalRead(button9Pin);
  if(counter==true)
  {
    if(button9State==LOW)
    {
      button9Blue();
      counter=false;
    }
  }
  else if(counter==false)
  {
    if(button9State==LOW)
    {
      button9Red();
      counter=true;
    }
  }
}
