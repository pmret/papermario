.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80148040
/* DE740 80148040 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DE744 80148044 AFBF0010 */  sw        $ra, 0x10($sp)
/* DE748 80148048 0C05203C */  jal       func_801480F0
/* DE74C 8014804C 00000000 */   nop      
/* DE750 80148050 0000202D */  daddu     $a0, $zero, $zero
/* DE754 80148054 3C068015 */  lui       $a2, %hi(D_80151328)
/* DE758 80148058 24C61328 */  addiu     $a2, $a2, %lo(D_80151328)
/* DE75C 8014805C 3C058015 */  lui       $a1, 0x8015
/* DE760 80148060 24A512B0 */  addiu     $a1, $a1, 0x12b0
/* DE764 80148064 0080182D */  daddu     $v1, $a0, $zero
.L80148068:
/* DE768 80148068 8CC20000 */  lw        $v0, ($a2)
/* DE76C 8014806C 00431021 */  addu      $v0, $v0, $v1
/* DE770 80148070 A0400004 */  sb        $zero, 4($v0)
/* DE774 80148074 8CA20000 */  lw        $v0, ($a1)
/* DE778 80148078 24840001 */  addiu     $a0, $a0, 1
/* DE77C 8014807C 00431021 */  addu      $v0, $v0, $v1
/* DE780 80148080 A0400004 */  sb        $zero, 4($v0)
/* DE784 80148084 28820007 */  slti      $v0, $a0, 7
/* DE788 80148088 1440FFF7 */  bnez      $v0, .L80148068
/* DE78C 8014808C 24630018 */   addiu    $v1, $v1, 0x18
/* DE790 80148090 3C048015 */  lui       $a0, %hi(D_80151328)
/* DE794 80148094 24841328 */  addiu     $a0, $a0, %lo(D_80151328)
/* DE798 80148098 8C820000 */  lw        $v0, ($a0)
/* DE79C 8014809C 24030032 */  addiu     $v1, $zero, 0x32
/* DE7A0 801480A0 A4400000 */  sh        $zero, ($v0)
/* DE7A4 801480A4 A04300AE */  sb        $v1, 0xae($v0)
/* DE7A8 801480A8 A04300AD */  sb        $v1, 0xad($v0)
/* DE7AC 801480AC A04300AC */  sb        $v1, 0xac($v0)
/* DE7B0 801480B0 8C840000 */  lw        $a0, ($a0)
/* DE7B4 801480B4 2402000A */  addiu     $v0, $zero, 0xa
/* DE7B8 801480B8 A08200AF */  sb        $v0, 0xaf($a0)
/* DE7BC 801480BC 3C048015 */  lui       $a0, 0x8015
/* DE7C0 801480C0 248412B0 */  addiu     $a0, $a0, 0x12b0
/* DE7C4 801480C4 8C820000 */  lw        $v0, ($a0)
/* DE7C8 801480C8 A4400000 */  sh        $zero, ($v0)
/* DE7CC 801480CC A04300AE */  sb        $v1, 0xae($v0)
/* DE7D0 801480D0 A04300AD */  sb        $v1, 0xad($v0)
/* DE7D4 801480D4 A04300AC */  sb        $v1, 0xac($v0)
/* DE7D8 801480D8 8C830000 */  lw        $v1, ($a0)
/* DE7DC 801480DC 24020014 */  addiu     $v0, $zero, 0x14
/* DE7E0 801480E0 A06200AF */  sb        $v0, 0xaf($v1)
/* DE7E4 801480E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* DE7E8 801480E8 03E00008 */  jr        $ra
/* DE7EC 801480EC 27BD0018 */   addiu    $sp, $sp, 0x18
