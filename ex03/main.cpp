/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:03:46 by MP9               #+#    #+#             */
/*   Updated: 2026/11/04 15:50:57 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

static void test(const char *name, Point const a, Point const b, Point const c,
	Point const p, bool expected)
{
	bool result = bsp(a, b, c, p);
	std::cout << (result == expected ? "[OK]   " : "[FAIL] ") << name
		<< " -> " << (result ? "true" : "false") << std::endl;
}

int main(void)
{
	Point const a(0, 0);
	Point const b(10, 0);
	Point const c(0, 10);

	test("inside (1, 1)",              a, b, c, Point(1, 1), true);
	test("inside (2.5, 2.5)",          a, b, c, Point(2.5f, 2.5f), true);
	test("inside, close to edge (0.5, 9.25)", a, b, c, Point(0.5f, 9.25f), true);
	test("outside (10, 10)",           a, b, c, Point(10, 10), false);
	test("outside (-1, 5)",            a, b, c, Point(-1, 5), false);
	test("vertex (0, 0)",               a, b, c, Point(0, 0), false);
	test("vertex (10, 0)",              a, b, c, Point(10, 0), false);
	test("on edge (5, 0)",          a, b, c, Point(5, 0), false);
	test("on hypotenuse (5, 5)",     a, b, c, Point(5, 5), false);
	test("reversed vertex order",     c, b, a, Point(1, 1), true);
	test("negative coordinates",      Point(-5, -5), Point(5, -5), Point(0, 5),
		Point(0, 0), true);
	test("degenerate triangle (line)", Point(0, 0), Point(5, 5), Point(10, 10),
		Point(3, 3), false);
	return (0);
}
