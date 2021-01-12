.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF600
/* 88AB0 800EF600 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 88AB4 800EF604 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 88AB8 800EF608 90620014 */  lbu       $v0, 0x14($v1)
/* 88ABC 800EF60C 2442FFFF */  addiu     $v0, $v0, -1
/* 88AC0 800EF610 A0620014 */  sb        $v0, 0x14($v1)
/* 88AC4 800EF614 00021600 */  sll       $v0, $v0, 0x18
/* 88AC8 800EF618 04420001 */  bltzl     $v0, .L800EF620
/* 88ACC 800EF61C A0600014 */   sb       $zero, 0x14($v1)
.L800EF620:
/* 88AD0 800EF620 03E00008 */  jr        $ra
/* 88AD4 800EF624 00000000 */   nop
