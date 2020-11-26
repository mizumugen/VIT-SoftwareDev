#include<bits/stdc++.h>
using namespace std;

class game{
    vector<vector<string>> grid;
    vector<vector<vector<int>>> pos;
    public:
    int p1, p2;
    game()
    {
        grid.resize(5, vector<string>(5, "-"));
        pos.resize(2, vector<vector<int>>(5, vector<int>(2)));
        p1=5;
        p2=5;
        display();
    }   
    void display()
    {
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
                cout<<grid[i][j]<<"\t";
            cout<<endl;
        }
    }
    void markgrid(string character, vector<int> new_pos, vector<int> old_pos)
    {
        grid[new_pos[0]][new_pos[1]] = character;
        grid[old_pos[0]][old_pos[1]] = "-";
        return;
    }

    void initialize(int player)
    {
        string s;
        cout<<"Enter the position of Pawn 1: ";
        cin>>s;
        pos[player-1][0][1] = s[1]-'1';
        pos[player-1][0][0] = (player==1?0:4);
        player == 1 ? markgrid("A-P1", pos[player-1][0], {2,2}): markgrid("B-P1", pos[player-1][0], {2,2});
        cout<<"Enter the position of Pawn 2: ";
        cin>>s;
        pos[player-1][1][1] = s[1]-'1';
        pos[player-1][1][0] = (player==1?0:4);
        player == 1 ? markgrid("A-P2", pos[player-1][1], {2,2}): markgrid("B-P2", pos[player-1][1], {2,2});
        cout<<"Enter the position of Hero 1: ";
        cin>>s;
        pos[player-1][2][1] = s[1]-'1';
        pos[player-1][2][0] = (player==1?0:4);
        player == 1 ? markgrid("A-H1", pos[player-1][2], {2,2}): markgrid("B-H1", pos[player-1][2], {2,2});
        cout<<"Enter the position of Hero 2: ";
        cin>>s;
        pos[player-1][3][1] = s[1]-'1';
        pos[player-1][3][0] = (player==1?0:4);
        player == 1 ? markgrid("A-H2", pos[player-1][3], {2,2}): markgrid("B-H2", pos[player-1][3], {2,2});
        cout<<"Enter the position of Hero 3: ";
        cin>>s;
        pos[player-1][4][1] = s[1]-'1';
        pos[player-1][4][0] = (player==1?0:4);
        player == 1 ? markgrid("A-H3", pos[player-1][4], {2,2}): markgrid("B-H3", pos[player-1][4], {2,2});
        display();
    }
    




};

int main()
{
    game gameSession;
    cout<<"Game grid is ready"<<endl;
    cout<<"Player 1 mark your positions "<<endl;
    gameSession.initialize(1);
    cout<<"Player 2 mark your positions "<<endl;
    gameSession.initialize(2);
    while(gameSession.p1>0&&gameSession.p2>0)
    {

    }
}