#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        map<Node*,Node*> m_map;
        queue<Node*> m_queue;
        m_map[node] = new Node(node->val);
        m_queue.push(node);
        while (!m_queue.empty())
        {
            Node *tmp_node = m_queue.front();
            m_queue.pop();
            for (size_t i = 0; i < tmp_node->neighbors.size(); i++)
            {
                if (m_map.find(tmp_node->neighbors[i]) == m_map.end())
                {
                    m_queue.push(tmp_node->neighbors[i]);
                    m_map[tmp_node->neighbors[i]] = new Node(tmp_node->neighbors[i]->val);
                }
                m_map[tmp_node]->neighbors.push_back(m_map[tmp_node->neighbors[i]]);

            }
            
        }
        return m_map[node];
    }
};
int main (){
		
	return 0;
}
