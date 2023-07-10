#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Stepper.h>
#include "PageIndex.h"

const int stepsPerRevolution = 20;
const char* ssid     = "CASA 13_2.4";
const char* password = "0450vitor";
int goal;
int sign = 1;
String comando;

Stepper myStepper(stepsPerRevolution, 5, 4, 14, 12); //pinos d1 d2 d5 d6
int stepCount = 0;        

ESP8266WebServer server(80);

void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleStepper(){
  String POS = server.arg("stepperPOS");
  goal = POS.toInt();
  server.send(200, "text/plane","");
}

void handleButtons(){
  String c = server.arg("button");
  comando = c;
  server.send(200, "text/plane","");
}

void setup() {
  Serial.begin(115200);
  delay(5000);
  WiFi.begin(ssid, password); //--> Connect to your WiFi router
  Serial.println("");
  Serial.println(WiFi.localIP());
  server.on("/",handleRoot);  //--> Routine to handle at root location. This is to display web page.
  server.on("/setPOS",handleStepper); //--> Sets servo position from Web request
  server.on("/comand",handleButtons);
  server.begin();  
}

void loop() {

   
  Serial.print("steps:");
  Serial.println(stepCount);
  Serial.println(comando);
  
  if(goal>stepCount){
    sign=1;
  }

  if(goal<stepCount){
    sign=-1;
  }
  
  if(goal!=stepCount){
    myStepper.step(1*sign);
    stepCount=stepCount+sign;
  }


  delay(10);
  server.handleClient();
}
