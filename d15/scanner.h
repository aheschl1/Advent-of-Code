#include<map>
#include<cmath>
#include<set>

class scanner{
    public:
    scanner(std::pair<int,int> loc, std::pair<int,int> b_loc);
    int getBeakonDistance();
    void impossible_beakons(std::map<int, std::set<int>> &impossible, int y_care);
    std::pair<int, int> loc;
    private:
    std::pair<int, int> b_loc;
};