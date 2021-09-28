package ComplexExpression;

import Domain.ComplexNumber;

public class ComplexExpressionMultiplication extends ComplexExpression {

    public ComplexExpressionMultiplication(ComplexNumber[] args) {
        super(args);
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right) {
        return left.multiplication(right);
    }
}
