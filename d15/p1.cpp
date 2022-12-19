#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<sstream>
#include"scanner.cpp"

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;


void solve(){
    //  y     x
    map<int, set<int>> impossible;
    map<int, set<int>> beakons;
    vector<scanner> scanners;
    int x,y,b_x,b_y;
    string line;
    while(getline(cin, line)){
        int xstart = line.find('=') + 1;
        int endx = line.find(',') - xstart;
        string xs = line.substr(xstart, endx);
        x = stoi(xs);
        line = line.substr(line.find(','));

        int ystart = line.find('=') + 1;
        int endy = line.find(':') - ystart;
        string ys = line.substr(ystart, endy);
        y = stoi(ys);
        line = line.substr(line.find(':'));
        
        xstart = line.find('=') + 1;
        endx = line.find(',') - xstart;
        xs = line.substr(xstart, endx);
        b_x = stoi(xs);
        line = line.substr(line.find(','));

        ystart = line.find('=') + 1;
        endy = line.find('\n') - ystart;
        ys = line.substr(ystart, endy);
        b_y = stoi(ys);
        beakons[b_y].insert(b_x);
        scanner scanner(make_pair(x,y), make_pair(b_x, b_y));
        scanners.push_back(scanner);
    }
    for(scanner s : scanners){
        s.impossible_beakons(impossible, 2000000);
    }
    set<int> out; 
    //set_difference(impossible[2000000].begin(), impossible[2000000].end(), beakons[2000000].begin(), beakons[2000000].end(), inserter(out, out.begin()));
    cout << impossible[2000000].size() - beakons[2000000].size() << endl;
    //cout << out.size() <<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}