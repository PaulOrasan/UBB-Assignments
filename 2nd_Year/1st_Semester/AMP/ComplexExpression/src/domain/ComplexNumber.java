package domain;

import javax.xml.crypto.dom.DOMCryptoContext;
import java.util.Locale;
import java.util.Objects;

public class ComplexNumber {
    private double real;

    private double imaginary;

    public ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public double getReal() {
        return real;
    }

    public void setReal(int real) {
        this.real = real;
    }

    public double getImaginary() {
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
        double a = real;
        double b = imaginary;
        double c = otherNumber.getReal();
        double d = otherNumber.getImaginary();
        return new ComplexNumber(a * c - b * d, b * c + a * d);
    }

    public ComplexNumber conjugate() {
        return new ComplexNumber(real, -imaginary);
    }

    public ComplexNumber division(ComplexNumber otherNumber) {
        if (!(otherNumber.getReal() != 0 || otherNumber.getImaginary() != 0))
            throw new ArithmeticException();
        double a = real;
        double b = imaginary;
        double c = otherNumber.getReal();
        double d = otherNumber.getImaginary();
        ComplexNumber newNumber = new ComplexNumber((a * c + b * d) / (c * c + d * d),
                (c * b - a * d) / (c * c + d * d));
        return newNumber;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ComplexNumber that = (ComplexNumber) o;
        return Double.compare(that.real, real) == 0 && Double.compare(that.imaginary, imaginary) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(real, imaginary);
    }

    @Override
    public String toString() {
        String middle = "+";
        if (getImaginary() < 0)
            middle = "";
        if (getImaginary() < 0.000000001 && getImaginary() > -0.000000001)
            return String.valueOf(getReal());
        if (getReal() < 0.000000001 && getReal() > -0.000000001)
            return String.format(Locale.ENGLISH, "%f*i", getImaginary());
        return String.format(Locale.ENGLISH, "%f" + middle + "%f*i", getReal(), getImaginary());
    }
}
