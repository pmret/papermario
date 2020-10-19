.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_CDC9E0
/* CDC9E0 80240340 8C8400C0 */  lw        $a0, 0xc0($a0)
/* CDC9E4 80240344 8C83000C */  lw        $v1, 0xc($a0)
/* CDC9E8 80240348 24020045 */  addiu     $v0, $zero, 0x45
/* CDC9EC 8024034C AC620030 */  sw        $v0, 0x30($v1)
/* CDC9F0 80240350 8C83000C */  lw        $v1, 0xc($a0)
/* CDC9F4 80240354 240200FF */  addiu     $v0, $zero, 0xff
/* CDC9F8 80240358 AC620034 */  sw        $v0, 0x34($v1)
/* CDC9FC 8024035C 8C83000C */  lw        $v1, 0xc($a0)
/* CDCA00 80240360 240200D9 */  addiu     $v0, $zero, 0xd9
/* CDCA04 80240364 AC620038 */  sw        $v0, 0x38($v1)
/* CDCA08 80240368 8C83000C */  lw        $v1, 0xc($a0)
/* CDCA0C 8024036C 240200B0 */  addiu     $v0, $zero, 0xb0
/* CDCA10 80240370 AC620040 */  sw        $v0, 0x40($v1)
/* CDCA14 80240374 8C83000C */  lw        $v1, 0xc($a0)
/* CDCA18 80240378 240200FE */  addiu     $v0, $zero, 0xfe
/* CDCA1C 8024037C AC620044 */  sw        $v0, 0x44($v1)
/* CDCA20 80240380 8C83000C */  lw        $v1, 0xc($a0)
/* CDCA24 80240384 2402007C */  addiu     $v0, $zero, 0x7c
/* CDCA28 80240388 AC620048 */  sw        $v0, 0x48($v1)
/* CDCA2C 8024038C 03E00008 */  jr        $ra
/* CDCA30 80240390 24020002 */   addiu    $v0, $zero, 2
