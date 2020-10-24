.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403EC_C85E9C
/* C85E9C 802403EC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C85EA0 802403F0 AFB10034 */  sw        $s1, 0x34($sp)
/* C85EA4 802403F4 0080882D */  daddu     $s1, $a0, $zero
/* C85EA8 802403F8 AFBF0038 */  sw        $ra, 0x38($sp)
/* C85EAC 802403FC AFB00030 */  sw        $s0, 0x30($sp)
/* C85EB0 80240400 8E300148 */  lw        $s0, 0x148($s1)
/* C85EB4 80240404 0C00EABB */  jal       get_npc_unsafe
/* C85EB8 80240408 86040008 */   lh       $a0, 8($s0)
/* C85EBC 8024040C 0040282D */  daddu     $a1, $v0, $zero
/* C85EC0 80240410 94A2008E */  lhu       $v0, 0x8e($a1)
/* C85EC4 80240414 2442FFFF */  addiu     $v0, $v0, -1
/* C85EC8 80240418 A4A2008E */  sh        $v0, 0x8e($a1)
/* C85ECC 8024041C 00021400 */  sll       $v0, $v0, 0x10
/* C85ED0 80240420 1C400023 */  bgtz      $v0, .L802404B0
/* C85ED4 80240424 24020004 */   addiu    $v0, $zero, 4
/* C85ED8 80240428 8E0300CC */  lw        $v1, 0xcc($s0)
/* C85EDC 8024042C AE02006C */  sw        $v0, 0x6c($s0)
/* C85EE0 80240430 8C620000 */  lw        $v0, ($v1)
/* C85EE4 80240434 ACA20028 */  sw        $v0, 0x28($a1)
/* C85EE8 80240438 9602007A */  lhu       $v0, 0x7a($s0)
/* C85EEC 8024043C A4A2008E */  sh        $v0, 0x8e($a1)
/* C85EF0 80240440 8E020078 */  lw        $v0, 0x78($s0)
/* C85EF4 80240444 28420008 */  slti      $v0, $v0, 8
/* C85EF8 80240448 14400018 */  bnez      $v0, .L802404AC
/* C85EFC 8024044C 24020021 */   addiu    $v0, $zero, 0x21
/* C85F00 80240450 24040003 */  addiu     $a0, $zero, 3
/* C85F04 80240454 27A30028 */  addiu     $v1, $sp, 0x28
/* C85F08 80240458 84A700A8 */  lh        $a3, 0xa8($a1)
/* C85F0C 8024045C 3C013F80 */  lui       $at, 0x3f80
/* C85F10 80240460 44810000 */  mtc1      $at, $f0
/* C85F14 80240464 3C014000 */  lui       $at, 0x4000
/* C85F18 80240468 44811000 */  mtc1      $at, $f2
/* C85F1C 8024046C 3C01C1A0 */  lui       $at, 0xc1a0
/* C85F20 80240470 44812000 */  mtc1      $at, $f4
/* C85F24 80240474 44873000 */  mtc1      $a3, $f6
/* C85F28 80240478 00000000 */  nop       
/* C85F2C 8024047C 468031A0 */  cvt.s.w   $f6, $f6
/* C85F30 80240480 E7A00010 */  swc1      $f0, 0x10($sp)
/* C85F34 80240484 E7A20014 */  swc1      $f2, 0x14($sp)
/* C85F38 80240488 E7A40018 */  swc1      $f4, 0x18($sp)
/* C85F3C 8024048C 8E020078 */  lw        $v0, 0x78($s0)
/* C85F40 80240490 44073000 */  mfc1      $a3, $f6
/* C85F44 80240494 0000302D */  daddu     $a2, $zero, $zero
/* C85F48 80240498 AFA30020 */  sw        $v1, 0x20($sp)
/* C85F4C 8024049C 2442FFFF */  addiu     $v0, $v0, -1
/* C85F50 802404A0 0C01BFA4 */  jal       fx_emote
/* C85F54 802404A4 AFA2001C */   sw       $v0, 0x1c($sp)
/* C85F58 802404A8 24020021 */  addiu     $v0, $zero, 0x21
.L802404AC:
/* C85F5C 802404AC AE220070 */  sw        $v0, 0x70($s1)
.L802404B0:
/* C85F60 802404B0 8FBF0038 */  lw        $ra, 0x38($sp)
/* C85F64 802404B4 8FB10034 */  lw        $s1, 0x34($sp)
/* C85F68 802404B8 8FB00030 */  lw        $s0, 0x30($sp)
/* C85F6C 802404BC 03E00008 */  jr        $ra
/* C85F70 802404C0 27BD0040 */   addiu    $sp, $sp, 0x40
