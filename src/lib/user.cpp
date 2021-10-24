#include "user.hpp"

User::User()
{
    count_visit = 0;
    role = 0;
    selected = false;
}

const QString &User::getSurname() const
{
    return surname;
}

void User::setSurname(const QString &surname_t)
{
    surname = surname_t;
}

const QString &User::getName() const
{
    return name;
}

void User::setName(const QString &name_t)
{
    name = name_t;
}

const QString &User::getPatronymic() const
{
    return patronymic;
}

void User::setPatronymic(const QString &patronymic_t)
{
    patronymic = patronymic_t;
}

const QString &User::getSeries() const
{
    return series;
}

void User::setSeries(const QString &series_t)
{
    series = series_t.trimmed();
}

const QString &User::getAdress() const
{
    return adress;
}

void User::setAdress(const QString &adress_t)
{
    adress = adress_t;
}

const int User::getVisit() const
{
    return count_visit;
}

void User::addVisit()
{
    count_visit++;
}

void User::setVisit(const int visit_counter)
{

    count_visit = visit_counter;
}

const int User::getRole() const
{
    return role;
}

void User::setRole(const int adm)
{
    role = adm;
}

const bool User::getSelect() const
{
    return selected;
}

void User::setSelect(const bool selection)
{
    selected = selection;
}

void User::save(QDataStream &ost) const
{
    ost << surname << name << patronymic << series << role
        << adress << count_visit;
}

void User::load(QDataStream &ist)
{
    ist >> surname >> name >> patronymic >> series >> role
            >> adress >> count_visit;
}
