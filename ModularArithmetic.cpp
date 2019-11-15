#include "ModularArithmetic.h"
#include <iostream>

ModularArithmetic::ModularArithmetic(unsigned long long int mod, unsigned long long int num){
    this->mod = mod;
    this->num = num % mod;
}

ModularArithmetic::ModularArithmetic(){
    this->mod = 1;
    this->num = 0;
}

unsigned long long int ModularArithmetic::getMod(){
    return this->mod;
}

unsigned long long int ModularArithmetic::getNum(){
    return this->num;
}

void ModularArithmetic::setMod(unsigned long long int mod){
    this->mod = mod;
}

void ModularArithmetic::setNum(unsigned long long int num){
    this->num = num % mod;
}

ModularArithmetic ModularArithmetic::operator+(unsigned long long int const n){
    ModularArithmetic res;
    res.setMod(this->getMod());
    res.setNum((this->getNum() + n) % mod);
    return res;
}


ModularArithmetic ModularArithmetic::operator*(unsigned long long int const n){
    ModularArithmetic res;
    res.setMod(this->getMod());
    res.setNum((this->getNum() * n) % mod);
    return res;
}

ModularArithmetic ModularArithmetic::modularPower(unsigned long long int base, unsigned long long int exp, unsigned long long int mod){
    ModularArithmetic m_base;
    m_base.setMod(mod);
    m_base.setNum(base);
    unsigned long long int i;  
    for(i = 0; i < exp - 1; i++){
        m_base = m_base * base;
    }
    return m_base;
}