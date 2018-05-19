import java.util.ArrayList;
import java.util.Scanner;

class LectureTime
{
    int weekday;
    int start;
    int end;

    LectureTime()
    {

    }
};

public class Main
{
    private static int solve(Scanner sc)
    {
        // read input
        int n, k;
        n = sc.nextInt();
        k = sc.nextInt();

        // get course info
        // Course *inp = new Course[n];
        ArrayList<ArrayList<LectureTime>> inp = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            inp.add(new ArrayList<LectureTime>());
        }

        for (int i = 0; i < n; i++) {
            int m;
            m = sc.nextInt();

            for (int j = 0; j < m; j++) {
                LectureTime tmp = new LectureTime();
                tmp.weekday = sc.nextInt();
                tmp.start = sc.nextInt();
                tmp.end = sc.nextInt();
                // inp[i].timetable.push_back(tmp);
                inp.get(i).add(tmp);
            }
        }

        // compute
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            // cout << i << ": ";
            int credit = 0;
            int overlap = 0;
            int[][] occupy;
            occupy = new int[7][];
            for(int j = 0; j < 7; j++)
                occupy[j] = new int[24];

            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    for (LectureTime t : inp.get(j)) {
                        for (int l = t.start; l < t.end; l++) {
                            if (occupy[t.weekday][l] > 0)
                                overlap++;
                            occupy[t.weekday][l]++;
                            credit++;
                        }
                    }
                }

                if (overlap <= k)
                    ans = Math.max(ans, credit);
            }

            // cout << credit << endl;
        }
        // cerr << "Done!" << endl;

        // delete[] inp;
        return ans;
    }

    public static void main(String[] argv)
    {
        // long start = System.currentTimeMillis();
        Scanner sc = new Scanner(System.in);
        int ncase;
        ncase = sc.nextInt();
        while (ncase-- > 0)
            System.out.println(solve(sc));
        // long end = System.currentTimeMillis();
        // System.out.printf("%.6fs", (end - start) * 1.0 / 1000);
    }
}
