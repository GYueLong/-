package lianxi;
import java.awt.*;
import javax.swing.*;

public class Caculator extends JFrame {
	JTabbedPane dbTabPane;	//ѡ����
    JPanel inputPanel;		// ¼�����;
	JPanel viewPanel;		// ������;
	std stdPanel;
	Programmer ProgrammerPanel;

	public Caculator() {
		super("������");
		setGUIComponent();
	}

	public void setGUIComponent() {
		Container c = getContentPane();
		dbTabPane = new JTabbedPane();
		// ����¼�����
		inputPanel = new JPanel();
		inputPanel.setLayout(null);
		stdPanel = new std(); // ¼��������
		inputPanel.add(stdPanel);		
		dbTabPane.add(inputPanel,"��׼" );

		// ����������
		viewPanel = new JPanel();
		viewPanel.setLayout(null);
		ProgrammerPanel=new Programmer();
		viewPanel.add(ProgrammerPanel);
		dbTabPane.add(viewPanel,"����Ա");

		c.add(dbTabPane);
}
	
	public static void main(String[] args) {
		Caculator sm = new Caculator();
		stdC stdc=new stdC();
		Programmer programmer=new Programmer();
		sm.setSize(600, 230);
		sm.setVisible(true);
		sm.setResizable(false);//���ڴ�С���ɸı�
		sm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
