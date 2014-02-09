import java.io.*;

class Program {
    private DS ds;
    private SS ss;
    public Program() {
        ds = null;
        ss = null;
    }
    public void parseProgram() {
        Tokenizer t = Tokenizer.instance();
        if(1 != t.getToken()) {
            System.out.println("Parse error : keyword program expected");
            exit(0);
        }
        t.skipToken();
        ds = new DS();
        ds.parseDS();
	if(2 != t.getToken()) {
            System.out.println("Parse error : keyword begin expected");
            exit(0);
        }
        t.skipToken();
        ss = new SS();
        ss.parseSS();
        if(3 != t.getToken()) {
            System.out.println("Parse error : keyword end expected");
            exit(0);
        }
        t.skipToken();
    }
}
