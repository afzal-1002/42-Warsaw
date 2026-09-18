/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/21 21:03:28 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point const a(0.0f, 0.0f);
	Point const b(5.0f, 0.0f);
	Point const c(0.0f, 5.0f);
	Point const inside(1.0f, 1.0f);
	Point const outside(4.0f, 4.0f);
	Point const edge(2.5f, 0.0f);
	Point const vertex(0.0f, 0.0f);

	std::cout << "Inside point: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside point: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "Edge point: " << bsp(a, b, c, edge) << std::endl;
	std::cout << "Vertex point: " << bsp(a, b, c, vertex) << std::endl;
	return (0);
}
