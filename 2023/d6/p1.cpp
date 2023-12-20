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

int compute(double c, double b){
    double first = -b + (sqrt((b*b)-4.0*c));
    double second = -b - (sqrt((b*b)-4.0*c));
    first /= -2.0; second /= -2.0;
    second = min(b, second);
    first = max(0.0, first);

    int rf = ceil(first);
    if(first == rf){
        rf++;
    }
    int rs = ceil(second);
    return abs(rf-rs);

}

void solve(){
    string _; cin >> _;
    vector<double> records, distances;
    double t;
    while(cin >> t){
        distances.push_back(t);
    }
    cin.clear();
    cin >> _;
    while(cin >> t){
        records.push_back(t);
    }
    int r = 1;
    for(int i = 0; i < distances.size(); i++){
        int x = compute(records[i], distances[i]);
        r *= x;
        cout << x << endl;
    }
    cout << r << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}