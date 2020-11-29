.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241904_A1CA04
/* A1CA04 80241904 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1CA08 80241908 AFB00010 */  sw        $s0, 0x10($sp)
/* A1CA0C 8024190C 0080802D */  daddu     $s0, $a0, $zero
/* A1CA10 80241910 AFBF0014 */  sw        $ra, 0x14($sp)
/* A1CA14 80241914 8E020148 */  lw        $v0, 0x148($s0)
/* A1CA18 80241918 0C00EABB */  jal       get_npc_unsafe
/* A1CA1C 8024191C 84440008 */   lh       $a0, 8($v0)
/* A1CA20 80241920 9443008E */  lhu       $v1, 0x8e($v0)
/* A1CA24 80241924 C440003C */  lwc1      $f0, 0x3c($v0)
/* A1CA28 80241928 24640001 */  addiu     $a0, $v1, 1
/* A1CA2C 8024192C 00031C00 */  sll       $v1, $v1, 0x10
/* A1CA30 80241930 00031B83 */  sra       $v1, $v1, 0xe
/* A1CA34 80241934 A444008E */  sh        $a0, 0x8e($v0)
/* A1CA38 80241938 3C018024 */  lui       $at, %hi(D_802457F4)
/* A1CA3C 8024193C 00230821 */  addu      $at, $at, $v1
/* A1CA40 80241940 C42257F4 */  lwc1      $f2, %lo(D_802457F4)($at)
/* A1CA44 80241944 8443008E */  lh        $v1, 0x8e($v0)
/* A1CA48 80241948 46020000 */  add.s     $f0, $f0, $f2
/* A1CA4C 8024194C 28630005 */  slti      $v1, $v1, 5
/* A1CA50 80241950 14600003 */  bnez      $v1, .L80241960
/* A1CA54 80241954 E440003C */   swc1     $f0, 0x3c($v0)
/* A1CA58 80241958 2402000C */  addiu     $v0, $zero, 0xc
/* A1CA5C 8024195C AE020070 */  sw        $v0, 0x70($s0)
.L80241960:
/* A1CA60 80241960 8FBF0014 */  lw        $ra, 0x14($sp)
/* A1CA64 80241964 8FB00010 */  lw        $s0, 0x10($sp)
/* A1CA68 80241968 03E00008 */  jr        $ra
/* A1CA6C 8024196C 27BD0018 */   addiu    $sp, $sp, 0x18
