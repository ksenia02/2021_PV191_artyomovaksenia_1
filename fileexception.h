#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H
#include <QString>

class Exception
{
    QString message;
public:
   Exception(QString name): message(name){};
   Exception(){};
   virtual QString what() {
       return message;
   };
};

class OpenError:public Exception
{
public:
   OpenError(QString name): Exception(name){};
   QString what() {
       return QString("!!! File : " + Exception::what() + " open error!!!");
   }
};

class FoundError:public Exception
{
public:
   FoundError(QString name):Exception(name) {};
   QString what() {
       return QString("!!! File : " + Exception::what() + " not found!!!");
   }
};

class OpenDir:public Exception
{
public:
   OpenDir(QString path_):Exception(path_){};
   QString what() {
       return QString("!!! Directory : " + QString(Exception::what()) + " not found!!!");
   }
};

class CountError:public Exception
{
public:
   CountError():Exception(){};
   QString what(){
       return "!!!Сheck the number of files!!";
   };
};
#endif // FILEEXCEPTION_H
