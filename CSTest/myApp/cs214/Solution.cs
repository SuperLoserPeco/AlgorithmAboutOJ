using System;

namespace myApp.cs214
{
    public class Manacher
    {
        int[] p;
        char[] str;
        public int manacherInit(char[] s) {
            int sz = s.Length;
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
                while(str[i - p[i]] == str[i + p[i]]) p[i]++;
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
            if(str[locate] == '#') {
                return p[locate] / 2;
            }
            else {
                return p[locate] / 2 + 1;
            }
        }

        int manacherToStringLocate(int locate) {
            return locate / 2 - 1;
        }

        public int stringLocateToLength(int locate, bool isOdd) {
            if(isOdd) {
                return manacherLength((locate + 1) * 2);
            }
            else {
                return manacherLength((locate + 1) * 2 + 1);
            }
        }


        void test() {
            string s = "wocao";
            char[] a = s.ToCharArray();
            
        }
    }
    public class Solution
    {
        Manacher p;
        public string ShortestPalindrome(string s) {
            p = new Manacher();
            p.manacherInit(s.ToCharArray());
            int sz = s.Length;
            int max = 0; int maxPos = 0; bool isOdd;
            for(int i = 0; i < sz; i++) {
                int part1 = p.stringLocateToLength(i, true);
                int part2 = p.stringLocateToLength(i, false);
                if(i + 1 == part1) {
                    if(i * 2 + 1 > max) {
                        max = i * 2 + 1;
                        maxPos = i;
                        isOdd = true;
                    }
                }
                if(i + 1 == part2) {
                    if((i + 1) * 2 > max) {
                        max = (i + 1) * 2;
                        maxPos = i;
                        isOdd = false;
                    }
                }


                if(part1 + i == sz) {
                    if((part1 * 2 - 1) > max) {
                        max = (part1 * 2 - 1);
                        maxPos = i;
                        isOdd = true;
                    }
                }
                if(part2 + i == sz - 1) {
                    if(part2 * 2 > max) {
                        max = (part2 * 2);
                        maxPos = i;
                        isOdd = false;
                    }
                }
            }
            return s;
        }
    }
}