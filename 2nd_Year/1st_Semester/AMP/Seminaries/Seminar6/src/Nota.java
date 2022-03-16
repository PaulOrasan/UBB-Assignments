import java.time.LocalDate;

public class Nota {
    private LocalDate date;
    private Student student;
    private Tema tema;
    private double value;
    private String profesor;

    public Nota(LocalDate date, Student student, Tema tema, double value, String profesor) {
        this.date = date;
        this.student = student;
        this.tema = tema;
        this.value = value;
        this.profesor = profesor;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public Student getStudent() {
        return student;
    }

    public void setStudent(Student student) {
        this.student = student;
    }

    public Tema getTema() {
        return tema;
    }

    public void setTema(Tema tema) {
        this.tema = tema;
    }

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public String getProfesor() {
        return profesor;
    }

    public void setProfesor(String profesor) {
        this.profesor = profesor;
    }

    @Override
    public String toString() {
        return "Nota{" +
                "date=" + date +
                ", student=" + student +
                ", tema=" + tema +
                ", value=" + value +
                ", profesor='" + profesor + '\'' +
                '}';
    }
}
