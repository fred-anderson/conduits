#ifndef CONDUITS_PROPERTIES_H
#define CONDUITS_PROPERTIES_H

#include <string>
#include <map>

namespace conduits {

namespace config {

class properties : public virtual std::map<std::string, std::string> {
    virtual ~properties();

};

} // namespace config

} // namespace conduits

#endif //CONDUITS_PROPERTIES_H
