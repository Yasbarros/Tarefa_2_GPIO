void activate_buzzer() {
    gpio_put(BUZZER_PIN, 1);  // Liga o buzzer
    sleep_ms(2000);           // Aguarda 2 segundos
    gpio_put(BUZZER_PIN, 0);  // Desliga o buzzer
}
