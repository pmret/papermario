.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_EF7DC0
/* EF7DC0 80240340 8C8400C0 */  lw        $a0, 0xc0($a0)
/* EF7DC4 80240344 8C83000C */  lw        $v1, 0xc($a0)
/* EF7DC8 80240348 24020045 */  addiu     $v0, $zero, 0x45
/* EF7DCC 8024034C AC620030 */  sw        $v0, 0x30($v1)
/* EF7DD0 80240350 8C83000C */  lw        $v1, 0xc($a0)
/* EF7DD4 80240354 240200FF */  addiu     $v0, $zero, 0xff
/* EF7DD8 80240358 AC620034 */  sw        $v0, 0x34($v1)
/* EF7DDC 8024035C 8C83000C */  lw        $v1, 0xc($a0)
/* EF7DE0 80240360 240200D9 */  addiu     $v0, $zero, 0xd9
/* EF7DE4 80240364 AC620038 */  sw        $v0, 0x38($v1)
/* EF7DE8 80240368 8C83000C */  lw        $v1, 0xc($a0)
/* EF7DEC 8024036C 240200B0 */  addiu     $v0, $zero, 0xb0
/* EF7DF0 80240370 AC620040 */  sw        $v0, 0x40($v1)
/* EF7DF4 80240374 8C83000C */  lw        $v1, 0xc($a0)
/* EF7DF8 80240378 240200FE */  addiu     $v0, $zero, 0xfe
/* EF7DFC 8024037C AC620044 */  sw        $v0, 0x44($v1)
/* EF7E00 80240380 8C83000C */  lw        $v1, 0xc($a0)
/* EF7E04 80240384 2402007C */  addiu     $v0, $zero, 0x7c
/* EF7E08 80240388 AC620048 */  sw        $v0, 0x48($v1)
/* EF7E0C 8024038C 03E00008 */  jr        $ra
/* EF7E10 80240390 24020002 */   addiu    $v0, $zero, 2
