#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include <sstream>      // std::stringstream

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

// 12 red, 13 green, 14 blue
bool game_works(int blues, int greens, int reds){
    return blues <= 14 && greens <= 13 && reds <= 12;
}

void solve(){
    string line;
    int result = 0;
    int current_game = -1;
    int blues, greens, reds;
    int current_number;
    bool check_game = false;
    bool early_death = false;
    for (string line; getline(cin, line, ' ');) {
        std::stringstream ss(line);
        getline(ss, line, '\n');
        if(check_game){
            check_game = false;
            early_death = early_death || !game_works(blues, greens, reds);
            blues = 0;
            greens = 0;
            reds = 0;
        }
        if(line[line.size()-1] == ':'){
            if(current_game != -1){
                result += (game_works(blues, greens, reds) && !early_death) ? current_game : 0;
                // cout << current_game << ' ' << (game_works(blues, greens, reds) && !early_death) << endl;
            }
            line.pop_back();
            current_game = stoi(line);
            early_death = false;
            blues = 0;
            greens = 0;
            reds = 0;
        }else if(line[line.size()-1] >= '0' && line[line.size()-1] <= '9'){
            current_number = stoi(line);
        }else{
            check_game = line[line.size()-1] == ';';
            if(check_game || line[line.size()-1] == ','){
                line.pop_back();
            }
            if(line == "blue"){
                blues += current_number;
            }else if(line == "red"){
                reds += current_number;
            }else if(line == "green"){
                greens += current_number;
            }else{
                // cout << "======" << endl;
                // cout << line << endl;
            }
        }
    }
    result += (game_works(blues, greens, reds) && !early_death) ? current_game : 0;
    // cout << current_game << ' ' << (game_works(blues, greens, reds) && !early_death) << endl;
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}