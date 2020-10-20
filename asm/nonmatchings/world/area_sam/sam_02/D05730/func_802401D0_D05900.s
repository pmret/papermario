.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D0_D05900
/* D05900 802401D0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* D05904 802401D4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* D05908 802401D8 3C014334 */  lui       $at, 0x4334
/* D0590C 802401DC 44816000 */  mtc1      $at, $f12
/* D05910 802401E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D05914 802401E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* D05918 802401E8 AFB00010 */  sw        $s0, 0x10($sp)
/* D0591C 802401EC 00031080 */  sll       $v0, $v1, 2
/* D05920 802401F0 00431021 */  addu      $v0, $v0, $v1
/* D05924 802401F4 00021080 */  sll       $v0, $v0, 2
/* D05928 802401F8 00431023 */  subu      $v0, $v0, $v1
/* D0592C 802401FC 000218C0 */  sll       $v1, $v0, 3
/* D05930 80240200 00431021 */  addu      $v0, $v0, $v1
/* D05934 80240204 000210C0 */  sll       $v0, $v0, 3
/* D05938 80240208 3C01800B */  lui       $at, 0x800b
/* D0593C 8024020C 00220821 */  addu      $at, $at, $v0
/* D05940 80240210 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* D05944 80240214 460C0300 */  add.s     $f12, $f0, $f12
/* D05948 80240218 0C00A6C9 */  jal       clamp_angle
/* D0594C 8024021C 0080802D */   daddu    $s0, $a0, $zero
/* D05950 80240220 4600008D */  trunc.w.s $f2, $f0
/* D05954 80240224 E6020084 */  swc1      $f2, 0x84($s0)
/* D05958 80240228 8FBF0014 */  lw        $ra, 0x14($sp)
/* D0595C 8024022C 8FB00010 */  lw        $s0, 0x10($sp)
/* D05960 80240230 24020002 */  addiu     $v0, $zero, 2
/* D05964 80240234 03E00008 */  jr        $ra
/* D05968 80240238 27BD0018 */   addiu    $sp, $sp, 0x18
