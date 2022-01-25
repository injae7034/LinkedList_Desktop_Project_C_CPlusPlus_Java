package VisitingCardBinder;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;

public class VisitingCardBinder implements Cloneable
{
    //인스턴트 필드멤버
    private LinkedList<VisitingCard> visitingCards;
    private VisitingCard current;//명함철에서 현재 카드
    private int length;
    //디폴트 생성자
    public VisitingCardBinder()
    {
        this.visitingCards = new LinkedList<VisitingCard>();
        this.current = null;
        this.length = 0;
    }
    //clone 메소드 오버라이딩하기
    @Override
    public VisitingCardBinder clone() throws CloneNotSupportedException
    {
        //복사할 대상 생성
        VisitingCardBinder visitingCardBinder = new VisitingCardBinder();
        //for each문으로 VisitingCard를 마지막까지 반복하기
        for (VisitingCard visitingCard : this.visitingCards)
        {
            //VisitingCard를 clone한 반환값(VisitingCard복사본)을 명함철(복사본)에 추가하기
            visitingCardBinder.visitingCards.add(visitingCard.clone());
            //명함철(복사본)의 현재 위치를 마지막 명함위치로 설정하기
            visitingCardBinder.current = visitingCardBinder.visitingCards.getLast();
            //명함철(복사본)의 길이를 증가시키기
            visitingCardBinder.length++;
        }
        //명함철(복사본) 반환
        return visitingCardBinder;
    }
    //TakeIn
    public VisitingCard takeIn(VisitingCard visitingCard)
    {
        //LinkedList에 매개변수로 입력 받은 VisitingCard객체를 순차적으로 끼운다.
        this.visitingCards.add(visitingCard);
        //개수를 증가시킨다.
        this.length++;
        //현재 명함의 위치를 저장한다.
        this.current = this.visitingCards.getLast();
        //끼운 명함을 출력한다.
        return this.current;
    }
    //find(개인 이름을 기준으로 명함철에서 명함찾기)(개인의 이름은 중복이 있을 수 있음)
    public ArrayList<VisitingCard> find(String personalName)
    {
        //찾고자 하는 이름과 같은 이름을 가진 명함의 참조변수값을 저장할 ArrayList 생성하기
        ArrayList<VisitingCard> indexes = new ArrayList<VisitingCard>();
        //for each 구문을 통해 처음부터 끝까지 반복을 돌리면서 찾고자 하는 이름과
        //같은 이름을 가진 명함의 참조변수값을 indexes에 저장하기
        for (VisitingCard visitingCard : this.visitingCards)
        {
            if(personalName.compareTo(visitingCard.getPersonalName()) == 0)
            {
                indexes.add(visitingCard);
            }
        }
        //결과를 반환한다.
        return indexes;
    }
    //findCompanyName(명함철에 해당 상호명이 있는지 확인)(상호명은 중복이 있을 수 없음)
    public VisitingCard findCompanyName(String companyName)
    {
        //for each 구문을 통해 처음부터 끝까지 반복을 돌리면서 찾고자 하는 이름과 같은 이름이 있으면 탈출
        for(VisitingCard visitingCard : this.visitingCards)
        {
            if(companyName.compareTo(visitingCard.getCompanyName()) == 0)
            {
                //같은 이름이 있으면 해당 명함을 출력
                return visitingCard;
            }
        }
        //명함철에 해당 상호명이 없으면 null출력
        return null;
    }
    //takeOut
    public VisitingCard takeOut(VisitingCard visitingCard)
    {
        //명함철에서 꺼내려고 하는 vistingCard 위치구하기
        int index = this.visitingCards.indexOf(visitingCard);
        //명함철에서 꺼내려고 하는 카드가 처음이 아니면
        if(index > 0)
        {
            //현재 카드 위치를 이전 위치로 정한다.
            this.current = this.visitingCards.get(index - 1);
        }
        //명함철에서 꺼내려는 카드가 처음 명함이면
        else
        {
            //명함철 개수가 1개 이상이면(현재 카드를 빼도 명함철에 카드가 남아있으면)
            if(this.visitingCards.size() > 1)
            {
                //다음 카드 위치를 현재 카드위치로 정한다.
                this.current = this.visitingCards.get(index + 1);
            }
            //명함철에 현재 명함이 1개라서 이 카드를 빼면 더이상 명함이 없을 경우
            else
            {
                this.current = null;
            }
        }
        //해당 명함을 명함철에서 꺼낸다.
        boolean flag = this.visitingCards.remove(visitingCard);
        //개수를 감소시킨다.
        this.length--;
        if(flag == true)
        {
            return visitingCard;
        }
        else
        {
            return null;
        }
    }
    //Move(현재 명함의 위치를 해당 명함으로 이동한다.)
    public VisitingCard move(VisitingCard visitingCard)
    {
        //입력받은 명함이 명함철에서 어디에 위치하는지 구하기
        int index = this.visitingCards.indexOf(visitingCard);
        //해당 명함을 현재 위치로 정하기
        this.current = this.visitingCards.get(index);
        //현재 위치를 출력하기
        return this.current;
    }
    //first(현재 명함의 위치를 처음으로 이동시킨다.)
    public VisitingCard first()
    {
        //현재 위치를 처음으로 이동시키기
        this.current = this.visitingCards.getFirst();
        //현재 위치를 출력하기
        return this.current;
    }
    //last(현재 명함의 위치를 마지막으로 이동시킨다.)
    public VisitingCard last()
    {
        //현재 위치를 마지막으로 이동시키기
        this.current = this.visitingCards.getLast();
        //현재 위치를 출력하기
        return this.current;
    }
    //previous(현재 명함의 위치 이전으로 이동시킨다.)
    public VisitingCard previous()
    {
        //현재 위치 index를 구하기
        int index = this.visitingCards.indexOf(this.current);
        //현재 위치가 첫번째 명함이 아니면
        if(index > 0)
        {
            //현재 카드를 이전으로 이동시킨다.
            this.current = this.visitingCards.get(index - 1);
        }
        //현재 카드 위치를 출력한다.
        return this.current;
    }
    //next(현재 명함의 위치를 다음으로 이동시킨다.)
    public VisitingCard next()
    {
        //현재 위치 index 구하기
        int index = this.visitingCards.indexOf(this.current);
        //현재 위치가 마지막 명함이 아니면
        int lastIndex = this.visitingCards.size() - 1;
        if(index < lastIndex)
        {
            //현재 카드를 다음으로 이동시킨다.
            this.current = this.visitingCards.get(index + 1);
        }
        //현재 카드 위치를 출력한다.
        return this.current;
    }
    //명함철에 끼운 전체 명함 출력하기(테스트에서 중복을 줄이기 위해)
    public void printAllVisitingCards()
    {
        int index = 1;
        for (VisitingCard visitingCard: this.visitingCards)
        {
            System.out.printf("%s%d","< ", index).println("번째 명함: " + visitingCard + " >");
            index++;
        }
    }
    //현재 명함 위치 구하기
    public VisitingCard getCurrent() { return this.current; }
    //현재 개수 구하기
    public int getLength() { return this.length; }
    //visitingCards 구하기
    public LinkedList<VisitingCard> getVisitingCards() { return this.visitingCards; }

    /*
    //외부 파일에 있는 정보를 읽어서 VisitingCardBinder에 Load하기(substring사용하기)
    public int load()
    {
        //해당위치에 있는 data를 읽어 File객체를 생성한다.
        File personalFile = new File("Personal.txt");
        File companyFile = new File("Company.txt");
        //해당 위치에 파일이 존재하면
        if(personalFile.exists() == true && companyFile.exists() == true)
        {
            //입력을 위한 스트림을 생성한다.
            try(Reader personalReader = new FileReader(personalFile);
                BufferedReader personalBufferedReader = new BufferedReader(personalReader);
                RandomAccessFile companyAccessFile = new RandomAccessFile("Company.txt", "r");)
            {
                VisitingCard visitingCard = null;//visitingCard를 임시저장할 공간
                //줄단위(Personal 객체단위)로 읽는다.
                int beginIndex = 0;//시작위치를 저장할 임시공간
                int endIndex = 0;//콤마(,)위치를 저장할 임시공간(,단위로 필드가 구분됨)
                String personalInformation = "";//한줄단위로 읽은 개인 데이터를 저장할 임시공간
                String companyCode;//한줄단위로 읽은 데이터 중에서 개인의 회사코드를 저장할 임시공간
                int code = 0;//한줄단위로 읽은 데이터 중에서 개인흐 회사코드를 정수로 변경할 공간
                String personalName;//한줄단위로 읽은 데이터 중에서 이름을 저장할 임시공간
                String position;//한줄단위로 읽은 데이터 중에서 직책을 저장할 임시공간
                String cellularPhoneNumber;//한줄단위로 읽은 데이터 중에서 휴대폰번호를 저장할 임시공간
                String emailAddress;//한줄단위로 읽은 데이터 중에서 이메일주소를 저장할 임시공간
                String companyInformation = "";//한줄단위로 읽은 회사 데이터를 저장할 임시공간
                String companyName;//한줄단위로 읽은 데이터 중에서 상호를 저장할 임시공간
                String address;//한줄단위로 읽은 데이터 중에서 주소를 저장할 임시공간
                String telephoneNumber;//한줄단위로 읽은 데이터 중에서 전화번호를 저장할 임시공간
                String faxNumber;//한줄단위로 읽은 데이터 중에서 팩스번호를 저장할 임시공간
                String url;//한줄단위로 읽은 데이터 중에서 홈페이지주소를 저장할 임시공간
                int i = 0;//반복제어변수
                //개인데이터를 파일의 마지막까지 읽는다.
                while((personalInformation = personalBufferedReader.readLine()) != null)
                {
                    //시작위치를 초기화한다.
                    beginIndex = 0;
                    //personalInformaion에서 처음부터 시작해서 ","의 위치를 찾는다.
                    endIndex = personalInformation.indexOf(",");
                    //companyCode 문자열을 구한다.
                    companyCode = personalInformation.substring(beginIndex, endIndex);
                    //companyCode 문자열을 정수로 바꿔준다.
                    code = Integer.parseInt(companyCode);
                    //회사파일을 파일의 처음으로 이동시킨다.
                    companyAccessFile.seek(0);
                    //companyCode까지 반복하면서 그리고 회사파일이 끝이 아닐동안 반복한다.
                    i = 0;
                    while(i < code && (companyInformation = companyAccessFile.readLine()) != null)
                    {
                       i++;
                    }
                    //읽은 외부데이터로부터 개인의 정보를 구한다.
                    //","위치 다음을 시작위치로 재설정한다.
                    beginIndex = endIndex + 1;
                    //재설정한 시작위치부터 다음 ","위치를 찾는다.
                    endIndex = personalInformation.indexOf(",", beginIndex);
                    //personalName 문자열을 구한다.
                    personalName = personalInformation.substring(beginIndex, endIndex);
                    //","위치 다음을 시작위치로 재설정한다.
                    beginIndex = endIndex + 1;
                    //재설정한 시작위치부터 다음 ","위치를 찾는다.
                    endIndex = personalInformation.indexOf(",", beginIndex);
                    //position 문자열을 구한다.
                    position = personalInformation.substring(beginIndex, endIndex);
                    //","위치 다음을 시작위치로 재설정한다.
                    beginIndex = endIndex + 1;
                    //재설정한 시작위치부터 다음 ","위치를 찾는다.
                    endIndex = personalInformation.indexOf(",", beginIndex);
                    //cellularPhoneNumber를 구한다.
                    cellularPhoneNumber = personalInformation.substring(beginIndex, endIndex);
                    //","위치 다음을 시작위치로 재설정한다.
                    beginIndex = endIndex + 1;
                    //emailAddress를 구한다.
                    emailAddress = personalInformation.substring(beginIndex);
                    //읽은 외부데이터로부터 회사의 정보를 구한다.
                    //RandomAcceesFile의 경우 앞의 2자리는 자리수를 나타내기 때문에 2부터 초기화하여 시작한다.
                    beginIndex = 2;
                    //한글이 깨지기 때문에 이를 안깨지게 정상화처리해줌
                    companyInformation = new String(companyInformation.
                            getBytes("iso-8859-1"), "utf-8");
                    //companyInformaion에서 처음부터 시작해서 ","의 위치를 찾는다.
                    endIndex = companyInformation.indexOf(",");
                    //comanyName 문자열을 구한다.
                    companyName = companyInformation.substring(beginIndex, endIndex);
                    //","위치 다음을 시작위치로 재설정한다.
                    beginIndex = endIndex + 1;
                    //재설정한 시작위치부터 다음 ","위치를 찾는다.
                    endIndex = companyInformation.indexOf(",", beginIndex);
                    //address 문자열을 구한다.
                    address = companyInformation.substring(beginIndex, endIndex);
                    //","위치 다음을 시작위치로 재설정한다.
                    beginIndex = endIndex + 1;
                    //재설정한 시작위치부터 다음 ","위치를 찾는다.
                    endIndex = companyInformation.indexOf(",", beginIndex);
                    //telephoneNumber 문자열을 구한다.
                    telephoneNumber = companyInformation.substring(beginIndex, endIndex);
                    //","위치 다음을 시작위치로 재설정한다.
                    beginIndex = endIndex + 1;
                    //재설정한 시작위치부터 다음 ","위치를 찾는다.
                    endIndex = companyInformation.indexOf(",", beginIndex);
                    //faxNumber 문자열을 구한다.
                    faxNumber = companyInformation.substring(beginIndex, endIndex);
                    //","위치 다음을 시작위치로 재설정한다.
                    beginIndex = endIndex + 1;
                    //url 문자열을 구한다.
                    url = companyInformation.substring(beginIndex);
                    //외부에서 읽은 개인의 정보와 회사의 정보로 명함을 생성한다.
                    visitingCard = new VisitingCard(personalName, position, cellularPhoneNumber,
                            emailAddress, companyName, address, telephoneNumber, faxNumber, url);
                    //명함을 명함철에 끼운다.
                    this.takeIn(visitingCard);
                }
            } catch (IOException e) { e.printStackTrace(); }
        }
        //load한 명함 수를 반환한다.
        return this.length;
    }
     */

    //외부 파일에 있는 정보를 읽어서 VisitingCardBinder에 Load하기(split사용하기)
    public int load()
    {
        //해당위치에 있는 data를 읽어 File객체를 생성한다.
        File personalFile = new File("Personal.txt");
        File companyFile = new File("Company.txt");
        //해당 위치에 파일이 존재하면
        if(personalFile.exists() == true && companyFile.exists() == true)
        {
            //입력을 위한 스트림을 생성한다.
            try(Reader personalReader = new FileReader(personalFile);
                BufferedReader personalBufferedReader = new BufferedReader(personalReader);
                RandomAccessFile companyAccessFile = new RandomAccessFile("Company.txt", "r");)
            {
                VisitingCard visitingCard = null;//visitingCard를 임시저장할 공간
                String personalInformation = "";//한줄단위로 읽은 개인 데이터를 저장할 임시공간
                String companyInformation = "";//한줄단위로 읽은 회사 데이터를 저장할 임시공간
                String[] personalTokens = null;//한줄단위로 읽은 개인데이터를 콤마단위로 분리해서 저장하는 배열
                String[] companyTokens = null;//한줄단위로 읽은 회사데이터를 콤마단위로 분리해서 자장하는 배열
                int companyCode = 0;//한줄단위로 읽은 데이터 중에서 개인의 회사코드를 정수로 변경할 공간
                int i = 0;//반복제어변수
                //개인데이터를 파일의 마지막까지 읽는다.
                while((personalInformation = personalBufferedReader.readLine()) != null)
                {
                    //한줄 단위로 읽은 개인데이터를 콤마(,)단위로 분리해서 문자열 배열에 저장한다.
                    personalTokens = personalInformation.split(",");
                    //분리한 개인데이터의 개수가 5이면
                    if(personalTokens.length == 5)
                    {
                        //companyCode를 정수로 바꿔준다.
                        companyCode = Integer.parseInt(personalTokens[0]);
                        //회사파일을 파일의 처음으로 이동시킨다.
                        companyAccessFile.seek(0);
                        //companyCode까지 반복하면서 그리고 회사파일이 끝이 아닐동안 반복한다.
                        i = 0;
                        while(i < companyCode &&
                                (companyInformation = companyAccessFile.readLine()) != null)
                        {
                            i++;
                        }
                        //RandomAccessFile로 읽으면 한글이 깨지기 때문에 이를 안깨지게 정상화처리해줌
                        companyInformation = new String(companyInformation.
                                getBytes("iso-8859-1"), "utf-8");
                        //RandomAccessFile로 읽으면 앞의 2자리는 자리수를 의미하는데 이를 제외시킴.
                        companyInformation = companyInformation.substring(2);
                        //한줄 단위로 읽은 회사데이터를 콤마(,)단위로 분리해서 문자열 배열에 저장한다.
                        companyTokens = companyInformation.split(",");
                        //분리한 회사 데이터가 5개이면
                        if(companyTokens.length == 5)
                        {
                            //외부에서 읽은 개인의 정보와 회사의 정보로 명함을 생성한다.
                            visitingCard = new VisitingCard(personalTokens[1], personalTokens[2],
                                    personalTokens[3], personalTokens[4], companyTokens[0],
                                    companyTokens[1], companyTokens[2], companyTokens[3], companyTokens[4]);
                            //명함을 명함철에 끼운다.
                            this.takeIn(visitingCard);
                        }
                    }
                }
            } catch (IOException e) { e.printStackTrace(); }
        }
        //load한 명함 수를 반환한다.
        return this.length;
    }

    //명함철에 있는 명함 정보를 외부파일에 저장하기
    public void save()
    {
        //해당위치에 있는 data를 읽어 File객체를 생성한다.
        File personalFile = new File("Personal.txt");
        //출력을 위한 스트림을 생성한다.
        try(Writer personalWriter = new FileWriter(personalFile);
            BufferedWriter personalBufferedWriter = new BufferedWriter(personalWriter);
            RandomAccessFile companyAccessFile = new RandomAccessFile("Company.txt", "rw");)
        {
            String companyInformation = "";//외부파일에서 회사정보를 담을 공간
            int companyCode = 0;//회사코드로 사용
            //명함철의 마지막 명함까지 반복한다.
            for(VisitingCard visitingCard : this.visitingCards)
            {
                //외부의 회사데이터 파일을 처음으로 이동시킨다.
                companyAccessFile.seek(0);
                //코드를 초기화시킨다.
                companyCode = 1;
                //외부 회사데이터 파일이 마지막이 아닌 동안 반복한다.
                while((companyInformation = companyAccessFile.readLine()) != null)
                {
                    //한글이 깨지기 때문에 이를 안깨지게 정상화처리해줌
                    companyInformation = new String(companyInformation.
                            getBytes("iso-8859-1"), "utf-8");
                    //RandomAccess의 writeUTF는 앞에 2byte에 길이를 같이 써서 출력하기 때문에
                    //상호 앞에 이를 제외하고 읽어야함.
                    // 외부 회사파일의 상호명과 명함철에서 읽은 명함의 상호명과 서로 같으면
                    if(companyInformation.substring(2, companyInformation.indexOf(","))
                            .equals(visitingCard.getCompanyName()) == true)
                    {
                        break;
                    }
                    //회사의 코드를 증가시킨다.
                    companyCode++;
                }
                //파일의 마지막이면(명함철에서 읽은 명함의 상호명이 외부 회사파일의 상호명에 없으면)
                if(companyInformation == null)
                {
                    //외부 회사파일에 중복이 안된 명함의 회사 정보를 출력한다.
                    companyAccessFile.writeUTF(visitingCard.getCompanyName()+ ","
                            + visitingCard.getAddress() + "," + visitingCard.getTelephoneNumber() +
                            "," + visitingCard.getFaxNumber() + "," + visitingCard.getUrl() + "\n");
                }
                //외부 개인파일에 개인 정보를 출력한다.
                personalBufferedWriter.write(companyCode + "," +
                        visitingCard.getPersonalName() + "," + visitingCard.getPosition() + "," +
                        visitingCard.getCellularPhoneNumber() + "," + visitingCard.getEmailAddress() + "\n");
            }
            personalBufferedWriter.flush();
        } catch (IOException e) { e.printStackTrace(); }
    }
    //이름기준으로 오름차순으로 정렬하기
    public void arrange()
    {
        Collections.sort(this.visitingCards, new Comparator<VisitingCard>() {
            @Override
            public int compare(VisitingCard one, VisitingCard other)
            {
                return one.getPersonalName().compareTo(other.getPersonalName());
            }
        });
        //현재 명함을 정렬한 후 제일 처음 명함으로 설정한다.
        this.current = this.visitingCards.getFirst();
    }
}
