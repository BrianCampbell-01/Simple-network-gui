#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

#include <QMainWindow>

class computations
{
    QString localIP, subnet, output;
    bool validInput = true;

    bool is_valid(QString);
    int qstringToInt(QString);
    std::vector<int> populate(QString);
    bool withinRange(int);
    void outputString(std::vector<int>&);

public:
    computations(QString, QString);
    bool checkInput();
    void compute();
    QString hostIP();


};

#endif // COMPUTATIONS_H
