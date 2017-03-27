#ifndef CONDUITS_CONFIGURABLE_H
#define CONDUITS_CONFIGURABLE_H

namespace conduits {

namespace config {

class configurable {
public:

    virtual ~configurable() { }

    virtual void configure(properties& props) = 0;

    virtual bool is_configured() = 0;

};

} // namespace config

} // namespace conduits

#endif // CONDUITS_CONFIGURABLE_H
