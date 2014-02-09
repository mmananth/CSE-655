import java.io.*;

//class for <in> NT
class In {
    private IdList idList;
    public In() {
        idList = null;
    }
    public void parseIn() throws FileNotFoundException, IOException {
        //check & skip terminal "read"
        if(10 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected : read");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
        idList = new IdList();
        idList.parseIdListForSS();
        //check & skip ";"
	if(12 != Tokenizer.instance().getToken()) {
            System.out.println("Parse error : expected ;");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
    }

    public void printIn(int indentLevel) throws FileNotFoundException, IOException {
        System.out.print(String.format("%1$#" + (4*indentLevel) + "sread ", " "));
        idList.printIdList();
        System.out.println(";");
    }

    public void executeIn() throws FileNotFoundException, IOException {
        idList.readInput();
    }
}
