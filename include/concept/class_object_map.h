#ifndef CLASS_OBJECT_MAP_H
#define CLASS_OBJECT_MAP_H

#include <type_traits>

template <auto first_object, auto... rest_objects> class ClassObjectMap {
    template <auto, auto...> friend class ClassObjectMap;

  public:
    constexpr static ClassObjectMap<rest_objects...> rest =
        ClassObjectMap<rest_objects...>();

    template <class T> constexpr static bool isKey() {
        return std::is_same_v<T, decltype(first_object)> ||
               rest.template isKey<T>();
    }

    template <class T> constexpr static T getValue() {
        if constexpr (std::is_same_v<T, decltype(first_object)>) {
            return first_object;
        } else {
            return rest.template getValue<T>();
        }
    }

  private:
    template <auto object> constexpr static bool checkDuplicateClasses() {
        return std::is_same_v<decltype(object), decltype(first_object)> ||
               rest.template checkDuplicateClasses<object>();
    }

    static_assert(!rest.template checkDuplicateClasses<first_object>(),
                  "Multiple objects of same class aren't allowed in template "
                  "declaration!");
};

template <auto last_object> class ClassObjectMap<last_object> {
    template <auto, auto...> friend class ClassObjectMap;

    template <class T> constexpr static bool isKey() {
        return std::is_same_v<T, decltype(last_object)>;
    }

    template <class T> constexpr static T getValue() {
        static_assert(std::is_same_v<T, decltype(last_object)>,
                      "The key is invalid!");
        return last_object;
    }

  private:
    template <auto object> constexpr static bool checkDuplicateClasses() {
        return std::is_same_v<decltype(object), decltype(last_object)>;
    }
};

#endif