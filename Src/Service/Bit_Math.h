#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, BIT)           	(REG|=(1<<BIT))
#define CLR_BIT(REG, BIT)						(REG&=(~(1<<BIT)))
#define TOGGLE_BIT(REG, BIT)					(REG^=(1<<BIT))

#endif /* BIT_MATH.H */