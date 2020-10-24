.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422A8_A091A8
/* A091A8 802422A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A091AC 802422AC AFB00010 */  sw        $s0, 0x10($sp)
/* A091B0 802422B0 0080802D */  daddu     $s0, $a0, $zero
/* A091B4 802422B4 AFBF0014 */  sw        $ra, 0x14($sp)
/* A091B8 802422B8 8E020148 */  lw        $v0, 0x148($s0)
/* A091BC 802422BC 0C00EABB */  jal       get_npc_unsafe
/* A091C0 802422C0 84440008 */   lh       $a0, 8($v0)
/* A091C4 802422C4 9443008E */  lhu       $v1, 0x8e($v0)
/* A091C8 802422C8 2463FFFF */  addiu     $v1, $v1, -1
/* A091CC 802422CC A443008E */  sh        $v1, 0x8e($v0)
/* A091D0 802422D0 00031C00 */  sll       $v1, $v1, 0x10
/* A091D4 802422D4 58600001 */  blezl     $v1, .L802422DC
/* A091D8 802422D8 AE000070 */   sw       $zero, 0x70($s0)
.L802422DC:
/* A091DC 802422DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A091E0 802422E0 8FB00010 */  lw        $s0, 0x10($sp)
/* A091E4 802422E4 03E00008 */  jr        $ra
/* A091E8 802422E8 27BD0018 */   addiu    $sp, $sp, 0x18
