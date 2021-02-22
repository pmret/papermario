.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D08_A2BF48
/* A2BF48 80241D08 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2BF4C 80241D0C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A2BF50 80241D10 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A2BF54 80241D14 3C04800B */  lui       $a0, %hi(gCameras)
/* A2BF58 80241D18 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A2BF5C 80241D1C AFBF0010 */  sw        $ra, 0x10($sp)
/* A2BF60 80241D20 00031080 */  sll       $v0, $v1, 2
/* A2BF64 80241D24 00431021 */  addu      $v0, $v0, $v1
/* A2BF68 80241D28 00021080 */  sll       $v0, $v0, 2
/* A2BF6C 80241D2C 00431023 */  subu      $v0, $v0, $v1
/* A2BF70 80241D30 000218C0 */  sll       $v1, $v0, 3
/* A2BF74 80241D34 00431021 */  addu      $v0, $v0, $v1
/* A2BF78 80241D38 000210C0 */  sll       $v0, $v0, 3
/* A2BF7C 80241D3C 10A00004 */  beqz      $a1, .L80241D50
/* A2BF80 80241D40 00442021 */   addu     $a0, $v0, $a0
/* A2BF84 80241D44 94820000 */  lhu       $v0, ($a0)
/* A2BF88 80241D48 3042FFF7 */  andi      $v0, $v0, 0xfff7
/* A2BF8C 80241D4C A4820000 */  sh        $v0, ($a0)
.L80241D50:
/* A2BF90 80241D50 44800000 */  mtc1      $zero, $f0
/* A2BF94 80241D54 00000000 */  nop
/* A2BF98 80241D58 44050000 */  mfc1      $a1, $f0
/* A2BF9C 80241D5C 24840194 */  addiu     $a0, $a0, 0x194
/* A2BFA0 80241D60 00A0302D */  daddu     $a2, $a1, $zero
/* A2BFA4 80241D64 0C019E40 */  jal       guTranslateF
/* A2BFA8 80241D68 00A0382D */   daddu    $a3, $a1, $zero
/* A2BFAC 80241D6C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2BFB0 80241D70 24020002 */  addiu     $v0, $zero, 2
/* A2BFB4 80241D74 03E00008 */  jr        $ra
/* A2BFB8 80241D78 27BD0018 */   addiu    $sp, $sp, 0x18
