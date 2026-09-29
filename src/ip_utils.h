#pragma once

#include <vector>
#include <tuple>
#include <string>
#include <cstdint>

using ip_tuple = std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>;

consteval ip_tuple generate_ip(std::uint32_t value);
constexpr bool validate_octet(std::uint32_t octet) noexcept;
std::vector<std::string> split(const std::string &str, char d);