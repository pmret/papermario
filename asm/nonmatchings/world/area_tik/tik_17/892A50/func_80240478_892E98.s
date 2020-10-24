.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240478_892E98
/* 892E98 80240478 3C028011 */  lui       $v0, 0x8011
/* 892E9C 8024047C 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 892EA0 80240480 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 892EA4 80240484 AFBF0010 */  sw        $ra, 0x10($sp)
/* 892EA8 80240488 00021100 */  sll       $v0, $v0, 4
/* 892EAC 8024048C 3C048009 */  lui       $a0, 0x8009
/* 892EB0 80240490 00822021 */  addu      $a0, $a0, $v0
/* 892EB4 80240494 8C84EF20 */  lw        $a0, -0x10e0($a0)
/* 892EB8 80240498 0C0496CF */  jal       set_message_string
/* 892EBC 8024049C 0000282D */   daddu    $a1, $zero, $zero
/* 892EC0 802404A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 892EC4 802404A4 24020002 */  addiu     $v0, $zero, 2
/* 892EC8 802404A8 03E00008 */  jr        $ra
/* 892ECC 802404AC 27BD0018 */   addiu    $sp, $sp, 0x18
