.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802430F0_C49CD0
/* C49CD0 802430F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C49CD4 802430F4 AFB00010 */  sw        $s0, 0x10($sp)
/* C49CD8 802430F8 0080802D */  daddu     $s0, $a0, $zero
/* C49CDC 802430FC AFBF0014 */  sw        $ra, 0x14($sp)
/* C49CE0 80243100 8E020148 */  lw        $v0, 0x148($s0)
/* C49CE4 80243104 0C00EABB */  jal       get_npc_unsafe
/* C49CE8 80243108 84440008 */   lh       $a0, 8($v0)
/* C49CEC 8024310C 9443008E */  lhu       $v1, 0x8e($v0)
/* C49CF0 80243110 2463FFFF */  addiu     $v1, $v1, -1
/* C49CF4 80243114 A443008E */  sh        $v1, 0x8e($v0)
/* C49CF8 80243118 00031C00 */  sll       $v1, $v1, 0x10
/* C49CFC 8024311C 1C600002 */  bgtz      $v1, .L80243128
/* C49D00 80243120 2402001E */   addiu    $v0, $zero, 0x1e
/* C49D04 80243124 AE020070 */  sw        $v0, 0x70($s0)
.L80243128:
/* C49D08 80243128 8FBF0014 */  lw        $ra, 0x14($sp)
/* C49D0C 8024312C 8FB00010 */  lw        $s0, 0x10($sp)
/* C49D10 80243130 03E00008 */  jr        $ra
/* C49D14 80243134 27BD0018 */   addiu    $sp, $sp, 0x18
