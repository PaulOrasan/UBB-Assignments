import java.util.ArrayList;
import java.util.List;

public class Main {

    public static <E> void printArie(List<E> l, Area<E> f) {
        l.forEach(elem -> {
            System.out.println(f.calculate(elem));
        });
    }

    public static void main(String[] args) {
        Area<Circle> circleArea = (circle) -> Math.pow(circle.getRadius(), 2) * 3.14;
        List<Circle> circleList = new ArrayList<>();

        circleList.add(new Circle(3));
        circleList.add(new Circle(5));

        Area<Square> squareArea = (square) -> Math.pow(square.getSide(), 2);
        List<Square> squareList = new ArrayList<>();

        squareList.add(new Square(2));
        squareList.add(new Square(7));

        printArie(circleList, circleArea);
        printArie(squareList, squareArea);
    }

}
