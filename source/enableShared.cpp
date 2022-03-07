// enableShared.cpp

#include <iostream>
#include <memory>

class ShareMe: public std::enable_shared_from_this<ShareMe>{
public:
  std::shared_ptr<ShareMe> getShared(){
    return shared_from_this();
  }
};

int main(){

  std::cout << '\n';

  std::shared_ptr<ShareMe> shareMe(new ShareMe);
  std::shared_ptr<ShareMe> shareMe1= shareMe->getShared();
  {
    auto shareMe2(shareMe1);
    std::cout << "shareMe.use_count(): "  << shareMe.use_count() << '\n';
  }
  std::cout << "shareMe.use_count(): "  << shareMe.use_count() << '\n';
  
  shareMe1.reset();
  
  std::cout << "shareMe.use_count(): "  << shareMe.use_count() << '\n';

  std::cout << '\n';

}


