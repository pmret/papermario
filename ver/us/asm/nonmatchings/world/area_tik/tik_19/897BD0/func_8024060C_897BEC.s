.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024060C_897BEC
/* 897BEC 8024060C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 897BF0 80240610 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* 897BF4 80240614 8C430000 */  lw        $v1, ($v0)
/* 897BF8 80240618 2404FFBF */  addiu     $a0, $zero, -0x41
/* 897BFC 8024061C 00641824 */  and       $v1, $v1, $a0
/* 897C00 80240620 AC430000 */  sw        $v1, ($v0)
/* 897C04 80240624 03E00008 */  jr        $ra
/* 897C08 80240628 24020002 */   addiu    $v0, $zero, 2
