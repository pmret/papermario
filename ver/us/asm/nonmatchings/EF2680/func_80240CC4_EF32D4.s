.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CC4_EF32D4
/* EF32D4 80240CC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EF32D8 80240CC8 AFB00010 */  sw        $s0, 0x10($sp)
/* EF32DC 80240CCC 0080802D */  daddu     $s0, $a0, $zero
/* EF32E0 80240CD0 AFBF0014 */  sw        $ra, 0x14($sp)
/* EF32E4 80240CD4 8E020148 */  lw        $v0, 0x148($s0)
/* EF32E8 80240CD8 0C00F92F */  jal       func_8003E4BC
/* EF32EC 80240CDC 84440008 */   lh       $a0, 8($v0)
/* EF32F0 80240CE0 9443008E */  lhu       $v1, 0x8e($v0)
/* EF32F4 80240CE4 C440003C */  lwc1      $f0, 0x3c($v0)
/* EF32F8 80240CE8 24640001 */  addiu     $a0, $v1, 1
/* EF32FC 80240CEC 00031C00 */  sll       $v1, $v1, 0x10
/* EF3300 80240CF0 00031B83 */  sra       $v1, $v1, 0xe
/* EF3304 80240CF4 A444008E */  sh        $a0, 0x8e($v0)
/* EF3308 80240CF8 3C018024 */  lui       $at, %hi(D_802444BC_EF6ACC)
/* EF330C 80240CFC 00230821 */  addu      $at, $at, $v1
/* EF3310 80240D00 C42244BC */  lwc1      $f2, %lo(D_802444BC_EF6ACC)($at)
/* EF3314 80240D04 8443008E */  lh        $v1, 0x8e($v0)
/* EF3318 80240D08 46020000 */  add.s     $f0, $f0, $f2
/* EF331C 80240D0C 28630005 */  slti      $v1, $v1, 5
/* EF3320 80240D10 14600003 */  bnez      $v1, .L80240D20
/* EF3324 80240D14 E440003C */   swc1     $f0, 0x3c($v0)
/* EF3328 80240D18 2402000C */  addiu     $v0, $zero, 0xc
/* EF332C 80240D1C AE020070 */  sw        $v0, 0x70($s0)
.L80240D20:
/* EF3330 80240D20 8FBF0014 */  lw        $ra, 0x14($sp)
/* EF3334 80240D24 8FB00010 */  lw        $s0, 0x10($sp)
/* EF3338 80240D28 03E00008 */  jr        $ra
/* EF333C 80240D2C 27BD0018 */   addiu    $sp, $sp, 0x18
