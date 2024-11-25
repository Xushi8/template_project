#pragma once

#include <template_project/common/common.hpp>
#include <QMainWindow>

BASIC_PROJECT_BEGIN_NAMESPACE

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QMainWindow* parent = nullptr) :
        QMainWindow(parent)
    {
        this->resize(900, 500);
    }
};

BASIC_PROJECT_END_NAMESPACE