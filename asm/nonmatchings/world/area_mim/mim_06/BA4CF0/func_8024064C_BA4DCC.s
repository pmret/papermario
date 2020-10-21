.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024064C_BA4DCC
/* BA4DCC 8024064C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* BA4DD0 80240650 AFB10034 */  sw        $s1, 0x34($sp)
/* BA4DD4 80240654 0080882D */  daddu     $s1, $a0, $zero
/* BA4DD8 80240658 AFBF0038 */  sw        $ra, 0x38($sp)
/* BA4DDC 8024065C AFB00030 */  sw        $s0, 0x30($sp)
/* BA4DE0 80240660 8E300148 */  lw        $s0, 0x148($s1)
/* BA4DE4 80240664 0C00EABB */  jal       get_npc_unsafe
/* BA4DE8 80240668 86040008 */   lh       $a0, 8($s0)
/* BA4DEC 8024066C 0040282D */  daddu     $a1, $v0, $zero
/* BA4DF0 80240670 94A2008E */  lhu       $v0, 0x8e($a1)
/* BA4DF4 80240674 2442FFFF */  addiu     $v0, $v0, -1
/* BA4DF8 80240678 A4A2008E */  sh        $v0, 0x8e($a1)
/* BA4DFC 8024067C 00021400 */  sll       $v0, $v0, 0x10
/* BA4E00 80240680 1C400023 */  bgtz      $v0, .L80240710
/* BA4E04 80240684 24020004 */   addiu    $v0, $zero, 4
/* BA4E08 80240688 8E0300CC */  lw        $v1, 0xcc($s0)
/* BA4E0C 8024068C AE02006C */  sw        $v0, 0x6c($s0)
/* BA4E10 80240690 8C620000 */  lw        $v0, ($v1)
/* BA4E14 80240694 ACA20028 */  sw        $v0, 0x28($a1)
/* BA4E18 80240698 9602007A */  lhu       $v0, 0x7a($s0)
/* BA4E1C 8024069C A4A2008E */  sh        $v0, 0x8e($a1)
/* BA4E20 802406A0 8E020078 */  lw        $v0, 0x78($s0)
/* BA4E24 802406A4 28420008 */  slti      $v0, $v0, 8
/* BA4E28 802406A8 14400018 */  bnez      $v0, .L8024070C
/* BA4E2C 802406AC 24020021 */   addiu    $v0, $zero, 0x21
/* BA4E30 802406B0 24040003 */  addiu     $a0, $zero, 3
/* BA4E34 802406B4 27A30028 */  addiu     $v1, $sp, 0x28
/* BA4E38 802406B8 84A700A8 */  lh        $a3, 0xa8($a1)
/* BA4E3C 802406BC 3C013F80 */  lui       $at, 0x3f80
/* BA4E40 802406C0 44810000 */  mtc1      $at, $f0
/* BA4E44 802406C4 3C014000 */  lui       $at, 0x4000
/* BA4E48 802406C8 44811000 */  mtc1      $at, $f2
/* BA4E4C 802406CC 3C01C1A0 */  lui       $at, 0xc1a0
/* BA4E50 802406D0 44812000 */  mtc1      $at, $f4
/* BA4E54 802406D4 44873000 */  mtc1      $a3, $f6
/* BA4E58 802406D8 00000000 */  nop       
/* BA4E5C 802406DC 468031A0 */  cvt.s.w   $f6, $f6
/* BA4E60 802406E0 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA4E64 802406E4 E7A20014 */  swc1      $f2, 0x14($sp)
/* BA4E68 802406E8 E7A40018 */  swc1      $f4, 0x18($sp)
/* BA4E6C 802406EC 8E020078 */  lw        $v0, 0x78($s0)
/* BA4E70 802406F0 44073000 */  mfc1      $a3, $f6
/* BA4E74 802406F4 0000302D */  daddu     $a2, $zero, $zero
/* BA4E78 802406F8 AFA30020 */  sw        $v1, 0x20($sp)
/* BA4E7C 802406FC 2442FFFF */  addiu     $v0, $v0, -1
/* BA4E80 80240700 0C01BFA4 */  jal       fx_emote
/* BA4E84 80240704 AFA2001C */   sw       $v0, 0x1c($sp)
/* BA4E88 80240708 24020021 */  addiu     $v0, $zero, 0x21
.L8024070C:
/* BA4E8C 8024070C AE220070 */  sw        $v0, 0x70($s1)
.L80240710:
/* BA4E90 80240710 8FBF0038 */  lw        $ra, 0x38($sp)
/* BA4E94 80240714 8FB10034 */  lw        $s1, 0x34($sp)
/* BA4E98 80240718 8FB00030 */  lw        $s0, 0x30($sp)
/* BA4E9C 8024071C 03E00008 */  jr        $ra
/* BA4EA0 80240720 27BD0040 */   addiu    $sp, $sp, 0x40
