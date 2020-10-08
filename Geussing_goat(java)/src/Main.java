
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int min_number=1;
		int max_number=18;
		
		int random_number=(int)(Math.random()*((max_number-min_number)+1))+min_number;
		
		Words w =new Words(random_number);
		Word_list l=new Word_list();
		Decision d=new Decision(max_number,w.the_word());
			l.list();
			d.loop();
		

}
}
