#include <iostream>
#include <vector>

using namespace std;

string b[1005]; // plansza
int n, m; // szerokosc i wysokosc / kolumny i wiersze
pair<int, int> dir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // mozliwe kierunki
bool visited[1005][1005]; // tablica oznaczajaca zbadane pola
bool is_found = false;

bool is_inside(int row, int col){ 
    return row >= 0 && row < m && col >= 0 && col < n; // sprawdza czy miescimy sie w planszy
}

void dfs(int row, int col){
    visited[row][col] = true;
    for (int i = 0; i < 4; i++) {
        int r2 = row + dir[i].first;
        int c2 = col + dir[i].second;
        if(is_inside(r2, c2) && !visited[r2][c2]) {
            if(b[r2][c2] == 'w') is_found = true;
                else if(b[r2][c2] == '-') dfs(r2, c2);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int start_row = 0;
    int start_col = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (b[i][j] == 'o') {
                start_row = i; 
                start_col = j;
                break;
            }
        }
    }

    dfs(start_row, start_col);
    
    if(is_found) cout << "TAK\n";
    else cout << "NIE\n";
    
}