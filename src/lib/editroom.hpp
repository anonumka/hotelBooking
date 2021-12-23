/*!
 * \file
 * \brief Заголовочный файл класса EditRoom
 */
#ifndef EDITROOM_H
#define EDITROOM_H

#include <QDialog>
#include "room.hpp"
#include "user.hpp"

namespace Ui {
class EditRoom;
}

/*!
 * \brief Класс Редактирования комнаты.
 *
 * Данное окно вызывается при создании или редактировании комнаты.
 */

class EditRoom : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit EditRoom(QWidget *parent = 0);
    //! Деконструктор
    ~EditRoom();
    //! Установка значения поля номера комнаты на \a num
    void setRoomNum(int num);
    //! Установка значения поля вместимости комнаты на \a capacity
    void setRoomCapacity(int capacity);
    //! Установка значения поля комфорта комнаты на \a comfort
    void setRoomComfort(QString comfort);
    //! Установка значения поля цены комнаты на \a price
    void setRoomPrice(int price);
    //! Функция, добавляющая номер в вектор занятых номеров комнат
    void setNumOtherRoom(int num);
    //! Установка указателя на редактируемую комнату
    void setRoom(Room *room);
    //! Устанавливает название окна
    void setTitle(QString title);
    //! Конвертация из числа в строку
    QString comfortConvert(int comfort);

public slots:
    //! Проверки перед тем, как сохранить значения для комнаты
    void accept() Q_DECL_OVERRIDE;

private:
    //! Указатель на интерфейс
    Ui::EditRoom *ui;
    //! Указатель на редактируемую комнату
    Room *r;
    //! Вектор с занятыми номерами для комнат
    std::vector<int> vNums;
};

#endif // EDITROOM_H
