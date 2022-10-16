#include "constants.cc"
#include <ctype.h>
#include <string>
#include <cassert>
#include <random>

class Square {
  public:
    int x;
    int y;
    
    Square operator+(const Square s1) const{
      return Square{s1.x+x, s1.y+y};
    }
    
    operator std::string() const {
      return std::to_string(x) + "," + std::to_string(y);
    }
    
    bool operator==(const Square& s1) {
      return s1.x == x && s1.y == y;
    }
    
    bool in_board() const {
      return !(x<0 || y<0 || x>=board_size || y>=board_size);
    }
    
    Square(int x, int y): x(x), y(y) {}
  
    // Input expected is : "1,2"
    // TODO Accept multidigit nums
    Square(std::string square) {
      assert(square.size() == 3);
      assert(std::isdigit(square[0]));
      assert(square[1] == ',');
      assert(std::isdigit(square[2]));
      x = int(square[0]-'0');
      y = int(square[2]-'0');
    }
    
    static Square get_random() {
      int x = rand() % (board_size+1);
      int y = rand() % (board_size+1);
      return {x,y};
    }
};
