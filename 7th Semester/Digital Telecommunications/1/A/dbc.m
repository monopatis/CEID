function [b0,b,bb]=dbc(x,B)
% [b0,b,bb]=dbc(x,B)
%
% Decimal-to-Binary conversion using B+1 bit precision
%
% x  : a constant in decimal
% B  : number of the precision bit
% b0 : sign bit ( 0 represent + sign, and 1 represents - sign)
% b  : binary bits after the binary point
% bb : (B+1)st bit
% ---------------------------------------------------------------------------
% Example: x=-0.778; b=4;
%          [b0,b,bb]=dbc(x,B);    % returns binary result.
%          [b]=qround(b,bb);      % rounds off the binary input, returns binary.
%          [Y]=bdc(b0,b);         % returns decimal result.
%
%      see also QROUND and BDC

%
% Sabri Gurbuz, 7-27-98
% Drexel University
% E-mail:sabrig@cbis.ece.drexel.edu
% *************************************************************************** 
B = B-1;
if x>1, error(' x is not normilized.'); end  
if x>=0
	b0=0;		% + sign is assigned.
	z=x;

else 
	b0=1;		% - sign is assigned. 
	z=-x;

end

if z >= 0

    for i=1:B,
	a=2*z;

     if a>=1
	b(i)=1;
	z=a-1;
     else 
        b(i)=0; 
        z=a;
     end
    end

	a=2*z;        % finds B+1 th bit in the binary point part

     if a>=1
	bb=1;
      else 
        bb=0; 
     end
    
end


 	 
