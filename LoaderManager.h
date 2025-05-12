#pragma once
#include <string>

class LoaderManager {
public:
    static LoaderManager* getInstance();
    static void destroyInstance();
    void loadAllAssets();
    void showLoadingScreen();

private:
    LoaderManager(); // prywatny konstruktor
    ~LoaderManager();

    static LoaderManager* instance;
};
