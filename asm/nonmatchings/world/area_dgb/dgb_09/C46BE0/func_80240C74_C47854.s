.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C74_C47854
/* C47854 80240C74 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C47858 80240C78 AFB10014 */  sw        $s1, 0x14($sp)
/* C4785C 80240C7C 0080882D */  daddu     $s1, $a0, $zero
/* C47860 80240C80 AFBF001C */  sw        $ra, 0x1c($sp)
/* C47864 80240C84 AFB20018 */  sw        $s2, 0x18($sp)
/* C47868 80240C88 AFB00010 */  sw        $s0, 0x10($sp)
/* C4786C 80240C8C 8E320148 */  lw        $s2, 0x148($s1)
/* C47870 80240C90 0C00EABB */  jal       get_npc_unsafe
/* C47874 80240C94 86440008 */   lh       $a0, 8($s2)
/* C47878 80240C98 240400B4 */  addiu     $a0, $zero, 0xb4
/* C4787C 80240C9C 0C00A67F */  jal       rand_int
/* C47880 80240CA0 0040802D */   daddu    $s0, $v0, $zero
/* C47884 80240CA4 C60C000C */  lwc1      $f12, 0xc($s0)
/* C47888 80240CA8 44820000 */  mtc1      $v0, $f0
/* C4788C 80240CAC 00000000 */  nop       
/* C47890 80240CB0 46800020 */  cvt.s.w   $f0, $f0
/* C47894 80240CB4 46006300 */  add.s     $f12, $f12, $f0
/* C47898 80240CB8 3C0142B4 */  lui       $at, 0x42b4
/* C4789C 80240CBC 44810000 */  mtc1      $at, $f0
/* C478A0 80240CC0 0C00A6C9 */  jal       clamp_angle
/* C478A4 80240CC4 46006301 */   sub.s    $f12, $f12, $f0
/* C478A8 80240CC8 E600000C */  swc1      $f0, 0xc($s0)
/* C478AC 80240CCC 8E4200CC */  lw        $v0, 0xcc($s2)
/* C478B0 80240CD0 8C420000 */  lw        $v0, ($v0)
/* C478B4 80240CD4 240403E8 */  addiu     $a0, $zero, 0x3e8
/* C478B8 80240CD8 0C00A67F */  jal       rand_int
/* C478BC 80240CDC AE020028 */   sw       $v0, 0x28($s0)
/* C478C0 80240CE0 00021FC2 */  srl       $v1, $v0, 0x1f
/* C478C4 80240CE4 00431821 */  addu      $v1, $v0, $v1
/* C478C8 80240CE8 00031843 */  sra       $v1, $v1, 1
/* C478CC 80240CEC 00031840 */  sll       $v1, $v1, 1
/* C478D0 80240CF0 00431023 */  subu      $v0, $v0, $v1
/* C478D4 80240CF4 24420002 */  addiu     $v0, $v0, 2
/* C478D8 80240CF8 AE220074 */  sw        $v0, 0x74($s1)
/* C478DC 80240CFC 24020004 */  addiu     $v0, $zero, 4
/* C478E0 80240D00 AE220070 */  sw        $v0, 0x70($s1)
/* C478E4 80240D04 8FBF001C */  lw        $ra, 0x1c($sp)
/* C478E8 80240D08 8FB20018 */  lw        $s2, 0x18($sp)
/* C478EC 80240D0C 8FB10014 */  lw        $s1, 0x14($sp)
/* C478F0 80240D10 8FB00010 */  lw        $s0, 0x10($sp)
/* C478F4 80240D14 03E00008 */  jr        $ra
/* C478F8 80240D18 27BD0020 */   addiu    $sp, $sp, 0x20
