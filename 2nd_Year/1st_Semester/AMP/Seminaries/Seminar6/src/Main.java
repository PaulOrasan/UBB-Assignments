import java.time.LocalDate;
import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Main {

    private static List<Student> getStudents(){
        List<Student> students = new ArrayList<>();
        Student s1 = new Student("Ion",225);
        s1.setId(1L);
        students.add(s1);
        Student s2 = new Student("Marius",225);
        s2.setId(3L);
        students.add(s2);
        Student s3 = new Student("cata",224);
        s3.setId(2L);
        students.add(s3);
        return  students;

    }

    private static List<Tema> getTema(){
        return Arrays.asList(new Tema("t1","frumoasa"),new Tema("t2","naspa")
                ,new Tema("t3","asa"),new Tema("t4","asaa"));
    }

    private static List<Nota> getNote(List<Student> studs,List<Tema> teme){
        return Arrays.asList(new Nota(LocalDate.of(2021,11,11),studs.get(0),teme.get(0),10,"Ion"),
                new Nota(LocalDate.of(2021,10,11),studs.get(1),teme.get(0),9,"Ion1"),
                new Nota(LocalDate.of(2021,11,1),studs.get(1),teme.get(1),3,"Ion"),
                new Nota(LocalDate.of(2021,3,11),studs.get(1),teme.get(2),7,"Ion1"),
                new Nota(LocalDate.of(2021,3,11),studs.get(2),teme.get(1),6,"Ion"),
                new Nota(LocalDate.of(2021,11,2),studs.get(2),teme.get(3),8,"Ion1"),
                new Nota(LocalDate.of(2021,11,11),studs.get(1),teme.get(3),10,"Ion"));
    }

    private static void cerinta1(List<Nota> note) {
        Predicate<Nota> de_grupa = x -> x.getStudent().getGupa() == 225;
        Predicate<Nota> de_prof = x -> x.getProfesor().equals("Ion");
        Predicate<Nota> de_grupa_de_prof = de_grupa.and(de_prof);
    }

    private static void cerinta2(List<Nota> note) {
        note.stream().filter( x -> x.getStudent().getGupa() == 225)
                .map( x -> new NotaDto(x.getStudent().getNume(),x.getTema().getId(),x.getValue(),x.getProfesor()))
                .forEach( x -> System.out.println(x));


    }
    //media notelor pt fiecare student
    public static void cerinta3(List<Nota> note) {
        Map<Student,List<Nota>> grupare = note.stream().collect(Collectors.groupingBy( x -> x.getStudent()));
        grupare.entrySet().forEach(x -> {
            System.out.println( x.getKey().getNume());
            Double sum = x.getValue().stream().map( y -> y.getValue()).reduce(0D,(a,b) -> a+b);
            System.out.println(sum/10);
        });

    }
   //media notelor la o anumita tema
    public static void cerinta4(List<Nota> note) {
        Map<Tema,List<Nota>> grup = note.stream().collect(Collectors.groupingBy(x -> x.getTema()));
        grup.entrySet().forEach(x -> {
            System.out.println( x.getKey());
            Double sum = x.getValue().stream().map( y -> y.getValue()).reduce(0D,(a,b)->a+b);
            System.out.println(sum/x.getValue().size());
        });
    }
    //tema cu cea mai mare medie
    public static void  cerinta5(List<Nota> note) {
        Map<Tema, List<Nota>> grup = note.stream().collect(Collectors.groupingBy(x -> x.getTema()));
        Map<Tema, Double> finalmap = new HashMap<>();
        grup.entrySet().forEach(x -> {

            Double sum = x.getValue().stream().map(y -> y.getValue()).reduce(0D, (a, b) -> a + b);
            Double medie = sum / x.getValue().size();
            finalmap.put(x.getKey(), medie);

        });
        System.out.println(Collections.max(finalmap.entrySet(),Comparator.comparingDouble(Map.Entry::getValue)).getKey());

        System.out.println(Collections.max(finalmap.entrySet(),Comparator.comparingDouble(Map.Entry::getValue)).getValue());

        System.out.println(Collections.min(finalmap.entrySet(),Comparator.comparingDouble(Map.Entry::getValue)).getKey());
        System.out.println(Collections.min(finalmap.entrySet(),Comparator.comparingDouble(Map.Entry::getValue)).getValue());

    }


    public static void main(String[] args) {
        cerinta4(getNote(getStudents(),getTema()));
        cerinta5(getNote(getStudents(),getTema()));
        cerinta2(getNote(getStudents(),getTema()));
        cerinta1(getNote(getStudents(),getTema()));

    }
}
