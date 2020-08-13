#ifndef _LOADSAVE_H
#define _LOADSAVE_H
#include <string>
#include <memory>

class LoadSave{
  public:
    void loadProperty(std::string ownableName, std::shared_ptr<Player> buyer);
    void loadMortProperty(std::string ownableName, std::shared_ptr<Player> own); 
}

#endif
