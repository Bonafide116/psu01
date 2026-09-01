#include <stdint.h>

extern uint32_t _estack;

int main(void);

void Reset_Handler(void);
void Default_Handler(void) { while (1); }

__attribute__((section(".isr_vector")))
void (* const vector_table[])(void) = {
    (void (*)(void))&_estack,
    Reset_Handler,
};

void Reset_Handler(void) {
    main();
    while (1);   // safety net if main() ever returns
}