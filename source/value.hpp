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

    ValueType getType(Value&);
}