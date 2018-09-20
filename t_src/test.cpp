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
   Agency* A = new Agency("1234");
   REQUIRE(A->get_value() == "1234");
  }

  // Invalid digit entry
  SECTION( "Error 2" ) 
  {
   Agency* A = new Agency("123a5");
   REQUIRE(A->get_value() == "123a5");
  }

  // Size greater than standard
  SECTION( "Error 3" ) 
  {
   Agency* A = new Agency("123456");
   REQUIRE(A->get_value() == "123456");
  }

}

TEST_CASE("create Bank", "[Bank]")
{
  SECTION( "common set" ) 
  {
   Bank* A = new Bank("123");
   REQUIRE(A->get_value() == "123");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   Bank* A = new Bank("13");
   REQUIRE(A->get_value() == "13");
  }

  // Invalid digit entry
  SECTION( "Error 2" ) 
  {
   Bank* A = new Bank("1a");
   REQUIRE(A->get_value() == "1a");
  }

  // Size greater than standard
  SECTION( "Error 3" ) 
  {
   Bank* A = new Bank("123456");
   REQUIRE(A->get_value() == "123456");
  }

}
