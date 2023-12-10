#include<vector>
#include<string>
typedef unsigned long long ull;

class Directory{
    public:

    Directory(std::string label, Directory *parent = nullptr);
    std::vector<Directory*> getChildDirs();
    void addChildDir(Directory *child);
    void addFile(int size);
    unsigned long long getSize();
    std::vector<int>& getFiles();
    Directory* getParent();
    std::string get_label();
    Directory* containsChild(std::string label);
    void get_map(std::vector<ull> &map);

    private:
    Directory *my_parent;
    std::vector<Directory*> childrenDir;
    std::vector<int> files;
    std::string name;
};