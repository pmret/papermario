.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD180_31CC70
/* 31CCF0 802BD180 3C03802C */  lui       $v1, 0x802c
/* 31CCF4 802BD184 2463E310 */  addiu     $v1, $v1, -0x1cf0
/* 31CCF8 802BD188 8C620000 */  lw        $v0, ($v1)
/* 31CCFC 802BD18C 10400005 */  beqz      $v0, .L802BD1A4
/* 31CD00 802BD190 00000000 */   nop      
/* 31CD04 802BD194 AC600000 */  sw        $zero, ($v1)
/* 31CD08 802BD198 8C43000C */  lw        $v1, 0xc($v0)
/* 31CD0C 802BD19C 24020001 */  addiu     $v0, $zero, 1
/* 31CD10 802BD1A0 AC620028 */  sw        $v0, 0x28($v1)
.L802BD1A4:
/* 31CD14 802BD1A4 03E00008 */  jr        $ra
/* 31CD18 802BD1A8 00000000 */   nop      
