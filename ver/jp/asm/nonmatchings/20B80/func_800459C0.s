.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800459C0
/* 20DC0 800459C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20DC4 800459C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 20DC8 800459C8 0080802D */  daddu     $s0, $a0, $zero
/* 20DCC 800459CC AFB10014 */  sw        $s1, 0x14($sp)
/* 20DD0 800459D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 20DD4 800459D4 0C011652 */  jal       func_80045948
/* 20DD8 800459D8 00A0882D */   daddu    $s1, $a1, $zero
/* 20DDC 800459DC 0040182D */  daddu     $v1, $v0, $zero
/* 20DE0 800459E0 10600011 */  beqz      $v1, .L80045A28
/* 20DE4 800459E4 00000000 */   nop
/* 20DE8 800459E8 3C028004 */  lui       $v0, %hi(func_80045A3C)
/* 20DEC 800459EC 24425A3C */  addiu     $v0, $v0, %lo(func_80045A3C)
/* 20DF0 800459F0 AC620004 */  sw        $v0, 4($v1)
/* 20DF4 800459F4 3C028004 */  lui       $v0, %hi(func_80045B5C)
/* 20DF8 800459F8 24425B5C */  addiu     $v0, $v0, %lo(func_80045B5C)
/* 20DFC 800459FC AC62000C */  sw        $v0, 0xc($v1)
/* 20E00 80045A00 24020001 */  addiu     $v0, $zero, 1
/* 20E04 80045A04 A0620017 */  sb        $v0, 0x17($v1)
/* 20E08 80045A08 24020001 */  addiu     $v0, $zero, 1
/* 20E0C 80045A0C AC600000 */  sw        $zero, ($v1)
/* 20E10 80045A10 AC600008 */  sw        $zero, 8($v1)
/* 20E14 80045A14 A4700012 */  sh        $s0, 0x12($v1)
/* 20E18 80045A18 A4710014 */  sh        $s1, 0x14($v1)
/* 20E1C 80045A1C A0600016 */  sb        $zero, 0x16($v1)
/* 20E20 80045A20 3C01800A */  lui       $at, %hi(D_8009ED50)
/* 20E24 80045A24 AC22ED50 */  sw        $v0, %lo(D_8009ED50)($at)
.L80045A28:
/* 20E28 80045A28 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20E2C 80045A2C 8FB10014 */  lw        $s1, 0x14($sp)
/* 20E30 80045A30 8FB00010 */  lw        $s0, 0x10($sp)
/* 20E34 80045A34 03E00008 */  jr        $ra
/* 20E38 80045A38 27BD0020 */   addiu    $sp, $sp, 0x20
