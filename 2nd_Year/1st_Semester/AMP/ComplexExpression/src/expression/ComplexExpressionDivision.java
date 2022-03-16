package expression;

import domain.ComplexNumber;

public class ComplexExpressionDivision extends ComplexExpression{

    public ComplexExpressionDivision(ComplexNumber[] args) {
        super(Operation.DIVISION, args);
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right) {
        return left.division(right);
    }
}
