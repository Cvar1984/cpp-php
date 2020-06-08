#include <phpcpp.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <Kalkulator.hpp>

using namespace Php;

void clear_screen()
{
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
}

extern "C" {
    PHPCPP_EXPORT void *get_module() {
        static Extension extension("cvar1984", "1.0");

        Class<Kalkulator> kalkulator("Kalkulator");

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
        extension.add<clear_screen>("clrscr");
        extension.add(std::move(kalkulator));
        return extension;
    }
}
