.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003A91C
/* 15D1C 8003A91C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 15D20 8003A920 AFB00010 */  sw        $s0, 0x10($sp)
/* 15D24 8003A924 0080802D */  daddu     $s0, $a0, $zero
/* 15D28 8003A928 AFB10014 */  sw        $s1, 0x14($sp)
/* 15D2C 8003A92C 00A0882D */  daddu     $s1, $a1, $zero
/* 15D30 8003A930 AFB20018 */  sw        $s2, 0x18($sp)
/* 15D34 8003A934 AFBF001C */  sw        $ra, 0x1c($sp)
/* 15D38 8003A938 8E020000 */  lw        $v0, ($s0)
/* 15D3C 8003A93C 3C030100 */  lui       $v1, 0x100
/* 15D40 8003A940 00431024 */  and       $v0, $v0, $v1
/* 15D44 8003A944 14400008 */  bnez      $v0, .L8003A968
/* 15D48 8003A948 00C0902D */   daddu    $s2, $a2, $zero
/* 15D4C 8003A94C 8E040024 */  lw        $a0, 0x24($s0)
/* 15D50 8003A950 0C04484E */  jal       func_80112138
/* 15D54 8003A954 00000000 */   nop
/* 15D58 8003A958 10400003 */  beqz      $v0, .L8003A968
/* 15D5C 8003A95C 00000000 */   nop
.L8003A960:
/* 15D60 8003A960 0800EA58 */  j         .L8003A960
/* 15D64 8003A964 00000000 */   nop
.L8003A968:
/* 15D68 8003A968 8E020000 */  lw        $v0, ($s0)
/* 15D6C 8003A96C 3C030100 */  lui       $v1, 0x100
/* 15D70 8003A970 00431024 */  and       $v0, $v0, $v1
/* 15D74 8003A974 14400008 */  bnez      $v0, .L8003A998
/* 15D78 8003A978 AE1200B0 */   sw       $s2, 0xb0($s0)
/* 15D7C 8003A97C 0220202D */  daddu     $a0, $s1, $zero
/* 15D80 8003A980 0C04470F */  jal       func_80111C3C
/* 15D84 8003A984 0240282D */   daddu    $a1, $s2, $zero
/* 15D88 8003A988 04410003 */  bgez      $v0, .L8003A998
/* 15D8C 8003A98C AE020024 */   sw       $v0, 0x24($s0)
.L8003A990:
/* 15D90 8003A990 0800EA64 */  j         .L8003A990
/* 15D94 8003A994 00000000 */   nop
.L8003A998:
/* 15D98 8003A998 8E030000 */  lw        $v1, ($s0)
/* 15D9C 8003A99C 3C024000 */  lui       $v0, 0x4000
/* 15DA0 8003A9A0 00621024 */  and       $v0, $v1, $v0
/* 15DA4 8003A9A4 14400009 */  bnez      $v0, .L8003A9CC
/* 15DA8 8003A9A8 AE110028 */   sw       $s1, 0x28($s0)
/* 15DAC 8003A9AC 3C020100 */  lui       $v0, 0x100
/* 15DB0 8003A9B0 00621024 */  and       $v0, $v1, $v0
/* 15DB4 8003A9B4 14400005 */  bnez      $v0, .L8003A9CC
/* 15DB8 8003A9B8 00000000 */   nop
/* 15DBC 8003A9BC 8E040024 */  lw        $a0, 0x24($s0)
/* 15DC0 8003A9C0 8E060030 */  lw        $a2, 0x30($s0)
/* 15DC4 8003A9C4 0C04477F */  jal       func_80111DFC
/* 15DC8 8003A9C8 0220282D */   daddu    $a1, $s1, $zero
.L8003A9CC:
/* 15DCC 8003A9CC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 15DD0 8003A9D0 8FB20018 */  lw        $s2, 0x18($sp)
/* 15DD4 8003A9D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 15DD8 8003A9D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 15DDC 8003A9DC 03E00008 */  jr        $ra
/* 15DE0 8003A9E0 27BD0020 */   addiu    $sp, $sp, 0x20
