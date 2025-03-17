#include "gtest/gtest.h"
#include "car.h"
#include "car_builder.h"
#include "car_parts_factory.h"
#include "part.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"
#include "hyundai_parts_factory.h"
#include "kia_parts_factory.h"
#include <string>

class CarBuilderTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(CarBuilderTest, test1) {
    HyundaiPartsFactory* hyundaiFactory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(hyundaiFactory);
    Car* car =
    builder.CreateDoor().CreateWheel().CreateRoof().SetColor("Black").Build();
    EXPECT_EQ(car->GetSpec(),
    "Car([hyundai] Door, [hyundai] Wheel, [hyundai] Roof, Black)");
    delete car;
}

TEST_F(CarBuilderTest, test2) {
    HyundaiPartsFactory* hyundaiFactory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(hyundaiFactory);
    Car* car = builder.CreateDoor().CreateWheel().SetColor("Purple").Build();
    EXPECT_EQ(car->GetSpec(), "Car([hyundai] Door, [hyundai] Wheel, Purple)");
    delete car;
}

TEST_F(CarBuilderTest, test3) {
    KiaPartsFactory* kiaFactory = KiaPartsFactory::GetInstance();
    CarBuilder builder(kiaFactory);
    Car* car = builder.CreateDoor().CreateRoof().SetColor("Orange").Build();
    EXPECT_EQ(car->GetSpec(), "Car([kia] Door, [kia] Roof, Orange)");
    delete car;
}

TEST_F(CarBuilderTest, test4) {
    HyundaiPartsFactory* hyundaiFactory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(hyundaiFactory);
    Car* car = builder.CreateDoor().CreateWheel().CreateRoof().Build();
    EXPECT_EQ(car->GetSpec(),
    "Car([hyundai] Door, [hyundai] Wheel, [hyundai] Roof)");
    delete car;
}

TEST_F(CarBuilderTest, test5) {
    HyundaiPartsFactory* hyundaiFactory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(hyundaiFactory);

    Car* car1 =
    builder.CreateDoor().CreateWheel().CreateRoof().Build();
    EXPECT_EQ(car1->GetSpec(),
    "Car([hyundai] Door, [hyundai] Wheel, [hyundai] Roof)");
    delete car1;

    Car* car2 =
    builder.CreateDoor().CreateWheel().CreateRoof().Build();
    EXPECT_EQ(car2->GetSpec(),
    "Car([hyundai] Door, [hyundai] Wheel, [hyundai] Roof)");
    delete car2;
}

TEST_F(CarBuilderTest, test6) {
    KiaPartsFactory* kiaFactory = KiaPartsFactory::GetInstance();
    CarBuilder builder(kiaFactory);
    Car* car =
    builder.CreateDoor().CreateWheel().CreateRoof().Build();
    EXPECT_EQ(car->GetSpec(),
    "Car([kia] Door, [kia] Wheel, [kia] Roof)");
    delete car;
}
