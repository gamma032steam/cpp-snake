#pragma once

#include <cassert>
#include <deque>
#include <set>
#include "square.cc"

class Fruit;
class Snake 
{
  private:
    std::deque<Square> squares_deque;
    std::set<Square> squares_set;
    Square dir;
    void grow();
    void move();
  public:
    void change_dir(char new_dir);
    void tick(const Fruit& fruit);
    bool is_on_square(const Square& square) const;
};
