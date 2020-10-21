.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B68_B94FA8
/* B94FA8 80241B68 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B94FAC 80241B6C AFB40040 */  sw        $s4, 0x40($sp)
/* B94FB0 80241B70 0080A02D */  daddu     $s4, $a0, $zero
/* B94FB4 80241B74 AFBF0044 */  sw        $ra, 0x44($sp)
/* B94FB8 80241B78 AFB3003C */  sw        $s3, 0x3c($sp)
/* B94FBC 80241B7C AFB20038 */  sw        $s2, 0x38($sp)
/* B94FC0 80241B80 AFB10034 */  sw        $s1, 0x34($sp)
/* B94FC4 80241B84 AFB00030 */  sw        $s0, 0x30($sp)
/* B94FC8 80241B88 8E910148 */  lw        $s1, 0x148($s4)
/* B94FCC 80241B8C 00A0902D */  daddu     $s2, $a1, $zero
/* B94FD0 80241B90 86240008 */  lh        $a0, 8($s1)
/* B94FD4 80241B94 0C00EABB */  jal       get_npc_unsafe
/* B94FD8 80241B98 00C0982D */   daddu    $s3, $a2, $zero
/* B94FDC 80241B9C 0040802D */  daddu     $s0, $v0, $zero
/* B94FE0 80241BA0 9602008E */  lhu       $v0, 0x8e($s0)
/* B94FE4 80241BA4 2442FFFF */  addiu     $v0, $v0, -1
/* B94FE8 80241BA8 A602008E */  sh        $v0, 0x8e($s0)
/* B94FEC 80241BAC 00021400 */  sll       $v0, $v0, 0x10
/* B94FF0 80241BB0 14400020 */  bnez      $v0, .L80241C34
/* B94FF4 80241BB4 0260202D */   daddu    $a0, $s3, $zero
/* B94FF8 80241BB8 AFA00010 */  sw        $zero, 0x10($sp)
/* B94FFC 80241BBC 8E46000C */  lw        $a2, 0xc($s2)
/* B95000 80241BC0 8E470010 */  lw        $a3, 0x10($s2)
/* B95004 80241BC4 0C01242D */  jal       func_800490B4
/* B95008 80241BC8 0220282D */   daddu    $a1, $s1, $zero
/* B9500C 80241BCC 54400018 */  bnel      $v0, $zero, .L80241C30
/* B95010 80241BD0 A600008E */   sh       $zero, 0x8e($s0)
/* B95014 80241BD4 24040002 */  addiu     $a0, $zero, 2
/* B95018 80241BD8 0200282D */  daddu     $a1, $s0, $zero
/* B9501C 80241BDC 0000302D */  daddu     $a2, $zero, $zero
/* B95020 80241BE0 860300A8 */  lh        $v1, 0xa8($s0)
/* B95024 80241BE4 3C013F80 */  lui       $at, 0x3f80
/* B95028 80241BE8 44810000 */  mtc1      $at, $f0
/* B9502C 80241BEC 3C014000 */  lui       $at, 0x4000
/* B95030 80241BF0 44811000 */  mtc1      $at, $f2
/* B95034 80241BF4 3C01C1A0 */  lui       $at, 0xc1a0
/* B95038 80241BF8 44812000 */  mtc1      $at, $f4
/* B9503C 80241BFC 2402000F */  addiu     $v0, $zero, 0xf
/* B95040 80241C00 AFA2001C */  sw        $v0, 0x1c($sp)
/* B95044 80241C04 44833000 */  mtc1      $v1, $f6
/* B95048 80241C08 00000000 */  nop       
/* B9504C 80241C0C 468031A0 */  cvt.s.w   $f6, $f6
/* B95050 80241C10 44073000 */  mfc1      $a3, $f6
/* B95054 80241C14 27A20028 */  addiu     $v0, $sp, 0x28
/* B95058 80241C18 AFA20020 */  sw        $v0, 0x20($sp)
/* B9505C 80241C1C E7A00010 */  swc1      $f0, 0x10($sp)
/* B95060 80241C20 E7A20014 */  swc1      $f2, 0x14($sp)
/* B95064 80241C24 0C01BFA4 */  jal       fx_emote
/* B95068 80241C28 E7A40018 */   swc1     $f4, 0x18($sp)
/* B9506C 80241C2C A600008E */  sh        $zero, 0x8e($s0)
.L80241C30:
/* B95070 80241C30 AE800070 */  sw        $zero, 0x70($s4)
.L80241C34:
/* B95074 80241C34 8FBF0044 */  lw        $ra, 0x44($sp)
/* B95078 80241C38 8FB40040 */  lw        $s4, 0x40($sp)
/* B9507C 80241C3C 8FB3003C */  lw        $s3, 0x3c($sp)
/* B95080 80241C40 8FB20038 */  lw        $s2, 0x38($sp)
/* B95084 80241C44 8FB10034 */  lw        $s1, 0x34($sp)
/* B95088 80241C48 8FB00030 */  lw        $s0, 0x30($sp)
/* B9508C 80241C4C 03E00008 */  jr        $ra
/* B95090 80241C50 27BD0048 */   addiu    $sp, $sp, 0x48
