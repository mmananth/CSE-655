import java.io.*;

//class for <cond> NT
class Cond {
    private Comp comp;
    private Cond cond1,cond2;
    private int altNo; //used to store which alternate production rule
                       //the NT is taking. For <cond> there are 4 
                       //possible choices.
    public Cond() {
        comp = null;
        cond1 = cond2 = null;
        altNo = 0;
    }
    public void parseCond() throws FileNotFoundException, IOException {
        //"(" implies first choice
        if(20 == Tokenizer.instance().getToken()) {
            altNo = 1;
            comp = new Comp();
            comp.parseComp();
        } else if(15 == Tokenizer.instance().getToken()) { //"!" implies second alternative
            altNo = 2;
            Tokenizer.instance().skipToken();
            cond1 = new Cond();
            cond1.parseCond();
        } else if(16 == Tokenizer.instance().getToken()) { //"[" may imply third/fourth choice
            Tokenizer.instance().skipToken();
            cond1 = new Cond();
            cond1.parseCond();
            if(18 == Tokenizer.instance().getToken()) { //The decision between third & fourth
                                                        //choice is made by checking for "&&" and "||"
                altNo = 3;
            } else if(19 == Tokenizer.instance().getToken()) {
                altNo = 4;
            } else {
                System.out.println("Parse error : expected : && or ||");
                System.exit(0);
            }
            Tokenizer.instance().skipToken();
            cond2 = new Cond();
            cond2.parseCond();
            //check & skip "]"
            if(17 == Tokenizer.instance().getToken()) {
		Tokenizer.instance().skipToken();
            } else {
		System.out.println("Parse error : expected : ]");
                System.exit(0);
            }
        } else {
	    System.out.println("Parse error : invalid cond");
	    System.exit(0);
        }
    }

    public void printCond() throws IOException {
        if(1 == altNo) {
            comp.printComp();
        } else if(2 == altNo) {
            System.out.print("!");
            cond1.printCond();
        } else if(3 == altNo) {
            System.out.print("[");
            cond1.printCond();
            System.out.print(" && ");
            cond2.printCond();
            System.out.print("]");
        } else if(4 == altNo) {
            System.out.print("[");
            cond1.printCond();
            System.out.print(" || ");
            cond2.printCond();
            System.out.print("]");
        }
    }

    public Boolean evalCond() throws FileNotFoundException, IOException {
        if(1 == altNo) {
            return comp.evalComp();
        }
        if(2 == altNo) {
            return !(cond1.evalCond());
        }
        if(3 == altNo) {
            return ((cond1.evalCond())&&(cond2.evalCond()));
        }
        if(4 == altNo) {
            return ((cond1.evalCond())||(cond2.evalCond()));
        }
        return false;
    }
}
