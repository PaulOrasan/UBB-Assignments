import java.util.List;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class Student {

    private String nume;
    private double medie;

    public Student(String nume, double medie) {
        this.nume = nume;
        this.medie = medie;
    }

    public String getNume() {
        return nume;
    }

    public double getMedie() {
        return medie;
    }

    public <E> List<E> cumVrei(List<E> lista, Predicate<E> pred) {
        List<E> result = lista.stream().filter(pred).collect(Collectors.toList());
        return result;
    }

}


