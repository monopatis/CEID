.arm
.text
.global main
main:
STMDB R13!, {R0-R12,R14}
LDR R0,=table
LDR R1,=error
SUB R1,R1,R0
BL Subrtn
BL Test
LDMIA R13!, {R0-R12,R14}
MOV PC,LR

Subrtn:
MOV R6, R0
MOV R7, R1
SUB R8,R7,#1
STMDB R13!, {R0-R8}
MOV R1, #0
there:
ADD R3, R1, #1
LDRB R0, [R6, R1]
MOV R2, R1
here:
LDRB R4, [R6, R3]
CMP R0, R4
MOVHI R2, R3
MOVHI R0, R4
ADD R3, R3, #1
CMP R3, R7
BLO here
LDRB R5, [R6, R1]
STRB R0, [R6, R1]
STRB R5, [R6, R2]
ADD R1, R1, #1
CMP R1,R8
BLO there
LDMIA R13!, {R0-R8}
MOV PC,LR

Test:
STMDB R13!, {R0-R4,LR}
MOV R4, #1
Loop:
LDRB R2, [R0]
LDRB R3, [R0, #1]
CMP R3, R2
BLO Stop
ADD R0, R0, #1
ADD R4, R4, #1
CMP R4, R1
BLO Loop
BL End
End:
LDMIA R13!, {R0-R4,LR}
MOV PC,LR
Stop:
MOV R2, #1
LDR R0,=error
STRB R2, [R0]
BL End

.data

table:
.byte 0x45, 0x82, 0x34, 0xDA, 0x10
.byte 0x55, 0x12, 0x84, 0xD5, 0x19
.byte 0x65, 0x32, 0x74, 0xDF, 0x11
.byte 0x75, 0x42, 0x04, 0xD3, 0x15
error:
.byte 0x0
