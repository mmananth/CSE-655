import java.io.*;

//class for non-terminal <decl>
class Decl {
    private IdList idList;
    public Decl() {
        idList = null;
    }
    public void parseDecl() throws FileNotFoundException, IOException {
        Tokenizer t = Tokenizer.instance();
        
        //check and skip terminal "int"
        if(4 != t.getToken()) {
            System.out.println("Parse Error : expected : int");
            System.exit(0);
        }
        t.skipToken();

        idList = new IdList();
        idList.parseIdListForDS();

        //check and skip ;
        if(12 != t.getToken()) {
            System.out.println("Parse Error : expected : ;");
            System.exit(0);
        }
        t.skipToken();
    }
    
    public void printDecl() throws FileNotFoundException, IOException {
        System.out.print(String.format("%1$#4sint ", " "));
        idList.printIdList();
        System.out.println(";");
    }
}
