.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404AC_D37CAC
/* D37CAC 802404AC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D37CB0 802404B0 AFB10034 */  sw        $s1, 0x34($sp)
/* D37CB4 802404B4 0080882D */  daddu     $s1, $a0, $zero
/* D37CB8 802404B8 AFBF0038 */  sw        $ra, 0x38($sp)
/* D37CBC 802404BC AFB00030 */  sw        $s0, 0x30($sp)
/* D37CC0 802404C0 8E300148 */  lw        $s0, 0x148($s1)
/* D37CC4 802404C4 0C00EABB */  jal       get_npc_unsafe
/* D37CC8 802404C8 86040008 */   lh       $a0, 8($s0)
/* D37CCC 802404CC 0040282D */  daddu     $a1, $v0, $zero
/* D37CD0 802404D0 94A2008E */  lhu       $v0, 0x8e($a1)
/* D37CD4 802404D4 2442FFFF */  addiu     $v0, $v0, -1
/* D37CD8 802404D8 A4A2008E */  sh        $v0, 0x8e($a1)
/* D37CDC 802404DC 00021400 */  sll       $v0, $v0, 0x10
/* D37CE0 802404E0 1C400023 */  bgtz      $v0, .L80240570
/* D37CE4 802404E4 24020004 */   addiu    $v0, $zero, 4
/* D37CE8 802404E8 8E0300CC */  lw        $v1, 0xcc($s0)
/* D37CEC 802404EC AE02006C */  sw        $v0, 0x6c($s0)
/* D37CF0 802404F0 8C620000 */  lw        $v0, ($v1)
/* D37CF4 802404F4 ACA20028 */  sw        $v0, 0x28($a1)
/* D37CF8 802404F8 9602007A */  lhu       $v0, 0x7a($s0)
/* D37CFC 802404FC A4A2008E */  sh        $v0, 0x8e($a1)
/* D37D00 80240500 8E020078 */  lw        $v0, 0x78($s0)
/* D37D04 80240504 28420008 */  slti      $v0, $v0, 8
/* D37D08 80240508 14400018 */  bnez      $v0, .L8024056C
/* D37D0C 8024050C 24020021 */   addiu    $v0, $zero, 0x21
/* D37D10 80240510 24040003 */  addiu     $a0, $zero, 3
/* D37D14 80240514 27A30028 */  addiu     $v1, $sp, 0x28
/* D37D18 80240518 84A700A8 */  lh        $a3, 0xa8($a1)
/* D37D1C 8024051C 3C013F80 */  lui       $at, 0x3f80
/* D37D20 80240520 44810000 */  mtc1      $at, $f0
/* D37D24 80240524 3C014000 */  lui       $at, 0x4000
/* D37D28 80240528 44811000 */  mtc1      $at, $f2
/* D37D2C 8024052C 3C01C1A0 */  lui       $at, 0xc1a0
/* D37D30 80240530 44812000 */  mtc1      $at, $f4
/* D37D34 80240534 44873000 */  mtc1      $a3, $f6
/* D37D38 80240538 00000000 */  nop       
/* D37D3C 8024053C 468031A0 */  cvt.s.w   $f6, $f6
/* D37D40 80240540 E7A00010 */  swc1      $f0, 0x10($sp)
/* D37D44 80240544 E7A20014 */  swc1      $f2, 0x14($sp)
/* D37D48 80240548 E7A40018 */  swc1      $f4, 0x18($sp)
/* D37D4C 8024054C 8E020078 */  lw        $v0, 0x78($s0)
/* D37D50 80240550 44073000 */  mfc1      $a3, $f6
/* D37D54 80240554 0000302D */  daddu     $a2, $zero, $zero
/* D37D58 80240558 AFA30020 */  sw        $v1, 0x20($sp)
/* D37D5C 8024055C 2442FFFF */  addiu     $v0, $v0, -1
/* D37D60 80240560 0C01BFA4 */  jal       fx_emote
/* D37D64 80240564 AFA2001C */   sw       $v0, 0x1c($sp)
/* D37D68 80240568 24020021 */  addiu     $v0, $zero, 0x21
.L8024056C:
/* D37D6C 8024056C AE220070 */  sw        $v0, 0x70($s1)
.L80240570:
/* D37D70 80240570 8FBF0038 */  lw        $ra, 0x38($sp)
/* D37D74 80240574 8FB10034 */  lw        $s1, 0x34($sp)
/* D37D78 80240578 8FB00030 */  lw        $s0, 0x30($sp)
/* D37D7C 8024057C 03E00008 */  jr        $ra
/* D37D80 80240580 27BD0040 */   addiu    $sp, $sp, 0x40
