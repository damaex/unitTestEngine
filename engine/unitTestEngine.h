#ifndef UNITTESTENGINE_H
#define UNITTESTENGINE_H

#if !defined(UNITTEST_CLASS_NAME)
#error UNITTEST_CLASS_NAME not defined
#endif

#if defined(__linux__) || defined(GTEST)

#include "gtest/gtest.h"
#include <string>

#define UNITTEST_NAMESPACE(name)            namespace name {
#define UNITTEST_NAMESPACE_END                }

#define UNITTEST_CLASS(name)                class name : public ::testing::Test\
{\
protected:\
virtual void SetUp();\
virtual void TearDown();\
};

#define UNITTEST_CLASS_END

#define UNITTEST_CLASS_INITIALIZE()            void UNITTEST_CLASS_NAME::SetUp()
#define UNITTEST_CLASS_CLEANUP()            void UNITTEST_CLASS_NAME::TearDown()

#define UNITTEST_METHOD(name)                TEST_F(UNITTEST_CLASS_NAME, name)

#define UNITTEST_ASSERT(ass)                ASSERT_TRUE(ass)
#define UNITTEST_ASSERT_EQUAL(a, b)            ASSERT_EQ(a, b)
#define UNITTEST_ASSERT_NOTEQUAL(a, b)        ASSERT_NE(a, b)

#define UNITTEST_ASSERT_ISTRUE(a)            ASSERT_TRUE(a);
#define UNITTEST_ASSERT_ISFALSE(a)            ASSERT_FALSE(a);

#define UNITTEST_ASSERT_ISNOTNULL(a)        ASSERT_TRUE(NULL != a)
#define UNITTEST_ASSERT_ISNULL(a)            ASSERT_TRUE(NULL == a)

#define UNITTEST_ASSERT_FAIL()                ASSERT_TRUE(false)


#elif _WIN32


#define UNITTEST_NAMESPACE(name)			namespace name {
#define UNITTEST_NAMESPACE_END				}

#define UNITTEST_CLASS(name)				TEST_CLASS(name)\
{\
public:\

#define UNITTEST_CLASS_END					};

#define	UNITTEST_CLASS_INITIALIZE()		    TEST_METHOD_INITIALIZE(UNITTEST_CLASS_NAME##Init)
#define UNITTEST_CLASS_CLEANUP()		    TEST_METHOD_CLEANUP(UNITTEST_CLASS_NAME##Clean)
#define UNITTEST_METHOD(name)				TEST_METHOD(name)

#define UNITTEST_ASSERT(a)                  Assert::IsTrue(a)
#define UNITTEST_ASSERT_EQUAL(a,b)			Assert::AreEqual(a, b)
#define UNITTEST_ASSERT_NOTEQUAL(a,b)		Assert::AreNotEqual(a, b)

#define UNITTEST_ASSERT_ISTRUE(a)			Assert::IsTrue(a)
#define UNITTEST_ASSERT_ISFALSE(a)			Assert::IsFalse(a)

#define UNITTEST_ASSERT_ISNOTNULL(a)		Assert::IsNotNull(a)
#define UNITTEST_ASSERT_ISNULL(a)           Assert::IsNull(a)

#define UNITTEST_ASSERT_FAIL()              Assert::Fail()

//Test Includes
#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


#elif __APPLE__

//Test Includes
#import <XCTest/XCTest.h>

#define UNITTEST_NAMESPACE(name)
#define UNITTEST_NAMESPACE_END

#define UNITTEST_CLASS(name)				@interface name : XCTestCase\
@end\
@implementation name

#define UNITTEST_CLASS_END					@end

#define	UNITTEST_CLASS_INITIALIZE()		    - (void)setUp
#define UNITTEST_CLASS_CLEANUP()		    - (void)tearDown
#define UNITTEST_METHOD(name)				- (void)test ## name

#define UNITTEST_ASSERT(a)                  XCTAssert(a)
#define UNITTEST_ASSERT_EQUAL(a,b)			XCTAssertEqual(a, b)
#define UNITTEST_ASSERT_NOTEQUAL(a,b)		XCTAssertNotEqual(a, b)

#define UNITTEST_ASSERT_ISTRUE(a)			XCTAssertTrue(a)
#define UNITTEST_ASSERT_ISFALSE(a)			XCTAssertFalse(a)

#define UNITTEST_ASSERT_ISNOTNULL(a)		UNITTEST_ASSERT_ISTRUE(a != NULL)
#define UNITTEST_ASSERT_ISNULL(a)           UNITTEST_ASSERT_ISTRUE(a == NULL)

#define UNITTEST_ASSERT_FAIL()              XCTFail()

#endif

#endif /* UNITTESTENGINE_H */
