.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DA0_7ECAB0
/* 7ECAB0 80241DA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7ECAB4 80241DA4 AFB20018 */  sw        $s2, 0x18($sp)
/* 7ECAB8 80241DA8 0080902D */  daddu     $s2, $a0, $zero
/* 7ECABC 80241DAC AFB10014 */  sw        $s1, 0x14($sp)
/* 7ECAC0 80241DB0 3C118025 */  lui       $s1, 0x8025
/* 7ECAC4 80241DB4 26318F18 */  addiu     $s1, $s1, -0x70e8
/* 7ECAC8 80241DB8 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ECACC 80241DBC 0000802D */  daddu     $s0, $zero, $zero
/* 7ECAD0 80241DC0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7ECAD4 80241DC4 26100001 */  addiu     $s0, $s0, 1
.L80241DC8:
/* 7ECAD8 80241DC8 8E250010 */  lw        $a1, 0x10($s1)
/* 7ECADC 80241DCC 26310014 */  addiu     $s1, $s1, 0x14
/* 7ECAE0 80241DD0 0240202D */  daddu     $a0, $s2, $zero
/* 7ECAE4 80241DD4 0C0B2026 */  jal       set_variable
/* 7ECAE8 80241DD8 0000302D */   daddu    $a2, $zero, $zero
/* 7ECAEC 80241DDC 2E020024 */  sltiu     $v0, $s0, 0x24
/* 7ECAF0 80241DE0 1440FFF9 */  bnez      $v0, .L80241DC8
/* 7ECAF4 80241DE4 26100001 */   addiu    $s0, $s0, 1
/* 7ECAF8 80241DE8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7ECAFC 80241DEC 8FB20018 */  lw        $s2, 0x18($sp)
/* 7ECB00 80241DF0 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ECB04 80241DF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ECB08 80241DF8 24020002 */  addiu     $v0, $zero, 2
/* 7ECB0C 80241DFC 03E00008 */  jr        $ra
/* 7ECB10 80241E00 27BD0020 */   addiu    $sp, $sp, 0x20
