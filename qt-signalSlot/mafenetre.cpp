#include "mafenetre.h"

MaFenetre::MaFenetre() : QWidget(){

    setFixedSize(200, 150);

    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(10, 20);

    m_bouton=new QPushButton("Reset",this);
    m_bouton->adjustSize();
    m_bouton->move(85,20);
    m_bouton->setCursor(Qt::PointingHandCursor);

    m_progressBar=new QProgressBar(this);
    m_progressBar->setOrientation(Qt::Horizontal);
    m_progressBar->setGeometry(10, 60, 150, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 100, 150, 20);


    connect(m_slider, SIGNAL(valueChanged(int)), m_progressBar, SLOT(setValue(int))); /* slider to progress bar */
}
