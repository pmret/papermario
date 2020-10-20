.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C94_CF3864
/* CF3864 80240C94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF3868 80240C98 AFB00010 */  sw        $s0, 0x10($sp)
/* CF386C 80240C9C 0080802D */  daddu     $s0, $a0, $zero
/* CF3870 80240CA0 AFBF0014 */  sw        $ra, 0x14($sp)
/* CF3874 80240CA4 8E020148 */  lw        $v0, 0x148($s0)
/* CF3878 80240CA8 0C00EABB */  jal       get_npc_unsafe
/* CF387C 80240CAC 84440008 */   lh       $a0, 8($v0)
/* CF3880 80240CB0 9443008E */  lhu       $v1, 0x8e($v0)
/* CF3884 80240CB4 C440003C */  lwc1      $f0, 0x3c($v0)
/* CF3888 80240CB8 24640001 */  addiu     $a0, $v1, 1
/* CF388C 80240CBC 00031C00 */  sll       $v1, $v1, 0x10
/* CF3890 80240CC0 00031B83 */  sra       $v1, $v1, 0xe
/* CF3894 80240CC4 A444008E */  sh        $a0, 0x8e($v0)
/* CF3898 80240CC8 3C018024 */  lui       $at, 0x8024
/* CF389C 80240CCC 00230821 */  addu      $at, $at, $v1
/* CF38A0 80240CD0 C422291C */  lwc1      $f2, 0x291c($at)
/* CF38A4 80240CD4 8443008E */  lh        $v1, 0x8e($v0)
/* CF38A8 80240CD8 46020000 */  add.s     $f0, $f0, $f2
/* CF38AC 80240CDC 28630005 */  slti      $v1, $v1, 5
/* CF38B0 80240CE0 14600003 */  bnez      $v1, .L80240CF0
/* CF38B4 80240CE4 E440003C */   swc1     $f0, 0x3c($v0)
/* CF38B8 80240CE8 2402000C */  addiu     $v0, $zero, 0xc
/* CF38BC 80240CEC AE020070 */  sw        $v0, 0x70($s0)
.L80240CF0:
/* CF38C0 80240CF0 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF38C4 80240CF4 8FB00010 */  lw        $s0, 0x10($sp)
/* CF38C8 80240CF8 03E00008 */  jr        $ra
/* CF38CC 80240CFC 27BD0018 */   addiu    $sp, $sp, 0x18
