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
void process_command(const char *command);
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


    while (1) {
        
    }

    return 0;
}

void init_gpio() {
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

}