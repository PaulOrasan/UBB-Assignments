package model;

import java.util.*;

public class MyMap {

    private Map<Integer, List<Student>> map;

    public MyMap() {
        this.map = new TreeMap<>(new ComparatorMap());
    }

    static class ComparatorMap implements Comparator<Integer> {
        @Override
        public int compare(Integer o1, Integer o2) {
            return o1 - o2;
        }
    }

    public void add(Student s) {
        Float sed = s.getMedie();
        Integer rot = Math.round(sed);
        List<Student> students = map.get(rot);
        if (students != null) {
            students.add(s);
        } else {
            students = new ArrayList<>();
            students.add(s);
            map.put(rot, students);
        }
    }
}
