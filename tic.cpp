#include <iostream>
using namespace std;
#include <map>
/*class Board{
    private:

    public: 
    void spaceOpen
} */
void spaceOpen(map<int, char> &board, int &position) {
    while(board.at(position) != ' ') {
        cout << "That spot is taken, choose another location" << endl;
        cin >> position;
        }
    }

void print(map<int, char> &board) {
    cout << board.at(1) << '|' << board.at(2) << '|' << board.at(3) << endl;
    cout << "-+-+-" << endl;
    cout << board.at(4) << '|' << board.at(5) << '|' << board.at(6) << endl;
    cout << "-+-+-" << endl;
    cout << board.at(7) << '|' << board.at(8) << '|' << board.at(9) << endl;
    cout << endl;
    cout << endl;
}

bool checkDraw(map<int, char> &board) {
    for(auto& [position, letter] : board) {
        if (board[position] == ' ') {
            return false;
            }
        }
    return true;
}

bool checkWin(map<int, char> &board)  {
    // for(auto& [position, letter] : board) {}
    if(board[1] == board[2] && board[1] == board[3] && board[1] != ' ') {
            return true;
        } else if(board[4] == board[5] && board[4] == board[6] && board[4] != ' ') {
            return true;
        } else if(board[7] == board[8] && board[7] == board[9] && board[7] != ' ') {
            return true;
        } else if(board[1] == board[4] && board[1] == board[7] && board[1] != ' ') {
            return true;
        } else if(board[2] == board[5] && board[2] == board[8] && board[2] != ' ') {
            return true;
        } else if(board[3] == board[6] && board[3] == board[9] && board[3] != ' ') {
            return true;
        } else if(board[1] == board[5] && board[1] == board[9] && board[1] != ' ') {
            return true;
        } else if(board[3] == board[5] && board[3] == board[7] && board[3] != ' ') {
            return true;
        } else {
            return false;
        }
}

/*
void checkNumber(int& position) {
    while(position > 9 || position < 1) {
            cout << "Please choose a number between 1 - 9!" << endl;
            cin >> position;
        }
    
}
*/

int insertMove(map<int, char> &board, int& position, char& letter) {
    print(board);
    if(letter == 'X') {
            cout <<  "Choose a move Player1: " << endl; 
        } else {
            cout <<  "Choose a move Player2: " << endl; 
        }
    while(cin >> position) {
        if(position <= 9 && position >= 1) {
            break;
        }
        cout << "Please choose a number between 1 - 9!" << endl;
    } 
    spaceOpen(board, position);
    // checkNumber(position);
    board.at(position) = letter;
    if(checkWin(board) == true) {
        if(letter == 'X') {
            print(board);
            cout << "Player1 Wins" << endl;
            return position;
        } else {
            print(board);
            cout << "Player2 Wins" << endl;
            return position;
        }
    } else if(checkDraw(board) == true) {
        print(board);
        cout << "It's a Draw" << endl;
        return position;
    } 
    print(board);
    return position;
}


int main() {
    map<int, char> board;
    map<int, char>::iterator itr;
    char letter = ' ';
    char lette = 'X';
    board.insert(pair<int, char>(1, letter));
    board.insert(pair<int, char>(2, letter));
    board.insert(pair<int, char>(3, letter));
    board.insert(pair<int, char>(4, letter));
    board.insert(pair<int, char>(5, letter));
    board.insert(pair<int, char>(6, letter));
    board.insert(pair<int, char>(7, letter));
    board.insert(pair<int, char>(8, letter));
    board.insert(pair<int, char>(9, letter));

    char Player1 = 'X';
    char Player2 = 'O';
    int position;
    int position2;

    while(checkDraw(board) == false && checkWin(board) == false) {
        insertMove(board, position, Player1);
        if(checkDraw(board) == true || checkWin(board) == true) {
            break;
        }
        insertMove(board, position, Player2);
    }

    return 0;
    }


