#include "constants.cc"
#include "square.cc"

#include <set>

class Fruit {
  private:
    Square location;
    int TTL=fruit_max_TTL;
    void reappear(std::set<Square>& snake_squares) {
      Square new_loc = Square::get_random();
      while (snake_squares.find(new_loc) != snake_squares.end()) {
        new_loc = Square::get_random();
      }
      location = new_loc;
      become_visible();
    }
    void become_visible() {
      square_char = fruit_char;
    }
    char square_char;
  public:
    void become_invisible() {
      square_char = empty_square_char;
    }
    bool is_visible() const {
      return square_char == fruit_char;
    }
    
    void tick(std::set<Square>& snake_squares) {
      TTL--;
      if (TTL==0) {
        TTL = fruit_max_TTL;
        reappear(snake_squares);
      }
    }
    
    const Square& get_loc() const {
      return location;
    }
};
