#include "drivers/gpio.h"

#

static uint32_t port_base(gpio_port_t port) {
    switch (port) {
        case GPIO_PORT_A: return GPIOA_BASE;
        case GPIO_PORT_B: return GPIOB_BASE;
        case GPIO_PORT_C: return GPIOC_BASE;
    }
    return 0;
}

void gpio_enable_clock(gpio_port_t port) {
    RCC_AHB2ENR |= (1UL << port);   // AHB2ENR bit layout matches GPIO_PORT_A/B/C = 0/1/2
}

static volatile uint32_t *moder(gpio_port_t port) {
    return (volatile uint32_t *)(port_base(port) + 0x00);
}
static volatile uint32_t *pupdr(gpio_port_t port) {
    return (volatile uint32_t *)(port_base(port) + 0x0c);
}
static volatile uint32_t *idr(gpio_port_t port) {
    return (volatile uint32_t *)(port_base(port) + 0x10);
}
static volatile uint32_t *odr(gpio_port_t port) {
    return (volatile uint32_t *)(port_base(port) + 0x14);
}

void gpio_set_output(gpio_port_t port, uint8_t pin) {
    *moder(port) &= ~(0x3UL << (pin * 2));
    *moder(port) |=  (0x1UL << (pin * 2));
}

void gpio_set_input(gpio_port_t port, uint8_t pin) {
    *moder(port) &= ~(0x3UL << (pin * 2));   // 00 = input, so just clearing is enough
}

void gpio_set_pup(gpio_port_t port, uint8_t pin) {
    *pupdr(port) &=  (0x3UL << (pin * 2));
    *pupdr(port) |=  (0x1UL << (pin * 2));
}

void gpio_set_pdn(gpio_port_t port, uint8_t pin) {
    *pupdr(port) &=  (0x3UL << (pin * 2));
    *pupdr(port) |=  (0x2UL << (pin * 2));
}

void gpio_write(gpio_port_t port, uint8_t pin, uint8_t high) {
    if (high) *odr(port) |=  (1UL << pin);
    else      *odr(port) &= ~(1UL << pin);
}

uint8_t gpio_read(gpio_port_t port, uint8_t pin) {
    return (*idr(port) >> pin) & 0x1UL;
}