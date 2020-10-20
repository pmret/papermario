.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C44_CD3A74
/* CD3A74 80241C44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CD3A78 80241C48 AFB00010 */  sw        $s0, 0x10($sp)
/* CD3A7C 80241C4C 0080802D */  daddu     $s0, $a0, $zero
/* CD3A80 80241C50 AFBF0014 */  sw        $ra, 0x14($sp)
/* CD3A84 80241C54 8E020148 */  lw        $v0, 0x148($s0)
/* CD3A88 80241C58 0C00EABB */  jal       get_npc_unsafe
/* CD3A8C 80241C5C 84440008 */   lh       $a0, 8($v0)
/* CD3A90 80241C60 0040202D */  daddu     $a0, $v0, $zero
/* CD3A94 80241C64 8482008E */  lh        $v0, 0x8e($a0)
/* CD3A98 80241C68 9483008E */  lhu       $v1, 0x8e($a0)
/* CD3A9C 80241C6C 18400005 */  blez      $v0, .L80241C84
/* CD3AA0 80241C70 2462FFFF */   addiu    $v0, $v1, -1
/* CD3AA4 80241C74 A482008E */  sh        $v0, 0x8e($a0)
/* CD3AA8 80241C78 00021400 */  sll       $v0, $v0, 0x10
/* CD3AAC 80241C7C 1C400006 */  bgtz      $v0, .L80241C98
/* CD3AB0 80241C80 00000000 */   nop      
.L80241C84:
/* CD3AB4 80241C84 8482008C */  lh        $v0, 0x8c($a0)
/* CD3AB8 80241C88 14400003 */  bnez      $v0, .L80241C98
/* CD3ABC 80241C8C 2402000E */   addiu    $v0, $zero, 0xe
/* CD3AC0 80241C90 A480008E */  sh        $zero, 0x8e($a0)
/* CD3AC4 80241C94 AE020070 */  sw        $v0, 0x70($s0)
.L80241C98:
/* CD3AC8 80241C98 8FBF0014 */  lw        $ra, 0x14($sp)
/* CD3ACC 80241C9C 8FB00010 */  lw        $s0, 0x10($sp)
/* CD3AD0 80241CA0 03E00008 */  jr        $ra
/* CD3AD4 80241CA4 27BD0018 */   addiu    $sp, $sp, 0x18
