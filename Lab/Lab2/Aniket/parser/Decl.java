import java.io.*;

class Decl {
    private IdList idList;
    public IdList() {
        idList = null;
    }
    public void parseDecl() {
        Tokenizer t = Tokenizer.instance();
        if(4 != t.getToken()) {
            System.out.println("Parse Error : expected : int");
            exit(0);
        }
        t.skipToken();
        idList = new IdList();
        idList.parseIdListForDS();
        if(12 != t.getToken()) {
            System.out.println("Parse Error : expected : ;");
            exit(0);
        }
        t.skipToken();
    }
}
