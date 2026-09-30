#pragma once

#include <vector>
#include <tuple>
#include <string>
#include <cstdint>

using ip_tuple = std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>;

consteval ip_tuple generate_ip(std::uint32_t value) {

    
    for(unsigned int i = 0; i < 10000; i++) {
        value ^= value << 13;
        value ^= value >> 17;
        value *= 0x45D9F3B;
        value ^= value >> 16;
    }
    auto A = static_cast<std::uint8_t>((value >> 24) & 255);
    auto B = static_cast<std::uint8_t>((value >> 16) & 255);
    auto C = static_cast<std::uint8_t>((value >> 8) & 255);
    auto D = static_cast<std::uint8_t>(value & 255);
    return {A, B, C, D};
}

constexpr bool validate_octet(int octet) noexcept
{
    return octet <= 255 && octet >= 0;
}

std::vector<std::string> split(const std::string &str, char d);