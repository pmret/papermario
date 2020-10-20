.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D0_BB7240
/* BB7240 802401D0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* BB7244 802401D4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* BB7248 802401D8 3C014334 */  lui       $at, 0x4334
/* BB724C 802401DC 44816000 */  mtc1      $at, $f12
/* BB7250 802401E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BB7254 802401E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* BB7258 802401E8 AFB00010 */  sw        $s0, 0x10($sp)
/* BB725C 802401EC 00031080 */  sll       $v0, $v1, 2
/* BB7260 802401F0 00431021 */  addu      $v0, $v0, $v1
/* BB7264 802401F4 00021080 */  sll       $v0, $v0, 2
/* BB7268 802401F8 00431023 */  subu      $v0, $v0, $v1
/* BB726C 802401FC 000218C0 */  sll       $v1, $v0, 3
/* BB7270 80240200 00431021 */  addu      $v0, $v0, $v1
/* BB7274 80240204 000210C0 */  sll       $v0, $v0, 3
/* BB7278 80240208 3C01800B */  lui       $at, 0x800b
/* BB727C 8024020C 00220821 */  addu      $at, $at, $v0
/* BB7280 80240210 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* BB7284 80240214 460C0300 */  add.s     $f12, $f0, $f12
/* BB7288 80240218 0C00A6C9 */  jal       clamp_angle
/* BB728C 8024021C 0080802D */   daddu    $s0, $a0, $zero
/* BB7290 80240220 4600008D */  trunc.w.s $f2, $f0
/* BB7294 80240224 E6020084 */  swc1      $f2, 0x84($s0)
/* BB7298 80240228 8FBF0014 */  lw        $ra, 0x14($sp)
/* BB729C 8024022C 8FB00010 */  lw        $s0, 0x10($sp)
/* BB72A0 80240230 24020002 */  addiu     $v0, $zero, 2
/* BB72A4 80240234 03E00008 */  jr        $ra
/* BB72A8 80240238 27BD0018 */   addiu    $sp, $sp, 0x18
