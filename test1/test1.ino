//INISIALISASI
int pinPIR=2,pinbuzz=5;
void setup() {
  // 
  Serial.begin(9600);
  pinMode(pinPIR,INPUT);
  pinMode(pinbuzz,OUTPUT);
}

void loop() {
  
  //BACA DATASENSOR
int bacaPIR=digitalRead(pinPIR);

//PRINT TO SERIAL
Serial.print("PIR :");
Serial.print(bacaPIR);
Serial.println();

//LOGIKA PROGRAM
if (bacaPIR==1){
  Serial.println("MALING CUK");
  digitalWrite(pinbuzz,HIGH);
  delay(200);
  digitalWrite(pinbuzz.LOW);
  delay(100);
}
else{
  Serial.println("AMAN SLURR");
  digitalWrite(pinbuzz,LOW);
  }
}
