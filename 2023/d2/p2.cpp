#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<sstream>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

// 12 red, 13 green, 14 blue

void solve(){
    string line;
    int result = 0;
    int current_game = -1;
    int blues = 0, greens = 0, reds = 0;
    int current_number;
    for (string line; getline(cin, line, ' ');) {
        std::stringstream ss(line);
        getline(ss, line, '\n');
        if(line[line.size()-1] == ':'){
            if(current_game != -1){
                result += reds*blues*greens;
            }
            line.pop_back();
            current_game = stoi(line);
            blues = 0;
            greens = 0;
            reds = 0;
        }else if(line[line.size()-1] >= '0' && line[line.size()-1] <= '9'){
            current_number = stoi(line);
        }else{
            if(line[line.size()-1] == ';' || line[line.size()-1] == ','){
                line.pop_back();
            }
            if(line == "blue"){
                blues = max(blues, current_number);
            }else if(line == "red"){
                reds = max(reds, current_number);
            }else if(line == "green"){
                greens = max(greens, current_number);
            }else{
                // cout << "======" << endl;
                // cout << line << endl;
            }
        }
    }
    result += reds*blues*greens;
    // cout << current_game << ' ' << (game_works(blues, greens, reds) && !early_death) << endl;
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}