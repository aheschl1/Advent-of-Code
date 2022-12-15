#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include <queue>

typedef long long int ll;
typedef unsigned long long ull;
typedef std::vector<std::vector<std::pair<int, bool>>> vvi;
using namespace std;


void displayMatrix(vvi &matrix){
    for(int r = 0; r < matrix.size(); r++){
        for(int c = 0; c < matrix[0].size(); c++){
            cout << matrix[r][c].second;
        }
        cout << endl;
    }
    cout << endl;
}

void transpose(vvi &matrix){
    vvi temp(matrix[0].size(), vector<pair<int, bool>>(matrix.size(), make_pair(0, false)));
    for(int r = 0; r < matrix.size(); r++){
        for(int c = 0; c < matrix[r].size(); c++){
            temp[c][r] = matrix[r][c];
        }
    }
    matrix = temp;
}

void reverse(vvi &matrix){
    for(int r = 0; r < matrix.size();r++){
        reverse(matrix[r].begin(),matrix[r].end());
    }
}

ull visible(vvi &matrix){
    ull count = 0;
    for(int r = 0; r < matrix.size(); r++){
        ull tempcount = 0;
        ll tallest = -1;
        for(int c = 0; c < matrix[r].size(); c++){
            if((matrix[r][c].first > tallest) && !matrix[r][c].second){
                tempcount ++;
                tallest = matrix[r][c].first;
                matrix[r][c].second = true;
            }else if(matrix[r][c].second && matrix[r][c].first > tallest){
                tallest = matrix[r][c].first;
            }
        }
        count += tempcount;
    }
    return count;
}

void solve(){
    //column99
    vvi matrix;
    string line;
    while(getline(cin, line)){
        vector<pair<int, bool>> temp;
        for(const char c : line.substr(0,line.size()-1)){
            temp.push_back(make_pair(c - '0', false));
        }
        matrix.push_back(temp);
    }
    ull totalcount = 0;
    //left
    totalcount += visible(matrix);
    //top
    transpose(matrix);
    totalcount += visible(matrix);
    transpose(matrix);
    //right
    reverse(matrix);
    totalcount += visible(matrix);
    reverse(matrix);
    //bottom
    transpose(matrix);
    reverse(matrix);
    totalcount += visible(matrix);
    reverse(matrix);
    transpose(matrix);

    cout << totalcount << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}