#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define SIZE 22

#define INF INT_MAX

using namespace std;

int strcmp(string,string);

class City
{
public:
    int city_num,pre;
    string city_name;
    City():city_num(0),pre(-1) {};
    City(string str,int x):city_name(str),city_num(x),pre(-1) {};
    City(int x):city_num(x),pre(-1) {};
    City(City &temp):city_num(temp.city_num),pre(temp.pre) {};
};


class Graph
{
    int adj_mat[SIZE][SIZE],distance[SIZE],visited[SIZE];
    string start,finish;
    vector<City *> cityarr;
    void city_creator(void);
    int display_path(string str);
    int path_calculator(string str);
public:
    Graph()
    {
        for(int i=0; i<SIZE; i++)
            for(int j=0; j<SIZE; j++)
            {
                if(i==j)
                    adj_mat[i][j] = 0;
                else
                    adj_mat[i][j] = INF;
            }
        for(int i=0; i<SIZE; i++)
        {
            visited[i]=0;
            distance[i]=INF;
        }
        city_creator();
    }
    void runMaps(void);
};




void Graph::runMaps(void)
{
    cout<<endl<<"There are following cities available:"<<endl;

    for(int i=0; i<SIZE; i++)
    {
        if(i%4==0)
            cout<<endl;

        cout.unsetf(ios::right);
        cout<<setw(20)<<setiosflags(ios::left)<<cityarr[i]->city_name;
    }

    cout<<endl<<endl<<"Enter your source point ";
    string st;
    cin>>st;

    int result = path_calculator(st);

    if(!result)
    {
        cout<<endl<<"Programme Terminated due to invalid initial city";
        return ;
    }

    cout<<"Enter your destination point ";
    string destination;
    cin>>destination;

    result = display_path(destination);

    if(!result)
    {
        cout<<endl<<"Programme Terminated due to invalid destination city";
        return ;
    }

}

void Graph::city_creator(void)
{
    //Bandera
    adj_mat[0][1]=adj_mat[1][0]=653;
    adj_mat[0][4]=adj_mat[4][0]=867;
    adj_mat[0][5]=adj_mat[5][0]=447;
    adj_mat[0][9]=adj_mat[9][0]=312;
    adj_mat[0][18]=adj_mat[18][0]=772;
    City * ptr = new City("Bandera",0);
    cityarr.push_back(ptr);


    //Bangalore
    adj_mat[1][5]=adj_mat[5][1]=330;
    adj_mat[1][9]=adj_mat[9][1]=564;
    adj_mat[1][15]=adj_mat[15][1]=1028;
    adj_mat[1][16]=adj_mat[16][1]=615;
    adj_mat[1][21]=adj_mat[21][1]=720;
    ptr = new City("Bangalore",1);
    cityarr.push_back(ptr);


    //Bhopal
    adj_mat[2][8]=adj_mat[8][2]=606;
    adj_mat[2][10]=adj_mat[10][2]=585;
    adj_mat[2][14]=adj_mat[14][2]=623;
    adj_mat[2][15]=adj_mat[15][3]=782;
    adj_mat[2][18]=adj_mat[18][2]=637;
    ptr = new City("Bhopal",2);
    cityarr.push_back(ptr);


    //Cuttack
    adj_mat[3][12]=adj_mat[12][3]=444;
    adj_mat[3][18]=adj_mat[18][3]=576;
    adj_mat[3][19]=adj_mat[19][3]=469;
    ptr = new City("Cuttack",3);
    cityarr.push_back(ptr);


    //Patiala
    adj_mat[4][6]=adj_mat[6][4]=169;
    adj_mat[4][7]=adj_mat[7][4]=251;
    adj_mat[4][11]=adj_mat[11][4]=375;
    adj_mat[4][20]=adj_mat[20][4]=110;
    ptr = new City("Patiala",4);
    cityarr.push_back(ptr);


    //Tirupati
    adj_mat[5][21]=adj_mat[21][5]=839;
    ptr = new City("Tirupati",5);
    cityarr.push_back(ptr);


    //Haridwar
    adj_mat[6][7]=adj_mat[7][6]=239;
    adj_mat[6][14]=adj_mat[14][6]=557;
    adj_mat[6][20]=adj_mat[20][6]=261;
    ptr = new City("Haridwar",6);
    cityarr.push_back(ptr);


    //NewDelhi
    adj_mat[7][10]=adj_mat[10][7]=261;
    adj_mat[7][14]=adj_mat[14][7]=518;
    adj_mat[7][20]=adj_mat[20][7]=347;
    ptr = new City("NewDelhi",7);
    cityarr.push_back(ptr);


    //Ahmedabad
    adj_mat[8][10]=adj_mat[10][8]=636;
    adj_mat[8][15]=adj_mat[15][8]=564;
    ptr = new City("Ahmedabad",8);
    cityarr.push_back(ptr);


    //Hyderabad
    adj_mat[9][15]=adj_mat[15][9]=708;
    adj_mat[9][18]=adj_mat[18][9]=784;
    ptr = new City("Hyderabad",9);
    cityarr.push_back(ptr);


    //Udaypur
    adj_mat[10][14]=adj_mat[14][10]=599;
    ptr = new City("Udaypur",10);
    cityarr.push_back(ptr);


    //Kashmir
    adj_mat[11][13]=adj_mat[13][11]=766;
    adj_mat[11][20]=adj_mat[20][11]=450;
    ptr = new City("Kashmir",11);
    cityarr.push_back(ptr);


    //Culcutta
    adj_mat[12][17]=adj_mat[17][12]=576;
    adj_mat[12][19]=adj_mat[19][12]=399;
    ptr = new City("Culcutta",12);
    cityarr.push_back(ptr);


    //Ladakh
    adj_mat[13][20]=adj_mat[20][13]=714;
    ptr = new City("Ladakh",13);
    cityarr.push_back(ptr);


    //Kanpur
    adj_mat[14][17]=adj_mat[17][14]=550;
    ptr = new City("Kanpur",14);
    cityarr.push_back(ptr);


    //Bombay
    adj_mat[15][16]=adj_mat[16][15]=567;
    adj_mat[15][18]=adj_mat[18][15]=1137;
    ptr = new City("Bombay",15);
    cityarr.push_back(ptr);


    //Goa
    ptr = new City("Goa",16);
    cityarr.push_back(ptr);


    //Muzaffarpur
    adj_mat[17][19]=adj_mat[19][17]=320;
    ptr = new City("Muzaffarpur",17);
    cityarr.push_back(ptr);


    //Bhilai
    adj_mat[19][18]=adj_mat[18][19]=673;
    ptr = new City("Bhilai",18);
    cityarr.push_back(ptr);

    //Jamshedpur
    ptr = new City("Jamshedpur",19);
    cityarr.push_back(ptr);


    //Manali
    ptr = new City("Manali",20);
    cityarr.push_back(ptr);


    //Trivandrum
    ptr = new City("Trivandrum",21);
    cityarr.push_back(ptr);
}


int Graph::display_path(string str)
{
    finish = str;
    stack<int> st;
    string temp = finish;
    int pos(-1);
    for(int i=0; i<SIZE; i++)
        if(!strcmp(str,cityarr[i]->city_name))
        {
            pos = cityarr[i]->city_num;
            break;
        }
    if(pos==-1)
    {
        cout<<endl<<"No such City exists";
        return 0;
    }
    cout<<endl<<"This trip will be of approximately "<<distance[pos]<<" kms";
    cout<<endl<<"Your journey will take "<<distance[pos]<<" minutes at 60kmph avg speed";
    cout<<endl<<"The route will be: ";
    while(pos!=-1)
    {
        st.push(pos);
        pos = cityarr[pos]->pre;
    }
    while(!st.empty())
    {
        cout<<endl<<cityarr[st.top()]->city_name<<" "<<distance[st.top()]<<" kms";
        st.pop();
    }
    return 1;
}


int Graph::path_calculator(string str)
{
    start = str;
    int pos(-1);

    for(int i=0; i<SIZE; i++)
        if(!strcmp(str,cityarr[i]->city_name))
        {
            pos = cityarr[i]->city_num;
            break;
        }

    if(pos==-1)
    {
        cout<<endl<<"No such City exists";
        return 0;
    }

    queue<int> qu;
    qu.push(pos);
    distance[pos] = 0;
    cityarr[pos]->pre = -1;

    while(!qu.empty())
    {
        int del = qu.front();
        qu.pop();
        visited[del]=1;

        for(int i=0;i<SIZE;i++)
            if(i!=del&&!visited[i])
                if((adj_mat[del][i]!=INF)&&(distance[del]+adj_mat[del][i]<distance[i]))
                {
                    distance[i] = distance[del]+adj_mat[del][i];
                    cityarr[i]->pre = del;
                    qu.push(i);
                }
    }

    return 1;
}

int strcmp(string str1,string str2)
{
    int res=0;
    if(str1.size()!=str2.size())
        res=1;
    else
        for(int i=0; i<str1.size(); i++)
            if(str1[i]!=str2[i]&&abs(str1[i]-str2[i])!=abs('A'-'a'))
                res=1;
    return res;
}

int main()
{
    cout<<"\t\t\t\t\t\t Graph based Navition System"<<endl<<endl;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        Graph G;
        G.runMaps();
        cout<<endl<<endl<<"Do you wish to continue??.....Press y/n ";
        do
        cin>>ch;
        while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
    }
    cout<<endl<<endl<<"\t\t\t\t\t\tThank You"<<endl;
}