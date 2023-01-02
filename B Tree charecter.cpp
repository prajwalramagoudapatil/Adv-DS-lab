#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
class Node {
  char *keys;
  int t;
  Node **C;
  int n;
  bool leaf;

public:
       Node(int t, bool leaf) {
        this->t = t;
        this->leaf = leaf;
        keys = new char[2 * t - 1];
        C = new Node *[2 * t];
        n = 0;
    }
    void insertNonFull(char k) {
      int i = n - 1;

      if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
          keys[i + 1] = keys[i];
          i--;
        }
        keys[i + 1] = k;
        n = n + 1;
      } else {
        while (i >= 0 && keys[i] > k)
          i--;
        if (C[i + 1]->n == 2 * t - 1) {
          splitChild(i + 1, C[i + 1]);
          if (keys[i + 1] < k)
        i++;
        }
        C[i + 1]->insertNonFull(k);
      }
    }
    void splitChild(int i, Node *y) {
      Node *z = new Node(y->t, y->leaf);
      z->n = t - 1;
      for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];
      if (y->leaf == false) {
        for (int j = 0; j < t; j++)
          z->C[j] = y->C[j + t];
      }
      y->n = t - 1;
      for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];
      C[i + 1] = z;
      for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

      keys[i] = y->keys[t - 1];
      n = n + 1;
    }
    void traverse() {

        int i;
        for (i = 0; i < n; i++) {
            if (leaf == false)
                C[i]->traverse();
        cout << " " << keys[i];
      }
        if (leaf == false)
            C[i]->traverse();

    }
friend class BTree;

};
class BTree {
    Node *root;
    int t;

    public:
    BTree(int t) {
        root = NULL;
        this->t = t;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
            cout<<endl;
    }
    void insert(char k) {
      if (root == NULL) {
        root = new Node(t, true);
        root->keys[0] = k;
        root->n = 1;
      }
      else {
        if (root->n == 2 * t - 1) {
          Node *s = new Node(t, false);

          s->C[0] = root;

          s->splitChild(0, root);

          int i = 0;
          if (s->keys[0] < k)
            i++;
          s->C[i]->insertNonFull(k);

          root = s;
        }
        else
          root->insertNonFull(k);
      }
    }
};
int main() {
  BTree t(5);
  char k;

int n,option;
do{
cout<<"Enter \n 1. insert \n 2.display \n";
cin>>option;
switch(option)
{

case 1:
cout<<"Enter the no. of elements"<<endl;
cin>>n;
cout<<"Enter the keys"<<endl;
for(int i=0; i<n; i++)
{
cin>>k;
t.insert(k);
}
break;
case 2:
cout << "Traversal of tree constructed is\n";
    t.traverse();
    break;
    return 0;

}
}while(option ==1 || option ==2);
}

