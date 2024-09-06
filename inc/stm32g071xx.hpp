/*!
    @file   stm32g071xx.hpp
    @brief  This file contains all the register definitions and memory mapping
            For the STM32G071xx devices
*/

/******************************************************************************
*   Include Files
******************************************************************************/
#include <utils.hpp>

/******************************************************************************
*   STM32G071XX Namespace
******************************************************************************/
namespace STM32G071XX
{

    /*! @brief  STM32G071XX Memory Map
    *   @enum   MemoryMap
    */
    enum class MemoryMap : std::uint32_t
    {
        FLASH_Base      = 0x08000000U,      //!< Starting address for the Flash
        RAM_Base        = 0x20000000U,      //!< Starting address for the RAM
        APB_Base        = 0x40000000U,      //!< Starting address for the APB Peripherals
        AHB_Base        = 0x40020000U,      //!< Starting address for the AHB Peripherals
        IO_PORT_Base    = 0x50000000U       //!< Starting address for the I/O Port Peripherals
    };

    /*! @brief  STM32G071XX GPIO Ports
    *   @enum   GpioPeriphAddress
    */
    enum class GpioPeriphAddr : std::uint32_t
    {
        GPIOA_Base   = utils_memoryAt( MemoryMap::IO_PORT_Base, 0x00000000U ),  //!< GPIOA Address
        GPIOB_Base   = utils_memoryAt( MemoryMap::IO_PORT_Base, 0x00000400U ),  //!< GPIOB Address
        GPIOC_Base   = utils_memoryAt( MemoryMap::IO_PORT_Base, 0x00000800U ),  //!< GPIOC Address
        GPIOD_Base   = utils_memoryAt( MemoryMap::IO_PORT_Base, 0x00000C00U ),  //!< GPIOD Address
        GPIOE_Base   = utils_memoryAt( MemoryMap::IO_PORT_Base, 0x00001400U ),  //!< GPIOF Address
    };
    
}