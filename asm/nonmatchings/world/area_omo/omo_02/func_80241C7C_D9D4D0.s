.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C7C_D9F14C
/* D9F14C 80241C7C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D9F150 80241C80 AFB20038 */  sw        $s2, 0x38($sp)
/* D9F154 80241C84 0080902D */  daddu     $s2, $a0, $zero
/* D9F158 80241C88 AFBF003C */  sw        $ra, 0x3c($sp)
/* D9F15C 80241C8C AFB10034 */  sw        $s1, 0x34($sp)
/* D9F160 80241C90 AFB00030 */  sw        $s0, 0x30($sp)
/* D9F164 80241C94 8E510148 */  lw        $s1, 0x148($s2)
/* D9F168 80241C98 0C00EABB */  jal       get_npc_unsafe
/* D9F16C 80241C9C 86240008 */   lh       $a0, 8($s1)
/* D9F170 80241CA0 0040802D */  daddu     $s0, $v0, $zero
/* D9F174 80241CA4 9602008E */  lhu       $v0, 0x8e($s0)
/* D9F178 80241CA8 2442FFFF */  addiu     $v0, $v0, -1
/* D9F17C 80241CAC A602008E */  sh        $v0, 0x8e($s0)
/* D9F180 80241CB0 00021400 */  sll       $v0, $v0, 0x10
/* D9F184 80241CB4 1C40002B */  bgtz      $v0, .L80241D64
/* D9F188 80241CB8 00000000 */   nop      
/* D9F18C 80241CBC 0C090652 */  jal       func_80241948
/* D9F190 80241CC0 0240202D */   daddu    $a0, $s2, $zero
/* D9F194 80241CC4 0040202D */  daddu     $a0, $v0, $zero
/* D9F198 80241CC8 0481001A */  bgez      $a0, .L80241D34
/* D9F19C 80241CCC 2402000F */   addiu    $v0, $zero, 0xf
/* D9F1A0 80241CD0 24040002 */  addiu     $a0, $zero, 2
/* D9F1A4 80241CD4 860300A8 */  lh        $v1, 0xa8($s0)
/* D9F1A8 80241CD8 AFA2001C */  sw        $v0, 0x1c($sp)
/* D9F1AC 80241CDC 27A20028 */  addiu     $v0, $sp, 0x28
/* D9F1B0 80241CE0 0200282D */  daddu     $a1, $s0, $zero
/* D9F1B4 80241CE4 3C013F80 */  lui       $at, 0x3f80
/* D9F1B8 80241CE8 44810000 */  mtc1      $at, $f0
/* D9F1BC 80241CEC 3C014000 */  lui       $at, 0x4000
/* D9F1C0 80241CF0 44811000 */  mtc1      $at, $f2
/* D9F1C4 80241CF4 3C01C1A0 */  lui       $at, 0xc1a0
/* D9F1C8 80241CF8 44812000 */  mtc1      $at, $f4
/* D9F1CC 80241CFC 44833000 */  mtc1      $v1, $f6
/* D9F1D0 80241D00 00000000 */  nop       
/* D9F1D4 80241D04 468031A0 */  cvt.s.w   $f6, $f6
/* D9F1D8 80241D08 44073000 */  mfc1      $a3, $f6
/* D9F1DC 80241D0C 0000302D */  daddu     $a2, $zero, $zero
/* D9F1E0 80241D10 AFA20020 */  sw        $v0, 0x20($sp)
/* D9F1E4 80241D14 E7A00010 */  swc1      $f0, 0x10($sp)
/* D9F1E8 80241D18 E7A20014 */  swc1      $f2, 0x14($sp)
/* D9F1EC 80241D1C 0C01BFA4 */  jal       fx_emote
/* D9F1F0 80241D20 E7A40018 */   swc1     $f4, 0x18($sp)
/* D9F1F4 80241D24 8E2200CC */  lw        $v0, 0xcc($s1)
/* D9F1F8 80241D28 8C420000 */  lw        $v0, ($v0)
/* D9F1FC 80241D2C 08090755 */  j         .L80241D54
/* D9F200 80241D30 AE020028 */   sw       $v0, 0x28($s0)
.L80241D34:
/* D9F204 80241D34 8E2200CC */  lw        $v0, 0xcc($s1)
/* D9F208 80241D38 8C420024 */  lw        $v0, 0x24($v0)
/* D9F20C 80241D3C 0C00FB3A */  jal       get_enemy
/* D9F210 80241D40 AE020028 */   sw       $v0, 0x28($s0)
/* D9F214 80241D44 86240008 */  lh        $a0, 8($s1)
/* D9F218 80241D48 24030001 */  addiu     $v1, $zero, 1
/* D9F21C 80241D4C AC43006C */  sw        $v1, 0x6c($v0)
/* D9F220 80241D50 AC44007C */  sw        $a0, 0x7c($v0)
.L80241D54:
/* D9F224 80241D54 96220076 */  lhu       $v0, 0x76($s1)
/* D9F228 80241D58 A602008E */  sh        $v0, 0x8e($s0)
/* D9F22C 80241D5C 24020021 */  addiu     $v0, $zero, 0x21
/* D9F230 80241D60 AE420070 */  sw        $v0, 0x70($s2)
.L80241D64:
/* D9F234 80241D64 8FBF003C */  lw        $ra, 0x3c($sp)
/* D9F238 80241D68 8FB20038 */  lw        $s2, 0x38($sp)
/* D9F23C 80241D6C 8FB10034 */  lw        $s1, 0x34($sp)
/* D9F240 80241D70 8FB00030 */  lw        $s0, 0x30($sp)
/* D9F244 80241D74 03E00008 */  jr        $ra
/* D9F248 80241D78 27BD0040 */   addiu    $sp, $sp, 0x40
