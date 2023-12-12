#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"QFileDialog"
#include"bst.h"
#include<avl.h>
#include"QKeyEvent"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    BST bst;
    AVL avl;
    QString receive;
    QVector<QString> v;
    void loadData(const QString&filename,QStringList*word,QStringList*trans);
//    void createBST(const QString &filename);
    void receiveData(QString data);
    Ui::MainWindow *ui;
private slots:
    void on_search_btn_clicked();

private:

};
#endif // MAINWINDOW_H
