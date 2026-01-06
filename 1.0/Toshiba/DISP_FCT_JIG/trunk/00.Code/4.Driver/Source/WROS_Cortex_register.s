












__attribute__( ( always_inline ) ) static __INLINE void __enable_irq(void)
{
  __ASM volatile ("cpsie i");
}

__attribute__( ( always_inline ) ) static __INLINE void __disable_irq(void)
{
  __ASM volatile ("cpsid i");
}



















