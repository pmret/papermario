.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047D30
/* 23130 80047D30 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 23134 80047D34 00041040 */  sll       $v0, $a0, 1
/* 23138 80047D38 00441021 */  addu      $v0, $v0, $a0
/* 2313C 80047D3C 00021080 */  sll       $v0, $v0, 2
/* 23140 80047D40 00441023 */  subu      $v0, $v0, $a0
/* 23144 80047D44 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 23148 80047D48 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 2314C 80047D4C 00021100 */  sll       $v0, $v0, 4
/* 23150 80047D50 AFBF0018 */  sw        $ra, 0x18($sp)
/* 23154 80047D54 AFB10014 */  sw        $s1, 0x14($sp)
/* 23158 80047D58 AFB00010 */  sw        $s0, 0x10($sp)
/* 2315C 80047D5C 00628821 */  addu      $s1, $v1, $v0
/* 23160 80047D60 2403FF7F */  addiu     $v1, $zero, -0x81
/* 23164 80047D64 8E220000 */  lw        $v0, ($s1)
/* 23168 80047D68 82240084 */  lb        $a0, 0x84($s1)
/* 2316C 80047D6C 00431024 */  and       $v0, $v0, $v1
/* 23170 80047D70 1480000E */  bnez      $a0, .L80047DAC
/* 23174 80047D74 AE220000 */   sw       $v0, ($s1)
/* 23178 80047D78 3C048010 */  lui       $a0, %hi(D_80107314)
/* 2317C 80047D7C 24847314 */  addiu     $a0, $a0, %lo(D_80107314)
/* 23180 80047D80 24020001 */  addiu     $v0, $zero, 1
/* 23184 80047D84 0C050529 */  jal       create_icon
/* 23188 80047D88 A2220084 */   sb       $v0, 0x84($s1)
/* 2318C 80047D8C 0040802D */  daddu     $s0, $v0, $zero
/* 23190 80047D90 0200202D */  daddu     $a0, $s0, $zero
/* 23194 80047D94 0C051280 */  jal       set_icon_flags
/* 23198 80047D98 24050002 */   addiu    $a1, $zero, 2
/* 2319C 80047D9C 0200202D */  daddu     $a0, $s0, $zero
/* 231A0 80047DA0 0C051280 */  jal       set_icon_flags
/* 231A4 80047DA4 24050080 */   addiu    $a1, $zero, 0x80
/* 231A8 80047DA8 AE300088 */  sw        $s0, 0x88($s1)
.L80047DAC:
/* 231AC 80047DAC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 231B0 80047DB0 8FB10014 */  lw        $s1, 0x14($sp)
/* 231B4 80047DB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 231B8 80047DB8 03E00008 */  jr        $ra
/* 231BC 80047DBC 27BD0020 */   addiu    $sp, $sp, 0x20
