

public class A
{
	// ���ģ��һ�� 0����ʾ����ײ
	static int test()
	{
		int n = 100;
		int[] day = new int[365];
		for(int i=0; i<n; i++){
			int k = (int)(Math.random() * 365);
			if(day[k]>0) return 1;
			day[k] = 1;
		}
		return 0;		
	}	

	
	public static void main(String[] args)
	{
		int n = 1000 * 100;  // ģ�����
		int N = 0;  // ������ͬ�Ĵ���
		for(int i=0; i<n; i++){
			N += test();
		}
		
		System.out.println(100.0 * N / n);
	}
}