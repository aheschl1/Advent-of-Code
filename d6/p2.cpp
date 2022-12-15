#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include <queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

bool valid_buffer(queue<char> currentbuffer){
    vector<char> chars;
    while(currentbuffer.size() > 0){
        char temp = currentbuffer.front();
        if(find(chars.begin(), chars.end(), temp) != chars.end()){
            return false;
        }
        chars.push_back(temp);
        currentbuffer.pop();
    }
    return true;
}
void solve(){
    queue<char> currentbuffer;
    string buffer;
    cin >> buffer;
    unsigned int count = 0;
    for(const char &c : buffer){
        count ++;
        currentbuffer.push(c);
        if(currentbuffer.size() >= 15){
            currentbuffer.pop();
            if(valid_buffer(currentbuffer)){
                cout << count << endl;
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}