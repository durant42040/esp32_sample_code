#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/adc.h"


void setup_adc() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_12);
    adc1_config_channel_atten(ADC1_CHANNEL_7, ADC_ATTEN_DB_12);
    adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_12);
}

void read_joystick_values() {
    int x_val = adc1_get_raw(ADC1_CHANNEL_4);
    int y_val = adc1_get_raw(ADC1_CHANNEL_7);
    int z_val = adc1_get_raw(ADC1_CHANNEL_6);

    printf("X axis value: %d\n", x_val);
    printf("Y axis value: %d\n", y_val);
    printf("Z axis value: %d\n", z_val);
}

void app_main() {
    setup_adc();

    while (1) {
        read_joystick_values();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
