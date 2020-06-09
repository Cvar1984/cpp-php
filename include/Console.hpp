#ifndef CONSOLE_HPP
#define CONSOLE_HPP
#include <ncurses.h>
#include <phpcpp.h>

using namespace Php;

class Console : public Base
{
    public:
        Console() = default;
        virtual ~Console() = default;
        void __construct (Parameters &params)
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
        void ncursesPrintw(Parameters &params)
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
#endif
