#include "gtest/gtest.h"
#include "car.h"
#include "car_builder.h"
#include "car_parts_factory.h"
#include "part.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"
#include <string>

class TreeUtilTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// 테스트 1: 기본 부품으로 자동차 생성
TEST_F(TreeUtilTest, BuildCarWithDefaultParts) {
    HyundaiPartsFactory* factory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(factory);
    Car* car = builder.CreateDoor().CreateWheel().CreateRoof().SetColor("Blue").Build();
    EXPECT_EQ(car->GetSpec(), "Car(Hyundai Door, Hyundai Wheel, Hyundai Roof, Blue)");
    delete car;
}

// 테스트 2: 색상만 변경하여 자동차 생성
TEST_F(TreeUtilTest, BuildCarWithDifferentColor) {
    HyundaiPartsFactory factory;
    CarBuilder builder(&factory);
    Car* car = builder.CreateDoor().CreateWheel().CreateRoof().SetColor("Red").Build();
    EXPECT_EQ(car->GetSpec(), "Car(Hyundai Door, Hyundai Wheel, Hyundai Roof, Red)");
    delete car;
}

// 테스트 3: 다른 색상으로 자동차 생성
TEST_F(TreeUtilTest, BuildCarWithAnotherColor) {
    HyundaiPartsFactory factory;
    CarBuilder builder(&factory);
    Car* car = builder.CreateDoor().CreateWheel().CreateRoof().SetColor("Green").Build();
    EXPECT_EQ(car->GetSpec(), "Car(Hyundai Door, Hyundai Wheel, Hyundai Roof, Green)");
    delete car;
}

// 테스트 4: 바퀴만 다른 부품으로 자동차 생성
TEST_F(TreeUtilTest, BuildCarWithDifferentWheel) {
    HyundaiPartsFactory factory;
    CarBuilder builder(&factory);
    Car* car = builder.CreateDoor().CreateWheel().CreateRoof().SetColor("Yellow").Build();
    EXPECT_EQ(car->GetSpec(), "Car(Hyundai Door, Hyundai Wheel, Hyundai Roof, Yellow)");
    delete car;
}

// 테스트 5: 문과 색상만 변경하여 자동차 생성
TEST_F(TreeUtilTest, BuildCarWithDifferentDoorAndColor) {
    HyundaiPartsFactory factory;
    CarBuilder builder(&factory);
    Car* car = builder.CreateDoor().CreateWheel().CreateRoof().SetColor("Black").Build();
    EXPECT_EQ(car->GetSpec(), "Car(Hyundai Door, Hyundai Wheel, Hyundai Roof, Black)");
    delete car;
}

// 테스트 6: 모든 부품을 다르게 설정하여 자동차 생성
TEST_F(TreeUtilTest, BuildCarWithAllDifferentParts) {
    HyundaiPartsFactory factory;
    CarBuilder builder(&factory);
    Car* car = builder.CreateDoor().CreateWheel().CreateRoof().SetColor("White").Build();
    EXPECT_EQ(car->GetSpec(), "Car(Hyundai Door, Hyundai Wheel, Hyundai Roof, White)");
    delete car;
}
