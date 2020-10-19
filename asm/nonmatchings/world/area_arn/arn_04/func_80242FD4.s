.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FD4
/* BE6784 80242FD4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BE6788 80242FD8 AFB00010 */  sw        $s0, 0x10($sp)
/* BE678C 80242FDC 0080802D */  daddu     $s0, $a0, $zero
/* BE6790 80242FE0 AFBF0014 */  sw        $ra, 0x14($sp)
/* BE6794 80242FE4 8E020148 */  lw        $v0, 0x148($s0)
/* BE6798 80242FE8 0C00EABB */  jal       get_npc_unsafe
/* BE679C 80242FEC 84440008 */   lh       $a0, 8($v0)
/* BE67A0 80242FF0 9443008E */  lhu       $v1, 0x8e($v0)
/* BE67A4 80242FF4 2463FFFF */  addiu     $v1, $v1, -1
/* BE67A8 80242FF8 A443008E */  sh        $v1, 0x8e($v0)
/* BE67AC 80242FFC 00031C00 */  sll       $v1, $v1, 0x10
/* BE67B0 80243000 58600001 */  blezl     $v1, .L80243008
/* BE67B4 80243004 AE000070 */   sw       $zero, 0x70($s0)
.L80243008:
/* BE67B8 80243008 8FBF0014 */  lw        $ra, 0x14($sp)
/* BE67BC 8024300C 8FB00010 */  lw        $s0, 0x10($sp)
/* BE67C0 80243010 03E00008 */  jr        $ra
/* BE67C4 80243014 27BD0018 */   addiu    $sp, $sp, 0x18
