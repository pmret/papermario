.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414E4_A3A9C4
/* A3A9C4 802414E4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A3A9C8 802414E8 AFBE0030 */  sw        $fp, 0x30($sp)
/* A3A9CC 802414EC 0080F02D */  daddu     $fp, $a0, $zero
/* A3A9D0 802414F0 0000202D */  daddu     $a0, $zero, $zero
/* A3A9D4 802414F4 3C05F5DE */  lui       $a1, 0xf5de
/* A3A9D8 802414F8 34A50180 */  ori       $a1, $a1, 0x180
/* A3A9DC 802414FC AFBF0034 */  sw        $ra, 0x34($sp)
/* A3A9E0 80241500 AFB7002C */  sw        $s7, 0x2c($sp)
/* A3A9E4 80241504 AFB60028 */  sw        $s6, 0x28($sp)
/* A3A9E8 80241508 AFB50024 */  sw        $s5, 0x24($sp)
/* A3A9EC 8024150C AFB40020 */  sw        $s4, 0x20($sp)
/* A3A9F0 80241510 AFB3001C */  sw        $s3, 0x1c($sp)
/* A3A9F4 80241514 AFB20018 */  sw        $s2, 0x18($sp)
/* A3A9F8 80241518 AFB10014 */  sw        $s1, 0x14($sp)
/* A3A9FC 8024151C 0C0B1EAF */  jal       get_variable
/* A3AA00 80241520 AFB00010 */   sw       $s0, 0x10($sp)
/* A3AA04 80241524 0040A82D */  daddu     $s5, $v0, $zero
/* A3AA08 80241528 0000A02D */  daddu     $s4, $zero, $zero
/* A3AA0C 8024152C 0280802D */  daddu     $s0, $s4, $zero
/* A3AA10 80241530 3C12F971 */  lui       $s2, 0xf971
/* A3AA14 80241534 365288E4 */  ori       $s2, $s2, 0x88e4
/* A3AA18 80241538 3C118024 */  lui       $s1, 0x8024
/* A3AA1C 8024153C 26314B8C */  addiu     $s1, $s1, 0x4b8c
/* A3AA20 80241540 AFC00088 */  sw        $zero, 0x88($fp)
.L80241544:
/* A3AA24 80241544 8E220004 */  lw        $v0, 4($s1)
/* A3AA28 80241548 02A2102A */  slt       $v0, $s5, $v0
/* A3AA2C 8024154C 5440000C */  bnel      $v0, $zero, .L80241580
/* A3AA30 80241550 26100001 */   addiu    $s0, $s0, 1
/* A3AA34 80241554 8E250000 */  lw        $a1, ($s1)
/* A3AA38 80241558 0C0B1EAF */  jal       get_variable
/* A3AA3C 8024155C 0000202D */   daddu    $a0, $zero, $zero
/* A3AA40 80241560 54400007 */  bnel      $v0, $zero, .L80241580
/* A3AA44 80241564 26100001 */   addiu    $s0, $s0, 1
/* A3AA48 80241568 0000202D */  daddu     $a0, $zero, $zero
/* A3AA4C 8024156C 0C0B1EAF */  jal       get_variable
/* A3AA50 80241570 02122821 */   addu     $a1, $s0, $s2
/* A3AA54 80241574 50400001 */  beql      $v0, $zero, .L8024157C
/* A3AA58 80241578 26940001 */   addiu    $s4, $s4, 1
.L8024157C:
/* A3AA5C 8024157C 26100001 */  addiu     $s0, $s0, 1
.L80241580:
/* A3AA60 80241580 2E020010 */  sltiu     $v0, $s0, 0x10
/* A3AA64 80241584 1440FFEF */  bnez      $v0, .L80241544
/* A3AA68 80241588 2631000C */   addiu    $s1, $s1, 0xc
/* A3AA6C 8024158C 12800029 */  beqz      $s4, .L80241634
/* A3AA70 80241590 00000000 */   nop      
/* A3AA74 80241594 0C00A67F */  jal       rand_int
/* A3AA78 80241598 2684FFFF */   addiu    $a0, $s4, -1
/* A3AA7C 8024159C 0040B82D */  daddu     $s7, $v0, $zero
/* A3AA80 802415A0 3C138024 */  lui       $s3, 0x8024
/* A3AA84 802415A4 26734B88 */  addiu     $s3, $s3, 0x4b88
/* A3AA88 802415A8 0000A02D */  daddu     $s4, $zero, $zero
/* A3AA8C 802415AC 0280802D */  daddu     $s0, $s4, $zero
/* A3AA90 802415B0 3C16F971 */  lui       $s6, 0xf971
/* A3AA94 802415B4 36D688E4 */  ori       $s6, $s6, 0x88e4
/* A3AA98 802415B8 26720004 */  addiu     $s2, $s3, 4
.L802415BC:
/* A3AA9C 802415BC 8E420004 */  lw        $v0, 4($s2)
/* A3AAA0 802415C0 02A2102A */  slt       $v0, $s5, $v0
/* A3AAA4 802415C4 54400017 */  bnel      $v0, $zero, .L80241624
/* A3AAA8 802415C8 26100001 */   addiu    $s0, $s0, 1
/* A3AAAC 802415CC 8E450000 */  lw        $a1, ($s2)
/* A3AAB0 802415D0 0C0B1EAF */  jal       get_variable
/* A3AAB4 802415D4 0000202D */   daddu    $a0, $zero, $zero
/* A3AAB8 802415D8 54400012 */  bnel      $v0, $zero, .L80241624
/* A3AABC 802415DC 26100001 */   addiu    $s0, $s0, 1
/* A3AAC0 802415E0 0000202D */  daddu     $a0, $zero, $zero
/* A3AAC4 802415E4 02168821 */  addu      $s1, $s0, $s6
/* A3AAC8 802415E8 0C0B1EAF */  jal       get_variable
/* A3AACC 802415EC 0220282D */   daddu    $a1, $s1, $zero
/* A3AAD0 802415F0 5440000C */  bnel      $v0, $zero, .L80241624
/* A3AAD4 802415F4 26100001 */   addiu    $s0, $s0, 1
/* A3AAD8 802415F8 16970009 */  bne       $s4, $s7, .L80241620
/* A3AADC 802415FC 26940001 */   addiu    $s4, $s4, 1
/* A3AAE0 80241600 0000202D */  daddu     $a0, $zero, $zero
/* A3AAE4 80241604 0220282D */  daddu     $a1, $s1, $zero
/* A3AAE8 80241608 8E620000 */  lw        $v0, ($s3)
/* A3AAEC 8024160C 24060001 */  addiu     $a2, $zero, 1
/* A3AAF0 80241610 0C0B2026 */  jal       set_variable
/* A3AAF4 80241614 AFC20088 */   sw       $v0, 0x88($fp)
/* A3AAF8 80241618 0809058D */  j         .L80241634
/* A3AAFC 8024161C 00000000 */   nop      
.L80241620:
/* A3AB00 80241620 26100001 */  addiu     $s0, $s0, 1
.L80241624:
/* A3AB04 80241624 2652000C */  addiu     $s2, $s2, 0xc
/* A3AB08 80241628 2E020010 */  sltiu     $v0, $s0, 0x10
/* A3AB0C 8024162C 1440FFE3 */  bnez      $v0, .L802415BC
/* A3AB10 80241630 2673000C */   addiu    $s3, $s3, 0xc
.L80241634:
/* A3AB14 80241634 8FBF0034 */  lw        $ra, 0x34($sp)
/* A3AB18 80241638 8FBE0030 */  lw        $fp, 0x30($sp)
/* A3AB1C 8024163C 8FB7002C */  lw        $s7, 0x2c($sp)
/* A3AB20 80241640 8FB60028 */  lw        $s6, 0x28($sp)
/* A3AB24 80241644 8FB50024 */  lw        $s5, 0x24($sp)
/* A3AB28 80241648 8FB40020 */  lw        $s4, 0x20($sp)
/* A3AB2C 8024164C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A3AB30 80241650 8FB20018 */  lw        $s2, 0x18($sp)
/* A3AB34 80241654 8FB10014 */  lw        $s1, 0x14($sp)
/* A3AB38 80241658 8FB00010 */  lw        $s0, 0x10($sp)
/* A3AB3C 8024165C 24020002 */  addiu     $v0, $zero, 2
/* A3AB40 80241660 03E00008 */  jr        $ra
/* A3AB44 80241664 27BD0038 */   addiu    $sp, $sp, 0x38
