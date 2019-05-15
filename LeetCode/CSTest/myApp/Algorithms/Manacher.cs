using System;

namespace myApp.Algorithms
{
//copy from https://blog.csdn.net/discreeter/article/details/52002761

    //LeetCode 132
    public class Manacher
    {
        int[] p;
        char[] str;

        int len;
        public int manacherInit(char[] s) {
            int sz = s.Length;
            len = (sz + 1) * 2;
            str = new char[(sz + 1) * 2 + 1];
            p = new int[(sz + 1) * 2 + 1];
            for(int i = 0; i <= (sz + 1) * 2; i++) p[i] = 0;

            for(int i = 1; i <= sz; i++) {
                str[i * 2] = s[i - 1];
                str[i * 2 + 1] = '#';
            }

            //  1 2 3 4 5 6 7 8
            //  # c # c # c # '\0'

            str[0] = '?'; str[1] = '#'; str[(sz + 1) * 2] = '\0';

            int res = 0, k = 0, maxk = 0;
            for(int i = 2; i <= (sz + 1) * 2; i++) {
                
                p[i] = i < maxk ? Math.Min(maxk - i, p[2 * k - i]) : 1;
                while((i - p[i] >= 0) && (i + p[i] <= (sz + 1) * 2) 
                    && str[i - p[i]] == str[i + p[i]]) p[i]++;
                if(p[i] + i > maxk) {
                    k = i;
                    maxk = i + p[i];
                }

                res = Math.Max(res, p[i]);
            }
            return res - 1;
        }

        //manacher后位于locate的回文串的长度
        int manacherLength(int locate) {
            return p[locate] / 2;
            // if(str[locate] == '#') {
            //     return p[locate] / 2;
            // }
            // else {
            //     return p[locate] / 2 + 1;
            // }
        }

        int manacherToStringLocate(int locate) {
            return locate / 2 - 1;
        }

        public int stringLocateToLength(int locate, bool isOdd) {
            if(isOdd) {
                return manacherLength(locate * 2);
            }
            else {
                return manacherLength(locate * 2 + 1);
            }
        }

        public void output() {
            for(int i = 0; i <=len; i++)
                Console.WriteLine(str[i] + "---" + p[i]);
        }

        void test() {
            string s = "wocao";
            char[] a = s.ToCharArray();
            
        }
    }
}