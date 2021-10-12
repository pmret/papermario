.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_69_update
/* 38CB2C E008A53C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 38CB30 E008A540 0080282D */  daddu     $a1, $a0, $zero
/* 38CB34 E008A544 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 38CB38 E008A548 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 38CB3C E008A54C 3C04800B */  lui       $a0, %hi(gCameras)
/* 38CB40 E008A550 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 38CB44 E008A554 AFBF002C */  sw        $ra, 0x2c($sp)
/* 38CB48 E008A558 AFB60028 */  sw        $s6, 0x28($sp)
/* 38CB4C E008A55C AFB50024 */  sw        $s5, 0x24($sp)
/* 38CB50 E008A560 AFB40020 */  sw        $s4, 0x20($sp)
/* 38CB54 E008A564 AFB3001C */  sw        $s3, 0x1c($sp)
/* 38CB58 E008A568 AFB20018 */  sw        $s2, 0x18($sp)
/* 38CB5C E008A56C AFB10014 */  sw        $s1, 0x14($sp)
/* 38CB60 E008A570 AFB00010 */  sw        $s0, 0x10($sp)
/* 38CB64 E008A574 8CB1000C */  lw        $s1, 0xc($a1)
/* 38CB68 E008A578 00031080 */  sll       $v0, $v1, 2
/* 38CB6C E008A57C 00431021 */  addu      $v0, $v0, $v1
/* 38CB70 E008A580 00021080 */  sll       $v0, $v0, 2
/* 38CB74 E008A584 00431023 */  subu      $v0, $v0, $v1
/* 38CB78 E008A588 000218C0 */  sll       $v1, $v0, 3
/* 38CB7C E008A58C 00431021 */  addu      $v0, $v0, $v1
/* 38CB80 E008A590 000210C0 */  sll       $v0, $v0, 3
/* 38CB84 E008A594 8E230020 */  lw        $v1, 0x20($s1)
/* 38CB88 E008A598 00442021 */  addu      $a0, $v0, $a0
/* 38CB8C E008A59C 28620064 */  slti      $v0, $v1, 0x64
/* 38CB90 E008A5A0 10400002 */  beqz      $v0, .LE008A5AC
/* 38CB94 E008A5A4 2462FFFF */   addiu    $v0, $v1, -1
/* 38CB98 E008A5A8 AE220020 */  sw        $v0, 0x20($s1)
.LE008A5AC:
/* 38CB9C E008A5AC 8E220020 */  lw        $v0, 0x20($s1)
/* 38CBA0 E008A5B0 04410005 */  bgez      $v0, .LE008A5C8
/* 38CBA4 E008A5B4 00000000 */   nop
/* 38CBA8 E008A5B8 0C080128 */  jal       shim_remove_effect
/* 38CBAC E008A5BC 00A0202D */   daddu    $a0, $a1, $zero
/* 38CBB0 E008A5C0 080229AF */  j         .LE008A6BC
/* 38CBB4 E008A5C4 00000000 */   nop
.LE008A5C8:
/* 38CBB8 E008A5C8 8E220024 */  lw        $v0, 0x24($s1)
/* 38CBBC E008A5CC 8E330020 */  lw        $s3, 0x20($s1)
/* 38CBC0 E008A5D0 8E35002C */  lw        $s5, 0x2c($s1)
/* 38CBC4 E008A5D4 24420001 */  addiu     $v0, $v0, 1
/* 38CBC8 E008A5D8 AE220024 */  sw        $v0, 0x24($s1)
/* 38CBCC E008A5DC 2A62000A */  slti      $v0, $s3, 0xa
/* 38CBD0 E008A5E0 10400005 */  beqz      $v0, .LE008A5F8
/* 38CBD4 E008A5E4 00131040 */   sll      $v0, $s3, 1
/* 38CBD8 E008A5E8 00531021 */  addu      $v0, $v0, $s3
/* 38CBDC E008A5EC 000210C0 */  sll       $v0, $v0, 3
/* 38CBE0 E008A5F0 00531021 */  addu      $v0, $v0, $s3
/* 38CBE4 E008A5F4 AE220028 */  sw        $v0, 0x28($s1)
.LE008A5F8:
/* 38CBE8 E008A5F8 C4800078 */  lwc1      $f0, 0x78($a0)
/* 38CBEC E008A5FC 3C01E009 */  lui       $at, %hi(D_E008AA78)
/* 38CBF0 E008A600 D422AA78 */  ldc1      $f2, %lo(D_E008AA78)($at)
/* 38CBF4 E008A604 4600020D */  trunc.w.s $f8, $f0
/* 38CBF8 E008A608 44144000 */  mfc1      $s4, $f8
/* 38CBFC E008A60C 00000000 */  nop
/* 38CC00 E008A610 44940000 */  mtc1      $s4, $f0
/* 38CC04 E008A614 00000000 */  nop
/* 38CC08 E008A618 46800021 */  cvt.d.w   $f0, $f0
/* 38CC0C E008A61C 46220002 */  mul.d     $f0, $f0, $f2
/* 38CC10 E008A620 00000000 */  nop
/* 38CC14 E008A624 3C013FF0 */  lui       $at, 0x3ff0
/* 38CC18 E008A628 44811800 */  mtc1      $at, $f3
/* 38CC1C E008A62C 44801000 */  mtc1      $zero, $f2
/* 38CC20 E008A630 00000000 */  nop
/* 38CC24 E008A634 46220000 */  add.d     $f0, $f0, $f2
/* 38CC28 E008A638 26310034 */  addiu     $s1, $s1, 0x34
/* 38CC2C E008A63C 4620020D */  trunc.w.d $f8, $f0
/* 38CC30 E008A640 44164000 */  mfc1      $s6, $f8
/* 38CC34 E008A644 1AA0001D */  blez      $s5, .LE008A6BC
/* 38CC38 E008A648 0000902D */   daddu    $s2, $zero, $zero
/* 38CC3C E008A64C 26300010 */  addiu     $s0, $s1, 0x10
.LE008A650:
/* 38CC40 E008A650 8E020020 */  lw        $v0, 0x20($s0)
/* 38CC44 E008A654 18400003 */  blez      $v0, .LE008A664
/* 38CC48 E008A658 2442FFFF */   addiu    $v0, $v0, -1
/* 38CC4C E008A65C 1C400012 */  bgtz      $v0, .LE008A6A8
/* 38CC50 E008A660 AE020020 */   sw       $v0, 0x20($s0)
.LE008A664:
/* 38CC54 E008A664 0220202D */  daddu     $a0, $s1, $zero
/* 38CC58 E008A668 0280282D */  daddu     $a1, $s4, $zero
/* 38CC5C E008A66C 02C0302D */  daddu     $a2, $s6, $zero
/* 38CC60 E008A670 C606FFF8 */  lwc1      $f6, -8($s0)
/* 38CC64 E008A674 C6000004 */  lwc1      $f0, 4($s0)
/* 38CC68 E008A678 C604FFFC */  lwc1      $f4, -4($s0)
/* 38CC6C E008A67C 46003180 */  add.s     $f6, $f6, $f0
/* 38CC70 E008A680 C6000008 */  lwc1      $f0, 8($s0)
/* 38CC74 E008A684 C602000C */  lwc1      $f2, 0xc($s0)
/* 38CC78 E008A688 46002100 */  add.s     $f4, $f4, $f0
/* 38CC7C E008A68C C6000000 */  lwc1      $f0, ($s0)
/* 38CC80 E008A690 0260382D */  daddu     $a3, $s3, $zero
/* 38CC84 E008A694 46020000 */  add.s     $f0, $f0, $f2
/* 38CC88 E008A698 E606FFF8 */  swc1      $f6, -8($s0)
/* 38CC8C E008A69C E604FFFC */  swc1      $f4, -4($s0)
/* 38CC90 E008A6A0 0C0228A4 */  jal       func_E008A290
/* 38CC94 E008A6A4 E6000000 */   swc1     $f0, ($s0)
.LE008A6A8:
/* 38CC98 E008A6A8 26520001 */  addiu     $s2, $s2, 1
/* 38CC9C E008A6AC 26100034 */  addiu     $s0, $s0, 0x34
/* 38CCA0 E008A6B0 0255102A */  slt       $v0, $s2, $s5
/* 38CCA4 E008A6B4 1440FFE6 */  bnez      $v0, .LE008A650
/* 38CCA8 E008A6B8 26310034 */   addiu    $s1, $s1, 0x34
.LE008A6BC:
/* 38CCAC E008A6BC 8FBF002C */  lw        $ra, 0x2c($sp)
/* 38CCB0 E008A6C0 8FB60028 */  lw        $s6, 0x28($sp)
/* 38CCB4 E008A6C4 8FB50024 */  lw        $s5, 0x24($sp)
/* 38CCB8 E008A6C8 8FB40020 */  lw        $s4, 0x20($sp)
/* 38CCBC E008A6CC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 38CCC0 E008A6D0 8FB20018 */  lw        $s2, 0x18($sp)
/* 38CCC4 E008A6D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 38CCC8 E008A6D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 38CCCC E008A6DC 03E00008 */  jr        $ra
/* 38CCD0 E008A6E0 27BD0030 */   addiu    $sp, $sp, 0x30
