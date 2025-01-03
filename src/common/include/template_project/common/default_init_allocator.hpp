#include <template_project/common/common.hpp>
#include <memory>

BASIC_PROJECT_BEGIN_NAMESPACE

template <typename T, typename A = std::allocator<T>>
class BASIC_PROJECT_EXPORT default_init_allocator : public A
{
    using a_t = std::allocator_traits<A>;

public:
    template <typename U>
    struct rebind
    {
        using other =
            default_init_allocator<
                U, typename a_t::template rebind_alloc<U>>;
    };

    using A::A;

    template <typename U>
    void construct(U* ptr) noexcept(std::is_nothrow_default_constructible<U>::value)
    {
        ::new (static_cast<void*>(ptr)) U;
    }
    template <typename U, typename... Args>
    void construct(U* ptr, Args&&... args)
    {
        a_t::construct(static_cast<A&>(*this),
            ptr, std::forward<Args>(args)...);
    }
};

BASIC_PROJECT_END_NAMESPACE