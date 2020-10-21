.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D8_DB2498
/* DB2498 802401D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB249C 802401DC AFB10014 */  sw        $s1, 0x14($sp)
/* DB24A0 802401E0 0080882D */  daddu     $s1, $a0, $zero
/* DB24A4 802401E4 AFBF0018 */  sw        $ra, 0x18($sp)
/* DB24A8 802401E8 AFB00010 */  sw        $s0, 0x10($sp)
/* DB24AC 802401EC 8E300148 */  lw        $s0, 0x148($s1)
/* DB24B0 802401F0 0C00EABB */  jal       get_npc_unsafe
/* DB24B4 802401F4 86040008 */   lh       $a0, 8($s0)
/* DB24B8 802401F8 0040182D */  daddu     $v1, $v0, $zero
/* DB24BC 802401FC 9462008E */  lhu       $v0, 0x8e($v1)
/* DB24C0 80240200 2442FFFF */  addiu     $v0, $v0, -1
/* DB24C4 80240204 A462008E */  sh        $v0, 0x8e($v1)
/* DB24C8 80240208 00021400 */  sll       $v0, $v0, 0x10
/* DB24CC 8024020C 14400005 */  bnez      $v0, .L80240224
/* DB24D0 80240210 00000000 */   nop      
/* DB24D4 80240214 8E0200CC */  lw        $v0, 0xcc($s0)
/* DB24D8 80240218 8C420000 */  lw        $v0, ($v0)
/* DB24DC 8024021C AC620028 */  sw        $v0, 0x28($v1)
/* DB24E0 80240220 AE200070 */  sw        $zero, 0x70($s1)
.L80240224:
/* DB24E4 80240224 8FBF0018 */  lw        $ra, 0x18($sp)
/* DB24E8 80240228 8FB10014 */  lw        $s1, 0x14($sp)
/* DB24EC 8024022C 8FB00010 */  lw        $s0, 0x10($sp)
/* DB24F0 80240230 03E00008 */  jr        $ra
/* DB24F4 80240234 27BD0020 */   addiu    $sp, $sp, 0x20
