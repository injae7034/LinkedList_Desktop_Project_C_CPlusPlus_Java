package VisitingCardBinder;

import java.util.ArrayList;
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
        //VistingCard 임시 저장소
        VisitingCard tempVisitingCard = null;
        //for each문으로 VisitingCard를 반복돌리면서 추가하기
        for (VisitingCard visitingCard : this.visitingCards)
        {
            tempVisitingCard = visitingCard.clone();
            visitingCardBinder.visitingCards.add(tempVisitingCard);
            visitingCardBinder.length++;
        }
        //복사본의 현재 명함 위치를 마지막 위치로 설정하기
        visitingCardBinder.current = visitingCardBinder.visitingCards.getLast();
        //복사본 반환
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
}
