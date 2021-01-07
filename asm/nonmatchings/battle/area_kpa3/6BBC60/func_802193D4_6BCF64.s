.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802193D4_6BCF64
/* 6BCF64 802193D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6BCF68 802193D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6BCF6C 802193DC 0C09A75B */  jal       get_actor
/* 6BCF70 802193E0 8C840148 */   lw       $a0, 0x148($a0)
/* 6BCF74 802193E4 8C440090 */  lw        $a0, 0x90($v0)
/* 6BCF78 802193E8 8C830014 */  lw        $v1, 0x14($a0)
/* 6BCF7C 802193EC 10600004 */  beqz      $v1, .L80219400
/* 6BCF80 802193F0 AC800000 */   sw       $zero, ($a0)
/* 6BCF84 802193F4 8C620000 */  lw        $v0, ($v1)
/* 6BCF88 802193F8 34420010 */  ori       $v0, $v0, 0x10
/* 6BCF8C 802193FC AC620000 */  sw        $v0, ($v1)
.L80219400:
/* 6BCF90 80219400 8C830018 */  lw        $v1, 0x18($a0)
/* 6BCF94 80219404 10600004 */  beqz      $v1, .L80219418
/* 6BCF98 80219408 00000000 */   nop      
/* 6BCF9C 8021940C 8C620000 */  lw        $v0, ($v1)
/* 6BCFA0 80219410 34420010 */  ori       $v0, $v0, 0x10
/* 6BCFA4 80219414 AC620000 */  sw        $v0, ($v1)
.L80219418:
/* 6BCFA8 80219418 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6BCFAC 8021941C 24020002 */  addiu     $v0, $zero, 2
/* 6BCFB0 80219420 03E00008 */  jr        $ra
/* 6BCFB4 80219424 27BD0018 */   addiu    $sp, $sp, 0x18
