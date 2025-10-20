class Solution {
    public int finalValueAfterOperations(String[] arr) {
        int x=0;
        System.out.println(arr[0]);
        for(int i=0;i<arr.length;i++){
            String temp=arr[i];
            if(temp.equals("++X")) ++x;
            else if(temp.equals("X++")) x++;
            else if(temp.equals("--X"))--x;
            else x--;
        }
        return x;
    }
}