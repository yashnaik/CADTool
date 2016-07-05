INPUTS  : a b c
OUTPUTS : z x
REGS    : d e f xrin zrin

d = a + b
f = a * c

if ( a ) {
e = a + c
g = d > e
}
zrin = g ? d : e

xrin = f - d  

x = xrin
z = zrin
