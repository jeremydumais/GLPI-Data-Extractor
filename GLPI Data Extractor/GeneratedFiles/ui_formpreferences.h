/********************************************************************************
** Form generated from reading UI file 'formpreferences.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPREFERENCES_H
#define UI_FORMPREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPreferences
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QLabel *labelTitle;
    QLabel *labelOutputFolder;
    QLineEdit *lineEditGLPIAddress;
    QLabel *labelGLPIAddress;
    QLineEdit *lineEditOutputFolder;
    QPushButton *pushButtonEtcFolder;
    QCheckBox *checkBoxDebugWindow;

    void setupUi(QDialog *FormPreferences)
    {
        if (FormPreferences->objectName().isEmpty())
            FormPreferences->setObjectName(QStringLiteral("FormPreferences"));
        FormPreferences->resize(610, 347);
        horizontalLayoutWidget = new QWidget(FormPreferences);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 290, 581, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(horizontalLayoutWidget);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/FormJobManagement/Images/Ok22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOK->setIcon(icon);

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(horizontalLayoutWidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/FormJobManagement/Images/Cancel22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonCancel);

        labelTitle = new QLabel(FormPreferences);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(0, 0, 611, 61));
        QFont font;
        font.setPointSize(20);
        labelTitle->setFont(font);
        labelTitle->setAutoFillBackground(false);
        labelTitle->setStyleSheet(QLatin1String("border-image: url(:/FormJobManagement/Images/Header.png);\n"
"color: rgb(255, 255, 255);"));
        labelTitle->setAlignment(Qt::AlignCenter);
        labelOutputFolder = new QLabel(FormPreferences);
        labelOutputFolder->setObjectName(QStringLiteral("labelOutputFolder"));
        labelOutputFolder->setGeometry(QRect(10, 121, 191, 20));
        lineEditGLPIAddress = new QLineEdit(FormPreferences);
        lineEditGLPIAddress->setObjectName(QStringLiteral("lineEditGLPIAddress"));
        lineEditGLPIAddress->setGeometry(QRect(200, 85, 381, 20));
        labelGLPIAddress = new QLabel(FormPreferences);
        labelGLPIAddress->setObjectName(QStringLiteral("labelGLPIAddress"));
        labelGLPIAddress->setGeometry(QRect(42, 85, 150, 20));
        lineEditOutputFolder = new QLineEdit(FormPreferences);
        lineEditOutputFolder->setObjectName(QStringLiteral("lineEditOutputFolder"));
        lineEditOutputFolder->setGeometry(QRect(200, 121, 351, 20));
        pushButtonEtcFolder = new QPushButton(FormPreferences);
        pushButtonEtcFolder->setObjectName(QStringLiteral("pushButtonEtcFolder"));
        pushButtonEtcFolder->setGeometry(QRect(550, 120, 31, 22));
        checkBoxDebugWindow = new QCheckBox(FormPreferences);
        checkBoxDebugWindow->setObjectName(QStringLiteral("checkBoxDebugWindow"));
        checkBoxDebugWindow->setGeometry(QRect(12, 154, 201, 20));
        checkBoxDebugWindow->setLayoutDirection(Qt::RightToLeft);
        checkBoxDebugWindow->setAutoFillBackground(true);
        checkBoxDebugWindow->setChecked(false);

        retranslateUi(FormPreferences);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), FormPreferences, SLOT(reject()));

        QMetaObject::connectSlotsByName(FormPreferences);
    } // setupUi

    void retranslateUi(QDialog *FormPreferences)
    {
        FormPreferences->setWindowTitle(QApplication::translate("FormPreferences", "Pr\303\251f\303\251rences", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("FormPreferences", "&OK", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("FormPreferences", "&Annuler", Q_NULLPTR));
        labelTitle->setText(QApplication::translate("FormPreferences", "Pr\303\251f\303\251rences", Q_NULLPTR));
        labelOutputFolder->setText(QApplication::translate("FormPreferences", "Dossier d'enregistrement des fichiers :", Q_NULLPTR));
        labelGLPIAddress->setText(QApplication::translate("FormPreferences", "Adresse web du syst\303\250me GLPI :", Q_NULLPTR));
        pushButtonEtcFolder->setText(QApplication::translate("FormPreferences", "...", Q_NULLPTR));
        checkBoxDebugWindow->setText(QApplication::translate("FormPreferences", "Afficher la fen\303\252tre de d\303\251bogage :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormPreferences: public Ui_FormPreferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPREFERENCES_H
