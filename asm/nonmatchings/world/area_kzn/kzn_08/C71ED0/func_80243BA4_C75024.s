.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243BA4_C75024
/* C75024 80243BA4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C75028 80243BA8 AFB40040 */  sw        $s4, 0x40($sp)
/* C7502C 80243BAC 0080A02D */  daddu     $s4, $a0, $zero
/* C75030 80243BB0 AFBF0044 */  sw        $ra, 0x44($sp)
/* C75034 80243BB4 AFB3003C */  sw        $s3, 0x3c($sp)
/* C75038 80243BB8 AFB20038 */  sw        $s2, 0x38($sp)
/* C7503C 80243BBC AFB10034 */  sw        $s1, 0x34($sp)
/* C75040 80243BC0 AFB00030 */  sw        $s0, 0x30($sp)
/* C75044 80243BC4 8E910148 */  lw        $s1, 0x148($s4)
/* C75048 80243BC8 00A0902D */  daddu     $s2, $a1, $zero
/* C7504C 80243BCC 86240008 */  lh        $a0, 8($s1)
/* C75050 80243BD0 0C00EABB */  jal       get_npc_unsafe
/* C75054 80243BD4 00C0982D */   daddu    $s3, $a2, $zero
/* C75058 80243BD8 0040802D */  daddu     $s0, $v0, $zero
/* C7505C 80243BDC 9602008E */  lhu       $v0, 0x8e($s0)
/* C75060 80243BE0 2442FFFF */  addiu     $v0, $v0, -1
/* C75064 80243BE4 A602008E */  sh        $v0, 0x8e($s0)
/* C75068 80243BE8 00021400 */  sll       $v0, $v0, 0x10
/* C7506C 80243BEC 14400020 */  bnez      $v0, .L80243C70
/* C75070 80243BF0 0260202D */   daddu    $a0, $s3, $zero
/* C75074 80243BF4 AFA00010 */  sw        $zero, 0x10($sp)
/* C75078 80243BF8 8E46000C */  lw        $a2, 0xc($s2)
/* C7507C 80243BFC 8E470010 */  lw        $a3, 0x10($s2)
/* C75080 80243C00 0C01242D */  jal       func_800490B4
/* C75084 80243C04 0220282D */   daddu    $a1, $s1, $zero
/* C75088 80243C08 54400018 */  bnel      $v0, $zero, .L80243C6C
/* C7508C 80243C0C A600008E */   sh       $zero, 0x8e($s0)
/* C75090 80243C10 24040002 */  addiu     $a0, $zero, 2
/* C75094 80243C14 0200282D */  daddu     $a1, $s0, $zero
/* C75098 80243C18 0000302D */  daddu     $a2, $zero, $zero
/* C7509C 80243C1C 860300A8 */  lh        $v1, 0xa8($s0)
/* C750A0 80243C20 3C013F80 */  lui       $at, 0x3f80
/* C750A4 80243C24 44810000 */  mtc1      $at, $f0
/* C750A8 80243C28 3C014000 */  lui       $at, 0x4000
/* C750AC 80243C2C 44811000 */  mtc1      $at, $f2
/* C750B0 80243C30 3C01C1A0 */  lui       $at, 0xc1a0
/* C750B4 80243C34 44812000 */  mtc1      $at, $f4
/* C750B8 80243C38 2402000F */  addiu     $v0, $zero, 0xf
/* C750BC 80243C3C AFA2001C */  sw        $v0, 0x1c($sp)
/* C750C0 80243C40 44833000 */  mtc1      $v1, $f6
/* C750C4 80243C44 00000000 */  nop
/* C750C8 80243C48 468031A0 */  cvt.s.w   $f6, $f6
/* C750CC 80243C4C 44073000 */  mfc1      $a3, $f6
/* C750D0 80243C50 27A20028 */  addiu     $v0, $sp, 0x28
/* C750D4 80243C54 AFA20020 */  sw        $v0, 0x20($sp)
/* C750D8 80243C58 E7A00010 */  swc1      $f0, 0x10($sp)
/* C750DC 80243C5C E7A20014 */  swc1      $f2, 0x14($sp)
/* C750E0 80243C60 0C01BFA4 */  jal       fx_emote
/* C750E4 80243C64 E7A40018 */   swc1     $f4, 0x18($sp)
/* C750E8 80243C68 A600008E */  sh        $zero, 0x8e($s0)
.L80243C6C:
/* C750EC 80243C6C AE800070 */  sw        $zero, 0x70($s4)
.L80243C70:
/* C750F0 80243C70 8FBF0044 */  lw        $ra, 0x44($sp)
/* C750F4 80243C74 8FB40040 */  lw        $s4, 0x40($sp)
/* C750F8 80243C78 8FB3003C */  lw        $s3, 0x3c($sp)
/* C750FC 80243C7C 8FB20038 */  lw        $s2, 0x38($sp)
/* C75100 80243C80 8FB10034 */  lw        $s1, 0x34($sp)
/* C75104 80243C84 8FB00030 */  lw        $s0, 0x30($sp)
/* C75108 80243C88 03E00008 */  jr        $ra
/* C7510C 80243C8C 27BD0048 */   addiu    $sp, $sp, 0x48
