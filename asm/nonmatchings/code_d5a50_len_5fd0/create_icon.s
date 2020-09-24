.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_icon
/* D7BA4 801414A4 3C038015 */  lui       $v1, 0x8015
/* D7BA8 801414A8 8C637960 */  lw        $v1, 0x7960($v1)
/* D7BAC 801414AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7BB0 801414B0 AFB20018 */  sw        $s2, 0x18($sp)
/* D7BB4 801414B4 0080902D */  daddu     $s2, $a0, $zero
/* D7BB8 801414B8 AFB10014 */  sw        $s1, 0x14($sp)
/* D7BBC 801414BC 0000882D */  daddu     $s1, $zero, $zero
/* D7BC0 801414C0 AFBF001C */  sw        $ra, 0x1c($sp)
/* D7BC4 801414C4 AFB00010 */  sw        $s0, 0x10($sp)
.L801414C8:
/* D7BC8 801414C8 8C620000 */  lw        $v0, ($v1)
/* D7BCC 801414CC 10400006 */  beqz      $v0, .L801414E8
/* D7BD0 801414D0 2A220140 */   slti     $v0, $s1, 0x140
/* D7BD4 801414D4 26310001 */  addiu     $s1, $s1, 1
/* D7BD8 801414D8 2A220140 */  slti      $v0, $s1, 0x140
/* D7BDC 801414DC 1440FFFA */  bnez      $v0, .L801414C8
/* D7BE0 801414E0 24630004 */   addiu    $v1, $v1, 4
/* D7BE4 801414E4 2A220140 */  slti      $v0, $s1, 0x140
.L801414E8:
/* D7BE8 801414E8 14400003 */  bnez      $v0, .L801414F8
/* D7BEC 801414EC 00000000 */   nop      
.L801414F0:
/* D7BF0 801414F0 0805053C */  j         .L801414F0
/* D7BF4 801414F4 00000000 */   nop      
.L801414F8:
/* D7BF8 801414F8 0C00AB39 */  jal       heap_malloc
/* D7BFC 801414FC 24040054 */   addiu    $a0, $zero, 0x54
/* D7C00 80141500 00112080 */  sll       $a0, $s1, 2
/* D7C04 80141504 3C038015 */  lui       $v1, 0x8015
/* D7C08 80141508 8C637960 */  lw        $v1, 0x7960($v1)
/* D7C0C 8014150C 3C058015 */  lui       $a1, 0x8015
/* D7C10 80141510 24A512B4 */  addiu     $a1, $a1, 0x12b4
/* D7C14 80141514 00832021 */  addu      $a0, $a0, $v1
/* D7C18 80141518 8CA30000 */  lw        $v1, ($a1)
/* D7C1C 8014151C 0040802D */  daddu     $s0, $v0, $zero
/* D7C20 80141520 AC900000 */  sw        $s0, ($a0)
/* D7C24 80141524 24630001 */  addiu     $v1, $v1, 1
/* D7C28 80141528 16000003 */  bnez      $s0, .L80141538
/* D7C2C 8014152C ACA30000 */   sw       $v1, ($a1)
.L80141530:
/* D7C30 80141530 0805054C */  j         .L80141530
/* D7C34 80141534 00000000 */   nop      
.L80141538:
/* D7C38 80141538 24030001 */  addiu     $v1, $zero, 1
/* D7C3C 8014153C AE030000 */  sw        $v1, ($s0)
/* D7C40 80141540 16400004 */  bnez      $s2, .L80141554
/* D7C44 80141544 AE120004 */   sw       $s2, 4($s0)
/* D7C48 80141548 3C028015 */  lui       $v0, 0x8015
/* D7C4C 8014154C 2442EFC8 */  addiu     $v0, $v0, -0x1038
/* D7C50 80141550 AE020004 */  sw        $v0, 4($s0)
.L80141554:
/* D7C54 80141554 A2030047 */  sb        $v1, 0x47($s0)
/* D7C58 80141558 8E030004 */  lw        $v1, 4($s0)
/* D7C5C 8014155C 3C013F80 */  lui       $at, 0x3f80
/* D7C60 80141560 44810000 */  mtc1      $at, $f0
/* D7C64 80141564 2402FFFF */  addiu     $v0, $zero, -1
/* D7C68 80141568 A2020045 */  sb        $v0, 0x45($s0)
/* D7C6C 8014156C A2020046 */  sb        $v0, 0x46($s0)
/* D7C70 80141570 240200FF */  addiu     $v0, $zero, 0xff
/* D7C74 80141574 A2000040 */  sb        $zero, 0x40($s0)
/* D7C78 80141578 A2000041 */  sb        $zero, 0x41($s0)
/* D7C7C 8014157C A2000042 */  sb        $zero, 0x42($s0)
/* D7C80 80141580 A2000043 */  sb        $zero, 0x43($s0)
/* D7C84 80141584 A2000044 */  sb        $zero, 0x44($s0)
/* D7C88 80141588 A202004A */  sb        $v0, 0x4a($s0)
/* D7C8C 8014158C A202004B */  sb        $v0, 0x4b($s0)
/* D7C90 80141590 A202004C */  sb        $v0, 0x4c($s0)
/* D7C94 80141594 A202004D */  sb        $v0, 0x4d($s0)
/* D7C98 80141598 3C048007 */  lui       $a0, 0x8007
/* D7C9C 8014159C 8C84419C */  lw        $a0, 0x419c($a0)
/* D7CA0 801415A0 24020400 */  addiu     $v0, $zero, 0x400
/* D7CA4 801415A4 A600003C */  sh        $zero, 0x3c($s0)
/* D7CA8 801415A8 A600003E */  sh        $zero, 0x3e($s0)
/* D7CAC 801415AC AE12000C */  sw        $s2, 0xc($s0)
/* D7CB0 801415B0 AE020034 */  sw        $v0, 0x34($s0)
/* D7CB4 801415B4 AE020038 */  sw        $v0, 0x38($s0)
/* D7CB8 801415B8 AE030008 */  sw        $v1, 8($s0)
/* D7CBC 801415BC E6000030 */  swc1      $f0, 0x30($s0)
/* D7CC0 801415C0 80820070 */  lb        $v0, 0x70($a0)
/* D7CC4 801415C4 10400005 */  beqz      $v0, .L801415DC
/* D7CC8 801415C8 00000000 */   nop      
/* D7CCC 801415CC 8E020000 */  lw        $v0, ($s0)
/* D7CD0 801415D0 36310800 */  ori       $s1, $s1, 0x800
/* D7CD4 801415D4 34420400 */  ori       $v0, $v0, 0x400
/* D7CD8 801415D8 AE020000 */  sw        $v0, ($s0)
.L801415DC:
/* D7CDC 801415DC 8E050004 */  lw        $a1, 4($s0)
/* D7CE0 801415E0 0C04FCD4 */  jal       func_8013F350
/* D7CE4 801415E4 0200202D */   daddu    $a0, $s0, $zero
.L801415E8:
/* D7CE8 801415E8 0C0505C1 */  jal       func_80141704
/* D7CEC 801415EC 0200202D */   daddu    $a0, $s0, $zero
/* D7CF0 801415F0 1440FFFD */  bnez      $v0, .L801415E8
/* D7CF4 801415F4 0220102D */   daddu    $v0, $s1, $zero
/* D7CF8 801415F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* D7CFC 801415FC 8FB20018 */  lw        $s2, 0x18($sp)
/* D7D00 80141600 8FB10014 */  lw        $s1, 0x14($sp)
/* D7D04 80141604 8FB00010 */  lw        $s0, 0x10($sp)
/* D7D08 80141608 03E00008 */  jr        $ra
/* D7D0C 8014160C 27BD0020 */   addiu    $sp, $sp, 0x20
