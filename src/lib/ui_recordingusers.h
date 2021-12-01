/********************************************************************************
** Form generated from reading UI file 'recordingusers.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDINGUSERS_H
#define UI_RECORDINGUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordingUsers
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLineEdit *surnameEdit;
    QLineEdit *nameEdit;
    QLineEdit *patronymicEdit;
    QLineEdit *seriesEdit;
    QLineEdit *adressEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *RecordingUsers)
    {
        if (RecordingUsers->objectName().isEmpty())
            RecordingUsers->setObjectName(QString::fromUtf8("RecordingUsers"));
        RecordingUsers->resize(400, 282);
        buttonBox = new QDialogButtonBox(RecordingUsers);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(RecordingUsers);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 381, 220));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::SpanningRole, label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer);

        surnameEdit = new QLineEdit(formLayoutWidget);
        surnameEdit->setObjectName(QString::fromUtf8("surnameEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, surnameEdit);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, nameEdit);

        patronymicEdit = new QLineEdit(formLayoutWidget);
        patronymicEdit->setObjectName(QString::fromUtf8("patronymicEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, patronymicEdit);

        seriesEdit = new QLineEdit(formLayoutWidget);
        seriesEdit->setObjectName(QString::fromUtf8("seriesEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, seriesEdit);

        adressEdit = new QLineEdit(formLayoutWidget);
        adressEdit->setObjectName(QString::fromUtf8("adressEdit"));

        formLayout->setWidget(7, QFormLayout::FieldRole, adressEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer_2);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_6);


        retranslateUi(RecordingUsers);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RecordingUsers, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RecordingUsers, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RecordingUsers);
    } // setupUi

    void retranslateUi(QDialog *RecordingUsers)
    {
        RecordingUsers->setWindowTitle(QCoreApplication::translate("RecordingUsers", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RecordingUsers", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        label_2->setText(QCoreApplication::translate("RecordingUsers", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("RecordingUsers", "\320\230\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("RecordingUsers", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_5->setText(QCoreApplication::translate("RecordingUsers", "\320\241\320\265\321\200\320\270\321\217 \320\270 \320\275\320\276\320\274\320\265\321\200 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("RecordingUsers", "\320\220\320\264\321\200\320\265\321\201 \320\277\321\200\320\276\320\266\320\270\320\262\320\260\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordingUsers: public Ui_RecordingUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDINGUSERS_H
