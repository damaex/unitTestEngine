#include "TestObject.h"

TestObject::TestObject(int value) : p_value(value) {}

TestObject::TestObject(const TestObject &obj) {
    this->p_value = obj.p_value;
}

TestObject &TestObject::operator=(const TestObject &obj) {
    if (this != &obj) {
        this->p_value = obj.p_value;
    }

    return *this;
}

bool TestObject::operator==(const TestObject &other) {
    return (this->p_value == other.p_value);
}

const bool TestObject::operator==(const TestObject &other) const {
    return (this->p_value == other.p_value);
}

bool TestObject::operator!=(const TestObject &other) {
    return !(*this == other);
}

const bool TestObject::operator!=(const TestObject &other) const {
    return !(*this == other);
}

int TestObject::getValue() {
    return this->p_value;
}