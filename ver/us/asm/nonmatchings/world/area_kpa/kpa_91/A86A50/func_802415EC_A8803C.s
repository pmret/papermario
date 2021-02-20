.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415EC_A8803C
/* A8803C 802415EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A88040 802415F0 AFB10014 */  sw        $s1, 0x14($sp)
/* A88044 802415F4 0080882D */  daddu     $s1, $a0, $zero
/* A88048 802415F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* A8804C 802415FC AFB00010 */  sw        $s0, 0x10($sp)
/* A88050 80241600 8E30000C */  lw        $s0, 0xc($s1)
/* A88054 80241604 8E050000 */  lw        $a1, ($s0)
/* A88058 80241608 0C0B1EAF */  jal       get_variable
/* A8805C 8024160C 26100004 */   addiu    $s0, $s0, 4
/* A88060 80241610 0220202D */  daddu     $a0, $s1, $zero
/* A88064 80241614 8E050000 */  lw        $a1, ($s0)
/* A88068 80241618 0C0B1EAF */  jal       get_variable
/* A8806C 8024161C 0040802D */   daddu    $s0, $v0, $zero
/* A88070 80241620 44820000 */  mtc1      $v0, $f0
/* A88074 80241624 00000000 */  nop
/* A88078 80241628 46800020 */  cvt.s.w   $f0, $f0
/* A8807C 8024162C 24020002 */  addiu     $v0, $zero, 2
/* A88080 80241630 00501804 */  sllv      $v1, $s0, $v0
/* A88084 80241634 00701821 */  addu      $v1, $v1, $s0
/* A88088 80241638 00431804 */  sllv      $v1, $v1, $v0
/* A8808C 8024163C 00701823 */  subu      $v1, $v1, $s0
/* A88090 80241640 000320C0 */  sll       $a0, $v1, 3
/* A88094 80241644 00641821 */  addu      $v1, $v1, $a0
/* A88098 80241648 000318C0 */  sll       $v1, $v1, 3
/* A8809C 8024164C 3C01800B */  lui       $at, %hi(gCameras+0x18)
/* A880A0 80241650 00230821 */  addu      $at, $at, $v1
/* A880A4 80241654 E4201D98 */  swc1      $f0, %lo(gCameras+0x18)($at)
/* A880A8 80241658 8FBF0018 */  lw        $ra, 0x18($sp)
/* A880AC 8024165C 8FB10014 */  lw        $s1, 0x14($sp)
/* A880B0 80241660 8FB00010 */  lw        $s0, 0x10($sp)
/* A880B4 80241664 03E00008 */  jr        $ra
/* A880B8 80241668 27BD0020 */   addiu    $sp, $sp, 0x20
