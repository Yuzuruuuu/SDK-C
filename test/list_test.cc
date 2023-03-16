#include <gtest/gtest.h>
#include <list.h>

TEST(ListTest, HandlesNormalValue) {
  ncsdk_List* list = ncsdk_List_New(int);
  EXPECT_NE(list, nullptr);

  for (int i = 0; i < 10; ++i) {
    ncsdk_List_PushBack(list, &i);
  }

  EXPECT_EQ(ncsdk_List_Size(list), 10);

  for (int i = 0; i < 10; ++i) {
    int* value = ncsdk_List_At(int, list, i);
    EXPECT_EQ(*value, i);
  }

  ncsdk_List_Delete(&list);
  EXPECT_EQ(list, nullptr);
}

TEST(ListTest, HandlesPointer) {
  ncsdk_List* list = ncsdk_List_New(int*);
  EXPECT_NE(list, nullptr);

  for (int i = 0; i < 10; ++i) {
    int* value = new int(i);
    ncsdk_List_PushBack(list, &value);
  }

  EXPECT_EQ(ncsdk_List_Size(list), 10);

  for (int i = 0; i < 10; ++i) {
    int** value = ncsdk_List_At(int*, list, i);
    EXPECT_EQ(**value, i);
    delete *value;
  }

  ncsdk_List_Delete(&list);
  EXPECT_EQ(list, nullptr);
}

TEST(ListTest, HandlesClearing) {
  ncsdk_List* list = ncsdk_List_New(int);
  EXPECT_NE(list, nullptr);

  for (int i = 0; i < 10; ++i) {
    ncsdk_List_PushBack(list, &i);
  }

  EXPECT_EQ(ncsdk_List_Size(list), 10);

  ncsdk_List_Clear(list);

  EXPECT_EQ(ncsdk_List_Size(list), 0);

  ncsdk_List_Delete(&list);
  EXPECT_EQ(list, nullptr);
}

TEST(ListTest, HandlesFilling) {
  ncsdk_List* list = ncsdk_List_New(int);
  EXPECT_NE(list, nullptr);

  for (int i = 0; i < 10; ++i) {
    ncsdk_List_PushBack(list, &i);
  }

  EXPECT_EQ(ncsdk_List_Size(list), 10);

  int value = 0;
  ncsdk_List_Fill(list, &value);

  for (int i = 0; i < 10; ++i) {
    int* v = ncsdk_List_At(int, list, i);
    EXPECT_EQ(*v, 0);
  }

  ncsdk_List_Delete(&list);
  EXPECT_EQ(list, nullptr);
}

TEST(ListTest, HandlesPopBack) {
  ncsdk_List* list = ncsdk_List_New(int);
  EXPECT_NE(list, nullptr);

  for (int i = 0; i < 10; ++i) {
    ncsdk_List_PushBack(list, &i);
  }

  EXPECT_EQ(ncsdk_List_Size(list), 10);

  for (int i = 9; i >= 0; --i) {
    ncsdk_List_PopBack(list);
    EXPECT_EQ(ncsdk_List_Size(list), i);
  }

  EXPECT_EQ(ncsdk_List_Size(list), 0);

  ncsdk_List_Delete(&list);
  EXPECT_EQ(list, nullptr);
}

TEST(ListTest, HandlesSize) {
  ncsdk_List* list = ncsdk_List_New(int);
  EXPECT_NE(list, nullptr);

  EXPECT_EQ(ncsdk_List_Size(list), 0);

  for (int i = 0; i < 10; ++i) {
    ncsdk_List_PushBack(list, &i);
    EXPECT_EQ(ncsdk_List_Size(list), i + 1);
  }

  ncsdk_List_Delete(&list);
  EXPECT_EQ(list, nullptr);
}

TEST(ListTest, HandlesMassivePushBack) {
  ncsdk_List* list = ncsdk_List_New(int);
  EXPECT_NE(list, nullptr);

  for (int i = 0; i < 100000; ++i) {
    ncsdk_List_PushBack(list, &i);
  }

  EXPECT_EQ(ncsdk_List_Size(list), 100000);

  for (int i = 0; i < 100000; ++i) {
    int* value = ncsdk_List_At(int, list, i);
    EXPECT_EQ(*value, i);
  }

  ncsdk_List_Delete(&list);
  EXPECT_EQ(list, nullptr);
}

TEST(ListTest, HandlesRandomPushAndPopWithoutCheck) {
  ncsdk_List* list = ncsdk_List_New(int);
  EXPECT_NE(list, nullptr);

  size_t size = 0;

  for (int i = 0; i < 100000; ++i) {
    if (rand() % 2 == 0) {
      ncsdk_List_PushBack(list, &i);
      ++size;
      EXPECT_EQ(ncsdk_List_Size(list), size);
    } else {
      ncsdk_List_PopBack(list);
      size = size > 0 ? size - 1 : 0;
      EXPECT_EQ(ncsdk_List_Size(list), size);
    }
  }

  ncsdk_List_Delete(&list);
  EXPECT_EQ(list, nullptr);
}