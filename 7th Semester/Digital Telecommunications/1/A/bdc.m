function [x]=bdc(b0,b)
%  [X]=BDC(b0,b) 
%
%  Binary-to-Decimal  conversion 
%
% b0 : sign bit ( 0 represent + sign, and 1 represents - sign)
% y  : binary bits after the binary point
% x  : a constant in decimal
% ---------------------------------------------------------------------------
% Example: x=-0.778; b=4;
%          [x]=bdc(b0,b);    % returns decimal result.
%
%      see also QROUND and DBC
%

% Sabri Gurbuz, 7-27-98
% Drexel University
% E-mail:sabrig@cbis.ece.drexel.edu
% *************************************************************************** 
 
N=length(b);      % finds the bit precision, B

y=0;

for i=1:N,
y=y+b(i)*2^(-i);  % for  x >0, converts from binary to decimal
end

x=-b0+y;

if x < 0
 
[b0,b]=dbc(x,N+1); %+1 bit is for sign
y=0;

  for i=1:N,
  y=y+b(i)*2^(-i);  % for x < 0, converts from binary to decimal
  end
end
x=-b0+y;
