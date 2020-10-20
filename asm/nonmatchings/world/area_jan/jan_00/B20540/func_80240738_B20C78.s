.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240738_B20C78
/* B20C78 80240738 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B20C7C 8024073C AFBF0010 */  sw        $ra, 0x10($sp)
/* B20C80 80240740 10A00003 */  beqz      $a1, .L80240750
/* B20C84 80240744 8C86000C */   lw       $a2, 0xc($a0)
/* B20C88 80240748 3C018024 */  lui       $at, 0x8024
/* B20C8C 8024074C AC20242C */  sw        $zero, 0x242c($at)
.L80240750:
/* B20C90 80240750 3C038024 */  lui       $v1, 0x8024
/* B20C94 80240754 2463242C */  addiu     $v1, $v1, 0x242c
/* B20C98 80240758 8C620000 */  lw        $v0, ($v1)
/* B20C9C 8024075C 54400003 */  bnel      $v0, $zero, .L8024076C
/* B20CA0 80240760 AC600000 */   sw       $zero, ($v1)
/* B20CA4 80240764 080901E0 */  j         .L80240780
/* B20CA8 80240768 0000102D */   daddu    $v0, $zero, $zero
.L8024076C:
/* B20CAC 8024076C 8CC50000 */  lw        $a1, ($a2)
/* B20CB0 80240770 3C068024 */  lui       $a2, 0x8024
/* B20CB4 80240774 0C0B2026 */  jal       set_variable
/* B20CB8 80240778 8CC62430 */   lw       $a2, 0x2430($a2)
/* B20CBC 8024077C 24020002 */  addiu     $v0, $zero, 2
.L80240780:
/* B20CC0 80240780 8FBF0010 */  lw        $ra, 0x10($sp)
/* B20CC4 80240784 03E00008 */  jr        $ra
/* B20CC8 80240788 27BD0018 */   addiu    $sp, $sp, 0x18
