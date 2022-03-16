package expression;

import domain.ComplexNumber;

public class ComplexExpressionSubtraction extends ComplexExpression {

    public ComplexExpressionSubtraction(ComplexNumber[] args) {
        super(Operation.SUBTRACTION, args);
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right) {
        return left.subtraction(right);
    }
}
