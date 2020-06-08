#ifndef KALKULATOR_HPP
#define KALKULATOR_HPP
#include <phpcpp.h>

using namespace Php;

class Kalkulator : public Base
{
    public:
        // constructor
        Kalkulator() = default;
        // destructor
        virtual ~Kalkulator() = default;
        // magic method
        std::string __toString()
        {
            return "v0.1";
        }
        // normal method
        Value swap(Parameters &params)
        {
            Value temp = params[0];
            params[0] = params[1];
            params[1] = temp;
            return true;
        }
        Value tambah(Parameters &params)
        {
            return params[0] + params[1];
        }
        Value kurang(Parameters &params)
        {
            return params[0] - params[1];
        }
        Value bagi(Parameters &params)
        {
            return params[0] / params[1];
        }
        Value kali(Parameters &params)
        {
            return params[0] * params[1];
        }
};
#endif
