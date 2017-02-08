#ifndef UNITTESTENGINE_TESTOBJECT_H
#define UNITTESTENGINE_TESTOBJECT_H

class TestObject {
private:
    int p_value;
public:
    TestObject(int value);

    TestObject(const TestObject &obj);

    TestObject &operator=(const TestObject &obj);

    bool operator==(const TestObject &other);
    const bool operator==(const TestObject &other) const;

    bool operator!=(const TestObject &other);
    const bool operator!=(const TestObject &other) const;

    int getValue();
};

#endif //UNITTESTENGINE_TESTOBJECT_H
