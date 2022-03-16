import java.sql.Array;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;

public class Main {

    public static <E> void print(List<E> l, Predicate<E> predicate) {
        l.forEach(elem -> {
            if (predicate.test(elem))
                System.out.println(elem);
        });
    }

    public static void main(String[] args) {
       /*List<Student> studentList = new ArrayList<>();
        studentList.add(new Student("Marius", 7));
        studentList.add(new Student("Andrei", 8));
        studentList.add(new Student("Mihaela", 9.1));
        studentList.add(new Student("Maria", 10));

        Predicate<Student> studentiBursieri = (student) -> student.getMedie() >= 9;
        Predicate<Student> studentiBursieriCuP = studentiBursieri.and((student) -> student.getNume().startsWith("P"));

        print(studentList, studentiBursieri);
        print(studentList, studentiBursieriCuP);

        Function<String, Integer> convertorLambda = x -> Integer.valueOf(x);
        Function<String, Integer> convertorRefereintaLaMetoda = Integer::valueOf;

        Integer rezultat = convertorLambda.apply("25");

        Supplier<ArrayList> supplier = ArrayList::new;
        Supplier<ArrayList> supplier1 = () -> new ArrayList();
        Supplier<ArrayList<String>> supplierStr = ArrayList<String>::new;

        ArrayList<String> list = supplierStr.get();
        Supplier<LocalDate> supplier3 = LocalDate::now;
        LocalDate date = supplier3.get();*/
        LocalDateTime dateTime = LocalDateTime.parse("2021-11-17T19:26:13.424260600");
        System.out.println(dateTime);
    }
}
