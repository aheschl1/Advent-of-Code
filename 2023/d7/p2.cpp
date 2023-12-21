#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<unordered_set>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;
map<char, int> ordering;

int typea(string &ocards){
    unordered_set<char> unique(ocards.begin(), ocards.end());
    if(unique.size()==1){
        // 5
        return 0;
    }else if(unique.size() == 2){
        // 4 of kind or full house
        char a = '_', b = '_';
        int ac = 0, bc = 0;
        for(char c : ocards){
            if(a == '_') a = c;
            else b = c;
            if(c==a){
                ac++;
            }
            else bc++;
        }
        if(ac == 3 || ac == 2){
            // full house
            return 2;
        }
        // 4 of kind
        return 1;
    }else if(unique.size() == 3){
        // 2 pair or 3 of kind
        map<char, int> count;
        for(char c : ocards){
            count[c] += 1;
        }
        int m = 0;
        for(auto x : count){
            m = max(x.second, m);
        }
        if(m == 3){
            return 3;
        }
        return 4;
    }else if(unique.size() == 4){
        // 1 pair
        return 5;
    }else{
        // no pair
        return 6;
    }
}

static bool sq(string &a, string &b){
    int ar = typea(a), br = typea(b);
    if(ar != br){
        return ar > br;
    }
    for(int i = 0; i < 5; i++){
        if(a[i] == b[i]) continue;
        return ordering[a[i]] > ordering[b[i]];
    }
}

struct Hand{
    string cards, ocards;
    int bid;

    string get_optimal(string og){
        vector<int> j_indices;
        vector<string> attempts;
        for(int i = 0; i < 5; i++){
            if(og[i] != 'J') continue;
            j_indices.push_back(i);
        }
        for(auto p : ordering){
            if(p.first == 'J') continue;
            string t(og.begin(), og.end());
            for(int j : j_indices){
                t[j] = p.first;
            }
            attempts.push_back(t);
        }
        sort(attempts.begin(), attempts.end(), sq);
        return attempts[attempts.size()-1];
    }

    Hand(string c, int b){
        this->cards = c;
        this->ocards = get_optimal(c);
        this->bid = b;
    }
    int type(){
        unordered_set<char> unique(ocards.begin(), ocards.end());
        if(unique.size()==1){
            // 5
            return 0;
        }else if(unique.size() == 2){
            // 4 of kind or full house
            char a = '_', b = '_';
            int ac = 0, bc = 0;
            for(char c : ocards){
                if(a == '_') a = c;
                else b = c;
                if(c==a){
                    ac++;
                }
                else bc++;
            }
            if(ac == 3 || ac == 2){
                // full house
                return 2;
            }
            // 4 of kind
            return 1;
        }else if(unique.size() == 3){
            // 2 pair or 3 of kind
            map<char, int> count;
            for(char c : ocards){
                count[c] += 1;
            }
            int m = 0;
            for(auto x : count){
                m = max(x.second, m);
            }
            if(m == 3){
                return 3;
            }
            return 4;
        }else if(unique.size() == 4){
            // 1 pair
            return 5;
        }else{
            // no pair
            return 6;
        }
    }
};
bool my_cmp(Hand& a, Hand& b)
{
    // smallest comes first
    int ar = a.type(), br = b.type();
    if(ar != br){
        return ar > br;
    }
    for(int i = 0; i < 5; i++){
        if(a.cards[i] == b.cards[i]) continue;
        return ordering[a.cards[i]] > ordering[b.cards[i]];
    }
}

void solve(){
    ordering['A'] = 0;
    ordering['K'] = 1;
    ordering['Q'] = 2;
    ordering['J'] = 13;
    ordering['T'] = 4;
    ordering['9'] = 5;
    ordering['8'] = 6;
    ordering['7'] = 7;
    ordering['6'] = 8;
    ordering['5'] = 9;
    ordering['4'] = 10;
    ordering['3'] = 11;
    ordering['2'] = 12;

    vector<Hand> hands;
    string hand;
    int bid;
    while(cin >> hand){
        cin >> bid;
        hands.push_back(Hand(hand, bid));
    }
    sort(hands.begin(), hands.end(), my_cmp);
    int result = 0;
    for(int i = hands.size(); i > 0; i--){
        result += hands[i-1].bid * i;
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}