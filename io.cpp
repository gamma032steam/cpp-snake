#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <sys/ioctl.h>

#if HAVE_STROPTS_H
#include <stropts.h>
#endif

// todo: make it work for windows https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive

class Board
{
public:
    bool running = true;
    int step = 0;

public:
    // keyboard reader https://www.flipcode.com/archives/_kbhit_for_Linux.shtml
    // https://stackoverflow.com/questions/27968446/test-whether-key-is-pressed-without-blocking-on-linux
    int khbit() const
    {
        struct timeval tv;
        fd_set fds;
        tv.tv_sec = 0;
        tv.tv_usec = 0;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
        return FD_ISSET(STDIN_FILENO, &fds);
    }

    void nonblock(int state) const
    {
        struct termios ttystate;
        tcgetattr(STDIN_FILENO, &ttystate);

        if (state == 1)
        {
            ttystate.c_lflag &= (~ICANON & ~ECHO); // Not display character
            ttystate.c_cc[VMIN] = 1;
        }
        else if (state == 0)
        {
            ttystate.c_lflag |= ICANON;
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
    }

    bool keyState(int key) const // Use ASCII table
    {
        bool pressed;
        int i = khbit(); // Alow to read from terminal
        if (i != 0)
        {
            char c = fgetc(stdin);
            if (c == (char)key)
            {
                pressed = true;
            }
            else
            {
                pressed = false;
            }
        }

        return pressed;
    }

    void print_board()
    {
        const int BOARD_SIZE = 8;
        string output;
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                output = output + to_string(step);
            }
            output = output + "\n";
        }
        std::cout << output;
        step = step + 1;
    }

    void render()
    {
        // windows way
        // system("cls");
        // linux way
        std::system("clear");
        print_board();
    }

    int kb_input()
    {
        nonblock(1);
        int i = 0;
        while (!i)
        {
            if (keyState(31)) // 32 in ASCII table correspond to Space Bar
            {
                i = 1;
            }
        }
        nonblock(0);
        if (i == 1)
        {
            cout << "pressed space";
        }
    }

    void start()
    {
        // 1000000 micro-seconds is 1 second
        const int framesPerSecond = 1;
        const int microToSeconds = 1000000;
        const double delay = microToSeconds / framesPerSecond;

        while (running)
        {
            render();
            kb_input();
            usleep(delay);
        };
    }
};

int main()
{
    Board b = Board();
    b.start();
    usleep(5 * 1000000);
    b.running = false;
}
