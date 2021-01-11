.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4154
/* 1059D4 802E4154 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1059D8 802E4158 AFB00018 */  sw        $s0, 0x18($sp)
/* 1059DC 802E415C 0080802D */  daddu     $s0, $a0, $zero
/* 1059E0 802E4160 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1059E4 802E4164 8E040040 */  lw        $a0, 0x40($s0)
/* 1059E8 802E4168 9483000A */  lhu       $v1, 0xa($a0)
/* 1059EC 802E416C 3402FFFF */  ori       $v0, $zero, 0xffff
/* 1059F0 802E4170 10620024 */  beq       $v1, $v0, .L802E4204
/* 1059F4 802E4174 00000000 */   nop
/* 1059F8 802E4178 0C05152F */  jal       get_global_flag
/* 1059FC 802E417C 0060202D */   daddu    $a0, $v1, $zero
/* 105A00 802E4180 10400020 */  beqz      $v0, .L802E4204
/* 105A04 802E4184 00000000 */   nop
/* 105A08 802E4188 0C0441A9 */  jal       get_entity_type
/* 105A0C 802E418C 92040004 */   lbu      $a0, 4($s0)
/* 105A10 802E4190 3C04802F */  lui       $a0, %hi(D_802EA0A0)
/* 105A14 802E4194 2484A0A0 */  addiu     $a0, $a0, %lo(D_802EA0A0)
/* 105A18 802E4198 24030014 */  addiu     $v1, $zero, 0x14
/* 105A1C 802E419C 10430003 */  beq       $v0, $v1, .L802E41AC
/* 105A20 802E41A0 00000000 */   nop
/* 105A24 802E41A4 3C04802F */  lui       $a0, %hi(D_802EA07C)
/* 105A28 802E41A8 2484A07C */  addiu     $a0, $a0, %lo(D_802EA07C)
.L802E41AC:
/* 105A2C 802E41AC C6020048 */  lwc1      $f2, 0x48($s0)
/* 105A30 802E41B0 C604004C */  lwc1      $f4, 0x4c($s0)
/* 105A34 802E41B4 C6060050 */  lwc1      $f6, 0x50($s0)
/* 105A38 802E41B8 C6000064 */  lwc1      $f0, 0x64($s0)
/* 105A3C 802E41BC 3C028000 */  lui       $v0, 0x8000
/* 105A40 802E41C0 AFA20014 */  sw        $v0, 0x14($sp)
/* 105A44 802E41C4 4600020D */  trunc.w.s $f8, $f0
/* 105A48 802E41C8 E7A80010 */  swc1      $f8, 0x10($sp)
/* 105A4C 802E41CC 4600120D */  trunc.w.s $f8, $f2
/* 105A50 802E41D0 44054000 */  mfc1      $a1, $f8
/* 105A54 802E41D4 4600220D */  trunc.w.s $f8, $f4
/* 105A58 802E41D8 44064000 */  mfc1      $a2, $f8
/* 105A5C 802E41DC 4600320D */  trunc.w.s $f8, $f6
/* 105A60 802E41E0 44074000 */  mfc1      $a3, $f8
/* 105A64 802E41E4 0C044631 */  jal       create_entity
/* 105A68 802E41E8 00000000 */   nop
/* 105A6C 802E41EC 3C05802F */  lui       $a1, %hi(D_802EA310)
/* 105A70 802E41F0 24A5A310 */  addiu     $a1, $a1, %lo(D_802EA310)
/* 105A74 802E41F4 0C043EF0 */  jal       func_8010FBC0
/* 105A78 802E41F8 0200202D */   daddu    $a0, $s0, $zero
/* 105A7C 802E41FC 080B9083 */  j         .L802E420C
/* 105A80 802E4200 00000000 */   nop
.L802E4204:
/* 105A84 802E4204 0C043F5A */  jal       func_8010FD68
/* 105A88 802E4208 0200202D */   daddu    $a0, $s0, $zero
.L802E420C:
/* 105A8C 802E420C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 105A90 802E4210 8FB00018 */  lw        $s0, 0x18($sp)
/* 105A94 802E4214 03E00008 */  jr        $ra
/* 105A98 802E4218 27BD0020 */   addiu    $sp, $sp, 0x20
