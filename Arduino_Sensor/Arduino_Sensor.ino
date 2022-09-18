#include <SPI.h>
#include <SD.h>
#include <dht.h>


#define DHT11_PIN 7


File file;
dht DHT;
String command;

void setup() {
    
    Serial.begin(9600); 
    if (!SD.begin(4)) {
    Serial.println("Initialization Failed!");
    while (1);
  }
  Serial.println("Initialization Done.");
    Serial.println("Welcome to Dark Eye OS Environmental Sensor.");
    Serial.println("Type help for commands list.");
    Serial.println(">:");
}
 
void loop() {
  
  
    if(Serial.available()){
        command = Serial.readStringUntil('\n');
         
        if(command.equals("ping")){
            Serial.println("OK. | C8");
            Serial.println(">:");
        }
        else if(command.equals("s1")){
          
            int chk = DHT.read11(DHT11_PIN);
            Serial.print("Temperature = ");
            Serial.println(DHT.temperature);
            Serial.print("Humidity = ");
            Serial.println(DHT.humidity);
            Serial.println(">:");
            
          
        }

        else if(command.equals("save s1")){
          int chk = DHT.read11(DHT11_PIN);
        
             SD.remove("/S1/SENSOR_1.DAT");
             file = SD.open("/S1/SENSOR_1.DAT", FILE_WRITE);
             if(file) {
              file.println("Temperature:");
              file.println(DHT.temperature);
              file.println("Humidity:");
              file.println(DHT.humidity);
              file.close();
              Serial.println("Written to Memory.");
              Serial.println(">:");
             }
            else {
           Serial.println("Error opening file. | 199");
           Serial.println(">:");
           }
          
        }
        else if(command.equals("help")){
            Serial.println("Command | Description of command            ");
            Serial.println("s1      | Displays humidity and temperature ");
            Serial.println("save s1 | Saves humidity and temperature to memory card. ");
            Serial.println("read s1 | Reads humidity and temperature file from memory card. ");
            Serial.println("init sd | This is recommended for new memory cards. ");
            Serial.println(">:");
        }
         else if(command.equals("read s1")){
            file = SD.open("/S1/SENSOR_1.DAT");
            if (file) {
            Serial.println("SENSOR_1.DAT:");

   
            while (file.available()) {
            Serial.write(file.read());
            }
    
            file.close();
            Serial.println(">:");
            } else {
    
             Serial.println("File not found. | 194");
             Serial.println(">:");
              }
            }
        else if(command.equals("init sd")){
           SD.mkdir("env");
           SD.mkdir("s1");

            int chk = DHT.read11(DHT11_PIN);

              SD.remove("/S1/SENSOR_1.DAT");
             file = SD.open("/S1/SENSOR_1.DAT", FILE_WRITE);
             if(file) {
              file.println("Content not available.");
              file.close();
              Serial.println("OK. | C8");
              
             }
             SD.remove("/ENV/CONFIG.DAT");
             file = SD.open("/ENV/CONFIG.DAT", FILE_WRITE);
             if(file) {
              file.println("Content not available.");
              file.close();
              Serial.println("OK. | C8");
              Serial.println(">:");
              
             }
             
            else {
           Serial.println("Error opening file. | 199");
           Serial.println(">:");
           }
        }
     
        else{
            Serial.println("Invalid command. | 194");
            Serial.println(">:");
        }
    }
}
