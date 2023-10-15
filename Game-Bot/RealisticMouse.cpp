#include <windows.h>
#include <algorithm>
#include <random>
#include <utility>
#include <numbers>
#include <thread>

#include "RealisticMouse.h"

#ifdef max
#define DISABLED_max max
#undef max
#endif

#ifdef min
#define DISABLED_min min
#undef min
#endif

//namespace real_mouse
//{
//	Mouse& Mouse::Init()
//	{
//		static Mouse mouse{};
//		return mouse;
//	}
//
//	std::pair<std::int32_t, std::int32_t> Mouse::GetPosition()
//	{
//		POINT pos{};
//		if (!GetCursorPos(&pos))
//		{
//			throw std::runtime_error{ "Unable to get cursor position" };
//		}
//		return { pos.x, pos.y };
//	}
//
//	Mouse& Mouse::Click(std::chrono::milliseconds clickDuration/* = 100ms*/, Buttons button/* = Buttons::LEFT*/)
//	{
//		namespace thr = std::this_thread;
//
//		m_clickingTasks.AddTask([this, button, clickDuration]()
//			{
//				PushDown(button);
//				thr::sleep_for(clickDuration);
//				PushUp(button);
//			});
//
//		return *this;
//	}
//
//	Mouse& Mouse::Move(std::int32_t x, std::int32_t y, std::int32_t velocity/* = 1000*/)
//	{
//		m_movingTasks.AddTask(&Mouse::MoveImpl, this, x, y, velocity);
//		return *this;
//	}
//
//	Mouse& Mouse::PushDown(Buttons button/* = Buttons::LEFT*/)
//	{
//		auto [x, y] = GetPosition();
//		DWORD buttonEvent = (button == Buttons::LEFT ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTDOWN);
//		MOUSEINPUT mouseInput{ x, y, 0, (DWORD)MOUSEEVENTF_ABSOLUTE | buttonEvent };
//		INPUT input{ .type = INPUT_MOUSE, .mi = mouseInput }; // Careful! mi is a member of the anonimous union
//		SendInput(1, &input, sizeof(input));
//		return *this;
//	}
//
//	Mouse& Mouse::PushUp(Buttons button/* = Buttons::LEFT*/)
//	{
//		auto [x, y] = GetPosition();
//		DWORD buttonEvent = (button == Buttons::LEFT ? MOUSEEVENTF_LEFTUP : MOUSEEVENTF_RIGHTUP);
//		MOUSEINPUT mouseInput{ x, y, 0, (DWORD)MOUSEEVENTF_ABSOLUTE | buttonEvent };
//		INPUT input{ .type = INPUT_MOUSE, .mi = mouseInput }; // Careful! mi is a member of the anonimous union
//		SendInput(1, &input, sizeof(input));
//		return *this;
//	}
//
//	Mouse& Mouse::RealisticMove(std::int32_t x, std::int32_t y, std::int32_t velocity/* = 1000*/)
//	{
//		m_movingTasks.AddTask(&Mouse::RealisticMoveImpl, this, x, y, velocity);
//		return *this;
//	}
//
//	Mouse& Mouse::SetPosition(std::int32_t x, std::int32_t y)
//	{
//		SetCursorPos(x, y);
//		return *this;
//	}
//
//	const Mouse& Mouse::WaitForClick() const
//	{
//		m_clickingTasks.WaitAll();
//		return *this;
//	}
//
//	Mouse& Mouse::WaitForClick()
//	{
//		return const_cast<Mouse&>(const_cast<const Mouse&>(*this).WaitForClick());
//	}
//
//	const Mouse& Mouse::WaitForMove() const
//	{
//		m_movingTasks.WaitAll();
//		return *this;
//	}
//
//	Mouse& Mouse::WaitForMove()
//	{
//		return const_cast<Mouse&>(const_cast<const Mouse&>(*this).WaitForMove());
//	}
//
//	bool Mouse::IsClicking() const
//	{
//		return m_clickingTasks.IsBusy();
//	}
//
//	bool Mouse::IsMoving() const
//	{
//		return m_movingTasks.IsBusy();
//	}
//
//	void Mouse::MoveImpl(std::int32_t destX, std::int32_t destY, std::int32_t velocity/* = 1000*/)
//	{
//		namespace ch = std::chrono;
//
//		std::chrono::nanoseconds iterTimeout{ static_cast<std::int64_t>((1. / velocity) * 1000000) };
//
//		auto [startX, startY] = GetPosition();
//		auto xDist = destX - startX;
//		auto yDist = destY - startY;
//		auto remainDistance = std::hypot(xDist, yDist);
//
//		auto distPerCycleX = std::min((destX - startX) / remainDistance, 1.);
//		auto distPerCycleY = std::min((destY - startY) / remainDistance, 1.);
//
//		double currX = startX;
//		double currY = startY;
//
//		while (remainDistance > 1)
//		{
//			currX += distPerCycleX;
//			currY += distPerCycleY;
//
//			remainDistance = std::hypot(destX - currX, destY - currY);
//
//			SetPosition(static_cast<std::int32_t>(currX),
//				static_cast<std::int32_t>(currY));
//
//			std::this_thread::sleep_for(iterTimeout);
//		}
//
//		SetPosition(destX, destY);
//	}
//
//	void Mouse::RealisticMoveImpl(std::int32_t destX, std::int32_t destY, std::int32_t velocity/* = 1000*/)
//	{
//		// The algorithm was inspired by WindMouse
//		// https://ben.land/post/2021/04/25/windmouse-human-mouse-movement/
//
//		static const double sqrt3 = std::sqrt(3);   // Result force damping coefficient
//		static const double sqrt5 = std::sqrt(5);   // Velocity rising limit decreasing coefficient
//
//		constexpr double windMag = 1;               // Random fluctuations magnitude
//		constexpr double gravity = 2;             // Gravity force coefficient
//		constexpr std::int32_t dampDistance = 20;   // Random fluctuations damping distance
//		constexpr std::int32_t maxProjection = 2;   // Maximum result force projection value
//
//		auto [currentX, currentY] = GetPosition();
//		auto remainDist = std::hypot(destX - currentX, destY - currentY);
//		std::chrono::nanoseconds iterTimeout{ static_cast<std::int64_t>((1. / velocity) * 1000000) };
//
//		auto windForce = [sqrt3 = sqrt3, sqrt5 = sqrt5, windMag = windMag, damp = dampDistance](double dist, double prevX = 0, double prevY = 0)
//			-> std::pair<double, double>
//			{
//				auto mag = std::min(windMag, dist);
//				std::random_device rd{};
//				std::mt19937 mt{ rd() };
//				std::uniform_real_distribution distribution{ -1., 1. };
//
//				// Damping result force projections
//				double x = prevX / sqrt3;
//				double y = prevY / sqrt3;
//
//				// Don't apply random fluctuations if distance is lesser than damp distance
//				if (dist > damp)
//				{
//					x += distribution(mt) * mag / sqrt5;
//					y += distribution(mt) * mag / sqrt5;
//				}
//				return { x, y };
//			};
//
//		auto gravityForce = [g = gravity, destX = destX, destY = destY](double dist, std::int32_t currX, std::int32_t currY)
//			-> std::pair<double, double>
//			{
//				auto gravityVecX = (destX - currX) / dist;
//				auto gravityVecY = (destY - currY) / dist;
//				double x = g * gravityVecX;
//				double y = g * gravityVecY;
//				return { x, y };
//			};
//
//		double currStepX = 0;
//		double currStepY = 0;
//		double wX = 0;
//		double wY = 0;
//		double gX = 0;
//		double gY = 0;
//		double stepX = 0;
//		double stepY = 0;
//
//		while (remainDist > 1)
//		{
//			auto wind = windForce(remainDist, wX, wY);
//			wX = wind.first;
//			wY = wind.second;
//
//			auto grav = gravityForce(remainDist, currentX, currentY);
//			gX = grav.first;
//			gY = grav.second;
//
//			stepX += wX + gX;
//			stepY += wY + gY;
//
//			if (stepX > maxProjection || stepX < -maxProjection)
//			{
//				auto ratio = std::abs(maxProjection / stepX);
//				stepX = stepX * ratio;
//				stepY = stepY * ratio;
//			}
//			if (stepY > maxProjection || stepY < -maxProjection)
//			{
//				auto ratio = std::abs(maxProjection / stepY);
//				stepX = stepX * ratio;
//				stepY = stepY * ratio;
//			}
//
//#ifndef NDEBUG
//			if (stepX > maxProjection || stepX < -maxProjection
//				|| stepY > maxProjection || stepY < -maxProjection)
//			{
//				throw std::runtime_error("Too long step");
//			}
//#endif
//
//			MoveImpl(currentX + static_cast<std::int32_t>(stepX),
//				currentY + static_cast<std::int32_t>(stepY),
//				velocity);
//
//			double _ = 0;
//			stepX = std::modf(stepX, &_);
//			stepY = std::modf(stepY, &_);
//
//			auto [currX, currY] = GetPosition();
//			currentX = currX;
//			currentY = currY;
//			remainDist = std::hypot(destX - currentX, destY - currentY);
//
//			std::this_thread::sleep_for(iterTimeout);
//		}
//
//		MoveImpl(destX, destY, velocity);
//	}
//}