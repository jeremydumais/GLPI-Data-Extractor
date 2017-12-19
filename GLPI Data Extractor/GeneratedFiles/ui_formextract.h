/********************************************************************************
** Form generated from reading UI file 'formextract.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMEXTRACT_H
#define UI_FORMEXTRACT_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormExtract
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWebEngineView *webEngineView;

    void setupUi(QWidget *FormExtract)
    {
        if (FormExtract->objectName().isEmpty())
            FormExtract->setObjectName(QStringLiteral("FormExtract"));
        FormExtract->resize(887, 545);
        gridLayout = new QGridLayout(FormExtract);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        webEngineView = new QWebEngineView(FormExtract);
        webEngineView->setObjectName(QStringLiteral("webEngineView"));
        webEngineView->setUrl(QUrl(QStringLiteral("http://demo.glpi-project.org/index.php?noAUTO=1")));

        verticalLayout->addWidget(webEngineView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(FormExtract);

        QMetaObject::connectSlotsByName(FormExtract);
    } // setupUi

    void retranslateUi(QWidget *FormExtract)
    {
        FormExtract->setWindowTitle(QApplication::translate("FormExtract", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormExtract: public Ui_FormExtract {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMEXTRACT_H
