import javax.swing.*; 

import sun.security.util.Length;

import java.awt.*; 
import java.awt.event.*; 
import java.awt.image.BufferedImage;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class MainApplet extends JApplet {
	JButton jbtnOne; 
	JButton jbtnTwo; 
	 
	JLabel jlab; 
	Sqlconnction sql;
	PowerTable jtable = null;
	//ImageIcon icon = createImageIcon("Icons/Armor/itempic0001.png","");
	ArrayList<Power> power = new ArrayList<Power>();
	
		
	public void init() {
       System.out.println("Working Directory = " +
               System.getProperty("user.dir"));
         
		try { 
		      SwingUtilities.invokeAndWait(new Runnable () { 
		        public void run() { 
		          guiInit(); // initialize the GUI 
		        } 
		      }); 
		    } catch(Exception exc) { 
		      System.out.println("Can't create because of "+ exc); 
		    }
		    sql = new Sqlconnction();
	  }
	// Called second, after init().  Also called 
	  // whenever the applet is restarted.  
	  public void start() { 
	    // Not used by this applet. 
	  } 
	 
	  // Called when the applet is stopped. 
	  public void stop() { 
	    // Not used by this applet. 
	  } 
	 
	  // Called when applet is terminated.  This is 
	  // the last method executed. 
	  public void destroy() { 
	    // Not used by this applet. 
	  } 
	 
	  // Setup and initialize the GUI.  
	  private void guiInit() { 
	    // Set the applet to use flow layout. 
	    setLayout(new GridBagLayout()); 
	    GridBagConstraints c = new GridBagConstraints();
	    // Create two buttons and a label. 
	    jbtnOne = new JButton(icon); 
	    jbtnTwo = new JButton("Two"); 
	    jlab = new JLabel("Press a button."); 
	 
	    // Add action listeners for the buttons. 
	    jbtnOne.addActionListener(new ActionListener() {      
	      public void actionPerformed(ActionEvent le) { 
	    	  String s= "";
				if(sql != null){
					if(jtable != null)
						getContentPane().remove(jtable);
					ResultSet rs;
					try {
						rs = sql.getStatement().executeQuery("Select count(*) from powertypeStats;");
						rs.next();
						int size = rs.getInt(1);
						rs = sql.getStatement().executeQuery("Select * from powertypeStats;");
						Object[][] data = new Object[size][3];
						int counter = 0;
						while( rs.next()){
							data[counter][0] = rs.getString(1);
							data[counter][1] = rs.getString(2);
							data[counter][2] = rs.getString(3);
							counter++;
							//s = "";
							//s += rs.getString(3) + "\t";
							//jtable.getCell();
						}
						
						jtable = new PowerTable(data);
						GridBagConstraints c = new GridBagConstraints();
						c.gridy = 4;
						getContentPane().add(jtable,c); 
						validate();
						repaint();
						System.out.println("hest");
					} catch (SQLException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				} 	    	  
	      }      
	    });      
	 
	    jbtnTwo.addActionListener(new ActionListener() {      
	      public void actionPerformed(ActionEvent le) {  
	        jlab.setText("Button Two pressed.");  
	      }      
	    });      
	 
	    // Add the components to the applet's content pane. 
	    c.fill = GridBagConstraints.HORIZONTAL;
	    c.weightx = 0.5;
	    c.weighty = 0.5;
	    c.gridx = 0;
	    c.gridy = 0;
	    getContentPane().add(jbtnOne,c);
	    c.fill = GridBagConstraints.HORIZONTAL;
	    c.weightx = 0.5;
	    c.gridx = 0;
	    c.gridy = 1;
	    getContentPane().add(jbtnTwo,c);

	    //getContentPane().add(jlab);     
	  } 
}
