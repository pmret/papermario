.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412EC
/* B53B1C 802412EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B53B20 802412F0 AFB00010 */  sw        $s0, 0x10($sp)
/* B53B24 802412F4 0080802D */  daddu     $s0, $a0, $zero
/* B53B28 802412F8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B53B2C 802412FC 8E020148 */  lw        $v0, 0x148($s0)
/* B53B30 80241300 0C00EABB */  jal       get_npc_unsafe
/* B53B34 80241304 84440008 */   lh       $a0, 8($v0)
/* B53B38 80241308 9443008E */  lhu       $v1, 0x8e($v0)
/* B53B3C 8024130C 2463FFFF */  addiu     $v1, $v1, -1
/* B53B40 80241310 A443008E */  sh        $v1, 0x8e($v0)
/* B53B44 80241314 00031C00 */  sll       $v1, $v1, 0x10
/* B53B48 80241318 58600001 */  blezl     $v1, .L80241320
/* B53B4C 8024131C AE000070 */   sw       $zero, 0x70($s0)
.L80241320:
/* B53B50 80241320 8FBF0014 */  lw        $ra, 0x14($sp)
/* B53B54 80241324 8FB00010 */  lw        $s0, 0x10($sp)
/* B53B58 80241328 03E00008 */  jr        $ra
/* B53B5C 8024132C 27BD0018 */   addiu    $sp, $sp, 0x18
