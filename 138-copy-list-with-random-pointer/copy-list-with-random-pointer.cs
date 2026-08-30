public class Solution {
    public Node CopyRandomList(Node head) {
        if (head == null) return null;

        Node temp = head;

        while (temp != null) {
            Node newNode = new Node(temp.val);
            Node save = temp.next;

            temp.next = newNode;
            temp = temp.next;
            temp.next = save;
            temp = temp.next;
        }

        temp = head;
        while (temp != null) {
            Node nxt = temp.next;
            nxt.random = (temp.random != null) ? temp.random.next : null;
            temp = nxt.next;
        }

        temp = head;
        Node ans = temp.next;

        while (temp != null) {
            Node copy = temp.next;
            Node nextOriginal = copy.next;   // save BEFORE mutating copy.next

            temp.next = nextOriginal;                        // restore original list
            copy.next = (nextOriginal != null) ? nextOriginal.next : null; // link copy list

            temp = nextOriginal;             // advance on the ORIGINAL list
        }

        return ans;
    }
}