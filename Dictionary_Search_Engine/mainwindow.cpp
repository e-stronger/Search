#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include<QVector>
#include<QHash>
#include <QStringList>
#include <QDebug>
#include"bst.h"
#include"QCompleter"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
//    ui->bstree = new BST(this);
//    createBST("C:\\Users\\apple pen\\Desktop\\EnWords.csv");
//    connect(&bst,&BST::sendData,this,&MainWindow::receiveData);
    ui->input_edit->setPlaceholderText("请输入英文：");
    ui->lineEdit_2->setReadOnly(1);
    ui->output_edit->setReadOnly(1);
    ui->output_edit_2->setReadOnly(1);
    QStringList *word=new QStringList;
    QStringList *trans=new QStringList;
    loadData("D:\\EnWords - 副本.csv",word,trans);//"D:\\EnWords - 副本.csv"
    QStringList *data=new QStringList;
    if(word->size()==trans->size())
    {
        for(int i=0;i<word->size();++i)
        {
            QString str;
            str=word->at(i)+' '+trans->at(i);
            data->push_back(str);
        }
    }
    for(int i=0;i<data->size();++i)
        v.push_back(data->at(i));
    QCompleter*com=new QCompleter(*word);
    com->setMaxVisibleItems(10);
    ui->input_edit->setCompleter(com);
    bst.createBST_plus(v);
    avl.createAVL(v);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadData(const QString &filename,QStringList*word,QStringList*trans)
{
//    QHash<QString, QString> dictionary;
//    QFile file(filename);
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        qDebug() << "Failed to open file.";
//    }
//    QTextStream infile(&file);
//    while (!infile.atEnd())
//    {
//       QString line = infile.readLine();
//       QStringList parts = line.split(',');
//       if (parts.size() >= 2)
//       {
//           QString word = parts.at(0).trimmed();
//           QString meaning = parts.at(1).trimmed();
//           dictionary.insert(word, meaning);
//       }
//    }
//       file.close();
        QFile inFile(filename);
        QStringList lines;
        if (inFile.open(QIODevice::ReadOnly))
        {
            QTextStream stream_text(&inFile);
            stream_text.setAutoDetectUnicode(true);
            while (!stream_text.atEnd())
            {
                lines.push_back(stream_text.readLine());
            }
            for (int j = 0; j < lines.size(); j++)
            {
                QString line = lines.at(j);//逐行取出
                int locate=0;
                for(int i=0;i<line.size();i++)
                {
                    if(line[i]==',')
                    {
                        locate=i;
                        break;
                    }
                }
                QString str1=line.mid(0,locate);
                QString str2=line.mid(locate+1,line.size()-locate-1);
                //去除引号
                str1.remove(0,1);
                str1.remove(str1.size()-1,1);
                word->push_back(str1);
//                str2.remove(0,1);
//                str2.remove(str2.size()-1,1);
                trans->push_back(str2);
            }
            inFile.close();
        }
}

//void MainWindow::createBST(const QString &filename)
//{
//    bst->root=NULL;
//    QFile file(filename);
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        qDebug() << "Failed to open file.";
//    }
//    QTextStream infile(&file);
//    qDebug()<<1<<endl;
//    while (!infile.atEnd())
//    {
//       QString line = infile.readLine();
//       QStringList parts = line.split(',');
//       if (parts.size() >= 2)
//       {
//           QString word = parts.at(0).trimmed();
//           QString meaning = parts.at(1).trimmed();
//           bst->insert(word,meaning);
//       }
//    }
//    cout<<"succeed"<<endl;
//    file.close();
//}

void MainWindow::receiveData(QString data)
{
    receive=data;
}
void MainWindow::on_search_btn_clicked()
{
    QString str=ui->input_edit->text();
    if(ui->search->currentText()=="顺序查找")
    {
        QString goal=NULL;
        int count=0;
        for(int i=0;i<v.size();++i)
        {
            int pos=0;
            for(int j=0;j<v[i].size();++j)
            {
                if(v[i].at(j)==' ')
                {
                    pos=j;
                    break;
                }
            }
            QString word=v[i].mid(0,pos);
            if(str==word)
            {
                count=i+1;
//                ui->output_edit_2->setText("搜索次数："+QString::number(count));
                goal=v[i];
            }
        }
        if(goal==NULL)
            ui->output_edit->setText("不存在此单词");
        else
            ui->output_edit->setText(goal);
    }
    if(ui->search->currentText()=="BST查找")
    {
        QString goal=NULL;
        int count=0;
        BSTNode*node=new BSTNode();
        node=bst.search(str,bst.root,count);
        if(node==NULL)
        ui->output_edit->setText("不存在此单词");
        else
        {
            ui->output_edit->setText(node->data);

        }
    }
    if(ui->search->currentText()=="AVLTree查找")
    {
//        QString goal=NULL;
//        int count=0;
//        Node*node=avl.search(str,avl.root,count);
//        if(node==NULL)
//        ui->output_edit->setText("不存在此单词");
//        else
//        {
//            ui->output_edit->setText(node->data);
//            qDebug()<<"AVLTree搜索次数："<<count<<endl;
//        }
        QString goal=NULL;
        int count=0;
        BSTNode*node=new BSTNode();
        node=bst.search(str,bst.root,count);
        if(node==NULL)
        ui->output_edit->setText("不存在此单词");
        else
        {
            ui->output_edit->setText(node->data);
            qDebug()<<"AVL times :"<<count<<endl;
        }
    }
}
