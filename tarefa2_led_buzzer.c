
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

    char command[32];
    while (1) {
        // Lê o comando via UART
        if (fgets(command, sizeof(command), stdin)) {
            process_command(command); // Processa o comando recebido
        }
    }
    return 0;
}

void activate_buzzer() {
    gpio_put(BUZZER_PIN, 1);  // Liga o buzzer
    sleep_ms(2000);           // Aguarda 2 segundos
    gpio_put(BUZZER_PIN, 0);  //Desliga o buzzer
}

void init_gpio() {
    //Inicialização dos leds azul e vermelho
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, 0);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);

    // configuração do buzzer como saída
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0);
}

