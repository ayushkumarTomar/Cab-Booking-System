//CabReplicationSystem
//3099_3110_3112
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<fstream>
#include<sstream>
#include<time.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
vector<string> areas(10);

//FUNCTION TO DISPLAY THE UPPER CONSTANT SCREEN TO GIVE A DESIGN TO THE CONSOLE SCREEN.
void upper()//TO BE USED BY ALL THE CLASSES
{
    system("cls");//CLEARS THE SCREEN
    cout<<endl<<endl;
    for(int i=0;i<200;i++)
        cout<<"*";
    cout<<endl;
    for(int j=0;j<10;j++)
        cout<<"\t";
    cout<<"AKSS CABS"<<endl;//DISPLAYS THE CAB NAME WITH A DESIGNED PATTERN ON EACH CONSOLE SCREEN
    for(int i=0;i<200;i++)
        cout<<"*";
    cout<<endl<<endl;
}
//USING DELAY FUNCTION TO PAUSE THE OUTPUT SCREEN FOR FEW SECONDS(AS WILL BE MENTIONED INSIDE ITS PARAMETERS).
void delay(int number_of_seconds)
{
  // Converting time into milli_seconds
  int milli_seconds = 1000 * number_of_seconds;
   // Storing start time
  clock_t start_time = clock();
  // looping till required time is not achieved
  while (clock() <start_time + milli_seconds);
}
typedef struct trip
{
    int pickup,drop,cabtype,price,time;
    string cabno,driver_name,cab_name;
}trip;
typedef struct cab
{
    int id;
    char cabno[9];
    int pickup;
    char driver_name[6];
    int drop;
    char cab_name[6];
    int cab_status; //1 for cab is occupied, 0 for cab is available
    int avg_rating,earnings;
    int noofbookings;
}cab;
//THE FIRST PAGE TO APPEAR AS WE RUN THE PROGRAM
void frontpage()
{
    for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        for(int i=0;i<15;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        cout<<"*";
        for(int j=0;j<10;j++)
            cout<<"\t";
        cout<<" CAB REPLICATION MODEL SYSTEM";
        for(int i=0;i<12;i++)
            cout<<"\t";
        cout<<"*"<<endl;
        for(int i=0;i<6;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        cout<<"*";
        for(int j=0;j<10;j++)
            cout<<"\t";
        cout<<"    WELCOME TO AKSS CABS";//NAME OF THE CAB APPLICATION INTRODUCED
        for(int i=0;i<12;i++)
            cout<<"\t";
        cout<<"*"<<endl;
        for(int i=0;i<10;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        delay(3);//PAUSE THE CONSOLE SCREEN FOR 3 SECONDS BEFORE PROCEEDING
        system("pause");//PAUSE THE SCREEN UNTIL ANY KEY IS PRESSED
        system("cls");
}
int noofcabs;//stores total number of cabs
//ALL INFORMATION ABOUT ADMIN OBJECT
class admin
{
    string password,correct_password,email;
public:
    cab ob[20];
    cab hash_table[15];
    admin()
    {
        email="admin";
        //password="admin123"
        correct_password="admin123";
    }
    int admin_login()
    {
        int f=0;
        string username;
        do
        {
            upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"********ADMIN LOGIN*********"<<endl<<endl;
            cout<<"Enter Email: ";
            cin>>username;
            cout<<"Enter Password: ";
            cin>>password;
            if(password==correct_password && username==email)
            {
                system("cls");
                upper();
                cout<<endl<<"Logged in Successfully!"<<endl;
                delay(3);
                system("cls");
                f=1;
            }
            else
            {
                system("cls");
                upper();
                cout<<endl<<"Wrong credentials entered. Please login again!"<<endl;
                system("pause");
                system("cls");
                f=0;
            }
        }while(f!=1);
        return f;
    }
    void change_password()
    {
        string pass,pas1;
        int f=0;
        delay(3);
        do
        {
             upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"********ADMIN LOGIN*********"<<endl<<endl;
            cout<<"Enter new password: ";
            cin>>pass;
            cout<<"Confirm new password: ";
            cin>>pas1;
            if(pass==pas1)
            {
                password=pas1;
                correct_password=pas1;
                cout<<endl<<"Password changed successfully!"<<endl;
                delay(3);
                f=1;
            }
            else
            {
                upper();
                for(int j=0;j<9;j++)
                    cout<<"\t";
                cout<<"********ADMIN LOGIN*********"<<endl<<endl;
                cout<<"Entered passwords do not match! Enter new password again."<<endl;
                system("pause");
                f=0;
            }
        }while(f!=1);
    }
    void driver_earnings(int i,int x)
    {
        ob[i].earnings=ob[i].earnings+x;
    }
    void add_cab()
    {
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        cab c;
        cout<<"Enter cab number: ";
        cin>>c.cabno;
        cin.clear();
        cout<<"Enter cab booking status: ";
        cin>>c.cab_status;
        cin.clear();
        cout<<"Enter driver_name: ";
        cin>>c.driver_name;
        cin.clear();
        cout<<"Enter cab's current pickup: ";
        cin>>c.pickup;
        cin.clear();
        cout<<"Enter cab name: ";
        cin>>c.cab_name;
        cin.clear();
        cout<<"Enter cab's current drop: ";
        cin>>c.drop;
        cin.clear();
        c.avg_rating=5;
        cout<<"Enter cab's earnings till now: ";
        cin>>c.earnings;
        cin.clear();
        cout<<"Enter cab's total no. of booking with us till now: ";
        cin>>c.noofbookings;
        cin.clear();
        c.id=((c.cabno[5]-'0')*1000) + ((c.cabno[6]-'0')*100) + ((c.cabno[7]-'0')*10) + ((c.cabno[8]-'0'));
        ob[noofcabs]=c;
        noofcabs=noofcabs+1;
    }
    void showDriverRatings();
    void update_rating(int rate,int index);
    void cabs_detail();
    void delete_cab();
};
admin a1;
void user_menu(int f);
void insertbyhash(cab ob)
{
    int index=(ob.id%13);
    if(a1.hash_table[index].id!=-1)
    {
        a1.hash_table[index]=ob;
    }
    else
    {
        while(a1.hash_table[index].id==-1 && index<15)
        {
            index++;
            if(index==15)
                index=0;
        }
        a1.hash_table[index]=ob;
    }
}
int search_cab(int num)
{
    int counter=0;
    int i=num%13;
    if(a1.hash_table[i].id==num)
    {
        return i;
    }
    else
    {
        while(a1.hash_table[i].id!=num && i<15)
        {
            i++;
            if(i==15)
            {
                i=0;
            }
            counter++;
            if(counter==15)
            {
                break;
            }
        }
        if(counter<15)
        {
           return i;
        }
        else
        {
            return -1;
        }
    }
    if(i<noofcabs)
    {
        return i;
    }
    return -1;
}


//REST FUNCTIONS OF ADMIN CLASS
void admin:: cabs_detail()
{
    upper();
    for(int j=0;j<9;j++)
        cout<<"\t";
    cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        for(int i=0;i<noofcabs;i++)
        {
            cout<<"Cab's ID: "<<a1.ob[i].id<<endl;
            cout<<"Cab number: "<<a1.ob[i].cabno<<endl;
            cout<<"Cab booking status: "<<a1.ob[i].cab_status<<endl;
            cout<<"Driver_name: "<<a1.ob[i].driver_name<<endl;
            cout<<"cab's current pickup: "<<a1.ob[i].pickup<<endl;
            cout<<"Cab name: "<<a1.ob[i].cab_name<<endl;
            cout<<"cab's current drop: "<<a1.ob[i].drop<<endl;
            cout<<"Avg_rating: "<<a1.ob[i].avg_rating<<endl;
            cout<<"cab's earnings till now: "<<a1.ob[i].earnings<<endl;
            cout<<"cab's total no. of booking with us till now: "<<a1.ob[i].noofbookings<<endl;
            cout<<endl<<endl;
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
}
void admin:: delete_cab()
{
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        int num;
        cout<<"Enter the cab Id of the cab you want to deregister: ";
        cin>>num;
        int i=search_cab(num);
        if(i!=-1)
        {
            cab tmp;
            tmp=a1.ob[i];
            a1.ob[i]=a1.ob[noofcabs-1];
            a1.ob[noofcabs-1]=tmp;
            cout<<"\nCab is deleted from our services!";
            delay(3);
            noofcabs--;
        }
        else
        {
            cout<<"Cab not found!";
            delay(3);
            system("cls");
        }
}
void admin::showDriverRatings()
{
         upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        for(int i=0;i<noofcabs;i++)
        {
            cout<<"Driver_name: "<<a1.ob[i].driver_name<<endl;
            cout<<"Avg_rating: "<<a1.ob[i].avg_rating<<endl;
            cout<<"cab's earnings till now: "<<a1.ob[i].earnings<<endl;
            cout<<endl<<endl;
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
}
void admin:: update_rating(int rate,int index)
{
        a1.ob[index].avg_rating=(a1.ob[index].avg_rating+rate)/a1.ob[index].noofbookings;
}

//ALL INFORMATION ABOUT USER OBJECT
class user
{
    string mob,password,correct_password,name,email;
    char gender;
    int pickup,drop,cab_type,fare,driver_rating;
    bool cab_status;
    vector<trip> t;
    cab ob;
public:
    user()
    {
        email="user1";
        //password="user123";
        correct_password="user123";
    }
   int login()
   {
       int f=0;
       string username;
       do
        {
            upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"*********USER LOGIN*********"<<endl<<endl;
            cout<<"Enter Email: ";
            cin>>username;
            cout<<"Enter Password: ";
            cin>>password;
            if(password==correct_password && cab_status==0 && username==email)
            {
                cout<<"Logged in Successfully!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                delay(3);
                user_menu(1);
                f=1;
            }
            else
            {
                cout<<"Wrong credentials entered! Please login again."<<endl;
                system("pause");
                f=0;
            }
        }while(f!=1);
        return f;
    }
    void signup()
    {
        int f=0;
        stringstream ss;
        do
        {
            upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"*********USER SIGNUP*********"<<endl<<endl;
            fflush(stdin);
            cout<<"Enter your Name: ";
            getline(cin,name);
            cout<<"Enter email-id: ";
            cin>>email;
            cout<<"Enter Mobile no.: ";
            cin>>mob;
            cout<<"Enter your gender[M/F]: ";
            cin>>gender;
            cout<<"Enter your password: ";
            cin>>password;
            cout<<"Confirm your password: ";
            cin>>correct_password;
            if(password==correct_password)
            {
                f=1;
                login();
            }
            else
            {
                f=0;
                cout<<"Entered passwords do not match please fill the form again!"<<endl;
                system("pause");
            }
        }while(f!=1);
    }
    void change_pass()
    {
        string pass,pass1;
        int f=0;
        do
        {
            upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"*********USER LOGIN*********"<<endl<<endl;
            cout<<"Enter a new password: ";
            cin>>pass;
            cout<<"Confirm new password: ";
            cin>>pass1;
            if(pass==pass1)
            {
                cout<<"Password is changed successfully!"<<endl;
                password=pass;
                correct_password=pass;
                for(int i=0;i<200;i++)
                    cout<<"*";
                delay(3);
                f=1;
            }
            else
            {
                f=0;
                cout<<"Entered passwords do not match! Enter a new password again."<<endl;
                system("pause");
            }
        }while(f!=1);
    }
    void trip_history()
    {
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"*********USER LOGIN*********"<<endl<<endl;
        if(t.size()==0)
        {
            cout<<"You haven't had any trip with our services yet! ";
        }
        else
        {
            int si=t.size();
            for(int i=0;i<si;i++)
            {
                cout<<"Trip number: "<<i+1<<endl;
                cout<<"Cab name and number: "<<t[i].cab_name<<t[i].cabno<<endl;
                cout<<"Driver name: "<<t[i].driver_name<<endl;
                cout<<"Pickup location: "<<areas[(t[i].pickup)-1]<<endl;
                cout<<"Drop location: "<<areas[(t[i].drop)-1]<<endl;
                cout<<"Fare: Rs. "<<t[i].price<<".00"<<endl;
                cout<<endl<<endl;
            }
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
    }
    void trip_details()
    {
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********TRIP DETAILS********"<<endl<<endl;
        int x=t.size()-1;
        cout<<"Cab name: "<<t[x].cab_name<<endl;
        cout<<"Cab number: "<<t[x].cabno<<endl;
        cout<<"Driver name: "<<t[x].driver_name<<endl;
        cout<<"\nPickup location: "<<areas[(t[x].pickup)-1]<<endl;
        cout<<"Drop location: "<<areas[(t[x].drop)-1]<<endl;
        cout<<"Fare: Rs."<<t[x].price<<".00"<<endl;
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
    }
    void getDriverRating(int c)
    {
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"*********USER LOGIN*********"<<endl<<endl;
        cout<<"Enter how many stars you want to give[1/2/3/4/5]: ";
        cin>>driver_rating;
        a1.update_rating(driver_rating,c);
        cout<<"Thank you for rating the driver!"<<endl;
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
    }
    void book_cab();
    void book_later();
};
user u1;
//Used Adjancency list
class Graph
{
    int V;
    list< pair<int, int> > *adj;
public:
    Graph(int n)
    {
        //allocates memory for adjacency list
        V=n;
        adj=new list<iPair> [n];
    }  // Constructor
    void addEdge(int u, int v, int w)// function to add an edge to graph
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    int shortestPath(int src,int dest)// Prints shortest paths from src to all other vertices
    {
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq; // Create a priority queue to store vertices that are being preprocessed.
        vector<int> dist(V, INF);
        pq.push(make_pair(0, src));  // Insert source itself in priority queue and initialize its distance as 0.
        dist[src] = 0;
        while (!pq.empty()) // Looping till priority queue becomes empty (or all distances are not finalized)
        {
           int u = pq.top().second;
           pq.pop();
           list< pair<int, int> >::iterator i; // 'i' is used to get all adjacent vertices of a vertex
           for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                // Get vertex label and weight of current adjacent of u.
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight)  //  If there is shorted path to v through u.
                {
                    dist[v] = dist[u] + weight; // Updating distance of v
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist[dest];
    }
};
Graph g(10);
void heapify(cab arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l].avg_rating > arr[largest].avg_rating)
        largest = l;
    if (r < n && arr[r].avg_rating > arr[largest].avg_rating)
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void tripheapify(vector<trip> arr, int i)
{
    int parent=(i-1)/2;
    while(parent!=0 && arr[parent].time>arr[i].time)
    {
        trip tmp;
        tmp=arr[parent];
        arr[parent]=arr[i];
        arr[i]=tmp;
        i=parent;
        parent=(i-1)/2;
    }
}
void heapSort(cab arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {

        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void sort_by_rating()
{
     heapSort(a1.ob,10);
}
int allocate_cab(int start,int endp)
{
    sort_by_rating();
    for(int i=0;i<10;i++)
    {
        if(a1.ob[i].drop==start && a1.ob[i].cab_status==0)
        {
            a1.ob[i].pickup=start;
            a1.ob[i].drop=endp;
            a1.ob[i].noofbookings+=1;
            return i;
        }
    }
    return -1;
}
void user:: book_cab()
{
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"*********USER LOGIN*********"<<endl<<endl;
        int dist;
        char confirmation;
        cout<<"You can book a cab between following areas:- "<<endl;
        int si1=areas.size();
        for(int i=0;i<si1;i++)
        {
            cout<<i+1<<"-> "<<areas[i]<<endl;
        }
        cout<<"Enter your choice of pickup location: ";
        cin>>pickup;
        cout<<"Enter your choice of drop location: ";
        cin>>drop;
        cout<<endl<<"You can book a cab of following types:- "<<endl;
        cout<<"1-> Micro"<<endl<<"2-> Mini"<<endl<<"3-> Sedan"<<endl<<"4-> Luxury"<<endl;
        cout<<"Enter your choice of cab type: ";
        cin>>cab_type;
        dist=g.shortestPath(pickup-1,drop-1);
        cout<<"Shortest path between "<<areas[pickup-1]<<" and "<<areas[drop-1]<<" is of "<<dist<<" kms."<<endl;
        fare=(7 + cab_type)*dist;
        cout<<"Fare of your trip would be Rs."<<fare<<".00"<<endl<<"Are you sure you want to book a cab?[Y/N]: ";
        cin>>confirmation;
        if(confirmation=='Y'||confirmation=='y')
        {
            int c;
            c=allocate_cab(pickup,drop);
            if(c!=-1)
            {
                cout<<endl<<"You are allocated "<<a1.ob[c].cabno<<"! Enjoy your ride!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
                cab_status=1;
                trip tmp;
                tmp.cabno=a1.ob[c].cabno;
                tmp.cab_name=a1.ob[c].cab_name;
                tmp.cabtype=cab_type;
                tmp.driver_name=a1.ob[c].driver_name;
                tmp.drop=drop;
                tmp.pickup=pickup;
                tmp.price=fare;
                tmp.time=0;
                t.push_back(tmp);
                a1.driver_earnings(c,fare);
                cout<<"You are on your way!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
                getDriverRating(c);
            }
            else
            {
                cout<<endl<<"Sorry! No cabs available right now !! "<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
            }
        }
}
void user:: book_later()
{
        char confirmation;
        int time,dist;
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"*********USER LOGIN*********"<<endl<<endl;
        cout<<"Enter after what time you want to take the ride [in hrs]: ";
        cin>>time;
        cout<<"You can book a cab between following areas:- "<<endl;
        int si2=areas.size();
        for(int i=0;i<si2;i++)
        {
            cout<<i+1<<"-> "<<areas[i]<<endl;
        }
        cout<<"Enter your choice of pickup location : ";
        cin>>pickup;
        cout<<"Enter your choice of drop location : ";
        cin>>drop;
        cout<<endl<<"You can book a cab of following types:- "<<endl;
        cout<<"1-> Micro"<<endl<<"2-> Mini"<<endl<<"3-> Sedan"<<endl<<"4-> Luxury"<<endl;
        cout<<"Enter your choice of cab type : ";
        cin>>cab_type;
        dist=g.shortestPath(pickup-1,drop-1);
        cout<<"Shortest path between "<<areas[pickup-1]<<" and "<<areas[drop-1]<<" is of "<<dist<<" kms."<<endl;
        fare=(7 + cab_type)*dist;
        cout<<"Fare of your trip would be Rs."<<fare<<".00!"<<endl<<"Are you sure you want to book a cab?[Y/N]: ";
        cin>>confirmation;
        if(confirmation=='Y'||confirmation=='y')
        {
            int c;
            c=allocate_cab(pickup,drop);
            if(c!=-1)
            {
                cout<<"You are allocated "<<a1.ob[c].cabno<<"! Enjoy your ride!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
                cab_status=1;
                trip tmp;
                tmp.cabno=a1.ob[c].cabno;
                tmp.cab_name=a1.ob[c].cab_name;
                tmp.cabtype=cab_type;
                tmp.driver_name=a1.ob[c].driver_name;
                tmp.drop=drop;
                tmp.pickup=pickup;
                tmp.price=fare;
                tmp.time=time;
                t.push_back(tmp);
                tripheapify(t,t.size());
                cout<<"You will reach your destination in desired time!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
                a1.driver_earnings(c,fare);
            }
        }
}
void admin_menu(int choice,int f)
{
    int ch1;
    if(choice==3 && f==1)
    {
        int opp=0;
        do
        {
           upper();
           for(int j=0;j<9;j++)
              cout<<"\t";
          cout<<"**********OPTIONS******"<<endl<<endl;
          cout<<"1-> CHANGE PASSWORD"<<endl;
          cout<<"2-> DISPLAY THE CABS WHICH ARE ALREADY ADDED WITH OUR SERVICES"<<endl;
          cout<<"3-> ADD ANOTHER CAB"<<endl;
          cout<<"4-> DELETE A CAB"<<endl;
          cout<<"5-> SHOW ALL DRIVERS' RATINGS"<<endl;
          cout<<"6-> UPDATE ANY DRIVER'S RATING"<<endl;
          cout<<"7-> EXIT"<<endl;
          cout<<"Enter your choice: ";
          cin>>ch1;
          switch(ch1)
          {
    case 1:
        a1.change_password();
        a1.admin_login();
        opp=0;
        break;
    case 2:
        a1.cabs_detail();
        opp=0;
        break;
    case 3:
        a1.add_cab();
        opp=0;
        break;
    case 4:
        a1.delete_cab();
        opp=0;
        break;
    case 5:
        a1.showDriverRatings();
        opp=0;
        break;
    case 6:
        int f,rate;
        int cbn;
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        cout<<"Enter the cab id whose driver's rating you want to update: ";
        cin>>cbn;
        cin.clear();
        cout<<"Enter how much you want to rate him[1/2/3/4/5]: ";
        cin>>rate;
        f=search_cab(cbn);
        a1.update_rating(rate,f);
        cout<<endl<<"UPDATED."<<endl;
        delay(3);
        opp=0;
        break;
    case 7:
        for(int i=0;i<200;i++)
            cout<<"*";
        delay(3);
        opp=1;
        break;
    default:
        cout<<"Wrong option selected. Please select again."<<endl;
        delay(4);
        opp=0;
        break;
      }
    }while(opp==0);
  }
}

void user_menu(int f)
{
    int ch1;
    if(f==1)
    {
        int pop=0;
        do
        {
          upper();
          for(int j=0;j<9;j++)
            cout<<"\t";
          cout<<"*********USER LOGIN*********"<<endl<<endl;
          cout<<"1-> CHANGE PASSWORD"<<endl;
          cout<<"2-> BOOK A CAB FOR NOW"<<endl;
          cout<<"3-> BOOK A CAB FOR LATER"<<endl;
          cout<<"4-> TRIP HISTORY"<<endl;
          cout<<"5-> PREVIOUS TRIP DETAILS"<<endl;
          cout<<"6-> EXIT"<<endl;
          cout<<"Enter your choice: ";
          cin>>ch1;
          switch(ch1)
          {
    case 1:
        pop=1;
        u1.change_pass();
        u1.login();
        break;
    case 2:
        pop=1;
        u1.book_cab();
        break;
    case 3:
        pop=1;
        u1.book_later();
        break;
    case 4:
        pop=1;
        u1.trip_history();
        break;
    case 5:
        pop=1;
        u1.trip_details();
        break;
    case 6:
        pop=0;
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        delay(3);
        break;
    default:
        pop=1;
        cout<<"WRONG CHOICE ENTERED. PLEASE SELECT AGAIN."<<endl;
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        delay(3);
        break;
        }
     }while(pop!=0);
   }
}
void End()
{
       system("cls");
       for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        for(int i=0;i<15;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        cout<<"*";
        for(int j=0;j<10;j++)
            cout<<"\t";
        cout<<"CAB REPLICATION MODEL SYSTEM";
        for(int i=0;i<12;i++)
            cout<<"\t";
        cout<<"*"<<endl;
        for(int i=0;i<6;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        cout<<"*";
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"THANK YOU FOR USING THE SYSTEM OF AKSS CABS.HAVE A NICE DAY.";
        for(int i=0;i<9;i++)
            cout<<"\t";
        cout<<"*"<<endl;
        for(int i=0;i<10;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        
}
int main()
{
    frontpage();
    upper();
    int f;
    areas[0]="Sector 62";
    areas[1]="Sector 128";
    areas[2]="Botanical Garden";
    areas[3]="Sector 18";
    areas[4]="Kaushambi";
    areas[5]="Anand Vihar";
    areas[6]="Rajiv Chowk";
    areas[7]="Kashmere Gate";
    areas[8]="Nehru Place";
    areas[9]="Pari Chowk";
    g.addEdge(0, 1, 19);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.addEdge(9, 5, 30);
    g.addEdge(9, 3, 25);
    int choice,i;
    fstream fil,fil2;
    fil.open("cabdatabase.txt",ios::in);
    i=0;
    cab c;
    char ch;
    while(!fil.eof())
    {
        fil.read((char*) &c,sizeof(c));
        a1.ob[i]=c;
        insertbyhash(c);
        i++;
    }
    noofcabs=i;
    fil.close();
    int opt=1;
    do
    {
    upper();
    for(int j=0;j<9;j++)
        cout<<"\t";
    cout<<"*********MAIN MENU**********"<<endl<<endl;
    cout<<"1-> USER LOGIN"<<endl;
    cout<<"2-> USER SIGNUP"<<endl;
    cout<<"3-> ADMIN LOGIN"<<endl;
    cout<<"4-> EXIT"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            f=u1.login();
            opt=1;
            break;
        }
    case 2:
        {
            user u2;
            u2.signup();
            opt=1;
            break;
        }
    case 3:
        {
            f=a1.admin_login();
            admin_menu(choice,f);
            opt=1;
            break;
        }
    case 4:
        opt=0;
        break;
    default:
        opt=1;
        cout<<"WRONG CHOICE ENTERED. PLEASE ENTER AGAIN."<<endl;
        delay(4);
        break;
    }
    }while(opt!=0);
    cout<<endl;
    for(int i=0;i<200;i++)
        cout<<"*";
    cout<<endl;
    system("pause");
    fil.open("cabdata1.txt",ios::out);
    for(int i=0;i<noofcabs;i++)
    {
        cab c=a1.ob[i];
        fil.write((char*) &c,sizeof(c));
    }
    fil.close();
    fil.open("cabdata1.txt",ios::in);
    fil2.open("cabdatabase.txt",ios::out);
    while (!fil.eof())
    {
         fil.get(ch);
         fil2<<ch;
    }
    fil2.close();
    fil.close();
    areas.clear();
    End();
    return 0;
}
