package VisitingCardBinder;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    private static VisitingCardBinder visitingCardBinder;
    public static void main(String[] args) throws IOException
    {
        //메인테스트 시나리오
        //1. VisitingCardBinder 객체를 생성한다.
        visitingCardBinder = new VisitingCardBinder();
        //2. 외부파일이 있으면 외부파일에 있는 Personal과 Company 객체정보를 load한다.
        visitingCardBinder.load();
        //3. 메뉴화면을 출력한다.
        displayMenu();
        //4. 콘솔창에서 menu 번호를 입력을 받는다.
        Scanner scanner = new Scanner(System.in);
        int menuNumber = scanner.nextInt();
        //5. 입력한 menu 번호로 이동한다.
        while (menuNumber != 0)
        {
            switch (menuNumber)
            {
                case 1: formFoTakingIn(); break;
                case 2: formFoFinding(); break;
                case 3: formFoTakingOut(); break;
                case 4: visitingCardBinder.arrange(); break;
                case 5: visitingCardBinder.first(); break;
                case 6: visitingCardBinder.previous(); break;
                case 7: visitingCardBinder.next(); break;
                case 8: visitingCardBinder.last(); break;
                default: break;
            }
            displayMenu();
            menuNumber = scanner.nextInt();
        }
        visitingCardBinder.save();
    }

    public static void displayMenu()
    {
        System.out.println("\t명함철");
        System.out.println("\t==========================================");
        System.out.println("\t<명함>");
        System.out.println("\t------------------------------------------");
        System.out.println("\t(개인정보)");
        if(visitingCardBinder.getCurrent() != null)
        {
            System.out.printf("\t성명: %s\n", visitingCardBinder.getCurrent().getPersonalName());
            System.out.printf("\t직책: %s\n", visitingCardBinder.getCurrent().getPosition());
            System.out.printf("\t휴대폰번호: %s\n", visitingCardBinder.getCurrent().getCellularPhoneNumber());
            System.out.printf("\t이메일주소: %s\n", visitingCardBinder.getCurrent().getEmailAddress());
        }
        else
        {
            System.out.println("\t성명: ");
            System.out.println("\t직책: ");
            System.out.println("\t휴대폰번호: ");
            System.out.println("\t이메일주소: ");
        }
        System.out.println("\t------------------------------------------");
        System.out.println("\t(회사정보)");
        if(visitingCardBinder.getCurrent() != null)
        {
            System.out.printf("\t상호명: %s\n", visitingCardBinder.getCurrent().getCompanyName());
            System.out.printf("\t주소: %s\n", visitingCardBinder.getCurrent().getAddress());
            System.out.printf("\t전화번호: %s\n", visitingCardBinder.getCurrent().getTelephoneNumber());
            System.out.printf("\t팩스번호: %s\n", visitingCardBinder.getCurrent().getFaxNumber());
            System.out.printf("\t홈페이지주소: %s\n", visitingCardBinder.getCurrent().getUrl());
        }
        else
        {
            System.out.println("\t상호명: ");
            System.out.println("\t주소: ");
            System.out.println("\t전화번호: ");
            System.out.println("\t팩스번호: ");
            System.out.println("\t홈페이지주소: ");
        }
        System.out.println("\t==========================================");
        System.out.printf("\t[1] 끼 우 기\t\t").printf("\t[2] 찾   기\n");
        System.out.printf("\t[3] 꺼 내 기\t\t").printf("\t[4] 정리하기\n");
        System.out.printf("\t[5] 처    음\t\t").printf("\t[6] 이   전\n");
        System.out.printf("\t[7] 다    음\t\t").printf("\t[8] 마 지 막\n");
        System.out.println("\t[0] 명 함 철 프 로 그 램 종 료 하 기");
        System.out.println("\t------------------------------------------");
        System.out.printf("\t메뉴를 선택하십시오! ");
    }
    //[1] 끼우기
    public static void formFoTakingIn() throws IOException
    {
        //사용자로부터 콘솔창에 입려을 받기 위해 Scanner 생성하기
        Scanner scanner = new Scanner(System.in);
        String going = "Y";
        while (going.equals("Y") == true || going.equals("y") == true)
        {
            System.out.println();
            System.out.printf("\t명함철 - 끼 우 기\n");
            System.out.printf("\t==============================================\n");
            System.out.printf("\t성명 : ");
            String personalName = scanner.nextLine();
            System.out.printf("\t직책 : ");
            String position = scanner.nextLine();
            System.out.printf("\t휴대폰번호 : ");
            String cellularPhoneNumber = scanner.nextLine();
            System.out.printf("\t이메일주소 : ");
            String emailAddress = scanner.nextLine();
            System.out.printf("\t상호명 : ");
            String companyName = scanner.nextLine();
            String address;
            String telephoneNumber;
            String faxNumber;
            String url;
            //상호명으로 찾는다.
            VisitingCard visitingCard = visitingCardBinder.findCompanyName(companyName);
            //찾은 상호명이 있으면(명함철에 해당 상호명의 회사 정보가 이미 있으면)
            if(visitingCard != null)
            {
                address = visitingCard.getAddress();
                System.out.printf("\t주소 : %s\n", address);
                telephoneNumber = visitingCard.getTelephoneNumber();
                System.out.printf("\t전화번호 : %s\n", telephoneNumber);
                faxNumber = visitingCard.getFaxNumber();
                System.out.printf("\t팩스번호 : %s\n", faxNumber);
                url = visitingCard.getUrl();
                System.out.printf("\t홈페이지주소 : %s\n", url);
            }
            //찾은 상호명이 없으면(명함철에 해당 상호명의 회사 정보가 없으면)
            else
            {
                System.out.printf("\t주소 : ");
                address = scanner.nextLine();
                System.out.printf("\t전화번호 : ");
                telephoneNumber = scanner.nextLine();
                System.out.printf("\t팩스번호 : ");
                faxNumber = scanner.nextLine();
                System.out.printf("\t홈페이지주소 : ");
                url = scanner.nextLine();
            }
            System.out.printf("\t----------------------------------------------\n");
            System.out.printf("\t명함을 끼우시겠습니까?(Y/N) ");
            String recording = scanner.nextLine();
            if (recording.equals("Y") == true || recording.equals("y") == true)
            {
                //명함을 생성한다.
                visitingCard = new VisitingCard(personalName, position,
                        cellularPhoneNumber, emailAddress, companyName, address,
                        telephoneNumber, faxNumber, url);
                //명함을 끼운다.
                visitingCard = visitingCardBinder.takeIn(visitingCard);
                //반복문을 벗어난다.
                break;
            }
            System.out.printf("\t============================================================================\n");
            System.out.printf("\t계속하시겠습니까?(Y/N) ");
            going = scanner.nextLine();
        }
    }
    //[2] 찾기
    public static void formFoFinding()
    {
        //사용자로부터 콘솔창에 입려을 받기 위해 Scanner 생성하기
        Scanner scanner = new Scanner(System.in);
        String going = "Y";
        while (going.equals("Y") == true || going.equals("y") == true)
        {
            System.out.println();
            System.out.printf("\t명함철 - 찾기\n");
            System.out.println();
            System.out.printf("\t성명 : ");
            String name = scanner.nextLine();
            System.out.println();
            ArrayList<VisitingCard> indexes = visitingCardBinder.find(name);
            //찾은게 있으면
            if(indexes.size() > 0)
            {
                String personalName;
                String position;
                String cellularPhoneNumber;
                String emailAddress;
                String companyName;
                String address;
                String telephoneNumber;
                String faxNumber;
                String url;
                for(int i = 0; i < indexes.size(); i++)
                {
                    VisitingCard visitingCard = indexes.get(i);
                    personalName = visitingCard.getPersonalName();
                    position = visitingCard.getPosition();
                    cellularPhoneNumber = visitingCard.getCellularPhoneNumber();
                    emailAddress = visitingCard.getEmailAddress();
                    companyName = visitingCard.getCompanyName();
                    address = visitingCard.getAddress();
                    telephoneNumber = visitingCard.getFaxNumber();
                    faxNumber = visitingCard.getFaxNumber();
                    url = visitingCard.getUrl();
                    System.out.printf("\t*번호: %d, *성명 : %s, *직책 : %s, *휴대폰번호 : %s, *이메일주소 : %s,\n" +
                                    "\t*상호명 : %s, *주소 : %s, *전화번호 : %s, *팩스번호 : %s, *홈페이지주소 : %s\n",
                            i + 1, personalName, position, cellularPhoneNumber, emailAddress,
                            companyName, address, telephoneNumber, faxNumber, url);
                    System.out.println();
                }
                System.out.printf("\t찾은 명함을 선택하시겠습니까?(Y/N) ");
                String choosing = scanner.nextLine();
                if(choosing.equals("Y") == true || choosing.equals("y") == true)
                {
                    while(true)
                    {
                        System.out.printf("\t번호 : ");
                        //nextInt대신에 nextLine을 써야 뒤에서 탈이 안남.
                        String stringIndex = scanner.nextLine();
                        int index = Integer.valueOf(stringIndex);
                        //배열첨자는 0부터 시작하기 때문에 사용자가 선택한 번호에서 -1해줘야함!
                        index--;
                        //번호를 제대로 눌렀으면(번호가 배열길이를 넘지 않고 음수가 아니면)
                        if(index < indexes.size() && index >= 0)
                        {
                            //현재 명함을 찾은 명함으로 이동한다.(바꾼다.)
                            visitingCardBinder.move(indexes.get(index));
                            //메소드 종료
                            return;
                        }
                        //번호를 잘못눌렀으면
                        else
                        {
                            System.out.println("\t번호를 잘못 선택하셨습니다.");
                            System.out.println("\t다시 번호를 선택해주세요.");
                        }
                    }
                }
            }
            //찾은게 없으면
            else
            {
                System.out.println("\t명함철에서 찾고자 하는 성명의 명함이 없습니다.");
            }
            System.out.println();
            System.out.printf("\t계속하시겠습니까?(Y/N) ");
            going = scanner.nextLine();
        }
    }
    //[3] 꺼내기
    public static void formFoTakingOut()
    {
        //현재 명함이 있으면
        if(visitingCardBinder.getCurrent() != null)
        {
            //명함철에서 현재 명함을 꺼낸다.
            VisitingCard visitingCard = visitingCardBinder.takeOut(visitingCardBinder.getCurrent());
            //사용자로부터 콘솔창에 입려을 받기 위해 Scanner 생성하기
            Scanner scanner = new Scanner(System.in);
            System.out.println();
            System.out.printf("\t명함철 - 꺼내기\n");
            System.out.println("\t==========================================");
            System.out.println("\t<명함>");
            System.out.println("\t------------------------------------------");
            System.out.println("\t(개인정보)");
            System.out.printf("\t성명: %s\n", visitingCard.getPersonalName());
            System.out.printf("\t직책: %s\n", visitingCard.getPosition());
            System.out.printf("\t휴대폰번호: %s\n", visitingCard.getCellularPhoneNumber());
            System.out.printf("\t이메일주소: %s\n", visitingCard.getEmailAddress());
            System.out.println("\t------------------------------------------");
            System.out.println("\t(회사정보)");
            System.out.printf("\t상호명: %s\n", visitingCard.getCompanyName());
            System.out.printf("\t주소: %s\n", visitingCard.getAddress());
            System.out.printf("\t전화번호: %s\n", visitingCard.getTelephoneNumber());
            System.out.printf("\t팩스번호: %s\n", visitingCard.getFaxNumber());
            System.out.printf("\t홈페이지주소: %s\n", visitingCard.getUrl());
            System.out.println("\t==========================================");
            System.out.printf("\t명함을 다시 명함철에 끼우시겠습니까?(Y/N) ");
            String takingInAgain = scanner.nextLine();
            if (takingInAgain.equals("Y") == true || takingInAgain.equals("y") == true)
            {
                //꺼낸 명함을 다시 명함철에 끼운다.
                visitingCardBinder.takeIn(visitingCard);
            }
        }
    }
}
