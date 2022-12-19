#include <iostream>
using namespace std;
#include <map>

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

void printStart() {
    cout << 1 << '|' << 2 << '|' << 3 << endl;
    cout << "-+-+-" << endl;
    cout << 4 << '|' << 5 << '|' << 6 << endl;
    cout << "-+-+-" << endl;
    cout << 7 << '|' << 8 << '|' << 9 << endl;
    cout << endl;
    cout << endl;
}

bool checkDraw(map<int, char> &board) {
    for(auto const& [position, letter] : board) {
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

bool checkMove(map<int, char> &board, char move)  {
    // for(auto& [position, letter] : board) {}
    if(board[1] == board[2] && board[1] == board[3] && board[1] == move) {
            return true;
        } else if(board[4] == board[5] && board[4] == board[6] && board[4] == move) {
            return true;
        } else if(board[7] == board[8] && board[7] == board[9] && board[7] == move) {
            return true;
        } else if(board[1] == board[4] && board[1] == board[7] && board[1] == move) {
            return true;
        } else if(board[2] == board[5] && board[2] == board[8] && board[2] == move) {
            return true;
        } else if(board[3] == board[6] && board[3] == board[9] && board[3] == move) {
            return true;
        } else if(board[1] == board[5] && board[1] == board[9] && board[1] == move) {
            return true;
        } else if(board[7] == board[5] && board[7] == board[3] && board[7] == move) {
            return true;
        } else {
            return false;
        }
}

int insertMove(map<int, char> &board, int& position, char letter) {
    if(letter == 'O') {
        cout <<  "Choose a move Player1: " << endl; 
        while(cin >> position) {
            if(position <= 9 && position >= 1) {
                break;
            }
            cout << "Please choose a number between 1 - 9!" << endl;
        } 
    } 
    spaceOpen(board, position);
    board.at(position) = letter;
    if(checkWin(board) == true) {
        if(letter == 'O') {
            print(board);
            cout << "Player1 Wins" << endl;
            return position;
        } else {
            print(board);
            cout << "Bot Wins" << endl;
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

int miniMax(map<int, char> &board, char letter, bool isMax) {
    int bestScore;
    int score;
    if(checkMove(board, 'X') == true) {
        // Bot2
        return 100;
    } else if(checkMove(board, 'O') == true) {
        // Player
        return -100;
    } else if(checkDraw(board) == true) {
        return 0;
    }

    if(isMax == true) { // computer p3laying to find Max score
        bestScore = -1000;
        for(auto const& [position, letter] : board) {
            if (board[position] == ' ') { // Minimizing Case where we choose the lowest score our player can move 
                board[position] = 'X';
                score = miniMax(board, 'X', false);
                board[position] = ' ';
                if(score > bestScore) {
                    bestScore = score;
                }
            }
        } 
        return bestScore;
    } else { 
        bestScore = 1000;
        for(auto const& [position, letter] : board) {
            if (board[position] == ' ') {
                board[position] = 'O';
                score = miniMax(board, 'O', true);
                board[position] = ' ';
                if(score < bestScore) {
                    bestScore = score;
                }
            }
        }
        return bestScore;
    }
}

void playerMove(map<int, char> &board, int& position) {
    insertMove(board, position, 'O');
}

void compMove(map<int, char> &board, int& position) {
    int bestScore = -1000;
    int bestMove = 0;

    for(auto const& [position, letter] : board) {
        if (board[position] == ' ') {
            board[position] = 'X';
            int score = miniMax(board, 'X', false); // score is always more than bestScore -- > problem in miniMax Function
            board[position] = ' ';
            if(score > bestScore) {
                bestScore = score; 
                bestMove = position;
            }
        }
    }
    insertMove(board, bestMove, 'X'); 
}
// algorithm for comp goes 1, 2, 3, 4, 5, ...

int main() {
    map<int, char> board;
    map<int, char>::iterator itr;
    char letter = ' ';
    char lette = 'X';
    int position;

    board.insert(pair<int, char>(1, letter));
    board.insert(pair<int, char>(2, letter));
    board.insert(pair<int, char>(3, letter));
    board.insert(pair<int, char>(4, letter));
    board.insert(pair<int, char>(5, letter));
    board.insert(pair<int, char>(6, letter));
    board.insert(pair<int, char>(7, letter));
    board.insert(pair<int, char>(8, letter));
    board.insert(pair<int, char>(9, letter));

    printStart();
    while(checkDraw(board) == false && checkWin(board) == false) {
        playerMove(board, position);
        if(checkDraw(board) == true || checkWin(board) == true) {
            break;
        }
        compMove(board, position);
    }
    return 0;
}


