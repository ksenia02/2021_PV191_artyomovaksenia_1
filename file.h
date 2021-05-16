#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QString>
#include <QLabel>
#include <QTextStream>
#include "sharedptr.h"
#include "fileexception.h"

class File
{
    QFile file;
    QString name;
public:
    File(QString& name_):name(name_),file(name_){};
    void openRead();
    void openWrite();
    void close();
    bool isOpen();
    bool atEnd();
    friend void copyFile(SharedPtr<File> oldFile, SharedPtr<File> newFile);
    void checFile();
};

#endif // FILE_H
