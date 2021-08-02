.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D68_EA2668
/* EA2668 80241D68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA266C 80241D6C AFB20018 */  sw        $s2, 0x18($sp)
/* EA2670 80241D70 0080902D */  daddu     $s2, $a0, $zero
/* EA2674 80241D74 AFBF001C */  sw        $ra, 0x1c($sp)
/* EA2678 80241D78 AFB10014 */  sw        $s1, 0x14($sp)
/* EA267C 80241D7C AFB00010 */  sw        $s0, 0x10($sp)
/* EA2680 80241D80 8E510148 */  lw        $s1, 0x148($s2)
/* EA2684 80241D84 0C00F92F */  jal       dead_get_npc_unsafe
/* EA2688 80241D88 86240008 */   lh       $a0, 8($s1)
/* EA268C 80241D8C 0040802D */  daddu     $s0, $v0, $zero
/* EA2690 80241D90 8E2300CC */  lw        $v1, 0xcc($s1)
/* EA2694 80241D94 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EA2698 80241D98 8C630020 */  lw        $v1, 0x20($v1)
/* EA269C 80241D9C AE030028 */  sw        $v1, 0x28($s0)
/* EA26A0 80241DA0 96220076 */  lhu       $v0, 0x76($s1)
/* EA26A4 80241DA4 A602008E */  sh        $v0, 0x8e($s0)
/* EA26A8 80241DA8 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EA26AC 80241DAC 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EA26B0 80241DB0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EA26B4 80241DB4 8C460028 */  lw        $a2, 0x28($v0)
/* EA26B8 80241DB8 0C00ABDC */  jal       fio_validate_header_checksums
/* EA26BC 80241DBC 8C470030 */   lw       $a3, 0x30($v0)
/* EA26C0 80241DC0 2402000D */  addiu     $v0, $zero, 0xd
/* EA26C4 80241DC4 E600000C */  swc1      $f0, 0xc($s0)
/* EA26C8 80241DC8 AE420070 */  sw        $v0, 0x70($s2)
/* EA26CC 80241DCC 8FBF001C */  lw        $ra, 0x1c($sp)
/* EA26D0 80241DD0 8FB20018 */  lw        $s2, 0x18($sp)
/* EA26D4 80241DD4 8FB10014 */  lw        $s1, 0x14($sp)
/* EA26D8 80241DD8 8FB00010 */  lw        $s0, 0x10($sp)
/* EA26DC 80241DDC 03E00008 */  jr        $ra
/* EA26E0 80241DE0 27BD0020 */   addiu    $sp, $sp, 0x20
