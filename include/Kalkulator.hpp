#ifndef KALKULATOR_HPP
#define KALKULATOR_HPP
#include <phpcpp.h>

namespace Cvar1984
{

    class Kalkulator : public Php::Base
    {
        public:
            Kalkulator() = default;
            virtual ~Kalkulator() = default;
            // magic method
            std::string __toString()
            {
                return "v0.1";
            }
            // normal method
            Php::Value swap(Php::Parameters &params)
            {
                Php::Value temp = params[0];
                params[0] = params[1];
                params[1] = temp;
                return true;
            }
            Php::Value tambah(Php::Parameters &params)
            {
                return params[0] + params[1];
            }
            Php::Value kurang(Php::Parameters &params)
            {
                return params[0] - params[1];
            }
            Php::Value bagi(Php::Parameters &params)
            {
                return params[0] / params[1];
            }
            Php::Value kali(Php::Parameters &params)
            {
                return params[0] * params[1];
            }
    };
}
#endif
