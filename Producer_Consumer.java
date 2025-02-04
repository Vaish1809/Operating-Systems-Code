import java.util.concurrent.Semaphore; 
public class BufferQueue { 
    
   private int item; 
   private Semaphore semaphoreConsumer = new Semaphore(0); 
   private Semaphore semaphoreProducer = new Semaphore(1); 
    
   public void put(int item){ 
       try{ 
           semaphoreProducer.acquire(); 
       }catch(InterruptedException e){ 
           System.out.println("InterruptedException Caught"); 
       } 
       this.item = item; 
       System.out.println("Producer produced item : " + item); 
        
       semaphoreConsumer.release(); 
   } 
    
   public void get() 
   { 
       try{ 
           semaphoreConsumer.acquire(); 
       }catch(InterruptedException e) 
       { 
           System.out.println("Interrupted Exception Caught"); 
       } 
       System.out.println("Consumer consumed item: "+ item); 
        
       semaphoreProducer.release(); 
   } 
} 
 
public class Producer implements Runnable{ 
    private BufferQueue bufferQueue; 
     
    public Producer(BufferQueue bufferQueue){ 
        this.bufferQueue = bufferQueue; 
    } 
    public void run(){ 
        while(true){ 
            Random random = new Random(); 
            int data = random.nextInt(100); 
            bufferQueue.put(data); 
            try{ 
                Thread.sleep(2000); 
            }catch(InterruptedException e) 
            { 
                e.printStackTrace(); 
            } 
        } 
    } 
} 
 
public class Consumer implements Runnable{ 
    private BufferQueue bufferQueue; 
     
    public Consumer(BufferQueue bufferQueue) 
    { 
        this.bufferQueue = bufferQueue; 
    } 
     
    public void run(){ 
        while(true){ 
            bufferQueue.get(); 
            try{ 
                Thread.sleep(2000); 
            }catch(InterruptedException e) 
            { 
                e.printStackTrace(); 
            } 
             
        } 
    } 
} 
 
public class ProducerAndConsumerTest { 
     
    public static void main(String[] args){ 
        BufferQueue bufferQueue = new BufferQueue(); 
         
        Producer producer = new Producer(bufferQueue); 
        Consumer consumer = new Consumer(bufferQueue); 
        Thread producerThread = new Thread(producer); 
        producerThread.start(); 
        Thread consumerThread = new Thread(consumer); 
        consumerThread.start(); 
    } 
} 
 
 