#ifndef BST_H
#define BST_H
//#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <QObject>
#include<QString>
#include <stdlib.h>
#include<QVector>
struct  BSTNode
{
    QString data;
    BSTNode*left,*right;
    BSTNode(){left=NULL;right=NULL;}
    BSTNode(QString data)
    {
        this->data=data;
        left=right=NULL;
    }
};
class BST : public QObject
{
    Q_OBJECT
public:
    BSTNode*root;
//    explicit BST(QObject *parent = nullptr);
//    BST(){this->root=NULL;};
    BST():root(NULL){}
    ~BST(){};
    BSTNode* search(QString x,BSTNode*rootptr,int &amount);
    bool insert(QString str,BSTNode *&root);
    bool createBST(QVector<QString> vec);
    bool createBST_plus(QVector<QString> vec);
    void inOrder(BSTNode*ptr);
signals:
    void sendData(QString send);

};

#endif // BST_H
