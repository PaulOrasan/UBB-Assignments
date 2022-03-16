public class Student extends Entity<Long>{

    private String nume;
    private int gupa;

    public Student(String nume, int gupa) {
        this.nume = nume;
        this.gupa = gupa;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public int getGupa() {
        return gupa;
    }

    public void setGupa(int gupa) {
        this.gupa = gupa;
    }

    @Override
    public String toString() {
        return "Student{" +
                "nume='" + nume + '\'' +
                ", gupa=" + gupa +
                '}';
    }
}
