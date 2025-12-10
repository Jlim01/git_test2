# git_test2
ci/cd

정정 전

on:
  push:
    branches: [master]
  pull_request:
    branches: [master]
    
    
정정 후
on: [push]

push할 때 깃액션 빌드업.
깃액션은 깃허브가 제공하는 서버라고 보면됨
yml파일에서 해당 코드 환경을 구축해줘야함.
opencv사용했으니 opencv 설치 명령을 typing함.


# test1
## test2
- test3


하트비트 신규 시나리오('25.05) 미적용에 따른 삭제

- PLC 요청 신규 하트비트 시나리오('25.05)을 사용하지 않기로 결정하여 삭제함
- 2023, 2025년 VDA PPC 모두 기존 하트비트 시나리오 유지

세부 내용:
- 신규 시나리오: B3100이 10초간 ON/OFF 유지 시 PLC 문제로 판단하여 GUI 자체 알람 발생
- 미적용 사유: 업데이트 전날 PLC 측 시나리오 정리 미완료로 인해
  신규(10초 기반 시나리오 + GUI 자체 알람)가 아닌 기존 시나리오를 적용



