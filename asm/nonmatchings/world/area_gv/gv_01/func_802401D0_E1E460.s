.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D0_E1E630
/* E1E630 802401D0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E1E634 802401D4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E1E638 802401D8 3C014334 */  lui       $at, 0x4334
/* E1E63C 802401DC 44816000 */  mtc1      $at, $f12
/* E1E640 802401E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E1E644 802401E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* E1E648 802401E8 AFB00010 */  sw        $s0, 0x10($sp)
/* E1E64C 802401EC 00031080 */  sll       $v0, $v1, 2
/* E1E650 802401F0 00431021 */  addu      $v0, $v0, $v1
/* E1E654 802401F4 00021080 */  sll       $v0, $v0, 2
/* E1E658 802401F8 00431023 */  subu      $v0, $v0, $v1
/* E1E65C 802401FC 000218C0 */  sll       $v1, $v0, 3
/* E1E660 80240200 00431021 */  addu      $v0, $v0, $v1
/* E1E664 80240204 000210C0 */  sll       $v0, $v0, 3
/* E1E668 80240208 3C01800B */  lui       $at, 0x800b
/* E1E66C 8024020C 00220821 */  addu      $at, $at, $v0
/* E1E670 80240210 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* E1E674 80240214 460C0300 */  add.s     $f12, $f0, $f12
/* E1E678 80240218 0C00A6C9 */  jal       clamp_angle
/* E1E67C 8024021C 0080802D */   daddu    $s0, $a0, $zero
/* E1E680 80240220 4600008D */  trunc.w.s $f2, $f0
/* E1E684 80240224 E6020084 */  swc1      $f2, 0x84($s0)
/* E1E688 80240228 8FBF0014 */  lw        $ra, 0x14($sp)
/* E1E68C 8024022C 8FB00010 */  lw        $s0, 0x10($sp)
/* E1E690 80240230 24020002 */  addiu     $v0, $zero, 2
/* E1E694 80240234 03E00008 */  jr        $ra
/* E1E698 80240238 27BD0018 */   addiu    $sp, $sp, 0x18
