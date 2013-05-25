
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTable;


public class PowerStatsTable extends JPanel {
    public PowerStatsTable() {
    	Object[][] cellData = {
    			{"row1-col1", "row1-col2"},
                {"row2-col1", "row2-col2"}
    			};
        String[] columnNames = {"col1", "col2"};
        add(  new JTable(cellData, columnNames) ) ;
    }
}
