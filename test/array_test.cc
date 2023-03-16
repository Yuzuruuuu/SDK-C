#include <array.h>
#include <gtest/gtest.h>

TEST(ArrayTest, HandlesBoolValue) {
  ncsdk_Array* array = ncsdk_Array_New(bool, 10);
  EXPECT_NE(array, nullptr);

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    bool* value = ncsdk_Array_At(bool, array, i);
    EXPECT_NE(value, nullptr);
    EXPECT_FALSE(*value);
  }

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    bool* value = ncsdk_Array_At(bool, array, i);
    EXPECT_NE(value, nullptr);
    *value = true;
  }

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    bool* value = ncsdk_Array_At(bool, array, i);
    EXPECT_NE(value, nullptr);
    EXPECT_TRUE(*value);
  }

  ncsdk_Array_Delete(&array);
  EXPECT_EQ(array, nullptr);
}

TEST(ArrayTest, HandlesIntValue) {
  ncsdk_Array* array = ncsdk_Array_New(int, 10);
  EXPECT_NE(array, nullptr);

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    int* value = ncsdk_Array_At(int, array, i);
    EXPECT_NE(value, nullptr);
    *value = (int)i;
  }

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    int* value = ncsdk_Array_At(int, array, i);
    EXPECT_NE(value, nullptr);
    EXPECT_EQ(*value, i);
  }

  ncsdk_Array_Delete(&array);
  EXPECT_EQ(array, nullptr);
}

TEST(ArrayTest, HandlesDoubleValue) {
  ncsdk_Array* array = ncsdk_Array_New(double, 10);
  EXPECT_NE(array, nullptr);

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    double* value = ncsdk_Array_At(double, array, i);
    EXPECT_NE(value, nullptr);
    *value = (int)i;
  }

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    double* value = ncsdk_Array_At(double, array, i);
    EXPECT_NE(value, nullptr);
    EXPECT_EQ(*value, i);
  }

  ncsdk_Array_Delete(&array);
  EXPECT_EQ(array, nullptr);
}

TEST(ArrayTest, HandlesStringValue) {
  ncsdk_Array* array = ncsdk_Array_New(char*, 10);
  EXPECT_NE(array, nullptr);

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    char** value = ncsdk_Array_At(char*, array, i);
    EXPECT_NE(value, nullptr);
    *value = new char[10];
    sprintf(*value, "%d", (int)i);
  }

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    char** value = ncsdk_Array_At(char*, array, i);
    EXPECT_NE(value, nullptr);
    char expected[10];
    sprintf(expected, "%d", (int)i);
    EXPECT_STREQ(*value, expected);
  }

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    char** value = ncsdk_Array_At(char*, array, i);
    EXPECT_NE(value, nullptr);
    delete[] * value;
  }

  ncsdk_Array_Delete(&array);
  EXPECT_EQ(array, nullptr);
}

TEST(ArrayTest, HandlesFilling) {
  ncsdk_Array* array = ncsdk_Array_New(int, 10);
  EXPECT_NE(array, nullptr);

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    int* value = ncsdk_Array_At(int, array, i);
    EXPECT_NE(value, nullptr);
    *value = (int)i;
  }

  int v = 0;
  ncsdk_Array_Fill(array, &v);

  for (size_t i = 0; i < ncsdk_Array_Size(array); ++i) {
    int* value = ncsdk_Array_At(int, array, i);
    EXPECT_NE(value, nullptr);
    EXPECT_EQ(*value, 0);
  }

  ncsdk_Array_Delete(&array);
  EXPECT_EQ(array, nullptr);
}

TEST(ArrayTest, HandlesOutOfRange) {
  ncsdk_Array* array = ncsdk_Array_New(int, 10);
  EXPECT_NE(array, nullptr);

  int* value = ncsdk_Array_At(int, array, 10);
  EXPECT_EQ(value, nullptr);

  value = ncsdk_Array_At(int, array, -1);
  EXPECT_EQ(value, nullptr);

  ncsdk_Array_Delete(&array);
  EXPECT_EQ(array, nullptr);
}

TEST(ArrayTest, HandlesZeroSize) {
  ncsdk_Array* array = ncsdk_Array_New(int, 0);
  EXPECT_NE(array, nullptr);

  EXPECT_EQ(ncsdk_Array_Size(array), 0);

  int* value = ncsdk_Array_At(int, array, 0);
  EXPECT_EQ(value, nullptr);

  ncsdk_Array_Delete(&array);
  EXPECT_EQ(array, nullptr);
}

TEST(ArrayTest, HandlesMuptileDeletion) {
  ncsdk_Array* array = ncsdk_Array_New(int, 10);
  EXPECT_NE(array, nullptr);

  ncsdk_Array_Delete(&array);
  EXPECT_EQ(array, nullptr);

  ncsdk_Array_Delete(&array);
  EXPECT_EQ(array, nullptr);
}