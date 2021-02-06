# String

### ASCII
- American Standard Code for Information Interchange
- 7bit 인코딩으로 128문자를 표현
- 33개의 출력 불가능한 제어 문자들과 공백을 비롯한 95개의 출력 가능한 문자들로 구성

### 유니코드
- 영어 외의 언어 처리(다국어 처리)를 위한 표준
- UCS-2, UCS-4
  - 유니코드를 저장하는 변수의 크기를 정의
  - **바이트 순서**(빅 인디안, 리틀 인디안)에 대해서 표준화하지 못함
  
### 유니코드 인코딩(Unicode Transformation Format)
- UTF-8(in web) 
- UTF-16(in windows, java)
- UTF-32(in unix)

### 비교
- java : 문자열 비교에서 == 연산은 **메모리 참조가 같은지**를 묻는 것
  - **equals()** 사용
- java script : == 연산은 **타입이 같은지**를 묻는 것
  - ===을 사용
- c : string.h의 strcmp를 사용하거나 직접 구현해서 사용
 
 ### 패턴매칭
- Brute Force 알고리즘
  - 텍스트의 모든 위치에서 패턴을 비교해야 함
  - O(MN)
- 카프-라빈 알고리즘
- KMP 알고리즘
  - 불일치가 발생한 텍스트 스트링의 앞 부분에 어떤 문자가 있는지를 미리 알고 있음
  - 불일치가 발생한 앞 부분에 대하여 다시 비교하지 않고 매칭을 수행
  - O(M + N)
- 보이어-무어 알고리즘
  - 오른쪽에서 왼쪽으로 비교
  - 패턴의 오른쪽 끝에 있는 문자가 불일치 하고 이 문자가 패턴 내에 존재하지 않는 경우, 이동 거리는 패턴의 길이
  
### 보이어-무어 알고리즘
- 점프 테이블을 생성(해당 문자열을 마주치면 몇 칸을 점프할지 담아두는 공간)
- 각 점프 테이블의 값은 (찾는 문자열의 길이 - index - 1)로 세팅
- 마지막 단어의 테이블 값은 max 값 
- 같은 단어가 나온다면 그 단어가 가진 테이블의 값 중 작은 것으로 세팅
- 찾지 않는 문자열은 모두 max 값으로 세팅
 ``` 
#define SIZE 256
static int jump_table[256];

void set_table(char pattern[])
{
  int length = strlen(pattern);
  for (int i = 0; i < SIZE; i++)
    jump_table[i] = length;
  for (int i = 0; i < length - 1; i++)
    jump_table[pattern[i]] = length - 1 - i;
}

char* boyer_moore(char text[], char pattern[])
{
  int n = strlen(text);
  int m - strlen(pattern);
  int i = 0;
  int index_t, index_p;
  
  set_table(pattern);
  while (i <= n - m)
  {
    index_t = i + m - 1;
    index_p = m - 1;
    while (j >= 0 && pattern[j]==text[k])
    {
      index_t--;
      index_p--;
    }
    if (j == -1)
      return (text + i);
    i += jump[text[i + index_p - 1]];
  }
}
 ```
