.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024013C_C4C4CC
/* C4C4CC 8024013C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* C4C4D0 80240140 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* C4C4D4 80240144 C442002C */  lwc1      $f2, 0x2c($v0)
/* C4C4D8 80240148 44800000 */  mtc1      $zero, $f0
/* C4C4DC 8024014C 00000000 */  nop       
/* C4C4E0 80240150 4602003E */  c.le.s    $f0, $f2
/* C4C4E4 80240154 00000000 */  nop       
/* C4C4E8 80240158 45000003 */  bc1f      .L80240168
/* C4C4EC 8024015C 0040182D */   daddu    $v1, $v0, $zero
/* C4C4F0 80240160 03E00008 */  jr        $ra
/* C4C4F4 80240164 0000102D */   daddu    $v0, $zero, $zero
.L80240168:
/* C4C4F8 80240168 C4420028 */  lwc1      $f2, 0x28($v0)
/* C4C4FC 8024016C 3C0143DC */  lui       $at, 0x43dc
/* C4C500 80240170 44810000 */  mtc1      $at, $f0
/* C4C504 80240174 00000000 */  nop       
/* C4C508 80240178 4600103C */  c.lt.s    $f2, $f0
/* C4C50C 8024017C 00000000 */  nop       
/* C4C510 80240180 45000003 */  bc1f      .L80240190
/* C4C514 80240184 00000000 */   nop      
/* C4C518 80240188 0809006D */  j         .L802401B4
/* C4C51C 8024018C 24020003 */   addiu    $v0, $zero, 3
.L80240190:
/* C4C520 80240190 C4620030 */  lwc1      $f2, 0x30($v1)
/* C4C524 80240194 3C01C32A */  lui       $at, 0xc32a
/* C4C528 80240198 44810000 */  mtc1      $at, $f0
/* C4C52C 8024019C 00000000 */  nop       
/* C4C530 802401A0 4600103C */  c.lt.s    $f2, $f0
/* C4C534 802401A4 00000000 */  nop       
/* C4C538 802401A8 45000002 */  bc1f      .L802401B4
/* C4C53C 802401AC 24020001 */   addiu    $v0, $zero, 1
/* C4C540 802401B0 24020002 */  addiu     $v0, $zero, 2
.L802401B4:
/* C4C544 802401B4 AC820084 */  sw        $v0, 0x84($a0)
/* C4C548 802401B8 03E00008 */  jr        $ra
/* C4C54C 802401BC 24020002 */   addiu    $v0, $zero, 2
