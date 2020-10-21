.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F6C_B35B3C
/* B35B3C 80240F6C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B35B40 80240F70 AFB3003C */  sw        $s3, 0x3c($sp)
/* B35B44 80240F74 0080982D */  daddu     $s3, $a0, $zero
/* B35B48 80240F78 AFBF0040 */  sw        $ra, 0x40($sp)
/* B35B4C 80240F7C AFB20038 */  sw        $s2, 0x38($sp)
/* B35B50 80240F80 AFB10034 */  sw        $s1, 0x34($sp)
/* B35B54 80240F84 AFB00030 */  sw        $s0, 0x30($sp)
/* B35B58 80240F88 8E720148 */  lw        $s2, 0x148($s3)
/* B35B5C 80240F8C 00A0882D */  daddu     $s1, $a1, $zero
/* B35B60 80240F90 86440008 */  lh        $a0, 8($s2)
/* B35B64 80240F94 0C00EABB */  jal       get_npc_unsafe
/* B35B68 80240F98 00C0802D */   daddu    $s0, $a2, $zero
/* B35B6C 80240F9C 0200202D */  daddu     $a0, $s0, $zero
/* B35B70 80240FA0 0240282D */  daddu     $a1, $s2, $zero
/* B35B74 80240FA4 24030001 */  addiu     $v1, $zero, 1
/* B35B78 80240FA8 AFA30010 */  sw        $v1, 0x10($sp)
/* B35B7C 80240FAC 8E260024 */  lw        $a2, 0x24($s1)
/* B35B80 80240FB0 8E270028 */  lw        $a3, 0x28($s1)
/* B35B84 80240FB4 0C01242D */  jal       func_800490B4
/* B35B88 80240FB8 0040802D */   daddu    $s0, $v0, $zero
/* B35B8C 80240FBC 1440001E */  bnez      $v0, .L80241038
/* B35B90 80240FC0 0200202D */   daddu    $a0, $s0, $zero
/* B35B94 80240FC4 24040002 */  addiu     $a0, $zero, 2
/* B35B98 80240FC8 0200282D */  daddu     $a1, $s0, $zero
/* B35B9C 80240FCC 0000302D */  daddu     $a2, $zero, $zero
/* B35BA0 80240FD0 860300A8 */  lh        $v1, 0xa8($s0)
/* B35BA4 80240FD4 3C013F80 */  lui       $at, 0x3f80
/* B35BA8 80240FD8 44810000 */  mtc1      $at, $f0
/* B35BAC 80240FDC 3C014000 */  lui       $at, 0x4000
/* B35BB0 80240FE0 44811000 */  mtc1      $at, $f2
/* B35BB4 80240FE4 3C01C1A0 */  lui       $at, 0xc1a0
/* B35BB8 80240FE8 44812000 */  mtc1      $at, $f4
/* B35BBC 80240FEC 2402000F */  addiu     $v0, $zero, 0xf
/* B35BC0 80240FF0 AFA2001C */  sw        $v0, 0x1c($sp)
/* B35BC4 80240FF4 44833000 */  mtc1      $v1, $f6
/* B35BC8 80240FF8 00000000 */  nop       
/* B35BCC 80240FFC 468031A0 */  cvt.s.w   $f6, $f6
/* B35BD0 80241000 44073000 */  mfc1      $a3, $f6
/* B35BD4 80241004 27A20028 */  addiu     $v0, $sp, 0x28
/* B35BD8 80241008 AFA20020 */  sw        $v0, 0x20($sp)
/* B35BDC 8024100C E7A00010 */  swc1      $f0, 0x10($sp)
/* B35BE0 80241010 E7A20014 */  swc1      $f2, 0x14($sp)
/* B35BE4 80241014 0C01BFA4 */  jal       fx_emote
/* B35BE8 80241018 E7A40018 */   swc1     $f4, 0x18($sp)
/* B35BEC 8024101C 8E4200CC */  lw        $v0, 0xcc($s2)
/* B35BF0 80241020 8C430000 */  lw        $v1, ($v0)
/* B35BF4 80241024 24020019 */  addiu     $v0, $zero, 0x19
/* B35BF8 80241028 A602008E */  sh        $v0, 0x8e($s0)
/* B35BFC 8024102C 2402000E */  addiu     $v0, $zero, 0xe
/* B35C00 80241030 0809041B */  j         .L8024106C
/* B35C04 80241034 AE030028 */   sw       $v1, 0x28($s0)
.L80241038:
/* B35C08 80241038 0C00F598 */  jal       func_8003D660
/* B35C0C 8024103C 24050001 */   addiu    $a1, $zero, 1
/* B35C10 80241040 8E050018 */  lw        $a1, 0x18($s0)
/* B35C14 80241044 8E06000C */  lw        $a2, 0xc($s0)
/* B35C18 80241048 0C00EA95 */  jal       npc_move_heading
/* B35C1C 8024104C 0200202D */   daddu    $a0, $s0, $zero
/* B35C20 80241050 8602008E */  lh        $v0, 0x8e($s0)
/* B35C24 80241054 9603008E */  lhu       $v1, 0x8e($s0)
/* B35C28 80241058 18400003 */  blez      $v0, .L80241068
/* B35C2C 8024105C 2462FFFF */   addiu    $v0, $v1, -1
/* B35C30 80241060 0809041C */  j         .L80241070
/* B35C34 80241064 A602008E */   sh       $v0, 0x8e($s0)
.L80241068:
/* B35C38 80241068 2402000C */  addiu     $v0, $zero, 0xc
.L8024106C:
/* B35C3C 8024106C AE620070 */  sw        $v0, 0x70($s3)
.L80241070:
/* B35C40 80241070 8FBF0040 */  lw        $ra, 0x40($sp)
/* B35C44 80241074 8FB3003C */  lw        $s3, 0x3c($sp)
/* B35C48 80241078 8FB20038 */  lw        $s2, 0x38($sp)
/* B35C4C 8024107C 8FB10034 */  lw        $s1, 0x34($sp)
/* B35C50 80241080 8FB00030 */  lw        $s0, 0x30($sp)
/* B35C54 80241084 03E00008 */  jr        $ra
/* B35C58 80241088 27BD0048 */   addiu    $sp, $sp, 0x48
