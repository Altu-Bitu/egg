//n*m보드를 8*8보드로 만들 때
//다시 칠해야 하는 칸 수의 최솟값 구하기
//8*8보드로 정해져있음-->흰색 시작 or 검은색시작. 두가지 뿐.
//B로 시작하는 체스판과 겹치지 않는 칸의수 // 겹치는 칸의 수

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 64; //체스판 8*8

//(row, col) 에서 시작하는 8 * 8 체스판 만드는 데 드는 최소 카운트 리턴
//B로 시작하는 체스판 기준으로 먼저계산
//W로 시작 체스판은 (64-앞의 계산한 수)
int chessChange(int row, int col, vector<vector<char>>& board) { //시작행, 시작열, 전역변수X라 board받음.
    int b_cnt = 0; //B로 시작하는 체스판 만들기 위한 카운트

    for (int i = 0; i < 8; i++) { //행 변화값
        for (int j = 0; j < 8; j++) { //열 변화값
            //(행,열)의 변화값 합이 짝수면 B(시작색) -> 동일하지 않다면 카운트
            //(행,열)로 하면 안됨. 똑같이 B가 시작색이어도 (0,0)에서 시작하기도 하고 (0,5)에서 시작하기도 하니깐.
            if ((i + j) % 2 == 0 && board[row + i][col + j] != 'B')
                b_cnt++;
            //(행, 열) 변화값이 홀수면 W(시작색아닌거) -> W가 아니라면 카운트
            else if ((i + j) % 2 && board[row + i][col + j] != 'W')
                b_cnt++;

        }
    }

    //최솟값 리턴
    if (b_cnt > SIZE / 2) //8*8보드판의 절반보다 b가 크면
        return SIZE - b_cnt;  //w로시작해야되니깐
    return b_cnt; //아니면 b로 시작.
}

int main() {
    int n, m;
    int ans = SIZE + 1; //정답은 최솟값 출력해야하니까. 체스판 칸 개수 + 1 로 초기화(64보다는 작으니)

    //입력
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m)); //2차원 벡터. 초기화. 행: n, 열: m
    for (int i = 0; i < n; i++) //보드 입력받기
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    //연산
    for (int i = 0; i <= n - 8; i++) { //(0,0)부터 검사 시작. 체스판 크기 8이어서 n-8까지.
        for (int j = 0; j <= m - 8; j++) {
            int cnt = chessChange(i, j, board);//시작인덱스가 (i,j)인 체스판 만드는 최솟값 저장한다.
            ans = min(ans, cnt); //최솟값 갱신
        }
    }

    //출력
    cout << ans << '\n';

    return 0;
}