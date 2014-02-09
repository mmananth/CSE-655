import java.io.*;

//class for <loop> NT
class Loop {
    Cond cond;
    SS ss;
    public Loop() {
        cond = null;
        ss = null;
    }
    public void parseLoop() throws FileNotFoundException, IOException {

        //check & skip terminal "while"
        if(8 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : while");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
        cond = new Cond();
        cond.parseCond();
        //check & skip "loop"
        if(9 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : loop");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
        ss = new SS();
        ss.parseSS();
        //check & skip "end" followed by ";"
        if(3 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : end");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
	if(12 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected ;");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
    }

    public void printLoop(int indentLevel) throws FileNotFoundException, IOException {
        System.out.print(String.format("%1$#" + (4*indentLevel) + "swhile ", " "));
        cond.printCond();
        System.out.println(" loop");
        ss.printSS(indentLevel+1);
        System.out.println(String.format("%1$#" + (4*indentLevel) + "send;", " "));
    }

    public void executeLoop() throws FileNotFoundException, IOException {
        while(true == cond.evalCond()) {
            ss.executeSS();
        }
    }
}
