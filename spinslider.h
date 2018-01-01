#ifndef SPINSLIDER_H
#define SPINSLIDER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QSpinBox>
#include <QString>


//rappresenta uno slider con uno spinbox


class SpinSlider:public QWidget
{
    Q_OBJECT
public:
    SpinSlider(QWidget* parent=0, QString desc="NO NAME",int min=0,int max = 255);
    QLabel* getLable() const;
    QSlider* getSlider() const;
    QSpinBox* getSpinBox() const;

private:
    QHBoxLayout* layout ;
    QLabel* desc_lable;
    QSlider* slider;
    QSpinBox* spin_box;
signals:
    void valueChanged(int newValue);
};

#endif // SPINSLIDER_H