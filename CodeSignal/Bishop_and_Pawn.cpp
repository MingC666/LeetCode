/*
For bishop = "a1" and pawn = "c3", the output should be
solution(bishop, pawn) = true.

p cannot in diagnal of b in 8*8 matrix
*/
bool checking(string b, string p)
{
    // supposed it is 8*8 matrix
    int bi = b[0]-'a', tbi=bi;
    int bj = b[1]-'0', tbj = bj;
    int pi = p[0]-'a';
    int pj = p[1]-'0';
    
    // left donw
    while(bi-1>-1 && bj-1>-1)
    {
        bi--; bj--;
        if(bi==pi && bj==pj)
            return true;
    }
    
    // left up
    bi = tbi;
    bj = tbj;
    while(bi-1>-1 && bj+1<9)
    {
        bi--; bj++;
        if(bi==pi && bj==pj)
            return true;
    }
    // right up
    bi = tbi;
    bj = tbj;
    while(bi+1<9 && bj+1<9)
    {
        cout << bi << ", " << bj << "; ";
        bi++; bj++;
        if(bi==pi && bj==pj)
            return true;
    }
    
    // right down
    bi = tbi;
    bj = tbj;
    while(bi+1<9 && bj-1>-1)
    {
        bi++; bj--;
        if(bi==pi && bj==pj)
            return true;
    }
    return false;
}
bool solution(string b, string p) {
    return abs(p[0]-b[0]) == abs(p[1]-b[1]);
}


bool solution1(string bishop, string pawn) {
    // checking if 'pawn' in 'bishop' 's diagonal
    return checking(bishop, pawn);
}