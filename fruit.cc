#include "constants.cc"
#include "square.cc"

#include <set>

class Fruit {
  private:
    Square location;
    int TTL;
    void reappear(std::set<Square>& snake_squares) {
      
    }
    char square_char;
  public:
    void disappear() {
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
