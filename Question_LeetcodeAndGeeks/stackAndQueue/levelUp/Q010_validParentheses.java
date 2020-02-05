public class Q010_validParentheses {

    public boolean isValid(String s) {

        ArrayDeque<Character> st = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(' || ch == '[' || ch == '{') {
                st.addFirst(ch);
            } else {

                if (st.isEmpty()) {
                    return false;
                } else if (st.getFirst() == '(' && ch != ')') {
                    return false;
                } else if (st.getFirst() == '{' && ch != '}') {
                    return false;
                } else if (st.getFirst() == '[' && ch != ']') {
                    return false;
                } else {
                    st.removeFirst();
                }
            }
        }


        return st.isEmpty();

    }

}