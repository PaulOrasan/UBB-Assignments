package Domain;

public class ComplexNumber {
    private int real;

    private int imaginary;

    public ComplexNumber(int real, int imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public int getReal() {
        return real;
    }

    public void setReal(int real) {
        this.real = real;
    }

    public int getImaginary() {
        return imaginary;
    }

    public void setImaginary(int imaginary) {
        this.imaginary = imaginary;
    }

    public ComplexNumber addition(ComplexNumber otherNumber) {
        return new ComplexNumber(real + otherNumber.getReal(),
                imaginary + otherNumber.getImaginary());
    }

    public ComplexNumber subtraction(ComplexNumber otherNumber) {
        return new ComplexNumber(real - otherNumber.getReal(),
                imaginary - otherNumber.getImaginary());
    }

    //(a+bi)*(c+di) = ac - bd + (bc + ad)i
    public ComplexNumber multiplication(ComplexNumber otherNumber) {
        int a = real;
        int b = imaginary;
        int c = otherNumber.getReal();
        int d = otherNumber.getImaginary();
        return new ComplexNumber(a * c - b * d, b * c + a * d);
    }

    public ComplexNumber conjugate() {
        return new ComplexNumber(real, -imaginary);
    }

    public ComplexNumber division(ComplexNumber otherNumber) {
        int a = real;
        int b = imaginary;
        int c = otherNumber.getReal();
        int d = otherNumber.getImaginary();
        return new ComplexNumber((a * c + b * d) / (c * c + d * d),
                (c * b - a * d) / (c * c + d * d));
    }
}
