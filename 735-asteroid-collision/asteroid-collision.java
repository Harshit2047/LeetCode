class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer>st=new Stack<>();
        int x=0;
        for(int i=0;i<asteroids.length;i++){
            if(st.size()==0) st.push(asteroids[i]);
            else{
                if(asteroids[i]>0){//positive
                    st.push(asteroids[i]);
                }
                else{
                    while(st.size()>0){
                        if(st.peek()>0){
                            if(st.peek()>Math.abs(asteroids[i])){
                                break;
                            }
                            else{

                                x= st.pop();
                                if(x==Math.abs(asteroids[i])){
                                    break;
                                }
                                if(st.size()==0){
                                    st.push(asteroids[i]);
                                    break;
                                }
                            }
                        }
                        else{
                            st.push(asteroids[i]);
                            break;
                        }
                        
                    }
                }
            }

        }
        int arr[]=new int[st.size()];
        int n=st.size()-1;
        while(st.size()>0){
            arr[n]=st.pop();
            n--;
        }
        return arr;
    }
}