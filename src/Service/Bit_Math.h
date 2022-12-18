#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, BIT)           	(REG|=(1<<BIT))
#define CLR_BIT(REG, BIT)						(REG&=(~(1<<BIT)))
#define TOGGLE_BIT(REG, BIT)					(REG^=(1<<BIT))


#define SET_BIT_PER_BB(REG, BIT)  ((*((volatile uint32_t *)( 0x42000000 + (((uint32_t) (&REG) - 0x40000000) *32 ) + ((BIT) *4) ))) =1)
#define CLR_BIT_PER_BB(REG, BIT)  ((*((volatile uint32_t *)(0x42000000 + (((uint32_t)(&REG) - 0x40000000) *32 ) + ((BIT) *4) ))) =0)

#endif /* BIT_MATH.H */