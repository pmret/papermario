.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402B0_90CEF0
/* 90CEF0 802402B0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 90CEF4 802402B4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 90CEF8 802402B8 8C430000 */  lw        $v1, ($v0)
/* 90CEFC 802402BC 8C840084 */  lw        $a0, 0x84($a0)
/* 90CF00 802402C0 34630010 */  ori       $v1, $v1, 0x10
/* 90CF04 802402C4 AC4400D0 */  sw        $a0, 0xd0($v0)
/* 90CF08 802402C8 AC430000 */  sw        $v1, ($v0)
/* 90CF0C 802402CC 03E00008 */  jr        $ra
/* 90CF10 802402D0 24020002 */   addiu    $v0, $zero, 2
/* 90CF14 802402D4 00000000 */  nop       
/* 90CF18 802402D8 00000000 */  nop       
/* 90CF1C 802402DC 00000000 */  nop       
