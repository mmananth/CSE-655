import java.io.*;

//class for <assign> NT
class Assign {
    Id id;
    Exp exp;
    public Assign() {
        id = null;
        exp = null;
    }
    public void parseAssign() throws FileNotFoundException, IOException {
        id = Id.parseIdForSS();

        //check & skip terminal "="
        if(14 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : =");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
        
        exp = new Exp();
        exp.parseExp();

        //check & skip terminal ;
        if(12 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected ;");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
    }

    public void printAssign(int indentLevel) throws IOException {
        System.out.print(String.format("%1$#" + (4*indentLevel) + "s"+id.getName()+" = ", " "));
        exp.printExp();
        System.out.println(";");
    }

    public void executeAssign() throws FileNotFoundException,IOException {
        id.setValue(exp.evalExp());
    }
}
