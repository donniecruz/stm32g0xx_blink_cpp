#include <cstdint>
#include <stm32g071xx.hpp>

int main()
{
    auto RCC { reinterpret_cast<stm32g071_regs::rcc_register*>(AhbPeriphAddr::Rcc) };
    auto GPIOA { reinterpret_cast<stm32g071_regs::gpio_registers*>(GpioPeriphAddr::GpioA ) };

    while( 1 )
    {
        RCC->APBENR2 = RCC->APBENR2 | 0x01;
        RCC->APBENR1 = RCC->APBENR1 | ( 1 << 28 );
        RCC->IOPENR = RCC->IOPENR | 0x01;

        // Reset the mode register
        GPIOA->MODER = GPIOA->MODER & ( 3 << 10 );

        // Set Port A/Pin 5 to General Purpose Output Mode
        GPIOA->MODER = GPIOA->MODER | ( 1 << 10 );

        // Turn on Port A/Pin 5
        GPIOA->ODR = GPIOA->ODR | ( 0 << 5 );
        // Do Nothing for now
    }
    return 0;
}