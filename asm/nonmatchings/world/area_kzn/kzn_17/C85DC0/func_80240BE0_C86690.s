.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BE0_C86690
/* C86690 80240BE0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C86694 80240BE4 AFB10014 */  sw        $s1, 0x14($sp)
/* C86698 80240BE8 0080882D */  daddu     $s1, $a0, $zero
/* C8669C 80240BEC AFBF0018 */  sw        $ra, 0x18($sp)
/* C866A0 80240BF0 AFB00010 */  sw        $s0, 0x10($sp)
/* C866A4 80240BF4 8E300148 */  lw        $s0, 0x148($s1)
/* C866A8 80240BF8 0C00EABB */  jal       get_npc_unsafe
/* C866AC 80240BFC 86040008 */   lh       $a0, 8($s0)
/* C866B0 80240C00 0040202D */  daddu     $a0, $v0, $zero
/* C866B4 80240C04 8482008E */  lh        $v0, 0x8e($a0)
/* C866B8 80240C08 9483008E */  lhu       $v1, 0x8e($a0)
/* C866BC 80240C0C 18400003 */  blez      $v0, .L80240C1C
/* C866C0 80240C10 2462FFFF */   addiu    $v0, $v1, -1
/* C866C4 80240C14 0809030E */  j         .L80240C38
/* C866C8 80240C18 A482008E */   sh       $v0, 0x8e($a0)
.L80240C1C:
/* C866CC 80240C1C 8E0200CC */  lw        $v0, 0xcc($s0)
/* C866D0 80240C20 AE00006C */  sw        $zero, 0x6c($s0)
/* C866D4 80240C24 8C420000 */  lw        $v0, ($v0)
/* C866D8 80240C28 AC820028 */  sw        $v0, 0x28($a0)
/* C866DC 80240C2C 24020001 */  addiu     $v0, $zero, 1
/* C866E0 80240C30 AE200074 */  sw        $zero, 0x74($s1)
/* C866E4 80240C34 AE220070 */  sw        $v0, 0x70($s1)
.L80240C38:
/* C866E8 80240C38 8FBF0018 */  lw        $ra, 0x18($sp)
/* C866EC 80240C3C 8FB10014 */  lw        $s1, 0x14($sp)
/* C866F0 80240C40 8FB00010 */  lw        $s0, 0x10($sp)
/* C866F4 80240C44 03E00008 */  jr        $ra
/* C866F8 80240C48 27BD0020 */   addiu    $sp, $sp, 0x20
