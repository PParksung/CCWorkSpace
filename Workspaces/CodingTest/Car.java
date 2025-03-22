import java.util.Scanner;

public class Car {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		String color = sc.next(); //black
		int speed = sc.nextInt(); //-1
		int spare_wheel = sc.nextInt();  //-1
		sc.close();
		
		if (speed == -1) {
			Created_car rc = new Created_car(color);
		} else if (spare_wheel == -1) {
			Created_car rc = new Created_car(color, speed);
		} else {
			Created_car rc = new Created_car(color, speed, spare_wheel);
		}		
	}
}

class Created_car{
	//
	String color;
	int speed;
	int spare_wheel;

	Created_car(String color, int speed, int spare_wheel){
		//
		this.color = color;
		this.speed = speed;
		this.spare_wheel = spare_wheel;

		System.out.println("color : "+ this.color);
		System.out.println("speed : "+ this.speed);
		System.out.println("spare_wheel : "+ this.spare_wheel);
	}
	
	Created_car(String color, int speed){
		//
		this.color = color;
		this.speed = speed;
		spare_wheel = 0;
		System.out.println("color : "+ this.color);
		System.out.println("speed : "+ this.speed);
		System.out.println("spare_wheel : " + this.spare_wheel);
	}
	
	Created_car(String color){
		//
		this.color = color;
		speed = 10;
		spare_wheel = 0;
		System.out.println("color : "+this.color);
		System.out.println("speed : "+this.speed);
		System.out.println("spare_wheel : "+this.spare_wheel);
	}
	
}