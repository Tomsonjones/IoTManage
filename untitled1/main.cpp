#include "mylogin.h"
#include "basewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // 自适应高分辨率
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    BaseWidget w;

    QFile file(":/images/img.qss");  // 根据你的文件位置进行调整
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        w.setStyleSheet(styleSheet); // 应用样式表到 QWidget
    }


    w.show();
    return a.exec();
}
