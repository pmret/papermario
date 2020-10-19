.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403FC_89DB9C
/* 89DB9C 802403FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 89DBA0 80240400 AFB10014 */  sw        $s1, 0x14($sp)
/* 89DBA4 80240404 0080882D */  daddu     $s1, $a0, $zero
/* 89DBA8 80240408 AFBF001C */  sw        $ra, 0x1c($sp)
/* 89DBAC 8024040C AFB20018 */  sw        $s2, 0x18($sp)
/* 89DBB0 80240410 0C016AFA */  jal       get_current_map_header
/* 89DBB4 80240414 AFB00010 */   sw       $s0, 0x10($sp)
/* 89DBB8 80240418 0220202D */  daddu     $a0, $s1, $zero
/* 89DBBC 8024041C 3C05FE36 */  lui       $a1, 0xfe36
/* 89DBC0 80240420 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 89DBC4 80240424 0C0B1EAF */  jal       get_variable
/* 89DBC8 80240428 0040902D */   daddu    $s2, $v0, $zero
/* 89DBCC 8024042C 0220202D */  daddu     $a0, $s1, $zero
/* 89DBD0 80240430 3C05FE36 */  lui       $a1, 0xfe36
/* 89DBD4 80240434 8E430014 */  lw        $v1, 0x14($s2)
/* 89DBD8 80240438 00028100 */  sll       $s0, $v0, 4
/* 89DBDC 8024043C 02031821 */  addu      $v1, $s0, $v1
/* 89DBE0 80240440 C4600000 */  lwc1      $f0, ($v1)
/* 89DBE4 80240444 4600008D */  trunc.w.s $f2, $f0
/* 89DBE8 80240448 44061000 */  mfc1      $a2, $f2
/* 89DBEC 8024044C 0C0B2026 */  jal       set_variable
/* 89DBF0 80240450 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 89DBF4 80240454 0220202D */  daddu     $a0, $s1, $zero
/* 89DBF8 80240458 8E420014 */  lw        $v0, 0x14($s2)
/* 89DBFC 8024045C 3C05FE36 */  lui       $a1, 0xfe36
/* 89DC00 80240460 02021021 */  addu      $v0, $s0, $v0
/* 89DC04 80240464 C4400004 */  lwc1      $f0, 4($v0)
/* 89DC08 80240468 4600008D */  trunc.w.s $f2, $f0
/* 89DC0C 8024046C 44061000 */  mfc1      $a2, $f2
/* 89DC10 80240470 0C0B2026 */  jal       set_variable
/* 89DC14 80240474 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 89DC18 80240478 0220202D */  daddu     $a0, $s1, $zero
/* 89DC1C 8024047C 8E420014 */  lw        $v0, 0x14($s2)
/* 89DC20 80240480 3C05FE36 */  lui       $a1, 0xfe36
/* 89DC24 80240484 02021021 */  addu      $v0, $s0, $v0
/* 89DC28 80240488 C4400008 */  lwc1      $f0, 8($v0)
/* 89DC2C 8024048C 4600008D */  trunc.w.s $f2, $f0
/* 89DC30 80240490 44061000 */  mfc1      $a2, $f2
/* 89DC34 80240494 0C0B2026 */  jal       set_variable
/* 89DC38 80240498 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 89DC3C 8024049C 0220202D */  daddu     $a0, $s1, $zero
/* 89DC40 802404A0 8E420014 */  lw        $v0, 0x14($s2)
/* 89DC44 802404A4 3C05FE36 */  lui       $a1, 0xfe36
/* 89DC48 802404A8 02028021 */  addu      $s0, $s0, $v0
/* 89DC4C 802404AC C600000C */  lwc1      $f0, 0xc($s0)
/* 89DC50 802404B0 4600008D */  trunc.w.s $f2, $f0
/* 89DC54 802404B4 44061000 */  mfc1      $a2, $f2
/* 89DC58 802404B8 0C0B2026 */  jal       set_variable
/* 89DC5C 802404BC 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 89DC60 802404C0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 89DC64 802404C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 89DC68 802404C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 89DC6C 802404CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 89DC70 802404D0 24020002 */  addiu     $v0, $zero, 2
/* 89DC74 802404D4 03E00008 */  jr        $ra
/* 89DC78 802404D8 27BD0020 */   addiu    $sp, $sp, 0x20
