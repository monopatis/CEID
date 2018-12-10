.arm
.text
.global main

main:

STMDB R13!, { R0-R12, R14}                   @E0

MOV R0, #0x20                                @E1
MOV R1, R0, LSL #2                           @E2
MVN R2, R1, LSL #1                           @E3

LDR R3, =Values                              @E4
LDR R4, [R3], #4                             @E5
LDRB R5, [R3], #2                            @E6
LDRSH R6, [R3], #2                           @E7
LDR R3, =Stack                               @E8					   
STMIA R3!, {R0-R2, R4-R6}                    @E9
LDMDB R3!, {R0-R2}                           @E10
LDMDB R3!, {R4-R6}                           @E11

LDMIA R13!, {R0-R12, PC}                     @E12

.data
Values:
.word 0xCAFEBABA
.word 0x82345678
Stack:
.word 0,0,0,0
.word 0,0,0,0
