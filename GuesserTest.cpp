/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, guess_matches)
{
	Guesser guess("test");
	bool actual = guess.match("test");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, guess_does_not_match)
{
	Guesser guess("test");
	bool actual = guess.match("TEST");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, guess_is_much_longer)
{
	Guesser guess("test");
	bool actual = guess.match("test1111111111111111111111111111111111");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, guess_is_much_shorter)
{
	Guesser guess("testtesttesttesttest");
	bool actual = guess.match("test");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, guess_is_one_longer)
{
	Guesser guess("test");
	bool actual = guess.match("test1");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, guess_is_one_shorter)
{
	Guesser guess("test");
	bool actual = guess.match("tes");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, locked_out_then_guess_correct)
{
	Guesser guess("test");
	bool actual = guess.match("11111111111111111");
	actual = guess.match("test");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, guess_three_times_wrong_then_guess_correct)
{
	Guesser guess("test");
	bool actual = guess.match("test1");
	actual = guess.match("test2");
	actual = guess.match("test3");
	actual = guess.match("test");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, secret_is_longer_than_32_characters)
{
	Guesser guess("111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	bool actual = guess.match("TEST");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, guess_wrong_once_then_guess_correct)
{
	Guesser guess("test");
	bool actual = guess.match("test1");
	actual = guess.match("test");
	ASSERT_EQ(true, actual);
}

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/
