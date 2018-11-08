#ifndef	PROJETO_TP1_ENTITY_H 
#define	PROJETO_TP1_ENTITY_H

#include "../include/domain.hpp"

//! User
/*!
    Receives and validates User.
*/
class User{

    private:

        Name* name_; /*!< object of class Name. Express user name */
        Identifier* identifier_; /*!< object of class Identifier. Express user identifier. */
        Password* password_; /*!< object of class Password. Express user password. */

    public:

        //! Constructor
        
        User();

        // name_ access methods:

        //! Set name_ function
        /*! 
            Set object name to User.
            \param name of class Name.
        */
        void set_name(Name* name){
            this->name_ = name;
        }

        //! Get name_ function
        /*!
            Returns object name_ from User.
        */
        Name* get_name() const {
            return this->name_;
        }

        // identifier_ access methods:

        //! Set identifier_ function
        /*! 
            Set object identifier_ to User.
            \param identifier of class Identifier.
        */
        void set_identifier(Identifier* identifier){
            this->identifier_ = identifier;
        }

        //! Get identifier_ function
        /*!
            Returns object identifier_ from User.
        */
        Identifier* get_identifier() const {
            return this->identifier_;
        }

        // password_ access methods:

        //! Set password_ function
        /*! 
            Set object password to User.
            \param password_ of class Password.
        */
        void set_password(Password* password){
            this->password_ = password;
        }

        //! Get password_ function
        /*!
            Returns object password_ from User.
        */
        Password* get_password() const {
            return this->password_;
        }
};

//! Accommodation
/*!
    Receives and validates Accommodation.
*/
class Accommodation
{
    private:

        Identifier* identifier_; /*!< object of class Identifier. Express Accommodation identifier */
        AccommodationType* accommodation_type_; /*!< object of class Accommodationtype. Express Accommodation accommodation type */
        AccommodationCapacity* accommodation_capacity_; /*!< object of class AccommodationCapacity. Express Accommodation accommodation capacity */
        Date* begin_date_; /*!< object of class Data. Express Accommodation begin date */
        Date* end_date_; /*!< object of class Data. Express Accommodation end date */
        State* state_; /*!< object of class State. Express Accommodation state */
        DailyValue* daily_; /*!< object of class Name. Express Accommodation daily value */

    public:

        //! Constructor
        
        Accommodation();

        // identifier_ access methods:
        
        //! Set identifier_ function
        /*! 
            Set object identifier to Accommodation.
            \param identifier of class Identifier.
        */
         void set_identifier(Identifier* identifier){
            this->identifier_ = identifier;
        }

        //! Get identifier_ function
        /*!
            Returns object identifier_ from Accommodation.
        */
        Identifier* get_identifier() const{
            return this->identifier_;
        }

        // accommodation_type_ access methods:

        //! Set accommodation_type_ function
        /*! 
            Set object accommodation_type to Accommodation.
            \param accommodation_type of class Accommodationtype.
        */
        void set_accommodation_type(AccommodationType* accommodation_type){
            this->accommodation_type_ = accommodation_type;
        }

        //! Get accommodation_type_ function
        /*!
            Returns object accommodation_type_ from Accommodation.
        */
        AccommodationType* get_accommodation_type() const{
            return this->accommodation_type_;
        }

        // accommodation_capacity access methods:
        
        //! Set accommodation_capacity function
        /*! 
            Set object accommodation_capacity to Accommodation.
            \param accommodation_capacity of class AccommodationCapacity.
        */
         void set_accommodation_capacity(AccommodationCapacity* accommodation_capacity){
            this->accommodation_capacity_ = accommodation_capacity;
        }

        //! Get accommodation_capacity_ function
        /*!
            Returns object accommodation_capacity_ from Accommodation.
        */
        AccommodationCapacity* get_accommodation_capacity() const{
            return this->accommodation_capacity_;
        }


        // begin_date_ access methods:

        //! Set begin_date_ date function
        /*! 
            Set object begin_date_ to Accommodation.
            \param begin_date of class Date.
        */
        void set_begin_date(Date* begin_date){
            this->begin_date_ = begin_date;
        }

        //! Get begin_date_ function
        /*!
            Returns object begin_date_ from Accommodation.
        */
        Date* get_begin_date() const{
            return this->begin_date_;
        }

        // end_date_ access methods:

        //! Set end_date_ function
        /*! 
            Set object end_date_ to Accommodation.
            \param end_date of class Date.
        */
        void set_end_date(Date* end_date){
            this->end_date_ = end_date;
        }

        //! Get end_date_ function
        /*!
            Returns object end_date_ from Accommodation.
        */
        Date* get_end_date() const{
            return this->end_date_;
        }

        // state_ access methods:

        //! Set state_ function
        /*! 
            Set object state_ to Accommodation.
            \param state_ of class State.
        */
        void set_state(State* state){
            this->state_ = state;
        }

        //! Get state_ function
        /*!
            Returns object state_ from Accommodation.
        */
        State* get_state() const{
            return this->state_;
        }

        // daily_ access methods:

        //! Set daily_ function
        /*! 
            Set object daily_ to Accommodation.
            \param daily_ of class DailyValue.
        */
        void set_daily(DailyValue* daily){
            this->daily_ = daily;
        }

        //! Get daily_ function
        /*!
            Returns object daily_ from Accommodation.
        */
        DailyValue* get_daily() const{
            return this->daily_;
        }
};

//! CreditCard
/*!
    Receives and validates CreditCard.
*/
class CreditCard{

    private:
        CreditCardNumber* number_; /*!< object of class CreditCardNumber. Express CreditCard number_  */
        ExpirationDate* expiration_; /*!< object of class ExpirationDate. Express CreditCard expiration_  */

    public:

        //! Constructor
        
        CreditCard();


        // number_ access methods:

        //! Set number_ function
        /*! 
            Set object number_ to CreditCard.
            \param number_ of class CreditCardNumber.
        */
        void set_number(CreditCardNumber* number_){
            this->number_ = number_;
        }

        //! Get number_ function
        /*!
            Returns object number_ from CreditCard.
        */
        CreditCardNumber* get_number() const{
            return this->number_;
        }

        // expiration_ access methods:

        //! Set expiration_ function
        /*! 
            Set object expiration_ to CreditCard.
            \param expiration_ of class ExpirationDate.
        */
        void set_expiration(ExpirationDate* expiration_) {
            this->expiration_ = expiration_;
        }

        //! Get expiration_ function
        /*!
            Returns object expiration_ from CreditCard.
        */
        ExpirationDate* get_expiration() const{
            return this->expiration_;
        }
};

//! Account
/*!
    Receives and validates Account.
*/

class Account{

    private:

        AccountNumber* number_; /*!< object of class AccountNumber. Express Account number*/
        Agency* agency_; /*!< object of class Agency. Express Account agency*/
        Bank* bank_; /*!< object of class Bank. Express Account bank*/

    public:

        //! Constructor
        
        Account();

        // number_ access methods:

        //! Set number_ function
        /*! 
            Set object number_ to Account.
            \param number_ of class Account.
        */
        void set_number(AccountNumber* number){
            this->number_ = number;
        }

        //! Get number_ function
        /*!
            Returns object number_ from Account.
        */
        AccountNumber* get_number() const{
            return this->number_;
        }

        // agency_ access methods:

        //! Set agency_ function
        /*! 
            Set object agency_ to Account.
            \param agency_ of class Account.
        */
        void set_agency(Agency* agency_){
            this->agency_ = agency_;
        }

        //! Get agency_ function
        /*!
            Returns object agency_ from Account.
        */
        Agency* get_agency() const{
            return this->agency_;
        }

        // bank_ access methods:

        //! Set bank_ function
        /*! 
            Set object bank_ to Account.
            \param bank_ of class Account.
        */
        void set_bank(Bank* bank_){
            this->bank_ = bank_;
        }

        //! Get bank_ function
        /*!
            Returns object bank_ from Account.
        */
        Bank* get_bank() const{
            return this->bank_;
        }
};

// Class Feedback represents success of operations 
class Feedback 
{
  protected:
  	int value;

	public:
		const static int kSuccess_ = 0;
		const static int kFail_ = 1;

		void set_value(int value)
		{
				this->value = value;
		}

		int get_value() const
		{
				return this->value;
		}
};

// Class FeedbackAuthentication represents success of Authentication module 

class FeedbackAuthentication: public Feedback
{
	private:
		Identifier identifier;

	public:
		void set_identifier(const Identifier &identifier)
		{
			this->identifier = identifier;
		}

		Identifier get_identifier() const
		{
			return this->identifier;
		}
};

// Class FeedbackUser represents success of User module 
class FeedbackUser: public Feedback
{
	private:
		User user;

	public:
		void set_user(const User &user)
		{
			this->user = user;
		}

		User get_user() const
		{
			return this->user;
		}
};

#endif	// PROJETO_TP1_ENTITY_H
