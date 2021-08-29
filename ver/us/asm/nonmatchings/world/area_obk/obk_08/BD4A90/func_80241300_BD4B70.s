.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241300_BD4B70
/* BD4B70 80241300 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* BD4B74 80241304 AFB20020 */  sw        $s2, 0x20($sp)
/* BD4B78 80241308 0080902D */  daddu     $s2, $a0, $zero
/* BD4B7C 8024130C 24040001 */  addiu     $a0, $zero, 1
/* BD4B80 80241310 AFBF003C */  sw        $ra, 0x3c($sp)
/* BD4B84 80241314 AFBE0038 */  sw        $fp, 0x38($sp)
/* BD4B88 80241318 AFB70034 */  sw        $s7, 0x34($sp)
/* BD4B8C 8024131C AFB60030 */  sw        $s6, 0x30($sp)
/* BD4B90 80241320 AFB5002C */  sw        $s5, 0x2c($sp)
/* BD4B94 80241324 AFB40028 */  sw        $s4, 0x28($sp)
/* BD4B98 80241328 AFB30024 */  sw        $s3, 0x24($sp)
/* BD4B9C 8024132C AFB1001C */  sw        $s1, 0x1c($sp)
/* BD4BA0 80241330 0C00EABB */  jal       get_npc_unsafe
/* BD4BA4 80241334 AFB00018 */   sw       $s0, 0x18($sp)
/* BD4BA8 80241338 24040002 */  addiu     $a0, $zero, 2
/* BD4BAC 8024133C 0C00EABB */  jal       get_npc_unsafe
/* BD4BB0 80241340 0040802D */   daddu    $s0, $v0, $zero
/* BD4BB4 80241344 24040003 */  addiu     $a0, $zero, 3
/* BD4BB8 80241348 0C00EABB */  jal       get_npc_unsafe
/* BD4BBC 8024134C 0040982D */   daddu    $s3, $v0, $zero
/* BD4BC0 80241350 24040004 */  addiu     $a0, $zero, 4
/* BD4BC4 80241354 0C00EABB */  jal       get_npc_unsafe
/* BD4BC8 80241358 0040A02D */   daddu    $s4, $v0, $zero
/* BD4BCC 8024135C 24040005 */  addiu     $a0, $zero, 5
/* BD4BD0 80241360 0C00EABB */  jal       get_npc_unsafe
/* BD4BD4 80241364 0040A82D */   daddu    $s5, $v0, $zero
/* BD4BD8 80241368 24040006 */  addiu     $a0, $zero, 6
/* BD4BDC 8024136C 0C00EABB */  jal       get_npc_unsafe
/* BD4BE0 80241370 0040B02D */   daddu    $s6, $v0, $zero
/* BD4BE4 80241374 24040007 */  addiu     $a0, $zero, 7
/* BD4BE8 80241378 0C00EABB */  jal       get_npc_unsafe
/* BD4BEC 8024137C 0040B82D */   daddu    $s7, $v0, $zero
/* BD4BF0 80241380 24040008 */  addiu     $a0, $zero, 8
/* BD4BF4 80241384 0C00EABB */  jal       get_npc_unsafe
/* BD4BF8 80241388 0040F02D */   daddu    $fp, $v0, $zero
/* BD4BFC 8024138C 0240202D */  daddu     $a0, $s2, $zero
/* BD4C00 80241390 3C05FD05 */  lui       $a1, 0xfd05
/* BD4C04 80241394 34A50F83 */  ori       $a1, $a1, 0xf83
/* BD4C08 80241398 0000302D */  daddu     $a2, $zero, $zero
/* BD4C0C 8024139C AE400088 */  sw        $zero, 0x88($s2)
/* BD4C10 802413A0 0C0B2026 */  jal       evt_set_variable
/* BD4C14 802413A4 AFA20010 */   sw       $v0, 0x10($sp)
/* BD4C18 802413A8 8E430084 */  lw        $v1, 0x84($s2)
/* BD4C1C 802413AC C602000C */  lwc1      $f2, 0xc($s0)
/* BD4C20 802413B0 2462FFE9 */  addiu     $v0, $v1, -0x17
/* BD4C24 802413B4 44820000 */  mtc1      $v0, $f0
/* BD4C28 802413B8 00000000 */  nop
/* BD4C2C 802413BC 46800020 */  cvt.s.w   $f0, $f0
/* BD4C30 802413C0 4600103E */  c.le.s    $f2, $f0
/* BD4C34 802413C4 00000000 */  nop
/* BD4C38 802413C8 4500000C */  bc1f      .L802413FC
/* BD4C3C 802413CC 0000882D */   daddu    $s1, $zero, $zero
/* BD4C40 802413D0 2462FFE5 */  addiu     $v0, $v1, -0x1b
/* BD4C44 802413D4 44820000 */  mtc1      $v0, $f0
/* BD4C48 802413D8 00000000 */  nop
/* BD4C4C 802413DC 46800020 */  cvt.s.w   $f0, $f0
/* BD4C50 802413E0 4602003E */  c.le.s    $f0, $f2
/* BD4C54 802413E4 00000000 */  nop
/* BD4C58 802413E8 45000004 */  bc1f      .L802413FC
/* BD4C5C 802413EC 24020001 */   addiu    $v0, $zero, 1
/* BD4C60 802413F0 AE420088 */  sw        $v0, 0x88($s2)
/* BD4C64 802413F4 0040882D */  daddu     $s1, $v0, $zero
/* BD4C68 802413F8 8E430084 */  lw        $v1, 0x84($s2)
.L802413FC:
/* BD4C6C 802413FC C662000C */  lwc1      $f2, 0xc($s3)
/* BD4C70 80241400 2462FFE9 */  addiu     $v0, $v1, -0x17
/* BD4C74 80241404 44820000 */  mtc1      $v0, $f0
/* BD4C78 80241408 00000000 */  nop
/* BD4C7C 8024140C 46800020 */  cvt.s.w   $f0, $f0
/* BD4C80 80241410 4600103E */  c.le.s    $f2, $f0
/* BD4C84 80241414 00000000 */  nop
/* BD4C88 80241418 4500000A */  bc1f      .L80241444
/* BD4C8C 8024141C 2462FFE5 */   addiu    $v0, $v1, -0x1b
/* BD4C90 80241420 44820000 */  mtc1      $v0, $f0
/* BD4C94 80241424 00000000 */  nop
/* BD4C98 80241428 46800020 */  cvt.s.w   $f0, $f0
/* BD4C9C 8024142C 4602003E */  c.le.s    $f0, $f2
/* BD4CA0 80241430 00000000 */  nop
/* BD4CA4 80241434 45000003 */  bc1f      .L80241444
/* BD4CA8 80241438 24020001 */   addiu    $v0, $zero, 1
/* BD4CAC 8024143C AE420088 */  sw        $v0, 0x88($s2)
/* BD4CB0 80241440 24110002 */  addiu     $s1, $zero, 2
.L80241444:
/* BD4CB4 80241444 8E430084 */  lw        $v1, 0x84($s2)
/* BD4CB8 80241448 C682000C */  lwc1      $f2, 0xc($s4)
/* BD4CBC 8024144C 2462FFE9 */  addiu     $v0, $v1, -0x17
/* BD4CC0 80241450 44820000 */  mtc1      $v0, $f0
/* BD4CC4 80241454 00000000 */  nop
/* BD4CC8 80241458 46800020 */  cvt.s.w   $f0, $f0
/* BD4CCC 8024145C 4600103E */  c.le.s    $f2, $f0
/* BD4CD0 80241460 00000000 */  nop
/* BD4CD4 80241464 4500000B */  bc1f      .L80241494
/* BD4CD8 80241468 2462FFE5 */   addiu    $v0, $v1, -0x1b
/* BD4CDC 8024146C 44820000 */  mtc1      $v0, $f0
/* BD4CE0 80241470 00000000 */  nop
/* BD4CE4 80241474 46800020 */  cvt.s.w   $f0, $f0
/* BD4CE8 80241478 4602003E */  c.le.s    $f0, $f2
/* BD4CEC 8024147C 00000000 */  nop
/* BD4CF0 80241480 45000004 */  bc1f      .L80241494
/* BD4CF4 80241484 24020001 */   addiu    $v0, $zero, 1
/* BD4CF8 80241488 AE420088 */  sw        $v0, 0x88($s2)
/* BD4CFC 8024148C 24110003 */  addiu     $s1, $zero, 3
/* BD4D00 80241490 8E430084 */  lw        $v1, 0x84($s2)
.L80241494:
/* BD4D04 80241494 C6A2000C */  lwc1      $f2, 0xc($s5)
/* BD4D08 80241498 2462FFE9 */  addiu     $v0, $v1, -0x17
/* BD4D0C 8024149C 44820000 */  mtc1      $v0, $f0
/* BD4D10 802414A0 00000000 */  nop
/* BD4D14 802414A4 46800020 */  cvt.s.w   $f0, $f0
/* BD4D18 802414A8 4600103E */  c.le.s    $f2, $f0
/* BD4D1C 802414AC 00000000 */  nop
/* BD4D20 802414B0 4500000A */  bc1f      .L802414DC
/* BD4D24 802414B4 2462FFE5 */   addiu    $v0, $v1, -0x1b
/* BD4D28 802414B8 44820000 */  mtc1      $v0, $f0
/* BD4D2C 802414BC 00000000 */  nop
/* BD4D30 802414C0 46800020 */  cvt.s.w   $f0, $f0
/* BD4D34 802414C4 4602003E */  c.le.s    $f0, $f2
/* BD4D38 802414C8 00000000 */  nop
/* BD4D3C 802414CC 45000003 */  bc1f      .L802414DC
/* BD4D40 802414D0 24020001 */   addiu    $v0, $zero, 1
/* BD4D44 802414D4 AE420088 */  sw        $v0, 0x88($s2)
/* BD4D48 802414D8 24110004 */  addiu     $s1, $zero, 4
.L802414DC:
/* BD4D4C 802414DC 8E430084 */  lw        $v1, 0x84($s2)
/* BD4D50 802414E0 C6C2000C */  lwc1      $f2, 0xc($s6)
/* BD4D54 802414E4 2462FFE9 */  addiu     $v0, $v1, -0x17
/* BD4D58 802414E8 44820000 */  mtc1      $v0, $f0
/* BD4D5C 802414EC 00000000 */  nop
/* BD4D60 802414F0 46800020 */  cvt.s.w   $f0, $f0
/* BD4D64 802414F4 4600103E */  c.le.s    $f2, $f0
/* BD4D68 802414F8 00000000 */  nop
/* BD4D6C 802414FC 4500000B */  bc1f      .L8024152C
/* BD4D70 80241500 2462FFE5 */   addiu    $v0, $v1, -0x1b
/* BD4D74 80241504 44820000 */  mtc1      $v0, $f0
/* BD4D78 80241508 00000000 */  nop
/* BD4D7C 8024150C 46800020 */  cvt.s.w   $f0, $f0
/* BD4D80 80241510 4602003E */  c.le.s    $f0, $f2
/* BD4D84 80241514 00000000 */  nop
/* BD4D88 80241518 45000004 */  bc1f      .L8024152C
/* BD4D8C 8024151C 24020001 */   addiu    $v0, $zero, 1
/* BD4D90 80241520 AE420088 */  sw        $v0, 0x88($s2)
/* BD4D94 80241524 24110005 */  addiu     $s1, $zero, 5
/* BD4D98 80241528 8E430084 */  lw        $v1, 0x84($s2)
.L8024152C:
/* BD4D9C 8024152C C6E2000C */  lwc1      $f2, 0xc($s7)
/* BD4DA0 80241530 2462FFE9 */  addiu     $v0, $v1, -0x17
/* BD4DA4 80241534 44820000 */  mtc1      $v0, $f0
/* BD4DA8 80241538 00000000 */  nop
/* BD4DAC 8024153C 46800020 */  cvt.s.w   $f0, $f0
/* BD4DB0 80241540 4600103E */  c.le.s    $f2, $f0
/* BD4DB4 80241544 00000000 */  nop
/* BD4DB8 80241548 4500000A */  bc1f      .L80241574
/* BD4DBC 8024154C 2462FFE5 */   addiu    $v0, $v1, -0x1b
/* BD4DC0 80241550 44820000 */  mtc1      $v0, $f0
/* BD4DC4 80241554 00000000 */  nop
/* BD4DC8 80241558 46800020 */  cvt.s.w   $f0, $f0
/* BD4DCC 8024155C 4602003E */  c.le.s    $f0, $f2
/* BD4DD0 80241560 00000000 */  nop
/* BD4DD4 80241564 45000003 */  bc1f      .L80241574
/* BD4DD8 80241568 24020001 */   addiu    $v0, $zero, 1
/* BD4DDC 8024156C AE420088 */  sw        $v0, 0x88($s2)
/* BD4DE0 80241570 24110006 */  addiu     $s1, $zero, 6
.L80241574:
/* BD4DE4 80241574 8E430084 */  lw        $v1, 0x84($s2)
/* BD4DE8 80241578 C7C2000C */  lwc1      $f2, 0xc($fp)
/* BD4DEC 8024157C 2462FFE9 */  addiu     $v0, $v1, -0x17
/* BD4DF0 80241580 44820000 */  mtc1      $v0, $f0
/* BD4DF4 80241584 00000000 */  nop
/* BD4DF8 80241588 46800020 */  cvt.s.w   $f0, $f0
/* BD4DFC 8024158C 4600103E */  c.le.s    $f2, $f0
/* BD4E00 80241590 00000000 */  nop
/* BD4E04 80241594 4500000B */  bc1f      .L802415C4
/* BD4E08 80241598 2462FFE5 */   addiu    $v0, $v1, -0x1b
/* BD4E0C 8024159C 44820000 */  mtc1      $v0, $f0
/* BD4E10 802415A0 00000000 */  nop
/* BD4E14 802415A4 46800020 */  cvt.s.w   $f0, $f0
/* BD4E18 802415A8 4602003E */  c.le.s    $f0, $f2
/* BD4E1C 802415AC 00000000 */  nop
/* BD4E20 802415B0 45000004 */  bc1f      .L802415C4
/* BD4E24 802415B4 24020001 */   addiu    $v0, $zero, 1
/* BD4E28 802415B8 AE420088 */  sw        $v0, 0x88($s2)
/* BD4E2C 802415BC 24110007 */  addiu     $s1, $zero, 7
/* BD4E30 802415C0 8E430084 */  lw        $v1, 0x84($s2)
.L802415C4:
/* BD4E34 802415C4 8FA70010 */  lw        $a3, 0x10($sp)
/* BD4E38 802415C8 2462FFE9 */  addiu     $v0, $v1, -0x17
/* BD4E3C 802415CC C4E2000C */  lwc1      $f2, 0xc($a3)
/* BD4E40 802415D0 44820000 */  mtc1      $v0, $f0
/* BD4E44 802415D4 00000000 */  nop
/* BD4E48 802415D8 46800020 */  cvt.s.w   $f0, $f0
/* BD4E4C 802415DC 4600103E */  c.le.s    $f2, $f0
/* BD4E50 802415E0 00000000 */  nop
/* BD4E54 802415E4 4500000A */  bc1f      .L80241610
/* BD4E58 802415E8 2462FFE5 */   addiu    $v0, $v1, -0x1b
/* BD4E5C 802415EC 44820000 */  mtc1      $v0, $f0
/* BD4E60 802415F0 00000000 */  nop
/* BD4E64 802415F4 46800020 */  cvt.s.w   $f0, $f0
/* BD4E68 802415F8 4602003E */  c.le.s    $f0, $f2
/* BD4E6C 802415FC 00000000 */  nop
/* BD4E70 80241600 45000003 */  bc1f      .L80241610
/* BD4E74 80241604 24020001 */   addiu    $v0, $zero, 1
/* BD4E78 80241608 AE420088 */  sw        $v0, 0x88($s2)
/* BD4E7C 8024160C 24110008 */  addiu     $s1, $zero, 8
.L80241610:
/* BD4E80 80241610 0240202D */  daddu     $a0, $s2, $zero
/* BD4E84 80241614 3C05FD05 */  lui       $a1, 0xfd05
/* BD4E88 80241618 34A50F83 */  ori       $a1, $a1, 0xf83
/* BD4E8C 8024161C 0C0B2026 */  jal       evt_set_variable
/* BD4E90 80241620 0220302D */   daddu    $a2, $s1, $zero
/* BD4E94 80241624 8FBF003C */  lw        $ra, 0x3c($sp)
/* BD4E98 80241628 8FBE0038 */  lw        $fp, 0x38($sp)
/* BD4E9C 8024162C 8FB70034 */  lw        $s7, 0x34($sp)
/* BD4EA0 80241630 8FB60030 */  lw        $s6, 0x30($sp)
/* BD4EA4 80241634 8FB5002C */  lw        $s5, 0x2c($sp)
/* BD4EA8 80241638 8FB40028 */  lw        $s4, 0x28($sp)
/* BD4EAC 8024163C 8FB30024 */  lw        $s3, 0x24($sp)
/* BD4EB0 80241640 8FB20020 */  lw        $s2, 0x20($sp)
/* BD4EB4 80241644 8FB1001C */  lw        $s1, 0x1c($sp)
/* BD4EB8 80241648 8FB00018 */  lw        $s0, 0x18($sp)
/* BD4EBC 8024164C 24020002 */  addiu     $v0, $zero, 2
/* BD4EC0 80241650 03E00008 */  jr        $ra
/* BD4EC4 80241654 27BD0040 */   addiu    $sp, $sp, 0x40
