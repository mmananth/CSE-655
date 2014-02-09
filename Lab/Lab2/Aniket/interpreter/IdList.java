import java.io.*;

//class for <id list>
class IdList {
    private Id id;
    private IdList idList;
    public IdList() {
        id = null;
        idList = null;
    }

    //This is for parsing an identifier list in declaration part
    public void parseIdListForDS() throws FileNotFoundException, IOException {
        id = Id.parseIdForDS();
        
        //skip the , in the identifier list
        if(13 == Tokenizer.instance().getToken()) {
            Tokenizer.instance().skipToken();
            if(32 == Tokenizer.instance().getToken()) {
                idList = new IdList();
                idList.parseIdListForDS();
            } else {
		System.out.println("Parse error : expected : ID");
		System.exit(0);
            }
	}
    }

    //This is for parsing an identifier list in any statement
    public void parseIdListForSS() throws FileNotFoundException, IOException {
        id = Id.parseIdForSS();
        if(13 == Tokenizer.instance().getToken()) {
            Tokenizer.instance().skipToken();
            if(32 == Tokenizer.instance().getToken()) {
                idList = new IdList();
                idList.parseIdListForSS();
            } else {
                System.out.println("Parse error : expected : ID");
                System.exit(0);
            }
        }
    }

    public void printIdList() throws FileNotFoundException, IOException {
        System.out.print(id.getName());
        if(null != idList) {
            System.out.print(", ");
            idList.printIdList();
        }
    }

    public void readInput() throws FileNotFoundException, IOException {
        id.setValue(Tokenizer.instance().getNextInput());
	//        System.out.println("DEBUG::"+id.getValue());
        if(null != idList) {
            idList.readInput();
        }
    }

    public void writeOutput() throws FileNotFoundException, IOException {
        if(!id.getInitialized()) {
            System.out.println("Run time error: variable "+id.getName()+" used without initialization");
            System.exit(0);
        }
        System.out.println(id.getName()+" = "+id.getValue());
        if(null != idList) {
            idList.writeOutput();
        }
    }
}
