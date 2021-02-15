.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF640
/* 88AF0 800EF640 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 88AF4 800EF644 AFB1004C */  sw        $s1, 0x4c($sp)
/* 88AF8 800EF648 0080882D */  daddu     $s1, $a0, $zero
/* 88AFC 800EF64C AFB30054 */  sw        $s3, 0x54($sp)
/* 88B00 800EF650 3C13800B */  lui       $s3, %hi(D_800B1E54)
/* 88B04 800EF654 26731E54 */  addiu     $s3, $s3, %lo(D_800B1E54)
/* 88B08 800EF658 0260202D */  daddu     $a0, $s3, $zero
/* 88B0C 800EF65C AFB20050 */  sw        $s2, 0x50($sp)
/* 88B10 800EF660 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 88B14 800EF664 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 88B18 800EF668 AFBF005C */  sw        $ra, 0x5c($sp)
/* 88B1C 800EF66C AFB40058 */  sw        $s4, 0x58($sp)
/* 88B20 800EF670 AFB00048 */  sw        $s0, 0x48($sp)
/* 88B24 800EF674 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 88B28 800EF678 8E450028 */  lw        $a1, 0x28($s2)
/* 88B2C 800EF67C 8E46002C */  lw        $a2, 0x2c($s2)
/* 88B30 800EF680 8E470030 */  lw        $a3, 0x30($s2)
/* 88B34 800EF684 27A20028 */  addiu     $v0, $sp, 0x28
/* 88B38 800EF688 AFA20014 */  sw        $v0, 0x14($sp)
/* 88B3C 800EF68C 27A2002C */  addiu     $v0, $sp, 0x2c
/* 88B40 800EF690 AFA20018 */  sw        $v0, 0x18($sp)
/* 88B44 800EF694 27A20030 */  addiu     $v0, $sp, 0x30
/* 88B48 800EF698 3C013F80 */  lui       $at, 0x3f80
/* 88B4C 800EF69C 4481A000 */  mtc1      $at, $f20
/* 88B50 800EF6A0 27B00034 */  addiu     $s0, $sp, 0x34
/* 88B54 800EF6A4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 88B58 800EF6A8 AFB00020 */  sw        $s0, 0x20($sp)
/* 88B5C 800EF6AC 0C00A588 */  jal       transform_point
/* 88B60 800EF6B0 E7B40010 */   swc1     $f20, 0x10($sp)
/* 88B64 800EF6B4 0260202D */  daddu     $a0, $s3, $zero
/* 88B68 800EF6B8 27A20038 */  addiu     $v0, $sp, 0x38
/* 88B6C 800EF6BC AFA20014 */  sw        $v0, 0x14($sp)
/* 88B70 800EF6C0 27A2003C */  addiu     $v0, $sp, 0x3c
/* 88B74 800EF6C4 AFA20018 */  sw        $v0, 0x18($sp)
/* 88B78 800EF6C8 27A20040 */  addiu     $v0, $sp, 0x40
/* 88B7C 800EF6CC AFB00020 */  sw        $s0, 0x20($sp)
/* 88B80 800EF6D0 26300038 */  addiu     $s0, $s1, 0x38
/* 88B84 800EF6D4 E7B40010 */  swc1      $f20, 0x10($sp)
/* 88B88 800EF6D8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 88B8C 800EF6DC 8E250038 */  lw        $a1, 0x38($s1)
/* 88B90 800EF6E0 8E26003C */  lw        $a2, 0x3c($s1)
/* 88B94 800EF6E4 8E270040 */  lw        $a3, 0x40($s1)
/* 88B98 800EF6E8 0C00A588 */  jal       transform_point
/* 88B9C 800EF6EC 26340040 */   addiu    $s4, $s1, 0x40
/* 88BA0 800EF6F0 862200A6 */  lh        $v0, 0xa6($s1)
/* 88BA4 800EF6F4 864300B2 */  lh        $v1, 0xb2($s2)
/* 88BA8 800EF6F8 3C013F66 */  lui       $at, 0x3f66
/* 88BAC 800EF6FC 34216666 */  ori       $at, $at, 0x6666
/* 88BB0 800EF700 44810000 */  mtc1      $at, $f0
/* 88BB4 800EF704 00431021 */  addu      $v0, $v0, $v1
/* 88BB8 800EF708 44824000 */  mtc1      $v0, $f8
/* 88BBC 800EF70C 00000000 */  nop
/* 88BC0 800EF710 46804220 */  cvt.s.w   $f8, $f8
/* 88BC4 800EF714 46004202 */  mul.s     $f8, $f8, $f0
/* 88BC8 800EF718 00000000 */  nop
/* 88BCC 800EF71C C7A60028 */  lwc1      $f6, 0x28($sp)
/* 88BD0 800EF720 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 88BD4 800EF724 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* 88BD8 800EF728 46003181 */  sub.s     $f6, $f6, $f0
/* 88BDC 800EF72C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 88BE0 800EF730 C7A20030 */  lwc1      $f2, 0x30($sp)
/* 88BE4 800EF734 46002101 */  sub.s     $f4, $f4, $f0
/* 88BE8 800EF738 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 88BEC 800EF73C 46001081 */  sub.s     $f2, $f2, $f0
/* 88BF0 800EF740 46003185 */  abs.s     $f6, $f6
/* 88BF4 800EF744 E7A60028 */  swc1      $f6, 0x28($sp)
/* 88BF8 800EF748 46002105 */  abs.s     $f4, $f4
/* 88BFC 800EF74C 4608303E */  c.le.s    $f6, $f8
/* 88C00 800EF750 E7A4002C */  swc1      $f4, 0x2c($sp)
/* 88C04 800EF754 46001285 */  abs.s     $f10, $f2
/* 88C08 800EF758 4500002B */  bc1f      .L800EF808
/* 88C0C 800EF75C E7AA0030 */   swc1     $f10, 0x30($sp)
/* 88C10 800EF760 862200A8 */  lh        $v0, 0xa8($s1)
/* 88C14 800EF764 864300B0 */  lh        $v1, 0xb0($s2)
/* 88C18 800EF768 00431021 */  addu      $v0, $v0, $v1
/* 88C1C 800EF76C 44820000 */  mtc1      $v0, $f0
/* 88C20 800EF770 00000000 */  nop
/* 88C24 800EF774 46800020 */  cvt.s.w   $f0, $f0
/* 88C28 800EF778 4600203E */  c.le.s    $f4, $f0
/* 88C2C 800EF77C 00000000 */  nop
/* 88C30 800EF780 45000021 */  bc1f      .L800EF808
/* 88C34 800EF784 00000000 */   nop
/* 88C38 800EF788 3C014010 */  lui       $at, 0x4010
/* 88C3C 800EF78C 44811800 */  mtc1      $at, $f3
/* 88C40 800EF790 44801000 */  mtc1      $zero, $f2
/* 88C44 800EF794 46005021 */  cvt.d.s   $f0, $f10
/* 88C48 800EF798 4622003E */  c.le.d    $f0, $f2
/* 88C4C 800EF79C 00000000 */  nop
/* 88C50 800EF7A0 45000019 */  bc1f      .L800EF808
/* 88C54 800EF7A4 00000000 */   nop
/* 88C58 800EF7A8 8E260038 */  lw        $a2, 0x38($s1)
/* 88C5C 800EF7AC 8E270040 */  lw        $a3, 0x40($s1)
/* 88C60 800EF7B0 C64C0028 */  lwc1      $f12, 0x28($s2)
/* 88C64 800EF7B4 0C00A720 */  jal       atan2
/* 88C68 800EF7B8 C64E0030 */   lwc1     $f14, 0x30($s2)
/* 88C6C 800EF7BC 4405A000 */  mfc1      $a1, $f20
/* 88C70 800EF7C0 44060000 */  mfc1      $a2, $f0
/* 88C74 800EF7C4 0C00EA95 */  jal       npc_move_heading
/* 88C78 800EF7C8 0220202D */   daddu    $a0, $s1, $zero
/* 88C7C 800EF7CC 0200202D */  daddu     $a0, $s0, $zero
/* 88C80 800EF7D0 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 88C84 800EF7D4 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 88C88 800EF7D8 3C064000 */  lui       $a2, 0x4000
/* 88C8C 800EF7DC 00021880 */  sll       $v1, $v0, 2
/* 88C90 800EF7E0 00621821 */  addu      $v1, $v1, $v0
/* 88C94 800EF7E4 00031880 */  sll       $v1, $v1, 2
/* 88C98 800EF7E8 00621823 */  subu      $v1, $v1, $v0
/* 88C9C 800EF7EC 000310C0 */  sll       $v0, $v1, 3
/* 88CA0 800EF7F0 00621821 */  addu      $v1, $v1, $v0
/* 88CA4 800EF7F4 000318C0 */  sll       $v1, $v1, 3
/* 88CA8 800EF7F8 02631821 */  addu      $v1, $s3, $v1
/* 88CAC 800EF7FC 8C67FF98 */  lw        $a3, -0x68($v1)
/* 88CB0 800EF800 0C00A7E7 */  jal       add_vec2D_polar
/* 88CB4 800EF804 0280282D */   daddu    $a1, $s4, $zero
.L800EF808:
/* 88CB8 800EF808 8FBF005C */  lw        $ra, 0x5c($sp)
/* 88CBC 800EF80C 8FB40058 */  lw        $s4, 0x58($sp)
/* 88CC0 800EF810 8FB30054 */  lw        $s3, 0x54($sp)
/* 88CC4 800EF814 8FB20050 */  lw        $s2, 0x50($sp)
/* 88CC8 800EF818 8FB1004C */  lw        $s1, 0x4c($sp)
/* 88CCC 800EF81C 8FB00048 */  lw        $s0, 0x48($sp)
/* 88CD0 800EF820 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 88CD4 800EF824 03E00008 */  jr        $ra
/* 88CD8 800EF828 27BD0068 */   addiu    $sp, $sp, 0x68
