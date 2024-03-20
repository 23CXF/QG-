package homework.pojo;

import java.util.List;

public class PageBean <T>{
    private int totalCount;
    private int unFinishedCount;
    private List<T> rows;

    public int getTotalCount() {
        return totalCount;
    }

    public void setTotalCount(int totalCount) {
        this.totalCount = totalCount;
    }

    public List<T> getRows() {
        return rows;
    }

    public void setRows(List<T> rows) {
        this.rows = rows;
    }

    public int getUnFinishedCount() {
        return unFinishedCount;
    }

    public void setUnFinishedCount(int unFinishedCount) {
        this.unFinishedCount = unFinishedCount;
    }

    @Override
    public String toString() {
        return "PageBean{" +
                "totalCount=" + totalCount +
                ", unFinishedCount=" + unFinishedCount +
                ", rows=" + rows +
                '}';
    }
}
