.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240434_A578E4
/* A578E4 80240434 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A578E8 80240438 AFB00010 */  sw        $s0, 0x10($sp)
/* A578EC 8024043C 0080802D */  daddu     $s0, $a0, $zero
/* A578F0 80240440 AFBF0018 */  sw        $ra, 0x18($sp)
/* A578F4 80240444 AFB10014 */  sw        $s1, 0x14($sp)
/* A578F8 80240448 8E02000C */  lw        $v0, 0xc($s0)
/* A578FC 8024044C 8C510000 */  lw        $s1, ($v0)
/* A57900 80240450 0C0B1EAF */  jal       get_variable
/* A57904 80240454 0220282D */   daddu    $a1, $s1, $zero
/* A57908 80240458 3C03FFF0 */  lui       $v1, 0xfff0
/* A5790C 8024045C 3463FFFF */  ori       $v1, $v1, 0xffff
/* A57910 80240460 0200202D */  daddu     $a0, $s0, $zero
/* A57914 80240464 00431024 */  and       $v0, $v0, $v1
/* A57918 80240468 00021140 */  sll       $v0, $v0, 5
/* A5791C 8024046C 3C068008 */  lui       $a2, %hi(gItemTable)
/* A57920 80240470 00C23021 */  addu      $a2, $a2, $v0
/* A57924 80240474 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* A57928 80240478 0C0B2026 */  jal       set_variable
/* A5792C 8024047C 0220282D */   daddu    $a1, $s1, $zero
/* A57930 80240480 8FBF0018 */  lw        $ra, 0x18($sp)
/* A57934 80240484 8FB10014 */  lw        $s1, 0x14($sp)
/* A57938 80240488 8FB00010 */  lw        $s0, 0x10($sp)
/* A5793C 8024048C 24020002 */  addiu     $v0, $zero, 2
/* A57940 80240490 03E00008 */  jr        $ra
/* A57944 80240494 27BD0020 */   addiu    $sp, $sp, 0x20
