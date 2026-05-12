#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _signGrade(150), _execGrade(150) {
}

Form::Form(const std::string& name, int signGrade, int execGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
}

const std::string& Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecGrade() const {
    return this->_execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade) {
        throw Form::GradeTooLowException();
    }
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade requirement is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low to sign this Form!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() << "\n"
       << "Status: " << (form.getIsSigned() ? "Signed" : "Not Signed") << "\n"
       << "Required Grade to Sign: " << form.getSignGrade() << "\n"
       << "Required Grade to Execute: " << form.getExecGrade();
    return os;
}
