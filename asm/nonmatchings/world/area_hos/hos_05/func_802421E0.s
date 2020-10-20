.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421E0
/* A2C420 802421E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A2C424 802421E4 AFB20020 */  sw        $s2, 0x20($sp)
/* A2C428 802421E8 3C128025 */  lui       $s2, 0x8025
/* A2C42C 802421EC 26529A74 */  addiu     $s2, $s2, -0x658c
/* A2C430 802421F0 3C03800B */  lui       $v1, %hi(gCameras)
/* A2C434 802421F4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A2C438 802421F8 AFB1001C */  sw        $s1, 0x1c($sp)
/* A2C43C 802421FC 3C118025 */  lui       $s1, 0x8025
/* A2C440 80242200 26319A78 */  addiu     $s1, $s1, -0x6588
/* A2C444 80242204 3C0141A0 */  lui       $at, 0x41a0
/* A2C448 80242208 44810000 */  mtc1      $at, $f0
/* A2C44C 8024220C 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* A2C450 80242210 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* A2C454 80242214 3C0542B4 */  lui       $a1, 0x42b4
/* A2C458 80242218 3C0643ED */  lui       $a2, 0x43ed
/* A2C45C 8024221C 34C6599A */  ori       $a2, $a2, 0x599a
/* A2C460 80242220 24040004 */  addiu     $a0, $zero, 4
/* A2C464 80242224 AFBF0024 */  sw        $ra, 0x24($sp)
/* A2C468 80242228 AFB00018 */  sw        $s0, 0x18($sp)
/* A2C46C 8024222C AFB20014 */  sw        $s2, 0x14($sp)
/* A2C470 80242230 00028080 */  sll       $s0, $v0, 2
/* A2C474 80242234 02028021 */  addu      $s0, $s0, $v0
/* A2C478 80242238 00108080 */  sll       $s0, $s0, 2
/* A2C47C 8024223C 02028023 */  subu      $s0, $s0, $v0
/* A2C480 80242240 001010C0 */  sll       $v0, $s0, 3
/* A2C484 80242244 02028021 */  addu      $s0, $s0, $v0
/* A2C488 80242248 001080C0 */  sll       $s0, $s0, 3
/* A2C48C 8024224C E7A00010 */  swc1      $f0, 0x10($sp)
/* A2C490 80242250 C6200000 */  lwc1      $f0, ($s1)
/* A2C494 80242254 46800020 */  cvt.s.w   $f0, $f0
/* A2C498 80242258 44070000 */  mfc1      $a3, $f0
/* A2C49C 8024225C 0C090439 */  jal       func_802410E4
/* A2C4A0 80242260 02038021 */   addu     $s0, $s0, $v1
/* A2C4A4 80242264 C6400000 */  lwc1      $f0, ($s2)
/* A2C4A8 80242268 8E220000 */  lw        $v0, ($s1)
/* A2C4AC 8024226C 24030001 */  addiu     $v1, $zero, 1
/* A2C4B0 80242270 A6030506 */  sh        $v1, 0x506($s0)
/* A2C4B4 80242274 24420001 */  addiu     $v0, $v0, 1
/* A2C4B8 80242278 E60004DC */  swc1      $f0, 0x4dc($s0)
/* A2C4BC 8024227C AE220000 */  sw        $v0, ($s1)
/* A2C4C0 80242280 28420015 */  slti      $v0, $v0, 0x15
/* A2C4C4 80242284 8FBF0024 */  lw        $ra, 0x24($sp)
/* A2C4C8 80242288 8FB20020 */  lw        $s2, 0x20($sp)
/* A2C4CC 8024228C 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2C4D0 80242290 8FB00018 */  lw        $s0, 0x18($sp)
/* A2C4D4 80242294 38420001 */  xori      $v0, $v0, 1
/* A2C4D8 80242298 03E00008 */  jr        $ra
/* A2C4DC 8024229C 27BD0028 */   addiu    $sp, $sp, 0x28
