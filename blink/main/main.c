#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO_PIN GPIO_NUM_2

void app_main(void) {
    gpio_set_direction(LED_GPIO_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(LED_GPIO_PIN, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LED_GPIO_PIN, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
