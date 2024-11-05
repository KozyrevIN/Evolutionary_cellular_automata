#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "../../../settings/compile_time_settings.h"

namespace Policies {

namespace Commands {
template <Enum T> auto adl_is_member_of_command(T &&) -> void;
}

namespace Helper {
template <Enum T, typename = void>
struct is_member_of_command : std::false_type {};

template <Enum T>
struct is_member_of_command<T, decltype(adl_is_member_of_command(
                                   std::declval<T>()))> : std::true_type {};

template <typename T>
concept is_command_v = (std::is_enum_v<T> && is_member_of_command<T>::value);

template <auto object>
concept is_active_command_v =
    (is_command_v<decltype(object)> && decltype(object)::Off != object);

template <ClassObjectMap map>
concept not_last_v = requires() { map.rest; };

template <typename T>
concept Command = is_command_v<T>;

} // namespace Helper

} // namespace Policies

namespace CPUKernel {

template <Policies::PolicyMap policy_map>
class Extractor : public decltype(policy_map) {
  public:
    constexpr static unsigned int commandsCount =
        Extractor::getCommandsCount(policy_map);

    template <Policies::Helper::Command T>
    constexpr static unsigned int idx = Extractor::template getCommandIdx<T>(policy_map);

  private:
    template <auto first_object, auto... rest_objects>
    constexpr static unsigned int
    getCommandsCount(ClassObjectMap<first_object, rest_objects...> map) {
        bool is_active_command =
            Policies::Helper::is_active_command_v<first_object>;

        if constexpr (Policies::Helper::not_last_v<map>) {
            return getCommandsCount(map.rest) + is_active_command;
        } else {
            return 1 + is_active_command;
        }
    }

    template <Policies::Helper::Command T, auto first_object,
              auto... rest_objects>
    constexpr static unsigned int
    getCommandIdx(ClassObjectMap<first_object, rest_objects...> map) {
        constexpr bool is_active_command =
            Policies::Helper::is_active_command_v<first_object>;
        constexpr bool is_same_as_T = std::is_same_v<decltype(first_object), T>;

        if constexpr (is_active_command && is_same_as_T) {
            return 0;
        } else if constexpr (Policies::Helper::not_last_v<map>) {
            return getCommandIdx<T>(map.rest) + is_active_command;
        } else {
            return is_active_command + 1;
        }
    }
};

constexpr static Extractor<Policies::policy_map> config;

} // namespace CPUKernel

#endif