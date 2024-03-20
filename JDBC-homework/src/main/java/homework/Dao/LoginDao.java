package homework.Dao;


import com.alibaba.druid.pool.DruidDataSourceFactory;
import homework.Dao.login;
import homework.pojo.Admin;
import homework.pojo.Student;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Properties;

public class LoginDao implements login {
    public LoginDao() {
    }

    public Admin selectAdmin(String username, String password) throws Exception {
        try {

            Properties prop = new Properties();
            prop.load(new FileInputStream("src/druid.properties"));
            //4. 获取连接池对象
            DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
            Connection connect=dataSource.getConnection();

            //2. 定义SQL
            String sql = "select * from tb_Admin where userName=? and password=?;";

            //3. 获取pstmt对象
            PreparedStatement pstmt = connect.prepareStatement(sql);

            pstmt.setString(1, username);
            pstmt.setString(2, password);

            //4. 设置参数

            //5. 执行SQL
            ResultSet rs = pstmt.executeQuery();

            //6. 处理结果 List<Brand> 封装Brand对象，装载List集合
            Admin admin = new Admin();
            while (rs.next()){
                //获取数据
                int id = rs.getInt("id");
                String userName = rs.getString("userName");
                String password1 = rs.getString("password");
                admin.setUserName(userName);
                admin.setPassword(password1);
            }
            //7. 释放资源
            rs.close();
            pstmt.close();
            connect.close();

            return admin;
        } catch (Exception e) {
            throw new Exception(e);
        }
    }

    @Override
    public Student loginStudent(Student student) throws Exception {


                Properties prop = new Properties();
                prop.load(new FileInputStream("src/druid.properties"));
                //4. 获取连接池对象
                DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
                Connection connect=dataSource.getConnection();

                //2. 定义SQL
                String sql = "select * from tb_student where userName=? and password=?;";

                //3. 获取pstmt对象
                PreparedStatement pstmt = connect.prepareStatement(sql);

                pstmt.setString(1, student.getUserName());
                pstmt.setString(2, student.getPassword());

                //4. 设置参数

                //5. 执行SQL
                ResultSet rs = pstmt.executeQuery();

                //6. 处理结果 List<Brand> 封装Brand对象，装载List集合
                Student student2 = new Student();
                while (rs.next()){
                    //获取数据
                    int id = rs.getInt("id");
                    String userName = rs.getString("userName");
                    String password1 = rs.getString("password");
                    student2.setUserName(userName);
                    student2.setPassword(password1);
                }
                System.out.println(student2.toString());

                //7. 释放资源
                rs.close();
                pstmt.close();
                connect.close();
                return student2;

    }
}
