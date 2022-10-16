#pragma once

#include "constants.cc"
#include "square.cc"

#include <set>

class Snake;
class Fruit {
  private:
    Square location;
    int TTL=fruit_max_TTL;
    void reappear(std::set<Square>& snake_squares);
    void become_visible();
    char square_char;
  public:
    void become_invisible();
    bool is_visible() const;
    void tick(const Snake& snake);
    const Square& get_loc() const;
};
