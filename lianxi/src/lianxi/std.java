package lianxi;
import javax.swing.*;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
public class std extends JPanel{
	String cs=" ";
	String input="";
	String beifen="";
	public JButton[] jbs = new JButton[20];
	JButton save = new JButton("����");
	JButton copy = new JButton("����");
	JButton clear = new JButton("���");
	JTextField tf = new JTextField();
	JTextArea text = new JTextArea();
	JPanel panel1 = new JPanel();
	StringBuffer strBuf = new StringBuffer();
	JScrollPane js = new JScrollPane(text);// ������
	ArrayList<String> strArray = new ArrayList<String>();
  public std() {
    setGUIComponent();
  }
  public void setGUIComponent(){
    //��ʼ�����
	    setLayout(null);
		tf.setHorizontalAlignment(JTextField.RIGHT);// �Ҷ���
		// tf.setEditable(false);//�ı����ֹ�༭
		tf.setBounds(0, 10, 350, 30);
		panel1.setLayout(new GridLayout(4, 5, 0, 0));
		panel1.setBounds(0, 50, 350, 120);
		// text.setLineWrap(true);//�Զ�����
		js.setBounds(360, 5, 200, 130);		
		save.setBounds(360, 140, 60, 30);
		copy.setBounds(430, 140, 60, 30);
		clear.setBounds(500,140, 60, 30);		
		
		strArray.add("1");	strArray.add("2");
		strArray.add("3");	strArray.add("+");
		strArray.add("c");	strArray.add("4");
		strArray.add("5");	strArray.add("6");
		strArray.add("-");	strArray.add("�˸�");	
		strArray.add("7");	strArray.add("8");
		strArray.add("9");	strArray.add("*");
		strArray.add("��");strArray.add("0");
		strArray.add(".");strArray.add("%");
		strArray.add("/");	strArray.add("=");
		for (int i = 0; i < jbs.length; i++) {
			jbs[i] = new JButton(strArray.get(i) + "");
			jbs[i].setSize(70, 30);
			panel1.add(jbs[i]);
			jbs[i].addActionListener(new ActionListener() {

				@Override
				public void actionPerformed(ActionEvent arg0) {
					// TODO Auto-generated method stub
					String s = arg0.getActionCommand();
					//System.out.println("123");
					if (s.equals("=") == false) {// ��Ϊ����ʱȫ��ʾ
						cs += s;
						
					}
					if (s.equals("c")) {
						cs = " ";
						input = "";
						beifen = "";
					}
					if (s.equals("�˸�")) {
						int m = input.length();
						int n = beifen.length();
						int flag = 0;
						for (int i = 0; i < cs.length(); i++) {
							if (tf.getText().equals("") && cs.charAt(i) == '��') {
								flag = 1;
								cs = " ";
								return;
							}
						}
						if (flag == 0) {
							if (m == 1) {
								input = input.substring(0, 0);// ��ֹ����һ�����־��˸�
								tf.setText("");
								return;
							}
							if (input.charAt(m - 2) == '+' || input.charAt(m - 2) == '-' || input.charAt(m - 2) == '*'
									|| input.charAt(m - 2) == '/' || input.charAt(m - 2) == '%' || input.charAt(m - 2) == '��') {
								input = input.substring(0, input.length() - 3);
							} else
								input = input.substring(0, input.length() - 1);
							cs = cs.substring(0, cs.length() - 3);
						}
					}
					tf.setText(cs);
					if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/") || s.equals("%")|| s.equals("��")) {
						input += " " + s + " ";
					} else if (s.equals("=")) {
						String input1 = "";
						String show = "";
						for (int i = 0; i < input.length(); i++) {
							if (input.charAt(i) != 'c') {
								input1 += input.charAt(i);
							}
						}
						show = input1 + "=" + " " +stdC.compute(input);
						strBuf.append(show + "\n");
						text.setText(strBuf.toString());
					} else if (s.equals("�˸�") == false) {
						/*��������ĳ�if (s.equals("�˸�") == false||s.equals("c") == false)
						 �Ļ�����ô������"c"ʱ�߼��жϵ�һ���������߼���·��������������ô�ͽ�"c"���絽��input
						��ˣ���compute���㺯���вŽ�"c"ȡ��*/
						input += s;
					}
				}
			});
			
		}
		add(tf);		add(js);
		add(panel1);
		add(save);		add(copy);
		add(clear);
		
		save.addActionListener(new ActionListener() { // ��ť�����¼�����
			public void actionPerformed(ActionEvent e) {
				BufferedWriter out = null;
				int flag=0;
				String Filename="d://writeFile.txt";//�����ļ�·��
				File file = new File(Filename);
				
				try {
					out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(file, true)));
					out.append(text.getText());
				} catch (Exception e0) {
					e0.printStackTrace();
				} finally {
					try {
						out.flush();
						out.close();
					} catch (IOException e1) {
						e1.printStackTrace();
					}
					JOptionPane.showMessageDialog(null, "�ѱ������ļ�"+Filename+"��");
				}
			}

		});
		copy.addActionListener(new ActionListener() { // ��ť�����¼�����
			public void actionPerformed(ActionEvent e) {
				text.copy();
			}
		});
		clear.addActionListener(new ActionListener() { // ��ť�����¼�����
			public void actionPerformed(ActionEvent e) {
				text.setText("");
				strBuf.setLength(0); // ���strBuf�е�����
			}
		});
		setVisible(true);    setSize(600, 300);
  }
  
}

