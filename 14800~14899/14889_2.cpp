#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::abs;

int N;
int answer = 123456789;

// 구현력 부족한 것 같다

void solve(const vector<vector<int>> &v, vector<bool> &isStartTeam, const int startIndex, const int remains) {
    // N/2 명씩 나눴으면 능력치 계산
  if (remains == 0) {
    // 스타트팀, 링크팀 멤버 나누기
    vector<int> startTeamMembers;
    vector<int> linkTeamMembers;
    for (int i=0; i<N; ++i) {
      if (isStartTeam[i]) {
        startTeamMembers.push_back(i);
      } else {
        linkTeamMembers.push_back(i);
      }
    }

    // 각 팀의 능력치 계산
    int abilityOfStartTeam = 0;
    int abilityOfLinkTeam = 0;
    for (int i=0; i<N/2; ++i) {
      for (int j=i+1; j<N/2; ++j) {
        // startTeamMembers[i] + startTeamMembers[j] 라고 해서 틀렸었다
        abilityOfStartTeam += v[startTeamMembers[i]][startTeamMembers[j]];
        abilityOfStartTeam += v[startTeamMembers[j]][startTeamMembers[i]];
        abilityOfLinkTeam += v[linkTeamMembers[i]][linkTeamMembers[j]];
        abilityOfLinkTeam += v[linkTeamMembers[j]][linkTeamMembers[i]];
      }
    }

    // 능력치 차이 최소값 저장
    int diff = abs(abilityOfLinkTeam - abilityOfStartTeam);
    answer = min(answer, diff);
  } else {
    // 중복 안 되게 N/2 명으로 나누기
    for (int i=startIndex; i<N; ++i) {
      isStartTeam[i] = true;
      solve(v, isStartTeam, i+1, remains-1);
      // i 를 startIndex 라고 적어서 중복됐었음
      // 추측: 1, 5, 그 다음에 뽑을게 없어서 N=6 일 때 2명 4명 이런 식으로 나뉨
      // => for 문 실행 안 되므로 방문 안함
      isStartTeam[i] = false;
    }
  }
}

int main() {
  cin >> N;
  vector<vector<int>> S(N, vector<int>(N));
  for (int i=0; i<N; ++i) {
    for (int j=0; j<N; ++j) {
      cin >> S[i][j];
    }
  }
  vector<bool> empty(N, false);
  solve(S, empty, 0, N/2);
  cout << answer << '\n';
  return 0;
}