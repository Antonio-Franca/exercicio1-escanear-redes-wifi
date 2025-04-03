#include "WiFi.h"

void setup() {
  Serial.begin(115200);  // Inicia a comunicação serial
  WiFi.mode(WIFI_STA);   // Define o ESP32 no modo Station
  WiFi.disconnect();     // Desconecta de redes anteriores
  delay(100);
}

void loop() {
  Serial.println("Escaneando redes WiFi...");

  int numRedes = WiFi.scanNetworks(); // Escaneia redes disponíveis

  if (numRedes > 0) {
    Serial.print("Total de redes encontradas: ");
    Serial.println(numRedes);

    // Itera sobre todas as redes encontradas
    for (int i = 0; i < numRedes; i++) {
      String nomeRede = WiFi.SSID(i); // Nome da rede (SSID)
      int rssi = WiFi.RSSI(i);        // Sinal RSSI da rede
      String seguranca = "";          // Tipo de segurança da rede

      // Determina o tipo de segurança da rede
      switch (WiFi.encryptionType(i)) {
        case WIFI_AUTH_OPEN:
          seguranca = "Nenhuma";
          break;
        case WIFI_AUTH_WEP:
          seguranca = "WEP";
          break;
        case WIFI_AUTH_WPA_PSK:
          seguranca = "WPA";
          break;
        case WIFI_AUTH_WPA2_PSK:
          seguranca = "WPA2";
          break;
        case WIFI_AUTH_WPA_WPA2_PSK:
          seguranca = "WPA/WPA2";
          break;
        default:
          seguranca = "Desconhecida";
          break;
      }

      // Exibe os detalhes da rede
      Serial.print("Rede ");
      Serial.print(i + 1);
      Serial.print(": [");
      Serial.print(nomeRede);
      Serial.print("] - RSSI: ");
      Serial.print(rssi);
      Serial.print(" dBm - Segurança: ");
      Serial.println(seguranca);
      delay(1000); //Aguarda 1 segundo para melhor visualização
    }
  } else {
    Serial.println("Nenhuma rede WiFi encontrada.");
  }

  Serial.println("");  // Linha em branco para melhor visualização
  delay(3000); //Aguarda 4 segundos antes de prosseguir para o próximo escaneamento
}