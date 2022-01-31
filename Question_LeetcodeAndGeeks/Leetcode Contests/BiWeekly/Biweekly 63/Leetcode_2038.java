public class Leetcode_2038 {
    public boolean winnerOfGame(String colors) {
        int[] countSteps = new int[2]; // 0th index for alice, 1st index for bob.

        int n = colors.length(), i = 0;
        while (i < n) {
            int countChar = 0;
            char ch = colors.charAt(i);
            while (i < n && ch == colors.charAt(i)){
                i++;
                countChar++;
            }

            countSteps[ch - 'A'] += Math.max(0,countChar - 2);
        }

        return countSteps[0] > countSteps[1];
    }

}