AREA test, CODE, READONLY
    ENTRY
    CODE32
START LDR R4, =0x00090010
    LDR R13, =0x00090020
    MOV R0, #15
    B START
    END
