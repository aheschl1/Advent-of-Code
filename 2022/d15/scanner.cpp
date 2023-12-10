
#include "scanner.h"

scanner::scanner(std::pair<int,int> loc, std::pair<int,int> b_loc){
    this->loc = loc;
    this->b_loc = b_loc;
}

void scanner::impossible_beakons(std::map<int, std::set<int>> &impossible, int y_care){
    int distance = getBeakonDistance();
    int y_off = y_care - loc.second;
    if(y_off > distance){
        return;
    }
    for(int x_off = -distance + abs(y_off); x_off <= distance - abs(y_off); x_off++){
        impossible[loc.second + y_off].insert(loc.first + x_off);
    }
}

int scanner::getBeakonDistance(){
    return abs(loc.first - b_loc.first) + abs(loc.second - b_loc.second);
}
