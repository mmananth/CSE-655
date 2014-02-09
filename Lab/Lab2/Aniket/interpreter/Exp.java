import java.io.*;

//class for <exp> NT
class Exp {
    private Trm trm;
    private Exp exp;
    int altNo; //stores which alternate rule <exp> will reduce to
               //<exp> has 3 possible choices
    public Exp() {
        trm = null;
        exp = null;
        altNo = 0;
    }
    public void parseExp() throws FileNotFoundException, IOException {
        altNo = 1;
        trm = new Trm();
        trm.parseTrm();
        //"+" implies rule 2
        if(22 == Tokenizer.instance().getToken()) {
            altNo = 2;
            Tokenizer.instance().skipToken();
            exp = new Exp();
            exp.parseExp();
        } else if(23 == Tokenizer.instance().getToken()) { //"-" implies rule 3
            altNo = 3;
            Tokenizer.instance().skipToken();
            exp = new Exp();
            exp.parseExp();
        }
    }

    public void printExp() throws FileNotFoundException, IOException {
        if(1 == altNo) {
            trm.printTrm();
        } else if(2 == altNo) {
            trm.printTrm();
            System.out.print(" + ");
            exp.printExp();
        } else if(3 == altNo) {
            trm.printTrm();
            System.out.print(" - ");
            exp.printExp();
        }
    }

    //instead of execute method, there is an eval method here as
    //this will return the value of an expression
    public int evalExp() throws FileNotFoundException, IOException {
	if(1 == altNo) {
            return trm.evalTrm();
        } else if(2 == altNo) {
            return (trm.evalTrm() + exp.evalExp());
        } else {
            return (trm.evalTrm() - exp.evalExp());
        }
    }
}
