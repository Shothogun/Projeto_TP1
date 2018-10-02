#ifndef	PROJETO_TP1_ENTITY_H 
#define	PROJETO_TP1_ENTITY_H

#include "domain.h"

class User{

    private:

        // Elementos que compoem a classe?
        Name name; /*!< Objeto da classe Nome. Armazena o nome do cliente. */
        Identifier identifier; /*!< Objeto da classe Identifier. Armazena o Identifier de usuário. */
        Password password; /*!< Objeto da classe Senha. Armazena a senha do usuário. */

    public:

        // Metodos de acesso ao nome:

        /*! \fn void SetNome(const Nome &nome)
            \brief Seta o objeto passado como o nome do usuário.
            \param nome Objeto do tipo Nome a ser setado.
        */
        void SetName(const Name &name){
            this->name = name;
        }

        /*! \fn Nome GetNome()
            \brief Retorna o objeto do nome do usuário.
            \return Objeto do tipo Nome.
        */
        Nome GetName() const {
            return nome;
        }

        // Metodos de acesso a agencia da conta:

        /*! \fn void Identifier(const Identifier &Identifier)
            \brief Seta o objeto passado como o Identifier do usuário.
            \param Identifier Objeto do tipo Identifier a ser setado.
        */
        void SetIdentifier(const Identifier &identifier){
            this->identifier = identifier;
        }

        /*! \fn Identifier GetIdentifier()
            \brief Retorna o objeto do Identifier de usuário armazenado.
            \return Objeto do tipo Identifier.
        */
        Identifier GetIdentifier() const {
            return identifier;
        }

        // Metodos de acesso à senha:

        /*! \fn void SetSenha(const Senha &senha)
            \brief Seta o objeto passado como a senha do usuário.
            \param banco Objeto do tipo Senha a ser setado.
        */
        void SetPassword(const Password &password){
            this->password = password;
        }

        /*! \fn Senha GetSenha()
            \brief Retorna o objeto da senha armazenada.
            \return Objeto do tipo Senha.
        */
        Senha GetPassword() const {
            return password;
        }
};

/*! \class Accommodation
        \brief Classe que define a entitade do tipo Accommodation.
        Classe que armazena as informações necessárias para definir uma acomodação
        Contém um objeto para os tipos Identifier, TipoDeAccommodation, CapacidadeDeAccommodation,
        Data, Nome, Estado e Diaria.
*/
class Accommodation
{
    private:

        // Elementos que compoem a classe?
        Identifier identifier; /*!< Objeto da classe Identifier. Armazena um Identifier para a acomodação. */
        AccommodationOption accommodation_option; /*!< Objeto da classe TipoDeAccommodation. Armazena qual é o tipo da acomodação. */
        AccommodationCapacity accommodation_capacity; /*!< Objeto da classe CapacidadeDeAccommodation. Armazena qual é a capacidade da acomodação. */
        Date begin_date; /*!< Objeto da classe Data. Armazena qual é a data de início da permanência. */
        Date end_date; /*!< Objeto da classe Data. Armazena qual é a data de término da permanência. */
        State state; /*!< Objeto da classe Estado. Armazena qual é o estado brasileiro da acaomodação. */
        DailyValue daily; /*!< Objeto da classe Diaria. Armazena qual é o valor da diária da acomodação. */

    public:

        // Métodos de acesso ao Identifier

        /*! \fn void SetIdentifier(const Identifier &Identifier)
            \brief Seta o objeto passado como o Identifier.
            \param Identifier Objeto do tipo Identifier a ser setado.
        */
         void SetIdentifier(const Identifier &identifier){
            this->Identifier = identifier;
        }

        /*! \fn Identifier GetIdentifier()
            \brief Retorna o objeto do Identifier armazenado.
            \return Objeto do tipo Identifier.
        */
        Identifier GetIdentifier(){
            return identifier;
        }

        // Métodos de acesso ao tipo de Accommodation
        /*! \fn void SetTipoDeAccommodation(const TipoDeAccommodation &tipo_de_Accommodation)
            \brief Seta o objeto passado como o tipo de Accommodation.
            \param tipo_de_Accommodation Objeto do tipo TipoDeAccommodation a ser setado.
        */
        void SetTipoDeAccommodation(const TipoDeAccommodation &tipo_de_Accommodation){
            this->tipo_de_Accommodation = tipo_de_Accommodation;
        }

        /*! \fn TipoDeAccommodation GetTipoDeAccommodation()
            \brief Retorna o objeto do tipo de Accommodation armazenado.
            \return Objeto do tipo TipoDeAccommodation.
        */
        AccommodationOption GetAccommodationOption(){
            return accommodation_option;
        }

        // Métodos de acesso à capacidade de acomodação

        /*! \fn void SetCapacidaDeAccommodation(const CapacidadeDeAccommodation &capacidade)
            \brief Seta o objeto passado como a capacidade de Accommodation.
            \param capacidade Objeto do tipo CapacidadeDeAccommodation a ser setado.
        */
        void SetAccommodationCapacity(const AccommodationCapacity &accommodation_capacity){
            this->accommodation_capacity = accommodation_capacity;
        }

        /*! \fn CapacidadeDeAccommodation GetCapacidadeDeAccommodation()
            \brief Retorna o objeto com a capacidade de Accommodation armazenada.
            \return Objeto do tipo CapacidadeDeAccommodation.
        */
        AccommodationCapacity GetAccommodationCapacity(){
            return accommodation_capacity;
        }

        // Métodos de acesso à data de início

        /*! \fn void SetDataInicio(const Data &data_inicio)
            \brief Seta o objeto passado como a data de inicio.
            \param data_inicio Objeto do tipo Data a ser setado.
        */
        void SetBeginDate(const Date &begin_date){
            this->begin_date = begin_date;
        }

        /*! \fn Data GetDataInicio()
            \brief Retorna o objeto com a data de inicio armazenada.
            \return Objeto do tipo Data
        */
        Data GetBeginDate(){
            return begin_date;
        }

        // Métodos de acesso à data de término

        /*! \fn void SetDataTermino(const Data &data_termino)
            \brief Seta o objeto passado como a data de término.
            \param data_termino Objeto do tipo Data a ser setado.
        */
        void SetEndDate(const Date &end_date){
            this->end_date = end_date;
        }

        /*! \fn Data GetDataTermino()
            \brief Retorna o objeto com a data de término armazenada.
            \return Objeto do tipo Data
        */
        Data GetEndDate(){
            return end_date;
        }

        // Métodos de acesso ao estado

        /*! \fn void SetEstado(const Estado &estado)
            \brief Seta o objeto passado como o estado.
            \param estado Objeto do tipo Estado a ser setado.
        */
        void SetState(const State &state){
            this->state = state;
        }

        /*! \fn Estado GetEstado()
            \brief Retorna o objeto com o estado armazenado.
            \return Objeto do tipo Estado
        */
        Estado GetState(){
            return state;
        }

        // Métodos de acesso à diária

        /*! \fn void SetDiaria(const Diaria &diaria)
            \brief Seta o objeto passado como a diária.
            \param diaria Objeto do tipo Diaria a ser setado.
        */
        void SetDailyValue(const DailyValue &daily){
            this->daily = daily;
        }

        /*! \fn GetDiaria()
            \brief Retorna o objeto com a diaria armazenada.
            \return Objeto do tipo Diaria
        */
        Diaria GetDailyVallue(){
            return daily;
        }
};
/*! \class Cartao
        \brief Classe que define a entitade do tipo Cartao.
        Classe que armazena as caracteristicas necessárias para definir a entidade catão de crédito.
        Contém um objeto para o tipo NumeroCartao e outro para a Validade.
*/
class CreditCard{

    private:

        // Elementos que compoem a classe?
        CreditCardNumber number; /*!< Objeto da classe NumeroCartao. Armazena o número do cartão de crédito. */
        ExpirationDate expiration; /*!< Objeto da classe Validade. Armazena a data de validade do cartão de crédito. */

    public:

        // Metodos de acesso ao numero do cartão:

        /*! \fn void SetNumero(const NumeroCartao &numero)
            \brief Seta o objeto passado como o número do cartão de crédito.
            \param numero Objeto do tipo NumeroCartao a ser setado.
        */
        void SetCreditCardNumber(const CreditCardNumber &number){
            this->number = number;
        }

        /*! \fn NumeroCartao GetNumero()
            \brief Retorna o objeto do número do cartão armazenado.
            \return Objeto do tipo NumeroCartao.
        */
       CreditCardNumber GetCreditCardNumber() const {
            return number;
        }

        // Metodos de acesso a data de validade do cartao:

        /*! \fn void SetValidade(const Validade &validade)
            \brief Seta o objeto passado como a validade do cartão de crédito.
            \param validade Objeto do tipo Validade a ser setado.
        */
        void SetExpirationDate(const ExpirationDate &expiration){
            this->expiration = expiration;
        }

        /*! \fn Validade GetValidade()
            \brief Retorna o objeto da data de validade do cartão armazenado.
            \return Objeto do tipo Validade.
        */
        Validade GetExpirationDate() const {
            return expiration;
        }
};

/*! \class ContaCorrente
        \brief Classe que define a entitade do tipo ContaCorrente.
        Classe que armazena as caracteristicas necessárias para definir a entidade da conta corrente.
        Contém um objeto para o tipo NumeroConta, outro para a Agencia e outro para o Banco.
*/

class Account{

    private:

        // Elementos que compoem a classe?
        AccountNumber number; /*!< Objeto da classe NumeroConta. Armazena o número da conta corrente. */
        Agency agency; /*!< Objeto da classe Agencia. Armazena o número da agencia bancaria. */
        Bank bank; /*!< Objeto da classe Banco. Armazena o número do banco da conta. */

    public:

        // Metodos de acesso ao numero da conta:

        /*! \fn void SetNumero(const NumeroConta &numero)
            \brief Seta o objeto passado como o número da conta corrente.
            \param numero Objeto do tipo NumeroConta a ser setado.
        */
        void SetAccountNumber(const AccountNumber &number){
            this->number = number;
        }

        /*! \fn NumeroConta GetNumero()
            \brief Retorna o objeto do número da conta corrente.
            \return Objeto do tipo NumeroConta.
        */
        AccountNumber GetAccountNumber() const {
            return number;
        }

        // Metodos de acesso a agencia da conta:

        /*! \fn void SetAgencia(const Agencia &agencia)
            \brief Seta o objeto passado como a agencia da conta corrente.
            \param agencia Objeto do tipo Agencia a ser setado.
        */
        void SetAgency(const Agency &agency){
            this->agency = agency;
        }

        /*! \fn Agencia GetAgencia()
            \brief Retorna o objeto da agencia da conta corrente armazenada.
            \return Objeto do tipo Agencia.
        */
        Agency GetAgency() const {
            return agency;
        }

        // Metodos de acesso ao banco da conta:

        /*! \fn void SetBanco(const Banco &banco)
            \brief Seta o objeto passado como o banco da conta corrente.
            \param banco Objeto do tipo Banco a ser setado.
        */
        void SetBank(const Bank &bank){
            this->bank = bank;
        }

        /*! \fn Banco GetBanco()
            \brief Retorna o objeto do banco da conta corrente armazenada.
            \return Objeto do tipo Banco.
        */
        Bank GetBank() const {
            return bank;
        }
};
#endif	// PROJETO_TP1_ENTITY_H
