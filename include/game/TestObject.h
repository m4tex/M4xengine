//
// Created by m4tex on 2023-06-28.
//

#ifndef M4XENGINE_TESTOBJECT_H
#define M4XENGINE_TESTOBJECT_H
#include "rendering/M4xObject.h"

class TestObject : public M4xObject {
public:
    TestObject();
private:
    void Update() override;
};


#endif //M4XENGINE_TESTOBJECT_H
