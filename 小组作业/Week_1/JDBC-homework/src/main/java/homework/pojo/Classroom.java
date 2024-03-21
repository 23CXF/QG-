package homework.pojo;

public class Classroom {
    private int id;
    private int Capacity;
    private String ClassroomStatus;
    private String Activity;
    private String ClassroomType;
    private String MultimediaStatus;
    private int NowNumber;



    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getClassroomStatus() {
        return ClassroomStatus;
    }

    public void setClassroomStatus(String classroomStatus) {
        ClassroomStatus = classroomStatus;
    }

    public int getCapacity() {
        return Capacity;
    }

    public void setCapacity(int capacity) {
        Capacity = capacity;
    }

    public String getActivity() {
        return Activity;
    }

    public void setActivity(String activity) {
        Activity = activity;
    }

    public String getClassroomType() {
        return ClassroomType;
    }

    public void setClassroomType(String classroomType) {
        ClassroomType = classroomType;
    }

    public String getMultimediaStatus() {
        return MultimediaStatus;
    }

    public void setMultimediaStatus(String multimediaStatus) {
        MultimediaStatus = multimediaStatus;
    }

    public int getNowNumber() {
        return NowNumber;
    }

    public void setNowNumber(int nowNumber) {
        NowNumber = nowNumber;
    }

    @Override
    public String toString() {
        return "Classroom{" +
                "id=" + id +
                ", Capacity=" + Capacity +
                ", ClassroomStatus='" + ClassroomStatus + '\'' +
                ", Activity='" + Activity + '\'' +
                ", ClassroomType='" + ClassroomType + '\'' +
                ", MultimediaStatus='" + MultimediaStatus + '\'' +
                ", NowNumber=" + NowNumber +
                '}';
    }
}
