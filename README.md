
OSHW SCREENING TASK README


Name: Albin Chacko  
College: Saintgits College of Engineering, Kottayam  
Department: Robotics and Automation  
Date: 8 November 2025


Objective

Set up and demonstrate a complete ESP32 emulation environment using QEMU and ESP-IDF.
Run and show two working examples:
1. Blink LED (GPIO simulation)
2. Temperature Reading (Simulated)


System Information

Operating System: Windows 11 (64-bit)
ESP-IDF Version: v5.2.1
QEMU Version: QEMU for ESP32 (xtensa-softmmu) build 2025.10
Python Version: 3.11.5
Build Tools Used: CMake, Ninja, Git, IDF Command Line Tools

Setup Steps

1. Installed ESP-IDF Tools for Windows from Espressif official website.
2. Installed QEMU emulator using:
   python %IDF_PATH%\tools\idf_tools.py install qemu-xtensa
   %IDF_PATH%\export.bat
3. Verified installation using:
   idf.py --version
4. Created a new ESP-IDF project using:
   idf.py create-project blink
5. Built and tested both projects in the QEMU emulator.


Project 1: Blink LED

Project Folder: blink
Main File: main/blink_main.c

Code Used:

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


Build Commands:
idf.py set-target esp32
idf.py build

Run Command:
idf.py qemu monitor

Expected Output:
LED ON
LED OFF
LED ON
LED OFF
...

<img width="1600" height="963" alt="image" src="https://github.com/user-attachments/assets/70330779-ef7e-4bc6-bfce-bfd243f4184e" />



Project 2: Temperature Simulation

Project Folder: temperature
Main File: main/temperature_main.c

Code Used:

#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    while (1) {
        int temperature = 25 + rand() % 6; // 25 to 30 °C
        printf("Temperature: %d°C\n", temperature);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}


Build Commands:
idf.py set-target esp32
idf.py build

Run Command:
idf.py qemu monitor

Expected Output:
Temperature: 27°C
Temperature: 29°C
Temperature: 26°C
Temperature: 30°C
...

<img width="1600" height="990" alt="image" src="https://github.com/user-attachments/assets/c22737f5-c987-4afd-ac1f-4e2b68cef811" />

