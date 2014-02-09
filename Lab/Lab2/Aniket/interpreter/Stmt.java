import java.io.*;

//class for <stmt>
class Stmt {
    private Assign assgn;
    private If IF;
    private Loop loop;
    private In in;
    private Out out;
    private int altNo; //This is used to store which rule non-terminal <stmt>
                       //is taking. This is used since the number of choices
                       //are quite high(5 choices)
    public Stmt() {
        assgn = null;
        IF = null;
        loop = null;
        in = null;
        out = null;
        altNo = 0;
    }
    public void parseStmt() throws FileNotFoundException, IOException {
        int currentToken = Tokenizer.instance().getToken();

        //Id token implies this is Assign
        if(32 == currentToken) {
            altNo = 1;
            assgn = new Assign();
            assgn.parseAssign();
            return;
        }

        //if token implies If statement
        if(5 == currentToken) {
            altNo = 2;
            IF = new If();
            IF.parseIf();
            return;
        }

        //loop token implies Loop stmt
        if(8 == currentToken) {
            altNo = 3;
            loop = new Loop();
            loop.parseLoop();
            return;
        }

        //in token implies In stmt
        if(10 == currentToken) {
            altNo = 4;
            in = new In();
            in.parseIn();
            return;
        }

        //out token implies Out stmt
        if(11 == currentToken) {
            altNo = 5;
            out = new Out();
            out.parseOut();
            return;
        }
    }

    public void printStmt(int indentLevel) throws FileNotFoundException, IOException {
        if(1 == altNo) {
            assgn.printAssign(indentLevel);
        } else if(2 == altNo) {
            IF.printIf(indentLevel);
        } else if(3 == altNo) {
            loop.printLoop(indentLevel);
        } else if(4 == altNo) {
            in.printIn(indentLevel);
        } else if(5 == altNo) {
            out.printOut(indentLevel);
        }
    }

    public void executeStmt() throws FileNotFoundException, IOException {
	if(1 == altNo) {
            assgn.executeAssign();
        } else if(2 == altNo) {
            IF.executeIf();
        } else if(3 == altNo) {
            loop.executeLoop();
        } else if(4 == altNo) {
            in.executeIn();
        } else if(5 == altNo) {
            out.executeOut();
        }
    }
}
