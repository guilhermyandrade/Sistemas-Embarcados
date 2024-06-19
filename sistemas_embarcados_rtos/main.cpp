#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";
const char* mqtt_server = "MQTT_SERVER";

WiFiClient espClient;
PubSubClient client(espClient);
const int Relay = D1;

void setup_wifi() {

  // Delay de 10 ms
  delay(10);

  // Imprimindo mensagem na tela para feedback se teve conexão ou não
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Tentando conectar no wifi (enquanto o status do wifi for diferente de conectado)
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); // delay de meio segundo
    Serial.print("."); // Imprimindo ponto na tela representando que não está conectado
  }

  // Após a conexão, imprimindo se está conectado
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// Função para feedback de recepção de mensagens
void callback(char* topic, byte* payload, unsigned int length) {

  // Imprimindo a mensagem recebida
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String message;
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println(message);

  // Vendo se a mensagem recebida é ON ou OFF
  if (String(topic) == "ControleRelay"){
    if (message == "ON") { // Se for ON, desligando o relay
      digitalWrite(Relay, LOW);
    } else if (message == "OFF") { // Se for OFF, ligando o relay
      digitalWrite(Relay, HIGH);
    }
  }
}

// Definição de portas e setup
void setup() {
  pinMode(Relay, OUTPUT);
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

// Função para reconexão
void reconnect() {

  // Enquanto o cliente estiver desconectado
  while (!client.connected()) {

    // Imprimindo mensagem na tela para feedback se teve conexão ou não
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      client.subscribe("ControleRelay");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() { 
  if (!client.connected()) { // Loop enquanto o cliente estiver desconectado
    reconnect();
  }
  client.loop(); // Loop do cliente
}