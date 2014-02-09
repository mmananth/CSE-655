import java.io.*;

//class for non-terminal <decl seq>
class DS {
    private Decl decl;
    private DS ds;
    public DS() {
        decl = null;
        ds = null;
    }
    public void parseDS() throws FileNotFoundException, IOException {
        decl = new Decl();
        decl.parseDecl();
        if(4 == Tokenizer.instance().getToken()) {
            ds = new DS();
            ds.parseDS();
        }
    }

    public void printDS() throws IOException {
        decl.printDecl();
        if(null != ds) {
            ds.printDS();
        }        
    }
}
