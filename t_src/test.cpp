#define CATCH_CONFIG_MAIN 
#include "../framework/catch.hpp"
#include "../include/domain.hpp"

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