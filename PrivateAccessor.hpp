#ifndef PRIVATEACCESSOR_HPP
#define PRIVATEACCESSOR_HPP

namespace PrivateAccess
{
    template <typename Class_t, typename Member_t, Member_t Class_t::* Member>
    struct Accessor
    {
        using PLACEHOLDER_TYPE = Member_t*;

        friend Member_t& access(Class_t& obj, PLACEHOLDER_TYPE)
        {
            return obj.*Member;
        }
    };

    template <typename T>
    constexpr static T* PlaceHolder = static_cast<T*>(nullptr);

#define DECLARE_ACCESS(CLASS_TYPE, PROPERTY_TYPE, PROPERTY_NAME)                    \
    namespace PrivateAccess                                                         \
    {                                                                               \
    template class Accessor<CLASS_TYPE, PROPERTY_TYPE, &CLASS_TYPE::PROPERTY_NAME>; \
    PROPERTY_TYPE& access(CLASS_TYPE&, PROPERTY_TYPE*);                             \
    }

}

#endif
