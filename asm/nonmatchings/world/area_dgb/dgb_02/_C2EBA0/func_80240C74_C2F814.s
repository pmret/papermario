.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C74_C2F814
/* C2F814 80240C74 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C2F818 80240C78 AFB10014 */  sw        $s1, 0x14($sp)
/* C2F81C 80240C7C 0080882D */  daddu     $s1, $a0, $zero
/* C2F820 80240C80 AFBF001C */  sw        $ra, 0x1c($sp)
/* C2F824 80240C84 AFB20018 */  sw        $s2, 0x18($sp)
/* C2F828 80240C88 AFB00010 */  sw        $s0, 0x10($sp)
/* C2F82C 80240C8C 8E320148 */  lw        $s2, 0x148($s1)
/* C2F830 80240C90 0C00EABB */  jal       get_npc_unsafe
/* C2F834 80240C94 86440008 */   lh       $a0, 8($s2)
/* C2F838 80240C98 240400B4 */  addiu     $a0, $zero, 0xb4
/* C2F83C 80240C9C 0C00A67F */  jal       rand_int
/* C2F840 80240CA0 0040802D */   daddu    $s0, $v0, $zero
/* C2F844 80240CA4 C60C000C */  lwc1      $f12, 0xc($s0)
/* C2F848 80240CA8 44820000 */  mtc1      $v0, $f0
/* C2F84C 80240CAC 00000000 */  nop       
/* C2F850 80240CB0 46800020 */  cvt.s.w   $f0, $f0
/* C2F854 80240CB4 46006300 */  add.s     $f12, $f12, $f0
/* C2F858 80240CB8 3C0142B4 */  lui       $at, 0x42b4
/* C2F85C 80240CBC 44810000 */  mtc1      $at, $f0
/* C2F860 80240CC0 0C00A6C9 */  jal       clamp_angle
/* C2F864 80240CC4 46006301 */   sub.s    $f12, $f12, $f0
/* C2F868 80240CC8 E600000C */  swc1      $f0, 0xc($s0)
/* C2F86C 80240CCC 8E4200CC */  lw        $v0, 0xcc($s2)
/* C2F870 80240CD0 8C420000 */  lw        $v0, ($v0)
/* C2F874 80240CD4 240403E8 */  addiu     $a0, $zero, 0x3e8
/* C2F878 80240CD8 0C00A67F */  jal       rand_int
/* C2F87C 80240CDC AE020028 */   sw       $v0, 0x28($s0)
/* C2F880 80240CE0 00021FC2 */  srl       $v1, $v0, 0x1f
/* C2F884 80240CE4 00431821 */  addu      $v1, $v0, $v1
/* C2F888 80240CE8 00031843 */  sra       $v1, $v1, 1
/* C2F88C 80240CEC 00031840 */  sll       $v1, $v1, 1
/* C2F890 80240CF0 00431023 */  subu      $v0, $v0, $v1
/* C2F894 80240CF4 24420002 */  addiu     $v0, $v0, 2
/* C2F898 80240CF8 AE220074 */  sw        $v0, 0x74($s1)
/* C2F89C 80240CFC 24020004 */  addiu     $v0, $zero, 4
/* C2F8A0 80240D00 AE220070 */  sw        $v0, 0x70($s1)
/* C2F8A4 80240D04 8FBF001C */  lw        $ra, 0x1c($sp)
/* C2F8A8 80240D08 8FB20018 */  lw        $s2, 0x18($sp)
/* C2F8AC 80240D0C 8FB10014 */  lw        $s1, 0x14($sp)
/* C2F8B0 80240D10 8FB00010 */  lw        $s0, 0x10($sp)
/* C2F8B4 80240D14 03E00008 */  jr        $ra
/* C2F8B8 80240D18 27BD0020 */   addiu    $sp, $sp, 0x20
