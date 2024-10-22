#include "registerdialog.h"
#include "ui_registerdialog.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);

    m_pMySqlite = new MySqlite ;

    //设置注册弹窗的窗口标题
    setWindowTitle("注册");
    //设置成密码模式
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    //给用户一个提示
    ui->passwordLineEdit->setToolTip("密码必须包含一个大写字母且不能有空格");

    //返回按钮和槽函数
    connect(ui->pushButton_quit,&QAbstractButton::clicked,this,[=](){
        this->close();
    });

    //注册按钮
    connect(ui->pushButton_Register, &QPushButton::clicked, this, &RegisterDialog::onRegisterButtonClicked);
}

void RegisterDialog::onRegisterButtonClicked()
{
    QString username = getUsername();
    QString password = getPassword();
    QString email = getEmail();
    QString phone = getPhone();
    QString nickname = getNickname();

    // 调用 UserRegister 函数来处理注册逻辑
    if (m_pMySqlite->UserRegister(username, password, email, phone, nickname)) {
        qDebug() << "Register success";
        QMessageBox::information(this, "注册成功", "恭喜，您已成功注册！");
        accept();  // 成功后关闭对话框
    } else {
        qDebug() << "Register failed";
        QMessageBox::warning(this, "注册失败", "注册失败，请检查输入信息。");
        // 不调用 accept()，保持对话框打开
    }
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

QString RegisterDialog::getUsername()  {
    return ui->usernameLineEdit->text();
}

QString RegisterDialog::getPassword()  {
    return ui->passwordLineEdit->text();
}

QString RegisterDialog::getEmail()  {
    return ui->emailLineEdit->text();
}

QString RegisterDialog::getPhone()  {
    return ui->phoneLineEdit->text();
}

QString RegisterDialog::getNickname()  {
    return ui->nicknameLineEdit->text();
}
