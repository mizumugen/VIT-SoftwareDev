#include<bits/stdc++.h>
using namespace std;

class game{
    vector<vector<string>> grid;
    vector<vector<vector<int>>> pos;
    unordered_map<string, vector<string>> legal_moves;
    map<vector<string>, vector<int>> move_matrix;
    public:
    int p1, p2;
    game()
    {
        grid.resize(5, vector<string>(5, "-"));
        pos.resize(2, vector<vector<int>>(5, vector<int>(2)));
        p1=5;
        p2=5;
        legal_moves["P1"] = {"F", "L", "R", "B"};
        legal_moves["P2"] = {"F", "L", "R", "B"};
        legal_moves["H1"] = {"F", "L", "R", "B"};
        legal_moves["H2"] = {"FL", "FR", "BR", "BL"};
        legal_moves["H3"] = {"FL", "FR", "BL", "BR", "RF", "RB", "LF", "LB"};
        move_matrix[{"P1","F"}] = {1, 0};
        move_matrix[{"P1","B"}] = {-1, 0};
        move_matrix[{"P1","R"}] = {0, 1};
        move_matrix[{"P1","L"}] = {0, -1};

        move_matrix[{"P2","F"}] = {1, 0};
        move_matrix[{"P2","B"}] = {-1, 0};
        move_matrix[{"P2","R"}] = {0, 1};
        move_matrix[{"P2","L"}] = {0, -1};

        move_matrix[{"H1","F"}] = {2, 0};
        move_matrix[{"H1","B"}] = {-2, 0};
        move_matrix[{"H1","R"}] = {0, 2};
        move_matrix[{"H1","L"}] = {0, -2};
        
        move_matrix[{"H2","FL"}] = {2, -2};
        move_matrix[{"H2","FR"}] = {2, 2};
        move_matrix[{"H2","BL"}] = {-2, -2};
        move_matrix[{"H2","BR"}] = {-2, 2};

        move_matrix[{"H3","FL"}] = {2, -1};
        move_matrix[{"H3","BL"}] = {-2, -1};
        move_matrix[{"H3","RF"}] = {2, 1};
        move_matrix[{"H3","LF"}] = {-2, 1};
        move_matrix[{"H3","FR"}] = {2, 1};
        move_matrix[{"H3","BR"}] = {-2, 1};
        move_matrix[{"H3","RB"}] = {-1, 2};
        move_matrix[{"H3","LB"}] = {-1, -2};
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
    
    void chance(int player)
    {
        string move;
        cout<<"Player "<<player<<" enter your move: ";
        cin>>move;
        string character = move.substr(0,2), position = move.substr(3,2);
        if(legal_moves.find(character)==legal_moves.end())
        {
            cout<<"Invalid Character Entered. Retry!"<<endl;
            chance(player);
            return ;            
        }
        else
        {
            int f=0;
            for(int i=0; i<legal_moves[character].size(); i++)
            {   
                if(position==legal_moves[character][i])
                {
                    
                    return;
                }
            }
            if(f==0)
            {
                cout<<"Invalid Move for the selected Charater. Retry!"<<endl;
                chance(player);
                return ; 
            }
        }

        bool nextMoveOnBoard(int player, int char_no, string position, string character)
        {
            if((pos[player-1][char_no][0]+move_matrix[{character, position}][0]>=0)
                &&(pos[player-1][char_no][1]+move_matrix[{character, position}][1]>=0)
                &&(pos[player-1][char_no][0]+move_matrix[{character, position}][0]<5)
                &&(pos[player-1][char_no][1]+move_matrix[{character, position}][0]<5))
                return true;
            else
                return false;
        }

        void makemove(string character, string position, int player)
        {
            int char_no;
            if(character=="P1")
                char_no = 0;
            else if(character=="P2")
                char_no = 1;
            else if(character=="H1")
                char_no = 2;
            else if(character=="H2")
                char_no = 3;
            else if(character=="H3")
                char_no = 4;
            if(!nextMoveOnBoard)
            {
                cout<<"Move Lands you out of the board. Thus, Invalid Move, Retry!" ;
                chance(player);
                return;  
            }

            
        }
        
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