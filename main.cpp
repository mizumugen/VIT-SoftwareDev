#include<bits/stdc++.h>
using namespace std;

class game{
    vector<vector<string>> grid;
    vector<vector<vector<int>>> pos;
    unordered_map<string, vector<string>> legal_moves;
    map<vector<string>, vector<int>> move_matrix;
    vector<vector<bool>> exist;
    public:
    int p1, p2;
    game()
    {
        grid.resize(5, vector<string>(5, "-"));
        pos.resize(2, vector<vector<int>>(5, vector<int>(2)));
        exist.resize(2,vector<bool>(5, false));
        p1=5;
        p2=5;
        legal_moves["P1"] = {"F", "L", "R", "B"};
        legal_moves["P2"] = {"F", "L", "R", "B"};
        legal_moves["H1"] = {"F", "L", "R", "B"};
        legal_moves["H2"] = {"FL", "FR", "BR", "BL"};
        legal_moves["H3"] = {"FL", "FR", "BL", "BR", "RF", "RB", "LF", "LB"};
        
        move_matrix[{"P1","F"}] = {0, 1};
        move_matrix[{"P1","B"}] = {-0, -1};
        move_matrix[{"P1","R"}] = {1, 0};
        move_matrix[{"P1","L"}] = {-1, 0};

        move_matrix[{"P2","F"}] = {0, 1};
        move_matrix[{"P2","B"}] = {-0, -1};
        move_matrix[{"P2","R"}] = {1, 0};
        move_matrix[{"P2","L"}] = {-1, 0};

        move_matrix[{"H1","F"}] = {0, 2};
        move_matrix[{"H1","B"}] = {0, -2};
        move_matrix[{"H1","R"}] = {2, 0};
        move_matrix[{"H1","L"}] = {-2, 0};
        
        move_matrix[{"H2","FL"}] = {-2, 2};
        move_matrix[{"H2","FR"}] = {2, 2};
        move_matrix[{"H2","BL"}] = {-2, -2};
        move_matrix[{"H2","BR"}] = {2, -2};

        move_matrix[{"H3","FL"}] = {-1, 2};
        move_matrix[{"H3","BL"}] = {-1, -2};
        move_matrix[{"H3","RF"}] = {2, 1};
        move_matrix[{"H3","LF"}] = {-2, 1};
        move_matrix[{"H3","FR"}] = {1, 2};
        move_matrix[{"H3","BR"}] = {1, -2};
        move_matrix[{"H3","RB"}] = {2, -1};
        move_matrix[{"H3","LB"}] = {-2, -1};
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
    void markgrid(string character, vector<int> new_pos, vector<int> old_pos, int player, int char_no)
    {
        if(grid[new_pos[0]][new_pos[1]]!="-")
        {
            string old = grid[new_pos[0]][new_pos[1]].substr(2,2);
            int char_no_old = get_char_no(old);
            exist[player==1?1:0][char_no_old] = false;
            if(character[0]=='A')
                p2--;
            else 
                p1--;
        }
        exist[player-1][char_no] = true;
        grid[new_pos[0]][new_pos[1]] = character;
        grid[old_pos[0]][old_pos[1]] = "-";
        pos[character[0]=='A'?0:1][char_no][0] = new_pos[0];
        pos[character[0]=='A'?0:1][char_no][1] = new_pos[1];
        return;
    }

    void initialize(int player)
    {
        string s;
        cout<<"Enter the position of Pawn 1: ";
        cin>>s;
        pos[player-1][0][1] = s[1]-'1';
        pos[player-1][0][0] = (player==1?4:0);
        player == 1 ? markgrid("A-P1", pos[player-1][0], {2,2}, player, 0): markgrid("B-P1", pos[player-1][0], {2,2}, player, 0);
        cout<<"Enter the position of Pawn 2: ";
        cin>>s;
        while(exist[player-1][s[1]-'1'])
        {
            cout<<"Invalid Position as chacrter already exist at position. Retry!"<<endl;
            cout<<"Enter the position of Pawn 2: ";
            cin>>s;
        }
        pos[player-1][1][1] = s[1]-'1';
        pos[player-1][1][0] = (player==1?4:0);
        player == 1 ? markgrid("A-P2", pos[player-1][1], {2,2}, player, 1): markgrid("B-P2", pos[player-1][1], {2,2}, player, 1);
        cout<<"Enter the position of Hero 1: ";
        cin>>s;
        while(exist[player-1][s[1]-'1'])
        {
            cout<<"Invalid Position as chacrter already exist at position. Retry!"<<endl;
            cout<<"Enter the position of Hero 1: ";
            cin>>s;
        }
        pos[player-1][2][1] = s[1]-'1';
        pos[player-1][2][0] = (player==1?4:0);
        player == 1 ? markgrid("A-H1", pos[player-1][2], {2,2}, player, 2): markgrid("B-H1", pos[player-1][2], {2,2}, player, 2);
        cout<<"Enter the position of Hero 2: ";
        cin>>s;
        while(exist[player-1][s[1]-'1'])
        {
            cout<<"Invalid Position as chacrter already exist at position. Retry!"<<endl;
            cout<<"Enter the position of Hero 2: ";
            cin>>s;
        }
        pos[player-1][3][1] = s[1]-'1';
        pos[player-1][3][0] = (player==1?4:0);
        player == 1 ? markgrid("A-H2", pos[player-1][3], {2,2}, player, 3): markgrid("B-H2", pos[player-1][3], {2,2}, player, 3);
        cout<<"Enter the position of Hero 3: ";
        cin>>s;
        while(exist[player-1][s[1]-'1'])
        {
            cout<<"Invalid Position as chacrter already exist at position. Retry!"<<endl;
            cout<<"Enter the position of Hero 3: ";
            cin>>s;
        }
        pos[player-1][4][1] = s[1]-'1';
        pos[player-1][4][0] = (player==1?4:0);
        player == 1 ? markgrid("A-H3", pos[player-1][4], {2,2}, player, 4): markgrid("B-H3", pos[player-1][4], {2,2}, player, 4);
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
            if(exist[player-1][get_char_no(character)]==false)
            {
                cout<<"Character DNE. Thus, Illegal Move. Retry!"<<endl;
                chance(player);
                return ; 
            }
            int f=0;
            for(int i=0; i<legal_moves[character].size(); i++)
            {   
                if(position==legal_moves[character][i])
                {
                    makeMove(character, position, player);
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

    }

    bool nextMoveOnBoard(int player, int char_no, string position, string character)
    {
        if((pos[player-1][char_no][0]+move_matrix[{character, position}][0]>=0)
            &&(pos[player-1][char_no][1]+move_matrix[{character, position}][1]>=0)
            &&(pos[player-1][char_no][0]+move_matrix[{character, position}][0]<5)
            &&(pos[player-1][char_no][1]+move_matrix[{character, position}][1]<5))
                return true;
        return false;
    }
    int get_char_no(string character)
    {
        
        if(character=="P1")
            return 0;
        else if(character=="P2")
            return 1;
        else if(character=="H1")
            return 2;
        else if(character=="H2")
            return 3;
        else 
            return 4;
    }
    void makeMove(string character, string position, int player)
    {
        int char_no = get_char_no(character);
        if(!nextMoveOnBoard(player, char_no, position, character))
        {
            cout<<"Move Lands you out of the board. Thus, Invalid Move, Retry!"<<endl ;
            chance(player);
            return;  
        }
        for(int i=0; i<5; i++)
        {
            if((pos[player-1][char_no][0]+move_matrix[{character, position}][0]==pos[player-1][i][0])
            &&(pos[player-1][char_no][1]+move_matrix[{character, position}][1]==pos[player-1][i][0]))
            {
                cout<<"Move Lands you on your another chacacter. Thus, Invalid Move, Retry!"<<endl;
                chance(player);
                return;
            }
        }
        if(char_no==0||char_no ==1||char_no==4)
        {
            markgrid(player==1? "A"+character:"B"+character,{pos[player-1][char_no][0]+move_matrix[{character, position}][0], 
                pos[player-1][char_no][1]+move_matrix[{character, position}][1]}, pos[player-1][char_no], player, char_no);
                display();
                return ;
        }
        else
        {
            markgrid(player==1? "A"+character:"B"+character,{pos[player-1][char_no][0]+move_matrix[{character, position}][0]/2, 
                pos[player-1][char_no][1]+move_matrix[{character, position}][1]/2}, pos[player-1][char_no], player, char_no);
            markgrid(player==1? "A"+character:"B"+character,{pos[player-1][char_no][0]+move_matrix[{character, position}][0]/2, 
                pos[player-1][char_no][1]+move_matrix[{character, position}][1]/2}, pos[player-1][char_no], player, char_no);
                display();
                return ;
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
    int turn = 1;
    while(gameSession.p1>0&&gameSession.p2>0)
    {
        gameSession.chance(turn);
        if(turn==1)
            turn = 2;
        else
            turn = 1;
    }
    if(gameSession.p1==0)
        cout<<"Player 2 WINS!!"<<endl;
    else
        cout<<"Player 1 WINS!!"<<endl;
}