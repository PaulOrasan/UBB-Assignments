import expression.ComplexExpression;
import expression.Operation;
import domain.ComplexNumber;
import workers.ExpressionException;
import workers.ExpressionFactory;
import workers.ExpressionParser;

public class main {

    public static void main(String[] args) {
	// write your code here
        ExpressionParser parser = new ExpressionParser();
        try {
            ComplexExpression expression = parser.parseExpression(args);
            System.out.println(expression.toString() + " = " + expression.execute());
        } catch (ExpressionException e) {
            System.out.println(e.getMessage());
        } catch (ArithmeticException e) {
            System.out.println("Division by ZERO is not allowed!");
        }
    }
}
