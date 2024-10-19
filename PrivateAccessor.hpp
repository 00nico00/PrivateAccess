#ifndef PRIVATEACCESSOR_HPP
#define PRIVATEACCESSOR_HPP

namespace PrivateAccess
{
    template <typename Class_t, typename Member_t, Member_t Class_t::* Member>
    struct PropertyAccessor
    {
        using Flag_t = Member_t*;

        friend Member_t& access(Class_t& obj, Flag_t)
        {
            return obj.*Member;
        }
    };

    template <typename T>
    constexpr static T* Flag = nullptr;

#ifdef DECLARE_PROPERTY_ACCESSOR
#error DECLARE_PROPERTY_ACCESSOR macro redefined!
#endif

#define DECLARE_PROPERTY_ACCESSOR(CLASS_TYPE, PROPERTY_TYPE, PROPERTY_NAME)                 \
    namespace PrivateAccess                                                                 \
    {                                                                                       \
    template class PropertyAccessor<CLASS_TYPE, PROPERTY_TYPE, &CLASS_TYPE::PROPERTY_NAME>; \
    PROPERTY_TYPE& access(CLASS_TYPE&, PROPERTY_TYPE*);                                     \
    }

    template <typename Class_t, typename Ret_t, Ret_t(Class_t::*Member)()>
    struct FunctionAccessorWith0Parameter
    {
        using Flag_t = Ret_t*;

        friend Ret_t call(Class_t& obj, Flag_t)
        {
            if constexpr (std::is_same_v<Ret_t, void>)
            {
                (obj.*Member)();
            }
            else
            {
                return (obj.*Member)();
            }
        }
    };

#ifdef DECLARE_FUNCTION_ACCESSOR_With_0_ARGS
#error DECLARE_FUNCTION_ACCESSOR_With_0_ARGS macro redefined!
#endif

#define DECLARE_FUNCTION_ACCESSOR_With_0_ARGS(CLASS_TYPE, RETURN_TYPE, FUNCTION_NAME)                   \
    namespace PrivateAccess                                                                             \
    {                                                                                                   \
    template class FunctionAccessorWith0Parameter<CLASS_TYPE, RETURN_TYPE, &CLASS_TYPE::FUNCTION_NAME>; \
    RETURN_TYPE call(CLASS_TYPE&, RETURN_TYPE*);                                                        \
    }

    template <typename Class_t, typename Ret_t, typename Parameter_t, Ret_t(Class_t::*Member)(Parameter_t)>
    struct FunctionAccessorWith1Parameter
    {
        using Flag_t = Ret_t*;

        friend Ret_t call(Class_t& obj, Parameter_t parameter, Flag_t)
        {
            if constexpr (std::is_same_v<Ret_t, void>)
            {
                (obj.*Member)(parameter);
            }
            else
            {
                return (obj.*Member)(parameter);
            }
        }
    };

#ifdef DECLARE_FUNCTION_ACCESSOR_With_1_ARGS
#error DECLARE_FUNCTION_ACCESSOR_With_1_ARGS macro redefined!
#endif

#define DECLARE_FUNCTION_ACCESSOR_With_1_ARGS(CLASS_TYPE, RETURN_TYPE, PARAMETER_TYPE, FUNCTION_NAME)                   \
    namespace PrivateAccess                                                                                             \
    {                                                                                                                   \
    template class FunctionAccessorWith1Parameter<CLASS_TYPE, RETURN_TYPE, PARAMETER_TYPE, &CLASS_TYPE::FUNCTION_NAME>; \
    RETURN_TYPE call(CLASS_TYPE&, PARAMETER_TYPE, RETURN_TYPE*);                                                        \
    }

}

#endif
