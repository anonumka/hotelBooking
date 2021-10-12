#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QtGlobal>
#include <QString>

namespace config
{
    const char applicationName[] = QT_TRANSLATE_NOOP("Config", "Hotel Booking");
    const char applicationVersion[] = "20210926";
    const QString fileUsers = "users.tnb";
    const QString fileRooms = "rooms.tnb";
    const QString fileBookedRooms = "bkdRooms.tnb";
}


#endif // CONFIG_HPP
