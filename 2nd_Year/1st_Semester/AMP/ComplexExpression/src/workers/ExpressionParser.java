package workers;

import domain.ComplexNumber;
import expression.ComplexExpression;
import expression.Operation;

import java.util.*;

public class ExpressionParser {

    private final Map<String, Operation> correspondence = new HashMap<>();

    public ExpressionParser() {
        correspondence.put("+", Operation.ADDITION);
        correspondence.put("-", Operation.SUBTRACTION);
        correspondence.put("*", Operation.MULTIPLICATION);
        correspondence.put("/", Operation.DIVISION);
    }

    public ComplexExpression parseExpression(String[] args) throws ExpressionException {
        validateExpression(args);
        String operator;
        if (args.length == 1)
            operator = "+";
        else
            operator = parseOperator(args[1]);
        List<ComplexNumber> list = new ArrayList<>();
        for (int i = 0; i < args.length; i++) {
            if (i % 2 == 0) {
                list.add(parseComplexNumber(args[i]));
            }
        }
        return ExpressionFactory.getInstance().createExpression(correspondence.get(operator), list.toArray(
                new ComplexNumber[0]));
    }

    public void validateExpression(String[] args) throws ExpressionException {
        if (args.length % 2 == 0)
            throw new ExpressionException("There are not enough arguments!");
        String operator;
        if (args.length == 1)
            operator = "+";
        else
            operator = parseOperator(args[1]);
        for (int i = 0; i < args.length; i++) {
            if (i % 2 == 0) {
                parseComplexNumber(args[i]);
            } else {
                if (!operator.equals(parseOperator(args[i]))) {
                    throw new ExpressionException("There were more operators provided to the expression.");
                }
            }
        }
    }

    private String parseOperator(String argument) throws ExpressionException {
        String validOperatorsString = "+-/*";
        Set<Character> validOperators = new HashSet<>();
        for (Character c : validOperatorsString.toCharArray())
            validOperators.add(c);

        if (argument.length() != 1 || !validOperators.contains(argument.charAt(0)))
            throw new ExpressionException(argument + " is an invalid operator!");
        return argument;
    }

    private ComplexNumber parseComplexNumber(String argument) throws ExpressionException {
        int countPlus = countMatches(argument, '+'), countMinus = countMatches(argument, '-');

        if (countPlus == 0 && (countMinus == 0 || countMinus == 1 && argument.charAt(0) == '-')) {  //  a or -a or b*i or -b*i
            if (validateRealNumber(argument))
                return new ComplexNumber(Double.parseDouble(argument), 0);
            if (validateImaginaryNumber(argument))
                return new ComplexNumber(0, Double.parseDouble(argument.split("\\*")[0]));
            throw new ExpressionException(argument + " is an invalid complex number!");
        }

        String original = argument;
        if (countPlus == 0 && countMinus > 0)   //  a-b*i or -a-b*i
            argument = new StringBuilder(argument).insert(argument.lastIndexOf('-'), '+').toString();
        countPlus = countMatches(argument, '+');
        if (countPlus != 1 || countMinus > 2)
            throw new ExpressionException(original + " is an invalid complex number!");
        String[] list = argument.split("\\+");
        String realPart = null, imaginaryPart = null;

        if (validateRealNumber(list[0]) && validateImaginaryNumber(list[1])) {
            realPart = list[0];
            imaginaryPart = list[1].split("\\*")[0];
        } else if (validateRealNumber(list[1]) && validateImaginaryNumber(list[0])) {
            realPart = list[1];
            imaginaryPart = list[1].split("\\*")[0];
        }

        if (realPart == null && imaginaryPart == null)
            throw new ExpressionException(original + " is an invalid complex number!");
        return new ComplexNumber(Double.parseDouble(realPart), Double.parseDouble(imaginaryPart));
    }

    private boolean validateRealNumber(String argument) {
        try {
            Double.parseDouble(argument);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    private boolean validateImaginaryNumber(String argument) {
        String[] list = argument.split("\\*");
        if (list.length != 2)
            return false;
        if (list[1].length() != 1 && list[1].charAt(0) != 'i')
            return false;
        try {
            Double.parseDouble(list[0]);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    private int countMatches(String argument, char character) {
        int count = 0;
        for (char c : argument.toCharArray()) {
            if (c == character)
                count++;
        }
        return count;
    }
}
