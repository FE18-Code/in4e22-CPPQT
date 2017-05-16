#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QWidget fenetre;
    QPushButton bouton(&fenetre);

    fenetre.setFixedSize(360, 150);
    bouton.setText("Hello World !");
    bouton.setToolTip("Message");
    bouton.setFont(QFont("Comic Sans MS", 20, QFont::Bold, true));
    bouton.setIcon(QIcon(QCoreApplication::applicationDirPath() + "/smile.jpeg"));
    bouton.move(60, 50);

    fenetre.show();
    return app.exec();
}
