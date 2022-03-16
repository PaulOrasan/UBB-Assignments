package workers;

import expression.ComplexExpression;
import expression.Operation;
import domain.ComplexNumber;
import expression.ComplexExpressionAddition;
import expression.ComplexExpressionDivision;
import expression.ComplexExpressionSubtraction;
import expression.ComplexExpressionMultiplication;


public class ExpressionFactory {
    private static ExpressionFactory instance = new ExpressionFactory();

    private ExpressionFactory() {}

    public static ExpressionFactory getInstance() {
        return instance;
    }

    public ComplexExpression createExpression(Operation operation, ComplexNumber[] args) {
        switch (operation) {
            case ADDITION:
                return new ComplexExpressionAddition(args);
            case SUBTRACTION:
                return new ComplexExpressionSubtraction(args);
            case DIVISION:
                return new ComplexExpressionDivision(args);
            case MULTIPLICATION:
                return new ComplexExpressionMultiplication(args);
            default:
                return null;
        }
    }
}
