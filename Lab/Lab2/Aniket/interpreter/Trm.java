import java.io.*;

//class for <trm> NT
class Trm {
    Op op;
    Trm trm;
    public Trm() {
        op = null;
        trm = null;
    }
    public void parseTrm() throws FileNotFoundException, IOException {
        op = new Op();
        op.parseOp();
        if(24 == Tokenizer.instance().getToken()) {
            Tokenizer.instance().skipToken();
            trm = new Trm();
            trm.parseTrm();
        }
    }

    public void printTrm() throws FileNotFoundException, IOException {
        op.printOp();
        if(null != trm) {
            System.out.print(" * ");
            trm.printTrm();
        }
    }

    //instead of "void execute.." method, eval method is used as it
    //it will return the value of the term
    public int evalTrm() throws FileNotFoundException, IOException {
        if(null == trm) {
            return op.evalOp();
        } else {
            return (op.evalOp()*trm.evalTrm());
        }
    }
}
