class Pair{
    int a,b;
    Pair(int a,int b){
        this.a=a;
        this.b=b;
    }
}
class StockSpanner {
    Stack<Pair>st=new Stack<>();
    public StockSpanner() {
        st=new Stack<>();
    }
    
    public int next(int price) {
        int c=0;
        while(st.size()>0 && st.peek().a<=price){
           c+= st.pop().b;
            
        }
        st.push(new Pair(price,1+c));
        return 1+c;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */