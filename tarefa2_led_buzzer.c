#include <stdio.h>
#include <string.h>         // Adicionado para corrigir o erro de 'strncmp'
#include "pico/stdlib.h"
#include "hardware/watchdog.h" // Necessário para o uso de watchdog_reboot



int main()
{
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
