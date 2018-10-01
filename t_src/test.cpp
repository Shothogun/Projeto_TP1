#define CATCH_CONFIG_MAIN 
#include "../framework/catch.hpp"
#include "../include/domain.hpp"

// Total - 4 Tests - 1 pass - 3 failed
TEST_CASE("create agency", "[Agency]")
{
  SECTION( "common set" ) 
  {
   Agency* A = new Agency("12345");
   REQUIRE(A->get_value() == "12345");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   Agency* Agency_test = new Agency("1234");
   REQUIRE(Agency_test->get_value() == "1234");
  }

  // Invalid digit entry
  SECTION( "Error 2" ) 
  {
   Agency* Agency_test = new Agency("123a5");
   REQUIRE(Agency_test->get_value() == "123a5");
  }

  // Size greater than standard
  SECTION( "Error 3" ) 
  {
   Agency* Agency_test = new Agency("123456");
   REQUIRE(Agency_test->get_value() == "123456");
  }

}

// Total - 8 Tests - 2 pass - 6 failed
TEST_CASE("create Bank", "[Bank]")
{
  SECTION( "common set" ) 
  {
   Bank* Bank_test = new Bank("123");
   REQUIRE(Bank_test->get_value() == "123");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   Bank* Bank_test = new Bank("13");
   REQUIRE(Bank_test->get_value() == "13");
  }

  // Invalid digit entry
  SECTION( "Error 2" ) 
  {
   Bank* Bank_test = new Bank("1a");
   REQUIRE(Bank_test->get_value() == "1a");
  }

  // Size greater than standard
  SECTION( "Error 3" ) 
  {
   Bank* Bank_test = new Bank("123456");
   REQUIRE(Bank_test->get_value() == "123456");
  }

}

// Total - 13 Tests - 3 pass - 10 failed
TEST_CASE("create Accommodation Capacity", "[Accommodation Capacity]")
{
  SECTION( "common set" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("1");
   REQUIRE(AccommodationCapacity_test->get_value() == "1");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("");
   REQUIRE(AccommodationCapacity_test->get_value() == "");
  }

  // Invalid digit entry
  SECTION( "Error 2" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("a");
   REQUIRE(AccommodationCapacity_test->get_value() == "a");
  }

  // Invalid digit entry
  SECTION( "Error 3" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("a");
   REQUIRE(AccommodationCapacity_test->get_value() == "A");
  }


  // Size greater than standard
  SECTION( "Error 4" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("123456");
   REQUIRE(AccommodationCapacity_test->get_value() == "123456");
  }

}

// Total - 19 Tests - 4 pass - 15 failed
TEST_CASE("create Daily Value", "[Daily Value]")
{
  SECTION( "common set" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("20.00");
   REQUIRE(DailyValue_test->get_value() == "20.00");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("0.02");
   REQUIRE(DailyValue_test->get_value() == "0.02");
  }

    // Size greater than standard
  SECTION( "Error 2" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("12300.00");
   REQUIRE(DailyValue_test->get_value() == "123000.00");
  }


  // Invalid digit entry
  SECTION( "Error 3" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("a");
   REQUIRE(DailyValue_test->get_value() == "a");
  }

  // Invalid digit entry
  SECTION( "Error 4" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("123as.00");
  }

  // Invalid digit entry
  SECTION( "Error 5" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("1232.00 3334.00");
  }
}

// Total -  44 Tests - 20 pass - 24 failed
TEST_CASE("create Date", "[Date]")
{
  SECTION("common set 1")
  {
    Date *Date_test = new Date("02/jan/2023");
    REQUIRE(Date_test->get_value() == "02/jan/2023");
    REQUIRE(Date_test->get_day() == 2);
    REQUIRE(Date_test->get_month() == 1);
    REQUIRE(Date_test->get_year() == 2023);
  }

  SECTION("common set 2")
  {
    Date *Date_test = new Date("27/jun/2005");
    REQUIRE(Date_test->get_value() == "27/jun/2005");
    REQUIRE(Date_test->get_day() == 27);
    REQUIRE(Date_test->get_month() == 06);
    REQUIRE(Date_test->get_year() == 2005);
  }

  // Size error
  SECTION("Error 1")
  {
    Date *Date_test = new Date("1/jun/2005");
  }

  // '/' error
  SECTION("Error 2")
  {
    Date *Date_test = new Date("012jun/2005");
  }

  // '/' error 
  SECTION("Error 3")
  {
    Date *Date_test = new Date("01/junn2005");
  }

  // Digit error
  SECTION("Error 4")
  {
    Date *Date_test = new Date("0a/jun/2000");
  }

  // Digit error
  SECTION("Error 5")
  {
    Date *Date_test = new Date("01/jun/200a");
  }

  // Month value error
  SECTION("Error 6")
  {
    Date *Date_test = new Date("01/feb/2010");
  }

  // Year value error
  SECTION("Error 7")
  {
    Date *Date_test = new Date("01/jun/1999");
  }

  // Year value error
  SECTION("Error 8")
  {
    Date *Date_test = new Date("01/jun/2100");
  }

  // Day value error(Not a leap year)
  SECTION("Error 9")
  {
    Date *Date_test = new Date("29/fev/2018");
  }

  SECTION("Leap year 1")
  {
    Date *Date_test = new Date("29/fev/2020");
    REQUIRE(Date_test->get_value() == "29/fev/2020");
    REQUIRE(Date_test->get_day() == 29);
    REQUIRE(Date_test->get_month() == 02);
    REQUIRE(Date_test->get_year() == 2020);
  }

  SECTION("Leap year 2")
  {
    Date *Date_test = new Date("29/fev/2000");
    REQUIRE(Date_test->get_value() == "29/fev/2000");
    REQUIRE(Date_test->get_day() == 29);
    REQUIRE(Date_test->get_month() == 02);
    REQUIRE(Date_test->get_year() == 2000);
  }
}

// Total -  52 Tests - 22 pass - 30 failed 
TEST_CASE("create Expiration date", "[Expiration date]")
{
  SECTION("common set")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("03/18");
    REQUIRE(ExpirationDate_test->get_month() == 3);
    REQUIRE(ExpirationDate_test->get_year() == 2018);
  }

  // Size error
  SECTION("Error 1")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("03/1");
  }

  // '/' error
  SECTION("Error 2")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("1/008");
  }

  // Digits error 
  SECTION("Error 3")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("0a/08");
  }

  // Digits error 
  SECTION("Error 4")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("02//8");
  }

  // Month value error 
  SECTION("Error 5")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("13/08");
  }

  // Month value error 
  SECTION("Error 6")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("00/08");
  }
}

// Total -  58 Tests - 26 pass - 32 failed 
TEST_CASE("create State", "[State]")
{
  SECTION("common set 1")
  {
    State* State_test = new State("AC");
    REQUIRE(State_test->get_value() == "AC");
    REQUIRE(State_test->get_state() == StateName::AC);
  }

    SECTION("common set 2")
  {
    State* State_test = new State("DF");
    REQUIRE(State_test->get_value() == "DF");
    REQUIRE(State_test->get_state() == StateName::DF);
  }

  SECTION("Error 1")
  {
    State* State_test = new State("df");
    REQUIRE(State_test->get_value() == "DF");
    REQUIRE(State_test->get_state() == StateName::AC);
  }

  SECTION("Error 2")
  {
    State* State_test = new State("EF");
  }
}

// Total -  62 Tests - 28 pass - 34 failed 
TEST_CASE("create Identifier", "[Identifier]")
{
  SECTION("common set 1")
  {
    Identifier *Identifier_test = new Identifier("ahyef");
    REQUIRE(Identifier_test->get_value() == "ahyef");
  }

  SECTION("common set 2")
  {
    Identifier *Identifier_test = new Identifier("aaaaa");
    REQUIRE(Identifier_test->get_value() == "aaaaa");
  }

  SECTION("Error 1")
  {
    Identifier *Identifier_test = new Identifier("Ahyef");
  }

  SECTION("Error 2")
  {
    Identifier *Identifier_test = new Identifier("a_yer");
  }
}

// Total -  68 Tests - 29 pass - 39 failed 
TEST_CASE("create Name", "[Name]")
{
  SECTION("common set")
  {
    Name* Name_test = new Name("Otho T. Komatsu");
    REQUIRE(Name_test->get_value() == "Otho T. Komatsu");
  }

  // Invalid digit
  SECTION("Error 1")
  {
    Name* Name_test = new Name("05h0 T. K0ma75u");
  }

  // Name initial character is a dot
  SECTION("Error 2")
  {
    Name* Name_test = new Name(".tho T. Komatsu");
  }

  // Dot without letter before
  SECTION("Error 3")
  {
    Name* Name_test = new Name("Otho . Komatsu ");
  }

  // Double spaced name
  SECTION("Error 4")
  {
    Name* Name_test = new Name("Otho  T Komatsu");
  }

  // No character
  SECTION("Error 5")
  {
    Name* Name_test = new Name(" . . . . . . . ");
  }
}


// Total - 72 Tests - 30 pass - 42 failed
TEST_CASE("create account number", "[AccountNumber]")
{
  SECTION( "common set" ) 
  {
   AccountNumber* AccountNumber_test = new AccountNumber("123456");
   REQUIRE(AccountNumber_test->get_value() == "123456");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   AccountNumber* AccountNumber_test = new AccountNumber("12345");
   REQUIRE(AccountNumber_test->get_value() == "12345");
  }

  // Invalid digit entry
  SECTION( "Error 2" ) 
  {
   AccountNumber* AccountNumber_test = new AccountNumber("123a5");
   REQUIRE(AccountNumber_test->get_value() == "123a5");
  }

  // Size greater than standard
  SECTION( "Error 3" ) 
  {
   AccountNumber* AccountNumber_test = new AccountNumber("1234567");
   REQUIRE(AccountNumber_test->get_value() == "123456");
  }
}

// Total - 79 Tests - 31 pass - 48 failed
TEST_CASE("create password", "[Password]")
{
  SECTION("common set")
  {
    Password* Password_test = new Password("123Abc!&");
    REQUIRE(Password_test->get_value() == "123Abc!&");
  }

  // Invalid digit
  SECTION("Error 1")
  {
    Password* Password_test = new Password("123Abc_&");
  }

  // Duplicated character
  SECTION("Error 2")
  {
    Password* Password_test = new Password("123Abc1&");
  }

  // No digit
  SECTION("Error 3")
  {
    Password* Password_test = new Password("%Abc#&Bd");
  }

  // No lower case
  SECTION("Error 4")
  {
    Password* Password_test = new Password("SA3C#&ED");
  }

  // No upper case
  SECTION("Error 5")
  {
    Password* Password_test = new Password("sabc#&2d");
  }

  // No special character
  SECTION("Error 6")
  {
    Password* Password_test = new Password("sabcEA2d");
  }
}

// Total - 86 Tests - 37 pass - 49 failed
TEST_CASE("create accommodation type", "[AccommodationType]")
{
  SECTION("common set")
  {
    AccommodationType* AccommodationType_test1 = new AccommodationType("Apartamento");
    AccommodationType* AccommodationType_test2 = new AccommodationType("Casa");
    AccommodationType* AccommodationType_test3 = new AccommodationType("Flat");

    REQUIRE(AccommodationType_test1->get_value() == "Apartamento");
    REQUIRE(AccommodationType_test1->get_accommodation_type() == AccommodationOption::Apartamento);

    REQUIRE(AccommodationType_test2->get_value() == "Casa");
    REQUIRE(AccommodationType_test2->get_accommodation_type() == AccommodationOption::Casa);

    REQUIRE(AccommodationType_test3->get_value() == "Flat");
    REQUIRE(AccommodationType_test3->get_accommodation_type() == AccommodationOption::Flat);
  }

  SECTION("uncommon set")
  {
    AccommodationType* AccommodationType_test1 = new AccommodationType("dewededef");
  }
}

// Total - 90 Tests - 39 pass - 51 failed
TEST_CASE("create CreditCardNumber", "[CreditCardNumber]")
{
  SECTION("common set 1")
  {
    CreditCardNumber* CreditCardNumber_test = new CreditCardNumber("1111111111111117");
    REQUIRE(CreditCardNumber_test->get_value() == "1111111111111117");
  }         

    SECTION("common set 2")
  {
    CreditCardNumber* CreditCardNumber_test = new CreditCardNumber("8297148378413852");
    REQUIRE(CreditCardNumber_test->get_value() == "8297148378413852");
  }       

  // Invalid Size
  SECTION("Error 1")
  {
    CreditCardNumber* CreditCardNumber_test = new CreditCardNumber("111111111117");
  }               

  // Invalid code number
  SECTION("Error 2")
  {
    CreditCardNumber* CreditCardNumber_test = new CreditCardNumber("3123847012389478");
  }                                                                
}