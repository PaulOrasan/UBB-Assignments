public class NotaDto {
    private String studName;
    private String temaId;
    private double value;
    private String profesor;

    public NotaDto(String studName, String temaId, double value, String profesor) {
        this.studName = studName;
        this.temaId = temaId;
        this.value = value;
        this.profesor = profesor;
    }

    public String getStudName() {
        return studName;
    }

    public void setStudName(String studName) {
        this.studName = studName;
    }

    public String getTemaId() {
        return temaId;
    }

    public void setTemaId(String temaId) {
        this.temaId = temaId;
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
        return "NotaDto{" +
                "studName='" + studName + '\'' +
                ", temaId='" + temaId + '\'' +
                ", value=" + value +
                ", profesor='" + profesor + '\'' +
                '}';
    }
}
