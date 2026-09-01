#ifndef DRIVERS_GPIO_H
#define DRIVERS_GPIO_H

#include <stdint.h>

typedef enum { GPIO_PORT_A, GPIO_PORT_B, GPIO_PORT_C } gpio_port_t;

void gpio_enable_clock(gpio_port_t port);
void gpio_set_output(gpio_port_t port, uint8_t pin);
void gpio_set_input(gpio_port_t port, uint8_t pin);
void gpio_write(gpio_port_t port, uint8_t pin, uint8_t high);
uint8_t gpio_read(gpio_port_t port, uint8_t pin);

#endif