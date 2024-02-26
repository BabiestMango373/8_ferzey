#include <iostream>
 
using namespace std;
const int n = 8;
 
int board[n][n];
int results_number = 1;
 
// Board() - отображает доску.
void Board()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << ((board[i][j]) ? "Q " : ". ");
        }
        cout << '\n';
    }
}
 
// CheckQueen() - проверяет не стоит ли уже ферзь
bool СheckQueen(int a, int b)
{
    for(int i = 0; i < a; i++)
    {
        if(board[i][b])
        {
            return false;
        }
    }
    
    for(int i = 1; i <= a && b-i >= 0; i++)
    {
        if(board[a-i][b-i])
        {
            return false;
        }
    }
    
    for(int i = 1; i <= a && b+i < n; i++)
    {
        if(board[a-i][b+i])
        {
            return false;
        }
    }
    
    return true;
}
 
// Queen() - ищет результат решения
void Queen(int a)
{
    if(a == n)
    {
        Board();
        cout << "Result №" << results_number++ << "\n\n";
    }
    
    for(int i = 0; i < n; i++)
    {

        if(СheckQueen(a, i))
        {
            board[a][i] = 1;
            Queen(a+1);
            board[a][i] = 0;
        }
    }

}
 
int main()
{
    Queen(0);
    
    return 0;
}
