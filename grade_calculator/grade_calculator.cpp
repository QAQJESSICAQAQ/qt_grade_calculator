#include "grade_calculator.h"
#include "ui_grade_calculator.h"
#include <QString>

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);

    QObject::connect(ui->horizontalSlider1,SIGNAL(valueChanged(int)),
                     ui->spinBox1,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider2,SIGNAL(valueChanged(int)),
                     ui->spinBox2,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider3,SIGNAL(valueChanged(int)),
                     ui->spinBox3,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider4,SIGNAL(valueChanged(int)),
                     ui->spinBox4,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider5,SIGNAL(valueChanged(int)),
                     ui->spinBox5,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider6,SIGNAL(valueChanged(int)),
                     ui->spinBox6,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider7,SIGNAL(valueChanged(int)),
                     ui->spinBox7,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider8,SIGNAL(valueChanged(int)),
                     ui->spinBox8,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider9,SIGNAL(valueChanged(int)),
                     ui->spinBox9,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider10,SIGNAL(valueChanged(int)),
                     ui->spinBox10,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider11,SIGNAL(valueChanged(int)),
                     ui->spinBox11,SLOT(setValue(int)));

    QObject::connect(ui->radioButtonA,SIGNAL(clicked()),
                    this,SLOT(compute_overall1()));
    QObject::connect(ui->radioButtonB,SIGNAL(clicked()),
                    this,SLOT(compute_overall2()));
    QString text ="Final Grade";
    ui->label_14->setText(text);

}



grade_calculator::~grade_calculator()
{
    delete ui;
}

#include <iostream>>

void grade_calculator::compute_overall1(){
    std::cout << "compute_overall1 start" << std::endl;
    grade=0.0;
    int hw1 =ui->spinBox1->value();
    int hw2 =ui->spinBox2->value();
    int hw3 =ui->spinBox3->value();
    int hw4 =ui->spinBox4->value();
    int hw5 =ui->spinBox5->value();
    int hw6 =ui->spinBox6->value();
    int hw7 =ui->spinBox7->value();
    int hw8 =ui->spinBox8->value();
    std::cout << "compute_overall1 got hw" << std::endl;
    std::vector<int> vec={hw1,hw2,hw3,hw4,hw5,hw6,hw7,hw8};
    int min=hw1;
    for (int i=0;i<8;i++){
         if (vec[i]<min)
         min=vec[i];
}
    int homework = 0;
    for (int i=0;i<8; i++){
        homework+=vec[i];

    }
    std::cout << "compute_overall1 loop 2" << std::endl;
    homework-=min;
    double hw=homework/700.0*25;
    int midterm1 =ui->spinBox9->value();
    int midterm2 =ui->spinBox10->value();
    int finalexam= ui->spinBox11->value();
    double mid =(midterm1*20/100.0)+(midterm2/100.0*20);
    double final=finalexam*35/100;
    grade=hw+mid+final;

    emit ui->label_14->setText(QString::number(grade));
    ui->label_14->repaint();
    std::cout << "compute_overall1 end grade = " << grade << std::endl;
    return;
}




void grade_calculator::compute_overall2(){
    grade=0.0;
    int hw1 =ui->spinBox1->value();
    int hw2 =ui->spinBox2->value();
    int hw3 =ui->spinBox3->value();
    int hw4 =ui->spinBox4->value();
    int hw5 =ui->spinBox5->value();
    int hw6 =ui->spinBox6->value();
    int hw7 =ui->spinBox7->value();
    int hw8 =ui->spinBox8->value();
    std::vector<int> vec={hw1,hw2,hw3,hw4,hw5,hw6,hw7,hw8};
    int min=hw1;
    for (int i=0;i<8;i++){
         if (vec[i]<min)
         min=vec[i];
}
    int homework = 0;
    for (int i=0;i<8; i++){
        homework+=vec[i];

    }
    homework-=min;
    double hw=homework/700.0*25;
    int midterm1 =ui->spinBox9->value();
    int midterm2 =ui->spinBox10->value();
    int finalexam= ui->spinBox11->value();
    double highest_mid=midterm1;
    if (midterm2>midterm1) highest_mid =midterm2;
    double mid=highest_mid/100.0*30;
    double final=finalexam/100.0*44;
    grade=hw+mid+final;
    ui->label_14->setText(QString::number(grade));
    ui->label_14->repaint();
    std::cout << "compute overall 2, text = " << ui->label_14->text().toStdString()  << std::endl;
    return;
}




