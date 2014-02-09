import java.io.*;

//class corresponding to non-terminal <prog>
class Program {
    private DS ds;
    private SS ss;
    public Program() {
        ds = null;
        ss = null;
    }
    public void parseProgram() throws FileNotFoundException, IOException {
        Tokenizer t = Tokenizer.instance();
        //check & skip terminal "program"
        if(1 != t.getToken()) {
            System.out.println("Parse error : keyword program expected");
            System.exit(0);
        }
        t.skipToken();
        ds = new DS();
        ds.parseDS();
        //check & skip terminal "begin"
	if(2 != t.getToken()) {
            System.out.println("Parse error : keyword begin expected");
            System.exit(0);
        }
        t.skipToken();
        ss = new SS();
        ss.parseSS();
        //check & skip terminal "end"
        if(3 != t.getToken()) {
            System.out.println("Parse error : keyword end expected");
            System.exit(0);
        }
        t.skipToken();
    }

    public void printProgram() throws FileNotFoundException, IOException {
        System.out.println("program");
        ds.printDS();
        System.out.println("begin");
        ss.printSS(1);
        System.out.println("end");
    }

    public void executeProgram() throws FileNotFoundException, IOException {
        //execution of declaration sequence done during parsing, so ds.executeDS() not required
        ss.executeSS();
    }
}
