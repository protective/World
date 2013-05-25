import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

public class Sqlconnction {
	Connection c = null;
	Statement s = null;
	public Sqlconnction(){
		System.out.println("Checking if Driver is registered with DriverManager.");
		  
	  try {
	    Class.forName("org.postgresql.Driver");
	  } catch (ClassNotFoundException cnfe) {
	    System.out.println("Couldn't find the driver!");
	    System.out.println("Let's print a stack trace, and exit.");
	    cnfe.printStackTrace();
	    System.exit(1);
	  }
	  
	  System.out.println("Registered the driver ok, so let's make a connection.");
	  
	 
	  
	  try {
	    // The second and third arguments are the username and password,
	    // respectively. They should be whatever is necessary to connect
	    // to the database.
	    c = DriverManager.getConnection("jdbc:postgresql://localhost/world",
	                                    "karsten", "F1ff");
	  } catch (SQLException se) {
	    System.out.println("Couldn't connect: print out a stack trace and exit.");
	    se.printStackTrace();
	    System.exit(1);
	  }
	  
	  if (c != null){
	    System.out.println("Hooray! We connected to the database!");
	  	try {
			s = c.createStatement();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	  } else
	    System.out.println("We should never get here.");
	  }
	
	public Statement getStatement(){
		return s;
	}
		
}

