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

bool check_valid(vvc engine, int r, int c){
    if(r + 1 < engine.size() && (engine[r+1][c] > '9' || engine[r+1][c] < '0') && engine[r+1][c] != '.'){
        return true;
    }else if(r + 1 < engine.size() && c + 1 < engine[r].size() && (engine[r+1][c+1] > '9'|| engine[r+1][c+1] < '0') && engine[r+1][c+1] != '.'){
        return true;
    }else if(r + 1 < engine.size() && c - 1 > 0 &&  (engine[r+1][c-1] > '9' || engine[r+1][c-1] < '0') && engine[r+1][c-1] != '.'){
        return true;
    }else if(r -1 > 0 && (engine[r-1][c] > '9'|| engine[r-1][c] < '0') && engine[r-1][c] != '.'){
        return true;
    }else if(r -1 > 0 && c + 1 < engine[r].size() && (engine[r-1][c+1] > '9'|| engine[r-1][c+1] < '0') && engine[r-1][c+1] != '.'){
        return true;
    }else if(r -1 > 0 && c - 1 > 0 && (engine[r-1][c-1] > '9'|| engine[r-1][c-1] < '0') && engine[r-1][c-1] != '.'){
        return true;        
    }else if(c - 1 > 0 && (engine[r][c-1] > '9'|| engine[r][c-1] < '0') && engine[r][c-1] != '.'){
        return true;       
    }else if(c + 1 < engine[r].size() && (engine[r][c+1] > '9'|| engine[r][c+1] < '0') && engine[r][c+1] != '.'){
        return true;       
    }
    return false;
}

int check_element(int &r, int &c, vvc &engine){
    if(engine[r][c] < '0' || engine[r][c] > '9'){
        c += 1;
        return -1;
    }
    vector<int> digits;
    bool valid = false;
    while(c < engine[r].size() && (engine[r][c] >= '0' && engine[r][c] <= '9')){
        valid = valid || check_valid(engine, r, c);
        digits.push_back(engine[r][c]-'0');
        c+=1;
    }
    if(valid){
        double result = 0;
        for(int i = 0; i < digits.size(); i++){
            double exp = digits.size() - i - 1;
            result += digits[i] * pow(10.0, exp);
        }
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
    
    vector<int> numbers;
    for(int r = 0; r < engine.size(); r++){
        int c = 0;
        while(c < engine[r].size()){
            int result = check_element(r, c, engine);
            if(result != -1){
                numbers.push_back(result);
            }
        }
    }
    int result = 0;
    for(int num : numbers){
        result += num;
    }
    cout << result << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}