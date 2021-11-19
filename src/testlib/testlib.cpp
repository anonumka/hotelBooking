#include "testlib.hpp"

#include <QApplication>
#include <QMessageBox>
#include <QTimer>

namespace Testlib {

QAbstractButton *click_standard_button(QMessageBox *box, QVector<QMessageBox::StandardButton> buttons)
{
    if (!box)
    {
        return nullptr;
    }
    for (auto b : buttons)
    {
        QAbstractButton *ab = box->button(b);
        if (ab)
        {
            ab->click();
            return ab;
        }
    }
    return nullptr;
}

QMessageBox *get_active_message_box()
{
    return dynamic_cast<QMessageBox *>(QApplication::activeModalWidget());
}

void post_active_message_box_click(QVector<QMessageBox::StandardButton> buttons)
{
    QTimer::singleShot(0, [=]() { click_standard_button(get_active_message_box(), buttons); });
}

void accept_active_message_box()
{
    QMessageBox *box = get_active_message_box();
    if (box)
    {
        box->accept();
    }
}

void post_active_message_box_accept()
{
    QTimer::singleShot(0, [=]() { accept_active_message_box(); });
}

} // namespace Testlib
