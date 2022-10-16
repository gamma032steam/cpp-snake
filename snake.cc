#include <cassert>
#include <deque>
#include <set>
#include "square.cc"
#include "fruit.cc"

class Snake 
{
  private:
    std::deque<Square> squares_deque;
    std::set<Square> squares_set;
    Square dir;
    void grow() {
      // Add beyond head square
      Square head = squares_deque.back() + dir;
      squares_deque.push_back(head);
      squares_set.insert(head);
    }
    void move() {
      // Remove tail square
      squares_set.erase(squares_deque.front());
      squares_deque.pop_front();
      // Add beyond head square
      grow();
    }
  public:
    void change_dir(char new_dir) {
      switch(new_dir) {
        case 'w':
          dir = {0,-1};
          break;
        case 'a':
          dir = {-1,0};
          break;
        case 's':
          dir = {0,1};
          break;
        case 'd':
          dir = {1,0};
          break;
        default:
          assert(false);
      }
    }
    void tick(Square& fruit_loc, bool fruit_is_visible) {
      if ((squares_deque.front() == fruit_loc) && fruit_is_visible) {
        grow();
      } else {
        move();
      }
    }
    bool is_on_square(const Square& square) const{
      return squares_set.find(square) != squares_set.end();
    }
};
