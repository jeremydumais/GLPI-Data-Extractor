/********************************************************************************
** Form generated from reading UI file 'formabout.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMABOUT_H
#define UI_FORMABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAbout
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *LabelName;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormAbout)
    {
        if (FormAbout->objectName().isEmpty())
            FormAbout->setObjectName(QStringLiteral("FormAbout"));
        FormAbout->resize(590, 251);
        gridLayout = new QGridLayout(FormAbout);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        LabelName = new QLabel(FormAbout);
        LabelName->setObjectName(QStringLiteral("LabelName"));
        QFont font;
        font.setPointSize(14);
        LabelName->setFont(font);

        verticalLayout->addWidget(LabelName);

        horizontalSpacer = new QSpacerItem(40, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        label = new QLabel(FormAbout);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(FormAbout);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(FormAbout);

        QMetaObject::connectSlotsByName(FormAbout);
    } // setupUi

    void retranslateUi(QWidget *FormAbout)
    {
        FormAbout->setWindowTitle(QApplication::translate("FormAbout", "\303\200 propos", Q_NULLPTR));
        LabelName->setText(QApplication::translate("FormAbout", "GLPI Data Extractor", Q_NULLPTR));
        label->setText(QApplication::translate("FormAbout", "Jed# Software", Q_NULLPTR));
        label_2->setText(QApplication::translate("FormAbout", "http://www.jedsharpshoftware.com", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormAbout: public Ui_FormAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMABOUT_H
