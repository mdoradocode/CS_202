#ifndef CAR_H
#define CAR_H

class car{

    public:
        car();
        car(int year, char *make, char *model, float price, bool available);
        int getYear();
        char *getModel();
        char *getMake();
        float getPrice();
        bool getAvailable();
        void setYear(int year);
        void setModel(char *model);
        void setMake(char *make);
        void setPrice(float price);
        void setAvailable(bool available);
        float estimateCost(int days);
    private:
        int m_year;
        char m_make[256];
        char m_model[256];
        float m_price;
        bool m_available;
        char empty[256] = "EMPTY";
};

#endif