#include "pch.h"
#include "gtest/gtest.h"
#include "Source.cpp"

TEST(FilesTest, files_counter)
{
	TextFileOperation t("Test", "Test/f1.txt");

	EXPECT_EQ(5, t.files_counter_in_directory());
}

TEST(FilesTest, lines_counter)
{
	TextFileOperation t("Test", "Test/f1.txt");

	EXPECT_EQ(9, t.lines_counter_in_txt_file());
}

TEST(FilesTest, words_counter)
{
	TextFileOperation t("Test", "Test/f1.txt");

	ASSERT_EQ(493, t.words_counter_in_txt_file());
}

TEST(FilesTest, letters_counter)
{
	TextFileOperation t("Test", "Test/f1.txt");

	ASSERT_EQ(3343, t.letters_counter_in_txt_file());
}

TEST(FilesTest, directory_name)
{
	TextFileOperation t("Test", "Test/f1.txt");

	ASSERT_EQ("Test", t.directory_name());
}

TEST(FilesTest, file_name)
{
	TextFileOperation t("Test", "Test/f1.txt");

	ASSERT_EQ("Test/f1.txt", t.file_name());
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
