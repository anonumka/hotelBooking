/********************************************************************************
** Form generated from reading UI file 'bookingroom.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINGROOM_H
#define UI_BOOKINGROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookingRoom
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLabel *label_2;
    QDateEdit *sellingEdit;
    QLabel *label_3;
    QDateEdit *releaseEdit;
    QLabel *label_6;
    QLineEdit *priceEdit;

    void setupUi(QDialog *bookingRoom)
    {
        if (bookingRoom->objectName().isEmpty())
            bookingRoom->setObjectName(QString::fromUtf8("bookingRoom"));
        bookingRoom->resize(400, 184);
        buttonBox = new QDialogButtonBox(bookingRoom);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(bookingRoom);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 9, 381, 111));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_5);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sellingEdit = new QDateEdit(formLayoutWidget);
        sellingEdit->setObjectName(QString::fromUtf8("sellingEdit"));
        sellingEdit->setEnabled(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, sellingEdit);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        releaseEdit = new QDateEdit(formLayoutWidget);
        releaseEdit->setObjectName(QString::fromUtf8("releaseEdit"));
        releaseEdit->setEnabled(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, releaseEdit);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        priceEdit = new QLineEdit(formLayoutWidget);
        priceEdit->setObjectName(QString::fromUtf8("priceEdit"));
        priceEdit->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, priceEdit);


        retranslateUi(bookingRoom);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, bookingRoom, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, bookingRoom, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(bookingRoom);
    } // setupUi

    void retranslateUi(QDialog *bookingRoom)
    {
        bookingRoom->setWindowTitle(QCoreApplication::translate("bookingRoom", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("bookingRoom", "\320\221\321\200\320\276\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\272\320\276\320\274\320\275\320\260\321\202\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("bookingRoom", "\320\224\320\260\321\202\320\260 \320\267\320\260\321\201\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("bookingRoom", "\320\224\320\260\321\202\320\260 \320\262\321\213\321\201\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("bookingRoom", "\320\230\321\202\320\276\320\263\320\276\320\262\320\260\321\217 \321\206\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookingRoom: public Ui_bookingRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINGROOM_H
