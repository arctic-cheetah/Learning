import java.util.concurrent.*;

public class PoolThread {
    public static void main(String[] args) {
        int numTasks = Integer.parseInt(args[0].trim());

        //Create thread pool
        ExecutorService pool = Executors.newCachedThreadPool();
        
        //Run each task using a thread in the pool
        for (int i = 0; i < numTasks; i +=1) {
            pool.execute(new Task());
        }
        
        pool.shutdown();
    }
}
