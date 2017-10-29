/********************************************************************************
** Form generated from reading UI file 'formjobmanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMJOBMANAGEMENT_H
#define UI_FORMJOBMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormJobManagement
{
public:
    QLabel *label;
    QLineEdit *lineEditName;
    QLabel *label_2;
    QPlainTextEdit *plainTextEditTicketIds;
    QLabel *labelTitle;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *FormJobManagement)
    {
        if (FormJobManagement->objectName().isEmpty())
            FormJobManagement->setObjectName(QStringLiteral("FormJobManagement"));
        FormJobManagement->resize(607, 314);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormJobManagement->sizePolicy().hasHeightForWidth());
        FormJobManagement->setSizePolicy(sizePolicy);
        FormJobManagement->setMinimumSize(QSize(0, 0));
        FormJobManagement->setSizeGripEnabled(false);
        label = new QLabel(FormJobManagement);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(92, 90, 81, 16));
        lineEditName = new QLineEdit(FormJobManagement);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(180, 90, 411, 20));
        label_2 = new QLabel(FormJobManagement);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 130, 151, 41));
        plainTextEditTicketIds = new QPlainTextEdit(FormJobManagement);
        plainTextEditTicketIds->setObjectName(QStringLiteral("plainTextEditTicketIds"));
        plainTextEditTicketIds->setGeometry(QRect(180, 130, 411, 71));
        labelTitle = new QLabel(FormJobManagement);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(0, 0, 611, 61));
        QFont font;
        font.setPointSize(20);
        labelTitle->setFont(font);
        labelTitle->setAutoFillBackground(false);
        labelTitle->setStyleSheet(QLatin1String("border-image: url(:/FormJobManagement/Images/Header.png);\n"
"color: rgb(255, 255, 255);"));
        labelTitle->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(FormJobManagement);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 249, 581, 51));
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


        retranslateUi(FormJobManagement);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), FormJobManagement, SLOT(reject()));

        QMetaObject::connectSlotsByName(FormJobManagement);
    } // setupUi

    void retranslateUi(QDialog *FormJobManagement)
    {
        FormJobManagement->setWindowTitle(QApplication::translate("FormJobManagement", "Gestion des travaux", Q_NULLPTR));
        label->setText(QApplication::translate("FormJobManagement", "Nom du travail :", Q_NULLPTR));
        label_2->setText(QApplication::translate("FormJobManagement", "<html><head/><body><p>Liste des num\303\251ros de billets :</p><p>(s\303\251par\303\251 par des virgules)</p></body></html>", Q_NULLPTR));
        labelTitle->setText(QApplication::translate("FormJobManagement", "Gestion des travaux", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("FormJobManagement", "&OK", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("FormJobManagement", "&Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormJobManagement: public Ui_FormJobManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMJOBMANAGEMENT_H
