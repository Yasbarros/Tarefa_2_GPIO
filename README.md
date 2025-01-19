# Projeto: Controle de LEDs e Buzzer via UART com Raspberry Pi Pico

Este projeto implementa um sistema de controle para LEDs RGB e um buzzer utilizando um Raspberry Pi Pico. Comandos recebidos via UART permitem ativar/desativar LEDs de diferentes cores, controlar o buzzer e reiniciar o sistema.

## Funcionalidades

- **Controle de LEDs RGB** (Verde, Azul, Vermelho, Branco e Desligar).
- **Ativação temporária do buzzer**.
- **Reinicialização do sistema via comando UART**.

## Hardware Necessário

1. **Raspberry Pi Pico**
2. **Três LEDs** (Verde, Azul e Vermelho) com resistores apropriados
3. **Buzzer**
4. **Protoboard e cabos de conexão**

## Conexões de Hardware

### LEDs
- **LED Verde**: GPIO `11`
- **LED Azul**: GPIO `12`
- **LED Vermelho**: GPIO `13`

### Buzzer
- **Buzzer**: GPIO `21`

## Comandos Disponíveis

Os comandos são enviados via UART (usando ferramentas como PuTTY ou minicom):

| **Comando** | **Ação**                                 |
|-------------|-----------------------------------------|
| verde       | Liga o LED verde                        |
| azul        | Liga o LED azul                         |
| vermelho    | Liga o LED vermelho                     |
| branco      | Liga todos os LEDs (luz branca)         |
| off         | Desliga todos os LEDs                   |
| buzzer      | Ativa o buzzer por 2 segundos           |
| reboot      | Reinicia o sistema                      |

## Funcionamento

1. **Inicialização**: 
   - Os GPIOs são configurados como saída para os LEDs e buzzer, e a UART é inicializada para receber comandos.

2. **Processamento de Comandos**:
   - O sistema lê comandos via UART e executa ações correspondentes (ex.: ligar LEDs, ativar buzzer).
   - Comandos inválidos geram uma mensagem de erro.

3. **Reinicialização**: 
   - O comando `reboot` utiliza o watchdog para reiniciar o Raspberry Pi Pico.

## Compilação e Execução

### Pré-requisitos

- **SDK do Raspberry Pi Pico** configurado.
- **Ferramentas de compilação** (CMake, GCC).

### Passos para Compilação

1. Clone o repositório do projeto:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <PASTA_DO_PROJETO>
   ```

2. Compile o código

3. Envie o arquivo `.uf2` para o Raspberry Pi Pico:
   - Conecte o Pico ao computador em modo bootloader.
   - Copie o arquivo `.uf2` gerado para o dispositivo USB montado.

4. Identifique a porta serial que o Raspberry Pi Pico está conectado

5. No putty, selecione a opção _serial_:
   - Na caixa _serial line_, digite a porta COM identificada no passo 4.
   - Em _speed_, digite o valor _115200_.

6. Aperte a opção _open_ e digite os comandos:
   - Para ligar o led verde, _verde_.
   - Para ligar o led vermelho, _vermelho_.
   - Para ligar o led azul, _azul_.
   - Para ligar todos os leds, _branco_.
   - Para desligar os leds, _off_.
   - Para ligar o buzzer, _buzzer_.
   - Para reiniciar o sistema, _reboot_.


## Observações

- Utilize resistores adequados para evitar danos aos LEDs.
- Certifique-se de que a conexão do buzzer está correta para evitar mau funcionamento.

[Clique aqui ⬆️ e assista o vídeo](https://youtu.be/e8moQTt2UPw)

