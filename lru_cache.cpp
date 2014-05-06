#include <iostream>
#include <list>
#include <map>

using namespace std;


class LRUCache{
private:
    struct node
    {
        int key;
        int value;
        node(int k=0, int v=0):key(k), value(v){}
    };
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map_node.find(key)==map_node.end()) return -1;
        list_node.splice(list_node.begin(), list_node, map_node[key]);
        map_node[key] = list_node.begin();
        return map_node[key]->value;
    }
    
    void set(int key, int value) {
        if(map_node.find(key) == map_node.end())
        {
            if(list_node.size() == capacity)
            {
                map_node.erase(list_node.back().key);
                list_node.pop_back();
            }
            list_node.insert(list_node.begin(), node(key, value));
            map_node[key] = list_node.begin();
        }else
        {
            map_node[key]->value = value;
            list_node.splice(list_node.begin(), list_node, map_node[key]);
            map_node[key] = list_node.begin();
        }
    }
private:
    list<node> list_node;
    map<int, list<node>::iterator> map_node;
    int capacity;
};


int main()
{
	LRUCache lru;
	return 0;
}