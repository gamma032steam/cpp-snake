#include <cassert>

class Snake 
{
  private:
    std::queue<Square> squares;
    std::set<Square> squares;
    Square dir;
  public:
    void grow();
    void move();
    void change_dir(char dir) {
      switch(dir) {
        case 'w':
          dir = {0,-1}
          break;
        case 'a':
          dir = {-1,0}
          break;
        case 's':
          dir = {0,1}
          break;
        case 'd':
          dir = {1,0}
          break;
        default:
          assert(false);
      }
    }
    void tick();
}
