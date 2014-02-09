import java.io.*;

//class for non-terminal <stmt seq>
class SS {
    private Stmt stmt;
    private SS ss;
    public SS() {
        stmt = null;
        ss = null;
    }
    public void parseSS() throws FileNotFoundException, IOException {
        stmt = new Stmt();
        stmt.parseStmt();
        int currentToken = Tokenizer.instance().getToken();
        //checks whether the current token is the start token for any
        //statement alternative
        if(32 == currentToken ||
           5 == currentToken ||
           8 == currentToken ||
           10 == currentToken ||
           11 == currentToken) {
            ss = new SS();
            ss.parseSS();
        }
    }

    public void printSS(int indentLevel) throws FileNotFoundException, IOException {
        stmt.printStmt(indentLevel);
        if(null != ss) {
            ss.printSS(indentLevel);
        }
    }

    public void executeSS() throws FileNotFoundException, IOException {
        stmt.executeStmt();
        if(null != ss) {
            ss.executeSS();
        }
    }
}
