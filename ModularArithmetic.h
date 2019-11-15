class ModularArithmetic {
    private:
        unsigned long long int mod;
        unsigned long long int num;
    public:
        ModularArithmetic(unsigned long long int mod, unsigned long long int num);
        ModularArithmetic();
        unsigned long long int getMod();
        unsigned long long int getNum();
        void setMod(unsigned long long int mod);
        void setNum(unsigned long long int num);
        ModularArithmetic operator+(unsigned long long int const n);
        ModularArithmetic operator*(unsigned long long int const n);
        static ModularArithmetic modularPower(unsigned long long int base, unsigned long long int exp, unsigned long long int mod);
};