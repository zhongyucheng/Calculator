#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QDebug>
#include <QContextMenuEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();

private slots:
    void on_Btn_1_clicked();

    void on_Btn_2_clicked();

    void on_Btn_3_clicked();

    void on_Btn_4_clicked();

    void on_Btn_5_clicked();

    void on_Btn_6_clicked();

    void on_Btn_7_clicked();

    void on_Btn_8_clicked();

    void on_Btn_9_clicked();

    void on_Btn_ce_clicked();

    void on_Btn_sub_clicked();

    void on_Btn_minus_clicked();

    void on_Btn_mul_clicked();

    void on_Btn_equa_clicked();

    void on_Btn_div_clicked();

    void on_Btn_point_clicked();

    void on_Btn_0_clicked();

    void on_Btn_OF_clicked();

    void on_Btn_nega_sign_clicked();

    void on_Btn_back_clicked();

    void on_Btn_X2_clicked();

    void on_Btn_X3_clicked();

    void on_Btn_Xsqr_clicked();

    void on_Btn_sin_clicked();

private:
    Ui::calculator *ui;

    //void contextMenuEvent(QContextMenuEvent *event) override;



    long double sub_1 = 0;
    long double sub_2 = 0;
    long double answer = 0;
    QString input_1;
    QString input_2;
    QString input_temp;
    QString input_history;

    enum input_status{input1 =1,input2,result};
    enum input_status status = input1;
    enum input_key{sub,min,mul,div,equal,square,s_root,cube,sin,cos,tan};
    enum input_key input_keys = sub;
    int _sta =1;
    //输入状态
    void input_status_change(input_key _input);
    void ouput_answer(input_key _input);

    //enum color { red, green, blue } c;
    //新一轮计算清楚旧的数据
    void clear_old_input();

    //是否输入过小数点
    bool is_poin =false;
    //是否已经按过一次加减乘除之类的运算符号
    bool is_alg_key = false;
    //是否开始新一轮计算
    bool is_new_alg = false;

};
#endif // CALCULATOR_H
