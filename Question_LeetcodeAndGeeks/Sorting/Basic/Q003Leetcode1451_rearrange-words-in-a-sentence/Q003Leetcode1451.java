public class Q003Leetcode1451{

    //method01.===========================================
    public String arrangeWords(String text) {
        String[] arr=text.split(" ");
        Arrays.sort(arr,(a,b)->{
           return a.length()-b.length();
        });
        
        StringBuilder sb=new StringBuilder();
        
        for(String s: arr){
            sb.append(s.toLowerCase() + " ");
        }
        
        sb.setCharAt(0,(char)(sb.charAt(0)-'a'+'A'));
        sb.deleteCharAt(sb.length()-1);
        return sb.toString();
    }

    //method02.===========================================
    public String arrangeWords(String text) {
        String[] arr=text.split(" ");
        Arrays.sort(arr,(a,b)->{
            return a.length()-b.length();
        });
               
        String ans=String.join(" ",arr);
        return ans.substring(0,1).toUpperCase() + ans.substring(1).toLowerCase();
               
    }
}