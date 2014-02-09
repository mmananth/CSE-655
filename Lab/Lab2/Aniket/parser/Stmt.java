import java.io.*;

class Stmt {
    private Assign assgn;
    private If IF;
    private Loop loop;
    private In in;
    private Out out;
    private int altNo;
    public Stmt() {
        assgn = null;
        IF = null;
        loop = null;
        in = null;
        out = null;
        altNo = 0;
    }
    public void parseStmt() {
        int currentToken = Tokenizer.instance().getToken();
        if(32 == currentToken) {
            altNo = 1;
            assgn = new Assign();
            assgn.parseAssign();
            return;
        }
        if(5 == currentToken) {
            altNo = 2;
            IF = new If();
            IF.parseIf();
            return;
        }
        if(8 == currentToken) {
            altNo = 3;
            loop = new Loop();
            loop.parseLoop();
            return;
        }
        if(10 == currentToken) {
            altNo = 4;
            in = new In();
            in.parseIn();
            return;
        }
        if(11 == currentToken) {
            altNo = 5;
            out = new Out();
            out.parseOut();
            return;
        }
    }
}
