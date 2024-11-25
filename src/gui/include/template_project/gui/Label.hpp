#pragma once

#include <template_project/common/common.hpp>
#include <QLabel>

BASIC_PROJECT_BEGIN_NAMESPACE

class Label : public QLabel
{
public:
    explicit Label(QLabel* parent = nullptr) :
        QLabel(parent)
    {
        this->setStyleSheet(R"(
                            QLabel {
                                margin: 10px;
                                font-size: 20px;
                            }
                            )");
    }
};

BASIC_PROJECT_END_NAMESPACE