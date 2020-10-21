.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419A8_B4C418
/* B4C418 802419A8 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B4C41C 802419AC AFB10034 */  sw        $s1, 0x34($sp)
/* B4C420 802419B0 0080882D */  daddu     $s1, $a0, $zero
/* B4C424 802419B4 AFBF0038 */  sw        $ra, 0x38($sp)
/* B4C428 802419B8 AFB00030 */  sw        $s0, 0x30($sp)
/* B4C42C 802419BC 8E300148 */  lw        $s0, 0x148($s1)
/* B4C430 802419C0 0C00EABB */  jal       get_npc_unsafe
/* B4C434 802419C4 86040008 */   lh       $a0, 8($s0)
/* B4C438 802419C8 0040282D */  daddu     $a1, $v0, $zero
/* B4C43C 802419CC 94A2008E */  lhu       $v0, 0x8e($a1)
/* B4C440 802419D0 2442FFFF */  addiu     $v0, $v0, -1
/* B4C444 802419D4 A4A2008E */  sh        $v0, 0x8e($a1)
/* B4C448 802419D8 00021400 */  sll       $v0, $v0, 0x10
/* B4C44C 802419DC 1C400023 */  bgtz      $v0, .L80241A6C
/* B4C450 802419E0 24020004 */   addiu    $v0, $zero, 4
/* B4C454 802419E4 8E0300CC */  lw        $v1, 0xcc($s0)
/* B4C458 802419E8 AE02006C */  sw        $v0, 0x6c($s0)
/* B4C45C 802419EC 8C620000 */  lw        $v0, ($v1)
/* B4C460 802419F0 ACA20028 */  sw        $v0, 0x28($a1)
/* B4C464 802419F4 9602007A */  lhu       $v0, 0x7a($s0)
/* B4C468 802419F8 A4A2008E */  sh        $v0, 0x8e($a1)
/* B4C46C 802419FC 8E020078 */  lw        $v0, 0x78($s0)
/* B4C470 80241A00 28420008 */  slti      $v0, $v0, 8
/* B4C474 80241A04 14400018 */  bnez      $v0, .L80241A68
/* B4C478 80241A08 24020021 */   addiu    $v0, $zero, 0x21
/* B4C47C 80241A0C 24040003 */  addiu     $a0, $zero, 3
/* B4C480 80241A10 27A30028 */  addiu     $v1, $sp, 0x28
/* B4C484 80241A14 84A700A8 */  lh        $a3, 0xa8($a1)
/* B4C488 80241A18 3C013F80 */  lui       $at, 0x3f80
/* B4C48C 80241A1C 44810000 */  mtc1      $at, $f0
/* B4C490 80241A20 3C014000 */  lui       $at, 0x4000
/* B4C494 80241A24 44811000 */  mtc1      $at, $f2
/* B4C498 80241A28 3C01C1A0 */  lui       $at, 0xc1a0
/* B4C49C 80241A2C 44812000 */  mtc1      $at, $f4
/* B4C4A0 80241A30 44873000 */  mtc1      $a3, $f6
/* B4C4A4 80241A34 00000000 */  nop       
/* B4C4A8 80241A38 468031A0 */  cvt.s.w   $f6, $f6
/* B4C4AC 80241A3C E7A00010 */  swc1      $f0, 0x10($sp)
/* B4C4B0 80241A40 E7A20014 */  swc1      $f2, 0x14($sp)
/* B4C4B4 80241A44 E7A40018 */  swc1      $f4, 0x18($sp)
/* B4C4B8 80241A48 8E020078 */  lw        $v0, 0x78($s0)
/* B4C4BC 80241A4C 44073000 */  mfc1      $a3, $f6
/* B4C4C0 80241A50 0000302D */  daddu     $a2, $zero, $zero
/* B4C4C4 80241A54 AFA30020 */  sw        $v1, 0x20($sp)
/* B4C4C8 80241A58 2442FFFF */  addiu     $v0, $v0, -1
/* B4C4CC 80241A5C 0C01BFA4 */  jal       fx_emote
/* B4C4D0 80241A60 AFA2001C */   sw       $v0, 0x1c($sp)
/* B4C4D4 80241A64 24020021 */  addiu     $v0, $zero, 0x21
.L80241A68:
/* B4C4D8 80241A68 AE220070 */  sw        $v0, 0x70($s1)
.L80241A6C:
/* B4C4DC 80241A6C 8FBF0038 */  lw        $ra, 0x38($sp)
/* B4C4E0 80241A70 8FB10034 */  lw        $s1, 0x34($sp)
/* B4C4E4 80241A74 8FB00030 */  lw        $s0, 0x30($sp)
/* B4C4E8 80241A78 03E00008 */  jr        $ra
/* B4C4EC 80241A7C 27BD0040 */   addiu    $sp, $sp, 0x40
