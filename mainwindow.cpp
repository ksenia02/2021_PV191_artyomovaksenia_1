#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file.h"
#include "fileexception.h"
#include <QMessageBox>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString creatPath(QString path, QString name){

    path.append("/");
    path = path + name;
    return path;
}

void MainWindow::on_pushButton_clicked()
{
    try{
    int count = ui->CountFile->value();
    QString oldPath = ui->OldPath->text();
    QDir d;
    if(!d.exists(oldPath))
        throw OpenDir(oldPath);
    QString newPath = ui->NewPath->text();
    if(!d.exists(newPath))
        throw OpenDir(newPath);
    QString path;

    QString data = ui->ListName->toPlainText();
    QStringList strList = data.split(QRegExp("[\n]"),QString::SkipEmptyParts);
    if(count != strList.size())
        throw CountError();
    for(int i = 0; i < count; ++i){
        path = creatPath(oldPath,strList[i]);
        SharedPtr<File> oldF(new File(path));
        oldF->checFile();
        path = creatPath(newPath, strList[i]);
        SharedPtr<File> newF(new File(path));
        copyFile(oldF, newF);
    }
      QMessageBox::information(this,"","Копирование успешно!");
    }
    catch(Exception& e){
        QMessageBox::warning(this,"Error",e.what());
    }
}
