.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180D0_464560
/* 464560 802180D0 2403000B */  addiu     $v1, $zero, 0xb
/* 464564 802180D4 3C028023 */  lui       $v0, %hi(D_80232C4C)
/* 464568 802180D8 24422C4C */  addiu     $v0, $v0, %lo(D_80232C4C)
.L802180DC:
/* 46456C 802180DC AC400000 */  sw        $zero, ($v0)
/* 464570 802180E0 2463FFFF */  addiu     $v1, $v1, -1
/* 464574 802180E4 0461FFFD */  bgez      $v1, .L802180DC
/* 464578 802180E8 2442FFFC */   addiu    $v0, $v0, -4
/* 46457C 802180EC 2402FFFF */  addiu     $v0, $zero, -1
/* 464580 802180F0 3C018023 */  lui       $at, %hi(D_80232C50)
/* 464584 802180F4 AC222C50 */  sw        $v0, %lo(D_80232C50)($at)
/* 464588 802180F8 03E00008 */  jr        $ra
/* 46458C 802180FC 24020002 */   addiu    $v0, $zero, 2
