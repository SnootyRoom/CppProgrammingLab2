#include "ip_utils.h"

consteval ip_tuple generate_ip(std::uint32_t value)
{
    for (unsigned int i = 0; i < 10000; i++)
    {
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

constexpr bool validate_octet(std::uint32_t octet) noexcept
{
    return octet <= 255;
}

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    auto stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}