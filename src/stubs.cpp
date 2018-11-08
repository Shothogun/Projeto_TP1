#include "../include/stubs.hpp"

Feedback StubServAuthentication::authenticate(const Identifier &identifier, const Password &password) throw(runtime_error)
{
  // Show input data

  cout << std::endl << "StubServAuthentication::authenticate" << std::endl;

  cout << "Identificador = " <<  identifier.get_value() << std::endl;


}