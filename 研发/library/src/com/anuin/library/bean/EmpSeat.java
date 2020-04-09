package src.com.anuin.library.bean;

public class EmpSeat {
    private Integer id;
    private Integer Xposition;
    private Integer Yposition;
    private String type;
    private String section;
    private Integer grade;
    private Integer count;
    private Integer appointment;
    private Integer floor;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getXposition() {
        return Xposition;
    }

    public void setXposition(Integer xposition) {
        Xposition = xposition;
    }

    public Integer getYposition() {
        return Yposition;
    }

    public void setYposition(Integer yposition) {
        Yposition = yposition;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getSection() {
        return section;
    }

    public void setSection(String section) {
        this.section = section;
    }

    public Integer getGrade() {
        return grade;
    }

    public void setGrade(Integer grade) {
        this.grade = grade;
    }

    public Integer getCount() {
        return count;
    }

    public void setCount(Integer count) {
        this.count = count;
    }

    public Integer getAppointment() {
        return appointment;
    }

    public void setAppointment(Integer appointment) {
        this.appointment = appointment;
    }

    public Integer getFloor() {
        return floor;
    }

    public void setFloor(Integer floor) {
        this.floor = floor;
    }

    @Override
    public String toString() {
        return "EmpSeat{" +
                "id=" + id +
                ", Xposition=" + Xposition +
                ", Yposition=" + Yposition +
                ", type='" + type + '\'' +
                ", section='" + section + '\'' +
                ", grade=" + grade +
                ", count=" + count +
                ", appointment=" + appointment +
                ", floor=" + floor +
                '}';
    }
}


