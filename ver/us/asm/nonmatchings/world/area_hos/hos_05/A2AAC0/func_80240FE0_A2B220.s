.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE0_A2B220
/* A2B220 80240FE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2B224 80240FE4 AFB00010 */  sw        $s0, 0x10($sp)
/* A2B228 80240FE8 0080802D */  daddu     $s0, $a0, $zero
/* A2B22C 80240FEC 3C05F4AC */  lui       $a1, 0xf4ac
/* A2B230 80240FF0 AFBF0014 */  sw        $ra, 0x14($sp)
/* A2B234 80240FF4 0C0B1EAF */  jal       get_variable
/* A2B238 80240FF8 34A5D490 */   ori      $a1, $a1, 0xd490
/* A2B23C 80240FFC 0040182D */  daddu     $v1, $v0, $zero
/* A2B240 80241000 8C64000C */  lw        $a0, 0xc($v1)
/* A2B244 80241004 C6000084 */  lwc1      $f0, 0x84($s0)
/* A2B248 80241008 46800020 */  cvt.s.w   $f0, $f0
/* A2B24C 8024100C E4800010 */  swc1      $f0, 0x10($a0)
/* A2B250 80241010 8C64000C */  lw        $a0, 0xc($v1)
/* A2B254 80241014 C6000088 */  lwc1      $f0, 0x88($s0)
/* A2B258 80241018 46800020 */  cvt.s.w   $f0, $f0
/* A2B25C 8024101C E4800014 */  swc1      $f0, 0x14($a0)
/* A2B260 80241020 8C63000C */  lw        $v1, 0xc($v1)
/* A2B264 80241024 C600008C */  lwc1      $f0, 0x8c($s0)
/* A2B268 80241028 46800020 */  cvt.s.w   $f0, $f0
/* A2B26C 8024102C E4600018 */  swc1      $f0, 0x18($v1)
/* A2B270 80241030 8FBF0014 */  lw        $ra, 0x14($sp)
/* A2B274 80241034 8FB00010 */  lw        $s0, 0x10($sp)
/* A2B278 80241038 24020002 */  addiu     $v0, $zero, 2
/* A2B27C 8024103C 03E00008 */  jr        $ra
/* A2B280 80241040 27BD0018 */   addiu    $sp, $sp, 0x18
