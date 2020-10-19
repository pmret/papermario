.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E24
/* 969FE4 80240E24 3C028025 */  lui       $v0, 0x8025
/* 969FE8 80240E28 8C42EFC8 */  lw        $v0, -0x1038($v0)
/* 969FEC 80240E2C 8C43000C */  lw        $v1, 0xc($v0)
/* 969FF0 80240E30 24020002 */  addiu     $v0, $zero, 2
/* 969FF4 80240E34 03E00008 */  jr        $ra
/* 969FF8 80240E38 AC62001C */   sw       $v0, 0x1c($v1)
