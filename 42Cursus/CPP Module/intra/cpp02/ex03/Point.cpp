/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/21 21:03:28 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue)
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
}

Fixed const &Point::getX(void) const
{
	return (this->x);
}

Fixed const &Point::getY(void) const
{
	return (this->y);
}

static Fixed sign(Point const point, Point const edgeStart, Point const edgeEnd)
{
	Fixed pointXFromEnd = point.getX() - edgeEnd.getX();
	Fixed pointYFromEnd = point.getY() - edgeEnd.getY();

	Fixed edgeX = edgeStart.getX() - edgeEnd.getX();
	Fixed edgeY = edgeStart.getY() - edgeEnd.getY();

	Fixed firstPart = pointXFromEnd * edgeY;
	Fixed secondPart = edgeX * pointYFromEnd;

	return (firstPart - secondPart);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed zero(0);
	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, c, a);

	if (d1 == zero || d2 == zero || d3 == zero)
		return (false);
	if ((d1 > zero && d2 > zero && d3 > zero) ||
		(d1 < zero && d2 < zero && d3 < zero))
		return (true);
	return (false);
}
