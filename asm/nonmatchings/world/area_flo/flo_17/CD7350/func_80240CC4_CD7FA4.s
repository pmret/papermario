.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CC4_CD7FA4
/* CD7FA4 80240CC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CD7FA8 80240CC8 AFB00010 */  sw        $s0, 0x10($sp)
/* CD7FAC 80240CCC 0080802D */  daddu     $s0, $a0, $zero
/* CD7FB0 80240CD0 AFBF0014 */  sw        $ra, 0x14($sp)
/* CD7FB4 80240CD4 8E020148 */  lw        $v0, 0x148($s0)
/* CD7FB8 80240CD8 0C00EABB */  jal       get_npc_unsafe
/* CD7FBC 80240CDC 84440008 */   lh       $a0, 8($v0)
/* CD7FC0 80240CE0 9443008E */  lhu       $v1, 0x8e($v0)
/* CD7FC4 80240CE4 C440003C */  lwc1      $f0, 0x3c($v0)
/* CD7FC8 80240CE8 24640001 */  addiu     $a0, $v1, 1
/* CD7FCC 80240CEC 00031C00 */  sll       $v1, $v1, 0x10
/* CD7FD0 80240CF0 00031B83 */  sra       $v1, $v1, 0xe
/* CD7FD4 80240CF4 A444008E */  sh        $a0, 0x8e($v0)
/* CD7FD8 80240CF8 3C018024 */  lui       $at, %hi(D_8024440C)
/* CD7FDC 80240CFC 00230821 */  addu      $at, $at, $v1
/* CD7FE0 80240D00 C422440C */  lwc1      $f2, %lo(D_8024440C)($at)
/* CD7FE4 80240D04 8443008E */  lh        $v1, 0x8e($v0)
/* CD7FE8 80240D08 46020000 */  add.s     $f0, $f0, $f2
/* CD7FEC 80240D0C 28630005 */  slti      $v1, $v1, 5
/* CD7FF0 80240D10 14600003 */  bnez      $v1, .L80240D20
/* CD7FF4 80240D14 E440003C */   swc1     $f0, 0x3c($v0)
/* CD7FF8 80240D18 2402000C */  addiu     $v0, $zero, 0xc
/* CD7FFC 80240D1C AE020070 */  sw        $v0, 0x70($s0)
.L80240D20:
/* CD8000 80240D20 8FBF0014 */  lw        $ra, 0x14($sp)
/* CD8004 80240D24 8FB00010 */  lw        $s0, 0x10($sp)
/* CD8008 80240D28 03E00008 */  jr        $ra
/* CD800C 80240D2C 27BD0018 */   addiu    $sp, $sp, 0x18
