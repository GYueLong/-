package lianxi;
/*����ע��������ʱ��ֻ�ܵ����������磨����9�����ܼ�������ŵı��ʽ
 * ��Ϊ����û���뵽ջ���棬��������ĺ���
 * */
import java.lang.Math;
import java.math.BigDecimal;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Stack;

import javax.swing.JButton;

public class stdC {

	public stdC() {

	}
	public static int sq(int n){//�������1
		if( n == 1){
			return 1;
		}
		int tmp = 0;
		for(int i=1;i<=n/2+1;i++){
			if(i*i == n){
				tmp = i;
				break;
			}
			if(i*i > n){
				tmp = i-1;
				break;
			}
		}
		return tmp;
	}
	public static double[] sc(int m){//�������2m==3������λС��
		double[] arr = new double[m];
		int num = 0;
		while(num != m){
			double f = 1;
			for(int i=0;i<=num;i++){
				f = f*10;
			}
			arr[num] = 1/f;//arr[0]=0.1 f==10��arr[1]=0.01 f==100��arr[2]=0.001 f==1000
			num++;
		}
		return arr;
	}
	public static double sb(int n, double j, double[] arr){//�������3
		double tmp = j;						//2
		for(int p=0;p<arr.length;p++){
			if(p>0){
				j = tmp;//��������ֵ������λ+С��λ�ĺͣ���ֵ��j������������㣩
			}
			for(int i=1;i<=9;i++){//С��λֻ�о�λ{0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9}
				tmp = i*arr[p]+j;//i*arr[p],�൱��ÿ�μ�0.1,0.2 ...
				if(tmp*tmp == n){
					return tmp;
				}
				if(tmp*tmp >n){
					//���ⶪʧ����
					BigDecimal c1 = new BigDecimal(Double.toString(tmp));
					BigDecimal c2 = new BigDecimal(Double.toString(arr[p]));
					tmp = c1.subtract(c2).doubleValue();
					break;
				}
			}
		}
		return tmp;
	}
	public static String compute(String input)// ��1237 �� ����
	{
		String str[];
		String inputnew = "";
		double dou;
		for (int i = 0; i < input.length(); i++) {
			if (input.charAt(i) != 'c') {
				inputnew += input.charAt(i);
			}
		}
		str = inputnew.split(" ");// �Կո�ָ�

		if (str[1].compareTo("��") == 0) {// ����Ϊʲô��1
			String str1 = "";
			int tmp = 0;
			for (int j = 2; j < str.length; j++) {
				str1 += str[j];
			}
			double ans1 = Double.parseDouble(str1);// ����ת��һ��
			if (ans1 == 0)
				return "false";
			if (ans1 == 1)
				return String.valueOf(ans1);
			dou = sb((int) ans1, sq((int) ans1), sc(3));
			String result1 = String.valueOf(dou);
			return result1;
		}
//1+2+3
		Stack<Double> s = new Stack<Double>();
		double m = Double.parseDouble(str[0]);// ��һ��Ϊ����,����Ϊ�����,ż��Ϊ������
		s.push(m);
		for (int i = 1; i < str.length; i++) {
			if (i % 2 == 1) {
				if (str[i].compareTo("+") == 0) {
					double help = Double.parseDouble(str[i + 1]);
					s.push(help);
				}

				if (str[i].compareTo("-") == 0) {
					double help = Double.parseDouble(str[i + 1]);
					s.push(-help);
				}

				if (str[i].compareTo("*") == 0) {// 1*2
					double help = Double.parseDouble(str[i + 1]);
					double ans = s.peek();// ȡ��ջ��Ԫ��
					s.pop();// ��ջ
					ans *= help;
					s.push(ans);
				}

				if (str[i].compareTo("/") == 0) {
					double help = Double.parseDouble(str[i + 1]);
					double ans = s.peek();
					s.pop();
					ans /= help;
					s.push(ans);
				}

				if (str[i].compareTo("%") == 0) {
					double help = Double.parseDouble(str[i + 1]);
					double ans = s.peek();
					s.pop();
					ans %= help;
					s.push(ans);
				}
			}
		}
		double ans = 0d;
		while (!s.isEmpty()) {
			ans += s.peek();
			s.pop();
		}
		String result = String.valueOf(ans);
		return result;
	}
}
