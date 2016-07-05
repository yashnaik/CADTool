`timescale 1ns / 1ps
module HLSM(Clk,Rst,Start,Done a,b,c,z,x,y);

input Clk,Rst;
input Start;
 output Done;
input [31:0] a;
input [31:0] b;
input [31:0] c;
output reg [31:0] z;
output reg [31:0] x;
output reg [31:0] y;
reg [31:0] d;
reg [31:0] e;
reg [31:0] f;
reg [31:0] g;
reg [31:0] xrin;
reg [31:0] zrin;
reg state [5:0] = 12;

parameter state1 = 0;
parameter state2 = 1;
parameter state3 = 2;
parameter state4 = 3;
parameter state5 = 4;
parameter state6 = 5;
parameter state7 = 6;
parameter state8 = 7;
parameter state9 = 8;
parameter state10 = 9;
parameter state11 = 10;
parameter state12 = 11;
parameter wait_state = 12;
parameter final_state = 13;
parameter mul_dummy =14;

always@( posedge Clk ) begin
if( Rst == 1 ) begin
a<=0;
b<=0;
c<=0;
z<=0;
x<=0;
y<=0;
d<=0;
e<=0;
f<=0;
g<=0;
xrin<=0;
zrin<=0;
Done<=0
state<=wait_state;
end

else begin
case(state)
wait_state: begin
if(Start==1)begin
state<=state1;
end
else  begin
state<=wait_state;
end
end
state1: begin
d<=a+b;
f<=a*c;
state<=state2;
end
state2: begin
e<=a+c;
state<=state3;
end
state4: begin
if(a==1) begin
state<=state5;
end
else begin
state<=state7;
end
state5: begin
y<=a-b;
e<=a*c;
state<=state6;
end
state6: begin
state<=state7;
end
state7:  begin 
state<=state9;
end
state9: begin
if(d>e)
begin
g<=1;
end
else begin
g<=0;
end
xrin<=f-d;
state<=state10;
end
state10: begin
if(g==1) begin
zrin<=d;
end
else  begin
zrin<=e;
end
x<=xrin;
state<=state11;
end
state11: begin
z<=zrin;
state<=final_state;
end
final_state: begin
Done<=1;
state<=wait_state;
end
endcase
end
end

endmodule