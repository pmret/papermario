.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_B59B60
/* B59B60 802402F0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B59B64 802402F4 AFB10034 */  sw        $s1, 0x34($sp)
/* B59B68 802402F8 0080882D */  daddu     $s1, $a0, $zero
/* B59B6C 802402FC AFBF0038 */  sw        $ra, 0x38($sp)
/* B59B70 80240300 AFB00030 */  sw        $s0, 0x30($sp)
/* B59B74 80240304 8E300148 */  lw        $s0, 0x148($s1)
/* B59B78 80240308 0C00EABB */  jal       get_npc_unsafe
/* B59B7C 8024030C 86040008 */   lh       $a0, 8($s0)
/* B59B80 80240310 0040282D */  daddu     $a1, $v0, $zero
/* B59B84 80240314 94A2008E */  lhu       $v0, 0x8e($a1)
/* B59B88 80240318 2442FFFF */  addiu     $v0, $v0, -1
/* B59B8C 8024031C A4A2008E */  sh        $v0, 0x8e($a1)
/* B59B90 80240320 00021400 */  sll       $v0, $v0, 0x10
/* B59B94 80240324 1C400023 */  bgtz      $v0, .L802403B4
/* B59B98 80240328 24020004 */   addiu    $v0, $zero, 4
/* B59B9C 8024032C 8E0300CC */  lw        $v1, 0xcc($s0)
/* B59BA0 80240330 AE02006C */  sw        $v0, 0x6c($s0)
/* B59BA4 80240334 8C620000 */  lw        $v0, ($v1)
/* B59BA8 80240338 ACA20028 */  sw        $v0, 0x28($a1)
/* B59BAC 8024033C 9602007A */  lhu       $v0, 0x7a($s0)
/* B59BB0 80240340 A4A2008E */  sh        $v0, 0x8e($a1)
/* B59BB4 80240344 8E020078 */  lw        $v0, 0x78($s0)
/* B59BB8 80240348 28420008 */  slti      $v0, $v0, 8
/* B59BBC 8024034C 14400018 */  bnez      $v0, .L802403B0
/* B59BC0 80240350 24020021 */   addiu    $v0, $zero, 0x21
/* B59BC4 80240354 24040003 */  addiu     $a0, $zero, 3
/* B59BC8 80240358 27A30028 */  addiu     $v1, $sp, 0x28
/* B59BCC 8024035C 84A700A8 */  lh        $a3, 0xa8($a1)
/* B59BD0 80240360 3C013F80 */  lui       $at, 0x3f80
/* B59BD4 80240364 44810000 */  mtc1      $at, $f0
/* B59BD8 80240368 3C014000 */  lui       $at, 0x4000
/* B59BDC 8024036C 44811000 */  mtc1      $at, $f2
/* B59BE0 80240370 3C01C1A0 */  lui       $at, 0xc1a0
/* B59BE4 80240374 44812000 */  mtc1      $at, $f4
/* B59BE8 80240378 44873000 */  mtc1      $a3, $f6
/* B59BEC 8024037C 00000000 */  nop       
/* B59BF0 80240380 468031A0 */  cvt.s.w   $f6, $f6
/* B59BF4 80240384 E7A00010 */  swc1      $f0, 0x10($sp)
/* B59BF8 80240388 E7A20014 */  swc1      $f2, 0x14($sp)
/* B59BFC 8024038C E7A40018 */  swc1      $f4, 0x18($sp)
/* B59C00 80240390 8E020078 */  lw        $v0, 0x78($s0)
/* B59C04 80240394 44073000 */  mfc1      $a3, $f6
/* B59C08 80240398 0000302D */  daddu     $a2, $zero, $zero
/* B59C0C 8024039C AFA30020 */  sw        $v1, 0x20($sp)
/* B59C10 802403A0 2442FFFF */  addiu     $v0, $v0, -1
/* B59C14 802403A4 0C01BFA4 */  jal       fx_emote
/* B59C18 802403A8 AFA2001C */   sw       $v0, 0x1c($sp)
/* B59C1C 802403AC 24020021 */  addiu     $v0, $zero, 0x21
.L802403B0:
/* B59C20 802403B0 AE220070 */  sw        $v0, 0x70($s1)
.L802403B4:
/* B59C24 802403B4 8FBF0038 */  lw        $ra, 0x38($sp)
/* B59C28 802403B8 8FB10034 */  lw        $s1, 0x34($sp)
/* B59C2C 802403BC 8FB00030 */  lw        $s0, 0x30($sp)
/* B59C30 802403C0 03E00008 */  jr        $ra
/* B59C34 802403C4 27BD0040 */   addiu    $sp, $sp, 0x40
