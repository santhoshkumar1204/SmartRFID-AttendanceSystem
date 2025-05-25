#include <SPI.h> 
#include <MFRC522.h> 
 
#define RST_PIN 27 
#define SS_PIN 26 
#define BUZZER_PIN 4 
 
MFRC522 mfrc522(SS_PIN, RST_PIN);  
 
void setup() { 
  Serial.begin(9600); 
  SPI.begin();   
  mfrc522.PCD_Init();  
 
  pinMode(BUZZER_PIN, OUTPUT); 
 
  // PLX-DAQ Header 
  Serial.println("CLEARDATA"); // Clears Excel sheet on run 
  Serial.println("LABEL,Time,UID,Name"); // Column headers 
} 
 
 
 
void loop() { 
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) { 
    return; 
  } 
 
  String uid = ""; 
  for (byte i = 0; i < mfrc522.uid.size; i++) { 
    uid += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""); 
    uid += String(mfrc522.uid.uidByte[i], HEX); 
  } 
  uid.toUpperCase(); 
 
  String name = getNameFromUID(uid); 
 
  // Buzzer beep 
  digitalWrite(BUZZER_PIN, HIGH); 
  delay(100); 
  digitalWrite(BUZZER_PIN, LOW); 
 
  // Send to PLX-DAQ 
  Serial.print("DATA,TIME,"); 
  Serial.print(uid); 
  Serial.print(","); 
 
 
  Serial.println(name); 
 
  mfrc522.PICC_HaltA(); 
  mfrc522.PCD_StopCrypto1(); 
  delay(1000); 
} 
 
String getNameFromUID(String uid) { 
  // Add your UID → Name mappings here 
  if (uid == "A1B2C3D4") return "Alice"; 
  if (uid == "1A2B3C4D") return "Bob"; 
  if (uid == "DEADBEEF") return "Charlie"; 
  return "Unknown"; 
} 
 
