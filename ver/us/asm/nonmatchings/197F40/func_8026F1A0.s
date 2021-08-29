.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026F1A0
/* 19DA80 8026F1A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19DA84 8026F1A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 19DA88 8026F1A8 0080902D */  daddu     $s2, $a0, $zero
/* 19DA8C 8026F1AC AFBF001C */  sw        $ra, 0x1c($sp)
/* 19DA90 8026F1B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 19DA94 8026F1B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 19DA98 8026F1B8 8E50000C */  lw        $s0, 0xc($s2)
/* 19DA9C 8026F1BC 8E050000 */  lw        $a1, ($s0)
/* 19DAA0 8026F1C0 0C0B1EAF */  jal       evt_get_variable
/* 19DAA4 8026F1C4 26100004 */   addiu    $s0, $s0, 4
/* 19DAA8 8026F1C8 0040882D */  daddu     $s1, $v0, $zero
/* 19DAAC 8026F1CC 8E050000 */  lw        $a1, ($s0)
/* 19DAB0 8026F1D0 0C0B1EAF */  jal       evt_get_variable
/* 19DAB4 8026F1D4 0240202D */   daddu    $a0, $s2, $zero
/* 19DAB8 8026F1D8 0040802D */  daddu     $s0, $v0, $zero
/* 19DABC 8026F1DC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19DAC0 8026F1E0 16220002 */  bne       $s1, $v0, .L8026F1EC
/* 19DAC4 8026F1E4 00000000 */   nop
/* 19DAC8 8026F1E8 8E510148 */  lw        $s1, 0x148($s2)
.L8026F1EC:
/* 19DACC 8026F1EC 0C09A75B */  jal       get_actor
/* 19DAD0 8026F1F0 0220202D */   daddu    $a0, $s1, $zero
/* 19DAD4 8026F1F4 16000007 */  bnez      $s0, .L8026F214
/* 19DAD8 8026F1F8 0040202D */   daddu    $a0, $v0, $zero
/* 19DADC 8026F1FC 3C03F7FF */  lui       $v1, 0xf7ff
/* 19DAE0 8026F200 8C820000 */  lw        $v0, ($a0)
/* 19DAE4 8026F204 3463FFFF */  ori       $v1, $v1, 0xffff
/* 19DAE8 8026F208 00431024 */  and       $v0, $v0, $v1
/* 19DAEC 8026F20C 0C099B90 */  jal       func_80266E40
/* 19DAF0 8026F210 AC820000 */   sw       $v0, ($a0)
.L8026F214:
/* 19DAF4 8026F214 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19DAF8 8026F218 8FB20018 */  lw        $s2, 0x18($sp)
/* 19DAFC 8026F21C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19DB00 8026F220 8FB00010 */  lw        $s0, 0x10($sp)
/* 19DB04 8026F224 24020002 */  addiu     $v0, $zero, 2
/* 19DB08 8026F228 03E00008 */  jr        $ra
/* 19DB0C 8026F22C 27BD0020 */   addiu    $sp, $sp, 0x20
