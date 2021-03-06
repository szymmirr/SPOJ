#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#define main __real_main
#include "../pie.cpp"
#undef main

std::string INPUT_1 = "7 3 1 3 5 2 3 4 3";
std::string CORRECT_ANSWER_1 = "2 7";
std::string INCORRECT_ANSWER_1 = "0";

std::string INPUT_2 = "4 2 2 3 4 5";
std::string CORRECT_ANSWER_2 = "1 1";

std::string INPUT_3 = "3 2 5 3 1";
std::string CORRECT_ANSWER_3 = "-1 -1";

std::ostringstream capture_main_stdout(std::string test_input) {
    std::istringstream input(test_input);
    std::cin.rdbuf(input.rdbuf());

    std::ostringstream output;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    __real_main();
    std::cout.rdbuf(p_cout_streambuf);

    return output;
}

TEST_CASE("Incorrect return") {
    std::ostringstream output = capture_main_stdout(INPUT_1);
    REQUIRE_FALSE(__real_main() == 1);
}

TEST_CASE("Correct return") {
    std::ostringstream output = capture_main_stdout(INPUT_1);
    REQUIRE(__real_main() == 0);
}

TEST_CASE("Incorrect answer") {
    std::ostringstream output = capture_main_stdout(INPUT_1);
    INFO(output.str());
	REQUIRE_FALSE(output.str() == INCORRECT_ANSWER_1);
}

TEST_CASE("Correct answer 1") {
    std::ostringstream output = capture_main_stdout(INPUT_1);
    INFO(output.str());
	REQUIRE(output.str() == CORRECT_ANSWER_1);
}

TEST_CASE("Correct answer 2") {
    std::ostringstream output = capture_main_stdout(INPUT_2);
    INFO(output.str());
	REQUIRE(output.str() == CORRECT_ANSWER_2);
}

TEST_CASE("Correct answer 3") {
    std::ostringstream output = capture_main_stdout(INPUT_3);
    INFO(output.str());
	REQUIRE(output.str() == CORRECT_ANSWER_3);
}
