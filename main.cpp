#include <phpcpp.h>
#include <unistd.h>
#include <iostream>
#include <sys/ioctl.h>
#include <termcolor.hpp>
#include <Kalkulator.hpp>
#include <Console.hpp>

using namespace Php;

// general utils
void clear_screen()
{
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
}

void printclr(Parameters &params)
{
    switch((int)params[1]) {
        case 1:
            std::cout
                << termcolor::red
                << params[0]
                << termcolor::reset
                << std::endl;
            break;
        case 2:
            std::cout
                << termcolor::green
                << params[0]
                << termcolor::reset
                << std::endl;
            break;
        case 3:
            std::cout
                << termcolor::blue
                << params[0]
                << termcolor::reset
                << std::endl;
            break;

    }
}

extern "C" {
    PHPCPP_EXPORT void *get_module() {
        static Extension extension("cvar1984", "1.0");

        Class<Kalkulator> kalkulator("Cvar1984\\Kalkulator");
        Class<Console> console("Cvar1984\\Console");

        kalkulator.method<&Kalkulator::swap>("swap", {
                ByRef("a", Type::Numeric),
                ByRef("b", Type::Numeric)
                });
        kalkulator.method<&Kalkulator::tambah>("tambah", {
                ByVal("a", Type::Numeric),
                ByVal("b", Type::Numeric)
                });
        kalkulator.method<&Kalkulator::kurang>("kurang", {
                ByVal("a", Type::Numeric),
                ByVal("b", Type::Numeric)
                });
        kalkulator.method<&Kalkulator::bagi>("bagi", {
                ByVal("a", Type::Numeric),
                ByVal("b", Type::Numeric)
                });
        kalkulator.method<&Kalkulator::kali>("kali", {
                ByVal("a", Type::Numeric),
                ByVal("b", Type::Numeric)
                });
        console.method<&Console::__construct>("__construct", {
                ByVal("a", Type::Numeric, false)
                });
        console.method<&Console::ncursesPrintw>("printw", {
                ByVal("a", Type::String)
                });
        console.method<&Console::__destruct>("__destruct");
        extension.add<clear_screen>("clrscr");
        extension.add<printclr>("printclr", {
                ByVal("a", Type::String),
                ByVal("b", Type::Constant)
                });
        extension.add(Constant("TERM_RED", 1));
        extension.add(Constant("TERM_GREEN", 2));
        extension.add(Constant("TERM_BLUE", 3));
        extension.add(std::move(kalkulator));
        extension.add(std::move(console));
        return extension;
    }
}
