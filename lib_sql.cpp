#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
#include<sstream>
#include<string>
#include<mysql.h>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<math.h>

using namespace std;



// Adjust date by a number of days + / -
void DatePlusDays(struct tm* date, int days)
{
    const time_t ONE_DAY = 24 * 60 * 60;

    // Seconds since start of epoch
    time_t date_seconds = mktime(date) + (days * ONE_DAY);

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime(&date_seconds); ;
}

// Global Variable
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            
            system("cls");
        }
        else {
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
            return;
        }
        conn = mysql_real_connect(conn, "localhost", "root", "password", "newdb", 3306, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            
        }
        else
            cout << "Failed To Connect! " << mysql_errno(conn) << endl;
    }
};


void AddNewItemInDatabase();
void ShowAllItems();
void ItemInStock();
void FindBook();
void EditItem();
void RemoveItem();
void CreateOrder(string);
void SoldItems();

// Library Management System.cpp

void LibrarianSection();
void ReaderSection();
void AboutUs();
string Login_Register();
string Login();
string Register();
void calculate_fine(string id);
void morethan3(string);
void returnbook(string);



int main()
{
    // Initial Load
    system("cls");
    system("title Library Management System");
    //system("color 0a");
    // Initial Load End

    db_response::ConnectionFunction();

    // Variables
    int chooseOneFromMenu = 0;
    char exitSurity;
    // Variables End

    cout << "Welcome To Library Main Section" << endl << endl;
    cout << "1. Librarian Section." << endl;
    cout << "2. Reader Section." << endl;
    cout << "3. About Us." << endl;
    cout << "4. Exit." << endl << endl;
    cout << "Choose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        LibrarianSection();
        break;
    case 2:
        ReaderSection();
        break;
    case 3:
        AboutUs();
        break;
    case 4:
    ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            return 0;
        }
        else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            main();
        }
        else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 4. Press Enter To Continue...";
        getchar();
        getchar();
        system("cls");
        main();
        break;
    }
    return 0;
}

void LibrarianSection()
{
    system("cls");

    int chooseOneFromMenu = 0;
    cout << "Welcome To Librarian Section" << endl << endl;
    cout << "1. Find Book." << endl;
    cout << "2. Issued Books." << endl;
    cout << "3. Books in Stock." << endl;
    cout << "4. All Books." << endl;
    cout << "5. Add New Book." << endl;
    cout << "6. Edit Book details." << endl;
    cout << "7. Remove Book." << endl;
    cout << "8. Back To Library Main Section." << endl << endl;
    cout << "Choose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        FindBook();
        break;
    case 2:
        SoldItems();
        break;
    case 3:
        ItemInStock();
        break;
    case 4:
        ShowAllItems();
        break;
    case 5:
        AddNewItemInDatabase();
        break;
    case 6:
        EditItem();
        break;
    case 7:
        RemoveItem();
        break;
    case 8:
        system("cls");
        main();
        break;
    default:
        cout << "Please choose between 1 - 8. Press Enter To Continue...";
        getchar();
        getchar();
        system("cls");
        LibrarianSection();
        break;
    }
}

void ReaderSection()
{
    static string id="";
    static int n = 0;
    if (n == 0)
    {
        id=Login_Register();
        calculate_fine(id);
        n++;
    }
    system("cls");

    int chooseOneFromMenu = 0;
    cout << "Welcome To Reader Section" << endl << endl;
    cout << "1. Issue book." << endl;
    cout << "2. Find Book." << endl;
    cout << "3. Issued Books." << endl;
    cout << "4. Books in Stock." << endl;
    cout << "5. All Books." << endl;
    cout << "6. Back To Library Main Section." << endl;
    cout << "7. Log out." << endl;
    cout << "8. Return book." << endl<<endl;
    cout << "Choose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        CreateOrder(id);
        break;
    case 2:
        FindBook();
        break;
    case 3:
        SoldItems();
        break;
    case 4:
        ItemInStock();
        break;
    case 5:
        ShowAllItems();
        break;
    case 6:
        system("cls");
        main();
        break;

    case 7:
        n = 0;
        ReaderSection();
        break;

    case 8:
        returnbook(id);
        break;



    default:
        cout << "Please choose between 1 - 8. Press Enter To Continue...";
        getchar();
        getchar();
        system("cls");
        ReaderSection();
        break;
    }
}

void AboutUs()
{
    system("cls");

    cout<< "Librarian Section :\n1)	Find Book : Librarian can find their books with four different categories Name, Category, Type, and Author.";
    cout << " \n2)	Issued Books : Through this function librarian can check how many booksand which books were sold.";
    cout << "\n3)	Books in stock : It shows the book that is in the stock that means the quantity of the book is more than zero.";
    cout << "\n4)	All books : It shows all the books in the database.";
    cout << "\n5)	Add new Book: This is used to add new book in the database.";
    cout << "\n6)	Edit book details : It is used to edit any book contents.";
    cout << "\n7)	Remove Book : It allows librarian to delete any book from the database.\n\n";

        cout << "\nReader Section :";
        cout << "\n1)	Reader register login: Here a new user can registerand then login to issue books or an existing user can login with the credentials to issue books.";
        cout << "\n2)	Issue Book : Here the reader can choose the books, not more than 3 books and specify the number of days between 8 to 40 days for which reader wants to issue book.\n        Also, the issue dateand the due date is calculated.";
        cout << "\n3)	Find Book : Reader can find their books with four different categories Name, Category, Type, and Author.";
        cout << "\n4)	Issued Books : Through this function, Reader can check how many booksand which books were sold.";
        cout << "\n5)	Books in stock : It shows the book that is in the stock that means the quantity of the book is more than zero.";
        cout << "\n6)	Return Book : This function allows the user to return the books and fine alert is also shown.";
        cout << "\n7)	All books : It shows all the books in the database.";
        cout << "\n8)	Logout: This allows the user to logout from the reader section.\n\n";

    cout << "                                 **************************\n";
    cout << "                                 PEOPLE BEHIND THIS PROJECT\n";
    cout << "                                 **************************\n\n\n";
    cout << "\n\n";

    cout << "\tMr. Ankit Vishnoi\n";
    cout << "\tAnish Bansal\n";
    cout << "\tAnkit Gupta\n";
    cout << "\tKartikey\n";
    cout << "\tNikhil Jain\n";

    cout << "\n\n\n\n";
    cout << "                                 *********** THANK YOU ************\n\n\n";
    cout << "\n";

    cout << "Press Enter To Return Library Main Section ";

    getchar();
    getchar();
    main();
}



void ShowAllItems()
{
system("cls");

// Variables
char choose;
// Variables End

cout<<"Welcome To Library" << endl << endl;
cout<<"Show All Books" << endl << endl;

qstate = mysql_query(conn, "select * from allBooks_tb2");
if (!qstate)
{
    res = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res)))
    {
        cout << "ID: " << row[0] << "\nCategory: " << row[1] << "\nType: " << row[2] << "\nName: " << row[3] << "\nAuthor: " << row[4] << "\nPrice: " << row[5] << "\nQuantity: " << row[6] << endl << endl;
    }
}
else
{
    cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
}

// Exit Code
cout << "Press 'm' to Menu and any other key to Exit: ";
cin >> choose;
if (choose == 'm' || choose == 'M')
{
    main();
}
else
{
    exit(0);
}
}

void AddNewItemInDatabase()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string category = "";
    string type = "";
    string name = "";
    string author = "";
    float price = 0.0;
    int quantity = 0;
    char choose;
    // Variables End

    cout << "Welcome To Library" << endl << endl;
    cout << "Add New Book" << endl << endl;

    cin.ignore(1, '\n');
    cout << "Enter Category: ";
    getline(cin, category);
    cout << "Enter Type: ";
    getline(cin, type);
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> quantity;

    stringstream streamPrice, streamQuan;
    string sprice, squan;
    streamPrice << price;
    streamPrice >> sprice;
    streamQuan << quantity;
    streamQuan >> squan;


    string insert_query = "insert into allBooks_tb (m_category, m_type, m_name, m_author, m_price, m_quantity) values ('" + category + "','" + type + "','" + name + "','" + author + "','" + sprice + "','" + squan + "')";

    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    insert_query = "insert into allBooks_tb2 (m_category, m_type, m_name, m_author, m_price, m_quantity) values ('" + category + "','" + type + "','" + name + "','" + author + "','" + sprice + "','" + squan + "')";

    q = insert_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        AddNewItemInDatabase();
    }
    else
    {
        exit(0);
    }
}

void ItemInStock()
{
    system("cls");

    // Variables
    char choose;
    // Variables End

    cout << "Welcome To Library" << endl << endl;
    cout << "Books In Stock Menu" << endl << endl;

    qstate = mysql_query(conn, "select m_name, m_author, m_price, m_quantity from allBooks_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            if (atoi(row[3]) > 0)
            {
                cout << "Name: " << row[0] << "\nAuthor: " << row[1] << "\nPrice: " << row[2] << "\nQuantity: " << row[3] << endl << endl;
            }
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

void FindBook()
{
    system("cls");

    // Variables
    char choose;
    string input;
    // Variables End

    cout << "Welcome To Library" << endl << endl;
    cout << "Find Books Menu" << endl << endl;

    cout << "Find by \n1. Name\n2. Category\n3. Type\n4. Author\nAny other number to Menu" << endl;
    cout << "Choose One: "; cin >> choose;
    system("cls");

    cin.ignore(1, '\n');
    if (choose == '1')
    {
        cout << "Enter Name: "; getline(cin, input);
        string findbyname_query = "select * from allBooks_tb where m_name like '" + input + "%'";
        const char* qn = findbyname_query.c_str();
        qstate = mysql_query(conn, qn);
    }
    else if (choose == '2')
    {
        cout << "Enter Category: "; getline(cin, input);
        string findbycategory_query = "select * from allBooks_tb where m_category like '" + input + "%'";
        const char* qc = findbycategory_query.c_str();
        qstate = mysql_query(conn, qc);
    }
    else if (choose == '3')
    {
        cout << "Enter Type: "; getline(cin, input);
        string findbytype_query = "select * from allBooks_tb where m_type like '" + input + "%'";
        const char* qt = findbytype_query.c_str();
        qstate = mysql_query(conn, qt);
    }
    else if (choose == '4')
    {
        cout << "Enter Author: "; getline(cin, input);
        string findbyauthor_query = "select * from allBooks_tb where m_author like '" + input + "%'";
        const char* qa = findbyauthor_query.c_str();
        qstate = mysql_query(conn, qa);
    }
    else
    {
        goto ExitMenu;
    }

    cout << endl;
    if (choose == '1' || choose == '2' || choose == '3' || choose == '4')
    {
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                cout << "ID: " << row[0] << "\nCategory: " << row[1] << "\nType: " << row[2] << "\nName: " << row[3] << "\nAuthor: " << row[4] << "\nPrice: " << row[5] << "\nQuantity: " << row[6] << endl << endl;
            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }

ExitMenu:
    cout << "Press 'm' to Menu, 'a' to Search again and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        FindBook();
    }
    else
    {
        exit(0);
    }
}

void EditItem()
{
    system("cls");

    // Variables
    string category = "";
    string type = "";
    string name = "";
    string author = "";
    string items[5000];
    string price = "";
    string quantity = "";
    char choose;
    int itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    // Store Variables
    string storeid = "";
    string storecategory = "";
    string storetype = "";
    string storename = "";
    string storeauthor = "";
    string storeprice = "";
    string storequantity = "";
    // Variables End

    cout << "Welcome To Library" << endl << endl;
    cout << "Edit Book Menu" << endl << endl;

    qstate = mysql_query(conn, "select m_id, m_name from allBooks_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "ID\tName\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout << row[0] << "\t" << row[1] << endl;
            items[indexForId] = row[0];
            indexForId++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }
            else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from allBooks_tb where m_id = '" + strid + "'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                cout << endl;
                while ((row = mysql_fetch_row(res)))
                {
                    cout << "ID: " << row[0] << "\nCategory: " << row[1] << "\nType: " << row[2] << "\nName: " << row[3] << "\nAuthor: " << row[4] << "\nPrice: " << row[5] << "\nQuantity: " << row[6] << endl << endl;
                    storeid = row[0];
                    storecategory = row[1];
                    storetype = row[2];
                    storename = row[3];
                    storeauthor = row[4];
                    storeprice = row[5];
                    storequantity = row[6];
                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            cout << "Enter Category (xN to not change): ";
            getline(cin, category);
            if (category == "xN")
            {
                category = storecategory;
            }
            cout << "Enter Type (xN to not change): ";
            getline(cin, type);
            if (type == "xN")
            {
                type = storetype;
            }
            cout << "Enter Name (xN to not change): ";
            getline(cin, name);
            if (name == "xN")
            {
                name = storename;
            }
            cout << "Enter Author (xN to not change): ";
            getline(cin, author);
            if (author == "xN")
            {
                author = storeauthor;
            }
            cout << "Enter Price (xN to not change): ";
            cin >> price;
            if (price == "xN")
            {
                category = storecategory;
            }
            cout << "Enter Quantity (xN to not change): ";
            cin >> quantity;
            if (quantity == "xN")
            {
                quantity = storequantity;
            }

            string update_query = "update allBooks_tb set m_category = '" + category + "', m_type = '" + type + "', m_name = '" + name + "', m_author = '" + author + "', m_price = '" + price + "', m_quantity = '" + quantity + "' where m_id = '" + strid + "'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Saved In Database." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

            update_query = "update allBooks_tb2 set m_category = '" + category + "', m_type = '" + type + "', m_name = '" + name + "', m_author = '" + author + "', m_price = '" + price + "', m_quantity = '" + quantity + "' where m_id = '" + strid + "'";
            qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another book and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'e' || choose == 'E')
    {
        EditItem();
    }
    else
    {
        exit(0);
    }
}

void RemoveItem()
{
    system("cls");

    // Variables
    char choose;
    int itemId;
    string items[5000];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;
    // Variables End

    cout << "Welcome To Library" << endl << endl;
    cout << "Remove Item Menu" << endl << endl;

    qstate = mysql_query(conn, "select m_id, m_name from allBooks_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "ID\tName\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout << row[0] << "\t" << row[1] << endl;
            items[indexForId] = row[0];
            indexForId++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }
            else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string delete_query = "delete from allBooks_tb where m_id = '" + strid + "'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Successfully Deleted From Database." << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }

            delete_query = "delete from allBooks_tb2 where m_id = '" + strid + "'";
            qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    // Exit Code
ExitMenu:
    cout << "Press 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'd' || choose == 'D')
    {
        EditItem();
    }
    else
    {
        exit(0);
    }
}

void CreateOrder(string id)
{
    system("cls");
    morethan3(id);
    system("cls");

    // Variables
    char choose;
    string getId = "";
    string itemId[100];
    string itemName[100];
    char chooseEditOrBuy;
    int itemIndex = 0;
    float totalPrice = 0.0;
    bool purchase, itemFalse = false;

    string storeId[100];
    string storeName[100];
    string storeCategory[100];
    string storeType[100];
    string storeauthor[100];
    string storePrice[100];
    string storeQuantity[100];
    int storeIndex = 0, storeIndexN = 0;
    int getdays = 0;
    int itemdays[100];
    int itemissuday[100];
    int itemissumon[100];
    int itemissuyear[100];
    int itemduyear[100];
    int itemduday[100];
    int itemdumon[100];
     //Variables End

    cout << "Welcome To Library" << endl << endl;
    cout << "Show All books Menu" << endl << endl;

    qstate = mysql_query(conn, "select * from allBooks_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            if (atoi(row[6]) > 0)
            {
                cout << "ID: " << row[0] << "\nCategory: " << row[1] << "\nType: " << row[2] << "\nName: " << row[3] << "\nAuthor: " << row[4] << "\nPrice/day: " << row[5] << endl << endl;
                storeId[storeIndex] = row[0];
                storeCategory[storeIndex] = row[1];
                storeType[storeIndex] = row[2];
                storeName[storeIndex] = row[3];
                storeauthor[storeIndex] = row[4];
                storePrice[storeIndex] = row[5];
                storeQuantity[storeIndex] = row[6];
                storeIndex++;
            }
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    for (itemIndex = 0;itemIndex<3; itemIndex++)
    {
        cout << "Enter a Book ID's (q to exit): ";
        cin >> getId;
        if (getId == "q")
        {
            break;
        }
        days:cout << "Enter the number of days you want to issue[7-60]:";
        cin >> getdays;
        if (getdays < 7 && getdays>0 || getdays>60)
        {
            cout << "please enter days between 7 and 60\n";
            goto days;
        }

        time_t now = time(0);
        tm* nowstr = localtime(&now);

        
        
            for (int i = 0; i < storeIndex; i++)
            {
                if (getId == storeId[i])
                {
                    itemId[itemIndex] = getId;
                    itemdays[itemIndex] = getdays;
                    itemissuday[itemIndex] = nowstr->tm_mday;
                    itemissumon[itemIndex] = nowstr->tm_mon + 1;
                    itemissuyear[itemIndex] = nowstr->tm_year +1900;
                    DatePlusDays(nowstr, getdays);
                    itemduday[itemIndex] = nowstr->tm_mday;
                    itemdumon[itemIndex] = nowstr->tm_mon + 1;
                    itemduyear[itemIndex] = nowstr->tm_year + 1900;
                   
                    itemFalse = false;
                    break;
                }
                else
                {
                    itemFalse = true;
                }
            }
            if (itemFalse == true)
            {
                cout << "Enter a valid number." << endl;
                itemIndex--;
                itemFalse = false;
            }
        
    }

    cout << "You choose this book id's: ";
    for (int i = 0; i < itemIndex; i++)
    {
        cout << itemId[i] << " issue date= " << itemissuday[i]<<"/"<<itemissumon[i]<< "/" << itemissuyear[i] << "   due date "<<itemduday[i]<<"/"<<itemdumon[i]<< "/" << itemduyear[i] <<endl;
    }

CHOOSEEDITORBUY:
    cout << endl << "Do you want to edit book list(e) or issue these books(b): ";
    cin >> chooseEditOrBuy;

    if (chooseEditOrBuy == 'e')
    {
        for (int i = 0;; i++)
        {
            cout << "Remove item id's (q to exit): ";
            cin >> getId;
            if (getId == "q")
            {
                break;
            }
            else
            {
                for (int j = 0; j < itemIndex; j++)
                {
                    if (itemId[j] == getId)
                    {
                        for (int k = j; k < itemIndex; k++)
                        {
                            itemId[k] = itemId[k + 1];
                            itemdays[k] = itemdays[k + 1];
                            itemissuday[k] = itemissuday[k + 1];
                            itemissumon[k] = itemissumon[k + 1];
                            itemduday[k] = itemduday[k + 1];
                            itemdumon[k] = itemdumon[k + 1];

                        }
                        itemId[itemIndex] = "\0";
                        itemdays[itemIndex] = 0;
                        itemissuday[itemIndex] = 0;
                        itemissumon[itemIndex] = 0;
                        itemduday[itemIndex] = 0;
                        itemdumon[itemIndex--] = 0;
                    }
                }
            }
        }

        cout << "You choose these book id's: ";
        for (int i = 0; i < itemIndex; i++)
        {
            cout << itemId[i] << " issue date=> " << itemissuday[i] << "/" << itemissumon[i] << "/" << itemissuyear[i] << "   due date=> " << itemduday[i] << "/" << itemdumon[i] << "/" << itemduyear[i] << endl;
        }

        goto CHOOSEEDITORBUY;
    }
    else if (chooseEditOrBuy == 'b')
    {
        for (int i = 0; i < itemIndex; i++)
        {
            for (int j = 0; j < storeIndex; j++)
            {
                if (itemId[i] == storeId[j])
                {
                    qstate = mysql_query(conn, "select m_quantity from allBooks_tb");
                    if (!qstate)
                    {
                        res = mysql_store_result(conn);
                        while ((row = mysql_fetch_row(res)))
                        {
                            if (atoi(row[0]) > 0)
                            {
                                storeQuantity[storeIndexN] = row[0];
                                storeIndexN++;
                            }
                        }
                        storeIndexN = 0;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }

                    totalPrice += (strtof((storePrice[j]).c_str(), 0))*itemdays[i];

                    float quan1 = strtof((storeQuantity[j]).c_str(), 0);
                    quan1 -= 1;
                    float quan2 = strtof((storeQuantity[j]).c_str(), 0);
                    float quan = quan2 - quan1;
                    string getResult;
                    stringstream strquan;
                    strquan << quan;
                    strquan >> getResult;

                    string getQuan1;
                    stringstream strquan1;
                    strquan1 << quan1;
                    strquan1 >> getQuan1;

                    string issuedate;
                    stringstream getdate;
                    getdate << itemissuday[i]<<"/"<<itemissumon[i]<<"/"<<itemissuyear[i];
                    getdate >> issuedate;

                    string duedate;
                    stringstream getdate1;
                    getdate1 << itemduday[i] << "/" << itemdumon[i] << "/" << itemduyear[i];
                    getdate1 >> duedate;



                    string insert_query = "insert into solditem_tb (m_category, m_type, m_name, m_author, m_price, m_quantity,m_issuedate,m_duedate) values ('" + storeCategory[j] + "','" + storeType[j] + "','" + storeName[j] + "','" + storeauthor[j] + "','" + storePrice[j] + "','" + getResult + "',STR_TO_DATE('"+ issuedate + "','%d/%m/%Y'),STR_TO_DATE('"+ duedate +"','%d/%m/%Y'))";

                    purchase = true;

                    //cout << insert_query << endl;


                    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

                    qstate = mysql_query(conn, q);

                    if (!qstate)
                    {
                        purchase = true;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }


                    insert_query = "insert into "+ id + "(book_name, issuedate, duedate) values('" + storeName[j] + "',STR_TO_DATE('" + issuedate + "','%d/%m/%Y'), STR_TO_DATE('" + duedate + "','%d/%m/%Y'))";
                    q = insert_query.c_str(); // c_str converts string to constant char and this is required

                    qstate = mysql_query(conn, q);

                    if (!qstate)
                    {
                        purchase = true;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }


                    string update_query = "update allBooks_tb set m_quantity = '" + getQuan1 + "' where m_id = '" + storeId[j] + "'";
                    const char* qu = update_query.c_str();
                    //cout << update_query << endl;

                    qstate = mysql_query(conn, qu);

                    if (qstate)
                    {
                        cout << "Failed To Update!" << mysql_errno(conn) << endl;
                    }
                }
            }
        }

        if (purchase == true)
        {
            cout << endl << "Book Issued Successfully." << endl;
            //cout << endl << "Total Price: " << totalPrice << endl;
        }
    }

    // Exit Code
    cout << endl << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

void SoldItems()
{

    system("cls");

    // Variables
    char choose;
    // Variables End

    cout << "Welcome To Library" << endl << endl;
    cout << "Sold books Menu" << endl << endl;

    qstate = mysql_query(conn, "select m_name, m_author, m_category, m_type, m_price, m_quantity, m_issuedate, m_duedate from solditem_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "Name: " << row[0] << "\nAuthor: " << row[1] << "\nCategory: " << row[2] << "\nType: " << row[3] << "\nPrice: " << row[4] << "\nQuantity: " << row[5] <<"\nIssuedate: " << row[6] << "\nDuedate: " <<row[7] << endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }

}

string Login_Register()
{
    string id;
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    int chooseOneFromMenu = 0;
    char exitSurity;
    // Variables End

    cout << "Welcome To Library Reader Section" << endl << endl;
    cout << "1. Login." << endl;
    cout << "2. Register." << endl;
    cout << "3. Back To Main Section." << endl;
    cout << "Choose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        id=Login();
        break;
    case 2:
        id=Register();
        break;
    case 3:
        main();
        break;
    default:
        cout << "Please choose between 1 - 3. Press Enter To Continue...";
        getchar();
        getchar();
        system("cls");
        Login_Register();
            break;
    }
    return id;
}

string Login()
{
    system("cls");

    // Variables
    int flag = 0;
    string id = "";
    string password = "";
    string name = "";
    // Variables End

    cout << "Welcome To Library" << endl << endl;
    //cout << "Show All Books" << endl << endl;

    cin.ignore(1, '\n');
    cout << "Enter Id: ";
    cin>>id;
    cout << "Enter Password: ";
    cin>>password;

    qstate = mysql_query(conn, "select r_id, r_name, r_password from reader_details");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            if (id==row[0])
                if (password == row[2])
                {
                    cout << "Welcome " << row[1] << " To Library\n";
                    cout << "Press Enter To Proceed.....";
                    getchar();
                    getchar();
                    flag = 1;
                    break;
                }
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    //cout << "Press 'm' to Menu and any other key to Exit: ";
    //cin >> choose;
    if (flag == 0)
    {
        cout << "Error! Press Enter To Re-Login.....";
            getchar();
        getchar();
        Login();
    }
    return id;

}


string Register()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string id = "";
    string name = "";
    string password = "";
    // Variables End


    cin.ignore(1, '\n');
    cout << "Enter Id: ";
    getline(cin, id);
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Password: ";
    getline(cin, password);
  


    string insert_query = "insert into reader_details (r_id, r_name, r_password) values ('" + id + "','" + name + "','" + password + "')";
    

    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Registered Successfully!" << endl;
        string insert_query = "create table "+ id + " (id int(10) NOT NULL AUTO_INCREMENT, book_name varchar(100) default '0',issuedate date default '0-0-0', duedate date default '0-0-0', PRIMARY KEY (id) )";


        const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            cout << "Press Enter To Login....." << endl;
            getchar();
            getchar();
            Login();

         }

        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            cout << "Press Enter To Re-Register.....";
            getchar();
            getchar();
            Register();
        }
        
       
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        cout << "Press Enter To Re-Register.....";
            getchar();
        getchar();
        Register();
    }
    return id;
}


void calculate_fine(string id)
{
    time_t now = time(0);
    tm* nowstr = localtime(&now);
    string query = "select * from " + id;
    const char* q = query.c_str();
    int allow = 0;

    qstate = mysql_query(conn, q);
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            if (atoi(row[3]) > 0)
            {
                string issuedate = row[3];
                const char *issdate = issuedate.c_str();
                const char* split = "-";
                const char* s = strpbrk(issdate, split);
                stringstream strea;
                string year;
                string month;
                string day;
                for (const char* i = issdate; i < s; i++)
                {
                    strea << i[0];                

                }

                strea >> year;
                s++;
                stringstream strea2;
                const char* s2 = strpbrk(s,split);
                for (const char* i = s; i < s2; i++)
                {
                    strea2 << i[0];

                }

                strea2 >> month;
                s2++;
                day = s2;
                int yr = atoi(year.c_str());
                int mon = atoi(month.c_str());
                int dd = atoi(day.c_str());
                tm* issustr = new tm();
                issustr->tm_mday = dd;
                issustr->tm_mon = mon - 1;
                issustr->tm_year = yr - 1900;
                //cout << nowstr->tm_mday << " " << issustr->tm_mday << endl;
                //cout << nowstr->tm_mon << " " << issustr->tm_mon << endl;
                //cout << nowstr->tm_year << " " << issustr->tm_year << endl;
                if (nowstr->tm_year == issustr->tm_year && nowstr->tm_mon == issustr->tm_mon && nowstr->tm_mday == issustr->tm_mday)
                {
                    cout << "Today is your due date for the book " << row[1] << ". Please return the book.\n Otherwise you have to pay fine of Rs 10/day ";
                    allow = 1;
                }


            }
        }

        if (allow == 1)
        {
            cout << "Press Enter To continue.....";
            getchar();
            getchar();
            returnbook(id);
            calculate_fine(id);
        }

    }

    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;

    }

}

void morethan3(string id)
{
    string records;

    string query = "select count(book_name) from " + id;
    const char* q = query.c_str();

    qstate = mysql_query(conn, q);
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            if (atoi(row[0]) > 0)
            {
                records = row[0];

            }
        }

        if (records == "3")
        {
            cout << "You cannot issue more books. You have already issued 3 books." << endl;
            cout << "Press Enter To continue.....";
            getchar();
            getchar();
            ReaderSection();
        }

    }

    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;

    }


}

void returnbook(string id)
{
    system("cls");

    // Variables
    int i;
    char choose;
    int itemId;
    string items[100];
    string name[100];
    string issuedate[100];
    string duedate[100];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;
    // Variables End

    cout << "Welcome To Library" << endl << endl;
    cout << "Return Book Menu" << endl << endl;
    string qu = "select * from " + id;

    qstate = mysql_query(conn, qu.c_str());
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "S.NO\t\tBook Name\t\tIssueDate\t\tDueDate\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout << row[0] << "\t\t" << row[1] << "\t\t" << row[2] << "\t\t" << row[3] << endl;
            items[indexForId] = row[0];
            name[indexForId] = row[1];
            issuedate[indexForId] = row[2];
            duedate[indexForId] = row[3];
            indexForId++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Book ID to return: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }
            else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string delete_query = "delete from " + id + " where id = '" + strid + "'";
            //cout <<delete_query<< endl;
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Book successfully returned" << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }

            delete_query = "delete from solditem_tb where m_name = '" + name[i] + "' AND m_issuedate= '" + issuedate[i] + "' AND m_duedate='" + duedate[i] + "'";
            //cout << delete_query << endl;
            qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);
            if (!qstate)
            {
                //cout << "Successfully Deleted From Soldbooks." << endl;
            }
            else
            {
                cout << "Failed To Delete from Soldbooks!" << mysql_errno(conn) << endl;
            }

            string qu = "select m_quantity from allBooks_tb where m_name ='" + name[i] + "'";
            //cout << qu << endl;

            qstate = mysql_query(conn, qu.c_str());
            if (!qstate)
            {
                char* qua;
                int quantity;
                res = mysql_store_result(conn);
                while ((row = mysql_fetch_row(res)))
                {
                    qua = row[0];
                    quantity = atoi(qua);
                    quantity++;

                }
                stringstream streamqua;
                string qty;
                streamqua << quantity;
                streamqua >> qty;
                string query = "update allBooks_tb set m_quantity = '" + qty + "' where m_name = '" + name[i] + "'";
                //cout << query<<endl;
                qstate = mysql_query(conn, query.c_str());
                if (!qstate)
                {
                    //cout << "successfully updated allbooks_tb";
                }

                else
                {
                    cout << "unable to update allbooks_tb ";
                }

            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    // Exit Code
ExitMenu:
    cout << "Press 'm' to Menu, 'r' to return another book and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'r' || choose == 'R')
    {
        returnbook(id);
    }
    else
    {
        exit(0);
    }

}


