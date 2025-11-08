#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    while (1) {
        int temperature = 25 + rand() % 6; // random 25–30°C
        printf("Temperature: %d°C\n", temperature);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
