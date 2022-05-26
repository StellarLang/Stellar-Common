#include "value.hpp"

#include <iostream>

[[maybe_unused]] stellar::ValueType stellar::typeOf(Value& value) {
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

[[maybe_unused]] std::string stellar::typeString(Value &value) {
    switch (typeOf(value)) {
        case VT_NUMBER:
            return "number";
        case VT_BOOLEAN:
            return "boolean";
        case VT_NULL:
            return "null";
        case VT_STRING:
            return "string";
    }
}

void stellar::printValue(Value& value) {
    std::cout << asString(value);
}

std::string stellar::asString(Value &value) {
    return std::visit([value](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, double>)
            return std::to_string(std::get<double>(value));
        else if constexpr (std::is_same_v<T, bool>) {
            if (std::get<bool>(value)) return std::string("true");
            else return std::string("false");
        } else if constexpr (std::is_same_v<T, std::monostate>)
            return std::string("null");
        else if constexpr (std::is_same_v<T, std::string>)
            return std::get<std::string>(value);
    }, value);
}

[[maybe_unused]] double stellar::asNumber(Value &value) {
    return std::visit([value](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, double>)
            return std::get<double>(value);
        else if constexpr (std::is_same_v<T, bool>) {
            if (std::get<bool>(value)) return 1.0;
            else return 0.0;
        } else if constexpr (std::is_same_v<T, std::monostate>)
            return 0.0;
        else if constexpr (std::is_same_v<T, std::string>)
            return std::stod(std::get<std::string>(value));
    }, value);
}

[[maybe_unused]] bool stellar::asBool(Value &value) {
    return std::visit([value](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, double>) {
            double num = std::get<double>(value);
            return num != 0.0;
        } else if constexpr (std::is_same_v<T, bool>)
            return std::get<bool>(value);
        else if constexpr (std::is_same_v<T, std::monostate>)
            return false;
        else if constexpr (std::is_same_v<T, std::string>)
            return true; // strings are always truthy, bite me
    }, value);
}
