package ComplexExpression;

import Domain.ComplexNumber;

import java.util.ArrayList;

public abstract class ComplexExpression {
    private Operation operation;
    private ComplexNumber[] args;

    public ComplexExpression(ComplexNumber[] args) {
        this.args = args;
    }

    public abstract ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right);

    public ComplexNumber execute() {
        if (args.length == 1)
            return args[0];
        ComplexNumber result = executeOneOperation(args[0], args[1]);
        for (int i = 2; i < args.length; i++)
            result = executeOneOperation(result, args[i]);
        return result;
    }
}
