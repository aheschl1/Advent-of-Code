#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
    int total_sum = 0;
    string line;
    while(cin >> line){
        int first = -1;
        int second = -1;
        for(char c : line){
            if(c >= '0' && c <= '9'){
                if(first == -1){
                    first = c - '0';
                }
                second = c - '0';
            }
        }
        int val = 10*first + second;
        total_sum += val;
    }
    cout << total_sum << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}