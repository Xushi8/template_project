#include <template_project/gui/gui.hpp>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <template_project/gui/Label.hpp>
#include <template_project/gui/MainWindow.hpp>
#include <fmt/format.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    basic_namespace::MainWindow main_window;
    main_window.setWindowTitle("乘法表");
    main_window.resize(900, 500);

    QWidget* central_widget = new QWidget;
    auto* layout = new QGridLayout;
    central_widget->setLayout(layout);
    main_window.setCentralWidget(central_widget);

    for (size_t i = 1; i <= 9; i++)
    {
        for (size_t j = 1; j <= 9; j++)
        {
            auto* label = new basic_namespace::Label;
            label->setText(QString::fromStdString(fmt::format("{} * {} = {}", i, j, i * j)));
            layout->addWidget(label, i - 1, j - 1);
        }
    }

    main_window.show();

    return QApplication::exec();
}