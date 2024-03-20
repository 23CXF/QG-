package homework.pojo;

import java.util.Arrays;
import java.util.List;

public class NumbersAndClassrooms {
    private List<Classroom>classrooms;
    private int[]numbers;

    public List<Classroom> getClassrooms() {
        return classrooms;
    }

    public void setClassrooms(List<Classroom> classrooms) {
        this.classrooms = classrooms;
    }

    public int[] getNumbers() {
        return numbers;
    }

    public void setNumbers(int[] numbers) {
        this.numbers = numbers;
    }

    @Override
    public String toString() {
        return "NumbersAndClassrooms{" +
                "classrooms=" + classrooms +
                ", numbers=" + Arrays.toString(numbers) +
                '}';
    }
}
