#include "file.h"
#include "fileexception.h"

void File::openRead(){
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen())
        throw OpenError(name);
}

void File::openWrite(){
    file.open(QIODevice::WriteOnly);
    if(!file.isOpen())
        throw OpenError(name);
}

bool File::isOpen(){

    return file.isOpen();
}

void File::close(){
    if (file.isOpen())
        file.close();
}

bool File::atEnd(){

    return file.atEnd();
}

void File::checFile(){

    if(!file.exists())
        throw FoundError(name);
}
 void copyFile(SharedPtr<File> oldFile, SharedPtr<File> newFile){

     oldFile->openRead();
     newFile->openWrite();
    while(!oldFile->atEnd()){
        QString line = oldFile->file.readLine();
        newFile->file.write(line.toUtf8());
    }
    oldFile->close();
    newFile->close();
 }
