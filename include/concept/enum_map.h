#ifndef ENUM_MAP_H
#define ENUM_MAP_H

#include <concepts>
#include <type_traits>

#include "class_object_map.h"

template<typename T>
concept Enum = (std::is_enum_v<T>);

template<auto... objects>
concept enums = (std::is_enum_v<decltype(objects)> && ...);

template<auto... enums>
class EnumMap : private ClassObjectMap<enums...> {
public:
    template<Enum T>
    constexpr static T getValue() {
        if constexpr (ClassObjectMap<enums...>::template isKey<T>()) {
            return ClassObjectMap<enums...>::template getValue<T>();
        } else {
            return static_cast<T>(0);
        }
    }
};

#endif