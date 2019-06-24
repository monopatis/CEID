import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ImageApp extends JFrame implements ActionListener {
    
    JPanel kentriko;
    JMenuBar menubar;
    JMenu optionsMenu;
    JMenuItem resetMenuItem;
    
    JPanel pnlKentriko;
    JPanel pnlEikona;
    JPanel pnlAlign;
    JPanel pnlSizes;
    JPanel pnlSizeW;
    JPanel pnlSizeH;
    JButton btnLeft;
    JButton btnCenter;
    JButton btnRight;    
    JLabel lblEikona;
    JLabel lblSizeW;
    JLabel lblSizeH;
    JTextField txtSizeW;
    JTextField txtSizeH;
    JButton btnResize;

    public ImageApp() {
        // Η super σε εφαρμογές JFrame δίνει τίτλο στο παράθυρο
        super("Image Application");
        // Θέλουμε η εφαρμογή να ολοκληρώνει την εκτέλεσή της με το κλείσιμο
        // του παραθύρου
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setSize(400,400);
        menubar = new JMenuBar();
        optionsMenu = new JMenu("Options");
        resetMenuItem = new JMenuItem("Reset");
        resetMenuItem.setActionCommand("reset");
        resetMenuItem.addActionListener(this);
        
        optionsMenu.add(resetMenuItem);
        menubar.add(optionsMenu);
        
        setJMenuBar(menubar);
        
        pnlKentriko = new JPanel();
        pnlKentriko.setLayout(new BoxLayout(pnlKentriko, BoxLayout.PAGE_AXIS));
        pnlAlign = new JPanel(new GridLayout(1,3));
        pnlEikona = new JPanel();
        pnlEikona.setLayout(new FlowLayout(FlowLayout.CENTER));
        pnlSizes = new JPanel(new GridLayout(3,2));
               
        lblSizeW = new JLabel("Width");
        txtSizeW = new JTextField();
        lblSizeH = new JLabel("Height");
        txtSizeH = new JTextField();
        btnResize = new JButton("Resize");
        btnResize.setActionCommand("resize");
        btnResize.addActionListener(this);
        
        pnlSizes.add(lblSizeW);
        pnlSizes.add(txtSizeW);
        pnlSizes.add(lblSizeH);
        pnlSizes.add(txtSizeH);
        pnlSizes.add(btnResize);        
        
        btnLeft = new JButton("Align Left");
        btnLeft.setActionCommand("alignleft");
        btnLeft.addActionListener(this);
        btnCenter = new JButton("Align Center");
        btnCenter.setActionCommand("aligncenter");
        btnCenter.addActionListener(this);
        btnRight = new JButton("Align Right");
        btnRight.setActionCommand("alignright");
        btnRight.addActionListener(this);
        
        pnlAlign.add(btnLeft);
        pnlAlign.add(btnCenter);
        pnlAlign.add(btnRight);
        
        ImageIcon image = new ImageIcon("image.jpg");
        lblEikona = new JLabel(image);
        
        pnlEikona.add(lblEikona); 
        
        pnlKentriko.add(pnlAlign);
        pnlKentriko.add(pnlEikona);
        pnlKentriko.add(pnlSizes);
        
        add(pnlKentriko);
        
        setVisible(true);
    }
    
    public void actionPerformed(ActionEvent e) {
        if ("alignleft".equals(e.getActionCommand())) {
            pnlEikona.setLayout(new FlowLayout(FlowLayout.LEFT));
            pnlEikona.revalidate();
            validate();
            repaint();
        } else if ("aligncenter".equals(e.getActionCommand())) {
            pnlEikona.setLayout(new FlowLayout(FlowLayout.CENTER));
            pnlEikona.revalidate();
            validate();
            repaint();
        } else if ("alignright".equals(e.getActionCommand())) {
            pnlEikona.setLayout(new FlowLayout(FlowLayout.RIGHT));
            pnlEikona.revalidate();
            validate();
            repaint();
        } else if ("resize".equals(e.getActionCommand())) {
            lblEikona.setPreferredSize(new Dimension(Integer.parseInt(txtSizeW.getText()), Integer.parseInt(txtSizeH.getText())));
            pnlEikona.revalidate();
            validate();
            repaint();
        } else if ("reset".equals(e.getActionCommand())) {
        }
    }
    
    public static void Main (String[] args) {
        ImageApp ia = new ImageApp();
    }
}