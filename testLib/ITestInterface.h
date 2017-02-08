#ifndef UNITTESTENGINE_ITESTINTERFACE_H
#define UNITTESTENGINE_ITESTINTERFACE_H

#include <string>

class ITestInterface {
public:
    virtual std::string getData() = 0;
};

#endif //UNITTESTENGINE_ITESTINTERFACE_H
