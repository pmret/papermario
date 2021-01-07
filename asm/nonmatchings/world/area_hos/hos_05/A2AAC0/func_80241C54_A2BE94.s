.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C54_A2BE94
/* A2BE94 80241C54 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* A2BE98 80241C58 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* A2BE9C 80241C5C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A2BEA0 80241C60 AFB1001C */  sw        $s1, 0x1c($sp)
/* A2BEA4 80241C64 3C118025 */  lui       $s1, %hi(D_80249980)
/* A2BEA8 80241C68 26319980 */  addiu     $s1, $s1, %lo(D_80249980)
/* A2BEAC 80241C6C F7B40028 */  sdc1      $f20, 0x28($sp)
/* A2BEB0 80241C70 3C014170 */  lui       $at, 0x4170
/* A2BEB4 80241C74 4481A000 */  mtc1      $at, $f20
/* A2BEB8 80241C78 3C0141F0 */  lui       $at, 0x41f0
/* A2BEBC 80241C7C 44816000 */  mtc1      $at, $f12
/* A2BEC0 80241C80 3C03800B */  lui       $v1, %hi(gCameras)
/* A2BEC4 80241C84 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A2BEC8 80241C88 AFBF0020 */  sw        $ra, 0x20($sp)
/* A2BECC 80241C8C AFB00018 */  sw        $s0, 0x18($sp)
/* A2BED0 80241C90 AFB10010 */  sw        $s1, 0x10($sp)
/* A2BED4 80241C94 8E260000 */  lw        $a2, ($s1)
/* A2BED8 80241C98 3C073F80 */  lui       $a3, 0x3f80
/* A2BEDC 80241C9C 00028080 */  sll       $s0, $v0, 2
/* A2BEE0 80241CA0 02028021 */  addu      $s0, $s0, $v0
/* A2BEE4 80241CA4 00108080 */  sll       $s0, $s0, 2
/* A2BEE8 80241CA8 02028023 */  subu      $s0, $s0, $v0
/* A2BEEC 80241CAC 001010C0 */  sll       $v0, $s0, 3
/* A2BEF0 80241CB0 02028021 */  addu      $s0, $s0, $v0
/* A2BEF4 80241CB4 001080C0 */  sll       $s0, $s0, 3
/* A2BEF8 80241CB8 02038021 */  addu      $s0, $s0, $v1
/* A2BEFC 80241CBC 0C090411 */  jal       func_80241044_A2B284
/* A2BF00 80241CC0 4600A386 */   mov.s    $f14, $f20
/* A2BF04 80241CC4 8E250000 */  lw        $a1, ($s1)
/* A2BF08 80241CC8 0C090355 */  jal       func_80240D54_A2AF94
/* A2BF0C 80241CCC 0000202D */   daddu    $a0, $zero, $zero
/* A2BF10 80241CD0 24020001 */  addiu     $v0, $zero, 1
/* A2BF14 80241CD4 C6200000 */  lwc1      $f0, ($s1)
/* A2BF18 80241CD8 0040182D */  daddu     $v1, $v0, $zero
/* A2BF1C 80241CDC 46140032 */  c.eq.s    $f0, $f20
/* A2BF20 80241CE0 00000000 */  nop       
/* A2BF24 80241CE4 45010002 */  bc1t      .L80241CF0
/* A2BF28 80241CE8 A6030506 */   sh       $v1, 0x506($s0)
/* A2BF2C 80241CEC 0000102D */  daddu     $v0, $zero, $zero
.L80241CF0:
/* A2BF30 80241CF0 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2BF34 80241CF4 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2BF38 80241CF8 8FB00018 */  lw        $s0, 0x18($sp)
/* A2BF3C 80241CFC D7B40028 */  ldc1      $f20, 0x28($sp)
/* A2BF40 80241D00 03E00008 */  jr        $ra
/* A2BF44 80241D04 27BD0030 */   addiu    $sp, $sp, 0x30
