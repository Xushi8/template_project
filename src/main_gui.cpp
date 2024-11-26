#include <template_project/gui/gui.hpp>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <template_project/gui/Label.hpp>
#include <template_project/gui/MainWindow.hpp>
#include <fmt/format.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    basic_namespace::MainWindow main_window;

    main_window.show();

    return QApplication::exec();
}