package src.com.anuin.library.bean;

public class EmpUser {

    private Integer id;
    private String account;
    private String password;
    private String isBlack;
    private Integer idEvaluate;
    private Integer idOrder;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getAccount() {
        return account;
    }

    public void setAccount(String account) {
        this.account = account;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getIsBlack() {
        return isBlack;
    }

    public void setIsBlack(String isBlack) {
        this.isBlack = isBlack;
    }

    public Integer getIdEvaluate() {
        return idEvaluate;
    }

    public void setIdEvaluate(Integer idEvaluate) {
        this.idEvaluate = idEvaluate;
    }

    public Integer getIdOrder() {
        return idOrder;
    }

    public void setIdOrder(Integer idOrder) {
        this.idOrder = idOrder;
    }

    @Override
    public String toString() {
        return "EmpUser{" +
                "id=" + id +
                ", account='" + account + '\'' +
                ", password='" + password + '\'' +
                ", isBlack='" + isBlack + '\'' +
                ", idEvaluate=" + idEvaluate +
                ", idOrder=" + idOrder +
                '}';
    }
}
