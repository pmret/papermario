.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242DB0_C42B60
/* C42B60 80242DB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C42B64 80242DB4 AFB30024 */  sw        $s3, 0x24($sp)
/* C42B68 80242DB8 0080982D */  daddu     $s3, $a0, $zero
/* C42B6C 80242DBC AFBF0028 */  sw        $ra, 0x28($sp)
/* C42B70 80242DC0 AFB20020 */  sw        $s2, 0x20($sp)
/* C42B74 80242DC4 AFB1001C */  sw        $s1, 0x1c($sp)
/* C42B78 80242DC8 AFB00018 */  sw        $s0, 0x18($sp)
/* C42B7C 80242DCC 8E700148 */  lw        $s0, 0x148($s3)
/* C42B80 80242DD0 00A0902D */  daddu     $s2, $a1, $zero
/* C42B84 80242DD4 86040008 */  lh        $a0, 8($s0)
/* C42B88 80242DD8 0C00EABB */  jal       get_npc_unsafe
/* C42B8C 80242DDC 00C0882D */   daddu    $s1, $a2, $zero
/* C42B90 80242DE0 0220202D */  daddu     $a0, $s1, $zero
/* C42B94 80242DE4 0200282D */  daddu     $a1, $s0, $zero
/* C42B98 80242DE8 24030001 */  addiu     $v1, $zero, 1
/* C42B9C 80242DEC AFA30010 */  sw        $v1, 0x10($sp)
/* C42BA0 80242DF0 8E460024 */  lw        $a2, 0x24($s2)
/* C42BA4 80242DF4 8E470028 */  lw        $a3, 0x28($s2)
/* C42BA8 80242DF8 0C01242D */  jal       func_800490B4
/* C42BAC 80242DFC 0040802D */   daddu    $s0, $v0, $zero
/* C42BB0 80242E00 10400024 */  beqz      $v0, .L80242E94
/* C42BB4 80242E04 24020010 */   addiu    $v0, $zero, 0x10
/* C42BB8 80242E08 8E050018 */  lw        $a1, 0x18($s0)
/* C42BBC 80242E0C 8E06000C */  lw        $a2, 0xc($s0)
/* C42BC0 80242E10 0C00EA95 */  jal       npc_move_heading
/* C42BC4 80242E14 0200202D */   daddu    $a0, $s0, $zero
/* C42BC8 80242E18 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C42BCC 80242E1C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C42BD0 80242E20 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C42BD4 80242E24 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C42BD8 80242E28 8C460028 */  lw        $a2, 0x28($v0)
/* C42BDC 80242E2C 0C00A7B5 */  jal       dist2D
/* C42BE0 80242E30 8C470030 */   lw       $a3, 0x30($v0)
/* C42BE4 80242E34 C6020018 */  lwc1      $f2, 0x18($s0)
/* C42BE8 80242E38 3C014004 */  lui       $at, 0x4004
/* C42BEC 80242E3C 44812800 */  mtc1      $at, $f5
/* C42BF0 80242E40 44802000 */  mtc1      $zero, $f4
/* C42BF4 80242E44 460010A1 */  cvt.d.s   $f2, $f2
/* C42BF8 80242E48 46241082 */  mul.d     $f2, $f2, $f4
/* C42BFC 80242E4C 00000000 */  nop       
/* C42C00 80242E50 46000021 */  cvt.d.s   $f0, $f0
/* C42C04 80242E54 4622003E */  c.le.d    $f0, $f2
/* C42C08 80242E58 00000000 */  nop       
/* C42C0C 80242E5C 45000003 */  bc1f      .L80242E6C
/* C42C10 80242E60 2402000E */   addiu    $v0, $zero, 0xe
/* C42C14 80242E64 08090BA5 */  j         .L80242E94
/* C42C18 80242E68 A600008E */   sh       $zero, 0x8e($s0)
.L80242E6C:
/* C42C1C 80242E6C 9602008E */  lhu       $v0, 0x8e($s0)
/* C42C20 80242E70 2442FFFF */  addiu     $v0, $v0, -1
/* C42C24 80242E74 A602008E */  sh        $v0, 0x8e($s0)
/* C42C28 80242E78 00021400 */  sll       $v0, $v0, 0x10
/* C42C2C 80242E7C 1C400006 */  bgtz      $v0, .L80242E98
/* C42C30 80242E80 3C030020 */   lui      $v1, 0x20
/* C42C34 80242E84 8E020000 */  lw        $v0, ($s0)
/* C42C38 80242E88 00431025 */  or        $v0, $v0, $v1
/* C42C3C 80242E8C AE020000 */  sw        $v0, ($s0)
/* C42C40 80242E90 2402000C */  addiu     $v0, $zero, 0xc
.L80242E94:
/* C42C44 80242E94 AE620070 */  sw        $v0, 0x70($s3)
.L80242E98:
/* C42C48 80242E98 8FBF0028 */  lw        $ra, 0x28($sp)
/* C42C4C 80242E9C 8FB30024 */  lw        $s3, 0x24($sp)
/* C42C50 80242EA0 8FB20020 */  lw        $s2, 0x20($sp)
/* C42C54 80242EA4 8FB1001C */  lw        $s1, 0x1c($sp)
/* C42C58 80242EA8 8FB00018 */  lw        $s0, 0x18($sp)
/* C42C5C 80242EAC 03E00008 */  jr        $ra
/* C42C60 80242EB0 27BD0030 */   addiu    $sp, $sp, 0x30
