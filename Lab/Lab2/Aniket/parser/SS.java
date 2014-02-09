import java.io.*;

class SS {
    private Stmt stmt;
    private SS ss;
    public SS() {
        stmt = null;
        ss = null;
    }
    public void parseSS() {
        stmt = new Stmt();
        stmt.parseStmt();
        int currentToken = Tokenizer.instance().getToken();
        if(32 == currentToken ||
           5 == currentToken ||
           8 == currentToken ||
           10 == currentToken ||
           11 == currentToken) {
            ss = new SS();
            ss.parseSS();
        }
    }
}
