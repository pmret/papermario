.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_9D7110
/* 9D7110 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D7114 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D7118 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 9D711C 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 9D7120 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 9D7124 80240104 0C016AFA */  jal       get_current_map_header
/* 9D7128 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 9D712C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 9D7130 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 9D7134 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 9D7138 80240118 0C0B1EAF */  jal       get_variable
/* 9D713C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 9D7140 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 9D7144 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 9D7148 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 9D714C 8024012C 00028100 */  sll       $s0, $v0, 4
/* 9D7150 80240130 02031821 */  addu      $v1, $s0, $v1
/* 9D7154 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 9D7158 80240138 4600008D */  trunc.w.s $f2, $f0
/* 9D715C 8024013C 44061000 */  mfc1      $a2, $f2
/* 9D7160 80240140 0C0B2026 */  jal       set_variable
/* 9D7164 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 9D7168 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 9D716C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 9D7170 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 9D7174 80240154 02021021 */  addu      $v0, $s0, $v0
/* 9D7178 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 9D717C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 9D7180 80240160 44061000 */  mfc1      $a2, $f2
/* 9D7184 80240164 0C0B2026 */  jal       set_variable
/* 9D7188 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 9D718C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 9D7190 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 9D7194 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 9D7198 80240178 02021021 */  addu      $v0, $s0, $v0
/* 9D719C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 9D71A0 80240180 4600008D */  trunc.w.s $f2, $f0
/* 9D71A4 80240184 44061000 */  mfc1      $a2, $f2
/* 9D71A8 80240188 0C0B2026 */  jal       set_variable
/* 9D71AC 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 9D71B0 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 9D71B4 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 9D71B8 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 9D71BC 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 9D71C0 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 9D71C4 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 9D71C8 802401A8 44061000 */  mfc1      $a2, $f2
/* 9D71CC 802401AC 0C0B2026 */  jal       set_variable
/* 9D71D0 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 9D71D4 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9D71D8 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 9D71DC 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D71E0 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D71E4 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 9D71E8 802401C8 03E00008 */  jr        $ra
/* 9D71EC 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
