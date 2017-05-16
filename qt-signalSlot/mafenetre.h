#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QtWidgets>

class MaFenetre : public QWidget{ // On hérite de QWidget (IMPORTANT)
public:
    MaFenetre();

private:
    QPushButton *m_bouton;
    QLCDNumber *m_lcd;
    QSlider *m_slider;
    QProgressBar *m_progressBar;
};

#endif // MAFENETRE_H
