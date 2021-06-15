#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "cursor.h" 
#include <string.h>
#include <assert.h>
#include <iostream>
using namespace std;

const int MaxCard = 48;    // 화투패 개수
const int CardGap = 4;     // 카드 간의 간격(하나의 카드를 세 문자 길이로 출력하고 공백 하나를 더해서 4칸)
const int Speed = 1000;        // 카드를 내거나 메세지를 출력할때 대기할 시간 => 전체적인 게임속도 조절
const int PromptSpeed = 2000;  // 변화가 생길때마다 게임판의 흐름과 메세지를 확인할 시간이 확보되야함.


//// 화투 한장을 표현하는 클래스
struct SCard
{
    char Name[4];
    SCard() { Name[0] = 0; }
    SCard(const char* pName)
    {
        strcpy(this->Name, pName);
    }

    int GetNumber() const  // 화투의 숫자
    {
        if (isdigit(Name[0])) return Name[0] - '0';
        if (Name[0] == 'J') return 10;                      // 10번 이상의 카드를 장, 비, 똥으로 불리는데 1바이트 표현을위해 J, B, D로 표현
        if (Name[0] == 'D') return 11;
        return 12;
    }

    int GetKind() const   // 화투의 종류
    {
        if (strcmp(Name + 1, "광") == 0) return 0;          // 카드의 종류는 광, 십, 오, 피 4종류로 구분
        else if (strcmp(Name + 1, "십") == 0) return 1;
        else if (strcmp(Name + 1, "오") == 0) return 2;
        else if (strcmp(Name + 1, "쌍") == 0) return 3;
        else return 4;
    }

    friend ostream& operator <<(ostream& c, const SCard& C) // << 연산자 정의, Name 멤버를 cout로 출력
    {
        return c << C.Name;
    }

    bool operator ==(const SCard& Other) const              // == 연산자 정의, 두 카드가 같은지 조사. 이름이 일치하면 같은 카드임.
    {
        return (strcmp(Name, Other.Name) == 0);
    }

    bool operator <(const SCard& Other) const               // < 연산자 정의, 두 카드의 대소를 비교.(1차로 숫자, 숫자가 같으면 광, 십, 오, 피 순으로 순서를 매김)
    {
        if (GetNumber() < Other.GetNumber()) return true;
        if (GetNumber() > Other.GetNumber()) return false;
        if (GetKind() < Other.GetKind()) return true;
        return false;
    }
};


// 화투의 초기 카드 목록
SCard HwaToo[MaxCard] = {
    "1광","1오","1피","1피","2십","2오","2피","2피","3광","3오","3피","3피",
    "4십","4오","4피","4피","5십","5오","5피","5피","6십","6오","6피","6피",
    "7십","7오","7피","7피","8광","8십","8피","8피","9십","9오","9피","9피",
    "J십","J오","J피","J피","D광","D쌍","D피","D피","B광","B십","B오","B쌍"
};


//// 카드의 집합을 관리하는 클래스
//// 삽입, 삭제, 검색 등의 기본적인 기능 제공
//// 이 클래스는 게임에 등장하는 카드 집합의 공통 부모역할을함.
class CCardSet
{
protected:
    SCard Card[MaxCard];
    int Num;                 // 집합에 포함된 카드의 현재 개수(삽입, 삭제되면서 증감)
    const int sx, sy;        // 카드 집합의 화면상 좌표이면서 출력 위치를 변경할 일이 없기때문에 상수화
    CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }

public:
    int GetNum()
    {
        return Num;
    }
    SCard GetCard(int idx)
    {
        return Card[idx];
    }
    void Reset()
    {
        for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
        Num = 0;
    }

    void InsertCard(SCard C);              // 카드삽입함수
    SCard RemoveCard(int idx);             // 지정한 첨자의 카드를 제거하고 해당 카드를 리턴(손에서 카드 내거나 데크에서 카드를 뒤집을때 호출)
    int FindSameCard(SCard C, int* pSame); // C와 일치하는 카드를 조사하는 함수
    int FindFirstCard(const char* pName);
    int GetMaxSeries();
};

// 카드 삽입 함수
void CCardSet::InsertCard(SCard C)
{
    int i;

    if (C.Name[0] == 0) return;
    for (i = 0; i < Num; i++)
    {
        if (C < Card[i]) break;
    }
    memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));
    Card[i] = C;
    Num++;
}

SCard CCardSet::RemoveCard(int idx)
{
    assert(idx < Num);
    SCard C = Card[idx];
    memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
    Num--;
    return C;
}

int CCardSet::FindSameCard(SCard C, int* pSame)
{
    int i, num;
    int* p = pSame;

    for (i = 0, num = 0; i < Num; i++)
    {
        if (Card[i].GetNumber() == C.GetNumber())
        {
            num++;
            *p++ = i;
        }
    }
    *p = -1;
    return num;
}

int CCardSet::FindFirstCard(const char* pName)
{
    int i;

    for (i = 0; i < Num; i++)
    {
        if (strstr(Card[i].Name, pName) != NULL)
        {
            return i;
        }
    }
    return -1;
}

// 한꺼번에 들어온 카드가 몇장인지 조사하는 함수
int CCardSet::GetMaxSeries()
{
    int i, n, m, old = -1;

    for (i = 0, n = 1, m = 1; i < Num; i++)
    {
        if (old == Card[i].GetNumber())
        {
            n++;
            m = max(n, m);
        }
        else
        {
            n = 1;
            old = Card[i].GetNumber();
        }
    }
    return m;
}

//// 담요 중앙에 카드를 쌓아 놓는 덱
class CDeck : public CCardSet  // 카드의 집합이므로 CCardSet에게 상속받음
{
public:
    CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }
    void Shuffle()          // 카드를 무작위로 섞기(랜덤함수사용)
    {
        int i, n;
        for (i = 0; i < MaxCard; i++)
        {
            do
            {
                n = random(MaxCard);
            } while (Card[n].Name[0] != NULL);

            Card[n] = HwaToo[i];    // 화투(1광, 1오 같은 이름이 겁나적혀있는 배열)가 무작위로 Card배열로 들어감
            Num++;
        }
    }
    SCard Pop() { return RemoveCard(Num - 1); } // 카드를 위에서부터 한장씩 플레이어에게 나눠주는 함수
    bool IsEmpty() { return Num == 0; }         // 카드가 0인지 조사하여 게임끝인지 조사함.
    bool IsNotLast() { return Num > 1; }        // 마지막판인지 조사
    void Draw(bool bFlip)                       // 화면에 덱을 그리는 함수. ???만 출력하고 한장을 막 뒤집었을때 옆에 무슨카드인지 보여줌
    {
        gotoxy(sx, sy);
        cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");  // bFlip인수는 제일 윗장을 뒤집어 보여줄것인지를 지정함
    }
};



//// 게임을 하는 플레이어
class CPlayer : public CCardSet
{
public:
    CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }

    // 플레이어의 패를 그리는 함수 => 손에 쥔 카드를 순서대로 화면에 나열.
    // 자기차례일때는 어떤 카드를 낼지 입력받기위해 패 아래쪽에 일련 번호를 출력
    // 1오 2십 2오 5오 5피         // 원래 이렇게보이다가
    // [1] [2] [3] [4] [5]         // 자기차례되면 번호가 나오게됨.(이때 숫자를 입력하면 그 카드를 내는것임)
    void Draw(bool MyTurn)
    {
        int i, x;
        for (i = 0, x = sx; i < Num; i++, x += CardGap)
        {
            gotoxy(x, sy);
            cout << Card[i];
            if (MyTurn)
            {
                gotoxy(x, sy + 1);
                cout << '[' << i + 1 << ']';
            }
        }
    }
};


// 게임이 진행되는 담요 : 카드를 보여주기만하면되서 카드를 고를 필요는 없음 => Draw함수는 그대로 호출하되 Myturn 인수는 항상 false임.
// 대신 일치하는 카드가 두장일때 어떤 카드를 먹을지 선택받아야함.
class CBlanket : public CPlayer
{
public:
    CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
    void Draw() {
        CPlayer::Draw(false);
    }


    // DrawSelNum 함수
    //                 [1] [2]      // 카드냈는데 일치하는 카드가 2장이면 이렇게 번호가 나와야함(1, 2 중에 키보드입력으로 뭐먹을지 선택)
    // 1피 2오 2피 5오 8광 8피
    void DrawSelNum(int* pSame)
    {
        int n;
        int* p;
        for (n = 1, p = pSame; *p != -1; p++, n++)
        {
            gotoxy(sx + *p * CardGap, sy - 1);
            cout << '[' << n << ']';
        }
    }


    // DrawTempCard 함수
    // 1피 2오 2피 5십 8광
    //             5피          // 카드냈는데 일치하는 카드가있으면 이렇게 표시함 
    void DrawTempCard(int idx, SCard C)
    {
        gotoxy(sx + idx * CardGap, sy + 1);
        cout << C;
    }
};



//// 플레이어가 먹은 카드의 집합
class CPlayerPae : public CCardSet
{
private:
    int nGo;            // 고 횟수는 숨겨놓음(1씩만 증가하면서 감소하는 경우는 없음)

public:
    int OldScore;       // 6점으로 초기화, 맞고는 7점 이상부터 스톱가능.
    int bShake;
    CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; bShake = false; }
    void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; bShake = false; }
    int GetGo() { return nGo; }
    void IncreaseGo() { nGo++; }
    void Draw();                        // 먹은 패를 화면에 출력
    int RemovePee(int n, SCard* pCard); // 상대방이 세 장을 한꺼번에 싹쓸이했을때 피 한장을 제거하여 상대방에게 주는 함수
                                        // RemovePee에서 리턴되는 카드는 상대방의 먹은 패에 삽입됨.  
    int CalcScore();  // 고스톱 규칙대로 점수 계산. 
                      // 광 개수에따라 세장 이상은 각각 3, 4, 15점.    비광이 포함된 3광은 2점.
                      // 십과 오는 다섯 장부터 1점으로 계산
                      // 청단, 초단, 홍단은 각 3점, 고도리는 5점
};


// 먹은 패를 화면에 출력
void CPlayerPae::Draw()
{
    int i, kind;
    int x[4] = { sx,sx,sx,sx }, py = sy + 3;

    for (i = 0; i < Num; i++)
    {
        kind = Card[i].GetKind();
        if (kind < 3)
        {
            gotoxy(x[kind], sy + kind);
            x[kind] += CardGap;
        }
        else
        {
            gotoxy(x[3], py);
            x[3] += CardGap;
            if (x[3] > 75)
            {
                x[3] = sx;
                py++;
            }
        }
        cout << Card[i];
    }

    // 처음패가 3장이상일때 흔들었으면 화면에 흔들었다는 표시해두기
    gotoxy(sx + 20, sy);
    cout << "점수:" << CalcScore() << "점, " << nGo << "고 "
        << (bShake ? "흔듬" : "");
}


// 상대방이 3장을 한꺼번에 먹거나 싹쓸이 했을때 피 한장을 제거하여 상대방에게 줄때
// RemovePee가 리턴하는 카드는 상대방의 먹은 패에 삽입됨.
int CPlayerPae::RemovePee(int n, SCard* pCard)
{
    int ns = 0;
    int np = 0;
    int tp;
    int i, idx, num = 0;
    SCard* p = pCard;

    for (i = 0; i < Num; i++)
    {
        if (Card[i].GetKind() == 3) ns++;
        if (Card[i].GetKind() == 4) np++;
    }
    tp = ns + np;
    if (tp == 0) return 0;

    switch (n)
    {
    case 1:
        if (np != 0)
        {
            *p++ = RemoveCard(FindFirstCard("피"));
            return 1;
        }
        else
        {
            *p++ = RemoveCard(FindFirstCard("쌍"));
            return 1;
        }
        break;

    case 2:
        if (ns != 0)
        {
            *p = RemoveCard(FindFirstCard("쌍"));
            return 1;
        }
        else
        {
            *p++ = RemoveCard(FindFirstCard("피"));
            num = 1;
            if (np >= 2)
            {
                *p++ = RemoveCard(FindFirstCard("피"));
                num = 2;
            }
            return num;
        }

    case 3:
        i = RemovePee(2, p);
        p += i;
        idx = RemovePee(1, p);
        return i + idx;

    default:
        return 0;
    }
}

// 고스톱 규칙대로 점수를 계산
int CPlayerPae::CalcScore()
{
    int i, kind, n[4] = { 0, };
    int NewScore;
    static int gscore[] = { 0,0,0,3,4,15 };

    for (i = 0; i < Num; i++)
    {
        kind = Card[i].GetKind();
        if (kind == 3) n[kind]++;
        if (kind >= 3) kind = 3;
        n[kind]++;
    }

    NewScore = gscore[n[0]];

    if (n[0] == 3 && FindFirstCard("B광") != -1) NewScore--;
    if (n[1] >= 5) NewScore += (n[1] - 4);
    if (n[2] >= 5) NewScore += (n[2] - 4);
    if (n[3] >= 10) NewScore += (n[3] - 9);
    if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1) NewScore += 5;
    if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1) NewScore += 3;
    if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1) NewScore += 3;
    if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1) NewScore += 3;

    return NewScore;
}




///////////////////////////////////////////////위에꺼가 클래스 정의////////////////////////////////////////////////////////////////////



// 함수 원형
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);


// 전역 변수
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);  // 플레이어(남군, 북군)
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn;       // 지금 누가 카드를 낼 차례인지 기억할 변수



void main()
{
    int i, ch;
    int arSame[4], SameNum;
    char Mes[256];
    CPlayer* Turn;
    CPlayerPae* TurnPae, * OtherPae;
    int UserIdx, UserSel, DeckSel;
    SCard UserCard, DeckCard;
    bool UserTriple;           // 플레이어가 카드를 냈는데 본인꺼 + 담요의 3장, 즉 4장을 먹었을때 flag
    bool DeckTriple;           // 맨위의 데크의 카드를 뒤집었는데 3장이 일치할때를 체크하는 flag
    int nSnatch;
    int NewScore;
    SCard arPee[3];
    int nPee;
    CPlayer* LastGo = NULL;

    randomize();

    /*for (int k = 0; k < 1000; k++) {    // 자동 테스트. main함수 맨밑에 for문 닫는 중괄호( '}')있음.
        srand(k);*/


    Initialize();
    DrawScreen();    // 각 객체를 화면에 그리고 시작


    // 처음 카드중에 3장이 같으면 흔들껀지 말껀지 출력 (남군, 북군 각각 1번씩)
    if (South.GetMaxSeries() == 3)
    {
        ch = InputInt("같은 카드가 세 장입니다. (1:흔들기, 2:그냥 하기) ", 1, 2);
        if (ch == 1) SouthPae.bShake = true;
    }

    if (North.GetMaxSeries() == 3)
    {
        ch = InputInt("같은 카드가 세 장입니다. (1:흔들기, 2:그냥 하기) ", 1, 2);
        if (ch == 1) NorthPae.bShake = true;
    }

    for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn)  // 남군의 턴, 덱이 0장일때까지, 남군의 턴이 남군의 턴이 아닐때(= 북군의 턴)
    {
        DrawScreen();

        // 누구의 턴인지 구별
        if (SouthTurn)     // 남군의 턴일때
        {
            Turn = &South;
            TurnPae = &SouthPae;
            OtherPae = &NorthPae;
        }
        else               // 북군의 턴일때
        {
            Turn = &North;
            TurnPae = &NorthPae;
            OtherPae = &SouthPae;
        }

        // 갖고있는 카드중에 뭘 낼껀지 물어봄
        sprintf(Mes, "내고 싶은 화투를 선택하세요(1~%d,0:종료) ", Turn->GetNum());
        ch = InputInt(Mes, 0, Turn->GetNum());

        if (ch == 0)
        {
            // 종료 조건문
            if (InputInt("정말 끝낼겁니까?(0:예,1:아니오)", 0, 1) == 0)
                return;       // 0 누르면 종료
            else
                continue;     // 1 누르면 그냥 계속 시작
        }

        // 플레이어가 카드를 한장 낸다.
        UserTriple = DeckTriple = false;
        UserIdx = ch - 1;
        UserCard = Turn->GetCard(UserIdx);
        SameNum = Blanket.FindSameCard(UserCard, arSame);  // 플레이어가 낸 카드와 담요의 카드의 일치 개수를 FindSameCard로 구해서 SameNum에 대입

        // 
        switch (SameNum)
        {
        case 0:                // 일치하는 카드가 없는경우
            UserSel = -1;
            Blanket.InsertCard(Turn->RemoveCard(UserIdx));
            DrawScreen();
            break;

        case 1:                // 하나만 일치하는 경우 => 이 카드를 먹음, 근데 쌌을때가 있을 수도 있으니까 이동은하면안됨.
            UserSel = arSame[0];
            break;

        case 2:                // 두 개가 일치하는 경우 => 둘 중 어떤것을 먹을지 질문하고 플레이어가 선택한 카드를 UserSel에 대입
            if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1]))
            {
                UserSel = arSame[0];
            }
            else
            {
                // 일치하는 카드 목록을 arSame에 담고 담요의 DrawSelNum을 호출.
                // 사용자의 키 입력을받아 UserSel에 담음.
                Blanket.DrawSelNum(arSame);
                sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
                UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];
            }
            break;


            // 두개가 일치하는 경우 ( 2가지 경우의 수)
            /*
             (담요)      1광 (4십 4피) 9십 B오                  1광 (4피 4피) 9십 B오

                          질문을 하는 경우                       질문 필요없는 경우 => 둘 중에 뭘먹든 똑같기때문에 필요없음.

                                              (플레이어카드) 4오
            */


        case 3:                  // 세 개가 일치하는 경우 => 처음부터 3장이 깔렸거나 싼것을 먹는 경우 => 4장의 카드를 다 먹고 상대방의 피를 하나 뺏어옴
            UserSel = arSame[1]; // 3장 중에 가운데 카드를 맞춤
            UserTriple = true;   // 3장을 먹을때의 flag를 true로 해줌
            break;
        }

        if (UserSel != -1)
        {
            Blanket.DrawTempCard(UserSel, UserCard);
        }
        delay(Speed);


        // 데크에서 한장을 뒤집는다.
        Deck.Draw(true);
        delay(Speed);

        DeckCard = Deck.Pop();  // Pop함수로 데크의 제일 위에있는 카드를 꺼내서 DeckCard에 대입

        SameNum = Blanket.FindSameCard(DeckCard, arSame);  // 


        // 데크에서 뒤집은 카드와 담요의 카드가 일치하는 개수에 따라 다음 진행이 결정됨
        switch (SameNum)
        {
        case 0:                  // 일치하는 카드가 없는 경우 => 플레이어가 낸 카드는 즉시 담요에 삽입되지만,
                                                             // 데크에서 뒤집은 카드는 바로 삽입하지 말고 플레이어의 카드가 처리될때 까지 대기함.
            DeckSel = -1;   // 먹을게 없음...
            break;

        case 1:                  // 하나만 일치하는 경우 
            DeckSel = arSame[0];         // DeckSel에 일치한 카드 첨자를 대입
            if (DeckSel == UserSel)
            {
                if (Deck.IsNotLast())    // 데크의 카드를 뒤집었을때 플레이어가 낸 카드와 데크의 카드가 일치하면 쌌다고 표현.
                {
                    Blanket.InsertCard(DeckCard);
                    Blanket.InsertCard(Turn->RemoveCard(UserIdx));
                    OutPrompt("쌌습니다.", PromptSpeed);
                    continue;            // 카드를 가져가지 못하고 모든 카드를 담요에 둔채로 게임이 계속 진행됨.
                }
                else                     // 마지막 판에는 싸는게 없으니 -1을 대입해서 사용자가 낸 카드를 그대로 가져가게함.
                {
                    DeckSel = -1;
                }
            }
            break;

        case 2:                  // 두 개가 일치하는 경우 => 플레이어가 카드를 낸 경우처럼 어떤 카드를 먹을지 플레이어에게 질문.
            if (UserSel == arSame[0])
            {
                DeckSel = arSame[1];
            }
            else if (UserSel == arSame[1])
            {
                DeckSel = arSame[0];
            }
            else
            {
                if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) // 만약 찜했으면 질문 필요없이 남은 하나를 가져감
                {
                    DeckSel = arSame[0];
                }
                else
                {
                    Blanket.DrawSelNum(arSame);
                    sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
                    DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
                }
            }
            break;

        case 3:               // 세 개가 일치하는 경우 => 모든 카드를 다 가져옴.
            DeckSel = arSame[1];   // DeckSel에 가운데 카드를 선택
            DeckTriple = true;     // DeckTriple flag를 true 대입해줌.
            break;
        }

        if (DeckSel != -1)
        {
            Blanket.DrawTempCard(DeckSel, DeckCard);
        }
        Deck.Draw(false);
        delay(Speed);


        // 일치하는 카드를 가져올때 => 세 장을 먹은 경우는 전부 가져옴(UserTriple를 flag로 사용)
        if (UserSel != -1)
        {
            if (UserTriple)   // 세장을 먹었을때
            {
                for (i = 0; i < 3; i++)
                {
                    TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));
                }
            }
            else
            {
                TurnPae->InsertCard(Blanket.RemoveCard(UserSel));
            }
            TurnPae->InsertCard(Turn->RemoveCard(UserIdx));
            if (DeckSel != -1 && DeckSel > UserSel)
            {
                DeckSel -= (UserTriple ? 3 : 1);
            }
        }
        if (DeckSel != -1)
        {
            if (DeckTriple)
            {
                for (i = 0; i < 3; i++)
                {
                    TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));
                }
            }
            else
            {
                TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));
            }
            TurnPae->InsertCard(DeckCard);
        }
        else
        {
            Blanket.InsertCard(DeckCard);
        }

        // 쪽, 따닥, 싹쓸이 조건을 점검하고 상대방의 피를 뺏는다.
        nSnatch = 0;
        if (Deck.IsNotLast())
        {
            if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber())
            {
                nSnatch++;
                OutPrompt("쪽입니다.", PromptSpeed);
            }
            if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber())
            {
                nSnatch++;
                OutPrompt("따닥입니다.", PromptSpeed);
            }
            if (Blanket.GetNum() == 0)
            {
                nSnatch++;
                OutPrompt("싹쓸이입니다.", PromptSpeed);
            }
            if (UserTriple || DeckTriple)
            {
                OutPrompt("한꺼번에 세 장을 먹었습니다.", PromptSpeed);
                nSnatch += UserTriple + DeckTriple;
            }
        }

        nPee = OtherPae->RemovePee(nSnatch, arPee);
        for (i = 0; i < nPee; i++)
        {
            TurnPae->InsertCard(arPee[i]);
        }


        // 점수를 계산하고 고, 스톱 여부를 질문한다.
        NewScore = TurnPae->CalcScore();
        if (Deck.IsNotLast() && NewScore > TurnPae->OldScore)
        {
            DrawScreen();
            if (InputInt("추가 점수를 획득했습니다.(0:스톱, 1:계속)", 0, 1) == 1)
            {
                TurnPae->OldScore = NewScore;
                TurnPae->IncreaseGo();
                LastGo = Turn;
            }
            else
            {
                break;
            }
        }
    }

    DrawScreen();

    // 승부와 피박, 광박, 독박 여부 판정
    bool SouthWin;
    int SouthScore, NorthScore;
    int TurnPee = 0;
    int TurnLight = 0;
    int OtherPee = 0;
    int OtherLight = 0;

    if (Deck.IsEmpty())      // 데크가 0장일 때
    {
        if (LastGo != NULL)  // 만약 둘 중 한명이 고박일때는 고박인 사람이 무조건 패배
        {
            SouthWin = (LastGo == &North);
        }
        else                 // 고박이 없으면 점수로 계산
        {
            SouthScore = SouthPae.CalcScore();
            NorthScore = NorthPae.CalcScore();
            if (SouthScore < 7 && NorthScore < 7)
            {
                OutPrompt("양쪽 모두 기본 점수를 얻지 못해 비겼습니다.");
                return;
            }
            SouthWin = (SouthScore > NorthScore);
        }
    }
    else
    {
        SouthWin = SouthTurn;
    }

    sprintf(Mes, "%s군이 이겼습니다. ", SouthWin ? "남" : "북");

    if (SouthWin)  // 남군이 이겼을때
    {
        TurnPae = &SouthPae;
        OtherPae = &NorthPae;
    }
    else           // 북군이 이겼을때
    {
        TurnPae = &NorthPae;
        OtherPae = &SouthPae;
    }
    for (i = 0; i < TurnPae->GetNum(); i++)
    {
        if (TurnPae->GetCard(i).GetKind() >= 3) TurnPee++;
        if (TurnPae->GetCard(i).GetKind() == 0) TurnLight++;
    }
    for (i = 0; i < OtherPae->GetNum(); i++)
    {
        if (OtherPae->GetCard(i).GetKind() >= 3) OtherPee++;
        if (OtherPae->GetCard(i).GetKind() == 0) OtherLight++;
    }

    if (TurnPee >= 10 && OtherPee < 5 && OtherPee != 0)  // 상대방 피가 다섯 장 미만일때
    {
        strcat(Mes, "진쪽이 피박입니다. ");
    }
    if (TurnLight >= 3 && OtherLight == 0)               // 상대방이 광을 못먹었을때
    {
        strcat(Mes, "진쪽이 광박입니다. ");
    }
    if (OtherPae->GetGo() != 0)                          // 상대방이 고를했지만 추가 점수를 못먹었을때
    {
        strcat(Mes, "진쪽이 독박입니다. ");
    }
    OutPrompt(Mes);

    /*
    // 테스트 할때 사용하는 코드
    gotoxy(40, 22);
    if (Blanket.GetNum() != 0)
    {
        printf("%d 난수번에 이상이 있음", k);
        _getch();
    }
    else
    {
        printf("%d번 테스트 완료", k);
        delay(500);
    }
    SouthPae.Reset();
    NorthPae.Reset();
    // }
    */

}


// 도우미 함수
/// <summary>
/// 덱의 패를 무작위로 섞어 카드를 초기화하는 함수 => 플레이어한테 카드 10장 돌리고 담요에 8장 카드를 깔음
/// </summary>
void Initialize()
{
    int i;

    for (;;) {
        Deck.Reset();
        South.Reset();
        North.Reset();
        Blanket.Reset();
        Deck.Shuffle();
        for (i = 0; i < 10; i++) {
            South.InsertCard(Deck.Pop());
            North.InsertCard(Deck.Pop());
            if (i < 8) Blanket.InsertCard(Deck.Pop());
        }

        // 4장의 같은 패가 들어오면 Reset함수로 집합을 비우고 다시 섞음
        if (South.GetMaxSeries() != 4 && North.GetMaxSeries() != 4 && Blanket.GetMaxSeries() != 4)
            break;
    }
}

/// <summary>
/// 화면을 지우고 모든 객체의 Draw 함수를 차례대로 호출하는 함수
/// </summary>
void DrawScreen()
{
    clrscr();
    South.Draw(SouthTurn);
    North.Draw(!SouthTurn);
    Blanket.Draw();
    Deck.Draw(false);
    SouthPae.Draw();
    NorthPae.Draw();
}

/// <summary>
/// 사용자에게 현재 상태를 알려주거나 다음 행동을 지시할 메세지 출력 함수
/// </summary>
void OutPrompt(const char* Mes, int Wait/*=0*/)
{
    gotoxy(5, 23);
    for (int i = 5; i < 79; i++) { cout << ' '; }
    gotoxy(5, 23);
    cout << Mes;
    delay(Wait);
}

/// <summary>
/// 지정한 범위의 정수 하나를 입력받는 함수(키보드의 숫자키로 진행, 숫자 10대신 알파벳 a를 썼음)
/// </summary>
int InputInt(const char* Mes, int start, int end)
{
    int ch;

    OutPrompt(Mes);
    for (;;) {
        ch = tolower(_getch());
        if (ch == 0xE0 || ch == 0) {
            ch = _getch();
            continue;
        }
        if (!(isdigit(ch) || ch == 'a')) continue;
        if (ch == 'a') ch = 10; else ch = ch - '0';
        if (ch >= start && ch <= end) {
            return ch;
        }
        OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요.");
    }
}
