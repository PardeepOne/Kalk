#include "coloroperationbuttons.h"

colorOperationButtons::colorOperationButtons(QWidget* parent):QWidget(parent)
{
    lbl1= new QLabel("Operazioni tra 2 Operandi");
    lbl2 = new QLabel("Operazioni su Operando 1");

    f = new QFont("Verdana",12);
    setFont(*f);

    fattoreScala = new QDoubleSpinBox;
    fattoreScala->setMinimum(0.1);
    fattoreScala->setFont(*f);

    H = new QDoubleSpinBox;
    H->setRange(0.0,400.0);
    H->setSuffix(" H");

    S= new QDoubleSpinBox;
    S->setRange(0.0,100.0);
    S->setSuffix(" S");

    L= new QDoubleSpinBox;;
    L->setRange(0.0,100.0);
    L->setSuffix(" L");

    R = new QSpinBox;
    R->setRange(0,255);
    R->setSuffix(" R");

    G = new QSpinBox;
    G->setRange(0,255);
    G->setSuffix(" G");

    B=new QSpinBox;
    B->setRange(0,255);
    B->setSuffix(" B");


    layout = new QGridLayout;
    btnSomma = new QPushButton(tr("Somma"));
    btnDifferenza =new QPushButton(tr("Differenza"));
    btnModulazione=new QPushButton(tr("Modulazione"));
    btnDeltaE =new QPushButton(tr("Delta E"));
    btnScala=new QPushButton(tr("Scala di "));
    btnComplementare=new QPushButton(tr("Complementare"));
    btnLuminosita= new QPushButton(tr("Luminosita"));
    btnCaldo= new QPushButton(tr("Colore Caldo/Freddo"));
    btnLab= new QPushButton(tr("Rappresentazione Lab"));
    btnHex= new QPushButton(tr("Rappresentazione HEX "));
    btnHsl2Rgb = new QPushButton(tr("HSL TO RGB"));
    btnHsl= new QPushButton(tr("Rappresentazione HSL "));
    btnHsl->setFont(*f);
    btnRgb = new QPushButton(tr("Rappresentazione RGB "));
    btnRgb->setFont(*f);

    btnRgb2Hsl = new QPushButton(tr("RGB To HSL"));

    layout->addWidget(lbl1,0,0,1,4,Qt::AlignCenter);
    layout->addWidget(btnSomma,1,0);
    layout->addWidget(btnDifferenza,1,1);
    layout->addWidget(btnModulazione,1,2);
    layout->addWidget(btnDeltaE,1,3);
    layout->addWidget(lbl2,2,0,1,4,Qt::AlignCenter);
    layout->addWidget(btnComplementare,3,0);
    layout->addWidget(btnLuminosita,3,1,1,2);
    layout->addWidget(btnCaldo,3,3);
    layout->addWidget(btnLab,4,0);
    layout->addWidget(btnHsl,4,1,1,2);
    layout->addWidget(btnHex,4,3);
    layout->addWidget(btnScala,5,0,1,2);
    layout->addWidget(fattoreScala,5,2,1,2);

    l = new QHBoxLayout;
    l->addWidget(btnHsl2Rgb);
    l->addWidget(H);
    l->addWidget(S);
    l->addWidget(L);

    layout->addLayout(l,6,0,1,4);

    connect(btnSomma,SIGNAL(clicked(bool)),this,SIGNAL(btnSommaClicked(bool)));
    connect(btnDifferenza,SIGNAL(clicked(bool)),this,SIGNAL(btnDifferenzaClicked(bool)));
    connect(btnModulazione,SIGNAL(clicked(bool)),this,SIGNAL(btnModulazioneClicked(bool)));
    connect(btnDeltaE,SIGNAL(clicked(bool)),this,SIGNAL(btnDeltaEClicked(bool)));
    connect(btnScala,SIGNAL(clicked(bool)),this,SIGNAL(btnScalaClicked(bool)));
    connect(btnComplementare,SIGNAL(clicked(bool)),this,SIGNAL(btnComplementareClicked(bool)));
    connect(btnLuminosita,SIGNAL(clicked(bool)),this,SIGNAL(btnLuminositaClicked(bool)));
    connect(btnCaldo,SIGNAL(clicked(bool)),this,SIGNAL(btnCaldoClicked(bool)));
    connect(btnLab,SIGNAL(clicked(bool)),this,SIGNAL(btnLabClicked(bool)));
    connect(btnHsl,SIGNAL(clicked(bool)),this,SIGNAL(btnHslClicked(bool)));
    connect(btnHex,SIGNAL(clicked(bool)),this,SIGNAL(btnHexClicked(bool)));
    connect(btnHsl2Rgb,SIGNAL(clicked(bool)),this,SIGNAL(btnHsl2RgbClicked(bool)));

    connect(btnRgb2Hsl,SIGNAL(clicked(bool)),this,SIGNAL(btnRgb2HslClicked(bool)));

    setLayout(layout);
}
colorOperationButtons::~colorOperationButtons(){
    remove(layout);
    delete layout;

    delete f;
}
QDoubleSpinBox* colorOperationButtons::getFattoreScalaSpin()const{return fattoreScala;}
QDoubleSpinBox* colorOperationButtons::getHSpin()const{return H;}
QDoubleSpinBox* colorOperationButtons::getSSpin()const{return S;}
QDoubleSpinBox* colorOperationButtons::getLSpin()const{return L;}

QSpinBox* colorOperationButtons::getRSpin()const{return R;}
QSpinBox* colorOperationButtons::getGSpin()const{return G;}
QSpinBox* colorOperationButtons::getBSpin()const{return B;}

//serve per rimpiazzare i controlli usati per la conversione da un tipo ad un altro
void colorOperationButtons::removeSpinConversione(){
    layout->removeItem(layout->itemAtPosition(6,0));

    deleteChildWidgets(l);

    delete l;

}


//Vengono creati i controlli necessari per la conversione dal tipo Hsl al tipo Rgb
void colorOperationButtons::addHsl2Rgb(){
    removeSpinConversione();
    deleteChildWidgets(layout->itemAtPosition(4,1));

    l = new QHBoxLayout;

    btnHsl2Rgb = new QPushButton(tr("HSL TO RGB"));
    btnHsl2Rgb->setFont(*f);

    btnHsl= new QPushButton(tr("Rappresentazione HSL "));
    btnHsl->setFont(*f);


    H = new QDoubleSpinBox;
    H->setRange(0.0,400.0);
    H->setSuffix(" H");
    H->setFont(*f);

    S= new QDoubleSpinBox;
    S->setRange(0.0,100.0);
    S->setSuffix(" S");
    S->setFont(*f);

    L= new QDoubleSpinBox;;
    L->setRange(0.0,100.0);
    L->setSuffix(" L");
    L->setFont(*f);

    layout->removeItem(layout->itemAtPosition(4,1));
    layout->addWidget(btnHsl,4,1,1,2);
    l->addWidget(btnHsl2Rgb);
    l->addWidget(H);
    l->addWidget(S);
    l->addWidget(L);
    layout->addLayout(l,6,0,1,4);

    connect(btnHsl2Rgb,SIGNAL(clicked(bool)),this,SIGNAL(btnHsl2RgbClicked(bool)));
    connect(btnHsl,SIGNAL(clicked(bool)),this,SIGNAL(btnHslClicked(bool)));
}

//Vengono creati i controlli necessari per la conversione dal tipo Rgb al tipo Hsl
void colorOperationButtons::addRgb2Hsl(){
    removeSpinConversione();
    deleteChildWidgets(layout->itemAtPosition(4,1));


    l = new QHBoxLayout;
    btnRgb2Hsl = new QPushButton(tr("RGB To HSL"));
    btnRgb2Hsl->setFont(*f);
    btnRgb = new QPushButton(tr("Rappresentazione RGB "));
    btnRgb->setFont(*f);

    R = new QSpinBox;
    R->setRange(0,255);
    R->setSuffix(" R");
    R->setFont(*f);

    G = new QSpinBox;
    G->setRange(0,255);
    G->setSuffix(" G");
    G->setFont(*f);

    B=new QSpinBox;
    B->setRange(0,255);
    B->setSuffix(" B");
    B->setFont(*f);

    layout->removeItem(layout->itemAtPosition(4,1));
    layout->addWidget(btnRgb,4,1,1,2);
    l->addWidget(btnRgb2Hsl);
    l->addWidget(R);
    l->addWidget(G);
    l->addWidget(B);
    layout->addLayout(l,6,0,1,4);

    connect(btnRgb2Hsl,SIGNAL(clicked(bool)),this,SIGNAL(btnRgb2HslClicked(bool)));
    connect(btnRgb,SIGNAL(clicked(bool)),this,SIGNAL(btnRgbClicked(bool)));
}


void colorOperationButtons::remove(QLayout * layout){
    QLayoutItem* child;
    while(layout->count()!=0)
    {
        child = layout->takeAt(0);
        if(child->layout() != 0)
        {
            remove(child->layout());
        }
        else if(child->widget() != 0)
        {
            delete child->widget();
        }

        delete child;
    }
}

void colorOperationButtons::deleteChildWidgets(QLayoutItem *item) {
    if (item->layout()) {
        for (int i = 0; i < item->layout()->count(); i++) {
            deleteChildWidgets(item->layout()->itemAt(i));
        }
    }
    delete item->widget();
}
