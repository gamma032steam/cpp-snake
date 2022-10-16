class Snake 
{
  private:
    std::queue<Square> squares;
    Square dir;
  public:
    void move();
    void change_dir;
}
