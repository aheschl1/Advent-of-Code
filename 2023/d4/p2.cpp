#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<unordered_set>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
    int result = 0;
    map<int, int> copies;
    string _; cin >> _;
    int card;
    while(cin >> card){
        char _; cin >> _;
        unordered_set<int> winning_numbers;
        while(!0){
            string win_num;
            cin >> win_num;
            if(win_num == "|") break;
            winning_numbers.insert(stoi(win_num));
        }
        int local_result = 0;
        while(!0){
            string num; cin >> num;
            if(num == "Card" || num == "\0") break;
            if(winning_numbers.find(stoi(num)) != winning_numbers.end()){
                local_result += 1;
            }
        }
        copies[card] += 1;
        while(local_result){
            copies[card+local_result] += copies[card];
            local_result -= 1;
        }
    }
    for(auto &entry : copies){
        result += entry.second;
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}