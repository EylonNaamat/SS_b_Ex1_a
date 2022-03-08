/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	
	CHECK(nospaces(mat(1, 3, '#', '$')) == nospaces("#\n"
													"#\n"
													"#\n"));
	
	CHECK(nospaces(mat(3, 3, '1', '2')) == nospaces("111\n"
													"121\n"
													"111\n"));
	CHECK(nospaces(mat(11, 3, 't', 't')) == nospaces("ttttttttttt\n"
													"ttttttttttt\n"
													"ttttttttttt\n"));
	CHECK(nospaces(mat(15, 5, '^', '*')) == nospaces("^^^^^^^^^^^^^^^\n"
													 "^*************^\n"
													 "^*^^^^^^^^^^^*^\n"
													 "^*************^\n"
													 "^^^^^^^^^^^^^^^\n")); 
	CHECK(nospaces(mat(11, 7, '1', '0')) == nospaces("11111111111\n"
													 "10000000001\n"
													 "10111111101\n"
													 "10100000101\n"
													 "10111111101\n"
													 "10000000001\n"
													 "11111111111\n"));
	CHECK(nospaces(mat(11, 3, 'e', 'n')) == nospaces("eeeeeeeeeee\n"
													 "ennnnnnnnne\n"
													 "eeeeeeeeeee\n"));
	CHECK(nospaces(mat(5, 5, '(', ')')) == nospaces("(((((\n"
													 "()))(\n"
													 "()()(\n"
													 "()))(\n"
													 "(((((\n"));

	CHECK(nospaces(mat(1, 5, '1', '0')) == nospaces("11111\n"));
	CHECK(nospaces(mat(int(9.5), int(7.7), '@', '-')) == nospaces("@@@@@@@@@\n"
												 	"@-------@\n"
												 	"@-@@@@@-@\n"
												 	"@-@---@-@\n"
												 	"@-@@@@@-@\n"
												 	"@-------@\n"
												 	"@@@@@@@@@"));

	CHECK(nospaces(mat(7, 7, '&', '-')) == nospaces("&&&&&&&\n"
													 "&-----&\n"
													 "&-&&&-&\n"
													 "&-&-&-&\n"
													 "&-&&&-&\n"
													 "&-----&\n"
													 "&&&&&&&\n"));

}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(0, 5, '$', '%'));
	CHECK_THROWS(mat(10, -1, '$', '%'));
	CHECK_THROWS(mat(-5, -1, '$', '%'));
	CHECK_THROWS(mat(11, 5, '\n', '%'));
	CHECK_THROWS(mat(11, 5, '\r', '%'));
	CHECK_THROWS(mat(11, 5, '\t', '%'));
	CHECK_THROWS(mat(11, 5, ' ', '%'));
	CHECK_THROWS(mat(10, 4, ' ', '\n'));
	CHECK_THROWS(mat(0, 0, ' ', '\n'));


    
}


/* Add more test cases here */
