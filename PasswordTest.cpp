/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_same_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, has_upper_no_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("UP");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_lower_no_upper)
{
        Password my_password;
        bool actual = my_password.has_mixed_case("up");
        ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_upper_and_lower)
{
        Password my_password;
        bool actual = my_password.has_mixed_case("Up");
        ASSERT_EQ(true, actual);
}

TEST(PasswordTest, default_pass)
{
	Password my_password;
	ASSERT_EQ(true, my_password.authenticate("ChicoCA-95929"));
}

TEST(PasswordTest, too_short)
{
	Password my_password;
	my_password.set("helloA");
	ASSERT_EQ(false, my_password.authenticate("hello"));
}

TEST(PasswordTest, too_long)
{
        Password my_password;
        my_password.set("helloqwertyuiopasdfghjklA");
        ASSERT_EQ(false, my_password.authenticate("helloqwertyuiopasdfghjklA"));
}

TEST(PasswordTest, more_than_3_leading)
{
        Password my_password;
        my_password.set("eeeeplauA");
        ASSERT_EQ(false, my_password.authenticate("eeeeplauA"));
}

TEST(PasswordTest, no_mixed_case)
{
        Password my_password;
        my_password.set("erfeplaua");
        ASSERT_EQ(false, my_password.authenticate("erfeplaua"));
}

TEST(PasswordTest, previous_password)
{
        Password my_password;
        my_password.set("erfeplauA");
	my_password.set("ChicoCA-95929");
        ASSERT_EQ(false, my_password.authenticate("ChicoCA-95929"));
}

TEST(PasswordTest, set_password_works)
{
        Password my_password;
        my_password.set("erfeplauA");
        ASSERT_EQ(true, my_password.authenticate("erfeplauA"));
}
