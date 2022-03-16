import domain.Student;

import java.util.*;

public class MyMap {
    private Map<Integer, List<Student>> map;

    public MyMap() {
        this.map = new TreeMap<>(new ComparatorKey());
    }
    static class ComparatorKey implements Comparator<Integer> {


        @Override
        public int compare(Integer o1, Integer o2) {
            return o1 - o2;
        }
    }
    public void ADD(Student stud){
        float medie= stud.getMedie();
        Integer rontunjit=Math.round(medie);
        List<Student> students= map.get(rontunjit);
        if(students!=null){
            students.add(stud);
        }
        else{
            students= new ArrayList<>();
            students.add(stud);
            map.put(rontunjit,students);
        }
    }
}
