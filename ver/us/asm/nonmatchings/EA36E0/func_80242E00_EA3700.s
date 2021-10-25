.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_set_cursor_goal_pos_EA3700
/* EA3700 80242E00 3C038011 */  lui       $v1, %hi(dead_gPartnerActionStatus2)
/* EA3704 80242E04 24637160 */  addiu     $v1, $v1, %lo(dead_gPartnerActionStatus2)
/* EA3708 80242E08 80620000 */  lb        $v0, ($v1)
/* EA370C 80242E0C 10400004 */  beqz      $v0, .L80242E20
/* EA3710 80242E10 2402FFFF */   addiu    $v0, $zero, -1
/* EA3714 80242E14 80620003 */  lb        $v0, 3($v1)
/* EA3718 80242E18 08090B89 */  j         .L80242E24
/* EA371C 80242E1C AC820084 */   sw       $v0, 0x84($a0)
.L80242E20:
/* EA3720 80242E20 AC820084 */  sw        $v0, 0x84($a0)
.L80242E24:
/* EA3724 80242E24 03E00008 */  jr        $ra
/* EA3728 80242E28 24020002 */   addiu    $v0, $zero, 2
