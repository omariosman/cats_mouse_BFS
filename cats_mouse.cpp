
#include<bits/stdc++.h>
using namespace std;

/*
    Will the mouse escape from the Cats?
    5 Feb - 2022
    Omar Osman
*/

int Mouse[100][100];
int Cats[100][100];
int r, c;

void BFS(vector<pair<int, int>> V,int arr[100][100]){

    memset(arr, 63, sizeof(Mouse));

    queue<pair<int, int>> Q;

    for (auto P: V){
        arr[P.first][P.second] = 0;
        Q.push(P);
    }

    while(Q.size()){
        int i, j;
        tie(i, j) = Q.front();
        Q.pop();
        int di = 0, dj = -1;
        for (int k = 0; k < 4; k++){
            int ni = i + di;
            int nj = j + dj;
            if (ni > -1 && ni < r && nj > -1 && nj < c){
                if (arr[ni][nj] > arr[i][j] + 1){
                    arr[ni][nj] = arr[i][j] + 1;
                    Q.emplace(ni, nj);
                }
            }
            swap(di, dj);
            if (k == 1){
                dj = 1;
            }
        }
    }


}

int main(){
    
    int t, a, b;
    cin >> r >> c;
    cin >> t;

    while (t--){
        vector<pair<int, int>> C, M;
   
        cin >> a >> b;
        a--, b--;
        M.emplace_back(a, b);
        for (int i =0; i < 2; i++){
            cin >> a >> b;
            a--, b--;
            C.emplace_back(a,b);
        }
        BFS(M, Mouse);
        BFS(C, Cats);
        bool can_escape = false;
        for (int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1){
                    if (Mouse[i][j] < Cats[i][j]){
                        can_escape = true;
                    }
                }
            }
        }

        if (can_escape){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        

    }


    return 0;
}



