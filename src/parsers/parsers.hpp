#pragma once

#include <regex>
#include <string>
#include <iostream>

#include "src/result.hpp"
#include "src/utils/utils.hpp"

namespace parser {
    static const unsigned short FULL_MATCH = 0;

    class Parser {
    protected:
        bool strictMode;
        std::regex pattern;

    public:
        Parser();

        //Parser(bool, std::regex);       // strictMode, pattern
        virtual std::regex getPattern() const { return std::regex(); };

        virtual parse::ParsedResult extract(std::string &, const std::smatch &, const posix_time::ptime &, long) {
            parse::ParsedResult tmp{};
            return tmp;
        }

        Result execute(std::string &, posix_time::ptime &);

        ~Parser();
    };
}
