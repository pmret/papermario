.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045D00
/* 21100 80045D00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 21104 80045D04 AFB00010 */  sw        $s0, 0x10($sp)
/* 21108 80045D08 0080802D */  daddu     $s0, $a0, $zero
/* 2110C 80045D0C AFB10014 */  sw        $s1, 0x14($sp)
/* 21110 80045D10 AFBF0018 */  sw        $ra, 0x18($sp)
/* 21114 80045D14 0C011722 */  jal       func_80045C88
/* 21118 80045D18 00A0882D */   daddu    $s1, $a1, $zero
/* 2111C 80045D1C 0040182D */  daddu     $v1, $v0, $zero
/* 21120 80045D20 10600011 */  beqz      $v1, .L80045D68
/* 21124 80045D24 00000000 */   nop
/* 21128 80045D28 3C028004 */  lui       $v0, %hi(func_80045D7C)
/* 2112C 80045D2C 24425D7C */  addiu     $v0, $v0, %lo(func_80045D7C)
/* 21130 80045D30 AC620004 */  sw        $v0, 4($v1)
/* 21134 80045D34 3C028004 */  lui       $v0, %hi(draw_merlee_message)
/* 21138 80045D38 24425ED0 */  addiu     $v0, $v0, %lo(draw_merlee_message)
/* 2113C 80045D3C AC62000C */  sw        $v0, 0xc($v1)
/* 21140 80045D40 24020001 */  addiu     $v0, $zero, 1
/* 21144 80045D44 A0620017 */  sb        $v0, 0x17($v1)
/* 21148 80045D48 24020001 */  addiu     $v0, $zero, 1
/* 2114C 80045D4C AC600000 */  sw        $zero, ($v1)
/* 21150 80045D50 AC600008 */  sw        $zero, 8($v1)
/* 21154 80045D54 A4700012 */  sh        $s0, 0x12($v1)
/* 21158 80045D58 A4710014 */  sh        $s1, 0x14($v1)
/* 2115C 80045D5C A0600016 */  sb        $zero, 0x16($v1)
/* 21160 80045D60 3C01800A */  lui       $at, %hi(D_800A0F40)
/* 21164 80045D64 AC220F40 */  sw        $v0, %lo(D_800A0F40)($at)
.L80045D68:
/* 21168 80045D68 8FBF0018 */  lw        $ra, 0x18($sp)
/* 2116C 80045D6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 21170 80045D70 8FB00010 */  lw        $s0, 0x10($sp)
/* 21174 80045D74 03E00008 */  jr        $ra
/* 21178 80045D78 27BD0020 */   addiu    $sp, $sp, 0x20
