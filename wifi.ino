#include <WiFi.h>

const char* ssid     = "meno-wifi-siete";
const char* password = "heslo-wifi-siete";

void setup() {
  Serial.begin(115200); // sputenie seriovej linky s rychlostou 115200
  Serial.println();     //vypis riadka
  Serial.print("Pripojenie na siet: "); //vypis textu na seriovu linku
  Serial.println(ssid);
  WiFi.begin(ssid, password); //pripojenie na WiFi siet s menom a heslom
  while (WiFi.status() != WL_CONNECTED) { //pokym nie je pripojeny cip do WiFi siete
    delay(500); //pozdrz program o 500ms
    Serial.print("."); //vypis bodku do serial monitoru
  }

  Serial.println(""); //vypis textu po pripojeni na siet
  Serial.println("WiFi pripojene");
  Serial.println("IP addresa: ");
  Serial.println(WiFi.localIP()); //vypis IP adresy v LAN sieti
}

void loop() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Pripojene na WiFi!");
  Serial.println("Cas procesora: ");
  Serial.print(millis());
  delay(5000);
}
