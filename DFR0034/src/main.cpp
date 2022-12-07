#include <Arduino.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"

const int ANALOG_PIN = A0;
int val = 0;

void setup()
{
  Serial.begin(115200); // open serial port, set the baud rate to 9600 bps

		while (!Serial) {}        // Attendre la connexion du moniteur serie
		wifiConnect();
		MQTTConnect();
		Serial.print("Bien connecté\n");
    pinMode(ANALOG_PIN, INPUT);
}
void loop()
{

    val = analogRead(A0);

    appendPayload("Sound :", val);  //Ajout de la donnée sound au message MQTT
    sendPayload();                //Envoie du message via le protocole MQTT

    delay(100);
}