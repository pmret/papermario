.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F8_ADB298
/* ADB298 802403F8 3C02E300 */  lui       $v0, 0xe300
/* ADB29C 802403FC 34420A01 */  ori       $v0, $v0, 0xa01
/* ADB2A0 80240400 3C07E200 */  lui       $a3, 0xe200
/* ADB2A4 80240404 34E7001C */  ori       $a3, $a3, 0x1c
/* ADB2A8 80240408 3C060C18 */  lui       $a2, 0xc18
/* ADB2AC 8024040C 34C649D8 */  ori       $a2, $a2, 0x49d8
/* ADB2B0 80240410 3C08FC11 */  lui       $t0, 0xfc11
/* ADB2B4 80240414 3C04800A */  lui       $a0, 0x800a
/* ADB2B8 80240418 2484A66C */  addiu     $a0, $a0, -0x5994
/* ADB2BC 8024041C 8C830000 */  lw        $v1, ($a0)
/* ADB2C0 80240420 350815FF */  ori       $t0, $t0, 0x15ff
/* ADB2C4 80240424 0060282D */  daddu     $a1, $v1, $zero
/* ADB2C8 80240428 24630008 */  addiu     $v1, $v1, 8
/* ADB2CC 8024042C AC830000 */  sw        $v1, ($a0)
/* ADB2D0 80240430 ACA20000 */  sw        $v0, ($a1)
/* ADB2D4 80240434 3C020010 */  lui       $v0, 0x10
/* ADB2D8 80240438 ACA20004 */  sw        $v0, 4($a1)
/* ADB2DC 8024043C 24620008 */  addiu     $v0, $v1, 8
/* ADB2E0 80240440 AC820000 */  sw        $v0, ($a0)
/* ADB2E4 80240444 24620010 */  addiu     $v0, $v1, 0x10
/* ADB2E8 80240448 AC670000 */  sw        $a3, ($v1)
/* ADB2EC 8024044C AC660004 */  sw        $a2, 4($v1)
/* ADB2F0 80240450 AC820000 */  sw        $v0, ($a0)
/* ADB2F4 80240454 2402FE3B */  addiu     $v0, $zero, -0x1c5
/* ADB2F8 80240458 AC62000C */  sw        $v0, 0xc($v1)
/* ADB2FC 8024045C 24620018 */  addiu     $v0, $v1, 0x18
/* ADB300 80240460 AC680008 */  sw        $t0, 8($v1)
/* ADB304 80240464 AC820000 */  sw        $v0, ($a0)
/* ADB308 80240468 3C048024 */  lui       $a0, 0x8024
/* ADB30C 8024046C 90841D3B */  lbu       $a0, 0x1d3b($a0)
/* ADB310 80240470 3C02FA00 */  lui       $v0, 0xfa00
/* ADB314 80240474 AC620010 */  sw        $v0, 0x10($v1)
/* ADB318 80240478 03E00008 */  jr        $ra
/* ADB31C 8024047C AC640014 */   sw       $a0, 0x14($v1)
