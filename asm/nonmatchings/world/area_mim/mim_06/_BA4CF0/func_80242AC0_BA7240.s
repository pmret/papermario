.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242AC0_BA7240
/* BA7240 80242AC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BA7244 80242AC4 AFB00010 */  sw        $s0, 0x10($sp)
/* BA7248 80242AC8 0080802D */  daddu     $s0, $a0, $zero
/* BA724C 80242ACC AFBF0014 */  sw        $ra, 0x14($sp)
/* BA7250 80242AD0 8E020148 */  lw        $v0, 0x148($s0)
/* BA7254 80242AD4 0C00EABB */  jal       get_npc_unsafe
/* BA7258 80242AD8 84440008 */   lh       $a0, 8($v0)
/* BA725C 80242ADC 9443008E */  lhu       $v1, 0x8e($v0)
/* BA7260 80242AE0 2463FFFF */  addiu     $v1, $v1, -1
/* BA7264 80242AE4 A443008E */  sh        $v1, 0x8e($v0)
/* BA7268 80242AE8 00031C00 */  sll       $v1, $v1, 0x10
/* BA726C 80242AEC 58600001 */  blezl     $v1, .L80242AF4
/* BA7270 80242AF0 AE000070 */   sw       $zero, 0x70($s0)
.L80242AF4:
/* BA7274 80242AF4 8FBF0014 */  lw        $ra, 0x14($sp)
/* BA7278 80242AF8 8FB00010 */  lw        $s0, 0x10($sp)
/* BA727C 80242AFC 03E00008 */  jr        $ra
/* BA7280 80242B00 27BD0018 */   addiu    $sp, $sp, 0x18
