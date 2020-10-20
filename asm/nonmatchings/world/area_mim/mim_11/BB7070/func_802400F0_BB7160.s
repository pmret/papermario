.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_BB7160
/* BB7160 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BB7164 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* BB7168 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* BB716C 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* BB7170 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* BB7174 80240104 0C016AFA */  jal       get_current_map_header
/* BB7178 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* BB717C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* BB7180 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* BB7184 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* BB7188 80240118 0C0B1EAF */  jal       get_variable
/* BB718C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* BB7190 80240120 0220202D */  daddu     $a0, $s1, $zero
/* BB7194 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* BB7198 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* BB719C 8024012C 00028100 */  sll       $s0, $v0, 4
/* BB71A0 80240130 02031821 */  addu      $v1, $s0, $v1
/* BB71A4 80240134 C4600000 */  lwc1      $f0, ($v1)
/* BB71A8 80240138 4600008D */  trunc.w.s $f2, $f0
/* BB71AC 8024013C 44061000 */  mfc1      $a2, $f2
/* BB71B0 80240140 0C0B2026 */  jal       set_variable
/* BB71B4 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* BB71B8 80240148 0220202D */  daddu     $a0, $s1, $zero
/* BB71BC 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* BB71C0 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* BB71C4 80240154 02021021 */  addu      $v0, $s0, $v0
/* BB71C8 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* BB71CC 8024015C 4600008D */  trunc.w.s $f2, $f0
/* BB71D0 80240160 44061000 */  mfc1      $a2, $f2
/* BB71D4 80240164 0C0B2026 */  jal       set_variable
/* BB71D8 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* BB71DC 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* BB71E0 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* BB71E4 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* BB71E8 80240178 02021021 */  addu      $v0, $s0, $v0
/* BB71EC 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* BB71F0 80240180 4600008D */  trunc.w.s $f2, $f0
/* BB71F4 80240184 44061000 */  mfc1      $a2, $f2
/* BB71F8 80240188 0C0B2026 */  jal       set_variable
/* BB71FC 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* BB7200 80240190 0220202D */  daddu     $a0, $s1, $zero
/* BB7204 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* BB7208 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* BB720C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* BB7210 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* BB7214 802401A4 4600008D */  trunc.w.s $f2, $f0
/* BB7218 802401A8 44061000 */  mfc1      $a2, $f2
/* BB721C 802401AC 0C0B2026 */  jal       set_variable
/* BB7220 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* BB7224 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* BB7228 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* BB722C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* BB7230 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* BB7234 802401C4 24020002 */  addiu     $v0, $zero, 2
/* BB7238 802401C8 03E00008 */  jr        $ra
/* BB723C 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
