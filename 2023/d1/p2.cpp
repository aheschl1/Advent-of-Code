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
        for(int i = 0; i < line.size(); i++){
            char c = line[i];
            if(c >= '0' && c <= '9'){
                if(first == -1){
                    first = c - '0';
                }
                second = c - '0';
            }else{
                int found = -1;
                if(c == 'o' && line.substr(i, 3) == "one"){
                    found = 1;
                }
                if(c == 't'){
                   if(line.substr(i, 3) == "two"){
                        found = 2;
                   }else if(line.substr(i, 5) == "three"){
                        found = 3;
                   } 
                }
                if(c == 'f'){
                   if(line.substr(i, 4) == "four"){
                        found = 4;
                   }else if(line.substr(i, 4) == "five"){
                        found = 5;
                   } 
                }
                if(c == 's'){
                   if(line.substr(i, 3) == "six"){
                        found = 6;
                   }else if(line.substr(i, 5) == "seven"){
                        found = 7;
                   } 
                }
                if(c == 'e' && line.substr(i, 5) == "eight"){
                    found = 8;   
                }
                if(c == 'n' && line.substr(i, 4) == "nine"){
                    found = 9;
                }
                if(found == -1){
                    continue;
                }
                if(first == -1){
                    first = found;
                }
                second = found;
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