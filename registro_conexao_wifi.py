import serial
import time

# Configuração da porta serial e taxa de transmissão
PORTA_SERIAL = "/dev/ttyUSB0"  # Ajuste conforme necessário
BAUDRATE = 115200              # Deve corresponder ao Arduino
ARQUIVO_SAIDA = "rssi_dados.txt"

def iniciar_conexao(porta, baudrate):
    """Inicializa a conexão com a porta serial."""
    try:
        conexao = serial.Serial(porta, baudrate, timeout=1)
        time.sleep(2)  # Aguarda estabilização
        print(f"Conectado à {porta}. Capturando dados RSSI...")
        return conexao
    except serial.SerialException as e:
        print(f"Erro ao acessar {porta}: {e}")
        return None

def salvar_dados_em_arquivo(arquivo, linha):
    """Salva uma linha de dados no arquivo especificado."""
    arquivo.write(linha + "\n")

def capturar_dados_rssi(conexao, arquivo_saida):
    """Captura os dados RSSI da conexão serial e salva em um arquivo."""
    with open(arquivo_saida, "w", encoding="utf-8") as arquivo:
        while True:
            try:
                # Lê a linha enviada pelo Arduino
                linha = conexao.readline().decode("utf-8", errors="ignore").strip()
                if linha:
                    print(linha)  # Exibe no terminal
                    salvar_dados_em_arquivo(arquivo, linha)
            except KeyboardInterrupt:
                print("\nCaptura interrompida pelo usuário.")
                break
            except Exception as e:
                print(f"Erro ao processar os dados: {e}")

def main():
    """Função principal para executar o programa."""
    conexao = iniciar_conexao(PORTA_SERIAL, BAUDRATE)
    if conexao:
        try:
            capturar_dados_rssi(conexao, ARQUIVO_SAIDA)
        finally:
            conexao.close()
            print("Conexão encerrada.")

if __name__ == "__main__":
    main()

