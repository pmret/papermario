.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240168_DEC038
/* DEC038 80240168 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DEC03C 8024016C AFB20018 */  sw        $s2, 0x18($sp)
/* DEC040 80240170 0080902D */  daddu     $s2, $a0, $zero
/* DEC044 80240174 AFBF001C */  sw        $ra, 0x1c($sp)
/* DEC048 80240178 AFB10014 */  sw        $s1, 0x14($sp)
/* DEC04C 8024017C AFB00010 */  sw        $s0, 0x10($sp)
/* DEC050 80240180 8E50000C */  lw        $s0, 0xc($s2)
/* DEC054 80240184 8E050000 */  lw        $a1, ($s0)
/* DEC058 80240188 0C0B1EAF */  jal       evt_get_variable
/* DEC05C 8024018C 26100004 */   addiu    $s0, $s0, 4
/* DEC060 80240190 8E050000 */  lw        $a1, ($s0)
/* DEC064 80240194 26100004 */  addiu     $s0, $s0, 4
/* DEC068 80240198 0240202D */  daddu     $a0, $s2, $zero
/* DEC06C 8024019C 0C0B1EAF */  jal       evt_get_variable
/* DEC070 802401A0 0040882D */   daddu    $s1, $v0, $zero
/* DEC074 802401A4 0240202D */  daddu     $a0, $s2, $zero
/* DEC078 802401A8 8E050000 */  lw        $a1, ($s0)
/* DEC07C 802401AC 0C0B1EAF */  jal       evt_get_variable
/* DEC080 802401B0 0040802D */   daddu    $s0, $v0, $zero
/* DEC084 802401B4 02020018 */  mult      $s0, $v0
/* DEC088 802401B8 24020002 */  addiu     $v0, $zero, 2
/* DEC08C 802401BC 8E430138 */  lw        $v1, 0x138($s2)
/* DEC090 802401C0 00003012 */  mflo      $a2
/* DEC094 802401C4 02268821 */  addu      $s1, $s1, $a2
/* DEC098 802401C8 00518804 */  sllv      $s1, $s1, $v0
/* DEC09C 802401CC 00711821 */  addu      $v1, $v1, $s1
/* DEC0A0 802401D0 AE430138 */  sw        $v1, 0x138($s2)
/* DEC0A4 802401D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* DEC0A8 802401D8 8FB20018 */  lw        $s2, 0x18($sp)
/* DEC0AC 802401DC 8FB10014 */  lw        $s1, 0x14($sp)
/* DEC0B0 802401E0 8FB00010 */  lw        $s0, 0x10($sp)
/* DEC0B4 802401E4 03E00008 */  jr        $ra
/* DEC0B8 802401E8 27BD0020 */   addiu    $sp, $sp, 0x20
