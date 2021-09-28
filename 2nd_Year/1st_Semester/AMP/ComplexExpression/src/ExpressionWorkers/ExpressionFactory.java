package ExpressionWorkers;

import ComplexExpression.ComplexExpression;
import ComplexExpression.Operation;
import Domain.ComplexNumber;
import ComplexExpression.ComplexExpressionAddition;
import ComplexExpression.ComplexExpressionDivision;
import ComplexExpression.ComplexExpressionSubtraction;
import ComplexExpression.ComplexExpressionMultiplication;


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
                return new ComplexExpressionMultiplication(args);
        }
    }
}
