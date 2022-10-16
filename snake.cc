class Snake 
{
  private:
    std::queue<Square> squares;
    std::set<Square> squares;
    Square dir;
  public:
    void grow();
    void move();
    void change_dir;
}
