#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<unordered_set>
#include<set>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;
typedef vector<vector<char>> vvc;
typedef set<pair<int, int>> spii;
// left over mess from p1; oh well
map<pair<int, int>, vector<int>> gear_count;

pair<int, int> check_valid(vvc engine, int r, int c){
    if(r + 1 < engine.size() && (engine[r+1][c] > '9' || engine[r+1][c] < '0') && engine[r+1][c] != '.'){
        return make_pair(r+1, c);
    }else if(r + 1 < engine.size() && c + 1 < engine[r].size() && (engine[r+1][c+1] > '9'|| engine[r+1][c+1] < '0') && engine[r+1][c+1] != '.'){
        return make_pair(r+1, c+1);
    }else if(r + 1 < engine.size() && c - 1 > 0 &&  (engine[r+1][c-1] > '9' || engine[r+1][c-1] < '0') && engine[r+1][c-1] != '.'){
        return make_pair(r+1, c-1);
    }else if(r -1 > 0 && (engine[r-1][c] > '9'|| engine[r-1][c] < '0') && engine[r-1][c] != '.'){
        return make_pair(r-1, c);
    }else if(r -1 > 0 && c + 1 < engine[r].size() && (engine[r-1][c+1] > '9'|| engine[r-1][c+1] < '0') && engine[r-1][c+1] != '.'){
        return make_pair(r-1, c+1);
    }else if(r -1 > 0 && c - 1 > 0 && (engine[r-1][c-1] > '9'|| engine[r-1][c-1] < '0') && engine[r-1][c-1] != '.'){
        return make_pair(r-1, c-1);
    }else if(c - 1 > 0 && (engine[r][c-1] > '9'|| engine[r][c-1] < '0') && engine[r][c-1] != '.'){
        return make_pair(r, c-1);  
    }else if(c + 1 < engine[r].size() && (engine[r][c+1] > '9'|| engine[r][c+1] < '0') && engine[r][c+1] != '.'){
        return make_pair(r, c+1);
    }
    return make_pair(-1, -1);
}

int check_element(int &r, int &c, vvc &engine){
    if(engine[r][c] < '0' || engine[r][c] > '9'){
        c += 1;
        return -1;
    }
    vector<int> digits;
    pair<int, int> location = make_pair(-1, -1);
    while(c < engine[r].size() && (engine[r][c] >= '0' && engine[r][c] <= '9')){
        pair<int, int> v = check_valid(engine, r, c);
        if(v.first != -1 && engine[v.first][v.second] == '*'){
            location = v;
        }
        digits.push_back(engine[r][c]-'0');
        c+=1;
    }
    if(location.first != -1){
        double result = 0;
        for(int i = 0; i < digits.size(); i++){
            double exp = digits.size() - i - 1;
            result += digits[i] * pow(10.0, exp);
        }
        gear_count[location].push_back((int)result);
        return (int)result;
    }
    return -1;
    
}

void solve(){
    vvc engine;
    string line;
    while(cin >> line){
        engine.push_back(vector<char>(line.begin(), line.end()));
    }
    
    for(int r = 0; r < engine.size(); r++){
        int c = 0;
        while(c < engine[r].size()){
            check_element(r, c, engine);
        }
    }
    int result = 0;
    for(pair<pair<int, int>, vector<int>> entry : gear_count){
        if(entry.second.size() == 2){
            result += entry.second[0] * entry.second[1];
        }
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}