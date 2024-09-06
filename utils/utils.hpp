/*!
    @file   utils.hpp
    @brief  This file contains various utility functions that can be used
*/

/******************************************************************************
*   Include Files
******************************************************************************/
#include <cstdint>
#include <utility>

/******************************************************************************
*   Private Function Definitions
******************************************************************************/

/*! @brief Check if the enum is scoped
*/
template <class T>
static constexpr bool isScopedEnum = !std::is_convertible_v<T, std::underlying_type_t<T>> && std::is_enum_v<T>;

/*! @brief      Function to check the underlying type of the enum
*   @param[in]  Enum
*
*   @return     Static casted value to the underlying type of the Enum
*/
template <typename Enum, typename = std::enable_if_t<isScopedEnum<Enum>>>
static constexpr auto convertToUnderlyingType( Enum t_e ) noexcept
{
    return static_cast<std:::underlying_type_t<Enum>( t_e );
}

/******************************************************************************
*   Public Function Definitions
******************************************************************************/

/*! @brief      This function takes the base memory and adds the peripheral offset
*   @param[in]  b Base Address
*   @param[in]  o Peripheral Offset Address
*
*   @return     Memory address of the peripheral
*/
template <typename Base, typename Offset>
constexpr auto utils_memoryAt( Base b, Offset o )
{
    if constexpr( std::is_enum_v<Base> )
    {
        return convertToUnderlyingType( b ) + o;
    }
    else
    {
        return b + o;
    }
}