#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<climits>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

struct valve{
    string id;
    int flowrate;
    float getRatio(int distance){
        return flowrate / (distance + 1);
    }
};

bool endsWith(const string& s, const string& suffix){
    return s.size() >= suffix.size() && s.substr(s.size() - suffix.size()) == suffix;
}

void trim(string &s){
    if(s[0] == ' ' || s[0] == 13){
        s = s.substr(1);
    }
    if(s[s.size()-1] == ' ' || s[s.size()-1] == 13){
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

pair<string, int> min_distance(map<string, int> &distances, set<string> &visited){
    pair<string, int> val;
    int min_d = INT_MAX;
    for(pair<string, int> p : distances){
        if(visited.find(p.first) == visited.end()){
            if(p.second < min_d){
                min_d = p.second;
                val = p;
            }
        }
    }
    return val;
}

//basically disjkstras
pair<map<string, int>, string> best_ratios(map<string, vector<string>> &adjacency_list, map<string, valve> &valves, set<string> &skip, string start){
    set<string> visited;
    map<string, int> distances;
    for(pair<string, vector<string>> p : adjacency_list){
        if(p.first == start){
            distances[p.first] = 0;
        }else{
            distances[p.first] = INT_MAX;
        }
    }
    while(visited.size() < adjacency_list.size()){
        pair<string, int> current = min_distance(distances, visited);
        for(int i =0; i < adjacency_list[current.first].size(); i++){
            string adjacent = adjacency_list[current.first][i];
            int current_distance = distances[adjacent];
            int new_distance = current.second + 1;
            if(new_distance < current_distance && visited.find(adjacent) == visited.end()){
                distances[adjacent] = new_distance;
            }
        }
        visited.insert(current.first);
    }

    int max_flow = INT_MIN;
    int min_distance = INT_MAX;
    float max_ratio = INT_MIN;
    string ideal;
    for(pair<string, int> p : distances){
        if(skip.find(p.first) == skip.end()){
            if(p.second < min_distance && valves[p.first].flowrate > 0){
                min_distance = distances[p.first];
                max_ratio = valves[p.first].getRatio(p.second*p.second);
                ideal = p.first;
            }
            else if(valves[p.first].getRatio(p.second) > max_ratio){
                min_distance = distances[p.first];
                max_ratio = valves[p.first].getRatio(p.second);
                ideal = p.first;
            }
        }
    }
    return make_pair(distances, ideal);
}

void solve(){
    map<string, vector<string>> adjacency_list;
    map<string, valve> valves;
    int visited = 0;

    string line;
    while(getline(cin, line)){
        valve new_valve;

        string name = line.substr(6, 2);
        new_valve.id = name;
        int fre = line.find(';');
        string frst = line.substr(23, line.length()-fre);
        int flow_rate = stoi(frst);

        new_valve.flowrate = flow_rate;
        if(flow_rate == 0){
            visited ++;
        }

        line = line.substr(line.find(';'));
        int child_s = line.find('s') + 2;
        int child_e = line.find('\n') - child_s;
        string childs = line.substr(child_s, child_e);
        vector<string> children = split(childs, ",");

        trim(name);
        valves[name] = new_valve;

        for(string name_c : children){
            trim(name_c);
            adjacency_list[name].push_back(name_c);
        }
    }
    string current = "AA";
    int mins_taken = 0;
    int total_pressure = 0;
    set<string> skip;

    //solve - potential issue: < 30
    while(mins_taken <= 30){
        if(visited < valves.size()){
            pair<map<string, int>, string> ratios = best_ratios(adjacency_list, valves, skip, current);
            map<string, int> distances = ratios.first;
            string destination = ratios.second;
            cout << destination << endl;

            skip.insert(destination);
            current = destination;
            mins_taken += distances[destination] + 1;
            total_pressure += (30 - mins_taken)*valves[destination].flowrate;

            visited ++;
        }else{
            mins_taken++;
        }
    }
    cout << total_pressure << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}