#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#define main __real_main
#include "../duz.cpp"
#undef main

std::string INPUT_1 = "1000000000000000000000000000000 < 1000000000000000000000000000001";
std::string CORRECT_ANSWER_1 = "TAK";
std::string INCORRECT_ANSWER_1 = "NIE";

std::string INPUT_2 = "999 >= 20000";
std::string CORRECT_ANSWER_2 = "NIE";

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
