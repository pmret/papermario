.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240680_895D60
/* 895D60 80240680 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 895D64 80240684 AFBF0010 */  sw        $ra, 0x10($sp)
/* 895D68 80240688 0C00FB5A */  jal       get_enemy_safe
/* 895D6C 8024068C 24040001 */   addiu    $a0, $zero, 1
/* 895D70 80240690 0040182D */  daddu     $v1, $v0, $zero
/* 895D74 80240694 10600002 */  beqz      $v1, .L802406A0
/* 895D78 80240698 24020001 */   addiu    $v0, $zero, 1
/* 895D7C 8024069C AC62006C */  sw        $v0, 0x6c($v1)
.L802406A0:
/* 895D80 802406A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 895D84 802406A4 24020002 */  addiu     $v0, $zero, 2
/* 895D88 802406A8 03E00008 */  jr        $ra
/* 895D8C 802406AC 27BD0018 */   addiu    $sp, $sp, 0x18
