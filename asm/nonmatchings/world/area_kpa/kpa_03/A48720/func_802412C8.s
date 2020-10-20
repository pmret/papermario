.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412C8
/* A49888 802412C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4988C 802412CC AFB10014 */  sw        $s1, 0x14($sp)
/* A49890 802412D0 0080882D */  daddu     $s1, $a0, $zero
/* A49894 802412D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* A49898 802412D8 AFB00010 */  sw        $s0, 0x10($sp)
/* A4989C 802412DC 8E220148 */  lw        $v0, 0x148($s1)
/* A498A0 802412E0 0C00EABB */  jal       get_npc_unsafe
/* A498A4 802412E4 84440008 */   lh       $a0, 8($v0)
/* A498A8 802412E8 24040064 */  addiu     $a0, $zero, 0x64
/* A498AC 802412EC 0C00A67F */  jal       rand_int
/* A498B0 802412F0 0040802D */   daddu    $s0, $v0, $zero
/* A498B4 802412F4 00021FC2 */  srl       $v1, $v0, 0x1f
/* A498B8 802412F8 00431821 */  addu      $v1, $v0, $v1
/* A498BC 802412FC 00031843 */  sra       $v1, $v1, 1
/* A498C0 80241300 00031840 */  sll       $v1, $v1, 1
/* A498C4 80241304 00431023 */  subu      $v0, $v0, $v1
/* A498C8 80241308 3C014334 */  lui       $at, 0x4334
/* A498CC 8024130C 44811000 */  mtc1      $at, $f2
/* A498D0 80241310 44820000 */  mtc1      $v0, $f0
/* A498D4 80241314 00000000 */  nop       
/* A498D8 80241318 46800020 */  cvt.s.w   $f0, $f0
/* A498DC 8024131C 46020002 */  mul.s     $f0, $f0, $f2
/* A498E0 80241320 00000000 */  nop       
/* A498E4 80241324 3C013F4C */  lui       $at, 0x3f4c
/* A498E8 80241328 3421CCCD */  ori       $at, $at, 0xcccd
/* A498EC 8024132C 44812000 */  mtc1      $at, $f4
/* A498F0 80241330 3C0142B4 */  lui       $at, 0x42b4
/* A498F4 80241334 44811000 */  mtc1      $at, $f2
/* A498F8 80241338 2402000F */  addiu     $v0, $zero, 0xf
/* A498FC 8024133C A602008E */  sh        $v0, 0x8e($s0)
/* A49900 80241340 46020000 */  add.s     $f0, $f0, $f2
/* A49904 80241344 24020006 */  addiu     $v0, $zero, 6
/* A49908 80241348 E6040018 */  swc1      $f4, 0x18($s0)
/* A4990C 8024134C E600000C */  swc1      $f0, 0xc($s0)
/* A49910 80241350 AE220070 */  sw        $v0, 0x70($s1)
/* A49914 80241354 8FBF0018 */  lw        $ra, 0x18($sp)
/* A49918 80241358 8FB10014 */  lw        $s1, 0x14($sp)
/* A4991C 8024135C 8FB00010 */  lw        $s0, 0x10($sp)
/* A49920 80241360 03E00008 */  jr        $ra
/* A49924 80241364 27BD0020 */   addiu    $sp, $sp, 0x20
