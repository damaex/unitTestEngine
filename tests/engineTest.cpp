#define UNITTEST_CLASS_NAME     engineTest

#include "unitTestEngine.h"

UNITTEST_NAMESPACE(UNITTESTENGINE_Tests)

    static int staticValue = 0;

    UNITTEST_CLASS(UNITTEST_CLASS_NAME)

    UNITTEST_CLASS_INITIALIZE() {}

    UNITTEST_CLASS_CLEANUP() {}

    UNITTEST_METHOD(ASSERT) {
        UNITTEST_ASSERT(true);
    }

    UNITTEST_METHOD(ASSERT_EQUAL) {
        UNITTEST_ASSERT_EQUAL(true, true);
        UNITTEST_ASSERT_NOTEQUAL(true, false);
    }

    UNITTEST_METHOD(ASSERT_TRUE) {
        UNITTEST_ASSERT_ISTRUE(true);
        UNITTEST_ASSERT_ISFALSE(false);
    }

    UNITTEST_METHOD(ASSERT_NULL) {
        int i = 12;
        int *p = &i;
        int *o = NULL;

        UNITTEST_ASSERT_ISNOTNULL(p);
        UNITTEST_ASSERT_ISNULL(o);
    }

    UNITTEST_METHOD(STATICS) {
        UNITTEST_ASSERT_EQUAL(staticValue, 0);
        staticValue = 10;
        UNITTEST_ASSERT_NOTEQUAL(staticValue, 0);
        UNITTEST_ASSERT_EQUAL(staticValue, 10);
    }

    UNITTEST_CLASS_END
UNITTEST_NAMESPACE_END
