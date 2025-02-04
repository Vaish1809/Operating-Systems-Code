class BusReservationSystem { 
    private int ticketsLeft = 1; 
 
    public void bookTicket(String userName) { 
        synchronized(this) { 
            if (ticketsLeft > 0) { 
                ticketsLeft--; 
                System.out.println(userName + " booked the ticket.\n"); 
            } else { 
                System.out.println(userName + " failed to book the ticket.\n"); 
            } 
        } 
    } 
} 
 
class User implements Runnable { 
    private String name; 
    private BusReservationSystem system; 
 
    public User(String name, BusReservationSystem system) { 
        this.name = name; 
        this.system = system; 
    } 
 
    @Override 
    public void run() { 
        system.bookTicket(name); 
    } 
} 
 
class Main { 
    public static void main(String[] args) { 
        System.out.println("ABC Bus Service Reservation\n"); 
        BusReservationSystem system = new BusReservationSystem(); 
        Thread user1 = new Thread(new User("User 1", system)); 
        Thread user2 = new Thread(new User("User 2", system)); 
        user2.start(); 
        user1.start(); 
    } 
} 
