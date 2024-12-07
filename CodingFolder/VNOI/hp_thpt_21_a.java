import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        String kq="";
        for (int i=0;i<s.length();i++) {
            char at=s.charAt(i);
            if ((at>='a' && at<='z')||(at>='A' && at<='Z')) kq+=at+"";
        }
        System.out.print(kq);
    }
}
