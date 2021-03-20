public class MyStack {
    private int[] arr; 
    private int maxElementsAllowed ;
    private int top = -1;

    public MyStack(int num) {
        arr = new int[2];
        maxElementsAllowed = num ;
    }

    public void printStack() {
        for( int i=0; i<=top; i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println("");
    }
    public int pop() {
        if (!this.empty()) {
            top--;
            return arr[top+1];
        } else {
            return Integer.MIN_VALUE;
        }
    }

    public void push(int x) {
        if ( !this.full()) {
            if ( top == arr.length -1) {
                int newArr[] = new int[arr.length*2]; 
                System.arraycopy(arr, 0, newArr, 0, arr.length);
                arr = newArr;
            }
            top++;
            arr[top] = x;
        }

    }

    public int peek() {
        if ( !this.empty() ) {
            return arr[top];
        } else {
            return Integer.MIN_VALUE;
        }

    }

    public boolean empty() {
        if ( top < 0) {
            System.out.println("No elements present");
            return true;
        } else {
            return false;
        }

    }

    public boolean full() {
        if ( top == (maxElementsAllowed - 1)) {
            System.out.println("Max Elements Limit Achieved!!"
                                + "\nPlease Pop a few elements before pushing.");
            return true;
        } else {
            return false ;
        }
    }

    public int numElementsPresent() {
        if ( !this.empty()) {
            return top+1;
        } else {
            return 0;
        }
    }
}
