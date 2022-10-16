#include "constants.cc"
#include "square.cc"

class Fruit {
  private:
    Square location;
    int TTL;
    void reappear();
  public:
    char square_char;
    
    void disappear() {
      square_char = empty_square_char;
    }
    bool is_visible() const {
      return square_char == fruit_char;
    }
    void tick() {
      TTL--;
      if (TTL==0) {
        TTL = fruit_max_TTL;
        reappear();
      }
    }
};
