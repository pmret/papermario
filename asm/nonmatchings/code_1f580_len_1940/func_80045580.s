.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045580
/* 20980 80045580 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20984 80045584 AFB00010 */  sw        $s0, 0x10($sp)
/* 20988 80045588 0080802D */  daddu     $s0, $a0, $zero
/* 2098C 8004558C AFBF001C */  sw        $ra, 0x1c($sp)
/* 20990 80045590 AFB20018 */  sw        $s2, 0x18($sp)
/* 20994 80045594 AFB10014 */  sw        $s1, 0x14($sp)
/* 20998 80045598 8E04014C */  lw        $a0, 0x14c($s0)
/* 2099C 8004559C 8E12000C */  lw        $s2, 0xc($s0)
/* 209A0 800455A0 0C00EABB */  jal       get_npc_unsafe
/* 209A4 800455A4 8E110148 */   lw       $s1, 0x148($s0)
/* 209A8 800455A8 0200202D */  daddu     $a0, $s0, $zero
/* 209AC 800455AC 8E450000 */  lw        $a1, ($s2)
/* 209B0 800455B0 0C0B1EAF */  jal       get_variable
/* 209B4 800455B4 0040802D */   daddu    $s0, $v0, $zero
/* 209B8 800455B8 A2220007 */  sb        $v0, 7($s1)
/* 209BC 800455BC C6000038 */  lwc1      $f0, 0x38($s0)
/* 209C0 800455C0 4600008D */  trunc.w.s $f2, $f0
/* 209C4 800455C4 44021000 */  mfc1      $v0, $f2
/* 209C8 800455C8 00000000 */  nop       
/* 209CC 800455CC A6220010 */  sh        $v0, 0x10($s1)
/* 209D0 800455D0 C600003C */  lwc1      $f0, 0x3c($s0)
/* 209D4 800455D4 4600008D */  trunc.w.s $f2, $f0
/* 209D8 800455D8 44021000 */  mfc1      $v0, $f2
/* 209DC 800455DC 00000000 */  nop       
/* 209E0 800455E0 A6220012 */  sh        $v0, 0x12($s1)
/* 209E4 800455E4 C6000040 */  lwc1      $f0, 0x40($s0)
/* 209E8 800455E8 4600008D */  trunc.w.s $f2, $f0
/* 209EC 800455EC 44031000 */  mfc1      $v1, $f2
/* 209F0 800455F0 00000000 */  nop       
/* 209F4 800455F4 A6230014 */  sh        $v1, 0x14($s1)
/* 209F8 800455F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 209FC 800455FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 20A00 80045600 8FB10014 */  lw        $s1, 0x14($sp)
/* 20A04 80045604 8FB00010 */  lw        $s0, 0x10($sp)
/* 20A08 80045608 24020002 */  addiu     $v0, $zero, 2
/* 20A0C 8004560C 03E00008 */  jr        $ra
/* 20A10 80045610 27BD0020 */   addiu    $sp, $sp, 0x20
