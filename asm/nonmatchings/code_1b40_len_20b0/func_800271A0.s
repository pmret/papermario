.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800271A0
/* 25A0 800271A0 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 25A4 800271A4 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 25A8 800271A8 8C830000 */  lw        $v1, ($a0)
/* 25AC 800271AC 3C02DB06 */  lui       $v0, 0xdb06
/* 25B0 800271B0 0060282D */  daddu     $a1, $v1, $zero
/* 25B4 800271B4 24630008 */  addiu     $v1, $v1, 8
/* 25B8 800271B8 AC830000 */  sw        $v1, ($a0)
/* 25BC 800271BC ACA20000 */  sw        $v0, ($a1)
/* 25C0 800271C0 24620008 */  addiu     $v0, $v1, 8
/* 25C4 800271C4 ACA00004 */  sw        $zero, 4($a1)
/* 25C8 800271C8 3C05DE00 */  lui       $a1, 0xde00
/* 25CC 800271CC AC820000 */  sw        $v0, ($a0)
/* 25D0 800271D0 3C020007 */  lui       $v0, 7
/* 25D4 800271D4 24424230 */  addiu     $v0, $v0, 0x4230
/* 25D8 800271D8 AC620004 */  sw        $v0, 4($v1)
/* 25DC 800271DC 24620010 */  addiu     $v0, $v1, 0x10
/* 25E0 800271E0 AC650000 */  sw        $a1, ($v1)
/* 25E4 800271E4 AC820000 */  sw        $v0, ($a0)
/* 25E8 800271E8 3C020007 */  lui       $v0, 7
/* 25EC 800271EC 24424210 */  addiu     $v0, $v0, 0x4210
/* 25F0 800271F0 AC650008 */  sw        $a1, 8($v1)
/* 25F4 800271F4 03E00008 */  jr        $ra
/* 25F8 800271F8 AC62000C */   sw       $v0, 0xc($v1)
