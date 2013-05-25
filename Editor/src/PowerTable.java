import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTable;

public class PowerTable extends JPanel {
	
    public PowerTable(Object[][] data) {
    	Object[][] cellData = data;
        String[] columnNames = {"col1", "col2", "col3"};
        add(  new JTable(cellData, columnNames) ) ;
    }
    
    //public Object[][] getCell(){return cellData;}
}
