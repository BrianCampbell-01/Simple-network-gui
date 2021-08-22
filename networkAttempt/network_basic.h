#ifndef NETWORK_BASIC_H
#define NETWORK_BASIC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class network_basic; }
QT_END_NAMESPACE

class network_basic : public QMainWindow
{
    Q_OBJECT

public:
    network_basic(QWidget *parent = nullptr);
    ~network_basic();

private:
    Ui::network_basic *ui;


private slots:
   // void subnetmask();
   // void HostIP();
    void validateInput();
    void subnetMaskA();
    void subnetMaskB();
    void subnetMaskC();

};
#endif // NETWORK_BASIC_H
