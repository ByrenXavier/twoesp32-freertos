#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial SerialPort(2);

void receive(void * parameters){
    for(;;){
        if (SerialPort.available()){
            char number = SerialPort.read();
            if (number == '1'){
                Serial.print("Hello");
            }
            if (number == '0'){
                Serial.println(" world!");
            }
        }
        yield();
    }
}

void setup() {
  // put your setup code here, to run once:
  SerialPort.begin(115200,SERIAL_8N1,16,17);
  Serial.begin(9600);
  xTaskCreate(receive,"Receive",1000,NULL,tskIDLE_PRIORITY,NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
  vTaskDelete(NULL);
}