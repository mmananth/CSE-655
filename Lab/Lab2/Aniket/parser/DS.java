import java.io.*;

class DS {
    private Decl decl;
    private DS ds;
    public DS() {
        decl = null;
        ds = null;
    }
    public void parseDS() {
        decl = new Decl();
        decl.parseDecl();
        if(4 == Tokenizer.instance().getToken()) {
            ds = new DS();
            ds.parseDS();
        }
    }
}
