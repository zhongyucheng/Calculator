#include "calculator.h"
#include "ui_calculator.h"
#include <QFloat16>
#define PI 3.141592653

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);
    status = input1;
    ui->Btn_sin->setHidden(true);
    ui->Btn_cos->hide();
    ui->Btn_tan->hide();
    ui->Btn_X2->hide();
    ui->Btn_X3->hide();
    ui->Btn_Xsqr->hide();


}

calculator::~calculator()
{
    delete ui;
}

//void calculator::contextMenuEvent(QContextMenuEvent *event)
//{
//    qDebug()<<"鼠标";
//}
//square,s_root,cube,sin,cos,tan
void calculator::input_status_change(calculator::input_key _input)
{
    is_poin = false;

    switch (_input) {
    case sub:
        input_keys = _input;
        status = input2;
        break;
    case min:
        input_keys = _input;
        status = input2;
        break;
    case mul:
        input_keys = _input;
        status = input2;
        break;
    case div:
        input_keys = _input;
        status = input2;
        break;
    case equal:
        status = result;
        is_poin = false;
        is_new_alg = true;
        break;
    case square:
        status = result;
        is_poin = false;
        is_new_alg = true;
        break;
    case s_root:
        status = result;
        is_poin = false;
        is_new_alg = true;
        break;
    case cube:
        status = result;
        is_poin = false;
        is_new_alg = true;
        break;
    case sin:
        status = result;
        is_poin = false;
        is_new_alg = true;
        break;
    case cos:
        status = result;
        is_poin = false;
        is_new_alg = true;
        break;
    case tan:
        status = result;
        is_poin = false;
        is_new_alg = true;
        break;

    default:
        break;
    }

}

void calculator::ouput_answer(calculator::input_key _input)
{
    double temp_answer;
    double temp_1 = ui->Line_input1->text().toDouble();
    //double temp_2 = ui->Line_input2->text().toDouble();
    switch (_input) {
    case sub:
        temp_answer = ui->Line_input1->text().toDouble() + ui->Line_input2->text().toDouble();
        qDebug()<<temp_answer;
        ui->Line_output->setText(QString::number(temp_answer));
        input_history = input_1 + " + " + input_2 + " = " + QString::number(temp_answer);
        ui->Text_hitory->append(input_history);
        status =input1;
        break;
    case min:
        temp_answer = ui->Line_input1->text().toDouble() - ui->Line_input2->text().toDouble();
        ui->Line_output->setText(QString::number(temp_answer));
        input_history = input_1 + " - " + input_2 + " = " + QString::number(temp_answer);
        ui->Text_hitory->append(input_history);
        status =input1;
        break;
    case mul:
        //long double temp;
        temp_answer = ui->Line_input1->text().toDouble() * ui->Line_input2->text().toDouble();
        qDebug()<<temp_answer;
        ui->Line_output->setText(QString::number(temp_answer));
        input_history = input_1 + " × " + input_2 + " = " + QString::number(temp_answer);
        ui->Text_hitory->append(input_history);
        status =input1;
        break;
    case div:
        temp_answer = ui->Line_input1->text().toDouble() / ui->Line_input2->text().toDouble();
        ui->Line_output->setText(QString::number(temp_answer));
        input_history = input_1 + " ÷ " + input_2 + " = " + QString::number(temp_answer);
        ui->Text_hitory->append(input_history);
        status =input1;
        break;
    case equal:
        status = result;
        break;
    case square:
        status = result;
        //double _temp ;//= ui->Line_input1->text().toDouble();
        temp_answer = ui->Line_input1->text().toDouble() * ui->Line_input1->text().toDouble();
        input_history = input_1 + "^2" + " = " + QString::number(temp_answer);
        ui->Text_hitory->append(input_history);
        status =input1;
        break;
    case cube:
        status = result;
        temp_answer = ui->Line_input1->text().toDouble() * ui->Line_input1->text().toDouble()*ui->Line_input1->text().toDouble();
        input_history = input_1 + "^2" + " = " + QString::number(temp_answer);
        ui->Text_hitory->append(input_history);
        status =input1;
        break;
    case s_root:
        //qreal temp;
        status = result;
        //temp_answer = qSqrt(temp)
    case sin:
        //double temp = ui->Line_input1->text().toDouble();
        if(temp_1>0)
        {
            temp_answer = double(temp_1)/180*PI;
        }
        input_history = "sin" + input_1 + " = " + QString::number(temp_answer);
        ui->Text_hitory->append(input_history);
        status = result;
        break;
    case cos:
        status = result;
    case tan:
        status = result;
    default:
        break;
    }
}

void calculator::clear_old_input()
{
    input_1.clear();
    input_2.clear();
    ui->Line_input1->clear();
    ui->Line_input2->clear();
    ui->Line_output->clear();
    is_new_alg =false;
    is_poin = false;
}


void calculator::on_Btn_1_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "1";
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "1";
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    }

}

void calculator::on_Btn_2_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "2";
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "2";
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    }

}

void calculator::on_Btn_3_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "3";
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "3";
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    }

}

void calculator::on_Btn_4_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "4";
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "4";
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    }

}

void calculator::on_Btn_5_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "5";
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "5";
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    }
}

void calculator::on_Btn_6_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "6";
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "6";
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    }
}

void calculator::on_Btn_7_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "7";
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "7";
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    }

}

void calculator::on_Btn_8_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "8";
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "8";
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    }

}

void calculator::on_Btn_9_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "9";
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "9";
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    }

}

void calculator::on_Btn_0_clicked()
{
    if(is_new_alg) clear_old_input();
    switch (status) {
    case input1:
        if(!(ui->Line_input1->text().isEmpty())){
        input_temp = ui->Line_input1->text();
        input_1 = ui->Line_input1->text() + "0";
        ui->Line_input1->setText(input_1);
        }
        break;
    case input2:
        if((!ui->Line_input2->text().isEmpty())){
        input_temp = ui->Line_input2->text();
        input_2 = ui->Line_input2->text() + "0";
        ui->Line_input2->setText(input_2);
        }
        break;
    case result:
        break;
    }
}

void calculator::on_Btn_nega_sign_clicked()
{
    //if(is_new_alg) clear_old_input();
    double temp;
    switch (status) {
    case input1:
        input_1 = ui->Line_input1->text();
        temp = input_1.toDouble() * -1;
        input_1 = QString::number(temp);
        ui->Line_input1->setText(input_1);
        break;
    case input2:
        input_2 = ui->Line_input2->text();
        temp = input_2.toDouble() * -1;
        input_2 = QString::number(temp);
        ui->Line_input2->setText(input_2);
        break;
    case result:
        break;
    default:
        break;
    }
}


void calculator::on_Btn_point_clicked()
{
    if(!is_poin)
    {
        switch (status) {
        case input1:
            if(!(ui->Line_input1->text().isEmpty()))
            {
                input_temp = ui->Line_input1->text();
                input_1 = ui->Line_input1->text() + ".";
                ui->Line_input1->setText(input_1);
                is_poin =true;
            }
            break;
        case input2:
            if(!(ui->Line_input2->text().isEmpty()))
            {
                input_temp = ui->Line_input2->text();
                input_2 = ui->Line_input2->text() + ".";
                ui->Line_input2->setText(input_2);
                is_poin =true;
            }

            break;
        case result:
            is_poin = true;
            break;
        }
    }
}



void calculator::on_Btn_ce_clicked()
{
    ui->Line_input1->clear();
    ui->Line_input2->clear();
    ui->Line_output->clear();
    input_temp.clear();
    input_1.clear();
    input_2.clear();
    status = input1;
    is_poin = false;

}

void calculator::on_Btn_sub_clicked()
{
    input_status_change(sub);
    ui->Lable_alg->setText("+");

}


void calculator::on_Btn_minus_clicked()
{
    input_status_change(min);
    ui->Lable_alg->setText("-");

}

void calculator::on_Btn_mul_clicked()
{
    input_status_change(mul);
    ui->Lable_alg->setText("×");
}

void calculator::on_Btn_div_clicked()
{
    input_status_change(div);
    ui->Lable_alg->setText("÷");
}

void calculator::on_Btn_X2_clicked()
{
    input_status_change(square);
    ui->Lable_alg->setText("^2");

}

void calculator::on_Btn_X3_clicked()
{
    input_status_change(square);
    ui->Lable_alg->setText("^3");
}

void calculator::on_Btn_Xsqr_clicked()
{
    input_status_change(square);
    ui->Lable_alg->setText("^1/2");
}

void calculator::on_Btn_sin_clicked()
{
    input_status_change(square);
    ui->Lable_alg->setText("sin");
}


void calculator::on_Btn_equa_clicked()
{
    input_status_change(equal);
    ouput_answer(input_keys);
    //ui->Lable_alg->setText("");
}




void calculator::on_Btn_OF_clicked()
{
    ui->Line_input1->clear();
    ui->Line_input2->clear();
    ui->Line_output->clear();
    ui->Text_hitory->clear();
    input_temp.clear();
    input_1.clear();
    input_2.clear();
    status = input1;

    is_poin = false;
}



void calculator::on_Btn_back_clicked()
{

    if(is_new_alg) clear_old_input();
    switch (status) {
        case input1:
//        QString tem;
//        tem = input_1.left(4);
        input_1 =input_1.left(input_1.length()-1);
        ui->Line_input1->setText(input_1);
        break ;
        case input2:
        if(input_2.length())
        {
            input_2 =input_2.left(input_2.length()-1);
            ui->Line_input2->setText(input_2);
        }else
        {
            status = input1;
        }

        break ;
        case result:
        break ;
    default:
        break;

    }
}



