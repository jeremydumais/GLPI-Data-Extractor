/********************************************************************************
** Form generated from reading UI file 'formmain.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMainClass
{
public:
    QAction *action_Quit;
    QAction *action_About;
    QAction *action_Preferences;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidgetJobs;
    QTableWidget *tableWidgetTicketsInJob;
    QLabel *labelExtractInfo;
    QProgressBar *progressBarExecution;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_AddJob;
    QPushButton *pushButton_UpdateJob;
    QPushButton *pushButton_DeleteJob;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonExecute;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menu_Fichier;
    QMenu *menu_Aide;

    void setupUi(QMainWindow *FormMainClass)
    {
        if (FormMainClass->objectName().isEmpty())
            FormMainClass->setObjectName(QStringLiteral("FormMainClass"));
        FormMainClass->resize(879, 585);
        FormMainClass->setWindowOpacity(1);
        FormMainClass->setDocumentMode(false);
        action_Quit = new QAction(FormMainClass);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_About = new QAction(FormMainClass);
        action_About->setObjectName(QStringLiteral("action_About"));
        action_Preferences = new QAction(FormMainClass);
        action_Preferences->setObjectName(QStringLiteral("action_Preferences"));
        centralWidget = new QWidget(FormMainClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidgetJobs = new QTableWidget(centralWidget);
        if (tableWidgetJobs->columnCount() < 2)
            tableWidgetJobs->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetJobs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetJobs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetJobs->setObjectName(QStringLiteral("tableWidgetJobs"));
        tableWidgetJobs->setStyleSheet(QStringLiteral(""));
        tableWidgetJobs->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetJobs->setDragDropOverwriteMode(false);
        tableWidgetJobs->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetJobs->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetJobs->horizontalHeader()->setMinimumSectionSize(200);
        tableWidgetJobs->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidgetJobs->horizontalHeader()->setStretchLastSection(false);

        horizontalLayout_2->addWidget(tableWidgetJobs);

        tableWidgetTicketsInJob = new QTableWidget(centralWidget);
        if (tableWidgetTicketsInJob->columnCount() < 1)
            tableWidgetTicketsInJob->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetTicketsInJob->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        tableWidgetTicketsInJob->setObjectName(QStringLiteral("tableWidgetTicketsInJob"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidgetTicketsInJob->sizePolicy().hasHeightForWidth());
        tableWidgetTicketsInJob->setSizePolicy(sizePolicy);
        tableWidgetTicketsInJob->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetTicketsInJob->setSelectionMode(QAbstractItemView::SingleSelection);

        horizontalLayout_2->addWidget(tableWidgetTicketsInJob);


        verticalLayout->addLayout(horizontalLayout_2);

        labelExtractInfo = new QLabel(centralWidget);
        labelExtractInfo->setObjectName(QStringLiteral("labelExtractInfo"));
        labelExtractInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelExtractInfo->setMargin(5);
        labelExtractInfo->setIndent(5);

        verticalLayout->addWidget(labelExtractInfo);

        progressBarExecution = new QProgressBar(centralWidget);
        progressBarExecution->setObjectName(QStringLiteral("progressBarExecution"));
        progressBarExecution->setValue(24);
        progressBarExecution->setTextVisible(true);
        progressBarExecution->setInvertedAppearance(false);

        verticalLayout->addWidget(progressBarExecution);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        pushButton_AddJob = new QPushButton(centralWidget);
        pushButton_AddJob->setObjectName(QStringLiteral("pushButton_AddJob"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/FormMain/Images/add22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_AddJob->setIcon(icon);

        horizontalLayout->addWidget(pushButton_AddJob);

        pushButton_UpdateJob = new QPushButton(centralWidget);
        pushButton_UpdateJob->setObjectName(QStringLiteral("pushButton_UpdateJob"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/FormMain/Images/edit22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_UpdateJob->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_UpdateJob);

        pushButton_DeleteJob = new QPushButton(centralWidget);
        pushButton_DeleteJob->setObjectName(QStringLiteral("pushButton_DeleteJob"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/FormMain/Images/Delete22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_DeleteJob->setIcon(icon2);

        horizontalLayout->addWidget(pushButton_DeleteJob);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonExecute = new QPushButton(centralWidget);
        pushButtonExecute->setObjectName(QStringLiteral("pushButtonExecute"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/FormMain/Images/lightning.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExecute->setIcon(icon3);

        horizontalLayout->addWidget(pushButtonExecute);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("border-image: url(:/FormMain/Images/Header.png);\n"
"color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(16);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        FormMainClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FormMainClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 879, 21));
        QPalette palette;
        menuBar->setPalette(palette);
        menu_Fichier = new QMenu(menuBar);
        menu_Fichier->setObjectName(QStringLiteral("menu_Fichier"));
        menu_Aide = new QMenu(menuBar);
        menu_Aide->setObjectName(QStringLiteral("menu_Aide"));
        FormMainClass->setMenuBar(menuBar);

        menuBar->addAction(menu_Fichier->menuAction());
        menuBar->addAction(menu_Aide->menuAction());
        menu_Fichier->addAction(action_Preferences);
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
        action_About->setText(QApplication::translate("FormMainClass", "\303\200 &propos...", Q_NULLPTR));
        action_Preferences->setText(QApplication::translate("FormMainClass", "&Pr\303\251f\303\251rences...", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetJobs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FormMainClass", "Travail", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetJobs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FormMainClass", "Nombre d'items", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetTicketsInJob->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("FormMainClass", "Ticket dans le travail", Q_NULLPTR));
        labelExtractInfo->setText(QString());
        pushButton_AddJob->setText(QApplication::translate("FormMainClass", "Ajouter", Q_NULLPTR));
        pushButton_UpdateJob->setText(QApplication::translate("FormMainClass", "Modifier", Q_NULLPTR));
        pushButton_DeleteJob->setText(QApplication::translate("FormMainClass", "Supprimer", Q_NULLPTR));
        pushButtonExecute->setText(QApplication::translate("FormMainClass", "D\303\251marrer l'extraction", Q_NULLPTR));
        label->setText(QApplication::translate("FormMainClass", "GLPI Data Extractor", Q_NULLPTR));
        menu_Fichier->setTitle(QApplication::translate("FormMainClass", "&Fichier", Q_NULLPTR));
        menu_Aide->setTitle(QApplication::translate("FormMainClass", "&Aide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormMainClass: public Ui_FormMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMAIN_H
