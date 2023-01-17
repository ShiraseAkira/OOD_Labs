#pragma once
#include <string>
/**
 * ÷елевой класс объ€вл€ет интерфейс, с которым может работать клиентский код.
 */
class Target {
public:
    virtual ~Target() = default;

    virtual std::string Request() const {
        return "Target: The default target's behavior.";
    }
};
