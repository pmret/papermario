.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024108C_C77D6C
/* C77D6C 8024108C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C77D70 80241090 AFB10014 */  sw        $s1, 0x14($sp)
/* C77D74 80241094 0080882D */  daddu     $s1, $a0, $zero
/* C77D78 80241098 AFBF0018 */  sw        $ra, 0x18($sp)
/* C77D7C 8024109C AFB00010 */  sw        $s0, 0x10($sp)
/* C77D80 802410A0 8E300148 */  lw        $s0, 0x148($s1)
/* C77D84 802410A4 0C00EABB */  jal       get_npc_unsafe
/* C77D88 802410A8 86040008 */   lh       $a0, 8($s0)
/* C77D8C 802410AC 0040202D */  daddu     $a0, $v0, $zero
/* C77D90 802410B0 9482008E */  lhu       $v0, 0x8e($a0)
/* C77D94 802410B4 2442FFFF */  addiu     $v0, $v0, -1
/* C77D98 802410B8 A482008E */  sh        $v0, 0x8e($a0)
/* C77D9C 802410BC 00021400 */  sll       $v0, $v0, 0x10
/* C77DA0 802410C0 1C400009 */  bgtz      $v0, .L802410E8
/* C77DA4 802410C4 24020003 */   addiu    $v0, $zero, 3
/* C77DA8 802410C8 96030076 */  lhu       $v1, 0x76($s0)
/* C77DAC 802410CC AE02006C */  sw        $v0, 0x6c($s0)
/* C77DB0 802410D0 A483008E */  sh        $v1, 0x8e($a0)
/* C77DB4 802410D4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C77DB8 802410D8 8C420024 */  lw        $v0, 0x24($v0)
/* C77DBC 802410DC AC820028 */  sw        $v0, 0x28($a0)
/* C77DC0 802410E0 24020020 */  addiu     $v0, $zero, 0x20
/* C77DC4 802410E4 AE220070 */  sw        $v0, 0x70($s1)
.L802410E8:
/* C77DC8 802410E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C77DCC 802410EC 8FB10014 */  lw        $s1, 0x14($sp)
/* C77DD0 802410F0 8FB00010 */  lw        $s0, 0x10($sp)
/* C77DD4 802410F4 03E00008 */  jr        $ra
/* C77DD8 802410F8 27BD0020 */   addiu    $sp, $sp, 0x20
