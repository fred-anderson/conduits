/*
 * This file is needed in every "Google Test" project to supply a main function,
 * initialize the google test system, and execute all registered tests.
 *
 * Individual tests are functions created with the TEST macro provided by gtest.h and
 * do not need to be referenced here in any way. The TEST macro performs all necessary
 * registration for a given test.
 */

#include <gtest/gtest.h>

using namespace testing;

int main(int ac, char* av[]) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

