function [st]=dpcm_deco_lpc(b, ai, bitsize)
%function [st]=dpcm_deco_lpc(b, ai, bitsize)
% b : input to decoder from communication channel
% bitsize : encoder bit size
% st : s_tilda (decoder output to lpf)

% __SG 8-2-98


[jj,size_ai] = size(ai);
[Q] = pcm_deco_quan(b, bitsize);
st=cumsum(Q(1:size_ai-1));
slen=length(Q);

m=1:size_ai-1;
j=2:size_ai;
for i=size_ai:slen   
   sth = sum(ai(i,j).*st(i-m));  
   st(i) = Q(i) + sth ;         
end   
