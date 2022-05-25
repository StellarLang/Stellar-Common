#include "value.hpp"

#include <iostream>

stellar::ValueType stellar::typeOf(Value& value) {
    return std::visit([](auto&& arg) {
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

void stellar::printValue(Value& value) {
    std::visit([value](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, double>)
            std::cout << std::get<double>(value);
        else if constexpr (std::is_same_v<T, bool>) {
            if (std::get<bool>(value)) std::cout << "true";
            else std::cout << "false";
        } else if constexpr (std::is_same_v<T, std::monostate>)
            std::cout << "null";
        else if constexpr (std::is_same_v<T, std::string>)
            std::cout << std::get<std::string>(value);
    }, value);
}