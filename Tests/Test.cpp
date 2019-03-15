//
// Created by max on 20.02.19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../MyList.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test{
    public:
        MyList<int> testExample;
        MyList<char> testExampleChar;
        ClassDeclaration(){
            testExample;
            testExampleChar;
        }
    };
}

TEST_F(ClassDeclaration, PushBackTest){
    ASSERT_EQ(nullptr,testExampleChar.ToArr()); //Check that list is empty
    int expect[] = {'1','2','3'};
    testExampleChar.PushBack('1');
    testExampleChar.PushBack('2');
    testExampleChar.PushBack('3');
    char *result = testExampleChar.ToArr();
    for ( unsigned int i = 0; i < 3; ++i )
        ASSERT_EQ(expect[i], result[i]); //Check normal work PushBack {1,2,3}
    delete result, expect, testExample;
}

TEST_F(ClassDeclaration, PushFrontTest){
    ASSERT_EQ(nullptr,testExample.ToArr()); //Check that list is empty
    int expect[] = {3,2,1};
    testExample.PushFront(1);
    testExample.PushFront(2);
    testExample.PushFront(3);
    int *result = testExample.ToArr();
    for ( unsigned int i = 0; i < testExample.GetSize(); ++i )
        ASSERT_EQ(expect[i], result[i]); //Check normal work PushFront {3,2,1}
    delete result, expect, testExample;
}

TEST_F(ClassDeclaration, PopBackTest){
    ASSERT_THROW(testExample.PopBack(), length_error); //Check pop of emtpy list
    int expect[] = {3};
    testExample.PushFront(2);
    testExample.PushFront(3);
    testExample.PopBack();
    int *result = testExample.ToArr();
    for ( unsigned int i = 0; i < testExample.GetSize(); ++i )
        ASSERT_EQ(expect[i],result[i]); //Check normal pop
    testExample.PopBack();
    ASSERT_EQ(nullptr,testExample.ToArr()); //Check pop on list with 1 element
    ASSERT_THROW(testExample.PopBack(), length_error); //Check empty list
    delete result, expect, testExample;
}

TEST_F(ClassDeclaration, PopFrontTest){
    ASSERT_THROW(testExample.PopFront(), length_error);
    int expect[] = {2};
    testExample.PushFront(2);
    testExample.PushFront(3);
    testExample.PopFront();
    int *result = testExample.ToArr();
    for ( unsigned int i = 0; i < testExample.GetSize(); ++i )
        ASSERT_EQ(expect[i], result[i]);
    testExample.PopFront();
    ASSERT_EQ(nullptr,testExample.ToArr());
    ASSERT_THROW(testExample.PopFront(), length_error);
    delete result;
}

TEST_F(ClassDeclaration, InsertTest){
    ASSERT_THROW(testExample.Insert(1,10), invalid_argument);
    ASSERT_THROW(testExample.Insert(1,-5), invalid_argument);
    int expect[] = {5,7,6};
    testExample.Insert(5,0);
    testExample.Insert(6,1);
    testExample.Insert(7,1);
    int *result = testExample.ToArr();
    for ( unsigned int i = 0; i < testExample.GetSize(); ++i )
        ASSERT_EQ(expect[i], result[i]);
    ASSERT_THROW(testExample.Insert(1,5), invalid_argument);
    delete result;
}

TEST_F(ClassDeclaration, AtTest){
    ASSERT_THROW(testExample.At(-1), invalid_argument);
    ASSERT_THROW(testExample.At(5),invalid_argument);

    testExample.PushBack(1);
    testExample.PushBack(2);
    testExample.PushBack(3);

    ASSERT_EQ(2, testExample.At(1));
    ASSERT_THROW(testExample.At(5),invalid_argument);
}

TEST_F(ClassDeclaration, RemoveTest){
    ASSERT_THROW(testExample.Remove(-5), invalid_argument);
    ASSERT_THROW(testExample.Remove(5), invalid_argument);
    ASSERT_THROW(testExample.Remove(0), invalid_argument);

    int expect[] = {1,3};

    testExample.PushBack(1);
    testExample.PushBack(2);
    testExample.PushBack(3);
    testExample.Remove(1);
    int *result = testExample.ToArr();
    for ( unsigned int i = 0; i < testExample.GetSize(); ++i )
        ASSERT_EQ(expect[i], result[i]);
    ASSERT_THROW(testExample.Remove(5), invalid_argument);
    delete result;
}

TEST_F(ClassDeclaration, GetSizeTest){
    ASSERT_EQ(0, testExample.GetSize());
    testExample.PushBack(1);
    ASSERT_EQ(1, testExample.GetSize());
    testExample.PushFront(2);
    ASSERT_EQ(2, testExample.GetSize());
    testExample.Insert(3,1);
    ASSERT_EQ(3, testExample.GetSize());
    testExample.Remove(0);
    ASSERT_EQ(2, testExample.GetSize());
    testExample.PopFront();
    ASSERT_EQ(1, testExample.GetSize());
    testExample.PopBack();
    ASSERT_EQ(0, testExample.GetSize());
    testExample.PushBack(1);
    testExample.Clear();
    ASSERT_EQ(0, testExample.GetSize());
}

TEST_F(ClassDeclaration, ClearTest){
    testExample.PushBack(1);
    testExample.PushBack(2);
    testExample.PushBack(3);

    testExample.Clear();
    ASSERT_EQ(nullptr, testExample.ToArr());
}

TEST_F(ClassDeclaration, SetTest){
    ASSERT_THROW(testExample.Set(5, -5), invalid_argument);
    ASSERT_THROW(testExample.Set(5, 0), invalid_argument);

    testExample.PushBack(1);
    testExample.PushBack(2);
    testExample.PushBack(3);
    testExample.Set(5,2);

    int expect[] = {1,2,5};
    int *result = testExample.ToArr();

    for ( unsigned int i = 0; i < testExample.GetSize(); ++i )
        ASSERT_EQ(expect[i], result[i]);

    ASSERT_THROW(testExample.Set(5, 5), invalid_argument);
    delete result;
}

