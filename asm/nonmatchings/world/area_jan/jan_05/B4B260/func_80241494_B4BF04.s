.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241494_B4BF04
/* B4BF04 80241494 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B4BF08 80241498 AFB3003C */  sw        $s3, 0x3c($sp)
/* B4BF0C 8024149C 0080982D */  daddu     $s3, $a0, $zero
/* B4BF10 802414A0 AFBF0048 */  sw        $ra, 0x48($sp)
/* B4BF14 802414A4 AFB50044 */  sw        $s5, 0x44($sp)
/* B4BF18 802414A8 AFB40040 */  sw        $s4, 0x40($sp)
/* B4BF1C 802414AC AFB20038 */  sw        $s2, 0x38($sp)
/* B4BF20 802414B0 AFB10034 */  sw        $s1, 0x34($sp)
/* B4BF24 802414B4 AFB00030 */  sw        $s0, 0x30($sp)
/* B4BF28 802414B8 8E720148 */  lw        $s2, 0x148($s3)
/* B4BF2C 802414BC 86440008 */  lh        $a0, 8($s2)
/* B4BF30 802414C0 8E70000C */  lw        $s0, 0xc($s3)
/* B4BF34 802414C4 0C00EABB */  jal       get_npc_unsafe
/* B4BF38 802414C8 00A0882D */   daddu    $s1, $a1, $zero
/* B4BF3C 802414CC 8E050000 */  lw        $a1, ($s0)
/* B4BF40 802414D0 26100004 */  addiu     $s0, $s0, 4
/* B4BF44 802414D4 0260202D */  daddu     $a0, $s3, $zero
/* B4BF48 802414D8 0C0B1EAF */  jal       get_variable
/* B4BF4C 802414DC 0040A82D */   daddu    $s5, $v0, $zero
/* B4BF50 802414E0 0260202D */  daddu     $a0, $s3, $zero
/* B4BF54 802414E4 8E050000 */  lw        $a1, ($s0)
/* B4BF58 802414E8 0C0B1EAF */  jal       get_variable
/* B4BF5C 802414EC 0040A02D */   daddu    $s4, $v0, $zero
/* B4BF60 802414F0 AE420094 */  sw        $v0, 0x94($s2)
/* B4BF64 802414F4 AFA00010 */  sw        $zero, 0x10($sp)
/* B4BF68 802414F8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B4BF6C 802414FC 8C420030 */  lw        $v0, 0x30($v0)
/* B4BF70 80241500 AFA20014 */  sw        $v0, 0x14($sp)
/* B4BF74 80241504 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B4BF78 80241508 8C42001C */  lw        $v0, 0x1c($v0)
/* B4BF7C 8024150C AFA20018 */  sw        $v0, 0x18($sp)
/* B4BF80 80241510 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B4BF84 80241514 8C420024 */  lw        $v0, 0x24($v0)
/* B4BF88 80241518 AFA2001C */  sw        $v0, 0x1c($sp)
/* B4BF8C 8024151C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B4BF90 80241520 8C420028 */  lw        $v0, 0x28($v0)
/* B4BF94 80241524 AFA20020 */  sw        $v0, 0x20($sp)
/* B4BF98 80241528 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B4BF9C 8024152C 3C0142C8 */  lui       $at, 0x42c8
/* B4BFA0 80241530 44810000 */  mtc1      $at, $f0
/* B4BFA4 80241534 8C42002C */  lw        $v0, 0x2c($v0)
/* B4BFA8 80241538 27B00010 */  addiu     $s0, $sp, 0x10
/* B4BFAC 8024153C E7A00028 */  swc1      $f0, 0x28($sp)
/* B4BFB0 80241540 A7A0002C */  sh        $zero, 0x2c($sp)
/* B4BFB4 80241544 12200019 */  beqz      $s1, .L802415AC
/* B4BFB8 80241548 AFA20024 */   sw       $v0, 0x24($sp)
/* B4BFBC 8024154C AE600070 */  sw        $zero, 0x70($s3)
/* B4BFC0 80241550 A6A0008E */  sh        $zero, 0x8e($s5)
/* B4BFC4 80241554 AE600074 */  sw        $zero, 0x74($s3)
/* B4BFC8 80241558 8EA20000 */  lw        $v0, ($s5)
/* B4BFCC 8024155C 2403F7FF */  addiu     $v1, $zero, -0x801
/* B4BFD0 80241560 00431024 */  and       $v0, $v0, $v1
/* B4BFD4 80241564 2403FDFF */  addiu     $v1, $zero, -0x201
/* B4BFD8 80241568 00431024 */  and       $v0, $v0, $v1
/* B4BFDC 8024156C 34420008 */  ori       $v0, $v0, 8
/* B4BFE0 80241570 AEA20000 */  sw        $v0, ($s5)
/* B4BFE4 80241574 8E4200B0 */  lw        $v0, 0xb0($s2)
/* B4BFE8 80241578 34420018 */  ori       $v0, $v0, 0x18
/* B4BFEC 8024157C AE4200B0 */  sw        $v0, 0xb0($s2)
/* B4BFF0 80241580 8E420000 */  lw        $v0, ($s2)
/* B4BFF4 80241584 3C034000 */  lui       $v1, 0x4000
/* B4BFF8 80241588 00431024 */  and       $v0, $v0, $v1
/* B4BFFC 8024158C 10400007 */  beqz      $v0, .L802415AC
/* B4C000 80241590 3C03BFFF */   lui      $v1, 0xbfff
/* B4C004 80241594 2402000C */  addiu     $v0, $zero, 0xc
/* B4C008 80241598 AE620070 */  sw        $v0, 0x70($s3)
/* B4C00C 8024159C 8E420000 */  lw        $v0, ($s2)
/* B4C010 802415A0 3463FFFF */  ori       $v1, $v1, 0xffff
/* B4C014 802415A4 00431024 */  and       $v0, $v0, $v1
/* B4C018 802415A8 AE420000 */  sw        $v0, ($s2)
.L802415AC:
/* B4C01C 802415AC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* B4C020 802415B0 30620004 */  andi      $v0, $v1, 4
/* B4C024 802415B4 10400007 */  beqz      $v0, .L802415D4
/* B4C028 802415B8 00000000 */   nop      
/* B4C02C 802415BC 824200B4 */  lb        $v0, 0xb4($s2)
/* B4C030 802415C0 14400034 */  bnez      $v0, .L80241694
/* B4C034 802415C4 0000102D */   daddu    $v0, $zero, $zero
/* B4C038 802415C8 2402FFFB */  addiu     $v0, $zero, -5
/* B4C03C 802415CC 00621024 */  and       $v0, $v1, $v0
/* B4C040 802415D0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802415D4:
/* B4C044 802415D4 8E630070 */  lw        $v1, 0x70($s3)
/* B4C048 802415D8 2C62000F */  sltiu     $v0, $v1, 0xf
/* B4C04C 802415DC 1040002C */  beqz      $v0, .L80241690
/* B4C050 802415E0 00031080 */   sll      $v0, $v1, 2
/* B4C054 802415E4 3C018024 */  lui       $at, %hi(D_80247A38)
/* B4C058 802415E8 00220821 */  addu      $at, $at, $v0
/* B4C05C 802415EC 8C227A38 */  lw        $v0, %lo(D_80247A38)($at)
/* B4C060 802415F0 00400008 */  jr        $v0
/* B4C064 802415F4 00000000 */   nop      
/* B4C068 802415F8 0260202D */  daddu     $a0, $s3, $zero
/* B4C06C 802415FC 0280282D */  daddu     $a1, $s4, $zero
/* B4C070 80241600 0C090229 */  jal       func_802408A4_B4B314
/* B4C074 80241604 0200302D */   daddu    $a2, $s0, $zero
/* B4C078 80241608 0260202D */  daddu     $a0, $s3, $zero
/* B4C07C 8024160C 0280282D */  daddu     $a1, $s4, $zero
/* B4C080 80241610 0C0902B5 */  jal       func_80240AD4_B4B544
/* B4C084 80241614 0200302D */   daddu    $a2, $s0, $zero
/* B4C088 80241618 080905A5 */  j         .L80241694
/* B4C08C 8024161C 0000102D */   daddu    $v0, $zero, $zero
/* B4C090 80241620 0260202D */  daddu     $a0, $s3, $zero
/* B4C094 80241624 0280282D */  daddu     $a1, $s4, $zero
/* B4C098 80241628 0C090383 */  jal       func_80240E0C_B4B87C
/* B4C09C 8024162C 0200302D */   daddu    $a2, $s0, $zero
/* B4C0A0 80241630 8E630070 */  lw        $v1, 0x70($s3)
/* B4C0A4 80241634 24020003 */  addiu     $v0, $zero, 3
/* B4C0A8 80241638 14620016 */  bne       $v1, $v0, .L80241694
/* B4C0AC 8024163C 0000102D */   daddu    $v0, $zero, $zero
/* B4C0B0 80241640 0260202D */  daddu     $a0, $s3, $zero
/* B4C0B4 80241644 0280282D */  daddu     $a1, $s4, $zero
/* B4C0B8 80241648 0C0903B3 */  jal       func_80240ECC_B4B93C
/* B4C0BC 8024164C 0200302D */   daddu    $a2, $s0, $zero
/* B4C0C0 80241650 080905A5 */  j         .L80241694
/* B4C0C4 80241654 0000102D */   daddu    $v0, $zero, $zero
/* B4C0C8 80241658 0260202D */  daddu     $a0, $s3, $zero
/* B4C0CC 8024165C 0280282D */  daddu     $a1, $s4, $zero
/* B4C0D0 80241660 0C09041C */  jal       func_80241070_B4BAE0
/* B4C0D4 80241664 0200302D */   daddu    $a2, $s0, $zero
/* B4C0D8 80241668 0260202D */  daddu     $a0, $s3, $zero
/* B4C0DC 8024166C 0280282D */  daddu     $a1, $s4, $zero
/* B4C0E0 80241670 0C090454 */  jal       func_80241150_B4BBC0
/* B4C0E4 80241674 0200302D */   daddu    $a2, $s0, $zero
/* B4C0E8 80241678 080905A5 */  j         .L80241694
/* B4C0EC 8024167C 0000102D */   daddu    $v0, $zero, $zero
/* B4C0F0 80241680 0260202D */  daddu     $a0, $s3, $zero
/* B4C0F4 80241684 0280282D */  daddu     $a1, $s4, $zero
/* B4C0F8 80241688 0C090514 */  jal       func_80241450_B4BEC0
/* B4C0FC 8024168C 0200302D */   daddu    $a2, $s0, $zero
.L80241690:
/* B4C100 80241690 0000102D */  daddu     $v0, $zero, $zero
.L80241694:
/* B4C104 80241694 8FBF0048 */  lw        $ra, 0x48($sp)
/* B4C108 80241698 8FB50044 */  lw        $s5, 0x44($sp)
/* B4C10C 8024169C 8FB40040 */  lw        $s4, 0x40($sp)
/* B4C110 802416A0 8FB3003C */  lw        $s3, 0x3c($sp)
/* B4C114 802416A4 8FB20038 */  lw        $s2, 0x38($sp)
/* B4C118 802416A8 8FB10034 */  lw        $s1, 0x34($sp)
/* B4C11C 802416AC 8FB00030 */  lw        $s0, 0x30($sp)
/* B4C120 802416B0 03E00008 */  jr        $ra
/* B4C124 802416B4 27BD0050 */   addiu    $sp, $sp, 0x50
