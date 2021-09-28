package ComplexExpression;

import Domain.ComplexNumber;

public class ComplexExpressionAddition extends ComplexExpression {

    public ComplexExpressionAddition(ComplexNumber[] args) {
        super(args);
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right) {
        return left.addition(right);
    }
}
