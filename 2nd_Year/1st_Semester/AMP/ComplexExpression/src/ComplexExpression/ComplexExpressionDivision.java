package ComplexExpression;

import Domain.ComplexNumber;

public class ComplexExpressionDivision extends ComplexExpression{

    public ComplexExpressionDivision(ComplexNumber[] args) {
        super(args);
    }

    @Override
    public ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right) {
        return left.division(right);
    }
}
