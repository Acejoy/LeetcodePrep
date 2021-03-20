/*
    the question is to implement stack using:
    1. arrays 
    
*/


public class stackImplementation {


    public static void main(String[] args) {
        MyStack st = new MyStack(4);
        MyStack new_st = new MyStack(2);

        new_st.push(2);
        new_st.pop();
        new_st.push(222);
        new_st.push(11);
        new_st.printStack();

        System.out.println(st.pop());
        st.push(1);
        System.out.println(st.peek());
        st.pop();
        st.push(10);
        st.push(11);
        System.out.println(st.numElementsPresent());
        st.push(80);
        st.push(91);
        st.printStack();

    }
}

