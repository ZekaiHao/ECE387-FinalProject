
int up=0;
int down=0;
int left=0;
int right=0;
void setup() {
  // put your setup code here, to run once:
pinMode(13,INPUT);
pinMode(12,INPUT);
pinMode(11,INPUT);
pinMode(10,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
up=digitalRead(13);
down=digitalRead(12);
left=digitalRead(11);
right=digitalRead(10);
if(up==HIGH)
{
  int s=1;
  Serial.println(s);
 }
 if(down==HIGH)
{
  int s=2;
  Serial.println(s);
 }
 if(left==HIGH)
{
  int s=3;
  Serial.println(s);
 }
 if(right==HIGH)
{
  int s=4;
  Serial.println(s);
 }

 delay(100);
}
