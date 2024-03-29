# 영문자/한글 정렬

한 문자열이 UTF-8 형식으로 주어진다. 이 문자열에는 Unicode로 영문자와 한글이 포함되어 있다.
한자나 특수문자(7bit 아스키 코드에 포함되지 않는 2byte 특수문자)는 없다고 가정한다.
문장에 있는 모든 영문자를 앞에서 우선 출력하고, 문장에 있는 모든 한글 문자를 영문 뒤에 출력하여라.
그 다음 줄에 영어 문자의 개수, 한글 문자의 개수, 총 개수를 차례로 출력하라.


입력
한글과 영문이 혼용된 문장

출력
영문 한글 순서로 정렬된 문장
영문자수 한글문자수 총문자수
```
예제 입력
Eng한글lish

예제 출력
English한글
7 2 9
```

# 암호 최대한 깨기

알파벳의 한 글자씩 다른 글자로 치환해서 암호를 만들었다고 하자. 이 암호를 일부는 깼는데, 다 깨진 못했다.
입력 첫째 줄에는 the quick brown fox jumps over the lazy dog의 암호화 버젼이 있는데, 암호를 다 깨진 못해서 일부는 ?로 되어 있다.
둘째 줄에는 암호화하지 않은 단어들이 있으며, 셋째 줄에는 암호화된 단어들이 있는데, 순서는 섞여 있으며, 서로 짝이 맞지 않는 경우도 있다.
예를 들어, 암호화하지 않은 단어는 있는데, 이에 맞는 암호화된 단어는 없을 수 있고 반대로 암호화된 단어는 있는데 암호화하지 않은 단어도 없을 수 있다. 각 단어는 최대 10글자이다.
이 단어들을 이용해 어떤 글자가 어떤 글자로 암호화되는지를 알아내, the quick brown fox jumps over the lazy dog을 최대한 암호화하여 출력하라.

```
입력
??i ????? h???? u?? ????? ??i? ??i ???? ??m
abcdd hijk lmnop qrstuv
tzwbb nofdx phqgg eayl jkrcvs

출력
cei jvaql hkd?f ud? yvoxr dsik cei np?? gdm
```
