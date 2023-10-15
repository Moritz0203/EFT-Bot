#pragma once

#include <chrono>
#include <mutex>
#include <iostream>
#include <queue>
#include <future>
//
//namespace real_mouse
//{
//	using namespace std::chrono_literals;
//
//	namespace utils
//	{
//		class ThreadPool
//		{
//		private:
//			class Locker
//			{
//			public:
//				Locker() = default;
//				Locker(const Locker&) = delete;
//				Locker(Locker&&) = default;
//				Locker& operator=(const Locker&) = delete;
//				Locker& operator=(Locker&&) = default;
//				~Locker() = default;
//
//				[[maybe_unused]] Locker& Lock() noexcept
//				{
//					++lockersCount;
//					return *this;
//				}
//
//				[[maybe_unused]] Locker& Unlock() noexcept
//				{
//					if (lockersCount)
//					{
//						--lockersCount;
//					}
//					return *this;
//				}
//
//				[[nodiscard]] bool IsLocked() const noexcept
//				{
//					return lockersCount;
//				}
//
//			private:
//				std::atomic<size_t> lockersCount = 0;
//			};
//
//		public:
//			using Task = std::pair<size_t, std::future<void>>;
//
//			ThreadPool(size_t threadsCount, std::queue<Task> tasks = {})
//				: m_threads{}, m_tasksQueue{ std::move(tasks) }, m_newTaskWaiter{},
//				m_queueLock{}, m_terminate{ false }
//			{
//				m_threads.reserve(threadsCount);
//				for (size_t i = 0; i < threadsCount; ++i)
//				{
//					m_threads.emplace_back(std::thread{ &ThreadPool::ProcessTasks, this });
//				}
//			}
//
//			ThreadPool() = delete;
//			ThreadPool(const ThreadPool&) = delete;
//			ThreadPool(ThreadPool&&) = delete;
//			ThreadPool& operator=(const ThreadPool&) = delete;
//			ThreadPool& operator=(ThreadPool&&) = delete;
//
//			~ThreadPool()
//			{
//				Terminate();
//			}
//
//			template<typename Func, typename ...Args>
//				requires(std::is_invocable_v<Func, Args...>)
//			[[maybe_unused]] ThreadPool& AddTask(Func&& task, Args&& ...args)
//			{
//				std::lock_guard guard{ m_queueLock };
//				auto&& future = std::async(std::launch::deferred, std::forward<Func>(task),
//					std::forward<Args>(args)...);
//				m_tasksQueue.emplace(Task{ m_tasksQueue.size(), std::move(future) });
//				m_newTaskWaiter.notify_one();
//
//				return *this;
//			}
//
//			void Terminate()
//			{
//				m_terminate = true;
//				m_newTaskWaiter.notify_all();
//				for (auto&& thread : m_threads)
//				{
//					thread.join();
//				}
//			}
//
//			[[maybe_unused]] ThreadPool& WaitAll()
//			{
//				std::unique_lock lock{ m_queueLock };
//				m_endAllTasksWaiter.wait(lock, [this]()
//					{
//						return m_tasksQueue.empty() && !m_processLocker.IsLocked();
//					});
//				return *this;
//			}
//
//			[[nodiscard]] bool IsBusy() const
//			{
//				std::lock_guard guard{ m_queueLock };
//				return !m_tasksQueue.empty() || m_processLocker.IsLocked();
//			}
//
//		private:
//			void ProcessTasks()
//			{
//				while (true)
//				{
//					std::unique_lock lock{ m_queueLock };
//					m_processLocker.Unlock();
//					m_newTaskWaiter.wait(lock, [this]() { return !m_tasksQueue.empty() || m_terminate; });
//
//					if (m_tasksQueue.empty() && m_terminate)
//					{
//						break;
//					}
//
//					m_processLocker.Lock();
//					auto task = std::move(m_tasksQueue.front());
//					m_tasksQueue.pop();
//
//					lock.unlock();
//					task.second.wait(); // Process task in calling thread
//					lock.lock();
//
//					if (m_tasksQueue.empty())
//					{
//						m_endAllTasksWaiter.notify_all();
//					}
//				}
//			}
//
//			std::vector<std::thread>        m_threads;
//			std::queue<Task>                m_tasksQueue;
//			std::condition_variable         m_newTaskWaiter;
//			std::condition_variable         m_endAllTasksWaiter;
//			mutable std::mutex              m_queueLock;
//			std::atomic_bool                m_terminate;
//			Locker                          m_processLocker;
//		};
//	}
//
//	// Class that represents the computer mouse.
//	class Mouse
//	{
//	public:
//		// Enum that represents mouse's buttons.
//		// Note, that mouse wheel is not provided now.
//		enum class Buttons
//		{
//			LEFT = 0,
//			RIGHT = 1,
//		};
//
//		Mouse(const Mouse&) = delete;
//		Mouse(Mouse&&) = delete;
//		Mouse& operator=(const Mouse&) = delete;
//		Mouse& operator=(Mouse&&) = delete;
//		~Mouse() = default;
//
//		// Mouse class can has only one object.
//		// In that cause Mouse can be obtained only by this fabric method.
//		static Mouse& Init();
//
//		// Returns current coordinates. Don't require Mouse object creation.
//		static std::pair<std::int32_t, std::int32_t> GetPosition();
//
//		// Simulates mouse click on current coordinates.
//		// Takes the mouse button and the time during which mouse button will be pressed.
//		[[maybe_unused]] Mouse& Click(std::chrono::milliseconds clickDuration = 100ms, Buttons button = Buttons::LEFT);
//
//		// Moves mouse to given coordinates.
//		// Note that, unlike SetPosition(....), this function moves mouse smoothly.
//		[[maybe_unused]] Mouse& Move(std::int32_t x, std::int32_t y, std::int32_t velocity = 1000);
//
//		// Pushes down given mouse button and holds one in pressed state.
//		[[maybe_unused]] Mouse& PushDown(Buttons button = Buttons::LEFT);
//
//		// Pushes up given mouse button and holds one in unpressed state.
//		[[maybe_unused]] Mouse& PushUp(Buttons button = Buttons::LEFT);
//
//		// Moves mouse to given coordinates.
//		// Note that, unlike SetPosition(....), this function moves mouse smoothly.
//		[[maybe_unused]] Mouse& RealisticMove(std::int32_t x, std::int32_t y, std::int32_t velocity = 1000);
//
//		// Sets mouse coordinates to given ones.
//		// Note that, unlike Move(....), this function instantly sets coordinates.
//		[[maybe_unused]] Mouse& SetPosition(std::int32_t x, std::int32_t y);
//
//		// Blocks calling thread, until all Click() operations become finished.
//		[[maybe_unused]] const Mouse& WaitForClick() const;
//		// Blocks calling thread, until all Click() operations become finished.
//		// Non-const version. Do the same as WaitForClick const.
//		[[maybe_unused]] Mouse& WaitForClick();
//
//		// Blocks calling thread, until all moving operations become finished.
//		[[maybe_unused]] const Mouse& WaitForMove() const;
//		// Blocks calling thread, until all moving operations become finished.
//		// Non-const version. Do the same as WaitForClick const.
//		[[maybe_unused]] Mouse& WaitForMove();
//
//		//// Observers
//
//		// Returns true if any thread processing click operation (here is underlying operations counter). False otherwise.
//		[[nodiscard]] bool                 IsClicking() const;
//
//		//Returns true if any thread processing moving operation (include RealisticMove and similar). False otherwise.
//		[[nodiscard]] bool                 IsMoving() const;
//
//	private:
//		// Don't change threads count in ThreadPool inside Mouse class!
//		// It causes to undefined execution order of any operation.
//		Mouse() : m_movingTasks{ 1 }, m_clickingTasks{ 1 } {}
//
//		void MoveImpl(std::int32_t x, std::int32_t y, std::int32_t velocity = 1000);
//		void RealisticMoveImpl(std::int32_t x, std::int32_t y, std::int32_t velocity = 1000);
//
//		mutable utils::ThreadPool m_movingTasks;
//		mutable utils::ThreadPool m_clickingTasks;
//	};
//}