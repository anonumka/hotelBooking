# Информационная система гостиниц Hotel Booking
Hotel Booking - система комнат в гостинице, имеющая авторизацию, создание и редактирование комнат и пользователей, бронирование комнат на определенные даты.
Данная система написана на языке C++ с использованием фреймворка Qt.

Работоспособность проверена на операционных системах Windows (10 версии 20H2 и 11 версии 21H2) и Ubuntu (версия 20.04).

#Установка
1. Скачать проект и запустить в Qt Creator.
2. Собрать проект.

#Собрать образ
1. Скачать проект и запустить в Qt Creator.
2. Собрать проект.
3. Перейти в путь сборки проекта. 
4. Перетащить lib.exe в файл windeployqt.exe, находящийся по пути %QT_DIR%/%VERSION%/mingw%MINGW_VERSION%/bin.
5. Дождаться завершения сборки и запустить приложение.
6. Если во время запуска будет не хватать библиотек для запуска, то вручную перекинуть недостающие библиотеки из %QT_DIR%/%VERSION%/mingw%MINGW_VERSION%/bin.