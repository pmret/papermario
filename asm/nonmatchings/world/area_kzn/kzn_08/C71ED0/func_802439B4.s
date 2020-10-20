.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802439B4
/* C74E34 802439B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C74E38 802439B8 AFB10014 */  sw        $s1, 0x14($sp)
/* C74E3C 802439BC 0080882D */  daddu     $s1, $a0, $zero
/* C74E40 802439C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C74E44 802439C4 AFB00010 */  sw        $s0, 0x10($sp)
/* C74E48 802439C8 8E300148 */  lw        $s0, 0x148($s1)
/* C74E4C 802439CC 0C00EABB */  jal       get_npc_unsafe
/* C74E50 802439D0 86040008 */   lh       $a0, 8($s0)
/* C74E54 802439D4 0040202D */  daddu     $a0, $v0, $zero
/* C74E58 802439D8 9482008E */  lhu       $v0, 0x8e($a0)
/* C74E5C 802439DC 2442FFFF */  addiu     $v0, $v0, -1
/* C74E60 802439E0 A482008E */  sh        $v0, 0x8e($a0)
/* C74E64 802439E4 00021400 */  sll       $v0, $v0, 0x10
/* C74E68 802439E8 8E030098 */  lw        $v1, 0x98($s0)
/* C74E6C 802439EC 00021403 */  sra       $v0, $v0, 0x10
/* C74E70 802439F0 0062182A */  slt       $v1, $v1, $v0
/* C74E74 802439F4 14600005 */  bnez      $v1, .L80243A0C
/* C74E78 802439F8 3C03E0EF */   lui      $v1, 0xe0ef
/* C74E7C 802439FC 8E020000 */  lw        $v0, ($s0)
/* C74E80 80243A00 3463FFFF */  ori       $v1, $v1, 0xffff
/* C74E84 80243A04 00431024 */  and       $v0, $v0, $v1
/* C74E88 80243A08 AE020000 */  sw        $v0, ($s0)
.L80243A0C:
/* C74E8C 80243A0C 8482008E */  lh        $v0, 0x8e($a0)
/* C74E90 80243A10 14400007 */  bnez      $v0, .L80243A30
/* C74E94 80243A14 00000000 */   nop      
/* C74E98 80243A18 8E0200CC */  lw        $v0, 0xcc($s0)
/* C74E9C 80243A1C 8C420028 */  lw        $v0, 0x28($v0)
/* C74EA0 80243A20 A480008E */  sh        $zero, 0x8e($a0)
/* C74EA4 80243A24 AC820028 */  sw        $v0, 0x28($a0)
/* C74EA8 80243A28 2402000C */  addiu     $v0, $zero, 0xc
/* C74EAC 80243A2C AE220070 */  sw        $v0, 0x70($s1)
.L80243A30:
/* C74EB0 80243A30 8FBF0018 */  lw        $ra, 0x18($sp)
/* C74EB4 80243A34 8FB10014 */  lw        $s1, 0x14($sp)
/* C74EB8 80243A38 8FB00010 */  lw        $s0, 0x10($sp)
/* C74EBC 80243A3C 03E00008 */  jr        $ra
/* C74EC0 80243A40 27BD0020 */   addiu    $sp, $sp, 0x20
