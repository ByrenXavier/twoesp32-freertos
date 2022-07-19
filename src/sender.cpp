#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial SerialPort(2);

void send(void * parameters){
    for(;;){
        while(SerialPort.available()){
            SerialPort.print(1);
            vTaskDelay(3000/portTICK_PERIOD_MS);
            SerialPort.print(0);
            vTaskDelay(3000/portTICK_PERIOD_MS);
            yield();
        }
    }
}

void setup() {
  // put your setup code here, to run once:
  SerialPort.begin(115200,SERIAL_8N1,16,17);
  xTaskCreate(send,"Send",1000,NULL,tskIDLE_PRIORITY,NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
  vTaskDelete(NULL);
}