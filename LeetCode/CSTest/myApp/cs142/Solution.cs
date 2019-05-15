namespace myApp.cs142
{
    //快慢指针
    //知道了 还是想不出来
    public class ListNode {
        public int val;
        public ListNode next;
        public ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public class Solution {
    int cnt;
    public ListNode DetectCycle(ListNode head) {
            cnt = 1;
            ListNode kuai = head;
            ListNode man = head;

            if(kuai == null || kuai.next == null || kuai.next.next == null) return null;
            kuai = kuai.next.next;
            man = man.next;
            while(kuai != man) {
                cnt++;
                if(kuai.next == null) return null;
                if(kuai.next.next == null) return null;
                kuai = kuai.next.next;
                man = man.next;
            }
            kuai = head;
            man = head;
            for(int i = 0; i < cnt; i++) kuai = kuai.next;
            while(kuai != man) {
                kuai = kuai.next;
                man = man.next;
            }
            return kuai;
        }
    }
}