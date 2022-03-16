package expression;

import domain.ComplexNumber;

public class ComplexExpressionMultiplication extends ComplexExpression {

    public ComplexExpressionMultiplication(ComplexNumber[] args) {
        super(Operation.MULTIPLICATION, args);
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right) {
        return left.multiplication(right);
    }
}
