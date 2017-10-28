/********************************************************************************
** Form generated from reading UI file 'formmain.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMAIN_H
#define UI_FORMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMainClass
{
public:
    QAction *action_Quit;
    QAction *action_About;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QProgressBar *progressBarExecution;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_AddJob;
    QPushButton *pushButton_UpdateJob;
    QPushButton *pushButton_DeleteJob;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonExecute;
    QMenuBar *menuBar;
    QMenu *menu_Fichier;
    QMenu *menu_Aide;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FormMainClass)
    {
        if (FormMainClass->objectName().isEmpty())
            FormMainClass->setObjectName(QStringLiteral("FormMainClass"));
        FormMainClass->resize(755, 486);
        action_Quit = new QAction(FormMainClass);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_About = new QAction(FormMainClass);
        action_About->setObjectName(QStringLiteral("action_About"));
        centralWidget = new QWidget(FormMainClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->horizontalHeader()->setMinimumSectionSize(200);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);

        progressBarExecution = new QProgressBar(centralWidget);
        progressBarExecution->setObjectName(QStringLiteral("progressBarExecution"));
        progressBarExecution->setValue(24);
        progressBarExecution->setInvertedAppearance(false);

        verticalLayout->addWidget(progressBarExecution);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_AddJob = new QPushButton(centralWidget);
        pushButton_AddJob->setObjectName(QStringLiteral("pushButton_AddJob"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/FormMain/add22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_AddJob->setIcon(icon);

        horizontalLayout->addWidget(pushButton_AddJob);

        pushButton_UpdateJob = new QPushButton(centralWidget);
        pushButton_UpdateJob->setObjectName(QStringLiteral("pushButton_UpdateJob"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/FormMain/edit22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_UpdateJob->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_UpdateJob);

        pushButton_DeleteJob = new QPushButton(centralWidget);
        pushButton_DeleteJob->setObjectName(QStringLiteral("pushButton_DeleteJob"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/FormMain/Delete22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_DeleteJob->setIcon(icon2);

        horizontalLayout->addWidget(pushButton_DeleteJob);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonExecute = new QPushButton(centralWidget);
        pushButtonExecute->setObjectName(QStringLiteral("pushButtonExecute"));

        horizontalLayout->addWidget(pushButtonExecute);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        FormMainClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FormMainClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 755, 21));
        menu_Fichier = new QMenu(menuBar);
        menu_Fichier->setObjectName(QStringLiteral("menu_Fichier"));
        menu_Aide = new QMenu(menuBar);
        menu_Aide->setObjectName(QStringLiteral("menu_Aide"));
        FormMainClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FormMainClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FormMainClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FormMainClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FormMainClass->setStatusBar(statusBar);

        menuBar->addAction(menu_Fichier->menuAction());
        menuBar->addAction(menu_Aide->menuAction());
        menu_Fichier->addAction(action_Quit);
        menu_Aide->addAction(action_About);

        retranslateUi(FormMainClass);
        QObject::connect(action_Quit, SIGNAL(triggered()), FormMainClass, SLOT(close()));

        QMetaObject::connectSlotsByName(FormMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *FormMainClass)
    {
        FormMainClass->setWindowTitle(QApplication::translate("FormMainClass", "GLPI Data Extractor", Q_NULLPTR));
        action_Quit->setText(QApplication::translate("FormMainClass", "&Quitter", Q_NULLPTR));
        action_About->setText(QApplication::translate("FormMainClass", "\303\200 &propos", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FormMainClass", "Travail", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FormMainClass", "Nombre d'items", Q_NULLPTR));
        pushButton_AddJob->setText(QApplication::translate("FormMainClass", "Ajouter", Q_NULLPTR));
        pushButton_UpdateJob->setText(QApplication::translate("FormMainClass", "Modifier", Q_NULLPTR));
        pushButton_DeleteJob->setText(QApplication::translate("FormMainClass", "Supprimer", Q_NULLPTR));
        pushButtonExecute->setText(QApplication::translate("FormMainClass", "D\303\251marrer l'extraction", Q_NULLPTR));
        menu_Fichier->setTitle(QApplication::translate("FormMainClass", "&Fichier", Q_NULLPTR));
        menu_Aide->setTitle(QApplication::translate("FormMainClass", "&Aide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormMainClass: public Ui_FormMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMAIN_H
