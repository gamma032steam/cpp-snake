#include "constants.cc"

struct Square {
  const int x;
  const int y;
  
  Square operator+(const Square s1) const{
    return Square{s1.x+x, s1.y+y};
  }
  
  bool in_board() const {
    return !(x<0 || y<0 || x>=board_size || y>=board_size);
  }
  
  Square(int x, int y): x(x), y(y) {}
  
  // Input format is "1,2"
  Square(std::string square) {
    assert(square.size() == 3);
    assert(std::isdigit(square[0]));
    assert(square[1] == ",");
    assert(std::isdigit(square[2]));
    x = std::tostring(square[0]);
    y = std::tostring(square[0]);
  }
};
