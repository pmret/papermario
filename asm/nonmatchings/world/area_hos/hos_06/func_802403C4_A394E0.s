.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C4_A398A4
/* A398A4 802403C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A398A8 802403C8 AFB00010 */  sw        $s0, 0x10($sp)
/* A398AC 802403CC 0080802D */  daddu     $s0, $a0, $zero
/* A398B0 802403D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A398B4 802403D4 AFB10014 */  sw        $s1, 0x14($sp)
/* A398B8 802403D8 8E02000C */  lw        $v0, 0xc($s0)
/* A398BC 802403DC 8C510000 */  lw        $s1, ($v0)
/* A398C0 802403E0 0C0B1EAF */  jal       get_variable
/* A398C4 802403E4 0220282D */   daddu    $a1, $s1, $zero
/* A398C8 802403E8 3C03FFF0 */  lui       $v1, 0xfff0
/* A398CC 802403EC 3463FFFF */  ori       $v1, $v1, 0xffff
/* A398D0 802403F0 0200202D */  daddu     $a0, $s0, $zero
/* A398D4 802403F4 00431024 */  and       $v0, $v0, $v1
/* A398D8 802403F8 00021140 */  sll       $v0, $v0, 5
/* A398DC 802403FC 3C068008 */  lui       $a2, %hi(gItemTable)
/* A398E0 80240400 00C23021 */  addu      $a2, $a2, $v0
/* A398E4 80240404 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* A398E8 80240408 0C0B2026 */  jal       set_variable
/* A398EC 8024040C 0220282D */   daddu    $a1, $s1, $zero
/* A398F0 80240410 8FBF0018 */  lw        $ra, 0x18($sp)
/* A398F4 80240414 8FB10014 */  lw        $s1, 0x14($sp)
/* A398F8 80240418 8FB00010 */  lw        $s0, 0x10($sp)
/* A398FC 8024041C 24020002 */  addiu     $v0, $zero, 2
/* A39900 80240420 03E00008 */  jr        $ra
/* A39904 80240424 27BD0020 */   addiu    $sp, $sp, 0x20
