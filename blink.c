#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    int led_state = 0;
    while (1) {
        led_state = !led_state;
        if (led_state)
            printf("LED ON\n");
        else
            printf("LED OFF\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
