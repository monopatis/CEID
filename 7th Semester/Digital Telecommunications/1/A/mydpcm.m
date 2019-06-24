% Removing all variables, functions, and MEX-files from memory, leaving the
% workspace empty.
clear all
% Deleting all figures whose handles are not hidden.
close all

% Deleting all figures including those with hidden handles.
close all hidden

% Clearing all input and output from the Command Window display giving us a clean screen.
clc

% Opening the file 'TEOTH.mp3' in the read access mode.
fid = fopen ('TEOTH.mp3','r');

% Generating the input signal 'm(t)' by reading the binary data in 16 bit
% integer format from the specified file and writing it into a matrix
% 'm(t)' and the number of elements successfully read is returned into an
% output argument 'count'.
[m,count] = fopen (fid,'int16');
load source.mat
% Redefining the count for efficiency.
count = 8500;
% Setting the sampling frequency.
% because the audio signal has a maximum frequency of 4K and according to
% Nyquist criteria, we get the following sampling frequency.
Fs = 8000;
% Setting the sampling instant.
Ts = 1;
% Setting the number of samples to be used.
No_Samples = (2*Fs)+Ts;
% Define the time vector for the calculations.
time = [1:Fs/64];


% Calculating maximum value of the input signal 'm(t)'.
Mp = max (m)


% Setting number of bits in a symbol.
bits = 5;


% Number of levels of uniform quantization.
levels = 2^bits;


% Calculating the bit rate.
bit_rate = 8000*bits;


% Since the DPCM is implemented by the linear predictor (transversal
% predictor) Hence setting up the prediction coefficient 'alpha'.
alpha = 0.45;


% Transmitting the difference.
% Since there is no estimated value before the first sample so we get
diff_sig(1) = m(1);


% Calculating the rest of the values of the difference signal with the help
% of coefficient.
for k = 2:count,
    diff_sig(k) = m(k) - alpha*m(k-1);
end


% Calculating maximum value of the input signal 'diff_sig(t)',i.e, to be
% quantized.
Dp = max (diff_sig)


% Calculating the step size of the quantization.
step_size = (2*Mp)/levels


% Quantizing the difference signal.
for k = 1:No_Samples,
    samp_in(k) = m(k*Ts);
    quant_in(k) = samp_in(k)/step_size;
    error(k) = (samp_in(k) - quant_in(k))/No_Samples;
end

% quant_in = diff_sig/step_size;


% Indicating the sign of the input signal 'm(t)' and calculating the
% quantized signal 'quant_out'.
signS = sign (m);
quant_out = quant_in;
for i = 1:count,
    S(i) = abs (quant_in(i)) + 0.5;
    quant_out(i) = signS(i)*round(S(i))*step_size;
end


% Decoding the signal using the quantized difference signal.
s_out = quant_out;
s_out(1) = quant_out(1);
for k = 2:count,
    s_out(k) = quant_out(k) + alpha*s_out(k-1);
end


% Calculating the quantization noise 'Nq'.
Nq = (((step_size)^2)/12)*((Mp/Dp)^2)


% Calculating signal to noise ratio 'SNR'.
SNR = 1.5*(levels^2)
SNR_db = 10*log10(SNR)


% Plotting the input signal 'm(t)'.
%figure;
subplot(4,1,1);
plot(time,m(time),time,s_out(time),'r');
title('Input Speech Signal');
xlabel('Time');
ylabel('m(t)');
grid on;


% Plotting the quantized signal 'quant_in(t)'.
%figure;
subplot(4,1,2);
stem(time,quant_in(time),'r');
title('Quantized Speech Signal');
xlabel('Time');
ylabel('Levels');
grid on;


% Plotting the DPCM signal 's_out(t)'.
%figure;
subplot(4,1,3);
plot(time,s_out(time));
title('Decoded DPCM Speech Signal');
xlabel('Time');
ylabel('Dq(t)');
grid on;


% Plotting the error signal 'error(t)'.
subplot(4,1,4);
plot(time,error(time));
title('Error Signal');
xlabel('Time');
ylabel('Error(t)');
grid on;

% Removing all variables, functions, and MEX-files from memory, leaving the
% workspace empty.
clear all