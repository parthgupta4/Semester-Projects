#include <bits/stdc++.h>
using namespace std;

void planDetails();
void graph();

void menu()
{
	int c;

	do
	{
		menu:
		cout << endl << endl;
		cout << "\n\t\t\t\t ----------| LAN INFRASTRUCTURE DESIGN |----------" << endl;
		cout << "\n\t\t\t\t *************************************************" << endl << endl;
		cout << "\n\t\t\t\t Please Select an Option: "<<endl;
		cout << "\n\t\t\t\t 1. Go to the Program";
		cout << "\n\t\t\t\t 2. Display Network Plan Details";
		cout << "\n\t\t\t\t 3. EXIT";
		cout << endl << "\n\t\t\t\t Enter your Option: "; cin >> c;
		switch (c)
		{
	
		case 1:
			graph();
			break;

		case 2:
            planDetails();
			break;

		case 3:
			exit(system("pause"));
			break;

		default:
			cout << "\n\t\t\t\t\t Wrong Option. Please enter again!!"<<endl<<endl;
            goto menu;
		}
	} while (1);
}

void basicPlan()
{
	cout << "\n\t\t\t\t\t----------| BASIC PLAN |----------";
	cout << "\n";
	cout << "\n";
	cout << "\n\t\t\t\t\t COST: Rs 500/- Per Month";
	cout << "\n";
	cout << "\n\t\t\t\t\t SPEED: Upto 40 Mbps";
	cout << "\n";
	cout << "\n\t\t\t\t\t DATA LIMIT: 100 Gigabytes";
	cout << "\n";
	cout << "\n\t\t\t\t\t CALLS: Unlimited Local/STD Calls";
	cout << "\n";
	cout << "\n";
	planDetails();
}
void classicPlan()
{
	cout << "\n\t\t\t\t\t----------| CLASSIC PLAN |----------";
	cout << "\n";
	cout << "\n";
	cout << "\n\t\t\t\t\t COST: Rs 600/- Per Month";
	cout << "\n";
	cout << "\n\t\t\t\t\t SPEED: Upto 80 Mbps";
	cout << "\n";
	cout << "\n\t\t\t\t\t DATA LIMIT: 200 Gigabytes";
	cout << "\n";
	cout << "\n\t\t\t\t\t CALLS: Unlimited Local/STD Calls (With Free Wi-Fi Calling)";
	cout << "\n";
	cout << "\n";
	planDetails();
}

void silverPlan()
{
	cout << "\n\t\t\t\t\t----------| SILVER PLAN |----------";
	cout << "\n";
	cout << "\n";
	cout << "\n\t\t\t\t\t COST: Rs 800/- Per Month";
	cout << "\n";
	cout << "\n\t\t\t\t\t SPEED: Upto 100 Mbps";
	cout << "\n";
	cout << "\n\t\t\t\t\t DATA LIMIT: 200 Gigabytes";
	cout << "\n";
	cout << "\n\t\t\t\t\t CALLS: Unlimited Local/STD Calls (With Free Wi-Fi Calling)";
	cout << "\n";
	cout << "\n";
	planDetails();
}

void goldPlan()
{
	cout << "\n\t\t\t\t\t----------| GOLD PLAN |----------";
	cout << "\n";
	cout << "\n";
	cout << "\n\t\t\t\t\t COST: Rs 1000/- Per Month";
	cout << "\n";
	cout << "\n\t\t\t\t\t SPEED: Upto 200 Mbps";
	cout << "\n";
	cout << "\n\t\t\t\t\t DATA LIMIT: Unlimited";
	cout << "\n";
	cout << "\n\t\t\t\t\t CALLS: Unlimited Local/STD Calls (With Free Wi-Fi Calling)";
	cout << "\n";
	cout << "\n";
	planDetails();
}

void planDetails()
{
	int c;

    plan:
	do
	{
		cout << "\n\t\t\t\t\t----------| SELECT YOUR PLAN |----------"<< endl;
		cout << "\n\t\t\t\t\t 1. Basic Plan";
		cout << "\n\t\t\t\t\t 2. Classic Plan";
		cout << "\n\t\t\t\t\t 3. Silver Plan";
		cout << "\n\t\t\t\t\t 4. Gold Plan";
		cout << "\n\t\t\t\t\t 5. EXIT" << endl;
		cout << "\n\t\t\t\t\t Enter your Option: "; cin >> c;

		switch (c)
		{
		case 1:
			basicPlan();
			break;

		case 2:
			classicPlan();
			break;

		case 3:
			silverPlan();
			break;

		case 4:
			goldPlan();
			break;

		case 5:
			exit(system("pause"));
			break;

		default:
			cout << "\n\t\t\t\t\t Wrong Option. Please enter again!!"<<endl<<endl;
            goto plan;
		}
	} while (1);
}


void graph()
{
    int v, e;
    int sum = 0;
    cout<<"\n\t\t\t\t----------------------------------------------------"<<endl;
    cout << "\n\t\t\t\tEnter the no. of buildings: ";
    cin >> v;
    cout << "\t\t\t\tEnter the no. of Edges of the buildings: ";
    cin >> e;
    int path[v];

    for(int i=0;i<v;i++) path[i]=-1;

    vector<pair<int, int> > adj[v]; //2nd node(destination node), weight and v represents 1st node(source node)

    for (int i = 0; i < e; i++)
    {
        int v1, v2, w; //which node is connected to which node and by which weight

        cout << "\t\t\t\tEnter 2 Building Numbers: ";
        cin >> v1 >> v2;
        cout << "\t\t\t\tEnter the distance b/w the 2 Buildings-" << v1 << " & " << v2 << ": ";
        cin >> w;
        cout << endl;

        pair<int, int> x(v2, w);
        adj[v1].push_back(x);
    }

    vector<int> distance(v, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; //MIN HEAP, saves the distance of vertex from source.

    int source;

    cout << "\t\t\t\tEnter the source Building No.: ";
    cin >> source;

    pair<int, int> y(0, source);
    pq.push(y);

    distance[source] = 0;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int currVertex = pq.top().second;

        pq.pop();

        vector<pair<int, int> >::iterator itr;

        for (itr = adj[currVertex].begin(); itr != adj[currVertex].end(); itr++)
        {
            int nextVertex = itr->first;
            int weight = itr->second;

            int possibleDistance = dist + weight;

            if (possibleDistance < distance[nextVertex])
            {
                distance[nextVertex] = possibleDistance;
                pair<int, int> z(possibleDistance, nextVertex);
                pq.push(z);
            }
        }
    }

    cout << endl;
    for (int i = 0; i < v; i++)
	{
        int j;
		if (i != source)
		{
			cout << "\n\t\t\t\t-------------------------------------------"<<endl;
            cout << "\n\t\t\t\t DISTANCE OF BUILDING FROM No." << source << " TO No. " << i << " IS: " << distance[i];
			
			if (distance[i] < 10)
			{
				long int price;
				long int price2;
				price = 1000 * distance[i];
				cout << "\n\t\t\t\t CABLE: Twisted Pair Cable";
				cout << "\n\t\t\t\t PRICE: " << price << " Rs";
				cout << "\n\t\t\t\t NETWORK: Local Area Network (LAN)";
				cout << "\n\t\t\t\t PRICE OF NETWORK: 2000 Rs";
                price2 = price + 2000;
				cout << "\n\t\t\t\t TOTAL PRICE: " << price2<<" Rs";
			}
			else if (distance[i] >= 10 && distance[i] <= 50)
			{
				long int price1;
				long int price3;
				price1 = 2000 * distance[i];
				cout << "\n\t\t\t\t CABLE: Coaxial Cable";
				cout << "\n\t\t\t\t PRICE: " << price1 <<" Rs";
				cout << "\n\t\t\t\t NETWORK: Metropolitan Area Network (MAN)";
				cout << "\n\t\t\t\t PRICE OF NETWORK: 3000 Rs";
				cout << "\n\t\t\t\t Repeater Cables are required";
				cout << "\n\t\t\t\t ADDITIONAL PRICE: 1000 Rs";
                price3 = price1 + 3000 + 1000;
				cout << "\n\t\t\t\t TOTAL PRICE: " << price3<<" Rs";
			}
			else if (distance[i] > 50)
			{
				long int price4;
				long int price5;
				price4 = 3000 * distance[i];
				cout << "\n\t\t\t\t CABLE: Optical Fiber";
				cout << "\n\t\t\t\t PRICE: " << price4 <<" Rs";
				cout << "\n\t\t\t\t NETWORK: Wide Area Network (WAN)";
				cout << "\n\t\t\t\t PRICE OF NETWORK: 4000 Rs";
				cout << "\n\t\t\t\t Repeater Cables are required";
				cout << "\n\t\t\t\t ADDITIONAL PRICE: 1000 Rs";
                price5 = price4 + 4000 + 1000;
				cout << "\n\t\t\t\t TOTAL PRICE: " << price5<<" Rs";
			}
		}
		cout << "\n";

		sum = sum + distance[i];
	}
    cout<<"\n\t\t\t\t----------------------------------------------------"<<endl;
    cout << "\n\t\t\t\t SHORTEST PATH FOR ALL BULIDINGS IS: " << sum;
    if (sum <= 40)
    {
        cout << "\n\t\t\t\t Using Bus Connection";
        cout << "\n\t\t\t\t Provided: Basic Plan";
    }
    else if (sum > 40 && sum <= 70)
    {
        cout << "\n\t\t\t\t Using Ring Connection";
        cout << "\n\t\t\t\t Provided: Classic Plan";
    }
    else if (sum > 70 && sum <= 120)
    {
        cout << "\n\t\t\t\t Using Mesh Connection";
        cout << "\n\t\t\t\t Provided: Silver Plan";
    }
    else
    {
        cout << "\n\t\t\t\t Using Star Connection";
        cout << "\n\t\t\t\t Provided: Gold Plan";
    }
    cout<<"\n\t\t\t\t----------------------------------------------------"<<endl;
    cout << endl;
}

int main()
{
    menu();
    return 0;
}