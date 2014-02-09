import java.io.*;

//class for <comp> NT
class Comp {
    private Op op1,op2;
    private CompOp compOp;
    public Comp () {
        op1 = op2 = null;
        compOp = null;
    }
    public void parseComp() throws FileNotFoundException, IOException {
        //check & skip terminal "("
        if(20 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : (");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
        op1 = new Op();
        op1.parseOp();
        compOp = new CompOp();
        compOp.parseCompOp();
        op2 = new Op();
        op2.parseOp();
        //check & skip ")"
        if(21 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : )");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
    }

    public void printComp() throws IOException {
        System.out.print("(");
        op1.printOp();
        compOp.printCompOp();
        op2.printOp();
        System.out.print(")");
    }

    public Boolean evalComp() throws FileNotFoundException, IOException {
        return compOp.evalCompOp(op1.evalOp(),op2.evalOp());
    }
}
