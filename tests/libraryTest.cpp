#define UNITTEST_CLASS_NAME     libraryTest

#include "unitTestEngine.h"
#include "TestObject.h"
#include "ITestInterface.h"

#if defined(_WIN32) && !defined(GTEST)
namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template<> static std::wstring ToString<TestObject>(const class TestObject& t) { return L"TestObject"; }
        }
    }
}
#endif

UNITTEST_NAMESPACE(UNITTESTENGINE_Tests)

    class InterfaceCheck : public ITestInterface {
    public:
        std::string getData() {
            return std::string("hello");
        }
    };

    UNITTEST_CLASS(UNITTEST_CLASS_NAME)

    UNITTEST_CLASS_INITIALIZE() {}

    UNITTEST_CLASS_CLEANUP() {}

    UNITTEST_METHOD(CompareObjects) {

        TestObject first(1);
        TestObject first2 = first;
        TestObject second(2);

        UNITTEST_ASSERT_EQUAL(first, first2);
        UNITTEST_ASSERT_NOTEQUAL(first, second);
    }

    UNITTEST_METHOD(InterfaceMockup) {

        InterfaceCheck check;

        UNITTEST_ASSERT_EQUAL(check.getData(), std::string("hello"));
    }

    UNITTEST_CLASS_END
UNITTEST_NAMESPACE_END
