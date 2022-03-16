package workers;

import static org.junit.jupiter.api.Assertions.*;

class ExpressionParserTest {

    ExpressionParser parser = new ExpressionParser();

    @org.junit.jupiter.api.Test
    void validateCorrectExpression1() {
        String testString = "2+3*i";
        try {
            parser.validateExpression(testString.split(" "));
        } catch (ExpressionException e) {
            fail();
        }
    }

    @org.junit.jupiter.api.Test
    void validateCorrectExpression2() {
        String testString = "2+3*i + 5-6*i + -5-7*i";
        try {
            parser.validateExpression(testString.split(" "));
        } catch (ExpressionException e) {
            fail();
        }
    }

    @org.junit.jupiter.api.Test
    void validateCorrectExpression3() {
        String testString = "2 - 5+7*i - 3*i";
        try {
            parser.validateExpression(testString.split(" "));
        } catch (ExpressionException e) {
            fail();
        }
    }

    @org.junit.jupiter.api.Test
    void validateCorrectExpression4() {
        String testString = "3.57+2.23*i - 2.9 - 3.234 - 2.57*i";
        try {
            parser.validateExpression(testString.split(" "));
        } catch (ExpressionException e) {
            fail();
        }
    }

    @org.junit.jupiter.api.Test
    void validateCorrectExpression5() {
        String testString = "3.57+2.23*i * -2.9-3.97*i * 3.234 * -2.57*i";
        try {
            parser.validateExpression(testString.split(" "));
        } catch (ExpressionException e) {
            fail();
        }
    }


    @org.junit.jupiter.api.Test
    void validateCorrectExpression6() {
        String testString = "-2.23-5.6765*i / 9.432 / -3.235*i-234.23";
        try {
            parser.validateExpression(testString.split(" "));
        } catch (ExpressionException e) {
            fail();
        }
    }

    @org.junit.jupiter.api.Test
    void validateWrongExpression1() {
        String testString = "2a+3*i";
        try {
            parser.validateExpression(testString.split(" "));
            fail();
        } catch (ExpressionException ignored) {

        }
    }

    @org.junit.jupiter.api.Test
    void validateWrongExpression2() {
        String testString = "-2.23-5.67.65*i / 9.432";
        try {
            parser.validateExpression(testString.split(" "));
            fail();
        } catch (ExpressionException ignored) {

        }
    }

    @org.junit.jupiter.api.Test
    void validateWrongExpression3() {
        String testString = "-2.23-5.6765*i / 9.432 * 3.235*i+234";
        try {
            parser.validateExpression(testString.split(" "));
            fail();
        } catch (ExpressionException ignored) {

        }
    }

    @org.junit.jupiter.api.Test
    void validateWrongExpression4() {
        String testString = "-2.23-5.6765*i / 9.432 * 3.235*i+234";
        try {
            parser.validateExpression(testString.split(" "));
            fail();
        } catch (ExpressionException ignored) {

        }
    }

    @org.junit.jupiter.api.Test
    void validateWrongExpression5() {
        String testString = "2 - 3 - 1,2-5.6*i";
        try {
            parser.validateExpression(testString.split(" "));
            fail();
        } catch (ExpressionException ignored) {

        }
    }

}