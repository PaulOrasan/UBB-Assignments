import ComplexExpression.ComplexExpression;
import ComplexExpression.ComplexExpressionAddition;
import ComplexExpression.Operation;
import Domain.ComplexNumber;
import ExpressionWorkers.ExpressionFactory;

public class Main {

    public static void main(String[] args) {
	// write your code here
        ExpressionFactory factory = ExpressionFactory.getInstance();
        ComplexExpression expression = factory.createExpression(Operation.ADDITION, new ComplexNumber[]{new ComplexNumber(2, 3),
                new ComplexNumber(1, 2)});
        ComplexNumber result = expression.execute();
    }
}
