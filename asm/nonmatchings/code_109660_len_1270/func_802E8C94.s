.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E8C94
/* 10A514 802E8C94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10A518 802E8C98 AFBF0010 */  sw        $ra, 0x10($sp)
/* 10A51C 802E8C9C 8C820040 */  lw        $v0, 0x40($a0)
/* 10A520 802E8CA0 8C430004 */  lw        $v1, 4($v0)
/* 10A524 802E8CA4 2463FFFF */  addiu     $v1, $v1, -1
/* 10A528 802E8CA8 AC430004 */  sw        $v1, 4($v0)
/* 10A52C 802E8CAC 2402FFFF */  addiu     $v0, $zero, -1
/* 10A530 802E8CB0 14620003 */  bne       $v1, $v0, .L802E8CC0
/* 10A534 802E8CB4 00000000 */   nop
/* 10A538 802E8CB8 0C043F5A */  jal       func_8010FD68
/* 10A53C 802E8CBC 00000000 */   nop
.L802E8CC0:
/* 10A540 802E8CC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10A544 802E8CC4 03E00008 */  jr        $ra
/* 10A548 802E8CC8 27BD0018 */   addiu    $sp, $sp, 0x18
