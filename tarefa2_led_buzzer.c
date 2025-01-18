void activate_buzzer() {
    gpio_put(BUZZER_PIN, 1);  // Liga o buzzer
    sleep_ms(500);           // Aguarda 0,5 segs
    gpio_put(BUZZER_PIN, 0);  // Desliga o buzzer
}
