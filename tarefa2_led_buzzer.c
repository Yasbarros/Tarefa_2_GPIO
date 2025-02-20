
#include <stdio.h>
#include <string.h>         // Adicionado para corrigir o erro de 'strncmp'
#include "pico/stdlib.h"
#include "hardware/watchdog.h" // Necessário para o uso de watchdog_reboot

// Definição dos GPIOs
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER_PIN 21

// Comprimentos dos comandos
#define CMD_LEN_VERDE 5
#define CMD_LEN_AZUL 4
#define CMD_LEN_VERMELHO 8
#define CMD_LEN_BRANCO 6
#define CMD_LEN_OFF 3
#define CMD_LEN_BUZZER 6
#define CMD_LEN_REBOOT 6

// Protótipos das funções
void init_gpio();
void control_led(uint8_t green, uint8_t blue, uint8_t red);
void activate_buzzer();
void process_command_logic(const char *command);
void process_command();

int main(){
    stdio_init_all(); // Inicializa a UART
    init_gpio();      // Configuração inicial dos GPIOs

    printf("Sistema iniciado. Digite os comandos:\n");
    printf("Para Ligar Led Verde, digite: verde\n");
    printf("Para Ligar Led Vermelho, digite: vermelho\n");
    printf("Para Ligar Led Azul, digite: azul\n");
    printf("Para Ligar Led branco, digite: branco\n");
    printf("Para Desligar todos os Leds, digite: off\n");
    printf("Para Ligar Buzzer, digite: buzzer\n");

    //loop principal
    while (true) {
        process_command(); // lê e processa o comando via UART
    }

    return 0;    
}

// Processamento dos comandos recebidos via UART
void process_command() {
    char command[32];
    int i = 0;
    char c;

    // Lê um caractere por vez até encontrar o caractere de nova linha '\n' ou atingir o limite
    while (i < sizeof(command) - 1) {
        c = getchar();  // Lê um caractere via UART
        
        if (c == '\n' || c == '\r') {
            command[i] = '\0';  // Finaliza a string
            break;  // Sai do loop quando o comando é completo
        }
        
        command[i++] = c;  // Adiciona o caractere ao buffer de comando
    }

    // Processa o comando
    process_command_logic(command);
}

// Função lógica para processar o comando
void process_command_logic(const char *command) {
    if (strncmp(command, "verde", CMD_LEN_VERDE) == 0) {
        control_led(1, 0, 0); // Liga o LED verde
        printf("LED Verde ligado.\n");
    } else if (strncmp(command, "azul", CMD_LEN_AZUL) == 0) {
        control_led(0, 1, 0); // Liga o LED azul
        printf("LED Azul ligado.\n");
    } else if (strncmp(command, "vermelho", CMD_LEN_VERMELHO) == 0) {
        control_led(0, 0, 1); // Liga o LED vermelho
        printf("LED Vermelho ligado.\n");
    } else if (strncmp(command, "branco", CMD_LEN_BRANCO) == 0) {
        control_led(1, 1, 1); // Liga todos os LEDs (branco)
        printf("Todos os LEDs ligados (luz branca).\n");
    } else if (strncmp(command, "off", CMD_LEN_OFF) == 0) {
        control_led(0, 0, 0); // Desliga todos os LEDs
        printf("Todos os LEDs desligados.\n");
    } else if (strncmp(command, "buzzer", CMD_LEN_BUZZER) == 0) {
        activate_buzzer();    // Ativa o buzzer
        printf("Buzzer ativado por 2 segundos.\n");
    } else if (strncmp(command, "reboot", CMD_LEN_REBOOT) == 0) {
        printf("Reiniciando o sistema...\n");
        sleep_ms(1000);
        watchdog_reboot(0, 0, 0); // Reinicia o sistema
    } else {
        printf("Comando invalido: %s\n", command);
    }
}

void activate_buzzer() {
    gpio_put(BUZZER_PIN, 1);  // Liga o buzzer
    sleep_ms(500);           // Aguarda 2 segundos
    gpio_put(BUZZER_PIN, 0);  //Desliga o buzzer
}

void init_gpio() {
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    //Inicialização dos leds azul e vermelho
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, 0);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);

    // configuração do buzzer como saída
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0);
}

void control_led(uint8_t green, uint8_t blue, uint8_t red) {
    gpio_put(LED_GREEN, green);
    gpio_put(LED_BLUE, blue);
    gpio_put(LED_RED, red);
}
