#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include <queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void checkCycle(int cycle, vector<int> &scores, ll &register_val){
    if(cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220){
        cout << cycle << ": " << register_val << endl;
        scores.push_back(register_val*cycle);
    }
}

void solve(){
    unsigned int cycle = 0;
    ll register_val = 1;
    vector<int> scores;
    string command;
    while(cin >> command){
        cycle++;
        checkCycle(cycle, scores, register_val);
        if(command == "addx"){
            int temp;
            cin >> temp;
            cycle++;
            checkCycle(cycle, scores, register_val);
            register_val+=temp;
        }
    }
    ll sum = 0;
    for(int i : scores){
        sum+=i;
    }
    cout << sum << endl;
    //Hello World
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}