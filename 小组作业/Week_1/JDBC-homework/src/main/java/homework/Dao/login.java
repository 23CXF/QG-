package homework.Dao;


import homework.pojo.Admin;
import homework.pojo.Student;

public interface login {
    Admin selectAdmin(String username, String password) throws Exception;
    Student loginStudent(Student student) throws Exception;
}
