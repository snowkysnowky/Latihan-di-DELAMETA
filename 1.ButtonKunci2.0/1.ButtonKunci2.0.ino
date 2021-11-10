int tombol1=2,R=5,tombol2=3,tombol3=4,Y=6,G=7,kunci1=0,kunci2=0,kunci3=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaTombol1=digitalRead(tombol1);
int bacaTombol2=digitalRead(tombol2);
int bacaTombol3=digitalRead(tombol3);

if (bacaTombol1==1 and kunci1==0)
{
  digitalWrite(R,HIGH);
  kunci1=1;
  delay(200);
}
if (bacaTombol1==1 and kunci1==1)
{
  digitalWrite(R,LOW);
  kunci1=0;
  delay(200);
}
if (bacaTombol2==1 and kunci2==0)
{
  digitalWrite(Y,HIGH);
  kunci2=1;
  delay(200);
}
if (bacaTombol2==1 and kunci2==1)
{
  digitalWrite(Y,LOW);
  kunci2=0;
  delay(200);
}
if (bacaTombol3==1 and kunci3==0)
{
  digitalWrite(G,HIGH);
  kunci3=0;
  delay(200);
}
if (bacaTombol3==1 and kunci3==1)
{
  digitalWrite(G,LOW);
  kunci3=0;
  delay(200);
}
else{}
}
