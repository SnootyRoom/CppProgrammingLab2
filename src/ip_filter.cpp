#include "ip_utils.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstdint>
#include <format>


int main(int argc, char const *argv[])
{
    try
    {   
        // lambda for print ip
        auto print_ip = [](const auto &ip)
        {
            std::cout << +std::get<0>(ip) << "."
                << +std::get<1>(ip) << "."
                << +std::get<2>(ip) << "."
                << +std::get<3>(ip) << "\n";
        };

        constexpr ip_tuple target_ip = generate_ip(986751920);

        // Write ip from console to ip_pool
        std::vector<ip_tuple> ip_pool;

        // lambda for tuples
        auto vector_to_tuple = [&](const std::vector<std::string> &v)
        {
            ip_tuple tuple;
            auto o1 = std::stoi(v.at(0));
            auto o2 = std::stoi(v.at(1));
            auto o3 = std::stoi(v.at(2));
            auto o4 = std::stoi(v.at(3));

            if (!validate_octet(o1) || !validate_octet(o2) || !validate_octet(o3) || !validate_octet(o4))
                throw std::runtime_error(std::format("Invalid ip: {}.{}.{}.{}", o1, o2, o3, o4));

            return std::make_tuple(
                static_cast<std::uint8_t>(o1),
                static_cast<std::uint8_t>(o2),
                static_cast<std::uint8_t>(o3),
                static_cast<std::uint8_t>(o4));
        };

        for (std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(vector_to_tuple(split(v.at(0), '.')));
        }

        // reverse lexicographically sort
        std::sort(ip_pool.begin(), ip_pool.end(),
            [](const auto &a, const auto &b)
                {
                    return a > b;
                });

        // Ip output to console
        std::for_each(ip_pool.begin(), ip_pool.end(), print_ip);

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        std::cout << "Target Ip\n";
        print_ip(target_ip);

        // search target_ip in ip_pool
        if (std::find(ip_pool.begin(), ip_pool.end(), target_ip) == ip_pool.end())
            std::cout << "Not find\n";
        else
            std::cout << "Find\n";

        

        // ip = filter(1)
        std::cout<<"Ip filter by first byte\n";
        std::for_each(ip_pool.begin(), ip_pool.end(), [&](const auto &ip){
            if(std::get<0>(ip) == 1)
                print_ip(ip);
        });

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // ip = filter(46, 70)
        std::cout<<"Ip filter by first and second bytes\n";
        std::for_each(ip_pool.begin(), ip_pool.end(), [&](const auto &ip){
            if(std::get<0>(ip) == 46 && std::get<1>(ip) == 70)
                print_ip(ip);
        });

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // ip = filter_any(46)
        std::cout<<"Ip filter by any byte\n";
        std::for_each(ip_pool.begin(), ip_pool.end(), [&](const auto &ip){
            if(std::get<0>(ip) == 46 || std::get<1>(ip) == 46 || std::get<2>(ip) == 46 || std::get<3>(ip) == 46)
                print_ip(ip);
        });
        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
