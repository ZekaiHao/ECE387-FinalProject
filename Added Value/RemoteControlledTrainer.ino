
#include <Wire.h>
#include <UTFT.h>
#include <URTouch.h>

UTFT    myGLCD(CTE32_R2,38,39,40,41);


//
URTouch  myTouch( 6, 5, 4, 3, 2);
char curpage;

extern uint8_t BigFont[];

int x, y;
char stCurrent[20]="";
int stCurrentLen=0;
char stLast[20]="";

int input=0;
boolean s=false;
int up=0;
int down=0;
int left=0;
int right=0;
int level=0;
int thinkTime=5000;
int score = 0;
boolean rst= false;
/*************************
**   Custom functions   **
*************************/





void drawHome()
{
score=0;
// Draw the lower row of buttons
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (110, 180, 190, 200);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (110, 180, 190, 200);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("START", 110, 183);
  myGLCD.setBackColor (0, 0, 0);
  myGLCD.print("Positioning", 70, 30);
  myGLCD.print("Trainer", 90, 50);
}

/*************************
**  Required functions  **
*  

*************************/



void drawPrep()
{
  myGLCD.setBackColor(0, 0, 0);
   myGLCD.print("Be Ready", 70, 30);
   myGLCD.print("Game begins in", 30, 50);

  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (120, 160, 180, 200);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (120, 160, 180, 200);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("3", 145, 173);
}



void drawGame()
{

  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (240, 15, 319, 40);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (240, 15, 319, 40);

  myGLCD.setBackColor(0, 0,255);
  myGLCD.print("EXIT", 245, 20);
  myGLCD.setBackColor(0, 0,0);
  myGLCD.print("Current Score", 45, 45);
  myGLCD.print(String(score), 120, 75);
  int guess=random(1,5);
  
  if(guess==1)
  {
    myGLCD.setColor(0, 255,0);
    myGLCD.fillRoundRect (120, 160, 200, 200);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (120, 160, 200, 200);

  myGLCD.setBackColor(0, 255,0);
  
  myGLCD.print("up", 125, 173);
   }
  if(guess==2)
  {
    myGLCD.setColor(255, 0,0);
    myGLCD.fillRoundRect (120, 160, 200, 200);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (120, 160, 200, 200);

    myGLCD.setBackColor(255, 0,0);
  myGLCD.print("down", 125, 173);
   }
   if(guess==3)
  {
    myGLCD.setColor(238, 130,238);
    myGLCD.fillRoundRect (120, 160, 200, 200);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (120, 160, 200, 200);

    myGLCD.setBackColor(238, 130,238);
  myGLCD.print("left", 125, 173);
   }
   if(guess==4)
  {
    myGLCD.setColor(255, 165,0);
    myGLCD.fillRoundRect (120, 160, 220, 200);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (120, 160, 220, 200);

      myGLCD.setBackColor(255, 165,0);
    myGLCD.print("right", 125, 173);
   }

   unsigned long st=millis();
  long ed=millis() ;
  s=false;
  while(st-ed<thinkTime)
  {
    st=millis();



    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

      if ((x>=240) && (x<=319)&&(y>=15) && (y<=40))  
      {
      Serial.println(x);
      Serial.println(y);
        st=ed+6000;
        curpage='0';
         myGLCD.clrScr();
         score=0;
         rst=true;
        drawHome();
      }
    }
  







    
    if(guess ==1)
    {
      up=digitalRead(13);
      down=digitalRead(12);
      left=digitalRead(11);
      right=digitalRead(10);
      if(up==HIGH)
      {
        st=ed+6000;
        s=true;
        delay(200);
       }
       else if(down==HIGH ||left==HIGH || right==HIGH  )
       {
        Serial.println(8);
        s=false;
        st=ed+6000;
        }
    }



    if(guess == 2)
    {
      up=digitalRead(13);
      down=digitalRead(12);
      left=digitalRead(11);
      right=digitalRead(10);
      if(down==HIGH)
      {
        st=ed+6000;
        s=true;
        delay(200);
       }
       else if(up==HIGH ||left==HIGH || right==HIGH  )
       {
        Serial.println(8);
        s=false;
        st=ed+6000;
        }
    }

     if(guess ==3)
    {
      up=digitalRead(13);
      down=digitalRead(12);
      left=digitalRead(11);
      right=digitalRead(10);
      if(left==HIGH)
      {
        st=ed+6000;
        s=true;
        delay(200);
       }
       else if(down==HIGH ||up==HIGH || right==HIGH  )
       {
        
        s=false;
        st=ed+6000;
        }
    }

     if(guess == 4)
    {
      up=digitalRead(13);
      down=digitalRead(12);
      left=digitalRead(11);
      right=digitalRead(10);
      if(right==HIGH)
      {
        st=ed+6000;
        s=true;
        delay(200);
       }
       else if(down==HIGH ||left==HIGH || up==HIGH  )
       {
        
        s=false;
        st=ed+6000;
        }
    }


   
   
  }

  if(rst==true)
  {
    rst=false;
   }

  else if(s==true)
  {
    score=score+1;
    curpage='2';
    myGLCD.clrScr();
    }
    else
    {
      curpage='3';
      myGLCD.clrScr();
      drawFail();
     }

    





   
  
 }

void drawFail()
{
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (240, 15, 319, 40);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (240, 15, 319, 40);

  myGLCD.setBackColor(0, 0,255);
  myGLCD.print("EXIT", 245, 20);

   myGLCD.setColor(255, 255, 255);
    myGLCD.setBackColor(0, 0,0);
 myGLCD.print("You Failed!", 60, 83);

 myGLCD.print("Score: ", 60, 120);

 myGLCD.print(String(score) , 160, 123);
 }



void drawLvl()
{
   myGLCD.setColor(238, 130,238);
   myGLCD.fillRoundRect (100, 20, 220, 60);
   myGLCD.setColor(255, 255, 255);
   myGLCD.drawRoundRect (100, 20, 220, 60);
   myGLCD.setBackColor(238, 130,238);
     myGLCD.print("LV1", 130, 30);

      myGLCD.setColor(238, 130,238);
   myGLCD.fillRoundRect (100, 80, 220, 120);
   myGLCD.setColor(255, 255, 255);
   myGLCD.drawRoundRect (100, 80, 220, 120);
   myGLCD.setBackColor(238, 130,238);
     myGLCD.print("LV2", 130, 90);


      myGLCD.setColor(238, 130,238);
   myGLCD.fillRoundRect (100, 140, 220, 180);
   myGLCD.setColor(255, 255, 255);
   myGLCD.drawRoundRect (100, 140, 220, 180);
   myGLCD.setBackColor(238, 130,238);
     myGLCD.print("LV3", 130, 150);
 
 }



/*************************
**  Required functions  **
*  

*************************/
void setup()
{
// Initial setup
Wire.begin(9);

  myGLCD.InitLCD();
  myGLCD.clrScr();
  Serial.begin(9600);
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_HI);

  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 255);
  drawHome();  
  curpage='0';

}

void receiveEvent(int bytes) 
{
  x = Wire.read();    // read one character from the I2C
}

void loop()
{
  if(curpage=='0')
{
     
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      Serial.println(x);
      Serial.println(y);
      if ((x>=110) && (x<=190)&&(y>=180) && (y<=200))  // Upper row
      {
        curpage='4';
         myGLCD.clrScr();
    drawLvl();
      }
    }
}
  if(curpage=='1')
{
   
   delay(600);
   myGLCD.print("2", 145, 173);
   delay(1000);
   myGLCD.print("1", 145, 173);
   delay(1000);
   myGLCD.clrScr();
   myGLCD.setBackColor(0, 0, 0);
   myGLCD.print("Go!", 145, 83);
   delay(1000);
   curpage='2';
    myGLCD.clrScr();
 }
 if(curpage=='2')
{
   drawGame();
   
 } 

 if(curpage=='3')
{
   
long prev=millis();
unsigned long cur=millis() ;
while((cur-prev)<4000)
{
 cur=millis();
  if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

      if ((x>=240) && (x<=319)&&(y>=15) && (y<=40))  
      {
      Serial.println(x);
      Serial.println(y);
        cur=prev+5000;
        curpage='0';
         myGLCD.clrScr();
         score=0;
        drawHome();
      }
    }
  
 }
 curpage='0';
  myGLCD.clrScr();
   drawHome();
 } 
 if(curpage=='4')
 {
  if (myTouch.dataAvailable())
  {
     myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

       if ((x>=100) && (x<=220))  // Upper row
      {
      Serial.println(x);
      Serial.println(y);
          if((y>=20)&&(y<=60))
          {
            thinkTime=5000;
            curpage='1';
             myGLCD.clrScr();
             drawPrep();
          }
     
        if((y>=80)&&(y<=120))
          {
            thinkTime=2000;
            curpage='1';
             myGLCD.clrScr();
             drawPrep();
          }

          if((y>=140)&&(y<=180))
          {
            thinkTime=1000;
            curpage='1';
             myGLCD.clrScr();
             drawPrep();
          }
      }
      
   
   }

   
 
  }


}

