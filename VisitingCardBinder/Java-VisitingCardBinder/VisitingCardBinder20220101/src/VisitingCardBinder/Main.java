package VisitingCardBinder;

public class Main
{
    public static void main(String[] args) throws CloneNotSupportedException
    {
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
    }
}
