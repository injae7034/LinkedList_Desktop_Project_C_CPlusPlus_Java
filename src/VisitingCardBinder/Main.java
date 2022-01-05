package VisitingCardBinder;

import java.io.IOException;
import java.sql.*;
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
        //visitingCardBinder.load();
        load();
        //load한게 있으면
        if(visitingCardBinder.getLength() > 0)
        {
            visitingCardBinder.first();
        }
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
        //visitingCardBinder.save();
        save();
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
                //명함철에 명함을 끼운다.
                visitingCard = visitingCardBinder.takeIn(visitingCard);
                //데이터베이스에 명함 데이터를 추가한다.
                insert(visitingCard);
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
            //데이터베이스에서 현재 명함의 데이터를 지운다.
            delete(visitingCard);
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
                visitingCard = visitingCardBinder.takeIn(visitingCard);
                //꺼낸 명함을 다시 데이터베이스에 저장한다.
                insert(visitingCard);
            }
        }
    }
    //데이터베이스 응용프로그래밍 시작
    //load
    public static void load()
    {
        //디스크파일에서는 Personl데이터 파일과 Company데이터 파일이 각각 따로 저장되어 있어서 load할 때
        //개인의 정보와 일치하는 회사정보를 찾기 위한 일련의 과정(반복)이 필요했는데 MySQL에서는 아래처럼
        //INNNER JOIN 시키면 자동으로 개인 정보와 이에 일치하는 회사정보를 한번에 구할 수 있음!
        String sql = "SELECT Company.name, Company.address, Company.telephoneNumber," +
                " Company.faxNumber, Company.url, Personal.name, Personal.position, " +
                "Personal.cellularPhoneNumber, Personal.emailAddress " +
                "FROM Company INNER JOIN Personal ON Company.companyCode = Personal.companyCode" +
                " ORDER BY Personal.code;";
        try(//Connection(데이터베이스와 연결을 위한 객체)생성 - getConnection(연결문자열, DB-ID, DB-PW)
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306" +
                    "/VisitingCardBinder?serverTimezone=Asia/Seoul", "root", "1q2w3e");
            //Statement(일회성 SQL 문을 데이터베이스에 보내기위한 객체)생성
            Statement stmt = con.createStatement();
            //sql 문장을 실행하고 결과를 리턴
            //ResultSet(SQL 질의에 의해 생성된 테이블을 저장하는 객체)
            //이제 rs에는 쿼리문에 의해서 찾은 DB의 전체 Comapany, Personal 데이터가 저장됨.
            ResultSet rs = stmt.executeQuery(sql);)
        {
            String companyName;
            String address;
            String telephoneNumber;
            String faxNumber;
            String url;
            String personalName;
            String position;
            String cellularPhoneNumber;
            String emailAddress;
            VisitingCard visitingCard = null;
            //rs에 저장된 데이터가 끝날때까지 반복한다.
            while(rs.next())
            {
                //rs에서 각 필드들의 데이터를 읽는다.
                companyName = rs.getString(1);
                address = rs.getString(2);
                telephoneNumber = rs.getString(3);
                faxNumber = rs.getString(4);
                url = rs.getString(5);
                personalName = rs.getString(6);
                position = rs.getString(7);
                cellularPhoneNumber = rs.getString(8);
                emailAddress = rs.getString(9);
                //읽은 데이터를 바탕으로 새로운 명함을 생성한다.
                visitingCard = new VisitingCard(personalName, position, cellularPhoneNumber,
                        emailAddress, companyName, address, telephoneNumber, faxNumber, url);
                //새로 생성한 명함을 명함철에 끼운다.
                visitingCardBinder.takeIn(visitingCard);
            }
        }
        catch (SQLException e)
        {
            System.out.println("[SQL Error : " + e.getMessage() +"]");
        }
    }
    //save
    public static void save()
    {
        String sql = "SELECT Company.companyCode, Personal.code FROM Company INNER JOIN Personal " +
        "ON Company.companyCode=Personal.companyCode ORDER BY Personal.code;";
        String sql2 = "DELETE FROM Personal;";
        //Company는 Personal이 먼저 다 지워지기전에는 지울수없음. 따라서 Personal을 먼저 다 지워야함.
        String sql3 = "DELETE FROM Company;";
        try(//Connection(데이터베이스와 연결을 위한 객체)생성 - getConnection(연결문자열, DB-ID, DB-PW)
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306" +
                    "/VisitingCardBinder?serverTimezone=Asia/Seoul", "root", "1q2w3e");
            //Statement(일회성 SQL 문을 데이터베이스에 보내기위한 객체)생성
            Statement stmt = con.createStatement();
            //ResultSet(SQL 질의에 의해 생성된 테이블을 저장하는 객체)생성
            //rs는 db의 Company와 Personal의 전체 코드를 테이블형식으로 저장함.
            ResultSet rs = stmt.executeQuery(sql);
            //PreStatement(여러번 SQL 문을 데이터베이스에 보내기위한 객체)생성
            //Statement stmt2 = con.createStatement();
            PreparedStatement pstmt = con.prepareStatement(sql2);
            PreparedStatement pstmt2 = con.prepareStatement(sql3);)
        {
            //DB에 있는 Personal 객체 정보들을 모두 지움.
            pstmt.executeUpdate();
            //DB에 있는 Company 객체 정보를  모두 지움.
            pstmt2.executeUpdate();
            String companyCode;//회사코드를 저장할 임시공간
            String personalCode;//개인코드를 저장할 임시공간
            String sql4;
            //for each 구문을 통해 명함철의 처음 명함부터 마지막 명함까지 반복한다.
            for (VisitingCard visitingCard : visitingCardBinder.getVisitingCards())
            {
                //rs를 이동시켜준다.
                rs.next();
                //rs에서 companyCode를 구한다.
                companyCode = rs.getString(1);
                //rs에서 구한 companyCode로 db에서 해당코드가 있는지 찾는 쿼리문 만들기
                sql4 = String.format("SELECT Company.name FROM Company WHERE companyCode = '%s';",
                        companyCode);
                //rs2를 새로 생성하여 companyCode로 찾은 상호명을 저장함.
                try(ResultSet rs2 = pstmt.executeQuery(sql4);)
                {
                    //rs에 저장된 데이터가 없으면(해당 companyCode가 db에 없으면)
                    if(rs2.next() == false)
                    {
                        //db에 새로운 회사정보를 추가한다.
                        sql4 = String.format("INSERT INTO Company(name, address," +
                                        " telephoneNumber, faxNumber, url, companyCode) " +
                                "VALUES('%s', '%s', '%s', '%s', '%s', '%s');",
                                visitingCard.getCompanyName(), visitingCard.getAddress(),
                                visitingCard.getTelephoneNumber(), visitingCard.getFaxNumber(),
                                visitingCard.getUrl(), companyCode);
                        pstmt.executeUpdate(sql4);
                    }
                }
                personalCode = rs.getString(2);
                sql4 = String.format("INSERT INTO Personal(name, position," +
                                " cellularPhoneNumber, emailAddress, code, companyCode) " +
                        "VALUES('%s', '%s', '%s', '%s', '%s', '%s');",
                        visitingCard.getPersonalName(), visitingCard.getPosition(),
                        visitingCard.getCellularPhoneNumber(), visitingCard.getEmailAddress(),
                        personalCode, companyCode);
                pstmt.executeUpdate(sql4);
            }
        }
        catch (SQLException e)
        {
            System.out.println("[SQL Error : " + e.getMessage() +"]");
        }
    }
    //getCompanyCode
    public static String getCompanyCode()
    {
        String code = "C0000";
        String newCode = null;
        String sql = "SELECT Company.companyCode FROM Company;";
        try(//Connection(데이터베이스와 연결을 위한 객체)생성 - getConnection(연결문자열, DB-ID, DB-PW)
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306" +
                    "/VisitingCardBinder?serverTimezone=Asia/Seoul", "root", "1q2w3e");
            // Statement 객체 생성 및 move를 단방향이 아닌 자유롭게 할 수 있도록 하기 위한 조치
            Statement stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,
                    ResultSet.CONCUR_UPDATABLE);
            //ResultSet(SQL 질의에 의해 생성된 테이블을 저장하는 객체)생성
            //rs는 Personal의 전체 코드를 가지게 됨.
            ResultSet rs = stmt.executeQuery(sql);)
        {
            int number;
            //rs에서 마지막으로 이동한 후에 저장된 데이터가 있으면
            if(rs.last())
            {
                //마지막 코드를 저장한다.
                code = rs.getString(1);
            }
            code = code.substring(1,5);
            number = Integer.parseInt(code);
            number++;
            newCode = String.format("C%04d", number);
        }
        catch (SQLException e)
        {
            System.out.println("[SQL Error : " + e.getMessage() +"]");
        }
        return newCode;
    }
    //getPersonalCode
    public static String getPersonalCode()
    {
        String code = "P0000";
        String newCode = null;
        String sql = "SELECT Personal.code FROM Personal;";
        try(//Connection(데이터베이스와 연결을 위한 객체)생성 - getConnection(연결문자열, DB-ID, DB-PW)
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306" +
                    "/VisitingCardBinder?serverTimezone=Asia/Seoul", "root", "1q2w3e");
            // Statement 객체 생성 및 move를 단방향이 아닌 자유롭게 할 수 있도록 하기 위한 조치
            Statement stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,
                    ResultSet.CONCUR_UPDATABLE);
            //ResultSet(SQL 질의에 의해 생성된 테이블을 저장하는 객체)생성
            //rs는 Personal의 전체 코드를 가지게 됨.
            ResultSet rs = stmt.executeQuery(sql);)
        {
            int number;
            //rs에서 마지막으로 이동한 후에 저장된 데이터가 있으면
            if(rs.last())
            {
                //마지막 코드를 저장한다.
                code = rs.getString(1);
            }
            code = code.substring(1,5);
            number = Integer.parseInt(code);
            number++;
            newCode = String.format("P%04d", number);
        }
        catch (SQLException e)
        {
            System.out.println("[SQL Error : " + e.getMessage() +"]");
        }
        return newCode;
    }
    //insert
    public static void insert(VisitingCard visitingCard)
    {
        //입력받은 명함의 정보로 DB에서 해당하는 회사코드가 있는지 찾는 쿼리문생성
        String sql = String.format("SELECT Company.companyCode FROM Company WHERE name='%s' AND" +
                        " address='%s' AND telephoneNumber='%s' AND faxNumber='%s' AND url='%s';",
                visitingCard.getCompanyName(), visitingCard.getAddress(),
                visitingCard.getTelephoneNumber(), visitingCard.getFaxNumber(),
                visitingCard.getUrl());
        try(Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306" +
                "/VisitingCardBinder?serverTimezone=Asia/Seoul", "root", "1q2w3e");
            PreparedStatement pstmt = con.prepareStatement(sql);
            //rs에 위의 쿼리문으로 찾은 결과를 저장함.
            ResultSet rs = pstmt.executeQuery();)
        {
            String companyCode;
            //쿼리문으로 DB에서 찾은 데이터가 있으면(rs에 저장된 데이터가 있으면)(중복이 있으면)
            if(rs.next() == true)
            {
                //해당데이터의 companyCode를 읽는다.
                companyCode = rs.getString(1);
            }
            //쿼리문으로 DB에서 찾은 데이터가 없으면(중복이 없으면)
            else
            {
                //새로운 companyCode를 생성한다.
                companyCode = getCompanyCode();
                //데이터베이스에 새로운 회사정보를 추가하기 위한 쿼리문 생성하기
                sql = String.format("INSERT INTO Company(name, address," +
                                " telephoneNumber, faxNumber, url, companyCode) " +
                        "VALUES('%s', '%s', '%s', '%s', '%s', '%s');",
                        visitingCard.getCompanyName(), visitingCard.getAddress(),
                        visitingCard.getTelephoneNumber(), visitingCard.getFaxNumber(),
                        visitingCard.getUrl(), companyCode);
                try(PreparedStatement pstmt2 = con.prepareStatement(sql);)
                {
                    pstmt2.executeUpdate();
                }
            }
            //데이터베이스에서 새로운 개인정보를 추가하기 위한 쿼리문 생성하기
            sql = String.format("INSERT INTO Personal(name, position, " +
                            "cellularPhoneNumber, emailAddress, code, companyCode) " +
                    "VALUES('%s', '%s', '%s', '%s', '%s', '%s');",
                    visitingCard.getPersonalName(), visitingCard.getPosition(),
                    visitingCard.getCellularPhoneNumber(), visitingCard.getEmailAddress(),
                    getPersonalCode(), companyCode);
            try(PreparedStatement pstmt2 = con.prepareStatement(sql);)
            {
                pstmt2.executeUpdate();
            }
        }
        catch (SQLException e)
        {
            System.out.println("[SQL Error : " + e.getMessage() +"]");
        }
    }
    //delete
    public static void delete(VisitingCard visitingCard)
    {
        String sql = String.format("SELECT Company.companyCode, Personal.code " +
                        "FROM Company INNER JOIN Personal ON " +
                        "Company.companyCode=Personal.companyCode WHERE Company.name='%s' AND" +
                        " Company.address='%s' AND Company.telephoneNumber='%s' AND " +
                        "Company.faxNumber='%s' AND Company.url='%s' AND Personal.name='%s' AND " +
                        "Personal.position = '%s' AND Personal.cellularPhoneNumber='%s' AND " +
                        "Personal.emailAddress='%s';", visitingCard.getCompanyName(),
                visitingCard.getAddress(), visitingCard.getTelephoneNumber(),
                visitingCard.getFaxNumber(), visitingCard.getUrl(), visitingCard.getPersonalName(),
                visitingCard.getPosition(), visitingCard.getCellularPhoneNumber(),
                visitingCard.getEmailAddress());
        try(Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306" +
                "/VisitingCardBinder?serverTimezone=Asia/Seoul", "root", "1q2w3e");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(sql);)
        {
            rs.next();
            String companyCode = rs.getString(1);
            String personalCode = rs.getString(2);
            sql = String.format("DELETE FROM Personal WHERE code='%s';", personalCode);
            stmt.executeUpdate(sql);
            sql = String.format("SELECT Personal.name FROM Personal WHERE companyCode='%s';"
                    , companyCode);
            try(ResultSet rs2 = stmt.executeQuery(sql);)
            {
                if(rs2.next())
                {
                    sql = String.format("DELETE FROM Company WHERE companyCode='%s';",
                            companyCode);
                    stmt.executeUpdate(sql);
                }
            }
        }
        catch (SQLException e)
        {
            System.out.println("[SQL Error : " + e.getMessage() +"]");
        }
    }
}
