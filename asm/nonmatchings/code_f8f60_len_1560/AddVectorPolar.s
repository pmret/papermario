.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddVectorPolar
/* 0F94C4 802D4B14 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F94C8 802D4B18 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0F94CC 802D4B1C 0080882D */  daddu $s1, $a0, $zero
/* 0F94D0 802D4B20 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F94D4 802D4B24 AFB30024 */  sw    $s3, 0x24($sp)
/* 0F94D8 802D4B28 AFB20020 */  sw    $s2, 0x20($sp)
/* 0F94DC 802D4B2C AFB00018 */  sw    $s0, 0x18($sp)
/* 0F94E0 802D4B30 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 0F94E4 802D4B34 8E30000C */  lw    $s0, 0xc($s1)
/* 0F94E8 802D4B38 8E130000 */  lw    $s3, ($s0)
/* 0F94EC 802D4B3C 26100004 */  addiu $s0, $s0, 4
/* 0F94F0 802D4B40 0C0B210B */  jal   get_float_variable
/* 0F94F4 802D4B44 0260282D */   daddu $a1, $s3, $zero
/* 0F94F8 802D4B48 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0F94FC 802D4B4C 8E120000 */  lw    $s2, ($s0)
/* 0F9500 802D4B50 26100004 */  addiu $s0, $s0, 4
/* 0F9504 802D4B54 0220202D */  daddu $a0, $s1, $zero
/* 0F9508 802D4B58 0C0B210B */  jal   get_float_variable
/* 0F950C 802D4B5C 0240282D */   daddu $a1, $s2, $zero
/* 0F9510 802D4B60 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0F9514 802D4B64 8E050000 */  lw    $a1, ($s0)
/* 0F9518 802D4B68 26100004 */  addiu $s0, $s0, 4
/* 0F951C 802D4B6C 0C0B210B */  jal   get_float_variable
/* 0F9520 802D4B70 0220202D */   daddu $a0, $s1, $zero
/* 0F9524 802D4B74 0220202D */  daddu $a0, $s1, $zero
/* 0F9528 802D4B78 8E050000 */  lw    $a1, ($s0)
/* 0F952C 802D4B7C 0C0B210B */  jal   get_float_variable
/* 0F9530 802D4B80 46000506 */   mov.s $f20, $f0
/* 0F9534 802D4B84 27A40010 */  addiu $a0, $sp, 0x10
/* 0F9538 802D4B88 4406A000 */  mfc1  $a2, $f20
/* 0F953C 802D4B8C 44070000 */  mfc1  $a3, $f0
/* 0F9540 802D4B90 0C00A7E7 */  jal   add_vec2D_polar
/* 0F9544 802D4B94 27A50014 */   addiu $a1, $sp, 0x14
/* 0F9548 802D4B98 0220202D */  daddu $a0, $s1, $zero
/* 0F954C 802D4B9C 8FA60010 */  lw    $a2, 0x10($sp)
/* 0F9550 802D4BA0 0C0B2190 */  jal   set_float_variable
/* 0F9554 802D4BA4 0260282D */   daddu $a1, $s3, $zero
/* 0F9558 802D4BA8 0220202D */  daddu $a0, $s1, $zero
/* 0F955C 802D4BAC 8FA60014 */  lw    $a2, 0x14($sp)
/* 0F9560 802D4BB0 0C0B2190 */  jal   set_float_variable
/* 0F9564 802D4BB4 0240282D */   daddu $a1, $s2, $zero
/* 0F9568 802D4BB8 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F956C 802D4BBC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0F9570 802D4BC0 8FB20020 */  lw    $s2, 0x20($sp)
/* 0F9574 802D4BC4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0F9578 802D4BC8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F957C 802D4BCC D7B40030 */  ldc1  $f20, 0x30($sp)
/* 0F9580 802D4BD0 24020002 */  addiu $v0, $zero, 2
/* 0F9584 802D4BD4 03E00008 */  jr    $ra
/* 0F9588 802D4BD8 27BD0038 */   addiu $sp, $sp, 0x38

/* 0F958C 802D4BDC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9590 802D4BE0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F9594 802D4BE4 10A00003 */  beqz  $a1, .L802D4BF4
/* 0F9598 802D4BE8 0080182D */   daddu $v1, $a0, $zero
/* 0F959C 802D4BEC AC600070 */  sw    $zero, 0x70($v1)
/* 0F95A0 802D4BF0 AC600074 */  sw    $zero, 0x74($v1)
.L802D4BF4:
/* 0F95A4 802D4BF4 8C620070 */  lw    $v0, 0x70($v1)
/* 0F95A8 802D4BF8 14400011 */  bnez  $v0, .L802D4C40
/* 0F95AC 802D4BFC 0000102D */   daddu $v0, $zero, $zero
/* 0F95B0 802D4C00 8C620074 */  lw    $v0, 0x74($v1)
/* 0F95B4 802D4C04 240400FF */  addiu $a0, $zero, 0xff
/* 0F95B8 802D4C08 14440003 */  bne   $v0, $a0, .L802D4C18
/* 0F95BC 802D4C0C 2442000A */   addiu $v0, $v0, 0xa
/* 0F95C0 802D4C10 080B5310 */  j     .L802D4C40
/* 0F95C4 802D4C14 24020002 */   addiu $v0, $zero, 2

.L802D4C18:
/* 0F95C8 802D4C18 AC620074 */  sw    $v0, 0x74($v1)
/* 0F95CC 802D4C1C 28420100 */  slti  $v0, $v0, 0x100
/* 0F95D0 802D4C20 50400001 */  beql  $v0, $zero, .L802D4C28
/* 0F95D4 802D4C24 AC640074 */   sw    $a0, 0x74($v1)
.L802D4C28:
/* 0F95D8 802D4C28 C4600074 */  lwc1  $f0, 0x74($v1)
/* 0F95DC 802D4C2C 46800020 */  cvt.s.w $f0, $f0
/* 0F95E0 802D4C30 44050000 */  mfc1  $a1, $f0
/* 0F95E4 802D4C34 0C04DF69 */  jal   func_80137DA4
/* 0F95E8 802D4C38 2404000A */   addiu $a0, $zero, 0xa
/* 0F95EC 802D4C3C 0000102D */  daddu $v0, $zero, $zero
.L802D4C40:
/* 0F95F0 802D4C40 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F95F4 802D4C44 03E00008 */  jr    $ra
/* 0F95F8 802D4C48 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F95FC 802D4C4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9600 802D4C50 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F9604 802D4C54 10A00004 */  beqz  $a1, .L802D4C68
/* 0F9608 802D4C58 0080182D */   daddu $v1, $a0, $zero
/* 0F960C 802D4C5C 240200FF */  addiu $v0, $zero, 0xff
/* 0F9610 802D4C60 AC600070 */  sw    $zero, 0x70($v1)
/* 0F9614 802D4C64 AC620074 */  sw    $v0, 0x74($v1)
.L802D4C68:
/* 0F9618 802D4C68 8C620070 */  lw    $v0, 0x70($v1)
/* 0F961C 802D4C6C 14400012 */  bnez  $v0, .L802D4CB8
/* 0F9620 802D4C70 0000102D */   daddu $v0, $zero, $zero
/* 0F9624 802D4C74 8C620074 */  lw    $v0, 0x74($v1)
/* 0F9628 802D4C78 14400006 */  bnez  $v0, .L802D4C94
/* 0F962C 802D4C7C 2442FFF6 */   addiu $v0, $v0, -0xa
/* 0F9630 802D4C80 3C05BF80 */  lui   $a1, 0xbf80
/* 0F9634 802D4C84 0C04DF69 */  jal   func_80137DA4
/* 0F9638 802D4C88 240400FF */   addiu $a0, $zero, 0xff
/* 0F963C 802D4C8C 080B532E */  j     .L802D4CB8
/* 0F9640 802D4C90 24020002 */   addiu $v0, $zero, 2

.L802D4C94:
/* 0F9644 802D4C94 04410002 */  bgez  $v0, .L802D4CA0
/* 0F9648 802D4C98 AC620074 */   sw    $v0, 0x74($v1)
/* 0F964C 802D4C9C AC600074 */  sw    $zero, 0x74($v1)
.L802D4CA0:
/* 0F9650 802D4CA0 C4600074 */  lwc1  $f0, 0x74($v1)
/* 0F9654 802D4CA4 46800020 */  cvt.s.w $f0, $f0
/* 0F9658 802D4CA8 44050000 */  mfc1  $a1, $f0
/* 0F965C 802D4CAC 0C04DF69 */  jal   func_80137DA4
/* 0F9660 802D4CB0 2404000A */   addiu $a0, $zero, 0xa
/* 0F9664 802D4CB4 0000102D */  daddu $v0, $zero, $zero
.L802D4CB8:
/* 0F9668 802D4CB8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F966C 802D4CBC 03E00008 */  jr    $ra
/* 0F9670 802D4CC0 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F9674 802D4CC4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9678 802D4CC8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F967C 802D4CCC 8C82000C */  lw    $v0, 0xc($a0)
/* 0F9680 802D4CD0 0C0B1EAF */  jal   get_variable
/* 0F9684 802D4CD4 8C450000 */   lw    $a1, ($v0)
/* 0F9688 802D4CD8 04410004 */  bgez  $v0, .L802D4CEC
/* 0F968C 802D4CDC 2404000A */   addiu $a0, $zero, 0xa
/* 0F9690 802D4CE0 3C05BF80 */  lui   $a1, 0xbf80
/* 0F9694 802D4CE4 080B533F */  j     .L802D4CFC
/* 0F9698 802D4CE8 240400FF */   addiu $a0, $zero, 0xff

.L802D4CEC:
/* 0F969C 802D4CEC 44820000 */  mtc1  $v0, $f0
/* 0F96A0 802D4CF0 00000000 */  nop   
/* 0F96A4 802D4CF4 46800020 */  cvt.s.w $f0, $f0
/* 0F96A8 802D4CF8 44050000 */  mfc1  $a1, $f0
.L802D4CFC:
/* 0F96AC 802D4CFC 0C04DF69 */  jal   func_80137DA4
/* 0F96B0 802D4D00 00000000 */   nop   
/* 0F96B4 802D4D04 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F96B8 802D4D08 24020002 */  addiu $v0, $zero, 2
/* 0F96BC 802D4D0C 03E00008 */  jr    $ra
/* 0F96C0 802D4D10 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F96C4 802D4D14 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F96C8 802D4D18 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F96CC 802D4D1C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F96D0 802D4D20 8C82000C */  lw    $v0, 0xc($a0)
/* 0F96D4 802D4D24 0C0B210B */  jal   get_float_variable
/* 0F96D8 802D4D28 8C450000 */   lw    $a1, ($v0)
/* 0F96DC 802D4D2C 0000202D */  daddu $a0, $zero, $zero
/* 0F96E0 802D4D30 0080282D */  daddu $a1, $a0, $zero
/* 0F96E4 802D4D34 2406000C */  addiu $a2, $zero, 0xc
/* 0F96E8 802D4D38 4600008D */  trunc.w.s $f2, $f0
/* 0F96EC 802D4D3C 44101000 */  mfc1  $s0, $f2
/* 0F96F0 802D4D40 0C04DF93 */  jal   func_80137E4C
/* 0F96F4 802D4D44 24070014 */   addiu $a3, $zero, 0x14
/* 0F96F8 802D4D48 0000202D */  daddu $a0, $zero, $zero
/* 0F96FC 802D4D4C 24050001 */  addiu $a1, $zero, 1
/* 0F9700 802D4D50 24060134 */  addiu $a2, $zero, 0x134
/* 0F9704 802D4D54 0C04DF93 */  jal   func_80137E4C
/* 0F9708 802D4D58 240700DC */   addiu $a3, $zero, 0xdc
/* 0F970C 802D4D5C 44901000 */  mtc1  $s0, $f2
/* 0F9710 802D4D60 00000000 */  nop   
/* 0F9714 802D4D64 468010A0 */  cvt.s.w $f2, $f2
/* 0F9718 802D4D68 44051000 */  mfc1  $a1, $f2
/* 0F971C 802D4D6C 0C04DF62 */  jal   func_80137D88
/* 0F9720 802D4D70 2404000C */   addiu $a0, $zero, 0xc
/* 0F9724 802D4D74 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F9728 802D4D78 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F972C 802D4D7C 24020002 */  addiu $v0, $zero, 2
/* 0F9730 802D4D80 03E00008 */  jr    $ra
/* 0F9734 802D4D84 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F9738 802D4D88 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F973C 802D4D8C 2404000C */  addiu $a0, $zero, 0xc
/* 0F9740 802D4D90 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F9744 802D4D94 0C04DF62 */  jal   func_80137D88
/* 0F9748 802D4D98 0000282D */   daddu $a1, $zero, $zero
/* 0F974C 802D4D9C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F9750 802D4DA0 24020002 */  addiu $v0, $zero, 2
/* 0F9754 802D4DA4 03E00008 */  jr    $ra
/* 0F9758 802D4DA8 27BD0018 */   addiu $sp, $sp, 0x18

