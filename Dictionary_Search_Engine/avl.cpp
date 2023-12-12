#include "avl.h"
#include<QDebug>
//Node* AVL::insert(Node *&root, QString str)
//{
//    if(root==NULL)0
//    {
//        root=new Node(str);
//        root->height=1;
//    }
//    if(str<root->data)
//        insert(root->left,str);
//    else if(str>root->data)
//        insert(root->right,str);
//    else
//        return false;
//0    root->height = qMax(getheight(root->left), getheight(root->right)) + 1;
//    root->height = qMax((root->left != nullptr ? root->left->height : 0), (root->right != nullptr ? root->right->height : 0)) + 1;
//    int b = getBalanceFactor(root);
//    if(b>1)
//    {
//        if(str<root->data)//LL型
//        {
//            rotateRight(root);
//        }
//        else//LR型
//        {
//            rotateLeft(root->left);
//            rotateRight(root);
//        }
//    }
//    if(b<-1)
//    {
//        if(str>root->data)//RR型
//        rotateLeft(root);
//        else//RL型
//        {
//            rotateRight(root->right);
//            rotateLeft(root);
//        }
//    }
//    return true;0
//        if(root == nullptr)
//        {
//            root = new Node(str);
//            root->height = 1;
//            return root;
//        }
//        if(str < root->data)
//        {
//            root->left=insert(root->left,str);
//        }
//        else if(str > root->data)
//        {
//            root->right=insert(root->right,str);
//        }
//        else
//        {
//            return root;
//        }
//        root->height = qMax((root->left != nullptr ? root->left->height : 0), (root->right != nullptr ? root->right->height : 0)) + 1;
//        int b = getBalanceFactor(root);
//        if(b > 1)
//        {
//            if(str < root->left->data) // LL型
//            {
//                return rotateRight(root);
//            }
//            else // LR型
//            {
//                root->left=rotateLeft(root->left);
//                return rotateRight(root);
//            }
//        }
//        else if(b < -1)
//        {
//            if(str > root->right->data) // RR型
//            {
//                return rotateLeft(root);
//            }
//            else // RL型
//            {
//                root->right=rotateRight(root->right);
//                return rotateLeft(root);
//            }
//        }
//        return root;
//}
Node* AVL::insert_plus(Node *root, QString str)
{
    if (root == NULL) {
        Node*temp = new Node(str);
//        root->height = 1;
        return temp;
    }
    if (str < root->data) {
        root->left = insert_plus(root->left, str);
    } else if (str > root->data) {
        root->right = insert_plus(root->right, str);
    } else {
        return root;
    }
    root->height=qMax(getheight(root->left), getheight(root->right)) + 1;
//    root->height = qMax((root->left != NULL ? root->left->height : 0), (root->right != nullptr ? root->right->height : 0)) + 1;
    int b = getBalanceFactor(root);
    if (b > 1) { // Left Left Case.
        if (str < root->left->data) { // LL型.
            return rotateRight(root);
        } else { // LR型.
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    } else if (b < -1) {
        if (str > root->right->data) { // RR型.
            return rotateLeft(root);
        } else { // RL型.
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
        return root;
}

void AVL::insert(Node *root, QString str)
{
    root=insert_plus(root,str);
}

Node *AVL::search(QString str, Node *root, int &amount)
{
    Node* temp=root;
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
        amount++;
//        if (str < s)
//            temp = temp->left;
//        else if (str > s)
//            temp = temp->right;
//        else
//            return temp;
          if(s == str)
               return root;
          if(s > str)
               return search(str,root->left,amount);
          if(s < str)
               return search(str,root->right,amount);
    }
    return NULL;
}
int AVL::getBalanceFactor(Node *node)
{
    if(node==NULL)
        return 0;
    return (getheight(node->left)-getheight(node->right));
}

Node* AVL::rotateRight(Node *y)
{
    Node*x=y->left;
    Node*temp=x->right;
    x->right=y;
    y->left=temp;
    y->height = 1+qMax(getheight(y->left), getheight(y->right));
    x->height = 1+qMax(getheight(x->left), getheight(x->right));
//    y->height = qMax((y->left != nullptr ? getheight(y->left) : 0), (y->right != nullptr ? getheight(y->right) : 0)) + 1;
//    x->height = qMax((x->left != nullptr ? getheight(x->left) : 0), (x->right != nullptr ? getheight(x->right) : 0)) + 1;
    return x;
}
Node* AVL::rotateLeft(Node *x)
{
    Node* y = x->right;
    Node* temp = y->left;
    y->left = x;
    x->right =temp;
    x->height = 1+qMax(getheight(x->left), getheight(x->right));
    y->height = 1+qMax(getheight(y->left), getheight(y->right));
//    x->height = qMax((x->left != nullptr ? getheight(x->left) : 0), (x->right != nullptr ? getheight(x->right) : 0)) + 1;
//    y->height = qMax((y->left != nullptr ? getheight(y->left) : 0), (y->right != nullptr ? getheight(y->right) : 0)) + 1;
    return y;
}

bool AVL::createAVL(QVector<QString> vec)
{
    if (vec.isEmpty())
    {
        return false;
    }
    for(int i=0;i<vec.size();++i)
    {
        insert(root,vec[i]);
    }
    return true;
}

int AVL::getheight(Node *node)
{
    if(node==NULL)
        return 0;
    return node->height;
}
