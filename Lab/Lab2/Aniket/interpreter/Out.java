import java.io.*;

//class for <out> NT
class Out {
    private IdList idList;
    public Out() {
        idList = null;
    }
    public void parseOut() throws FileNotFoundException, IOException {
        //check & skip terminal "write"
        if(11 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : write");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
        idList = new IdList();
        idList.parseIdListForSS();
        //check & skip terminal ";"
	if(12 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected ;");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
    }

    public void printOut(int indentLevel) throws FileNotFoundException, IOException {
        System.out.print(String.format("%1$#" + (4*indentLevel) + "swrite ", " "));
        idList.printIdList();
        System.out.println(";");
    }

    public void executeOut() throws FileNotFoundException, IOException {
        idList.writeOutput();
    }
}
