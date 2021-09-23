.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F40_EB9D90
/* EB9D90 80240F40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB9D94 80240F44 AFB00010 */  sw        $s0, 0x10($sp)
/* EB9D98 80240F48 0080802D */  daddu     $s0, $a0, $zero
/* EB9D9C 80240F4C AFB20018 */  sw        $s2, 0x18($sp)
/* EB9DA0 80240F50 3C128011 */  lui       $s2, %hi(dead_gPlayerStatus)
/* EB9DA4 80240F54 26527578 */  addiu     $s2, $s2, %lo(dead_gPlayerStatus)
/* EB9DA8 80240F58 AFBF001C */  sw        $ra, 0x1c($sp)
/* EB9DAC 80240F5C AFB10014 */  sw        $s1, 0x14($sp)
/* EB9DB0 80240F60 C64000A8 */  lwc1      $f0, 0xa8($s2)
/* EB9DB4 80240F64 8E02000C */  lw        $v0, 0xc($s0)
/* EB9DB8 80240F68 4600008D */  trunc.w.s $f2, $f0
/* EB9DBC 80240F6C 44061000 */  mfc1      $a2, $f2
/* EB9DC0 80240F70 8C450000 */  lw        $a1, ($v0)
/* EB9DC4 80240F74 0C0B551A */  jal       dead_evt_set_variable
/* EB9DC8 80240F78 8C510004 */   lw       $s1, 4($v0)
/* EB9DCC 80240F7C 0200202D */  daddu     $a0, $s0, $zero
/* EB9DD0 80240F80 C6400080 */  lwc1      $f0, 0x80($s2)
/* EB9DD4 80240F84 4600008D */  trunc.w.s $f2, $f0
/* EB9DD8 80240F88 44061000 */  mfc1      $a2, $f2
/* EB9DDC 80240F8C 0C0B551A */  jal       dead_evt_set_variable
/* EB9DE0 80240F90 0220282D */   daddu    $a1, $s1, $zero
/* EB9DE4 80240F94 8FBF001C */  lw        $ra, 0x1c($sp)
/* EB9DE8 80240F98 8FB20018 */  lw        $s2, 0x18($sp)
/* EB9DEC 80240F9C 8FB10014 */  lw        $s1, 0x14($sp)
/* EB9DF0 80240FA0 8FB00010 */  lw        $s0, 0x10($sp)
/* EB9DF4 80240FA4 24020002 */  addiu     $v0, $zero, 2
/* EB9DF8 80240FA8 03E00008 */  jr        $ra
/* EB9DFC 80240FAC 27BD0020 */   addiu    $sp, $sp, 0x20
