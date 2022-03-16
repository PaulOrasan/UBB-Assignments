package expression;

import domain.ComplexNumber;

public class ComplexExpressionAddition extends ComplexExpression {

    public ComplexExpressionAddition(ComplexNumber[] args) {
        super(Operation.ADDITION, args);
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right) {
        return left.addition(right);
    }
}
