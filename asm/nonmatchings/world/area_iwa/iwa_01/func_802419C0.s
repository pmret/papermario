.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419C0
/* 911070 802419C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 911074 802419C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 911078 802419C8 0080882D */  daddu     $s1, $a0, $zero
/* 91107C 802419CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 911080 802419D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 911084 802419D4 8E300148 */  lw        $s0, 0x148($s1)
/* 911088 802419D8 0C00EABB */  jal       get_npc_unsafe
/* 91108C 802419DC 86040008 */   lh       $a0, 8($s0)
/* 911090 802419E0 0040202D */  daddu     $a0, $v0, $zero
/* 911094 802419E4 9482008E */  lhu       $v0, 0x8e($a0)
/* 911098 802419E8 24030002 */  addiu     $v1, $zero, 2
/* 91109C 802419EC 2442FFFF */  addiu     $v0, $v0, -1
/* 9110A0 802419F0 A482008E */  sh        $v0, 0x8e($a0)
/* 9110A4 802419F4 00021400 */  sll       $v0, $v0, 0x10
/* 9110A8 802419F8 00021403 */  sra       $v0, $v0, 0x10
/* 9110AC 802419FC 14430005 */  bne       $v0, $v1, .L80241A14
/* 9110B0 80241A00 3C03E0EF */   lui      $v1, 0xe0ef
/* 9110B4 80241A04 8E020000 */  lw        $v0, ($s0)
/* 9110B8 80241A08 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9110BC 80241A0C 00431024 */  and       $v0, $v0, $v1
/* 9110C0 80241A10 AE020000 */  sw        $v0, ($s0)
.L80241A14:
/* 9110C4 80241A14 8482008E */  lh        $v0, 0x8e($a0)
/* 9110C8 80241A18 1C400007 */  bgtz      $v0, .L80241A38
/* 9110CC 80241A1C 3C02002F */   lui      $v0, 0x2f
/* 9110D0 80241A20 34420018 */  ori       $v0, $v0, 0x18
/* 9110D4 80241A24 AC820028 */  sw        $v0, 0x28($a0)
/* 9110D8 80241A28 2402000A */  addiu     $v0, $zero, 0xa
/* 9110DC 80241A2C A482008E */  sh        $v0, 0x8e($a0)
/* 9110E0 80241A30 2402000E */  addiu     $v0, $zero, 0xe
/* 9110E4 80241A34 AE220070 */  sw        $v0, 0x70($s1)
.L80241A38:
/* 9110E8 80241A38 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9110EC 80241A3C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9110F0 80241A40 8FB00010 */  lw        $s0, 0x10($sp)
/* 9110F4 80241A44 03E00008 */  jr        $ra
/* 9110F8 80241A48 27BD0020 */   addiu    $sp, $sp, 0x20
