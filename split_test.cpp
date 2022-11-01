#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

#include "split.hpp"

#include <vector>
#include <string>

class FraccionTest : public CPPUNIT_NS::TestFixture {

    CPPUNIT_TEST_SUITE(FraccionTest);
    CPPUNIT_TEST(testNone);
    CPPUNIT_TEST(testSeparadorChar);
    CPPUNIT_TEST(testSeparadorString);
    CPPUNIT_TEST_SUITE_END();

protected:
    void testNone() {
        CPPUNIT_ASSERT(misstr::split("") == std::vector<std::string>({}));
        CPPUNIT_ASSERT(misstr::split("\t\n \t\n") == std::vector<std::string>({}));
        CPPUNIT_ASSERT(misstr::split("8") == std::vector<std::string>({"8"}));
        CPPUNIT_ASSERT(misstr::split("i15n") == std::vector<std::string>({"i15n"}));
        CPPUNIT_ASSERT(misstr::split(" x") == std::vector<std::string>({"x"}));
        CPPUNIT_ASSERT(misstr::split("y ") == std::vector<std::string>({"y"}));
        CPPUNIT_ASSERT(misstr::split("  z  ") == std::vector<std::string>({"z"}));
        CPPUNIT_ASSERT(misstr::split(" \t hola la \n patata   ") == std::vector<std::string>({"hola", "la", "patata"}));
        CPPUNIT_ASSERT(misstr::split("la vida nos golpea") == std::vector<std::string>({"la", "vida", "nos", "golpea"}));
        CPPUNIT_ASSERT(misstr::split("¡Sé un campeón, Toño!") == std::vector<std::string>({"¡Sé", "un", "campeón,", "Toño!"}));
    }

    void testSeparadorChar() {
        CPPUNIT_ASSERT(misstr::split("", ' ') == std::vector<std::string>({""}));
        CPPUNIT_ASSERT(misstr::split("\t\n \t\n", ' ') == std::vector<std::string>({"\t\n", "\t\n"}));
        CPPUNIT_ASSERT(misstr::split("\t\n \t\n", '\t') == std::vector<std::string>({"", "\n ", "\n"}));
        CPPUNIT_ASSERT(misstr::split("8", ' ') == std::vector<std::string>({"8"}));
        CPPUNIT_ASSERT(misstr::split("8", '8') == std::vector<std::string>({"", ""}));
        CPPUNIT_ASSERT(misstr::split("i15n", '5') == std::vector<std::string>({"i1", "n"}));
        CPPUNIT_ASSERT(misstr::split("  z  ", ' ') == std::vector<std::string>({"", "", "z", "", ""}));
        CPPUNIT_ASSERT(misstr::split(" \t hola la \n patata   ", 'a') == std::vector<std::string>({" \t hol", " l", " \n p", "t", "t", "   "}));
        CPPUNIT_ASSERT(misstr::split("la vida nos golpea", 'x') == std::vector<std::string>({"la vida nos golpea"}));
        CPPUNIT_ASSERT(misstr::split("¡Sé un campeón, Toño!", ' ') == std::vector<std::string>({"¡Sé", "un", "campeón,", "Toño!"}));
    }

    void testSeparadorString() {
        CPPUNIT_ASSERT(misstr::split("", " ") == std::vector<std::string>({""}));
        CPPUNIT_ASSERT(misstr::split("\t\n \t\n", " ") == std::vector<std::string>({"\t\n", "\t\n"}));
        CPPUNIT_ASSERT(misstr::split("\t\n \t\n", "\t") == std::vector<std::string>({"", "\n ", "\n"}));
        CPPUNIT_ASSERT(misstr::split("8", " ") == std::vector<std::string>({"8"}));
        CPPUNIT_ASSERT(misstr::split("8", "8") == std::vector<std::string>({"", ""}));
        CPPUNIT_ASSERT(misstr::split("i15n", "5") == std::vector<std::string>({"i1", "n"}));
        CPPUNIT_ASSERT(misstr::split("  z  ", " ") == std::vector<std::string>({"", "", "z", "", ""}));
        CPPUNIT_ASSERT(misstr::split(" \t hola la \n patata   ", "a") == std::vector<std::string>({" \t hol", " l", " \n p", "t", "t", "   "}));
        CPPUNIT_ASSERT(misstr::split(" \t hola la \n patata   ", "la") == std::vector<std::string>({" \t ho", " ", " \n patata   "}));
        CPPUNIT_ASSERT(misstr::split(" \t hola la \n patata   ", "ta") == std::vector<std::string>({" \t hola la \n pa", "", "   "}));
        CPPUNIT_ASSERT(misstr::split("la vida nos golpea", "x") == std::vector<std::string>({"la vida nos golpea"}));
        CPPUNIT_ASSERT(misstr::split("¡Sé un campeón, Toño!", " ") == std::vector<std::string>({"¡Sé", "un", "campeón,", "Toño!"}));
        CPPUNIT_ASSERT(misstr::split("xxxyxyxxyx", "x") == std::vector<std::string>({"", "", "", "y", "y", "", "y", ""}));
        CPPUNIT_ASSERT(misstr::split("xxxyxyxxyx", "xy") == std::vector<std::string>({"xx", "", "x", "x"}));
        CPPUNIT_ASSERT(misstr::split("xxxyxyxxyx", "xx") == std::vector<std::string>({"", "xyxy", "yx"}));
        CPPUNIT_ASSERT(misstr::split("xxxyxyxxyx", "xyx") == std::vector<std::string>({"xx", "yx", ""}));
    }
};

int main() {
    CPPUNIT_NS::TextUi::TestRunner runner;
    runner.addTest(FraccionTest::suite());
    bool wasSuccessful = runner.run();
    return (wasSuccessful ? EXIT_SUCCESS : EXIT_FAILURE);
}
