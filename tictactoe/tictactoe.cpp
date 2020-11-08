#include <iostream>
#include <vector>

class Player {
  public:
    Player(char id) : id(id) {};
    char id;
  
};



class tictactoe {
  
  std::vector<std::vector<char>> board;
  public:
  tictactoe(int row = 3, int  col = 3) {
    board.resize(row, std::vector<char> (col, '-'));
  }
  
  void printBoard() const {
    for (int i = 0; i < board.size(); i++) {
      //declare j here to print row
      int j = 0;
      for (j = 0; j < board.size() - 1; j++) {
        std::cout << board[i][j] << "|";
      } 
        //require endl to print row
        std::cout << board[i][j]<<std::endl;
    }
  }
  
  bool play(int row, int col, Player p) {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
      return false;
    if (board[row][col] == '-') {
      board[row][col] = p.id;
      return true;
    }
    return false;
  }
  
  
};

int main() {
  int row, col;
  Player p1('x');
  Player p2('o');
  tictactoe t;
  int count = 0;
  while(true) {
    Player temp = count % 2 == 0 ? p1 : p2; 
    
    std::cout << "Enter row col player " << temp.id << ":";
    std::cin >> row >> col;
    
    if(t.play(row,col,temp)) {
      t.printBoard();
      count++;
    }
  }
  
  
}

