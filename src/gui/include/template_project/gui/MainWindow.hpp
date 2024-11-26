#pragma once

#include <template_project/common/common.hpp>
#include <QVBoxLayout>
#include <QPushButton>
#include <fmt/format.h>
#include <QMainWindow>
#include <QLineEdit>
#include <QValidator>

BASIC_PROJECT_BEGIN_NAMESPACE

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QMainWindow* parent = nullptr) :
        QMainWindow(parent), m_line(new QLineEdit)
    {
        this->setWindowTitle("乘法表");
        this->resize(900, 500);

        auto* central_widget = new QWidget;
        this->setCentralWidget(central_widget);

        auto* layout = new QVBoxLayout;
        central_widget->setLayout(layout);

        m_line->setValidator(new QDoubleValidator);
        layout->addWidget(m_line);

        auto* button = new QPushButton;
        button->setText("确认");
        layout->addWidget(button);

        connect(button, &QPushButton::clicked, this,
            [this]
            { fmt::print("button clicked, value = {}\n", m_line->text().toDouble()); });
    }

private:
    QLineEdit* m_line;
};

BASIC_PROJECT_END_NAMESPACE