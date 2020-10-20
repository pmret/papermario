.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416B0
/* A49C70 802416B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A49C74 802416B4 AFB00010 */  sw        $s0, 0x10($sp)
/* A49C78 802416B8 0080802D */  daddu     $s0, $a0, $zero
/* A49C7C 802416BC AFBF0014 */  sw        $ra, 0x14($sp)
/* A49C80 802416C0 8E020148 */  lw        $v0, 0x148($s0)
/* A49C84 802416C4 0C00EABB */  jal       get_npc_unsafe
/* A49C88 802416C8 84440008 */   lh       $a0, 8($v0)
/* A49C8C 802416CC 24030028 */  addiu     $v1, $zero, 0x28
/* A49C90 802416D0 A443008E */  sh        $v1, 0x8e($v0)
/* A49C94 802416D4 24020015 */  addiu     $v0, $zero, 0x15
/* A49C98 802416D8 AE020070 */  sw        $v0, 0x70($s0)
/* A49C9C 802416DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A49CA0 802416E0 8FB00010 */  lw        $s0, 0x10($sp)
/* A49CA4 802416E4 03E00008 */  jr        $ra
/* A49CA8 802416E8 27BD0018 */   addiu    $sp, $sp, 0x18
