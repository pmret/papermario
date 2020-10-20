.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_A06FF0
/* A06FF0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A06FF4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* A06FF8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* A06FFC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* A07000 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* A07004 80240104 0C016AFA */  jal       get_current_map_header
/* A07008 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* A0700C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* A07010 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* A07014 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A07018 80240118 0C0B1EAF */  jal       get_variable
/* A0701C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* A07020 80240120 0220202D */  daddu     $a0, $s1, $zero
/* A07024 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* A07028 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* A0702C 8024012C 00028100 */  sll       $s0, $v0, 4
/* A07030 80240130 02031821 */  addu      $v1, $s0, $v1
/* A07034 80240134 C4600000 */  lwc1      $f0, ($v1)
/* A07038 80240138 4600008D */  trunc.w.s $f2, $f0
/* A0703C 8024013C 44061000 */  mfc1      $a2, $f2
/* A07040 80240140 0C0B2026 */  jal       set_variable
/* A07044 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* A07048 80240148 0220202D */  daddu     $a0, $s1, $zero
/* A0704C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* A07050 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* A07054 80240154 02021021 */  addu      $v0, $s0, $v0
/* A07058 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* A0705C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* A07060 80240160 44061000 */  mfc1      $a2, $f2
/* A07064 80240164 0C0B2026 */  jal       set_variable
/* A07068 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* A0706C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* A07070 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* A07074 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* A07078 80240178 02021021 */  addu      $v0, $s0, $v0
/* A0707C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* A07080 80240180 4600008D */  trunc.w.s $f2, $f0
/* A07084 80240184 44061000 */  mfc1      $a2, $f2
/* A07088 80240188 0C0B2026 */  jal       set_variable
/* A0708C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* A07090 80240190 0220202D */  daddu     $a0, $s1, $zero
/* A07094 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* A07098 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* A0709C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* A070A0 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* A070A4 802401A4 4600008D */  trunc.w.s $f2, $f0
/* A070A8 802401A8 44061000 */  mfc1      $a2, $f2
/* A070AC 802401AC 0C0B2026 */  jal       set_variable
/* A070B0 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* A070B4 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* A070B8 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* A070BC 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* A070C0 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* A070C4 802401C4 24020002 */  addiu     $v0, $zero, 2
/* A070C8 802401C8 03E00008 */  jr        $ra
/* A070CC 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
