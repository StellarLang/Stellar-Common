#pragma once

#include <type_traits>
#include <variant>
#include <string>

namespace stellar {
    enum ValueType {
        VT_NUMBER,
        VT_BOOLEAN,
        VT_NULL,
        VT_STRING
    };

    using Value = std::variant<
            double, // number
            bool, // boolean
            std::monostate, // null
            std::string // string
    >;

    [[maybe_unused]] ValueType typeOf(Value& value);
    [[maybe_unused]] std::string typeString(Value& value);
    void printValue(Value& value);
    std::string asString(Value& value);
    [[maybe_unused]] double asNumber(Value& value);
    [[maybe_unused]] bool asBool(Value& value);
}