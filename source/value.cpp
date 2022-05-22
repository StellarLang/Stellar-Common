#include "value.hpp"

stellar::ValueType stellar::getType(Value& value) {
    std::visit([](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, double>)
            return VT_NUMBER;
        else if constexpr (std::is_same_v<T, bool>)
            return VT_BOOLEAN;
        else if constexpr (std::is_same_v<T, std::monostate>)
            return VT_NULL;
        else if constexpr (std::is_same_v<T, std::string>)
            return VT_STRING;
    }, value);
}