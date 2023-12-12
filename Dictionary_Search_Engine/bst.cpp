#include "bst.h"
#include"QDebug"
#include<QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
//BST::BST(QObject *parent) : QObject(parent)
//{

//}
//BST::BST(MainWindow*parent):QWidget(parent)
//{
//    ui=parent->ui;
//}
BSTNode* BST::search(QString str,BSTNode* root,int &amount)//搜索结点
{
    BSTNode* temp = new BSTNode;
    temp = root;
    while (temp != NULL)
    {
        int pos=0;
        for(int i=0;i<temp->data.size();i++)
        {
            if(temp->data.at(i)==' ')
            {
                pos=i;
                break;
            }
        }
        QString s = temp->data.mid(0, pos);
//        cui->output_edit_2->setText(s);
        amount++;
        if (str < s)
            temp = temp->left;
        else if (str > s)
            temp = temp->right;
        else
            return temp;
    }
    return NULL;
}
//bool BST::insert(QString str, BSTNode*&root) {
//    if (root == nullptr) {
//        root = new BSTNode(str);
//        if (root == nullptr) {
//            qDebug() << "错误!";
//            return true;
//        }
//    } else if (str < root->data) {
//        qDebug()<<1<<endl;
//        insert(str, root->left);
//    } else if (str > root->data) {
//        insert(str, root->right);
//    } else {
//        return false;
//    }
//}
//bool BST::createBST(QVector<QString> vec)
//{//顺序建树
//    if (vec.isEmpty()) {
//        return false;
//    }
//    for(int i=0;i<vec.size();++i)
//    {
//        insert(vec[i],root);
//    }
//    return true;
//}
bool BST::insert(QString str,BSTNode *&root)//插入结点
{
    if(root==NULL)
    {
        root=new BSTNode(str);
        if(root==NULL)
            qDebug()<<"false";
        return true;
    }
    else if(str<root->data)
        insert(str,root->left);
    else if(str>root->data)
        insert(str,root->right);
    else
        return false;
}

bool BST::createBST(QVector<QString> vec)
{//顺序建树
//    if(vec.size()==0)0
//        return false;
//    for(int i=0;i<vec.size();i++)
//    {
//        insert(vec.at(i),root);
//    }
//    return true;0
        if (vec.isEmpty())
        {
            return false;
        }
        for (const QString& word : vec)
        {
            insert(word, root);
        }
        return true;
}

bool BST::createBST_plus(QVector<QString> vec)//折半建立BST
{
        if (vec.size() == 0)
            return false;
        int mid = vec.size() / 2;
        insert(vec.at(mid), root);
        QVector<QString> temp = vec;
        for (int i = 0; i < vec.size() - mid; i++)
        {
            QVector<QString>::iterator end = temp.end();
            temp.erase(--end);//left
        }
        createBST_plus(temp);
        QVector<QString> post = vec;
        for (int i = 0; i < mid + 1; i++)
        {
            QVector<QString>::iterator begin = post.begin();
            post.erase(begin);//right
        }
        createBST_plus(post);
}

