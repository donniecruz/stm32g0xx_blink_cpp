/*!
*       @file   startup_stm32g071.cpp
*       @brief  Startup Code for STM32G071 for Vector Table Initialization
                And Reset Handling
*/

/*
*   Include Files
*/
#include <cstdint>
#include <algorithm>
#include <stm32g071xx.hpp>

/*
*   Extern Variables from the Linker Script
*/
extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/*
*   Extern main() Function
*/

/*
*   Private Function Declaration
*/
extern "C"
{
    [[noreturn]] void Reset_Handler( void );
    void Default_Handler( void );
    extern int main( void );
}

/*
*   Weak Function Prototypes for the STM32G071
*/
void NMI_Handler                        ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void HardFault_Handler                  ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void SVC_Handler                        ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void PendSV_Handler                     ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void SysTick_Handler                    ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void WWDG_IRQHandler                    ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void PVD_IRQHandler                     ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void RTC_TAMP_IRQHandler                ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void FLASH_IRQHandler                   ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void RCC_IRQHandler                     ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void EXTI0_1_IRQHandler                 ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void EXTI2_3_IRQHandler                 ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void EXTI4_15_IRQHandler                ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void UCPD1_2_IRQHandler                 ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void DMA1_Channel1_IRQHandler           ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void DMA1_Channel2_3_IRQHandler         ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void DMA1_Ch4_7_DMAMUX1_OVR_IRQHandler  ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void ADC1_COMP_IRQHandler               ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM1_BRK_UP_TRG_COM_IRQHandler     ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM1_CC_IRQHandler                 ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM2_IRQHandler                    ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM3_IRQHandler                    ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM6_DAC_LPTIM1_IRQHandler         ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM7_LPTIM2_IRQHandler             ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM14_IRQHandler                   ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM15_IRQHandler                   ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM16_IRQHandler                   ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void TIM17_IRQHandler                   ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void I2C1_IRQHandler                    ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void I2C2_IRQHandler                    ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void SPI1_IRQHandler                    ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void SPI2_IRQHandler                    ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void USART1_IRQHandler                  ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void USART2_IRQHandler                  ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void USART3_4_LPUART1_IRQHandler        ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );
void CEC_IRQHandler                     ( void ) __attribute__( ( weak, alias( "Default_Handler" ) ) );


/*
*   STM32G071 Vector Table Definition
*/
uint32_t vectors[] __attribute__( ( section( ".isr_vector" ) ) ) =
{
    0x20009000,
    ( uint32_t ) Reset_Handler,
    ( uint32_t ) NMI_Handler,
    ( uint32_t ) HardFault_Handler,
    ( uint32_t ) 0,
    ( uint32_t ) 0,
    ( uint32_t ) 0,
    ( uint32_t ) 0,
    ( uint32_t ) 0,
    ( uint32_t ) 0,
    ( uint32_t ) 0,
    ( uint32_t ) SVC_Handler,
    ( uint32_t ) 0,
    ( uint32_t ) 0,
    ( uint32_t ) PendSV_Handler,
    ( uint32_t ) SysTick_Handler,
    ( uint32_t ) WWDG_IRQHandler,
    ( uint32_t ) PVD_IRQHandler,
    ( uint32_t ) RTC_TAMP_IRQHandler,
    ( uint32_t ) FLASH_IRQHandler,
    ( uint32_t ) RCC_IRQHandler,
    ( uint32_t ) EXTI0_1_IRQHandler,
    ( uint32_t ) EXTI2_3_IRQHandler,
    ( uint32_t ) EXTI4_15_IRQHandler,
    ( uint32_t ) UCPD1_2_IRQHandler,
    ( uint32_t ) DMA1_Channel1_IRQHandler,
    ( uint32_t ) DMA1_Channel2_3_IRQHandler,
    ( uint32_t ) DMA1_Ch4_7_DMAMUX1_OVR_IRQHandler,
    ( uint32_t ) ADC1_COMP_IRQHandler,
    ( uint32_t ) TIM1_BRK_UP_TRG_COM_IRQHandler,
    ( uint32_t ) TIM1_CC_IRQHandler,
    ( uint32_t ) TIM2_IRQHandler,
    ( uint32_t ) TIM3_IRQHandler,
    ( uint32_t ) TIM6_DAC_LPTIM1_IRQHandler,
    ( uint32_t ) TIM7_LPTIM2_IRQHandler,
    ( uint32_t ) TIM14_IRQHandler,
    ( uint32_t ) TIM15_IRQHandler,
    ( uint32_t ) TIM16_IRQHandler,
    ( uint32_t ) TIM17_IRQHandler,
    ( uint32_t ) I2C1_IRQHandler,
    ( uint32_t ) I2C2_IRQHandler,
    ( uint32_t ) SPI1_IRQHandler,
    ( uint32_t ) SPI2_IRQHandler,
    ( uint32_t ) USART1_IRQHandler,
    ( uint32_t ) USART2_IRQHandler,
    ( uint32_t ) USART3_4_LPUART1_IRQHandler,
    ( uint32_t ) CEC_IRQHandler,
};

/*
*   Private Function Definition
*/

/*!
*   @brief      This function handles the initialization of memory and calls main
*   @param[in]  void
*   @return     void
*/
[[noreturn]] void Reset_Handler( void )
{
    std::uint32_t data_size = (std::uint32_t)&_edata - (std::uint32_t)&_sdata;

    // Copy .data section to RAM
    std::copy( &_sidata, &_sidata + data_size, &_sdata );

    // Initialize the BSS  to zero
    std::fill( &_sbss, &_ebss, 0 );

    auto &SCB { *reinterpret_cast<stm32g071_regs::scb_register*>(ScsMemoryMap::ScbBase) };

    SCB.VTOR = 0x08000000U;

    // Call the main function
    main();

    // Main should never exit or return. Place the MCU in a while loop if this happens
    while( 1 )
    {
        __asm("nop");
    }
}

/*!
*   @brief      This functions is the default function when prototypes are not defined
*   @param[in]  void
*   @return     void
*/
void Default_Handler( void )
{
    while( 1 )
    {
        // Do nothing
    }
}