import java.io.*;

//class for <if> NT
class If {
    private Cond cond;
    private SS ss1, ss2;
    public If() {
        cond = null;
        ss1 = ss2 = null;
    }
    public void parseIf() throws FileNotFoundException, IOException {

        //check & skip terminal "if"
        if(5 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : if");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
        cond = new Cond();
        cond.parseCond();

        //check & skip "then"
	if(6 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : then");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
        ss1 = new SS();
        ss1.parseSS();

        //parse "else" part if present
        if(7 == Tokenizer.instance().getToken()) {
            Tokenizer.instance().skipToken();
            ss2 = new SS();
            ss2.parseSS();
        }

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

    public void printIf(int indentLevel) throws FileNotFoundException, IOException {
        System.out.print(String.format("%1$#" + (4*indentLevel) + "sif ", " "));
        cond.printCond();
        System.out.println(" then");
        ss1.printSS(indentLevel+1);
        if(null != ss2) {
            System.out.println(String.format("%1$#" + (4*indentLevel) + "selse", " "));
            ss2.printSS(indentLevel+1);
        }
        System.out.println(String.format("%1$#" + (4*indentLevel) + "send;", " "));
    }

    public void executeIf() throws FileNotFoundException, IOException {
        if(true == cond.evalCond()) {
            ss1.executeSS();
        } else if(null != ss2) {
            ss2.executeSS();
        }
    }
}
