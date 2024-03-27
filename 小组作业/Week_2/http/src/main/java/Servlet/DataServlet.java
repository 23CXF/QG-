package Servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/DataServlet")
public class DataServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        handleRequest(request, response, "GET");
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        handleRequest(request, response, "POST");
    }

    protected void doPut(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        handleRequest(request, response, "PUT");
    }

    protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        handleRequest(request, response, "DELETE");
    }

    private void handleRequest(HttpServletRequest request, HttpServletResponse response, String method) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        String param = request.getParameter("param");

        // 根据请求方式不同，返回不同的响应状态码和消息
        switch (method) {
            case "GET":
                if (param != null && !param.isEmpty()) {
                    out.println("GET 请求成功，参数：" + param);
                } else {
                    response.setStatus(HttpServletResponse.SC_BAD_REQUEST); // 设置状态码为400
                    out.println("GET 请求参数错误");
                }
                break;
            case "POST":
                if (param != null && !param.isEmpty()) {
                    out.println("POST 请求成功，参数：" + param);
                } else {
                    response.setStatus(HttpServletResponse.SC_BAD_REQUEST); // 设置状态码为400
                    out.println("POST 请求参数错误");
                }
                break;
            case "PUT":
                // 处理 PUT 请求
                response.setStatus(HttpServletResponse.SC_METHOD_NOT_ALLOWED); // 设置状态码为405
                out.println("不支持的请求方式：PUT");
                break;
            case "DELETE":
                // 处理 DELETE 请求
                response.setStatus(HttpServletResponse.SC_METHOD_NOT_ALLOWED); // 设置状态码为405
                out.println("不支持的请求方式：DELETE");
                break;
            default:
                // 处理其他未定义的请求方式
                response.setStatus(HttpServletResponse.SC_METHOD_NOT_ALLOWED); // 设置状态码为405
                out.println("不支持的请求方式：" + method);
                break;
        }
    }
}
