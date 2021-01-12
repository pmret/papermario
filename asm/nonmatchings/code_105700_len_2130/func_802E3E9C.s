.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3E9C
/* 10571C 802E3E9C 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x4)
/* 105720 802E3EA0 8C42EFCC */  lw        $v0, %lo(gPlayerStatus+0x4)($v0)
/* 105724 802E3EA4 9083000B */  lbu       $v1, 0xb($a0)
/* 105728 802E3EA8 30420001 */  andi      $v0, $v0, 1
/* 10572C 802E3EAC 50400007 */  beql      $v0, $zero, .L802E3ECC
/* 105730 802E3EB0 2463FFE0 */   addiu    $v1, $v1, -0x20
/* 105734 802E3EB4 24630020 */  addiu     $v1, $v1, 0x20
/* 105738 802E3EB8 286200C1 */  slti      $v0, $v1, 0xc1
/* 10573C 802E3EBC 50400005 */  beql      $v0, $zero, .L802E3ED4
/* 105740 802E3EC0 240300C0 */   addiu    $v1, $zero, 0xc0
/* 105744 802E3EC4 03E00008 */  jr        $ra
/* 105748 802E3EC8 A083000B */   sb       $v1, 0xb($a0)
.L802E3ECC:
/* 10574C 802E3ECC 58600001 */  blezl     $v1, .L802E3ED4
/* 105750 802E3ED0 0000182D */   daddu    $v1, $zero, $zero
.L802E3ED4:
/* 105754 802E3ED4 A083000B */  sb        $v1, 0xb($a0)
/* 105758 802E3ED8 03E00008 */  jr        $ra
/* 10575C 802E3EDC 00000000 */   nop
