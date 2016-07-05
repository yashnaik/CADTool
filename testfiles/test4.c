INPUTS  : a b c
OUTPUTS : z x y
REGS    : d e f g xrin zrin

d = a + b
f = a * c
e = a + c
if ( a ) {
y = a - b
e = a * c
}
g = d > e
zrin = g ? d : e
xrin = f - d
x = xrin
z = zrin
