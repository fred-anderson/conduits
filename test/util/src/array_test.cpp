#include <gtest/gtest.h>

#include "conduits/util/array.h"

using namespace conduits::util;

TEST(array, default_constructor) {
    array<double> myArray;

    ASSERT_EQ(myArray.length, 0);
    ASSERT_EQ(myArray.data, nullptr);
}


TEST(array, length_constructor) {
    array<float> myArray(10);

    ASSERT_EQ(myArray.length, 10);
    for (int x = 0; x < 10; ++x) {
        ASSERT_EQ(myArray[x], 0.0);
    }
}


TEST(array, memory_constructor) {
    int x[] = { 1, 3, 5, 7, 9 };
    array<int> myArray(x, 3);

    ASSERT_EQ(myArray.length, 3);
    ASSERT_EQ(myArray[0], 1);
    ASSERT_EQ(myArray[1], 3);
    ASSERT_EQ(myArray[2], 5);
}


TEST(array, initializer_list_constructor) {
    array<int> myArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    ASSERT_EQ(myArray.length, 10);
    for (int x = 0; x < myArray.length; ++x) {
        ASSERT_EQ(myArray[x], x + 1);
    }

    myArray = array<int>({ 10, 20, 30 });

    ASSERT_EQ(myArray.length, 3);
    for (int x = 0; x < myArray.length; ++x) {
        ASSERT_EQ(myArray[x], (x + 1) * 10);
    }

    std::initializer_list<int> list = { 0, 5, 10, 15, 20 };
    myArray = array<int>(list);

    ASSERT_EQ(myArray.length, 5);
    for (int x = 0; x < 5; ++x) {
        ASSERT_EQ(myArray[x], x * 5);
    }
}

TEST(array, container_constructor) {
    std::list<std::string> myList({ "this", "is", "a", "test" });
    array<std::string> myArray(myList);

    ASSERT_EQ(myArray.length, 4);
    ASSERT_EQ(myArray[0], "this");
    ASSERT_EQ(myArray[1], "is");
    ASSERT_EQ(myArray[2], "a");
    ASSERT_EQ(myArray[3], "test");

    std::vector<std::string> myVector({ "now", "is", "the", "time" });
    myArray = array<std::string>(myVector);

    ASSERT_EQ(myArray.length, 4);
    ASSERT_EQ(myArray[0], "now");
    ASSERT_EQ(myArray[1], "is");
    ASSERT_EQ(myArray[2], "the");
    ASSERT_EQ(myArray[3], "time");

    std::set<int> mySet({ 5, 4, 3, 2, 1, 10, 9, 8, 7, 6 });
    array<int> intArray(mySet);

    ASSERT_EQ(intArray.length, 10);
    for (int x = 0; x < 10; ++x) {
        ASSERT_EQ(intArray[x], x + 1);
    }
}


TEST(array, assignment_operator) {
    array<std::string> sArray1;
    array<std::string> sArray2 = { "a", "b", "c", "d" };

    sArray1 = sArray2;
    ASSERT_EQ(sArray1.length, sArray2.length);
    for (int x = 0; x < sArray1.length; ++x) {
        ASSERT_EQ(sArray1[x], sArray2[x]);
    }

    sArray1 = array<std::string>({ "this", "is", "the", "hour", "of", "our", "discontent" });
    ASSERT_EQ(sArray1.length, 7);
    ASSERT_EQ(sArray1[0], "this");
    ASSERT_EQ(sArray1[1], "is");
    ASSERT_EQ(sArray1[2], "the");
    ASSERT_EQ(sArray1[3], "hour");
    ASSERT_EQ(sArray1[4], "of");
    ASSERT_EQ(sArray1[5], "our");
    ASSERT_EQ(sArray1[6], "discontent");

    std::vector<std::string> vector = { "it", "was", "a", "dark", "and", "stormy", "night" };
    sArray2 = vector;
    ASSERT_EQ(sArray2.length, 7);
    ASSERT_EQ(sArray2[0], "it");
    ASSERT_EQ(sArray2[1], "was");
    ASSERT_EQ(sArray2[2], "a");
    ASSERT_EQ(sArray2[3], "dark");
    ASSERT_EQ(sArray2[4], "and");
    ASSERT_EQ(sArray2[5], "stormy");
    ASSERT_EQ(sArray2[6], "night");

    std::set<int> mySet({ 5, 4, 3, 2, 1, 10, 9, 8, 7, 6 });
    array<int> intArray;

    intArray = mySet;
    ASSERT_EQ(intArray.length, 10);
    for (int x = 0; x < 10; ++x) {
        ASSERT_EQ(intArray[x], x + 1);
    }
}
