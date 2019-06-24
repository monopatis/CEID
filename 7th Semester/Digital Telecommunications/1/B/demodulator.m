function [r] = demodulator(received_signal, m)
% [r1, r2] = demodulator(received_signal)
% The demodulator function takes as argument the received signal and finds
% the components (r1, ...) of every transmitted signal

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
pulse = sqrt(2 * E_s / T_symbol);

[L_symbol, T_symbol] = size(received_signal);
% demodulation
for t = 1: T_symbol
        y1(t, 1) = pulse * cos(2 * pi * f_c * t);
        y2(t, 1) = pulse * sin(2 * pi * f_c * t);
end
% calculation of the 2 components
r = [received_signal * y1, received_signal * y2];
end
