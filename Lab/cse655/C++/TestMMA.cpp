class User;


class MyMessageBox
{
public:
 void sendMessage(Message *msg, User *recvr);
 vector<Message> *dataMessageList;
};

class User
{
public:
 MyMessageBox dataMsgBox;
};
