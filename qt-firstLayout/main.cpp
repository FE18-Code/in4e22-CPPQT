#include <QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QWidget fenetre;
    QFormLayout *layout = new QFormLayout;

    QLineEdit *questionName = new QLineEdit;
    QLineEdit *questionFirstName = new QLineEdit;
    QLineEdit *questionAge = new QLineEdit;
    QPushButton *quitter = new QPushButton;
    quitter->setText("&Quitter");

    layout->addRow("Your &Name", questionName);
    layout->addRow("Your &First name", questionFirstName);
    layout->addRow("Your &Age", questionAge);
    layout->addRow(quitter);

    fenetre.setLayout(layout);
    fenetre.show();

    QObject::connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    return app.exec();
}
