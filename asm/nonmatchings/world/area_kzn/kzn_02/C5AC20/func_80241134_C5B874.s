.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241134_C5B874
/* C5B874 80241134 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5B878 80241138 AFB00010 */  sw        $s0, 0x10($sp)
/* C5B87C 8024113C 0080802D */  daddu     $s0, $a0, $zero
/* C5B880 80241140 AFBF0014 */  sw        $ra, 0x14($sp)
/* C5B884 80241144 8E020148 */  lw        $v0, 0x148($s0)
/* C5B888 80241148 0C00EABB */  jal       get_npc_unsafe
/* C5B88C 8024114C 84440008 */   lh       $a0, 8($v0)
/* C5B890 80241150 9443008E */  lhu       $v1, 0x8e($v0)
/* C5B894 80241154 C440003C */  lwc1      $f0, 0x3c($v0)
/* C5B898 80241158 24640001 */  addiu     $a0, $v1, 1
/* C5B89C 8024115C 00031C00 */  sll       $v1, $v1, 0x10
/* C5B8A0 80241160 00031B83 */  sra       $v1, $v1, 0xe
/* C5B8A4 80241164 A444008E */  sh        $a0, 0x8e($v0)
/* C5B8A8 80241168 3C018024 */  lui       $at, %hi(D_80244900)
/* C5B8AC 8024116C 00230821 */  addu      $at, $at, $v1
/* C5B8B0 80241170 C4224900 */  lwc1      $f2, %lo(D_80244900)($at)
/* C5B8B4 80241174 8443008E */  lh        $v1, 0x8e($v0)
/* C5B8B8 80241178 46020000 */  add.s     $f0, $f0, $f2
/* C5B8BC 8024117C 28630005 */  slti      $v1, $v1, 5
/* C5B8C0 80241180 14600003 */  bnez      $v1, .L80241190
/* C5B8C4 80241184 E440003C */   swc1     $f0, 0x3c($v0)
/* C5B8C8 80241188 2402000C */  addiu     $v0, $zero, 0xc
/* C5B8CC 8024118C AE020070 */  sw        $v0, 0x70($s0)
.L80241190:
/* C5B8D0 80241190 8FBF0014 */  lw        $ra, 0x14($sp)
/* C5B8D4 80241194 8FB00010 */  lw        $s0, 0x10($sp)
/* C5B8D8 80241198 03E00008 */  jr        $ra
/* C5B8DC 8024119C 27BD0018 */   addiu    $sp, $sp, 0x18
