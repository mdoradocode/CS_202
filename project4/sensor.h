#pragma once

class sensor{
    public:
        static int gpsCnt, cameraCnt, lidarCnt, radarCnt;
        sensor();
        sensor(char *type);
        sensor(sensor *copy);

        void setType(char *type);
        void setExCost();
        void reset();

        char *getType();
        int getGps();
        int getCamera();
        int getLidar();
        int getRadar();
        float getExCost();

        bool operator== (sensor *sensorPtr);

    private:
        float m_exCost;
        char m_type[256];
        char empty[256] = "EMPTY";

};
