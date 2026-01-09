#include <gtest/gtest.h>
#include <sht45_handler.h>
#include <gmock/gmock.h>
#include "sht45_mock.h"

Mocksensor sensor;

TEST(test, test1){
    ASSERT_EQ(1, 1);
    measure_task(&sensor);
}