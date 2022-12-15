#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include <queue>

typedef long long int ll;
typedef unsigned long long ull;
typedef std::vector<std::vector<int>> vvi;
using namespace std;


void displayMatrix(vvi &matrix){
    for(int r = 0; r < matrix.size(); r++){
        for(int c = 0; c < matrix[0].size(); c++){
            cout << matrix[r][c];
        }
        cout << endl;
    }
    cout << endl;
}

ull getScenery(vvi &matrix, int c, int r){
    ull score = 1;
    int my_height = matrix[r][c];

    if(r > 0){
        int total_count = 0;
        int tallest = -1;
        //up
        for(int check_r = r - 1; check_r >= 0; check_r--){
            total_count++;
            tallest = matrix[check_r][c];
            if(tallest >= my_height){
                break;
            }
        }
        score *= total_count;
    }
    if(r < matrix.size() - 1){
        int total_count = 0;
        int tallest = -1;
        //down
        for(int check_r = r + 1; check_r < matrix.size(); check_r++){
            total_count++;
            tallest = matrix[check_r][c];
            if(tallest >= my_height){
                break;
            }
        }
        score *= total_count;
    }
    if(c > 0){
        //left
        int total_count = 0;
        int tallest = -1;
        for(int check_c = c - 1; check_c >= 0; check_c--){
            total_count++;
            tallest = matrix[r][check_c];
            if(tallest >= my_height){
                break;
            }
        }
        score *= total_count;

    }

    if(c < matrix[0].size() - 1){
        int tallest = -1;
        //right
        int total_count = 0;
        for(int check_c = c + 1; check_c < matrix[0].size(); check_c++){
            total_count++;
            tallest = matrix[r][check_c];
            if(tallest >= my_height){
                break;
            }
            
        }
        score *= total_count;
    }
    return score;

}


void solve(){
    //column99
    vvi matrix;
    string line;
    ull maxview = 0;
    while(getline(cin, line)){
        vector<int> temp;
        for(const char c : line.substr(0,line.size()-1)){
            temp.push_back(c - '0');
        }
        matrix.push_back(temp);
    }

    ull largest = 0;

    for(int r = 0; r < matrix.size(); r++){
        for(int c = 0; c < matrix[r].size(); c++){
            ull scenery = getScenery(matrix, c, r);
            if(scenery > largest){
                largest = scenery;
            }
        }
    }
    cout << largest << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}