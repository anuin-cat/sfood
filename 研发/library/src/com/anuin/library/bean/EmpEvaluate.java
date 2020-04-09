package src.com.anuin.library.bean;

import java.sql.Date;

public class EmpEvaluate {
    private Integer id;
    private String content;
    private Integer grade;
    private Date time;
    private Integer idUser;
    private Integer idSeat;
    private Integer idOrder0;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public Integer getGrade() {
        return grade;
    }

    public void setGrade(Integer grade) {
        this.grade = grade;
    }

    public Date getTime() {
        return time;
    }

    public void setTime(Date time) {
        this.time = time;
    }

    public Integer getIdUser() {
        return idUser;
    }

    public void setIdUser(Integer idUser) {
        this.idUser = idUser;
    }

    public Integer getIdSeat() {
        return idSeat;
    }

    public void setIdSeat(Integer idSeat) {
        this.idSeat = idSeat;
    }

    public Integer getIdOrder0() {
        return idOrder0;
    }

    public void setIdOrder0(Integer idOrder0) {
        this.idOrder0 = idOrder0;
    }

    @Override
    public String toString() {
        return "EmpEvaluate{" +
                "id=" + id +
                ", content='" + content + '\'' +
                ", grade=" + grade +
                ", time=" + time +
                ", idUser=" + idUser +
                ", idSeat=" + idSeat +
                ", idOrder0=" + idOrder0 +
                '}';
    }
}
