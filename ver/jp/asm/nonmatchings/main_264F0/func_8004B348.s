.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B348
/* 26748 8004B348 0000282D */  daddu     $a1, $zero, $zero
/* 2674C 8004B34C 0080182D */  daddu     $v1, $a0, $zero
.L8004B350:
/* 26750 8004B350 A46000C2 */  sh        $zero, 0xc2($v1)
/* 26754 8004B354 A46000C4 */  sh        $zero, 0xc4($v1)
/* 26758 8004B358 A46000C6 */  sh        $zero, 0xc6($v1)
/* 2675C 8004B35C A46000C8 */  sh        $zero, 0xc8($v1)
/* 26760 8004B360 A06000CA */  sb        $zero, 0xca($v1)
/* 26764 8004B364 24A50001 */  addiu     $a1, $a1, 1
/* 26768 8004B368 28A20010 */  slti      $v0, $a1, 0x10
/* 2676C 8004B36C 1440FFF8 */  bnez      $v0, .L8004B350
/* 26770 8004B370 2463000A */   addiu    $v1, $v1, 0xa
/* 26774 8004B374 A0800165 */  sb        $zero, 0x165($a0)
/* 26778 8004B378 A0800164 */  sb        $zero, 0x164($a0)
/* 2677C 8004B37C A0800163 */  sb        $zero, 0x163($a0)
/* 26780 8004B380 03E00008 */  jr        $ra
/* 26784 8004B384 A0800162 */   sb       $zero, 0x162($a0)
