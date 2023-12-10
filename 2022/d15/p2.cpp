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

int missing(vector<int> arr, int n){
   int arrMin = *min_element(arr.begin(), arr.end());
   int numXor = 0;
   int rangeXor = arrMin;
   for (int i = 0; i < n; i++) {
      numXor ^= arr[i];
      arrMin++;
      rangeXor ^= arrMin;
   }
   return numXor ^ rangeXor;
}
 
 

void solve(){
    //  y     x
    map<int, set <int>> impossible;
    map<int, set <int>> beakons;
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
    
    for(int y_check = 0; y_check <= 4000000; y_check++){
        for(scanner s : scanners){
            s.impossible_beakons(impossible, y_check);
        }
        vector<int> v(impossible[y_check].begin(), impossible[y_check].end());
        int missing_v = missing(v, v.size());
        if(missing_v != v[v.size()-1] + 1){
            cout << missing_v << " " << y_check << endl; 
        }
    }
   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}