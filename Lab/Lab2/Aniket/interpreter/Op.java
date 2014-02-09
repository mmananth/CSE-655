import java.io.*;

//class for <op> NT
class Op {
    int no, altNo;//no --> will store the value of integer literal in the program
                  //altNo --> will store the alternate rule number, with which
                  //<op> will reduce
    Id id;
    Exp exp;
    public Op() {
        altNo = 0;
        id = null;
        exp = null;
    }
    public void parseOp() throws FileNotFoundException, IOException {
        int currentToken = Tokenizer.instance().getToken();
        //check & skip if it is an integer literal
        if(31 == currentToken) {
            altNo = 1;
            no = Tokenizer.instance().intVal();
            Tokenizer.instance().skipToken();
        } else if (32 == currentToken) { //Id is the second alternate choice
            altNo = 2;
            id = Id.parseIdForSS();
	} else if (20 == currentToken) { //parenthesized expression is the third choice
            altNo = 3;
            Tokenizer.instance().skipToken();
            exp = new Exp();
            exp.parseExp();
            if(21 != Tokenizer.instance().getToken()) {
                System.out.println("Parse error : expected : )");
                System.exit(0);
            }
            Tokenizer.instance().skipToken();
        }
    }

    public void printOp() throws FileNotFoundException, IOException {
        if(1 == altNo) {
            System.out.print(no);
        } else if(2 == altNo) {
            System.out.print(id.getName());
        } else {
            System.out.print("(");
            exp.printExp();
            System.out.print(")");
        }
    }

    //instead of a "void execute.." method, this eval method will
    //return the value of this operator
    public int evalOp() throws FileNotFoundException, IOException {
        if(1 == altNo) {
            return no;
        } else if(2 == altNo) { //run time check for uiniliazied variable use
            if(!id.getInitialized()) {
		System.out.println("Run time error: variable "+id.getName()+" used without initialization");
		System.exit(0);
	    }
            return id.getValue();
        } else {
            return exp.evalExp();
        }
    }
}
