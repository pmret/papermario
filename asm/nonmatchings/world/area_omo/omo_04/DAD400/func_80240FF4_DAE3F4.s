.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FF4_DAE3F4
/* DAE3F4 80240FF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DAE3F8 80240FF8 AFB00010 */  sw        $s0, 0x10($sp)
/* DAE3FC 80240FFC 0080802D */  daddu     $s0, $a0, $zero
/* DAE400 80241000 AFBF0014 */  sw        $ra, 0x14($sp)
/* DAE404 80241004 8E020148 */  lw        $v0, 0x148($s0)
/* DAE408 80241008 0C00EABB */  jal       get_npc_unsafe
/* DAE40C 8024100C 84440008 */   lh       $a0, 8($v0)
/* DAE410 80241010 9443008E */  lhu       $v1, 0x8e($v0)
/* DAE414 80241014 C440003C */  lwc1      $f0, 0x3c($v0)
/* DAE418 80241018 24640001 */  addiu     $a0, $v1, 1
/* DAE41C 8024101C 00031C00 */  sll       $v1, $v1, 0x10
/* DAE420 80241020 00031B83 */  sra       $v1, $v1, 0xe
/* DAE424 80241024 A444008E */  sh        $a0, 0x8e($v0)
/* DAE428 80241028 3C018024 */  lui       $at, %hi(func_80242EF0_BE66A0)
/* DAE42C 8024102C 00230821 */  addu      $at, $at, $v1
/* DAE430 80241030 C4222EF0 */  lwc1      $f2, %lo(func_80242EF0_BE66A0)($at)
/* DAE434 80241034 8443008E */  lh        $v1, 0x8e($v0)
/* DAE438 80241038 46020000 */  add.s     $f0, $f0, $f2
/* DAE43C 8024103C 28630005 */  slti      $v1, $v1, 5
/* DAE440 80241040 14600003 */  bnez      $v1, .L80241050
/* DAE444 80241044 E440003C */   swc1     $f0, 0x3c($v0)
/* DAE448 80241048 2402000C */  addiu     $v0, $zero, 0xc
/* DAE44C 8024104C AE020070 */  sw        $v0, 0x70($s0)
.L80241050:
/* DAE450 80241050 8FBF0014 */  lw        $ra, 0x14($sp)
/* DAE454 80241054 8FB00010 */  lw        $s0, 0x10($sp)
/* DAE458 80241058 03E00008 */  jr        $ra
/* DAE45C 8024105C 27BD0018 */   addiu    $sp, $sp, 0x18
