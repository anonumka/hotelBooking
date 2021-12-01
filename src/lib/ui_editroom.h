/********************************************************************************
** Form generated from reading UI file 'editroom.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITROOM_H
#define UI_EDITROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditRoom
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QLineEdit *comfortEdit;
    QLineEdit *numEdit;
    QLabel *label_2;
    QLineEdit *priceEdit;
    QLineEdit *capacityEdit;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLabel *label;

    void setupUi(QDialog *EditRoom)
    {
        if (EditRoom->objectName().isEmpty())
            EditRoom->setObjectName(QString::fromUtf8("EditRoom"));
        EditRoom->resize(401, 243);
        buttonBox = new QDialogButtonBox(EditRoom);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 200, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(EditRoom);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 371, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 0, 1, 3);

        comfortEdit = new QLineEdit(gridLayoutWidget);
        comfortEdit->setObjectName(QString::fromUtf8("comfortEdit"));

        gridLayout->addWidget(comfortEdit, 4, 2, 1, 1);

        numEdit = new QLineEdit(gridLayoutWidget);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));
        numEdit->setInputMethodHints(Qt::ImhNone);

        gridLayout->addWidget(numEdit, 2, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        priceEdit = new QLineEdit(gridLayoutWidget);
        priceEdit->setObjectName(QString::fromUtf8("priceEdit"));

        gridLayout->addWidget(priceEdit, 5, 2, 1, 1);

        capacityEdit = new QLineEdit(gridLayoutWidget);
        capacityEdit->setObjectName(QString::fromUtf8("capacityEdit"));

        gridLayout->addWidget(capacityEdit, 3, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);


        retranslateUi(EditRoom);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditRoom, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditRoom, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditRoom);
    } // setupUi

    void retranslateUi(QDialog *EditRoom)
    {
        EditRoom->setWindowTitle(QCoreApplication::translate("EditRoom", "Dialog", nullptr));
        label_8->setText(QCoreApplication::translate("EditRoom", "Create Room:", nullptr));
        label_2->setText(QCoreApplication::translate("EditRoom", "Capacity", nullptr));
        label_3->setText(QCoreApplication::translate("EditRoom", "Comfort", nullptr));
        label_4->setText(QCoreApplication::translate("EditRoom", "Price at day", nullptr));
        label->setText(QCoreApplication::translate("EditRoom", "Num room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditRoom: public Ui_EditRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITROOM_H
