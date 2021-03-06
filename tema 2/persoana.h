//
// Created by Daria on 3/30/2020.
//

#ifndef TEMA_2_PERSOANA_H
#define TEMA_2_PERSOANA_H
#include <string>


class persoana {
protected:
    std :: string id;
    std :: string name;
public:
    explicit persoana(std :: string id = "", std :: string name = "");
    persoana(const persoana &a);
    const std :: string &get_id() const;
    const std :: string &get_name() const;
    void setName(std :: string m_name);
    friend std :: istream& operator >> (std :: istream &i, persoana &a);
    friend std :: ostream& operator << (std :: ostream  &o, persoana &a);
    virtual void print (std :: ostream& o);
    persoana& operator = (persoana const &a);
    virtual ~persoana();
};


#endif //TEMA_2_PERSOANA_H
