#include <cstdint>
#include <utility>

template <class T>
static constexpr bool is_scoped_enum = !std::is_convertible_v<T, std::underlying_type_t<T>> && std::is_enum_v<T>;

template <typename Enum, typename = std::enable_if_t<is_scoped_enum<Enum>>>
constexpr auto to_underlying(Enum t_e) noexcept {
	return static_cast<std::underlying_type_t<Enum>>(t_e);
}

template <typename Base, typename Offset>
constexpr auto memory_at(Base b, Offset o) {
	if constexpr (std::is_enum_v<Base>) {
		return to_underlying(b) + o;
	} else {
		return b + o;
	}
}

/*!
*   @brief  Cortex-M0 Plus System Control Space Memory Map
*   @enum   ScsMemoryMap
*/
enum class ScsMemoryMap : std::uint32_t
{
    ScsBase         = 0xE000E000U,
    SysTickBase     = memory_at( ScsBase, 0x0010U ),
    NvicBase        = memory_at( ScsBase, 0x0100U ),
    ScbBase         = memory_at( ScsBase, 0x0D00U ),
};

/*!
*   @brief  Cortex-M0 Plus Peripheral Memory Map
*   @enum   PeriphMemoryMap
*/
enum class PeriphMemoryMap : std::uint32_t
{
    FlashBase       = 0x08000000U,
    SramBase        = 0x20000000U,
    ApbPeriphBase   = 0x40000000U,
    IoPortBase      = 0x50000000U,
    AhbPeriphBase   = memory_at( ApbPeriphBase, 0x20000U ),
};

/*!
*   @brief Cortex-M0 Plus AHB Peripherals
*   @enum   AhbPeriphAddr
*/
enum class AhbPeriphAddr : std::uint32_t
{
    Dma1        = memory_at( PeriphMemoryMap::AhbPeriphBase, 0x0000U ),
    Dma1Mux     = memory_at( PeriphMemoryMap::AhbPeriphBase, 0x0800U ),
    Rcc         = memory_at( PeriphMemoryMap::AhbPeriphBase, 0x1000U ),
    Exti        = memory_at( PeriphMemoryMap::AhbPeriphBase, 0x1800U ),
    FlashR      = memory_at( PeriphMemoryMap::AhbPeriphBase, 0x2000U ),
    Crc         = memory_at( PeriphMemoryMap::AhbPeriphBase, 0x3000U ),
};

/*!
*   @brief  Cortex-M0 Plus Input/Output Peripherals
*   @enum   GpioPeriphAddr
*/
enum class GpioPeriphAddr : std::uint32_t
{
    GpioA   = memory_at( PeriphMemoryMap::IoPortBase, 0x0000U ),
    GpioB   = memory_at( PeriphMemoryMap::IoPortBase, 0x0400U ),
    GpioC   = memory_at( PeriphMemoryMap::IoPortBase, 0x0800U ),
    GpioD   = memory_at( PeriphMemoryMap::IoPortBase, 0x0C00U ),
    GpioF   = memory_at( PeriphMemoryMap::IoPortBase, 0x1400U ),
};

namespace stm32g071_regs
{
    using device_register = volatile std::uint32_t;

    /*!
    *   @brief  Structure Type to Access the System Control Block
    */
   struct scb_register
   {
        device_register CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
        device_register ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
        device_register VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
        device_register AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
        device_register SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
        device_register CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
        device_register RESERVED1;
        device_register SHP[2U];                /*!< Offset: 0x01C (R/W)  System Handlers Priority Registers. [0] is RESERVED */
        device_register SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
   };

    /*!
    *   @brief Reset and Clock Control Register Structure
    */
    struct rcc_register
    {
        device_register CR;          /*!< RCC Clock Sources Control Register,                                     Address offset: 0x00 */
        device_register ICSCR;       /*!< RCC Internal Clock Sources Calibration Register,                        Address offset: 0x04 */
        device_register CFGR;        /*!< RCC Regulated Domain Clocks Configuration Register,                     Address offset: 0x08 */
        device_register PLLCFGR;     /*!< RCC System PLL configuration Register,                                  Address offset: 0x0C */
        device_register RESERVED0;   /*!< Reserved,                                                               Address offset: 0x10 */
        device_register RESERVED1;   /*!< Reserved,                                                               Address offset: 0x14 */
        device_register CIER;        /*!< RCC Clock Interrupt Enable Register,                                    Address offset: 0x18 */
        device_register CIFR;        /*!< RCC Clock Interrupt Flag Register,                                      Address offset: 0x1C */
        device_register CICR;        /*!< RCC Clock Interrupt Clear Register,                                     Address offset: 0x20 */
        device_register IOPRSTR;     /*!< RCC IO port reset register,                                             Address offset: 0x24 */
        device_register AHBRSTR;     /*!< RCC AHB peripherals reset register,                                     Address offset: 0x28 */
        device_register APBRSTR1;    /*!< RCC APB peripherals reset register 1,                                   Address offset: 0x2C */
        device_register APBRSTR2;    /*!< RCC APB peripherals reset register 2,                                   Address offset: 0x30 */
        device_register IOPENR;      /*!< RCC IO port enable register,                                            Address offset: 0x34 */
        device_register AHBENR;      /*!< RCC AHB peripherals clock enable register,                              Address offset: 0x38 */
        device_register APBENR1;     /*!< RCC APB peripherals clock enable register1,                             Address offset: 0x3C */
        device_register APBENR2;     /*!< RCC APB peripherals clock enable register2,                             Address offset: 0x40 */
        device_register IOPSMENR;    /*!< RCC IO port clocks enable in sleep mode register,                       Address offset: 0x44 */
        device_register AHBSMENR;    /*!< RCC AHB peripheral clocks enable in sleep mode register,                Address offset: 0x48 */
        device_register APBSMENR1;   /*!< RCC APB peripheral clocks enable in sleep mode register1,               Address offset: 0x4C */
        device_register APBSMENR2;   /*!< RCC APB peripheral clocks enable in sleep mode register2,               Address offset: 0x50 */
        device_register CCIPR;       /*!< RCC Peripherals Independent Clocks Configuration Register,              Address offset: 0x54 */
        device_register RESERVED2;   /*!< Reserved,                                                               Address offset: 0x58 */
        device_register BDCR;        /*!< RCC Backup Domain Control Register,                                     Address offset: 0x5C */
        device_register CSR;         /*!< RCC Unregulated Domain Clock Control and Status Register,               Address offset: 0x60 */
    };

    /*!
    *   @brief General Purpoer I/O
    */
    struct gpio_registers
    {
        device_register MODER;       /*!< GPIO port mode register,               Address offset: 0x00      */
        device_register OTYPER;      /*!< GPIO port output type register,        Address offset: 0x04      */
        device_register OSPEEDR;     /*!< GPIO port output speed register,       Address offset: 0x08      */
        device_register PUPDR;       /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
        device_register IDR;         /*!< GPIO port input data register,         Address offset: 0x10      */
        device_register ODR;         /*!< GPIO port output data register,        Address offset: 0x14      */
        device_register BSRR;        /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
        device_register LCKR;        /*!< GPIO port configuration lock register, Address offset: 0x1C      */
        device_register AFR[2U];      /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
        device_register BRR;         /*!< GPIO Bit Reset register,               Address offset: 0x28      */
    };
}