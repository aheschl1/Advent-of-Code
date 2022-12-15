#include<vector>
#include<map>
#include <cstdlib>

class Knot{
    public:
    Knot(int index, int *visit_count, Knot *parent = nullptr, Knot*child = nullptr);
    void parent_moved();
    void move(char direction);
    void set_child(Knot *child);
    std::pair<int, int> pos = std::make_pair(0,0);
    Knot *child;
    int index;

    private:
    std::map<int, std::vector<int>> visited;
    bool is_new(std::pair<int, int> &new_pos);
    Knot *parent;
    int *visit_count;

    bool inRange(std::pair<int, int> &head_pos, std::pair<int, int> &tail_pos){
        return abs(head_pos.first - tail_pos.first) <= 1 && abs(head_pos.second - tail_pos.second) <= 1;
    }

};