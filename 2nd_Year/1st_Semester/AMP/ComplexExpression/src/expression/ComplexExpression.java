package expression;

import domain.ComplexNumber;

import java.util.Arrays;

public abstract class ComplexExpression {
    private Operation operation;
    private ComplexNumber[] args;

    public ComplexExpression(Operation operation, ComplexNumber[] args) {
        this.operation = operation;
        this.args = args;
    }

    protected abstract ComplexNumber executeOneOperation(ComplexNumber left, ComplexNumber right);

    public ComplexNumber execute() {
        if (args.length == 1)
            return args[0];
        ComplexNumber result = executeOneOperation(args[0], args[1]);
        for (int i = 2; i < args.length; i++)
            result = executeOneOperation(result, args[i]);
        return result;
    }


    @Override
    public String toString() {
        String output = args[0].toString();
        String operator = "";
        switch (operation) {
            case ADDITION -> operator = " + ";


            case SUBTRACTION -> operator = " - ";


            case MULTIPLICATION -> operator = " * ";


            case DIVISION -> operator = " / ";
        }
        for (int i = 1; i < args.length; i++) {
            output += operator;
            output += args[i].toString();
        }
        return output;
    }
}
