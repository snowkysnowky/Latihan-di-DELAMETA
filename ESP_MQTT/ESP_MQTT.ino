#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <MFRC522.h>
String uidString;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); //Create MFRC522 instance

char ssid[]        = "delameta";            // your network SSID (name)
char pass[]        = "bilano1407";        // your network password
int status = WL_IDLE_STATUS; // the Wifi radio's status
unsigned long lastSend;

// Initialize the Ethernet client object
WiFiEspClient espClient;
PubSubClient client(espClient);

SoftwareSerial Serialx(2,3); // RX, TX   //ESP8266 RX,TX connected to these pins
int kunci=0;
int ledr=4;
int ledy=5;
int ledg=6;
int ldr=A0;
int Flame=A1;
void setup() {
// initialize serial for debugging
Serial.begin(115200);
SPI.begin(); //Initiate SPI bus
mfrc522.PCD_Init();

// initialize serial for ESP module
Serialx.begin(9600);
// initialize ESP module
WiFi.init(&Serialx);
pinMode(ledr,OUTPUT);
pinMode(ledy,OUTPUT);
pinMode(ldr,INPUT);
pinMode(Flame,INPUT);
// check for the presence of the shield
if (WiFi.status() == WL_NO_SHIELD) {
Serial.println("WiFi shield not present");
// don't continue
while (true);
}

// attempt to connect to WiFi network
while ( status != WL_CONNECTED) {
Serial.print("Attempting to connect to WPA SSID: ");
Serial.println(ssid);
// Connect to WPA/WPA2 network
status = WiFi.begin(ssid, pass);
lastSend = 0;
}

// you're connected now, so print out the data
Serial.println("You're connected to the network");

//connect to MQTT server
client.setServer("broker.hivemq.com", 1883);
client.setCallback(callback);
}

//print any message received for subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Pesan diterima [");
  Serial.print(topic);
  Serial.println("] ");
  //==============================================================
  if (strcmp(topic, "daffa8388/lampu1") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(ledr,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(ledr,LOW);
    }
  }
  }
  //==============================================================
  //==============================================================
  if (strcmp(topic, "daffa8388/lampu2") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(ledy,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(ledy,LOW);
    }
  }
  }
  //==============================================================

  //==============================================================
  if (strcmp(topic, "daffa8388/lampu3") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(ledg,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(ledg,LOW);
    }
  }
  }
  //==============================================================
  //==============================================================
  if (strcmp(topic, "daffa8388/flipflop") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       kunci=1;
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
        digitalWrite(ledr,LOW);
        digitalWrite(ledy,LOW);
        digitalWrite(ledg,LOW);
       kunci=0;
    }
  }
  }
  //==============================================================
}

void pushdata(){
  //Ambil Data / Baca Sensor
  int bacaldr=analogRead(ldr);
  int bacaFlame=analogRead(Flame);
  int datax=bacaldr;
  if(mfrc522.PICC_IsNewCardPresent()){
  readRFID();
}
  //POST TO SERIAL
  Serial.print("Sensor 1 :");Serial.print(datax);
  Serial.println();
Serial.print("Sensor 2 :");Serial.print(bacaFlame);
  Serial.println();
  Serial.print("UID :");Serial.print(uidString);
  Serial.println();
  
  //POST TO MQTT
  //client.publish("daffa8388/datax", dtostrf(datax, 6, 2, msgBuffer)); //Convert to String 
  client.publish("daffa8388/datax", String(datax).c_str());
  client.publish("daffa8388/datax1", String(bacaFlame).c_str());
  client.publish("daffa8388/datax2", String(uidString).c_str());
}

void loop() {
// put your main code here, to run repeatedly:

if (!client.connected()) {
reconnect();
}
if ( millis() - lastSend > 3000 ) { // Update and send only after 1 seconds
    pushdata();
    lastSend = millis();
 }
client.loop();
if(kunci==1){
  flipflop();

}
}

void reconnect() {
// Loop until we're reconnected
while (!client.connected()) {
Serial.print("Attempting MQTT connection...");
// Attempt to connect, just a name to identify the client
if (client.connect("daffaaw")) {
Serial.println("connected");

//client.publish("outpic","Hello World");
client.subscribe("daffa8388/lampu1",0);
client.subscribe("daffa8388/lampu2",0);
client.subscribe("daffa8388/lampu3",0);
client.subscribe("daffa8388/flipflop",0);
} else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds");
  // Wait 5 seconds before retrying
  delay(5000);
}
}
}
void flipflop(){
  
   digitalWrite(ledr,HIGH);
  delay(100);
  digitalWrite(ledr,LOW);
  digitalWrite(ledy,HIGH);
  delay(100);
  digitalWrite(ledy,LOW);
  digitalWrite(ledg,HIGH);
  delay(100);
  digitalWrite(ledg,HIGH);
  digitalWrite(ledy,LOW);
  delay(100);
  digitalWrite(ledg,LOW);
  digitalWrite(ledy,HIGH);
  delay(100);
  digitalWrite(ledy,LOW);
  digitalWrite(ledr,HIGH);
  delay(100);
  digitalWrite(ledy,LOW);
}
void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //Sound the buzzer when a card is read
  //Pembatas bisa dirubah sesuai keiginan,disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0]) + "-" +
  String(mfrc522.uid.uidByte[1]) + "-" +
  String(mfrc522.uid.uidByte[2]) + "-" +
  String(mfrc522.uid.uidByte[3]);
  break;
}
