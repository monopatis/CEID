close all
clear

load source.mat
% s=(x(1:181))';
s=x';

%lpc and encoder-decoder parameters
lpclen=20;
bitsize=input('bitsize=');
fprintf('\nPlease wait... data length is %i\n',length(s))
%LPF parameters
%tap=100;
%cf=.15;

% DPCM with predictor
[Q,b, ai] = dpcm_enco_lpc(s, lpclen, bitsize);
[st]=dpcm_deco_lpc(b, ai, bitsize);
%Sa=lpf(tap,cf,st);
%[xa,ya]=stairs(tn,Sa);

figure
subplot(2,1,1),plot(s,'r');
ylabel('amplitude');
title('DPCM with predictor (red:input, green:decoder)');
subplot(2,1,2),plot(st,'g');
ylabel('amplitude');
% subplot(3,1,3),plot(Sa,'b');
% ylabel('amplitude');
xlabel('index, n');
grid

