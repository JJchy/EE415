/* fixed_point.h

  This header file is made to support floating-point arithmetic
  in the kernel. The fundamental idea is to treat the rightmost
  bits of an integer as representing a fraction. For example,
  we can designate the lowest 14 bits of a signed 32-bit integer
  as fractional bits, so that an integer x represents the real
  number x/(2^14). This is called a 17.14 fixed-point number
  representation.

  A number in 17.14 format represents, at maximum, a value of
  (2^31 - 1)/2^14 ~ 131,071,999.

  The following functions below are the implementation of
  fixed-point arithmetic operations. In the function, x and y
  are fixed-point numbers, n is an integer, and f is 1<<pp
  
  (q.pp format)                                                */


#define fixedp_t int

#define pp 14
#define ff 1<<(pp)

#define NtoF(n) ((n) * (ff))
#define FtoN_Z(x) ((x) / (ff))
#define FtoN_N(x) ((x) >= 0 ? ((x) + (ff) / 2) / (ff) : ((x) - (ff) / 2) / (ff))
#define add(x, y) ((x) + (y))
#define addn(x, n) ((x) + (n)*(ff))
#define sub(x, y) ((x) - (y))
#define subn(x, n) ((x) - (n)*(ff))
#define mul(x, y) (((int64_t) (x)) * (y) / (ff))
#define muln(x, n) ((x) * (n))
#define div(x, y) (((int64_t) (x)) * (ff) / (y))
#define divn(x, n) ((x) / (n))
