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

bool endsWith(const string& s, const string& suffix){
    return s.size() >= suffix.size() && s.substr(s.size() - suffix.size()) == suffix;
}

void trim(string &s){
    if(s[0] == ' '){
        s = s.substr(1);
    }
    if(s[s.size()-1] == ' '){
        s = s.substr(0, s.size()-1);
    }
}

vector<string> split(const string& s, const string& delimiter, const bool removeEmptyEntries = false)
{
    vector<string> tokens;
    for (size_t start = 0, end; start < s.length(); start = end + delimiter.length()){
         size_t position = s.find(delimiter, start);
         end = position != string::npos ? position : s.length();

         string token = s.substr(start, end - start);
         if (!removeEmptyEntries || !token.empty())
         {
            trim(token);
            tokens.push_back(token);
         }
    }
    if (!removeEmptyEntries &&(s.empty() || endsWith(s, delimiter))){tokens.push_back("");}
    return tokens;
}

void solve(){
    map<int, vector<int>> cave_map;
    char garbage;
    string line;
    int max_y = 0;
    while(getline(cin, line)){
        vector<string> temp = split(line, "->");
        for(int i = 0; i < temp.size()-1; i++){
            //todo - connect points
            string t1, t2;
            t1 = temp[i];
            t2 = temp[i+1];
            int x, y, x2, y2;
            x = stoi(t1); t1 = t1.substr(4); y = stoi(t1);
            x2 = stoi(t2); t2 = t2.substr(4); y2 = stoi(t2);
            if(y > max_y){
                max_y = y;
            }
            if(y2 > max_y){
                max_y = y2;
            }
            if(!count(cave_map[y].begin(), cave_map[y].end(), x)){
                cave_map[y].push_back(x);
            }
            if(!count(cave_map[y2].begin(), cave_map[y2].end(), x2)){
                cave_map[y2].push_back(x2);
            }
            if(y == y2){
                if(x > x2){
                    for(int n = x-1; n > x2; n--){
                        cave_map[y].push_back(n);
                    }
                }else{
                    for(int n = x+1; n < x2; n++){
                        cave_map[y].push_back(n);
                    }
                }
            }
            if(x == x2){
                if(y > y2){
                    for(int n = y-1; n > y2; n--){
                        cave_map[n].push_back(x);
                    }
                }else{
                    for(int n = y+1; n < y2; n++){
                        cave_map[n].push_back(x);
                    }   
                }
                
            }
        }
    }
    //sand starts 500,0

    pair<int, int> sand_pos = make_pair(500, 0);
    bool loop = true;
    int sand_count = 0;

    while(loop){
        if(find(cave_map[sand_pos.second+1].begin(), cave_map[sand_pos.second+1].end(), sand_pos.first) == cave_map[sand_pos.second+1].end()){
            sand_pos.second ++;
        }else if(find(cave_map[sand_pos.second+1].begin(), cave_map[sand_pos.second+1].end(), sand_pos.first-1) == cave_map[sand_pos.second+1].end()){
            sand_pos.first--;
            sand_pos.second++;
        }else if(find(cave_map[sand_pos.second+1].begin(), cave_map[sand_pos.second+1].end(), sand_pos.first+1) == cave_map[sand_pos.second+1].end()){
            sand_pos.first++;
            sand_pos.second++;
        }else{
            //rest. create new sand.
            sand_count ++;
            cave_map[sand_pos.second].push_back(sand_pos.first);
            sand_pos = make_pair(500, 0);
            continue;
        }
        if(sand_pos.second > max_y){
            break;
        }
    }
    cout << sand_count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}