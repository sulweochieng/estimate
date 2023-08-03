/**
 * share_of_a - calculates the share of 'a' in the ratio.
 * @a: member representative of the Senior level.
 * @b: member representative of the Mid-level.
 * @c: member representative of the Junior level.
 * Return: returns the share of 'a'.
 */
float share_of_a(int a, int b, int c)
{
	return ((float)a / (a + b + c));
}
/**
 * share_of_b - calculates the share of 'b' in the ratio
 * @a: member representative of the Senior level.
 * @b: member representative of the Mid-level.
 * @c: member representative of the Junior level.
 * Return: returns the share of 'b'.
 */
float share_of_b(int a, int b, int c)
{
	return ((float)b / (a + b + c));
}
/**
 * share_of_c - calculates the share of 'c' in the ratio
 * @a: member representative of the Senior level.
 * @b: member representative of the Mid-level.
 * @c: member representative of the Junior level.
 * Return: returns the share of 'c'.
 */
float share_of_c(int a, int b, int c)
{
	return ((float)c / (a + b + c));
}
