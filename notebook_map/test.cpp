#include "Notebook.h"
#include "../gtest/gtest/gtest.h"
#include <cstring>

using std::strcmp;

TEST(trie, add) {
    Notebook example;
    example.add("Vasya", "46464");
    example.add("Petya", "asdad");
    example.add("Alla", "sdfsfs");
    example.add("Alladin", "433");
}

TEST(trie, find) {
    Notebook example;
    example.add("Vasya", "46464");
    example.add("Petya", "asdad");
    example.add("Alla", "sdfsfs");
    example.add("Alladin", "433");
    EXPECT_EQ(nullptr, example.find("lolo"));
    EXPECT_TRUE("46464" == *example.find("Vasya"));
    EXPECT_TRUE("asdad" == *example.find("Petya"));
    EXPECT_TRUE("433" == *example.find("Alladin"));
    EXPECT_TRUE("sdfsfs" == *example.find("Alla"));
}

TEST(trie, remove) {
    Notebook example;
    example.add("Vasya", "46464");
    example.add("Petya", "asdad");
    example.add("Alla", "sdfsfs");
    example.add("Alladin", "433");
    EXPECT_EQ(nullptr, example.find("lolo"));
    example.remove("Vasya");
    EXPECT_EQ(nullptr, example.find("Vasya"));
    example.remove("Petya");
    EXPECT_EQ(nullptr, example.find("Petya"));
    example.remove("Alladin");
    EXPECT_EQ(nullptr, example.find("Alladin"));
    EXPECT_TRUE("sdfsfs" == *example.find("Alla"));
    example.remove("Alla");
    EXPECT_EQ(nullptr, example.find("Alla"));
    EXPECT_EQ(nullptr, example.find("Alladin"));
}

TEST(trie, simple) {
    Notebook example;
    example.add("Vasya", "46464");
    example.add("Petya", "asdad");
    example.add("Alla", "sdfsfs");
    example.add("Alladin", "433");
    example.remove("lolo");
    EXPECT_TRUE("433" == *example.find("Alladin"));
    EXPECT_EQ(nullptr, example.find("lolo"));
    example.add("Alla", "8952");
    EXPECT_TRUE("8952" == *example.find("Alla"));
    example.remove("Alladin");
    EXPECT_TRUE("8952" == *example.find("Alla"));
    example.remove("Alla");
    EXPECT_EQ(nullptr, example.find("Alla"));
    example.add("Vasyas", "36464");
    EXPECT_TRUE("46464" == *example.find("Vasya"));
    EXPECT_TRUE("36464" == *example.find("Vasyas"));
    example.remove("Vasya");
    EXPECT_EQ(nullptr, example.find("Vasya"));
    EXPECT_TRUE("36464" == *example.find("Vasyas"));
    example.remove("Vasya");
    example.add("Petya", "2asdad");
    EXPECT_TRUE("2asdad" == *example.find("Petya"));
    example.remove("Petya");
    EXPECT_EQ(nullptr, example.find("Petya"));
}

TEST(trie, empty) {
    Notebook example;
    example.add("", "");
    EXPECT_TRUE("" == *example.find(""));
    example.add("", "343442");
    EXPECT_TRUE("343442" == *example.find(""));
    example.remove("");
    EXPECT_EQ(nullptr, example.find(""));
    example.add("", "");
    EXPECT_TRUE("" == *example.find(""));
    example.remove("");
    EXPECT_EQ(nullptr, example.find(""));
}

TEST(trie, once) {
    Notebook example;
    example.add("q", "");
    EXPECT_TRUE("" == *example.find("q"));
    example.add("q", "343442");
    EXPECT_TRUE("343442" == *example.find("q"));
    example.remove("q");
    EXPECT_EQ(nullptr, example.find("q"));
    example.add("q", "q");
    EXPECT_TRUE("q" == *example.find("q"));
    example.remove("q");
    EXPECT_EQ(nullptr, example.find("q"));
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
