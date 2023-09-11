#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include <QMultiHash>
#include <QStringList>

class WordDataSet
{
private:
    void _loadWords();

public:
    WordDataSet();
    ~WordDataSet() {}

    QMultiHash<QString, QString> validWordBucket[32];
    QStringList validAnswerList;
    int error_code = 0;

    QString generateRandomAnswer();
};

#endif // LOAD_DATA_H
