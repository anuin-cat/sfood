package src.com.anuin.library.bean;

import java.sql.Date;

public class EmpOrder0 {
    private Integer id;
    private Date timeStart;
    private String time;
    private Integer idUser;
    private Integer idSeat;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Date getTimeStart() {
        return timeStart;
    }

    public void setTimeStart(Date timeStart) {
        this.timeStart = timeStart;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
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

    @Override
    public String toString() {
        return "EmpOrder{" +
                "id=" + id +
                ", timeStart=" + timeStart +
                ", time='" + time + '\'' +
                ", idUser=" + idUser +
                ", idSeat=" + idSeat +
                '}';
    }
}
