package VisitingCardBinder;

import java.util.ArrayList;

public class Main
{
    public static void main(String[] args) throws CloneNotSupportedException {
        /*
        //Personal 클래스 테스트
        System.out.println("Personal 클래스 테스트");
        //1. Personal 디폴트 생성자
        System.out.println("1. Personal 디폴트 생성자");
        Personal personalOne = new Personal();
        System.out.println(personalOne);
        //2. 매개변수를 가지는 생성자
        System.out.println("2. 매개변수를 가지는 생성자");
        Personal personalTwo = new Personal("홍길동", "대리",
                "01099840345", "Hong@naver.com");
        System.out.println(personalTwo);
        //3. personalOne과 personalTwo비교하기
        System.out.println("3. personalOne과 personalTwo 비교하기");
        System.out.println(personalOne.equals(personalTwo));
        //4. clone으로 복사하기
        System.out.println("4. clone으로 복사하기");
        personalOne = personalTwo.clone();
        System.out.println(personalOne);
        //5.personalOne과 personalTwo비교하기
        System.out.println("5. personalOne과 personalTwo 비교하기");
        System.out.println(personalOne.equals(personalTwo));

        System.out.println();
        //Company 클래스 테스트
        System.out.println("Company 클래스 테스트");
        //1. Company 디폴트 생성자
        System.out.println("1. Company 디폴트 생성자");
        Company companyOne = new Company();
        System.out.println(companyOne);
        //2. 매개변수를 가지는 생성자
        System.out.println("2. 매개변수를 가지는 생성자");
        Company companyTwo = new Company("삼성전자", "서울시 서초구",
                "023345678", "023345679", "samsung.com");
        System.out.println(companyTwo);
        //3. personalOne과 personalTwo비교하기
        System.out.println("3. companyOne companyTwo 비교하기");
        System.out.println(companyOne.equals(companyTwo));
        //4. clone으로 복사하기
        System.out.println("4. clone으로 복사하기");
        companyOne = companyTwo.clone();
        System.out.println(companyOne);
        //5.personalOne과 personalTwo비교하기
        System.out.println("5. companyOne companyTwo 비교하기");
        System.out.println(companyOne.equals(companyTwo));

        System.out.println();
        //VisitingCard 클래스 테스트
        System.out.println("VisitingCard 클래스 테스트");
        //1. VisitingCard 디폴트 생성자
        System.out.println("1. VisitingCard 디폴트 생성자");
        VisitingCard visitingCardOne = new VisitingCard();
        System.out.println(visitingCardOne);
        //2. 매개변수를 2개 가지는 생성자
        System.out.println("2. 매개변수를 2개 가지는 생성자");
        VisitingCard visitingCardTwo = new VisitingCard(personalTwo, companyTwo);
        System.out.println(visitingCardTwo);
        //3. 매개변수를 9개 가지는 생성자
        System.out.println("3. 매개변수를 9개 가지는 생성자");
        VisitingCard visitingCardThree = new VisitingCard(personalOne.getName(),
                personalOne.getPosition(), personalOne.getCellularPhoneNumber(),
                personalOne.getEmailAddress(), companyOne.getName(),
                companyOne.getAddress(), companyOne.getTelephoneNumber(),
                companyOne.getFaxNumber(), companyOne.getUrl());
        System.out.println(visitingCardThree);
        //4. visitingCardOne과 visitringCardTwo 비교하기
        System.out.println("4. visitingCardOne과 visitringCardTwo 비교하기");
        System.out.println(visitingCardOne.equals(visitingCardTwo));
        //5. clone으로 복사하기
        System.out.println("5. clone으로 복사하기");
        visitingCardOne = visitingCardTwo.clone();
        System.out.println(visitingCardOne);
        //6. visitingCardOne과 visitringCardTwo 비교하기
        System.out.println("6. visitingCardOne과 visitringCardTwo 비교하기");
        System.out.println(visitingCardOne.equals(visitingCardTwo));
         */
        //System.out.println();
/*
        //VisitingCardBinder 클래스 테스트
        System.out.println("VisitingCardBinder 클래스 테스트");
        //VisitingCardBinder 디폴트 생성자로 생성하기
        VisitingCardBinder originalVcb = new VisitingCardBinder();
        //명함철에 끼울 명함생성하기
        VisitingCard one = new VisitingCard("정길동", "대리",
                "01024367967", "Jung@naver.com",
                "삼성전자", "서울시 서초구", "023692447",
                "023692448", "Samsung.com");
        VisitingCard two = new VisitingCard("홍길동", "대리",
                "01036937428", "Hong@naver.com",
                "신한은행", "서울 중구",
                "023347714", "023347715", "Shinhan.com");
        VisitingCard three = new VisitingCard("차길동", "과장",
                "01036925571", "Cha@naver.com",
                "엘지전자", "서울시 강서구",
                "022397821", "022397822", "LG.com");
        VisitingCard four = new VisitingCard("김길동", "부장",
                "01036901127", "Kim@naver.comn",
                "현대자동차", "울산 북구",
                "0524379702", "0524379701", "Hyundai.com");
        VisitingCard five = new VisitingCard("나길동", "사원",
                "01036928827", "Na@naver.com",
                "SK하이닉스", "경기도 이천",
                "-0313692248", "0313692249", "SK.com");
        VisitingCard six = new VisitingCard("장길동", "전무",
                "01044287990", "Jang@naver.com",
                "노랑풍선", "서울 중구",
                "029912970", "029912971", "Yellow.com");
        VisitingCard seven = new VisitingCard("홍길동", "이사",
                "01098712341", "Hong@gmail.com",
                "아시아나항공", "서울 종로구",
                "028711297", "028711298", "Asiana.com");
        //명함철에 명함 끼우기
        originalVcb.takeIn(one);
        originalVcb.takeIn(two);
        originalVcb.takeIn(three);
        originalVcb.takeIn(four);
        originalVcb.takeIn(five);
        originalVcb.takeIn(six);
        originalVcb.takeIn(seven);
        //1. 명함철에 끼운 명함들 출력하기
        System.out.println("1. 명함철에 끼운 명함들 출력하기");
        //originalVcb.load();
        //System.out.println("load한 후에 바로 명함철 출력하기");
        originalVcb.printAllVisitingCards();
        //originalVcb.printAllVisitingCards();
        System.out.println();
        /*
        one = new VisitingCard("공길동", "과장",
                "01048489904", "Gong@naver.com",
                "신한은행", "서울 중구",
                "023347714", "023347715", "Shinhan.com");
        two = new VisitingCard("봉길동", "차장",
                "01099840103", "Bong@naver.com",
                "신한은행", "서울 중구",
                "023347714", "023347715", "Shinhan.com");
        three = new VisitingCard("홍길동", "사원",
                "01047589912", "Hong@naver.comn",
                "현대자동차", "울산 북구",
                "0524379702", "0524379701", "Hyundai.com");
        four = new VisitingCard("김길동", "대리",
                "01011945927", "Kim@gmail.comn",
                "현대자동차", "울산 북구",
                "0524379702", "0524379701", "Hyundai.com");
        System.out.println("명함 추가한 후에 명함철 출력하기");
        five = new VisitingCard("박길동", "사원",
                "01098900743", "Park@naver.com",
                "네이버", "성남시 판교", "0319984567",
                "0329984568", "www.naver.com");
        originalVcb.takeIn(one);
        originalVcb.takeIn(two);
        originalVcb.takeIn(three);
        originalVcb.takeIn(four);
        originalVcb.takeIn(five);
         */
        //originalVcb.printAllVisitingCards();
        //originalVcb.save();
/*
        //복사하기
        VisitingCardBinder copyVcb = originalVcb.clone();
        //2. 복사본 출력하기
        System.out.println();
        System.out.println("2. 복사본 출력하기");
        copyVcb.printAllVisitingCards();
        //복사본 정렬하기
        copyVcb.arrange();
        //3. 정렬한 복사본 출력하기
        System.out.println();
        System.out.println("3. 정렬한 복사본 출력하기");
        copyVcb.printAllVisitingCards();
        //4. 원본 출력하기
        System.out.println();
        System.out.println("4. 원본출력하기");
        originalVcb.printAllVisitingCards();
        */

        /*
        System.out.println();
        //복사하기
        VisitingCardBinder copyVcb = originalVcb.clone();
        //2. 복사본 출력하기
        System.out.println("2. 복사본 출력하기");
        copyVcb.printAllVisitingCards();
        //복사본에 끼운 명함내용 변경하기
        copyVcb.getVisitingCards().getLast().setPosition("회장");
        copyVcb.getVisitingCards().getFirst().setPosition("부장");
        //3. 복사본에 명함 내용 변경한 후에 복사본 출력하기
        System.out.println();
        System.out.println("3. 복사본에 명함 내용 변경한 후에 복사본 출력하기");
        copyVcb.printAllVisitingCards();
        System.out.println();
        //4. 복사본에 명함 내용 변경한 후에 원본 출력하기
        System.out.println("4. 복사본에 명함 내용 변경한 후에 원본 출력하기");
        originalVcb.printAllVisitingCards();
        //복사본에서 홍길동으로 명함 찾기
        ArrayList<VisitingCard> indexes = copyVcb.find("홍길동");
        //5. 홍길동으로 찾은 명함 출력하기
        System.out.println();
        System.out.println("5. 홍길동으로 찾은 명함 출력하기");
        for (int i = 0; i < indexes.size(); i++)
        {
            System.out.printf("%s%d","< ", i).println("번째 명함: " + indexes.get(i) + " >");
        }
        //복사본에서 첫번째 홍길동 명함꺼내기
        VisitingCard visitingCard = copyVcb.takeOut(indexes.get(0));
        //6. 복사본에서 꺼낸 첫번째 홍길동 명함 출력하기
        System.out.println();
        System.out.println("6. 복사본에서 꺼낸 첫번째 홍길동 명함 출력하기");
        System.out.println(visitingCard);
        //7. 복사본에서 첫번째 홍길동 명함 꺼낸 후에 복사본 출력하기
        System.out.println();
        System.out.println("7. 복사본에서 첫번째 홍길동 명함 꺼낸 후에 복사본 출력하기");
        copyVcb.printAllVisitingCards();
        //8. 복사본에서 첫번째 홍길동 명함 꺼낸 후에 원본 출력하기
        System.out.println();
        System.out.println("8. 복사본에서 첫번째 홍길동 명함 꺼낸 후에 원본 출력하기");
        originalVcb.printAllVisitingCards();
        //원본에서 상호명(삼성전자)으로 명함 찾기
        visitingCard = originalVcb.findCompanyName("삼성전자");
        //9. 원본에서 상호명(삼성전자)으로 찾은 명함 출력하기
        System.out.println();
        System.out.println("9. 원본에서 상호명(삼성전자)으로 찾은 명함 출력하기");
        System.out.println(visitingCard);
        //10. 원본에서 현재 명함 출력하기
        System.out.println();
        System.out.println("10. 원본에서 현재 명함 출력하기");
        System.out.println(originalVcb.getCurrent());
        //11. 원본에서 다음으로 이동한 후 출력하기
        System.out.println();
        originalVcb.next();
        System.out.println("11. 원본에서 다음으로 이동한 후 출력하기");
        System.out.println(originalVcb.getCurrent());
        //12. 원본에서 마지막으로 이동한 후 출력하기
        System.out.println();
        originalVcb.last();
        System.out.println("12. 원본에서 마지막으로 이동한 후 출력하기");
        System.out.println(originalVcb.getCurrent());
        //13. 원본에서 이전으로 이동한 후 출력하기
        System.out.println();
        System.out.println("13. 원본에서 이전으로 이동한 후 출력하기");
        originalVcb.previous();
        System.out.println(originalVcb.getCurrent());
        //14. 원본에서 처음으로 이동한 후 출력하기
        System.out.println();
        originalVcb.first();
        System.out.println("14. 원본에서 처음으로 이동한 후 출력하기");
        System.out.println(originalVcb.getCurrent());
        //15. 원본에서 이전으로 이동한 후 출력하기
        System.out.println();
        originalVcb.previous();
        System.out.println("15. 원본에서 이전으로 이동한 후 출력하기");
        System.out.println(originalVcb.getCurrent());
        //16. 원본에서 처음으로 이동한 후 출력하기
        System.out.println();
        System.out.println("16. 원본에서 처음으로 이동한 후 출력하기");
        originalVcb.first();
        System.out.println(originalVcb.getCurrent());
        //17. 원본에서 다음으로 이동한 후 출력하기
        System.out.println();
        System.out.println("17. 원본에서 다음으로 이동한 후 출력하기");
        originalVcb.next();
        System.out.println(originalVcb.getCurrent());
        //18. 원본에서 마지막으로 이동한 후 출력하기
        System.out.println();
        System.out.println("18. 원본에서 마지막으로 이동한 후 출력하기");
        originalVcb.last();
        System.out.println(originalVcb.getCurrent());
         */
        //VisitingCardBinder 클래스 테스트
        System.out.println("VisitingCardBinder 클래스 테스트");
        //VisitingCardBinder 디폴트 생성자로 생성하기
        VisitingCardBinder originalVcb = new VisitingCardBinder();
        //명함철에 끼울 명함생성하기
        VisitingCard one = new VisitingCard("정길동", "대리",
                "01024367967", "Jung@naver.com",
                "삼성전자", "서울시 서초구", "023692447",
                "023692448", "Samsung.com");
        VisitingCard two = new VisitingCard("홍길동", "대리",
                "01036937428", "Hong@naver.com",
                "신한은행", "서울 중구",
                "023347714", "023347715", "Shinhan.com");
        VisitingCard three = new VisitingCard("차길동", "과장",
                "01036925571", "Cha@naver.com",
                "엘지전자", "서울시 강서구",
                "022397821", "022397822", "LG.com");
        VisitingCard four = new VisitingCard("김길동", "부장",
                "01036901127", "Kim@naver.comn",
                "현대자동차", "울산 북구",
                "0524379702", "0524379701", "Hyundai.com");
        VisitingCard five = new VisitingCard("나길동", "사원",
                "01036928827", "Na@naver.com",
                "SK하이닉스", "경기도 이천",
                "-0313692248", "0313692249", "SK.com");
        VisitingCard six = new VisitingCard("장길동", "전무",
                "01044287990", "Jang@naver.com",
                "노랑풍선", "서울 중구",
                "029912970", "029912971", "Yellow.com");
        VisitingCard seven = new VisitingCard("홍길동", "이사",
                "01098712341", "Hong@gmail.com",
                "아시아나항공", "서울 종로구",
                "028711297", "028711298", "Asiana.com");
        //명함철에 명함 끼우기
        originalVcb.takeIn(one);
        originalVcb.takeIn(two);
        originalVcb.takeIn(three);
        originalVcb.takeIn(four);
        originalVcb.takeIn(five);
        originalVcb.takeIn(six);
        originalVcb.takeIn(seven);
        //1. 명함철에 끼운 명함들 출력하기
        System.out.println("1. 명함철에 끼운 명함들 출력하기");
        originalVcb.printAllVisitingCards();
        System.out.println();
        //복사하기
        VisitingCardBinder copyVcb = originalVcb.clone();
        //2. 복사본 출력하기
        System.out.println();
        System.out.println("2. 복사본 출력하기");
        copyVcb.printAllVisitingCards();
        //복사본에 끼운 명함내용 변경하기
        copyVcb.getVisitingCards().getLast().setPosition("회장");
        copyVcb.getVisitingCards().getFirst().setPosition("부장");
        //3. 복사본에 명함 내용 변경한 후에 복사본 출력하기
        System.out.println();
        System.out.println("3. 복사본에 명함 내용 변경한 후에 복사본 출력하기");
        copyVcb.printAllVisitingCards();
        System.out.println();
        //4. 복사본에 명함 내용 변경한 후에 원본 출력하기
        System.out.println("4. 복사본에 명함 내용 변경한 후에 원본 출력하기");
        originalVcb.printAllVisitingCards();
        //복사본에서 홍길동으로 명함 찾기
        ArrayList<VisitingCard> indexes = copyVcb.find("홍길동");
        //5. 복사본에서 홍길동으로 찾은 명함 출력하기
        System.out.println();
        System.out.println("5. 복사본에서 홍길동으로 찾은 명함 출력하기");
        for (int i = 0; i < indexes.size(); i++)
        {
            System.out.printf("%s%d","< ", i).println("번째 명함: " + indexes.get(i) + " >");
        }
        //복사본에서 첫번째 홍길동 명함꺼내기
        VisitingCard visitingCard = copyVcb.takeOut(indexes.get(0));
        //6. 복사본에서 꺼낸 첫번째 홍길동 명함 출력하기
        System.out.println();
        System.out.println("6. 복사본에서 꺼낸 첫번째 홍길동 명함 출력하기");
        System.out.println(visitingCard);
        //7. 복사본에서 첫번째 홍길동 명함 꺼낸 후에 복사본 출력하기
        System.out.println();
        System.out.println("7. 복사본에서 첫번째 홍길동 명함 꺼낸 후에 복사본 출력하기");
        copyVcb.printAllVisitingCards();
        //복사본 정렬하기
        copyVcb.arrange();
        //8. 정렬한 복사본 출력하기
        System.out.println();
        System.out.println("8. 정렬한 복사본 출력하기");
        copyVcb.printAllVisitingCards();
        //9. 원본에서 현재 명함 출력하기
        System.out.println();
        System.out.println("9. 원본에서 현재 명함 출력하기");
        System.out.println(originalVcb.getCurrent());
        //10. 원본에서 다음으로 이동한 후 출력하기
        System.out.println();
        originalVcb.next();
        System.out.println("10. 원본에서 다음으로 이동한 후 출력하기");
        System.out.println(originalVcb.getCurrent());
        //11. 원본에서 마지막으로 이동한 후 출력하기
        System.out.println();
        originalVcb.last();
        System.out.println("11. 원본에서 마지막으로 이동한 후 출력하기");
        System.out.println(originalVcb.getCurrent());
        //12. 원본에서 이전으로 이동한 후 출력하기
        System.out.println();
        System.out.println("12. 원본에서 이전으로 이동한 후 출력하기");
        originalVcb.previous();
        System.out.println(originalVcb.getCurrent());
        //13. 원본에서 처음으로 이동한 후 출력하기
        System.out.println();
        originalVcb.first();
        System.out.println("13. 원본에서 처음으로 이동한 후 출력하기");
        System.out.println(originalVcb.getCurrent());
        //14. 원본에서 이전으로 이동한 후 출력하기
        System.out.println();
        originalVcb.previous();
        System.out.println("14. 원본에서 이전으로 이동한 후 출력하기");
        System.out.println(originalVcb.getCurrent());
        //15. 원본에서 처음으로 이동한 후 출력하기
        System.out.println();
        System.out.println("15. 원본에서 처음으로 이동한 후 출력하기");
        originalVcb.first();
        System.out.println(originalVcb.getCurrent());
        //16. 원본에서 다음으로 이동한 후 출력하기
        System.out.println();
        System.out.println("16. 원본에서 다음으로 이동한 후 출력하기");
        originalVcb.next();
        System.out.println(originalVcb.getCurrent());
        //17. 원본에서 마지막으로 이동한 후 출력하기
        System.out.println();
        System.out.println("17. 원본에서 마지막으로 이동한 후 출력하기");
        originalVcb.last();
        System.out.println(originalVcb.getCurrent());
    }
}
