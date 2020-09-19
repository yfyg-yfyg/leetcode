class Foo {

    private boolean second_run = false;
    private boolean third_run = false;  

    public Foo() {
             
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        synchronized(this) {
            printFirst.run();
            second_run = true;
            notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        synchronized(this) {
            while ( second_run == false) {
                wait();
            }
           printSecond.run();
           third_run = true;
           notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        synchronized(this) {
            while(third_run == false) {
                wait();
            }
            printThird.run();
           
        }
    }
}

