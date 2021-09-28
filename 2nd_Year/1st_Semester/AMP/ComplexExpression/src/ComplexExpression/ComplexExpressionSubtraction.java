package ComplexExpression;

import Domain.ComplexNumber;

public class ComplexExpressionSubtraction extends ComplexExpression {

    public ComplexExpressionSubtraction(ComplexNumber[] args) {
        super(args);
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right) {
        return left.subtraction(right);
    }
}
