#include "drivers/gpio.h"
#include "drivers/uart.h"


int main(void) {
    gpio_enable_clock(GPIO_PORT_A);   // both LED and switch are on port A now
    gpio_set_output(LED_PORT, LED_PIN);
    
    gpio_set_input(SWITCH_PORT, SWITCH_PIN);
    gpio_set_pup(SWITCH_PORT, SWITCH_PIN);

    while (1) {
        gpio_write(LED_PORT, LED_PIN, gpio_read(SWITCH_PORT, SWITCH_PIN));
    }
}