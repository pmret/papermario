.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80026AD4
/* 1ED4 80026AD4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1ED8 80026AD8 3C04800A */  lui       $a0, %hi(D_8009A654)
/* 1EDC 80026ADC 8C84A654 */  lw        $a0, %lo(D_8009A654)($a0)
/* 1EE0 80026AE0 3C05800A */  lui       $a1, %hi(D_8009A64C)
/* 1EE4 80026AE4 24A5A64C */  addiu     $a1, $a1, %lo(D_8009A64C)
/* 1EE8 80026AE8 AFB00010 */  sw        $s0, 0x10($sp)
/* 1EEC 80026AEC 3C10800A */  lui       $s0, %hi(D_8009A630)
/* 1EF0 80026AF0 2610A630 */  addiu     $s0, $s0, %lo(D_8009A630)
/* 1EF4 80026AF4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1EF8 80026AF8 AFB10014 */  sw        $s1, 0x14($sp)
/* 1EFC 80026AFC 3C018007 */  lui       $at, %hi(D_800741D0)
/* 1F00 80026B00 A42041D0 */  sh        $zero, %lo(D_800741D0)($at)
/* 1F04 80026B04 8E020000 */  lw        $v0, ($s0)
/* 1F08 80026B08 24830230 */  addiu     $v1, $a0, 0x230
/* 1F0C 80026B0C 30420008 */  andi      $v0, $v0, 8
/* 1F10 80026B10 10400007 */  beqz      $v0, .L80026B30
/* 1F14 80026B14 ACA30000 */   sw       $v1, ($a1)
/* 1F18 80026B18 3C038007 */  lui       $v1, %hi(D_800741D4)
/* 1F1C 80026B1C 246341D4 */  addiu     $v1, $v1, %lo(D_800741D4)
/* 1F20 80026B20 8C620000 */  lw        $v0, ($v1)
/* 1F24 80026B24 38420001 */  xori      $v0, $v0, 1
/* 1F28 80026B28 08009B65 */  j         .L80026D94
/* 1F2C 80026B2C AC620000 */   sw       $v0, ($v1)
.L80026B30:
/* 1F30 80026B30 3C03DA38 */  lui       $v1, 0xda38
/* 1F34 80026B34 34630003 */  ori       $v1, $v1, 3
/* 1F38 80026B38 24820238 */  addiu     $v0, $a0, 0x238
/* 1F3C 80026B3C ACA20000 */  sw        $v0, ($a1)
/* 1F40 80026B40 3C028007 */  lui       $v0, %hi(D_80074188)
/* 1F44 80026B44 24424188 */  addiu     $v0, $v0, %lo(D_80074188)
/* 1F48 80026B48 AC830230 */  sw        $v1, 0x230($a0)
/* 1F4C 80026B4C 0C04456C */  jal       func_801115B0
/* 1F50 80026B50 AC820234 */   sw       $v0, 0x234($a0)
/* 1F54 80026B54 8E020000 */  lw        $v0, ($s0)
/* 1F58 80026B58 30420002 */  andi      $v0, $v0, 2
/* 1F5C 80026B5C 14400003 */  bnez      $v0, .L80026B6C
/* 1F60 80026B60 00000000 */   nop
/* 1F64 80026B64 0C00B4F3 */  jal       func_8002D3CC
/* 1F68 80026B68 0000202D */   daddu    $a0, $zero, $zero
.L80026B6C:
/* 1F6C 80026B6C 0C038090 */  jal       func_800E0240
/* 1F70 80026B70 00000000 */   nop
/* 1F74 80026B74 0C0B0FB9 */  jal       func_802C3EE4
/* 1F78 80026B78 00000000 */   nop
/* 1F7C 80026B7C 0C04F4B4 */  jal       func_8013D2D0
/* 1F80 80026B80 00000000 */   nop
/* 1F84 80026B84 0C04A1D8 */  jal       func_80128760
/* 1F88 80026B88 00000000 */   nop
/* 1F8C 80026B8C 0C051CB0 */  jal       func_801472C0
/* 1F90 80026B90 00000000 */   nop
/* 1F94 80026B94 0C016711 */  jal       func_80059C44
/* 1F98 80026B98 00000000 */   nop
/* 1F9C 80026B9C 0C04605A */  jal       func_80118168
/* 1FA0 80026BA0 00000000 */   nop
/* 1FA4 80026BA4 8E020000 */  lw        $v0, ($s0)
/* 1FA8 80026BA8 3C030001 */  lui       $v1, 1
/* 1FAC 80026BAC 00431024 */  and       $v0, $v0, $v1
/* 1FB0 80026BB0 14400003 */  bnez      $v0, .L80026BC0
/* 1FB4 80026BB4 00000000 */   nop
/* 1FB8 80026BB8 0C0532DD */  jal       func_8014CB74
/* 1FBC 80026BBC 00000000 */   nop
.L80026BC0:
/* 1FC0 80026BC0 8E020000 */  lw        $v0, ($s0)
/* 1FC4 80026BC4 30420002 */  andi      $v0, $v0, 2
/* 1FC8 80026BC8 14400009 */  bnez      $v0, .L80026BF0
/* 1FCC 80026BCC 3C100010 */   lui      $s0, 0x10
/* 1FD0 80026BD0 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 1FD4 80026BD4 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 1FD8 80026BD8 80420078 */  lb        $v0, 0x78($v0)
/* 1FDC 80026BDC 14400004 */  bnez      $v0, .L80026BF0
/* 1FE0 80026BE0 00000000 */   nop
/* 1FE4 80026BE4 0C00B4F3 */  jal       func_8002D3CC
/* 1FE8 80026BE8 24040001 */   addiu    $a0, $zero, 1
/* 1FEC 80026BEC 3C100010 */  lui       $s0, 0x10
.L80026BF0:
/* 1FF0 80026BF0 3C11800A */  lui       $s1, %hi(D_8009A630)
/* 1FF4 80026BF4 2631A630 */  addiu     $s1, $s1, %lo(D_8009A630)
/* 1FF8 80026BF8 8E220000 */  lw        $v0, ($s1)
/* 1FFC 80026BFC 36100010 */  ori       $s0, $s0, 0x10
/* 2000 80026C00 00501024 */  and       $v0, $v0, $s0
/* 2004 80026C04 14400003 */  bnez      $v0, .L80026C14
/* 2008 80026C08 00000000 */   nop
/* 200C 80026C0C 0C04A523 */  jal       func_8012948C
/* 2010 80026C10 00000000 */   nop
.L80026C14:
/* 2014 80026C14 0C04A1BC */  jal       func_801286F0
/* 2018 80026C18 00000000 */   nop
/* 201C 80026C1C 0C051DF3 */  jal       func_801477CC
/* 2020 80026C20 00000000 */   nop
/* 2024 80026C24 0C04F494 */  jal       func_8013D250
/* 2028 80026C28 00000000 */   nop
/* 202C 80026C2C 8E220000 */  lw        $v0, ($s1)
/* 2030 80026C30 24030010 */  addiu     $v1, $zero, 0x10
/* 2034 80026C34 00501024 */  and       $v0, $v0, $s0
/* 2038 80026C38 14430003 */  bne       $v0, $v1, .L80026C48
/* 203C 80026C3C 00000000 */   nop
/* 2040 80026C40 0C04A523 */  jal       func_8012948C
/* 2044 80026C44 00000000 */   nop
.L80026C48:
/* 2048 80026C48 0C00AE90 */  jal       func_8002BA40
/* 204C 80026C4C 00000000 */   nop
/* 2050 80026C50 8E220000 */  lw        $v0, ($s1)
/* 2054 80026C54 3C030010 */  lui       $v1, 0x10
/* 2058 80026C58 00431024 */  and       $v0, $v0, $v1
/* 205C 80026C5C 10400003 */  beqz      $v0, .L80026C6C
/* 2060 80026C60 00000000 */   nop
/* 2064 80026C64 0C04A523 */  jal       func_8012948C
/* 2068 80026C68 00000000 */   nop
.L80026C6C:
/* 206C 80026C6C 8E220000 */  lw        $v0, ($s1)
/* 2070 80026C70 3C030001 */  lui       $v1, 1
/* 2074 80026C74 00431024 */  and       $v0, $v0, $v1
/* 2078 80026C78 10400003 */  beqz      $v0, .L80026C88
/* 207C 80026C7C 00000000 */   nop
/* 2080 80026C80 0C0532DD */  jal       func_8014CB74
/* 2084 80026C84 00000000 */   nop
.L80026C88:
/* 2088 80026C88 0C046075 */  jal       func_801181D4
/* 208C 80026C8C 00000000 */   nop
/* 2090 80026C90 8E220000 */  lw        $v0, ($s1)
/* 2094 80026C94 30420020 */  andi      $v0, $v0, 0x20
/* 2098 80026C98 10400010 */  beqz      $v0, .L80026CDC
/* 209C 80026C9C 00000000 */   nop
/* 20A0 80026CA0 3C038007 */  lui       $v1, %hi(D_80074182)
/* 20A4 80026CA4 84634182 */  lh        $v1, %lo(D_80074182)($v1)
/* 20A8 80026CA8 28620002 */  slti      $v0, $v1, 2
/* 20AC 80026CAC 1040000B */  beqz      $v0, .L80026CDC
/* 20B0 80026CB0 00000000 */   nop
/* 20B4 80026CB4 04600009 */  bltz      $v1, .L80026CDC
/* 20B8 80026CB8 24040007 */   addiu    $a0, $zero, 7
/* 20BC 80026CBC 3C028007 */  lui       $v0, %hi(D_80074180)
/* 20C0 80026CC0 84424180 */  lh        $v0, %lo(D_80074180)($v0)
/* 20C4 80026CC4 44820000 */  mtc1      $v0, $f0
/* 20C8 80026CC8 00000000 */  nop
/* 20CC 80026CCC 46800020 */  cvt.s.w   $f0, $f0
/* 20D0 80026CD0 44050000 */  mfc1      $a1, $f0
/* 20D4 80026CD4 0C04EECC */  jal       func_8013BB30
/* 20D8 80026CD8 0000302D */   daddu    $a2, $zero, $zero
.L80026CDC:
/* 20DC 80026CDC 3C02800A */  lui       $v0, %hi(D_8009A64C)
/* 20E0 80026CE0 8C42A64C */  lw        $v0, %lo(D_8009A64C)($v0)
/* 20E4 80026CE4 3C03800A */  lui       $v1, %hi(D_8009A654)
/* 20E8 80026CE8 8C63A654 */  lw        $v1, %lo(D_8009A654)($v1)
/* 20EC 80026CEC 2442FDD0 */  addiu     $v0, $v0, -0x230
/* 20F0 80026CF0 00431023 */  subu      $v0, $v0, $v1
/* 20F4 80026CF4 000210C2 */  srl       $v0, $v0, 3
/* 20F8 80026CF8 28422000 */  slti      $v0, $v0, 0x2000
/* 20FC 80026CFC 54400003 */  bnel      $v0, $zero, .L80026D0C
/* 2100 80026D00 0000302D */   daddu    $a2, $zero, $zero
.L80026D04:
/* 2104 80026D04 08009B41 */  j         .L80026D04
/* 2108 80026D08 00000000 */   nop
.L80026D0C:
/* 210C 80026D0C 3C070004 */  lui       $a3, 4
/* 2110 80026D10 3C08800A */  lui       $t0, %hi(D_8009A64C)
/* 2114 80026D14 2508A64C */  addiu     $t0, $t0, %lo(D_8009A64C)
/* 2118 80026D18 34E70001 */  ori       $a3, $a3, 1
/* 211C 80026D1C 8D030000 */  lw        $v1, ($t0)
/* 2120 80026D20 3C02800A */  lui       $v0, %hi(D_8009A654)
/* 2124 80026D24 8C42A654 */  lw        $v0, %lo(D_8009A654)($v0)
/* 2128 80026D28 0060482D */  daddu     $t1, $v1, $zero
/* 212C 80026D2C 24630008 */  addiu     $v1, $v1, 8
/* 2130 80026D30 24440230 */  addiu     $a0, $v0, 0x230
/* 2134 80026D34 2465FDD8 */  addiu     $a1, $v1, -0x228
/* 2138 80026D38 00A22823 */  subu      $a1, $a1, $v0
/* 213C 80026D3C 000528C3 */  sra       $a1, $a1, 3
/* 2140 80026D40 000528C0 */  sll       $a1, $a1, 3
/* 2144 80026D44 3C02E900 */  lui       $v0, 0xe900
/* 2148 80026D48 AD030000 */  sw        $v1, ($t0)
/* 214C 80026D4C AD220000 */  sw        $v0, ($t1)
/* 2150 80026D50 24620008 */  addiu     $v0, $v1, 8
/* 2154 80026D54 AD200004 */  sw        $zero, 4($t1)
/* 2158 80026D58 AD020000 */  sw        $v0, ($t0)
/* 215C 80026D5C 3C02DF00 */  lui       $v0, 0xdf00
/* 2160 80026D60 AC620000 */  sw        $v0, ($v1)
/* 2164 80026D64 0C00B3C9 */  jal       func_8002CF24
/* 2168 80026D68 AC600004 */   sw       $zero, 4($v1)
/* 216C 80026D6C 24050140 */  addiu     $a1, $zero, 0x140
/* 2170 80026D70 240600F0 */  addiu     $a2, $zero, 0xf0
/* 2174 80026D74 3C038007 */  lui       $v1, %hi(D_800741D4)
/* 2178 80026D78 246341D4 */  addiu     $v1, $v1, %lo(D_800741D4)
/* 217C 80026D7C 8C620000 */  lw        $v0, ($v1)
/* 2180 80026D80 3C04800A */  lui       $a0, %hi(D_8009A62C)
/* 2184 80026D84 8C84A62C */  lw        $a0, %lo(D_8009A62C)($a0)
/* 2188 80026D88 38420001 */  xori      $v0, $v0, 1
/* 218C 80026D8C 0C00B214 */  jal       func_8002C850
/* 2190 80026D90 AC620000 */   sw       $v0, ($v1)
.L80026D94:
/* 2194 80026D94 8FBF0018 */  lw        $ra, 0x18($sp)
/* 2198 80026D98 8FB10014 */  lw        $s1, 0x14($sp)
/* 219C 80026D9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 21A0 80026DA0 03E00008 */  jr        $ra
/* 21A4 80026DA4 27BD0020 */   addiu    $sp, $sp, 0x20
