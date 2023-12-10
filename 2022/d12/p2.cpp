#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>

typedef long long int ll;
typedef unsigned long long ull;
typedef std::vector<std::vector<char>> vvc;

using namespace std;

bool accesible(char start, char destination){
    return start == (destination + 1) || start < destination || start == destination;
}

pair<int, int> min_distance(map<int, int> &distances, set<int> &ignore){
    pair<int, int> minimum = make_pair(-1,-1);
    int min_d = INT16_MAX;
    int counter = 0;
    for(pair<int, int> p : distances){
        if(ignore.find(p.first) == ignore.end()){
            if(p.second < min_d){
                minimum = p;
                min_d = p.second;
            }
        }
    }
    return minimum;
}

map<int, int> shortest_path(map<int, vector<int>> &adjacency_list, int start){
    set<int> visited;
    vector<int> unvisted;
    map<int, int> distances;
    for(pair<int, vector<int>> p : adjacency_list){
        unvisted.push_back(p.first);
        if(p.first == start){
            distances[p.first] = 0;
            continue;
        }
        distances[p.first] = INT16_MAX;
    }
    while(visited.size() < adjacency_list.size()){
        pair<int, int> current = min_distance(distances, visited);
        if(current.first == -1 && current.second == -1){
            break;
        }
        for(int adjacent : adjacency_list[current.first]){
            //only perform if visited does not contain element
            if(visited.find(adjacent) != visited.end()){
                continue;
            }
            int old_distance = distances[adjacent];
            int new_distance = distances[current.first] + 1;
            if(new_distance < old_distance){
                distances[adjacent] = new_distance;
            }
        }
        //remove from unvisited move to visited.
        visited.insert(current.first);
    }
    return distances;
}

void solve(){
    map<int, vector<int>> adjacency_list;
    vvc height_map;
    string line;
    int start_vertex;
    vector<int> checks;
    //raw input
    int counter = 0;
    while(getline(cin, line)){
        vector<char> temp;
        for(char c : line){
            if(c == 13){
                continue;
            }
            if(c == 'S'){
                c = 'a';
            }else if(c == 'E'){
                start_vertex = counter;
                c = 'z';
            }
            if(c == 'a'){
                checks.push_back(counter);
            }
            temp.push_back(c);
            counter ++;
        }
        height_map.push_back(temp);
    }
    //fill adjacency matrix
    for(int r = 0; r < height_map.size(); r++){
        for(int c = 0; c < height_map[r].size(); c++){
            int id = c + r*(height_map[r].size());
            vector<int> temp;
            int t;
            char element;            
            //above
            if(r > 0){
                element = height_map[r-1][c];
                if(accesible(height_map[r][c], element)){
                    t = c + (r-1)*(height_map[r].size());
                    temp.push_back(t);
                }
            }
            //bellow
            if(r < height_map.size()-1){
                element = height_map[r+1][c];
                if(accesible(height_map[r][c], element)){
                    t = c + (r+1)*(height_map[r].size());
                    temp.push_back(t);
                }
            }
            //left
            if(c > 0){
                element = height_map[r][c-1];
                if(accesible(height_map[r][c], element)){
                    t = (c-1) + (r)*(height_map[r].size());
                    temp.push_back(t);
                }
            }
            //right
            if(c < height_map[r].size()-1){
                element = height_map[r][c+1];
                if(accesible(height_map[r][c], element)){
                    t = (c+1) + (r)*(height_map[r].size());
                    temp.push_back(t);
                }
            }
            adjacency_list[id] = temp;
        }
    }
    
    map<int, int> shortest = shortest_path(adjacency_list, start_vertex);
    int min = INT16_MAX;
    for(int i = 0; i < checks.size(); i ++){
        if(shortest[checks[i]] < min){
            min = shortest[checks[i]];
        }
    }
    cout << min << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}