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

vector<vector<long int>> get_mapping(){
    string _; cin >> _ >> _;
    vector<long int> soilmapping;
    long int dest;
    while(cin >> dest){
        long int source; cin >> source;
        long int range; cin >> range;
        soilmapping.push_back(dest);
        soilmapping.push_back(source);
        soilmapping.push_back(range);
    }
    // fertilizer
    cin.clear();
    cin >> _ >> _;
    vector<long int> fertilizermapping;
    while(cin >> dest){
        long int source; cin >> source;
        long int range; cin >> range;
        fertilizermapping.push_back(dest);
        fertilizermapping.push_back(source);
        fertilizermapping.push_back(range);
    }
    // water
    cin.clear();    
    cin >> _ >> _;
    vector<long int> watermapping;
    while(cin >> dest){
        long int source; cin >> source;
        long int range; cin >> range;
        watermapping.push_back(dest);
        watermapping.push_back(source);
        watermapping.push_back(range);
    }
    // light
    cin.clear();      
    cin >> _ >> _;
    vector<long int> lightmapping;
    while(cin >> dest){
        long int source; cin >> source;
        long int range; cin >> range;
        lightmapping.push_back(dest);
        lightmapping.push_back(source);
        lightmapping.push_back(range);
    }
    // temp
    cin.clear();      
    cin >> _ >> _;
    vector<long int> tempmapping;
    while(cin >> dest){
        long int source; cin >> source;
        long int range; cin >> range;
        tempmapping.push_back(dest);
        tempmapping.push_back(source);
        tempmapping.push_back(range);
    }
    // humidity
    cin.clear();      
    cin >> _ >> _;
    vector<long int> humiditymapping;
    while(cin >> dest){
        long int source; cin >> source;
        long int range; cin >> range;
        humiditymapping.push_back(dest);
        humiditymapping.push_back(source);
        humiditymapping.push_back(range);
    }
    // loc
    cin.clear();      
    cin >> _ >> _;
    vector<long int> locmapping;
    while(cin >> dest){
        long int source; cin >> source;
        long int range; cin >> range;
        locmapping.push_back(dest);
        locmapping.push_back(source);
        locmapping.push_back(range);
    }
    vector<vector<long int>> final_mapping;
    final_mapping.push_back(soilmapping);
    final_mapping.push_back(fertilizermapping);
    final_mapping.push_back(watermapping);
    final_mapping.push_back(lightmapping);
    final_mapping.push_back(tempmapping);
    final_mapping.push_back(humiditymapping);
    final_mapping.push_back(locmapping);
    return final_mapping;

}

long int get_location(long int seed, vector<vector<long int>> &mapping){
    // soil
    long int val = seed;
    for(long int map = 0; map <= mapping.size(); map++){
        long int dest_i = 0;
        while(dest_i < mapping[map].size()){
            if(val >= mapping[map][dest_i+1] && val < mapping[map][dest_i+1]+mapping[map][dest_i+2]){
                val = mapping[map][dest_i+0] + (val-mapping[map][dest_i+1]);
                break;
            }
            dest_i += 3;
        }
    }
    return val;
}

void solve(){
    string _; cin >> _;
    long int i = 20;
    vector<long int> seeds;
    while(i--){
        long int _; cin >> _;
        seeds.push_back(_);
    }
    long int min_location = INT32_MAX;
    vector<vector<long int>> mapping = get_mapping();
    for(long int seed : seeds){
        long int location = get_location(seed, mapping);
        min_location = min(min_location, location);
    } 
    cout << min_location << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}