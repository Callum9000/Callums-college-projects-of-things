

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;

int m;
int n;
int l = 0;
int nl;
float avg;
int b;
int c;
float stn = 0;
int line = 0;
vector <string> edgy;

class nz {	    // one instance for every non-zero entry in matrix
public:
    nz() { ind = 0; val = 0.0; }
    nz(int i, double v) {	// constructor when given the two items of data
        ind = i;
        val = v;
    }
    int getInd() const { return ind; } // access to ind class member
    double getVal() const { return val; } // access to val class member
    friend istringstream& operator>>(istringstream& is, nz& base);
    friend ostream& operator<<(ostream& os, const nz& base);

private:
    int ind;
    double val;
};
istringstream& operator>>(istringstream& is, nz& base)
{
    is >> base.ind;
    is >> base.val;
    return is;
}
ostream& operator<<(ostream& os, const nz& base)
{
    os << base.ind << " " << base.val << " ";
    return os;
}

typedef list<nz> sparseRow;
typedef vector<sparseRow> sparseMat;
vector <int> Q;
sparseMat rows;
void readMat(sparseMat&, string);
void Degree(const sparseMat);
void dfs(int , int, int  );
void print_dis_K(const sparseMat graph, int node, int c, int n, int m);


int main(int argc, char* argv[])
{
    string file;
    int a;
    cin >> file;
    cin >> a;
    cin >> b;
    cin >> c;
    readMat(rows, file);

    switch (a) {
    case 1: {  
        cout << "n= " << n << "; m= " << m << endl;
        break;
    }
    case 2: {
        Degree(rows);
        cout << "v= " << l << "; |N(v)|= " << nl << "." << endl;
        break;
    }
    case 3: { 
        Degree(rows);
        printf("avg |N(v)|= %0.6f. \n", avg);
        break;
    }
    case 4: {
        cout << "N(" << b << ")= ";
        for (int i = 0; i < edgy.size(); i++)
        {
            cout << edgy[i] << " ";
        }
        cout << endl;
        break;
    }
    case 5: {
       
        cout << "N(" << b << "," << c << ")= ";
        
        dfs(c, b - 1, 0 );
        sort(Q.begin(), Q.end());
        Q.erase(unique(Q.begin(), Q.end()), Q.end());
        for (int i = 0; i < Q.size(); i++)
        {
            cout << Q[i] + 1 << " ";
        }
        cout << endl;
        break;
    }
 


    }
}


void readMat(sparseMat& rows, string file)
{

    string line;

    int x = 0;
    std::ifstream fs;
    cin >> b;
    fs.open(file + ".osm.graph");

    while (std::getline(fs, line) && line[0] == '%');
    istringstream lstream(line);
    lstream >> n;
    lstream >> m;



    while (getline(fs, line))
    {
        if (line[0] == '%') continue;

        x++;
        istringstream lstream(line);

        sparseRow row;
        nz* next;
        string temp;
        while (lstream >> temp) {

            int temp2;

            istringstream(temp) >> temp2;

            if (x == b) {
                edgy.push_back(temp);
            }
            next = new nz(rows.size() + 1, temp2);
            row.push_back(*next);


        }

        rows.push_back(row);

    }

    fs.close();

}


void Degree(const sparseMat lne) {
    int n = 0;
    sparseMat::const_iterator rit;
    for (rit = lne.begin(); rit != lne.end(); rit++)
    {

        line++;
        sparseRow row = *rit;
        sparseRow::const_iterator nzit;

        for (nzit = row.begin(); nzit != row.end(); nzit++)
        {
            n++;
        }

        if (nl < n) {
            l = line;
            nl = n;
        }

        stn += n;
        n = 0;
    }
    avg = stn / line;
}


void dfs(int c, int node, int parent) {
    if (c < 0) {
        return;
    }

    if (c == 0) {
        Q.push_back(node);
    }

    nz j;
    sparseRow::const_iterator itr;

    for (itr = rows.at(node).begin(); itr != rows.at(node).end(); itr++){
        j = *itr;
         dfs(c - 1, j.getVal() - 1, node);
    }

}
