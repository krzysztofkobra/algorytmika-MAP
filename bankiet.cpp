#include <iostream>
#include <vector>

using namespace std;

int guests_n; // liczba gosci
vector<int> guests; // vector przetrzymujacy podane po kolei numerki gosci
bool visited[30002];
int tables_counter;

void dfs(int guest_number){
    visited[guest_number] = true;
    int next_guest = guests[guest_number - 1];
    if(!visited[next_guest]){
        dfs(next_guest);
    }
}

int main(){
    cin >> guests_n;
    for(int i = 1; i <= guests_n; i++){
        int guest;
        cin >> guest;
        guests.push_back(guest);
    }

    for (int i = 1; i <= guests_n; i++) {
        if (!visited[i]) {
            dfs(i); 
            tables_counter++; 
        }
    }

    cout << tables_counter << "\n";
}