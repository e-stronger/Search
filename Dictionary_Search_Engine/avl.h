#ifndef AVL_H
#define AVL_H
#include<QString>
#include<QVector>
struct Node
{
    QString data;
    int height;
    Node*left;
    Node*right;
    Node(QString str)
    {
        this->data=str;
        this->height=1;
        this->left=NULL;
        this->right=NULL;
    }

};
class AVL
{
public:
    Node*root;
    AVL():root(NULL){};
    Node* insert_plus(Node*root,QString str);
    void insert(Node*root,QString str);
    Node* search(QString str,Node* root,int &amount);
    int getBalanceFactor(Node*node);
    Node* rotateRight(Node*y);
    Node* rotateLeft(Node*x);
    bool createAVL(QVector<QString> vec);
    int getheight(Node*node);
};

#endif // AVL_H
