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
    string _; cin >> _;
    while(cin >> _){
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
                if(local_result){
                    local_result *= 2;
                }else{
                    local_result = 1;
                }
            }
        }
        result += local_result;
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}