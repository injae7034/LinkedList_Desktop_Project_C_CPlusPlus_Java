package VisitingCardBinder;

public class Personal implements Cloneable
{
    //인스턴스 필드멤버
    private String name;
    private String position;
    private String cellularPhoneNumber;
    private String emailAddress;
    //디폴트 생성자
    public Personal()
    {
        this.name = "";
        this.position = "";
        this.cellularPhoneNumber = "";
        this.emailAddress = "";
    }
    //매개변수를 가지는 생성자
    public  Personal(String name, String position, String cellularPhoneNumber,
                     String emailAddress)
    {
        this.name = name;
        this.position = position;
        this.cellularPhoneNumber = cellularPhoneNumber;
        this.emailAddress = emailAddress;
    }
    //Cloneable 의 clone 메소드 오버라이딩하기(구현하기)
    @Override
    public Personal clone() throws CloneNotSupportedException
    {
        return (Personal)super.clone();
    }
    //같은 Personal 객체인지 확인하기(오버라이딩하기)
    @Override
    public boolean equals(Object obj)
    {
        boolean ret = false;
        if(obj instanceof Personal)
        {
            if(this.name.compareTo(((Personal)obj).name)==0
                    && this.position.compareTo(((Personal)obj).position)==0
                    && this.cellularPhoneNumber.compareTo(((Personal)obj).cellularPhoneNumber)==0
                    && this.emailAddress.compareTo(((Personal)obj).emailAddress)==0)
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
        return new String(this.name + ", " + this.position + ", " +
                this.cellularPhoneNumber + ", " + this.emailAddress);
    }
    //getter 메소드
    //name 가져오기
    public String getName() { return this.name; }
    //position 가져오기
    public  String getPosition() { return this.position; }
    //cellularPhoneNumber 가져오기
    public String getCellularPhoneNumber() { return this.cellularPhoneNumber; }
    //emailAddress 가져오기
    public String getEmailAddress() { return  this.emailAddress; }
    //setter 메소드
    //position 변경하기
    public void setPosition(String position)
    {
        this.position = position;
    }
    //cellularPhone 변경하기
    public void setCellularPhoneNumber(String cellularPhoneNumber)
    {
        this.cellularPhoneNumber = cellularPhoneNumber;
    }
    //emailAddress 변경하기
    public void setEmailAddress(String emailAddress)
    {
        this.emailAddress = emailAddress;
    }
}
