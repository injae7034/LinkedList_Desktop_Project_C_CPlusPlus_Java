package VisitingCardBinder;

public class Company implements Cloneable
{
    //인스턴스 필드멤버
    String name;
    String address;
    String telephoneNumber;
    String faxNumber;
    String url;

    //디폴트생성자
    public Company()
    {
        this.name = "";
        this.address = "";
        this.telephoneNumber = "";
        this.faxNumber = "";
        this.url = "";
    }
    //매개변수를 가지는 생성자
    public Company(String name, String address, String telephoneNumber,
                   String faxNumber, String url)
    {
        this.name = name;
        this.address = address;
        this.telephoneNumber = telephoneNumber;
        this.faxNumber = faxNumber;
        this.url = url;
    }
    //Cloneable 의 clone 메소드 오버라이딩하기(구현하기)
    @Override
    public Company clone() throws CloneNotSupportedException
    {
        return (Company) super.clone();
    }
    //같은 Company 객체인지 확인하기(오버라이딩하기)
    @Override
    public boolean equals(Object obj)
    {
        boolean ret = false;
        if(obj instanceof Company)
        {
            if(this.name.compareTo(((Company)obj).name)==0
                    && this.address.compareTo(((Company)obj).address)==0
                    && this.telephoneNumber.compareTo(((Company)obj).telephoneNumber)==0
                    && this.faxNumber.compareTo(((Company)obj).faxNumber)==0
                    && this.url.compareTo(((Company)obj).url)==0)
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
        return new String(this.name + ", " + this.address + ", " +
                this.telephoneNumber + ", " + this.faxNumber + ", " + this.url);
    }
    //getter 메소드
    //name 가져오기
    public String getName() { return this.name; }
    //address 가져오기
    public  String getAddress() { return this.address; }
    //telephoneNumber 가져오기
    public String getTelephoneNumber() { return this.telephoneNumber; }
    //faxNumber 가져오기
    public String getFaxNumber() { return  this.faxNumber; }
    //url 가져오기
    public  String getUrl() { return  this.url; }
}
