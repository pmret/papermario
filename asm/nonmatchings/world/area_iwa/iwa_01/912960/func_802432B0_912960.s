.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802432B0_912960
/* 912960 802432B0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 912964 802432B4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 912968 802432B8 8C430000 */  lw        $v1, ($v0)
/* 91296C 802432BC 8C840084 */  lw        $a0, 0x84($a0)
/* 912970 802432C0 34630010 */  ori       $v1, $v1, 0x10
/* 912974 802432C4 AC4400D0 */  sw        $a0, 0xd0($v0)
/* 912978 802432C8 AC430000 */  sw        $v1, ($v0)
/* 91297C 802432CC 03E00008 */  jr        $ra
/* 912980 802432D0 24020002 */   addiu    $v0, $zero, 2
/* 912984 802432D4 00000000 */  nop       
/* 912988 802432D8 00000000 */  nop       
/* 91298C 802432DC 00000000 */  nop       
