//Inisialisasi pembuatan variable
#define B1 5 // Motor B pins
#define B2 6

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer

 pinMode(B1, OUTPUT);
 pinMode(B2, OUTPUT);

 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);
 
 Serial.println("Silahkan Pilih salah satu:");
 Serial.println("1.forward");
 Serial.println("2.backward");
 Serial.println("3.stop"); 
}

void loop() {
 //Program yang akan dijalankan berulang-ulang
forward();
delay(100);
Stop();
delay(1000);
backward();
delay(100);
Stop();
delay(1000);
}
void forward() { //function of forward 
 analogWrite(B1, 255);
 analogWrite(B2, 0);
}
void backward() { //function of backward

 analogWrite(B1, 0);
 analogWrite(B2, 255);
}
void Stop() { //function of stop

 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);

}
