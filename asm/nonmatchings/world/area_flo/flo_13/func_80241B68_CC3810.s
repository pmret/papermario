.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B68_CC5378
/* CC5378 80241B68 27BDFF98 */  addiu     $sp, $sp, -0x68
/* CC537C 80241B6C AFB20048 */  sw        $s2, 0x48($sp)
/* CC5380 80241B70 0080902D */  daddu     $s2, $a0, $zero
/* CC5384 80241B74 AFBF0054 */  sw        $ra, 0x54($sp)
/* CC5388 80241B78 AFB40050 */  sw        $s4, 0x50($sp)
/* CC538C 80241B7C AFB3004C */  sw        $s3, 0x4c($sp)
/* CC5390 80241B80 AFB10044 */  sw        $s1, 0x44($sp)
/* CC5394 80241B84 AFB00040 */  sw        $s0, 0x40($sp)
/* CC5398 80241B88 F7B60060 */  sdc1      $f22, 0x60($sp)
/* CC539C 80241B8C F7B40058 */  sdc1      $f20, 0x58($sp)
/* CC53A0 80241B90 8E510148 */  lw        $s1, 0x148($s2)
/* CC53A4 80241B94 00A0982D */  daddu     $s3, $a1, $zero
/* CC53A8 80241B98 86240008 */  lh        $a0, 8($s1)
/* CC53AC 80241B9C 0C00EABB */  jal       get_npc_unsafe
/* CC53B0 80241BA0 00C0A02D */   daddu    $s4, $a2, $zero
/* CC53B4 80241BA4 0040802D */  daddu     $s0, $v0, $zero
/* CC53B8 80241BA8 C6200078 */  lwc1      $f0, 0x78($s1)
/* CC53BC 80241BAC 46800020 */  cvt.s.w   $f0, $f0
/* CC53C0 80241BB0 46000021 */  cvt.d.s   $f0, $f0
/* CC53C4 80241BB4 3C014059 */  lui       $at, 0x4059
/* CC53C8 80241BB8 44814800 */  mtc1      $at, $f9
/* CC53CC 80241BBC 44804000 */  mtc1      $zero, $f8
/* CC53D0 80241BC0 8602008E */  lh        $v0, 0x8e($s0)
/* CC53D4 80241BC4 9603008E */  lhu       $v1, 0x8e($s0)
/* CC53D8 80241BC8 46280003 */  div.d     $f0, $f0, $f8
/* CC53DC 80241BCC 18400003 */  blez      $v0, .L80241BDC
/* CC53E0 80241BD0 462005A0 */   cvt.s.d  $f22, $f0
/* CC53E4 80241BD4 2462FFFF */  addiu     $v0, $v1, -1
/* CC53E8 80241BD8 A602008E */  sh        $v0, 0x8e($s0)
.L80241BDC:
/* CC53EC 80241BDC 27A50028 */  addiu     $a1, $sp, 0x28
/* CC53F0 80241BE0 27A6002C */  addiu     $a2, $sp, 0x2c
/* CC53F4 80241BE4 27A70030 */  addiu     $a3, $sp, 0x30
/* CC53F8 80241BE8 C6000038 */  lwc1      $f0, 0x38($s0)
/* CC53FC 80241BEC C602003C */  lwc1      $f2, 0x3c($s0)
/* CC5400 80241BF0 C6040040 */  lwc1      $f4, 0x40($s0)
/* CC5404 80241BF4 3C01447A */  lui       $at, 0x447a
/* CC5408 80241BF8 44813000 */  mtc1      $at, $f6
/* CC540C 80241BFC 27A20034 */  addiu     $v0, $sp, 0x34
/* CC5410 80241C00 E7A00028 */  swc1      $f0, 0x28($sp)
/* CC5414 80241C04 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CC5418 80241C08 E7A40030 */  swc1      $f4, 0x30($sp)
/* CC541C 80241C0C E7A60034 */  swc1      $f6, 0x34($sp)
/* CC5420 80241C10 C6340070 */  lwc1      $f20, 0x70($s1)
/* CC5424 80241C14 4680A520 */  cvt.s.w   $f20, $f20
/* CC5428 80241C18 4600A521 */  cvt.d.s   $f20, $f20
/* CC542C 80241C1C 4628A503 */  div.d     $f20, $f20, $f8
/* CC5430 80241C20 AFA20010 */  sw        $v0, 0x10($sp)
/* CC5434 80241C24 8E040080 */  lw        $a0, 0x80($s0)
/* CC5438 80241C28 0C0372DF */  jal       func_800DCB7C
/* CC543C 80241C2C 4620A520 */   cvt.s.d  $f20, $f20
/* CC5440 80241C30 C62C0074 */  lwc1      $f12, 0x74($s1)
/* CC5444 80241C34 0C00A8BB */  jal       sin_deg
/* CC5448 80241C38 46806320 */   cvt.s.w  $f12, $f12
/* CC544C 80241C3C 46140002 */  mul.s     $f0, $f0, $f20
/* CC5450 80241C40 00000000 */  nop       
/* CC5454 80241C44 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* CC5458 80241C48 46161080 */  add.s     $f2, $f2, $f22
/* CC545C 80241C4C 46001080 */  add.s     $f2, $f2, $f0
/* CC5460 80241C50 E602003C */  swc1      $f2, 0x3c($s0)
/* CC5464 80241C54 8E220074 */  lw        $v0, 0x74($s1)
/* CC5468 80241C58 2442000C */  addiu     $v0, $v0, 0xc
/* CC546C 80241C5C 44826000 */  mtc1      $v0, $f12
/* CC5470 80241C60 00000000 */  nop       
/* CC5474 80241C64 0C00A6C9 */  jal       clamp_angle
/* CC5478 80241C68 46806320 */   cvt.s.w  $f12, $f12
/* CC547C 80241C6C 4600028D */  trunc.w.s $f10, $f0
/* CC5480 80241C70 E62A0074 */  swc1      $f10, 0x74($s1)
/* CC5484 80241C74 0280202D */  daddu     $a0, $s4, $zero
/* CC5488 80241C78 24020001 */  addiu     $v0, $zero, 1
/* CC548C 80241C7C AFA20010 */  sw        $v0, 0x10($sp)
/* CC5490 80241C80 8E660024 */  lw        $a2, 0x24($s3)
/* CC5494 80241C84 8E670028 */  lw        $a3, 0x28($s3)
/* CC5498 80241C88 0C01242D */  jal       func_800490B4
/* CC549C 80241C8C 0220282D */   daddu    $a1, $s1, $zero
/* CC54A0 80241C90 1040001D */  beqz      $v0, .L80241D08
/* CC54A4 80241C94 0000202D */   daddu    $a0, $zero, $zero
/* CC54A8 80241C98 0200282D */  daddu     $a1, $s0, $zero
/* CC54AC 80241C9C 0000302D */  daddu     $a2, $zero, $zero
/* CC54B0 80241CA0 860300A8 */  lh        $v1, 0xa8($s0)
/* CC54B4 80241CA4 3C013F80 */  lui       $at, 0x3f80
/* CC54B8 80241CA8 44810000 */  mtc1      $at, $f0
/* CC54BC 80241CAC 3C014000 */  lui       $at, 0x4000
/* CC54C0 80241CB0 44811000 */  mtc1      $at, $f2
/* CC54C4 80241CB4 3C01C1A0 */  lui       $at, 0xc1a0
/* CC54C8 80241CB8 44812000 */  mtc1      $at, $f4
/* CC54CC 80241CBC 2402000F */  addiu     $v0, $zero, 0xf
/* CC54D0 80241CC0 AFA2001C */  sw        $v0, 0x1c($sp)
/* CC54D4 80241CC4 44835000 */  mtc1      $v1, $f10
/* CC54D8 80241CC8 00000000 */  nop       
/* CC54DC 80241CCC 468052A0 */  cvt.s.w   $f10, $f10
/* CC54E0 80241CD0 44075000 */  mfc1      $a3, $f10
/* CC54E4 80241CD4 27A20038 */  addiu     $v0, $sp, 0x38
/* CC54E8 80241CD8 AFA20020 */  sw        $v0, 0x20($sp)
/* CC54EC 80241CDC E7A00010 */  swc1      $f0, 0x10($sp)
/* CC54F0 80241CE0 E7A20014 */  swc1      $f2, 0x14($sp)
/* CC54F4 80241CE4 0C01BFA4 */  jal       fx_emote
/* CC54F8 80241CE8 E7A40018 */   swc1     $f4, 0x18($sp)
/* CC54FC 80241CEC 0200202D */  daddu     $a0, $s0, $zero
/* CC5500 80241CF0 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CC5504 80241CF4 0C012530 */  jal       func_800494C0
/* CC5508 80241CF8 3C060020 */   lui      $a2, 0x20
/* CC550C 80241CFC 2402000C */  addiu     $v0, $zero, 0xc
/* CC5510 80241D00 08090764 */  j         .L80241D90
/* CC5514 80241D04 AE420070 */   sw       $v0, 0x70($s2)
.L80241D08:
/* CC5518 80241D08 8602008C */  lh        $v0, 0x8c($s0)
/* CC551C 80241D0C 14400020 */  bnez      $v0, .L80241D90
/* CC5520 80241D10 00000000 */   nop      
/* CC5524 80241D14 8602008E */  lh        $v0, 0x8e($s0)
/* CC5528 80241D18 1C40001D */  bgtz      $v0, .L80241D90
/* CC552C 80241D1C 00000000 */   nop      
/* CC5530 80241D20 8E420074 */  lw        $v0, 0x74($s2)
/* CC5534 80241D24 2442FFFF */  addiu     $v0, $v0, -1
/* CC5538 80241D28 18400018 */  blez      $v0, .L80241D8C
/* CC553C 80241D2C AE420074 */   sw       $v0, 0x74($s2)
/* CC5540 80241D30 C600000C */  lwc1      $f0, 0xc($s0)
/* CC5544 80241D34 3C014334 */  lui       $at, 0x4334
/* CC5548 80241D38 44816000 */  mtc1      $at, $f12
/* CC554C 80241D3C 0C00A6C9 */  jal       clamp_angle
/* CC5550 80241D40 460C0300 */   add.s    $f12, $f0, $f12
/* CC5554 80241D44 240403E8 */  addiu     $a0, $zero, 0x3e8
/* CC5558 80241D48 0C00A67F */  jal       rand_int
/* CC555C 80241D4C E600000C */   swc1     $f0, 0xc($s0)
/* CC5560 80241D50 3C032E8B */  lui       $v1, 0x2e8b
/* CC5564 80241D54 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* CC5568 80241D58 00430018 */  mult      $v0, $v1
/* CC556C 80241D5C 00021FC3 */  sra       $v1, $v0, 0x1f
/* CC5570 80241D60 00004010 */  mfhi      $t0
/* CC5574 80241D64 00082043 */  sra       $a0, $t0, 1
/* CC5578 80241D68 00832023 */  subu      $a0, $a0, $v1
/* CC557C 80241D6C 00041840 */  sll       $v1, $a0, 1
/* CC5580 80241D70 00641821 */  addu      $v1, $v1, $a0
/* CC5584 80241D74 00031880 */  sll       $v1, $v1, 2
/* CC5588 80241D78 00641823 */  subu      $v1, $v1, $a0
/* CC558C 80241D7C 00431023 */  subu      $v0, $v0, $v1
/* CC5590 80241D80 24420005 */  addiu     $v0, $v0, 5
/* CC5594 80241D84 08090764 */  j         .L80241D90
/* CC5598 80241D88 A602008E */   sh       $v0, 0x8e($s0)
.L80241D8C:
/* CC559C 80241D8C AE400070 */  sw        $zero, 0x70($s2)
.L80241D90:
/* CC55A0 80241D90 8FBF0054 */  lw        $ra, 0x54($sp)
/* CC55A4 80241D94 8FB40050 */  lw        $s4, 0x50($sp)
/* CC55A8 80241D98 8FB3004C */  lw        $s3, 0x4c($sp)
/* CC55AC 80241D9C 8FB20048 */  lw        $s2, 0x48($sp)
/* CC55B0 80241DA0 8FB10044 */  lw        $s1, 0x44($sp)
/* CC55B4 80241DA4 8FB00040 */  lw        $s0, 0x40($sp)
/* CC55B8 80241DA8 D7B60060 */  ldc1      $f22, 0x60($sp)
/* CC55BC 80241DAC D7B40058 */  ldc1      $f20, 0x58($sp)
/* CC55C0 80241DB0 03E00008 */  jr        $ra
/* CC55C4 80241DB4 27BD0068 */   addiu    $sp, $sp, 0x68
