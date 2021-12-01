/********************************************************************************
** Form generated from reading UI file 'listusers.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTUSERS_H
#define UI_LISTUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListUsers
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_5;
    QDialogButtonBox *buttonBox;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_4;
    QPushButton *resetBtn;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *roleBox;
    QLabel *label_2;
    QComboBox *comboBox;
    QLineEdit *seriesEdit;
    QLineEdit *countEdit;
    QLineEdit *roomEdit;
    QDateEdit *releaseEdit;
    QDateEdit *settlingEdit;

    void setupUi(QDialog *ListUsers)
    {
        if (ListUsers->objectName().isEmpty())
            ListUsers->setObjectName(QString::fromUtf8("ListUsers"));
        ListUsers->resize(404, 289);
        gridLayoutWidget = new QWidget(ListUsers);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 381, 270));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        buttonBox = new QDialogButtonBox(gridLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 10, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        resetBtn = new QPushButton(gridLayoutWidget);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));

        gridLayout->addWidget(resetBtn, 10, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 0, 1, 2);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        roleBox = new QComboBox(gridLayoutWidget);
        roleBox->addItem(QString());
        roleBox->addItem(QString());
        roleBox->addItem(QString());
        roleBox->setObjectName(QString::fromUtf8("roleBox"));

        gridLayout->addWidget(roleBox, 9, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        seriesEdit = new QLineEdit(gridLayoutWidget);
        seriesEdit->setObjectName(QString::fromUtf8("seriesEdit"));
        seriesEdit->setReadOnly(true);

        gridLayout->addWidget(seriesEdit, 2, 1, 1, 1);

        countEdit = new QLineEdit(gridLayoutWidget);
        countEdit->setObjectName(QString::fromUtf8("countEdit"));

        gridLayout->addWidget(countEdit, 8, 1, 1, 1);

        roomEdit = new QLineEdit(gridLayoutWidget);
        roomEdit->setObjectName(QString::fromUtf8("roomEdit"));
        roomEdit->setEnabled(true);
        roomEdit->setReadOnly(true);

        gridLayout->addWidget(roomEdit, 3, 1, 1, 1);

        releaseEdit = new QDateEdit(gridLayoutWidget);
        releaseEdit->setObjectName(QString::fromUtf8("releaseEdit"));
        releaseEdit->setEnabled(true);
        releaseEdit->setReadOnly(true);

        gridLayout->addWidget(releaseEdit, 6, 1, 1, 1);

        settlingEdit = new QDateEdit(gridLayoutWidget);
        settlingEdit->setObjectName(QString::fromUtf8("settlingEdit"));
        settlingEdit->setEnabled(true);
        settlingEdit->setReadOnly(true);

        gridLayout->addWidget(settlingEdit, 5, 1, 1, 1);


        retranslateUi(ListUsers);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ListUsers, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ListUsers, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ListUsers);
    } // setupUi

    void retranslateUi(QDialog *ListUsers)
    {
        ListUsers->setWindowTitle(QCoreApplication::translate("ListUsers", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("ListUsers", "\320\224\320\260\321\202\320\260 \320\262\321\213\321\201\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("ListUsers", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\320\271", nullptr));
        label_8->setText(QCoreApplication::translate("ListUsers", "\320\241\320\265\321\200\320\270\321\217 \320\270 \320\275\320\276\320\274\320\265\321\200 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260", nullptr));
        label->setText(QCoreApplication::translate("ListUsers", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("ListUsers", "\320\232\320\276\320\274\320\275\320\260\321\202\320\260", nullptr));
        resetBtn->setText(QCoreApplication::translate("ListUsers", "Reset", nullptr));
        label_6->setText(QCoreApplication::translate("ListUsers", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217\321\205:", nullptr));
        label_7->setText(QCoreApplication::translate("ListUsers", "\320\240\320\276\320\273\321\214", nullptr));
        roleBox->setItemText(0, QCoreApplication::translate("ListUsers", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        roleBox->setItemText(1, QCoreApplication::translate("ListUsers", "\320\243\320\277\321\200\320\260\320\262\320\273\321\217\321\216\321\211\320\270\320\271", nullptr));
        roleBox->setItemText(2, QCoreApplication::translate("ListUsers", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));

        label_2->setText(QCoreApplication::translate("ListUsers", "\320\224\320\260\321\202\320\260 \320\267\320\260\321\201\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        comboBox->setItemText(0, QString());

    } // retranslateUi

};

namespace Ui {
    class ListUsers: public Ui_ListUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTUSERS_H
