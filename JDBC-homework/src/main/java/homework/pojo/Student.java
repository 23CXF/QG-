package homework.pojo;

public class Student {
    private int id;
    private String UserName;
    private String Password;
    private String College;
    private String Phone;
    private String IdentityCard;

    public String getUserName() {
        return UserName;
    }

    public void setUserName(String userName) {
        UserName = userName;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }



    public String getPassword() {
        return Password;
    }

    public void setPassword(String password) {
        Password = password;
    }

    public String getCollege() {
        return College;
    }

    public void setCollege(String college) {
        College = college;
    }

    public String getPhone() {
        return Phone;
    }

    public void setPhone(String phone) {
        Phone = phone;
    }

    public String getIdentityCard() {
        return IdentityCard;
    }

    public void setIdentityCard(String identityCard) {
        IdentityCard = identityCard;
    }

    @Override
    public String toString() {
        return "Student{" +
                "UserName='" + UserName + '\'' +
                ", Password='" + Password + '\'' +
                ", College='" + College + '\'' +
                ", Phone='" + Phone + '\'' +
                ", IdentityCard='" + IdentityCard + '\'' +
                '}';
    }
}
