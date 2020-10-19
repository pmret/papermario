.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_D11110
/* D11110 80240050 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D11114 80240054 AFB10014 */  sw        $s1, 0x14($sp)
/* D11118 80240058 0080882D */  daddu     $s1, $a0, $zero
/* D1111C 8024005C AFBF0018 */  sw        $ra, 0x18($sp)
/* D11120 80240060 AFB00010 */  sw        $s0, 0x10($sp)
/* D11124 80240064 8E300148 */  lw        $s0, 0x148($s1)
/* D11128 80240068 0C00EABB */  jal       get_npc_unsafe
/* D1112C 8024006C 86040008 */   lh       $a0, 8($s0)
/* D11130 80240070 24030001 */  addiu     $v1, $zero, 1
/* D11134 80240074 0040202D */  daddu     $a0, $v0, $zero
/* D11138 80240078 AE03006C */  sw        $v1, 0x6c($s0)
/* D1113C 8024007C 8482008C */  lh        $v0, 0x8c($a0)
/* D11140 80240080 14400009 */  bnez      $v0, .L802400A8
/* D11144 80240084 24020002 */   addiu    $v0, $zero, 2
/* D11148 80240088 96030072 */  lhu       $v1, 0x72($s0)
/* D1114C 8024008C AE02006C */  sw        $v0, 0x6c($s0)
/* D11150 80240090 A483008E */  sh        $v1, 0x8e($a0)
/* D11154 80240094 8E0200CC */  lw        $v0, 0xcc($s0)
/* D11158 80240098 8C420020 */  lw        $v0, 0x20($v0)
/* D1115C 8024009C AC820028 */  sw        $v0, 0x28($a0)
/* D11160 802400A0 2402001F */  addiu     $v0, $zero, 0x1f
/* D11164 802400A4 AE220070 */  sw        $v0, 0x70($s1)
.L802400A8:
/* D11168 802400A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* D1116C 802400AC 8FB10014 */  lw        $s1, 0x14($sp)
/* D11170 802400B0 8FB00010 */  lw        $s0, 0x10($sp)
/* D11174 802400B4 03E00008 */  jr        $ra
/* D11178 802400B8 27BD0020 */   addiu    $sp, $sp, 0x20
