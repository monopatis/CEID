function [s_m] = modulator(symbols_array, m)
% modulator(symbols_array, encoding)
%
% Takes as arguments the symbols array that are to be transmitted and
% encodes it
% Returns the modulated signal

% size of the array that has the sequence converted into symbols
size_of_symbols_array = length(symbols_array);

% period of symbol
T_symbol = 40;
% frequency of symbol
f_symbol = 1 / T_symbol;
% period of sample
T_sample = 1;
% period of ferousa
T_c = 4;
% frequency of ferousa
f_c = 1 / T_c;
% Energy per symbol
E_s = 1;

% orthogonal pulse
g = sqrt(2 * E_s / T_symbol);

% initialization of the symbols that we send
s_m = zeros(size_of_symbols_array, T_symbol / T_sample);

% computation of the transmitted signal
for i = 1: size_of_symbols_array
        for t = 1: T_symbol/T_sample
            s_m(i, t) = g * cos( 2*pi*f_c*t - 2*pi*symbols_array(i)/m );
        end
end

end
