/*!
 * \file
 * \brief Конфиг файл
 */
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QtGlobal>
#include <QString>

namespace config
{
    //! Название программы
    const char applicationName[] = QT_TRANSLATE_NOOP("Config", "Hotel Booking");
    //! Версия программы
    const char applicationVersion[] = "20211223";
    //! Название файла с пользователей
    const QString fileUsers = "users.tnb";
    //! Название файла с комнатами
    const QString fileRooms = "rooms.tnb";
    //! Название файла с бронированными комнатами
    const QString fileBookedRooms = "bkdRooms.tnb";
}


#endif // CONFIG_HPP
