#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>

#define SIZE 3
#define HUMAN_PALYER 'O'
#define AI_PLAYER 'X'

using namespace std;

// storage for mapping each row data
// example --> if X at (1,1) then we increment row 1 by 1 and column 1 by 1 (row[1] = 1 && column[1] = 1)
// X at (2 ,1) then we increment row 2 by 1 and column 1 by 1  (row[2] = 1 && column[1] = 2)
// X at (0, 1) then we increment row 0 by 1 and column 1 by 1 (row[0] = 1 && column[1] = 3) here column[1] is fullied all by X meaning X won..
unordered_map<int, int> user_rows;
unordered_map<int, int> user_cols;
int user_diag;
int user_antiDiag;
unordered_map<int, int> ai_rows;
unordered_map<int, int> ai_cols;
int ai_diag;
int ai_antiDiag;
unordered_map<char, int> scores;
int counter = 0;
 

 
char check(vector<vector<char>> &board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                if (board[i][0] == HUMAN_PALYER)
                {
                    return 'O';
                }
                else if(board[i][0] == AI_PLAYER)
                {
                    return 'X';
                }
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {
                if (board[0][i] == HUMAN_PALYER)
                {
                    return 'O';
                }
                else if(board[0][i] == AI_PLAYER)
                {
                    return 'X';
                }
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[1][1] == HUMAN_PALYER)
        {
            return 'O';
        }
        else if(board[1][1] == AI_PLAYER)
        {
            return 'X';
        }
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
    {
        if (board[1][1] == HUMAN_PALYER)
        {
            return 'O';
        }
        else if(board[1][1] == AI_PLAYER)
        {
            return 'X';
        }
    }
    return '\0';
}

bool isMovesLeft(vector<vector<char>> &board)
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='-')
                return true;
    return false;
}
 

 int miniMax(vector<vector<char>> &board, int alpha, int beta, bool isMaximizing)
{
    counter++;
     char result = check(board);
     if(result){  
        return scores[result];
     }
     if(isMovesLeft(board)==false){
        return 0;
     }
      
     if(isMaximizing){
        int bestScore = INT_MIN;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '-'){
                    board[i][j] = AI_PLAYER;
                    int score = miniMax(board, alpha, beta, false); 
                    bestScore = max(bestScore, score);  
                    alpha = max(bestScore, alpha);
                    board[i][j] = '-';
                 }
                 if(alpha >= beta){
                    break;
                }
            }
        }
        return bestScore;
     }
     else{
        int bestScore  = INT_MAX;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '-'){
                    board[i][j] = HUMAN_PALYER;
                    int score = miniMax(board, alpha, beta, true); 
                    bestScore = min(bestScore, score);  
                    beta = min(beta, bestScore);
                    board[i][j] = '-';
                      
                }
                if(alpha >= beta){
                    break;
                }
            }
        }
        return bestScore;
     }
}
 

bool checkWinner(int i = -1, int j = -1, char symbol = 'T')
{

    if (symbol == HUMAN_PALYER)
    {
        user_rows[i]++;
        user_cols[j]++;
        if (i == j)
            user_diag++;
        if (i + j == SIZE - 1)
            user_antiDiag++;
    }
    else if (symbol == AI_PLAYER)
    {
        ai_rows[i]++;
        ai_cols[j]++;
        if (i == j)
            ai_diag++;
        if (i + j == 3)
            ai_antiDiag++;
    }
    if (ai_antiDiag == 3 || ai_diag == 3 || ai_cols[j] == 3 || ai_rows[i] == 3)
    {
        return true;
    }
    if (user_antiDiag == 3 || user_diag == 3 || user_cols[j] == 3 || user_rows[i] == 3)
    {
        return true;
    }
    return false;
}
 
// returns a pair of AI putting its O becoz we need to use th position to checkWinner
void ai(vector<vector<char>> &board)
{
    int bestVal = -10000;
    pair<int, int> x{-1,-1};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                 board[i][j] = AI_PLAYER;  
                 int score = miniMax(board, INT_MIN, INT_MAX, false);
                 board[i][j] = '-';
                
                 if(bestVal < score){ 
                     bestVal = score;
                     x.first = i;
                     x.second = j;
                 } 
            }
        }
    }
    cout << counter << endl;
    board[x.first][x.second] = AI_PLAYER;
     
}

void print_grid(vector<vector<char>> &board)
{
    int counter = 1;
    for (int i = 0; i < 3; i++)
    {
        cout << "***********" << endl;
        for (int j = 0; j < 3; j++)
        {
             if(board[i][j] != '-'){
                cout << board[i][j] << " | ";
             }else{
                cout << counter << " | ";
             }
            counter++;
        }
        cout << endl;
    }
    cout << "***********" << endl;
}

 
 

int main()
{
    vector<vector<char>> grid;

    scores['X'] = 10;
    scores['O'] = -10;
    

    for (int i = 0; i < SIZE; i++)
    {
        vector<char> c;
        for (int j = 0; j < SIZE; j++)
        {
            c.push_back('-');
        }
        grid.push_back(c);
    }
    int x, y;
    int i, j;

    print_grid(grid);
    while (1)
    {
        cout << "User turn: ";
        cin >> x;
        i = (x-1)/3;
        j = (x-1)%3;
        grid[i][j] = HUMAN_PALYER;
        char value1 = check(grid);
        if (value1 == HUMAN_PALYER)
        {
            cout << "Winner Human" << endl;
            break;
        } 

        if(isMovesLeft(grid) == false){
            cout << "Its a tie" << endl;
            break;
        }

        ai(grid); 
        char value2 = check(grid);
        if (value2 == AI_PLAYER)
        {
            cout << "Winner AI" << endl;
            break;
        }
        print_grid(grid);
    }
    
    print_grid(grid);
}

 