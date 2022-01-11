package VisitingCardBinder;

public class VisitingCard implements Cloneable
{
    //인스턴스 필드멤버
    private Personal personal;
    private Company company;
    //디폴트 생성자
    public VisitingCard()
    {
        this.personal = new Personal();
        this.company = new Company();
    }
    //매개변수를 2개 가지는 생성자
    public VisitingCard(Personal personal, Company company)
    {
        this.personal = personal;
        this.company = company;
    }
    //매개변수를 9개 가지는 생성자
    public  VisitingCard(String personalName, String position, String cellularPhoneNumber,
                         String emailAddress, String companyName, String address,
                         String telephoneNumber, String faxNumber, String url)
    {
        this.personal = new Personal(personalName, position, cellularPhoneNumber,
                emailAddress);
        this.company = new Company(companyName, address, telephoneNumber,
                faxNumber, url);
    }
    //Cloneable 의 clone 메소드 오버라이딩하기(구현하기)
    @Override
    public VisitingCard clone() throws CloneNotSupportedException
    {
        return (VisitingCard) super.clone();
    }
    //같은 VisitingCard 인지 확인하기(오버라이딩하기)
    @Override
    public boolean equals(Object obj)
    {
        boolean ret = false;
        if(obj instanceof VisitingCard)
        {
            if(this.personal.equals(((VisitingCard)obj).personal) == true
                && this.company.equals(((VisitingCard)obj).company) == true)
            {
                ret = true;
            }
        }
        return ret;
    }
    //테스트 출력용
    @Override
    public String toString()
    {
        return new String("개인 -> " + this.personal.toString() + "\n" +
                            "회사 -> " + this.company.toString());
    }
    //personal getter 메소드
    //getPersonalName
    public String getPersonalName() { return this.personal.getName(); }
    //getPosition
    public String getPosition() { return this.personal.getPosition(); }
    //getCellularPhoneNumber
    public String getCellularPhoneNumber() { return this.personal.getCellularPhoneNumber(); }
    //getEmailAddress
    public String getEmailAddress() { return this.personal.getEmailAddress(); }
    //company getter 메소드
    //getCompanyName
    public String getCompanyName() { return this.company.getName(); }
    //getAddress
    public String getAddress() { return this.company.getAddress(); }
    //getTelephoneNumber
    public String getTelephoneNumber() { return this.company.getTelephoneNumber(); }
    //getFaxNumber
    public String getFaxNumber() { return this.getFaxNumber(); }
    //getUrl
    public String getUrl() { return this.company.getUrl(); }
}
