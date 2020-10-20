.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240388
/* 8AC318 80240388 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8AC31C 8024038C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8AC320 80240390 0C04760B */  jal       func_8011D82C
/* 8AC324 80240394 24040003 */   addiu    $a0, $zero, 3
/* 8AC328 80240398 3C038015 */  lui       $v1, 0x8015
/* 8AC32C 8024039C 8C6312F0 */  lw        $v1, 0x12f0($v1)
/* 8AC330 802403A0 24020003 */  addiu     $v0, $zero, 3
/* 8AC334 802403A4 A0620000 */  sb        $v0, ($v1)
/* 8AC338 802403A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8AC33C 802403AC 24020002 */  addiu     $v0, $zero, 2
/* 8AC340 802403B0 03E00008 */  jr        $ra
/* 8AC344 802403B4 27BD0018 */   addiu    $sp, $sp, 0x18
