#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include <queue>
#include<cmath>

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef vector<vector<char>> vvc;

void display(vvc &matrix){
    for(int i = 0; i < 6; i++){
        for(int x = 0; x < 40; x++){
            cout << matrix[i][x];
        }
        cout << endl;
    }
}

void draw_pixel(vvc &matrix, int pixel, int register_val){
    int row = pixel/40;
    int column = pixel;
    while(column >= 40){
        column -= 40;
    }
    char draw = '.';    cout << column << endl;

    if(register_val-1 == column || register_val == column || register_val+1 == column){
        draw = '#';
    }
    matrix[row][column] = draw;
}

void solve(){
    unsigned int cycle = 0;
    ll register_val = 1;
    string command;
    
    vvc matrix(6, vector<char>(40, '.'));
    while(cin >> command){
        cycle++;
        draw_pixel(matrix, cycle-1, register_val);
        if(command == "addx"){
            int temp;
            cin >> temp;
            cycle++;
            draw_pixel(matrix, cycle-1, register_val);
            register_val+=temp;
        }
    }
    display(matrix);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}