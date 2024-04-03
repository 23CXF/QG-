import com.alibaba.fastjson.JSON;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
      this.doPost(request,response);
//
//        BufferedReader reader = request.getReader();
//        String param = reader.readLine();
//        User user = JSON.parseObject(param, User.class);
//
//
//        String jsonString = JSON.toJSONString(user);
//        response.setContentType("text/json;charset=utf-8");
//        response.getWriter().write(jsonString);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        BufferedReader reader = request.getReader();
        String param = reader.readLine();
        User user = JSON.parseObject(param, User.class);
        System.out.println(user.toString());



        String jsonString = JSON.toJSONString(user);
        System.out.println(jsonString);
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);

    }
}
