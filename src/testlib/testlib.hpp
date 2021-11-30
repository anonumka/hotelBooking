/*!
 * \file
 * \brief Файл основа для тестов
 */
#ifndef TESTLIB_HPP
#define TESTLIB_HPP

#include <QAbstractButton>
#include <QMessageBox>
#include <QVector>

namespace Testlib {

Q_DECL_EXPORT QAbstractButton *click_standard_button(QMessageBox *box, QVector<QMessageBox::StandardButton> buttons);

Q_DECL_EXPORT QMessageBox *get_active_message_box();

Q_DECL_EXPORT void post_active_message_box_click(QVector<QMessageBox::StandardButton> buttons);

Q_DECL_EXPORT void accept_active_message_box();

Q_DECL_EXPORT void post_active_message_box_accept();

} // namespace Testlib
#endif // TESTLIB_HPP
