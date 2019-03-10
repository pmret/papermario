
.section .text002B2000, "ax"

/* 316F30 002B2000 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 316F34 002B2004 3C040031 */  lui   $a0, %hi(D_003169F0) # $a0, 0x31
/* 316F38 002B2008 248469F0 */  addiu $a0, %lo(D_003169F0) # addiu $a0, $a0, 0x69f0
/* 316F3C 002B200C 3C050031 */  lui   $a1, %hi(D_00316A70) # $a1, 0x31
/* 316F40 002B2010 24A56A70 */  addiu $a1, %lo(D_00316A70) # addiu $a1, $a1, 0x6a70
/* 316F44 002B2014 3C068020 */  lui   $a2, 0x8020
/* 316F48 002B2018 24C60000 */  addiu $a2, $a2, 0
/* 316F4C 002B201C AFBF0010 */  sw    $ra, 0x10($sp)
/* 316F50 002B2020 0C00A5CF */  jal   func_0002973C
/* 316F54 002B2024 00000000 */   nop   
/* 316F58 002B2028 0C080000 */  jal   func_00200000
/* 316F5C 002B202C 00000000 */   nop   
/* 316F60 002B2030 8FBF0010 */  lw    $ra, 0x10($sp)
/* 316F64 002B2034 03E00008 */  jr    $ra
/* 316F68 002B2038 27BD0018 */   addiu $sp, $sp, 0x18

/* 316F6C 002B203C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 316F70 002B2040 3C040031 */  lui   $a0, %hi(D_00316A70) # $a0, 0x31
/* 316F74 002B2044 24846A70 */  addiu $a0, %lo(D_00316A70) # addiu $a0, $a0, 0x6a70
/* 316F78 002B2048 3C050031 */  lui   $a1, %hi(D_00316C00) # $a1, 0x31
/* 316F7C 002B204C 24A56C00 */  addiu $a1, %lo(D_00316C00) # addiu $a1, $a1, 0x6c00
/* 316F80 002B2050 3C068020 */  lui   $a2, %hi(D_80200080) # $a2, 0x8020
/* 316F84 002B2054 24C60080 */  addiu $a2, %lo(D_80200080) # addiu $a2, $a2, 0x80
/* 316F88 002B2058 AFBF0010 */  sw    $ra, 0x10($sp)
/* 316F8C 002B205C 0C00A5CF */  jal   func_0002973C
/* 316F90 002B2060 00000000 */   nop   
/* 316F94 002B2064 0C080020 */  jal   func_00200080
/* 316F98 002B2068 00000000 */   nop   
/* 316F9C 002B206C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 316FA0 002B2070 03E00008 */  jr    $ra
/* 316FA4 002B2074 27BD0018 */   addiu $sp, $sp, 0x18

/* 316FA8 002B2078 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 316FAC 002B207C 3C040031 */  lui   $a0, %hi(D_00316C00) # $a0, 0x31
/* 316FB0 002B2080 24846C00 */  addiu $a0, %lo(D_00316C00) # addiu $a0, $a0, 0x6c00
/* 316FB4 002B2084 3C050031 */  lui   $a1, %hi(D_00316D90) # $a1, 0x31
/* 316FB8 002B2088 24A56D90 */  addiu $a1, %lo(D_00316D90) # addiu $a1, $a1, 0x6d90
/* 316FBC 002B208C 3C06802B */  lui   $a2, %hi(D_802AE000) # $a2, 0x802b
/* 316FC0 002B2090 24C6E000 */  addiu $a2, %lo(D_802AE000) # addiu $a2, $a2, -0x2000
/* 316FC4 002B2094 AFBF0010 */  sw    $ra, 0x10($sp)
/* 316FC8 002B2098 0C00A5CF */  jal   func_0002973C
/* 316FCC 002B209C 00000000 */   nop   
/* 316FD0 002B20A0 0C0AB800 */  jal   func_002AE000
/* 316FD4 002B20A4 00000000 */   nop   
/* 316FD8 002B20A8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 316FDC 002B20AC 03E00008 */  jr    $ra
/* 316FE0 002B20B0 27BD0018 */   addiu $sp, $sp, 0x18

/* 316FE4 002B20B4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 316FE8 002B20B8 3C040031 */  lui   $a0, %hi(D_00316D90) # $a0, 0x31
/* 316FEC 002B20BC 24846D90 */  addiu $a0, %lo(D_00316D90) # addiu $a0, $a0, 0x6d90
/* 316FF0 002B20C0 3C050031 */  lui   $a1, %hi(D_00316F30) # $a1, 0x31
/* 316FF4 002B20C4 24A56F30 */  addiu $a1, %lo(D_00316F30) # addiu $a1, $a1, 0x6f30
/* 316FF8 002B20C8 3C06802B */  lui   $a2, %hi(D_802AE000) # $a2, 0x802b
/* 316FFC 002B20CC 24C6E000 */  addiu $a2, %lo(D_802AE000) # addiu $a2, $a2, -0x2000
/* 317000 002B20D0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 317004 002B20D4 0C00A5CF */  jal   func_0002973C
/* 317008 002B20D8 00000000 */   nop   
/* 31700C 002B20DC 0C0AB800 */  jal   func_002AE000
/* 317010 002B20E0 00000000 */   nop   
/* 317014 002B20E4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 317018 002B20E8 03E00008 */  jr    $ra
/* 31701C 002B20EC 27BD0018 */   addiu $sp, $sp, 0x18
