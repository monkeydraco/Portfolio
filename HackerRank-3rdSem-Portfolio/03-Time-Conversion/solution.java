import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String timeConversion(String s) {
        // Extract AM/PM modifier from the last two characters
        String modifier = s.substring(s.length() - 2);
        
        // Extract the hour part
        String hourStr = s.substring(0, 2);
        int hour = Integer.parseInt(hourStr);
        
        // Extract minutes and seconds (e.g., ":05:45")
        String minutesAndSeconds = s.substring(2, s.length() - 2);
        
        // Handle conversion rules
        if (modifier.equals("AM")) {
            if (hour == 12) {
                hourStr = "00";
            }
        } else if (modifier.equals("PM")) {
            if (hour != 12) {
                hour += 12;
                hourStr = String.valueOf(hour);
            }
        }
        
        // Combine hour with minutes and seconds
        return hourStr + minutesAndSeconds;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.timeConversion(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
