# Escaneamento de redes WiFi com ESP32

## Descrição do Projeto

Este projeto consiste em dois componentes que trabalham em conjunto para escanear redes WiFi disponíveis e capturar os dados relacionados. Utilizou-se um ESP32 para identificar redes no ambiente, enquanto um script em Python captura e armazena os dados no computador local.

---

## Componentes do Projeto

### Código ESP32
O código no ESP32 é responsável por:
1. Escanear redes WiFi disponíveis.
2. Exibir informações sobre cada rede, como:
   - Nome da rede (SSID).
   - Intensidade do sinal (RSSI).
   - Tipo de segurança (aberta, WEP, WPA, etc.).
3. Enviar essas informações para o computador via comunicação serial.

Este código opera com o ESP32 configurado no modo *Station* (STA), que permite que ele funcione como um cliente, identificando redes próximas, mas sem conectar-se a elas.

---

### Código Python
O script Python complementa o código do ESP32 ao:
1. Capturar os dados enviados pelo ESP32 via porta serial.
2. Exibir os dados no terminal para visualização em tempo real.
3. Salvar os dados em um arquivo (`rssi_dados.txt`).

---

## Passo a Passo para Executar

### Configuração do ESP32
1. Certifique-se de que o código Arduino esteja carregado no ESP32.
2. Configure o monitor serial na Arduino IDE com a mesma taxa de transmissão (baud rate) usada no código Python.

### Configuração do Script Python
1. Instale o Python e certifique-se de que a biblioteca `pyserial` está disponível. Você pode instalá-la com:
   ```bash
   pip install pyserial
   ```
2. Ajuste a porta serial no script Python conforme necessário (ex.: `/dev/ttyUSB0` ou `COM4`).

## Exemplo de Fluxo de Dados

1. ESP32 envia dados como:
   ```plaintext
   Rede 1: [MinhaRedeWiFi] - RSSI: -67 dBm - Segurança: WPA2
   ```
2. Python recebe e exibe:
   ```plaintext
   Rede 1: [MinhaRedeWiFi] - RSSI: -67 dBm - Segurança: WPA2
   ```
3. Python salva no arquivo `rssi_dados.txt`:
   ```plaintext
   Rede 1: [MinhaRedeWiFi] - RSSI: -67 dBm - Segurança: WPA2
   ```
---

## Considerações Finais
- **Delay**: Os tempos de espera no código (`delay`) são usados para melhorar a visualização das informações no monitor serial.

- **Limitações**: O código apenas exibe as redes encontradas;

---

