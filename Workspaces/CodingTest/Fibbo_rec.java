import java.util.Scanner;

public class Fibbo_rec {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int i1 = sc.nextInt();
		sc.close();
		
		Fibbo fibbo1 = new Fibbo(i1);
		fibbo1.print();

	}
}

class Fibbo{
	int num;
	int sn1;
	int sn2;
	//1,1,2,3,5,8,13,21 etc
	int rec(int num){
		if(num>2){
			return rec(num-2)+rec(num-1);
		}else if(num==2){
			return sn2;
		}else if(num==1){
			return sn1;
		}else{
			return 0;
		}
	}

	void print(){
		System.out.println(rec(num));
	}

	public Fibbo(int num){
		this.num = num;
		this.sn1 = 1;
		this.sn2 = 1;
	}
}


