
#include <boost/asio.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <iostream>
using namespace std::chrono;
namespace asio = boost::asio;
using boost::asio::ip::tcp;

namespace
{

asio::awaitable<void> serve_client(tcp::socket socket)
{
    std::cout << "New client connected\n";
    auto ex = co_await asio::this_coro::executor;
    auto timer = asio::steady_timer{ex};
    auto counter = 0;
    while (true)
    {
        try
        {
            auto s = std::to_string(counter) + "\n";
            auto buf = asio::buffer(s.data(), s.size());
            auto n = co_await async_write(socket, buf, asio::use_awaitable);
            std::cout << "Wrote " << n << " byte(s)\n";
            ++counter;
            timer.expires_from_now(100ms);
            co_await timer.async_wait(asio::use_awaitable);
        }
        catch (...)
        {
            // Error or client disconnected
            break;
        }
    }
}

asio::awaitable<void> listen(tcp::endpoint endpoint)
{
    auto ex = co_await asio::this_coro::executor;
    auto a = tcp::acceptor{ex, endpoint};
    while (true)
    {
        auto socket = co_await a.async_accept(asio::use_awaitable);
        asio::co_spawn(ex, [s = std::move(socket)]() mutable
            { return serve_client(std::move(s)); }, asio::detached);
    }
}

} // namespace

int main()
{
    auto server = []
    {
        auto endpoint = tcp::endpoint{tcp::v6(), 37259};
        return listen(endpoint);
    };
    auto ctx = asio::io_context{};
    asio::co_spawn(ctx, server, asio::detached);
    ctx.run(); // Run event loop from main thread
}