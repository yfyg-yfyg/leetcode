import java.time.LocalDate;
class Solution {
    public int dayOfYear(String date) {
        LocalDate date_ = LocalDate.parse(date);
        return date_.getDayOfYear();
    }
}
