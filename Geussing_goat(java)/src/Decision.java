import java.util.Scanner;
public class Decision {

	int i=0;
	int max_number;
	String decision;
	String the_word;
	String guess_word;
	
	Scanner in=new Scanner(System.in);
	
	Decision(int max_number, String the_word){
		this.max_number=max_number;
		this.the_word=the_word;
		//this.guess_word=guess_word;
		
	}
	void loop() {
	System.out.println("Type your guessd word here:");
	guess_word=in.nextLine();
	
	while(!guess_word.equals(the_word)) {
		System.out.println();
		System.out.println("Wrong Guess!!!");
		System.out.println("want to guess again??(Yes/No)");
		decision=in.nextLine();
		if(decision.equals("No")||decision.equals("NO")||decision.equals("no"))
		{
			System.out.println("The word is:"+the_word);
			i=max_number;
			break;
		}
		System.out.println();
		System.out.println("Enter a word again:");
		guess_word=in.nextLine();
		i=i+1;
		}
	System.out.println();
	System.out.println("-------------------Your point:"+(max_number-i));

	}
	


}



