.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414F8_8D72F8
/* 8D72F8 802414F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8D72FC 802414FC AFB00010 */  sw        $s0, 0x10($sp)
/* 8D7300 80241500 0080802D */  daddu     $s0, $a0, $zero
/* 8D7304 80241504 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8D7308 80241508 0C00FB5A */  jal       get_enemy_safe
/* 8D730C 8024150C 24040002 */   addiu    $a0, $zero, 2
/* 8D7310 80241510 AE020084 */  sw        $v0, 0x84($s0)
/* 8D7314 80241514 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8D7318 80241518 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D731C 8024151C 24020002 */  addiu     $v0, $zero, 2
/* 8D7320 80241520 03E00008 */  jr        $ra
/* 8D7324 80241524 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8D7328 80241528 00000000 */  nop       
/* 8D732C 8024152C 00000000 */  nop       
