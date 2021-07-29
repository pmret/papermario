.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80241E90_8D5C50
.double 32767.0

.section .text

glabel func_80240000_8D3DC0
/* 8D3DC0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8D3DC4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D3DC8 80240008 0080802D */  daddu     $s0, $a0, $zero
/* 8D3DCC 8024000C AFBF001C */  sw        $ra, 0x1c($sp)
/* 8D3DD0 80240010 AFB20018 */  sw        $s2, 0x18($sp)
/* 8D3DD4 80240014 AFB10014 */  sw        $s1, 0x14($sp)
/* 8D3DD8 80240018 8E110148 */  lw        $s1, 0x148($s0)
/* 8D3DDC 8024001C 86240008 */  lh        $a0, 8($s1)
/* 8D3DE0 80240020 0C00EABB */  jal       get_npc_unsafe
/* 8D3DE4 80240024 00A0902D */   daddu    $s2, $a1, $zero
/* 8D3DE8 80240028 8E2300CC */  lw        $v1, 0xcc($s1)
/* 8D3DEC 8024002C 0040202D */  daddu     $a0, $v0, $zero
/* 8D3DF0 80240030 8C630000 */  lw        $v1, ($v1)
/* 8D3DF4 80240034 24020001 */  addiu     $v0, $zero, 1
/* 8D3DF8 80240038 AC830028 */  sw        $v1, 0x28($a0)
/* 8D3DFC 8024003C AE020070 */  sw        $v0, 0x70($s0)
/* 8D3E00 80240040 8E220000 */  lw        $v0, ($s1)
/* 8D3E04 80240044 3C030010 */  lui       $v1, 0x10
/* 8D3E08 80240048 00431024 */  and       $v0, $v0, $v1
/* 8D3E0C 8024004C 10400004 */  beqz      $v0, .L80240060
/* 8D3E10 80240050 00000000 */   nop
/* 8D3E14 80240054 C620006C */  lwc1      $f0, 0x6c($s1)
/* 8D3E18 80240058 46800020 */  cvt.s.w   $f0, $f0
/* 8D3E1C 8024005C E480000C */  swc1      $f0, 0xc($a0)
.L80240060:
/* 8D3E20 80240060 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8D3E24 80240064 8C420014 */  lw        $v0, 0x14($v0)
/* 8D3E28 80240068 1C400004 */  bgtz      $v0, .L8024007C
/* 8D3E2C 8024006C 00000000 */   nop
/* 8D3E30 80240070 C640000C */  lwc1      $f0, 0xc($s2)
/* 8D3E34 80240074 08090027 */  j         .L8024009C
/* 8D3E38 80240078 E4800018 */   swc1     $f0, 0x18($a0)
.L8024007C:
/* 8D3E3C 8024007C 3C018024 */  lui       $at, %hi(D_80241E90_8D5C50)
/* 8D3E40 80240080 D4221E90 */  ldc1      $f2, %lo(D_80241E90_8D5C50)($at)
/* 8D3E44 80240084 44820000 */  mtc1      $v0, $f0
/* 8D3E48 80240088 00000000 */  nop
/* 8D3E4C 8024008C 46800021 */  cvt.d.w   $f0, $f0
/* 8D3E50 80240090 46220003 */  div.d     $f0, $f0, $f2
/* 8D3E54 80240094 46200020 */  cvt.s.d   $f0, $f0
/* 8D3E58 80240098 E4800018 */  swc1      $f0, 0x18($a0)
.L8024009C:
/* 8D3E5C 8024009C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8D3E60 802400A0 8FB20018 */  lw        $s2, 0x18($sp)
/* 8D3E64 802400A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D3E68 802400A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D3E6C 802400AC 03E00008 */  jr        $ra
/* 8D3E70 802400B0 27BD0020 */   addiu    $sp, $sp, 0x20
