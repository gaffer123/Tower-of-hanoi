#include <iostream>
#include <vector>
using namespace std;


int main(){
    int r,rings, candidate,to, from, move=0;

    cout<<"Please enter a number of rings to move: ";
    cin>>rings;
    cout<<endl;
    cout<<"Please enter the number of towers: ";
    cin>>r;
    cout<<endl;

    vector<int> tower[r];

    for(int i=rings+1;i>=1;i--)
        tower[0].push_back(i);  //a
    tower[1].push_back(rings+1);//b
    tower[2].push_back(rings+1);//c
    tower[3].push_back(rings+1);//d

    from=0;
    if((rings%2)==1/*is odd*/) to=1;
    else to=2;
    candidate=1;
    while( tower[1].size()<rings+1){

        tower[to].push_back(tower[from].back());
        tower[from].pop_back();
        cout<<"#"<<++move<<": move ring "<<candidate<<" from tower "<< (from + 1) <<" to tower "<<(to + 1)<<endl;


        if(rings%2==1){
            if(tower[(to+1)%3].back() < tower[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;

            if(tower[(from)].back() < tower[(from+1)%3].back())
                to=(from+1)%3;
            else
                to=(from+2)%3;

            candidate=(tower[from].back());
        } else {
            if(tower[(to+1)%3].back() < tower[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;

            if(tower[(from)].back() < tower[(from+2)%3].back())
                to=(from+2)%3;
            else
                to=(from+1)%3;
              candidate=(tower[from].back());
        }
    }
    return 0;
}
