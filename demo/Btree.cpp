#include <iostream>
#include <vector>
using namespace std;


class BTree_node
{
public:
    vector<int> keys;
    vector<BTree_node*> children;
    bool is_leaf() {return children.empty();}
    int n;// == keys.size()
    BTree_node()
    {
        keys.resize(0);
        children.resize(0);
        n = 0;
    }


    void insertNonFull(int k);
    void splitChild(int i, BTree_node *p);
    void traverse();//duyet qua tat ca cac khoa trong cay--> in ra

    BTree_node* search(int k);
};

class BTree
{
public:
BTree() { _m = 0; root = NULL; }
BTree(int m)
{
    if(m % 2 == 0) // chan
        m = m / 2 + 1; 
    _m = m; root = NULL;
}


bool empty(){ return root == NULL; }

void traverse()
{
    if(root != NULL)
        root->traverse();
}

BTree_node* search(int k)
{
    return root == NULL ? NULL : root->search(k);
}

void insert(int k);
private:
BTree_node* root;
int _m; // bac cua cay
};

void BTree_node::traverse()
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(is_leaf == false)
            children[i]->traverse();
        cout << " " << keys[i];
    }

    if(is_leaf == false)
    {
        children[i]->traverse();
    }
}

BTree_node* BTree_node::search(int k) // tim 1 node o 1 node con
{
    int i = 0;
    while(i < n && k > keys[i])
        i++;
    if(keys[i] == k)
        return this;

    else if(is_leaf)
    {
        return NULL;
    }

    return this->children[i]->search(k);
}

void BTree::insert(int k)
{
    if(!root)
    {
        root = new BTree_node;
        root->keys.push_back(k);
        root->n++;
    }
    else
    {
        if(root->n == this->_m)
        {
            BTree_node * s = new BTree_node;
            s->children.push_back(root);
            s->splitChild(0, root);

            int i = 0;
            if(s->keys[0] < k)
            {
                i++;
            }
            s->children[i]->insertNonFull(k);

            root = s;
        }
        else
        root->insertNonFull(k);
    }
}
