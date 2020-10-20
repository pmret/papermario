.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_A64FB0
/* A64FB0 80240F20 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A64FB4 80240F24 AFB3003C */  sw        $s3, 0x3c($sp)
/* A64FB8 80240F28 0080982D */  daddu     $s3, $a0, $zero
/* A64FBC 80240F2C AFBF0044 */  sw        $ra, 0x44($sp)
/* A64FC0 80240F30 AFB40040 */  sw        $s4, 0x40($sp)
/* A64FC4 80240F34 AFB20038 */  sw        $s2, 0x38($sp)
/* A64FC8 80240F38 AFB10034 */  sw        $s1, 0x34($sp)
/* A64FCC 80240F3C AFB00030 */  sw        $s0, 0x30($sp)
/* A64FD0 80240F40 8E720148 */  lw        $s2, 0x148($s3)
/* A64FD4 80240F44 00A0882D */  daddu     $s1, $a1, $zero
/* A64FD8 80240F48 86440008 */  lh        $a0, 8($s2)
/* A64FDC 80240F4C 0C00EABB */  jal       get_npc_unsafe
/* A64FE0 80240F50 00C0A02D */   daddu    $s4, $a2, $zero
/* A64FE4 80240F54 0040802D */  daddu     $s0, $v0, $zero
/* A64FE8 80240F58 9602008E */  lhu       $v0, 0x8e($s0)
/* A64FEC 80240F5C 2442FFFF */  addiu     $v0, $v0, -1
/* A64FF0 80240F60 A602008E */  sh        $v0, 0x8e($s0)
/* A64FF4 80240F64 00021400 */  sll       $v0, $v0, 0x10
/* A64FF8 80240F68 1C400032 */  bgtz      $v0, .L80241034
/* A64FFC 80240F6C 00000000 */   nop      
/* A65000 80240F70 0260202D */  daddu     $a0, $s3, $zero
/* A65004 80240F74 8E250024 */  lw        $a1, 0x24($s1)
/* A65008 80240F78 8E260028 */  lw        $a2, 0x28($s1)
/* A6500C 80240F7C 0C090014 */  jal       func_80240050
/* A65010 80240F80 0280382D */   daddu    $a3, $s4, $zero
/* A65014 80240F84 0040882D */  daddu     $s1, $v0, $zero
/* A65018 80240F88 24020001 */  addiu     $v0, $zero, 1
/* A6501C 80240F8C 1222001D */  beq       $s1, $v0, .L80241004
/* A65020 80240F90 0200282D */   daddu    $a1, $s0, $zero
/* A65024 80240F94 24040002 */  addiu     $a0, $zero, 2
/* A65028 80240F98 0000302D */  daddu     $a2, $zero, $zero
/* A6502C 80240F9C 860300A8 */  lh        $v1, 0xa8($s0)
/* A65030 80240FA0 3C013F80 */  lui       $at, 0x3f80
/* A65034 80240FA4 44810000 */  mtc1      $at, $f0
/* A65038 80240FA8 3C014000 */  lui       $at, 0x4000
/* A6503C 80240FAC 44811000 */  mtc1      $at, $f2
/* A65040 80240FB0 3C01C1A0 */  lui       $at, 0xc1a0
/* A65044 80240FB4 44812000 */  mtc1      $at, $f4
/* A65048 80240FB8 2402000C */  addiu     $v0, $zero, 0xc
/* A6504C 80240FBC AFA2001C */  sw        $v0, 0x1c($sp)
/* A65050 80240FC0 44833000 */  mtc1      $v1, $f6
/* A65054 80240FC4 00000000 */  nop       
/* A65058 80240FC8 468031A0 */  cvt.s.w   $f6, $f6
/* A6505C 80240FCC 44073000 */  mfc1      $a3, $f6
/* A65060 80240FD0 27A20028 */  addiu     $v0, $sp, 0x28
/* A65064 80240FD4 AFA20020 */  sw        $v0, 0x20($sp)
/* A65068 80240FD8 E7A00010 */  swc1      $f0, 0x10($sp)
/* A6506C 80240FDC E7A20014 */  swc1      $f2, 0x14($sp)
/* A65070 80240FE0 0C01BFA4 */  jal       fx_emote
/* A65074 80240FE4 E7A40018 */   swc1     $f4, 0x18($sp)
/* A65078 80240FE8 8E4200CC */  lw        $v0, 0xcc($s2)
/* A6507C 80240FEC 8C430000 */  lw        $v1, ($v0)
/* A65080 80240FF0 2402000F */  addiu     $v0, $zero, 0xf
/* A65084 80240FF4 A602008E */  sh        $v0, 0x8e($s0)
/* A65088 80240FF8 AE030028 */  sw        $v1, 0x28($s0)
/* A6508C 80240FFC 0809040D */  j         .L80241034
/* A65090 80241000 AE600070 */   sw       $zero, 0x70($s3)
.L80241004:
/* A65094 80241004 0200202D */  daddu     $a0, $s0, $zero
/* A65098 80241008 240520D5 */  addiu     $a1, $zero, 0x20d5
/* A6509C 8024100C 0C012530 */  jal       func_800494C0
/* A650A0 80241010 0000302D */   daddu    $a2, $zero, $zero
/* A650A4 80241014 86440008 */  lh        $a0, 8($s2)
/* A650A8 80241018 0C00FB3A */  jal       get_enemy
/* A650AC 8024101C 24840001 */   addiu    $a0, $a0, 1
/* A650B0 80241020 AC51006C */  sw        $s1, 0x6c($v0)
/* A650B4 80241024 24020014 */  addiu     $v0, $zero, 0x14
/* A650B8 80241028 A602008E */  sh        $v0, 0x8e($s0)
/* A650BC 8024102C 24020018 */  addiu     $v0, $zero, 0x18
/* A650C0 80241030 AE620070 */  sw        $v0, 0x70($s3)
.L80241034:
/* A650C4 80241034 8FBF0044 */  lw        $ra, 0x44($sp)
/* A650C8 80241038 8FB40040 */  lw        $s4, 0x40($sp)
/* A650CC 8024103C 8FB3003C */  lw        $s3, 0x3c($sp)
/* A650D0 80241040 8FB20038 */  lw        $s2, 0x38($sp)
/* A650D4 80241044 8FB10034 */  lw        $s1, 0x34($sp)
/* A650D8 80241048 8FB00030 */  lw        $s0, 0x30($sp)
/* A650DC 8024104C 03E00008 */  jr        $ra
/* A650E0 80241050 27BD0048 */   addiu    $sp, $sp, 0x48
