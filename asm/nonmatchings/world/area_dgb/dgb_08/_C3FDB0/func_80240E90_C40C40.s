.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E90_C40C40
/* C40C40 80240E90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C40C44 80240E94 AFB10014 */  sw        $s1, 0x14($sp)
/* C40C48 80240E98 0080882D */  daddu     $s1, $a0, $zero
/* C40C4C 80240E9C AFBF0018 */  sw        $ra, 0x18($sp)
/* C40C50 80240EA0 AFB00010 */  sw        $s0, 0x10($sp)
/* C40C54 80240EA4 8E300148 */  lw        $s0, 0x148($s1)
/* C40C58 80240EA8 0C00EABB */  jal       get_npc_unsafe
/* C40C5C 80240EAC 86040008 */   lh       $a0, 8($s0)
/* C40C60 80240EB0 24030001 */  addiu     $v1, $zero, 1
/* C40C64 80240EB4 0040202D */  daddu     $a0, $v0, $zero
/* C40C68 80240EB8 AE03006C */  sw        $v1, 0x6c($s0)
/* C40C6C 80240EBC 8482008C */  lh        $v0, 0x8c($a0)
/* C40C70 80240EC0 14400009 */  bnez      $v0, .L80240EE8
/* C40C74 80240EC4 24020002 */   addiu    $v0, $zero, 2
/* C40C78 80240EC8 96030072 */  lhu       $v1, 0x72($s0)
/* C40C7C 80240ECC AE02006C */  sw        $v0, 0x6c($s0)
/* C40C80 80240ED0 A483008E */  sh        $v1, 0x8e($a0)
/* C40C84 80240ED4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C40C88 80240ED8 8C420020 */  lw        $v0, 0x20($v0)
/* C40C8C 80240EDC AC820028 */  sw        $v0, 0x28($a0)
/* C40C90 80240EE0 2402001F */  addiu     $v0, $zero, 0x1f
/* C40C94 80240EE4 AE220070 */  sw        $v0, 0x70($s1)
.L80240EE8:
/* C40C98 80240EE8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C40C9C 80240EEC 8FB10014 */  lw        $s1, 0x14($sp)
/* C40CA0 80240EF0 8FB00010 */  lw        $s0, 0x10($sp)
/* C40CA4 80240EF4 03E00008 */  jr        $ra
/* C40CA8 80240EF8 27BD0020 */   addiu    $sp, $sp, 0x20
