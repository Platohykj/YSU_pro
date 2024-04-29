//
// Created by plato on 24-4-24.
//

#include "student.h"
#include <QDebug>

void Student::display() {
    qInfo() << "name: " << name << " age: " << age << " height: " << height << " weight: " << weight << " id: " << id;
}
