package main;

import model.Student;

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Student s1= new Student("Dan", 4.5f);
        Student s2= new Student("Ana", 8.5f);
        Student s3= new Student("Dan", 4.5f);
        Student s4 = new Student("Andrei", 1.1f);
        Student s5 = new Student("Barbu", 10.0f);

        Set<Student> set = new HashSet<>();

        set.addAll(Arrays.asList(s1, s2, s3, s4, s5));

        System.out.println(set);

        Set<Student> set1 = new TreeSet<>();

        set1.addAll(Arrays.asList(s1, s2, s3, s4, s5));

        System.out.println(set1);

        Map<String, Student> map1 = new HashMap<>();
        map1.put(s1.getNume(), s1);
        map1.put(s2.getNume(), s2);
        map1.put(s3.getNume(), s3);
        map1.put(s4.getNume(), s4);
        map1.put(s5.getNume(), s5);

        /*for (Map.Entry<String, Student> pereche : map1.entrySet()) {
            System.out.println("key = " + pereche.getKey() + " value = " + pereche.getValue());
        }*/

        Map<String, Student> map2 = new TreeMap<>();
        map2.put(s1.getNume(), s1);
        map2.put(s2.getNume(), s2);
        map2.put(s3.getNume(), s3);
        map2.put(s4.getNume(), s4);
        map2.put(s5.getNume(), s5);

        for (Map.Entry<String, Student> pereche : map2.entrySet()) {
            System.out.println("key = " + pereche.getKey() + " value = " + pereche.getValue());
        }
    }
}
