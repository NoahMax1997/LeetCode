#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
class LRUCacheWrong {
public:
    struct Node
    {
       int key;
       int value;
       Node* pre;
       Node* next;
       Node(){
           key=0;
           value=0;
           pre=NULL;
           next=NULL;
       }
    };
    Node *head=NULL,*tail=NULL;
    map<int,Node*> Map;
    int size=0,sum=0;
    LRUCacheWrong(int capacity) {
       head=new Node();
       head->next=new Node();
       tail=head->next;
       tail->pre=head;
       size=capacity;
    }

    void push_front(int key,int value){
        Node *t=head->next;
        head->next=new Node();
        head->next->key=key;
        head->next->value=value;
        head->next->pre=head;
        head->next->next=t;
        t->pre=head->next;

    }
    int get(int key) {
        int ret=-1;
        if(Map.find(key)!=Map.end()){
            ret=Map[key]->value;
            put(key,ret);
        }
        return ret;
    }
    void put(int key, int value) {
        if(Map.find(key)!=Map.end()){
            Node *tt=Map[key];
            if(tt==head->next){
                tt->value=value;
                return;
            }
            tt->pre->next=tt->next;
            tt->next->pre=tt->pre;
            tt->next=head->next;
            tt->pre=head;
            head->next->pre=tt;
            head->next=tt;
            tt->value=value;
        }else if(sum<size){
            push_front(key,value);
            Map[key]=head->next;
            sum++;
        }else
        {
            if(tail->pre==head->next){
                Map.erase(tail->pre->key);
                tail->pre->key=key;
                tail->pre->value=value;
                Map[key]=tail->pre;
                return;
            }
            Map.erase(tail->pre->key);
            // cout<<tail->key<<" "<<Map.size()<<endl;
            tail->pre->key=key;
            tail->pre->value=value;
            swap(head->next->key,tail->pre->key);
            swap(head->next->value,tail->pre->value);
            Map[key]=head->next;
            Map[tail->pre->key]=tail->pre;
        } 
    }
    void print(Node *tt){
        cout<<"print::1"<<endl;
        while(tt){
            printf("key=%d  value=%d| ",tt->key,tt->value);
            tt=tt->next;
        }
        cout<<endl;
        cout<<"print2::"<<endl;
        tt=tail;
        while(tt){
            printf("key=%d  value=%d| ",tt->key,tt->value);
            tt=tt->pre;
        }
        cout<<endl;
        cout<<"........."<<endl;
    }
};
class LRUCache {
public:
    struct Node
    {
       int key;
       int value;
       Node* pre;
       Node* next;
       Node(){
           key=0;
           value=0;
           pre=NULL;
           next=NULL;
       }
    };
    Node *head=NULL,*tail=NULL;
    map<int,Node*> cache;
    int size=0,capacity;
    LRUCache(int capacity) {
       head=new Node();
       tail=new Node();
       head->next=tail;
       tail->pre=head;
       this->capacity=capacity;
    }
    void removeNode(Node *node){
        node->pre->next=node->next;
        node->next->pre=node->pre;
        delete node;
    }
    void addNodeToHead(int key,int value){
        Node *t_node=new Node();
        t_node->key=key;
        t_node->value=value;
        head->next->pre=t_node;
        t_node->next=head->next;
        head->next=t_node;
        t_node->pre=head;
    }
    int get(int key) {
        int ret=-1;
        if(cache.find(key)!=cache.end()){
            ret=cache[key]->value;
            removeNode(cache[key]);
            addNodeToHead(key,ret);
            cache[key]=head->next;
        }
        return ret;
    }
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            removeNode(cache[key]);
            addNodeToHead(key,value);
            cache[key]=head->next;
        }else{
            addNodeToHead(key,value);
            cache[key]=head->next;
            size++;
        }
        while(size>capacity){
            removeNode(tail->pre);
            cache.erase(tail->pre->value);
            size--;
        }
    }
    void print(Node *tt){
        cout<<"print::1"<<endl;
        while(tt){
            printf("key=%d  value=%d| ",tt->key,tt->value);
            tt=tt->next;
        }
        cout<<endl;
        cout<<"print2::"<<endl;
        tt=tail;
        while(tt){
            printf("key=%d  value=%d| ",tt->key,tt->value);
            tt=tt->pre;
        }
        cout<<endl;
        cout<<"........."<<endl;
    }
};
int main (){
	LRUCache lru(1);
    lru.put(2,1);
    // lru.put(3,2);
    lru.print(lru.head);
    cout<<lru.get(2)<<endl;
    lru.print(lru.head);
    // cout<<lru.get(2)<<endl;
    // lru.print(lru.head);
    lru.put(3,2);
    lru.print(lru.head);
    cout<<lru.get(2)<<endl;
    lru.print(lru.head);
    // // lru.put(4,4);
    // // lru.print(lru.head);
    cout<<lru.get(3)<<endl;
    lru.print(lru.head);
    // // cout<<lru.get(3)<<endl;
    // // lru.print(lru.head);
    // cout<<lru.get(4)<<endl;
    lru.print(lru.head);
    system("pause");
	return 0;
}
