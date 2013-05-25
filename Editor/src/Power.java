import javax.swing.Icon;
import javax.swing.ImageIcon;


public class Power {

	int id;
	ImageIcon icon;
	public Power(int id,String Path){
		ImageIcon icon = new ImageIcon(this.getClass().getClassLoader().getResource(Path));
	}
	
	public ImageIcon getImage(){
		return icon;
	}
}
