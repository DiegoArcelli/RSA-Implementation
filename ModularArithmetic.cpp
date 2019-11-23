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
    if(mod == 1){
        ModularArithmetic res(1,1);
        return res;
    } else {
        ModularArithmetic r(mod,1);
        base = base % mod;
        while(exp > 0){
            if(exp % 2 == 1)
                r = r*base;
            exp = exp >> 1;
            base = (base*base) % mod;
        }
        return r;
    }
}