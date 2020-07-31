#ifndef CONSOLE_HPP
#define CONSOLE_HPP
#include <ncurses.h>
#include <phpcpp.h>

namespace Cvar1984
{
    class Console : public Php::Base
    {
        public:
            Console() = default;
            virtual ~Console() = default;
            void __construct (Php::Parameters &params)
            {
                initscr();
                if(!params.empty()) {
                    switch ((int)params[0]) {
                        case 1:
                            cbreak();
                            noecho();
                            curs_set(0);
                            break;
                        case 2:
                            cbreak();
                            noecho();
                            curs_set(1);
                        default:
                            break;
                    }
                }
            }
            void ncursesPrintw(Php::Parameters &params)
            {
                printw(params[0]);
                refresh();
                getch();
            }
            void __destruct()
            {
                endwin();
            }
    };
}
#endif
