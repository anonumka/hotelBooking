#ifndef USER_HPP
#define USER_HPP
#include <QString>
#include <QDate>

class User
{
public:
    User();
    const QString &getSurname() const;
    void setSurname(const QString &surname_t);
    const QString &getName() const;
    void setName(const QString &name_t);
    const QString &getPatronymic() const;
    void setPatronymic(const QString &patronymic_t);
    const QString &getSeries() const;
    void setSeries(const QString &series_t);
    const QString &getAdress() const;
    void setAdress(const QString &adress_t);

    const int getVisit() const;
    void addVisit();
    void setVisit(const int visit_counter);
    const int getRole() const;
    void setRole(const int adm);
    const bool getSelect() const;
    void setSelect(const bool selection);

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);

private:
    QString surname;
    QString name;
    QString patronymic;
    QString series;
    QString adress;

    int count_visit;
    int role;
    bool selected;
};

inline QDataStream &operator<<(QDataStream &ost, const User &u)
{
    u.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, User &u)
{
    u.load(ist);
    return ist;
}

#endif // USER_HPP
